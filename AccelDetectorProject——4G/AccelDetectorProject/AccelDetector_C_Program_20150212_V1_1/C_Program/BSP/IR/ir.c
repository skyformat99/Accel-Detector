
#include "ir.h"
#include "tim.h"
#include "led.h"
/*----------------------------------------------------------------------------------
NEC红外接收头，HS0038B解调之后输出给单片机GPIO的格式：
单次按键：引导码+地址码+地址反码+命令码+命令反码+结束码+按键次数码
按住不放：引导码+地址码+地址反码+命令码+命令反码+结束码+按键次数码+按键次数码+...

引导码：9ms低电平+4.5ms高电平
逻辑0： 0.56ms低电平+（1.125-0.56）ms高电平
逻辑1： 0.56ms低电平+（2.25-0.56）ms高电平
结束码：0.56ms低电平+ 40ms高电平
按键次数码：9ms低电平+2ms高+0.56ms低电平+100ms高电平
----------------------------------------------------------------------------------*/

IR_Frame_t		IR_Frame;
vu32			G_IsIrEventOccured;
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void IR_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	
	RCC_APB2PeriphClockCmd(IR_GPIO_RCC_Periph|RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  IR_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(IR_GPIO_Port, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(IR_GPIO_INT_Port_Source, IR_GPIO_INT_Pin_Source);  
	EXTI_InitStructure.EXTI_Line=IR_GPIO_INT_EXTI_Line;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = IR_GPIO_INT_NVIC_Channel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStructure);		
	
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void IR_TIM_Config(void)
{
	TIM3_Config();	
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
u32 IR_GetTime(void)
{
	return TIM3_GetTime();//base on 100us
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
u8 IR_IsTimeExpired(u32 PeriodBased100us)
{
	return TIM3_IsExpired(PeriodBased100us);
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void IR_Init(IR_Frame_t	*p)
{	
	p->State = IR_GET_HEADER;
	p->RcvBitCnt = 0;
	p->TimeStamp = IR_GetTime();
	p->PreTime = IR_GetTime();
	p->ThisTime = IR_GetTime();	
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void IR_Process(IR_Frame_t	*p)
{	
	if(G_IsIrEventOccured == 0)
		return ;
	
	G_IsIrEventOccured = 0;
	
	switch(p->State)
	{
		case IR_GET_HEADER:
		{
			if((p->ThisTime - p->PreTime > 130) && (p->ThisTime - p->PreTime < 140))
			{
				p->State = IR_GET_ADDR; 
				p->RcvBitCnt = 0;
				p->Buffer.BitStream = 0;
			}
			
		}break;
		
		case IR_GET_ADDR:
		{
			//receive "1"
			if((p->ThisTime - p->PreTime > 18)&& (p->ThisTime - p->PreTime < 25))
			{
				p->Buffer.BitStream |= (0x01UL<<p->RcvBitCnt);	
				p->RcvBitCnt++;				
			}
			//receive "0"
			if((p->ThisTime - p->PreTime > 8) && (p->ThisTime - p->PreTime < 18))
			{
				p->Buffer.BitStream &= ~(0x01UL<<p->RcvBitCnt);
				p->RcvBitCnt++;	
			}

			if(p->RcvBitCnt > 31)
			{	
				p->IsRcvNewFrame = 1;
				p->State = IR_GET_HEADER;	
			}
				
		}break;
		
		default :break;
	}
}

/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 为了和unsigned char KEY_GetValue(void) 兼容,该函数很晦涩
---------------------------------------------------------------------------*/
#include "key.h"
unsigned char IR_GetValue(void)
{
	IR_Frame_t	*p = &IR_Frame;
	
	IR_Process(p);
	
	if(p->IsRcvNewFrame == 0)
		return KEY_ID_NONE|KEY_EVENT_NONE;
	
	p->IsRcvNewFrame = 0;
	
	if(p->Buffer.Structure.Addr != IR_CTRL_ID)
		return KEY_ID_NONE|KEY_EVENT_NONE;
//	if(p->Buffer.Structure.AddrComp != ~p->Buffer.Structure.Addr)
//		return KEY_ID_NONE|KEY_EVENT_NONE;
//	if(p->Buffer.Structure.Cmd != ~p->Buffer.Structure.CmdComp)
//		return KEY_ID_NONE|KEY_EVENT_NONE;
	GPIO_WriteBit(	LED_0_GPIO_Port, LED_0_GPIO_Pin, 
					(BitAction)(GPIO_ReadInputDataBit(LED_0_GPIO_Port, LED_0_GPIO_Pin)^0x01));	
	switch(p->Buffer.Structure.Cmd) 
	{
		case IR_PAD_OK:
		{
			return KEY_ID_ENTER | KEY_EVENT_SHORT;
		}
		
		case IR_PAD_LEFT:
		{
			return KEY_ID_ESC | KEY_EVENT_SHORT;
		}
		
		case IR_PAD_RIGHT:
		{
			return KEY_ID_RIGHT | KEY_EVENT_SHORT;
		}
		
		case IR_PAD_DN:
		{
			return KEY_ID_UPDOWM | KEY_EVENT_SHORT;
		}
		
		default :break;
	}
	
	return KEY_ID_NONE|KEY_EVENT_NONE;
}






