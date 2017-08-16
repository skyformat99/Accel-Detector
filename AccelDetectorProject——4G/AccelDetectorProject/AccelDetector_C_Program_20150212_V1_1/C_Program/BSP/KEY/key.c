
#include "stm32f10x.h"
#include "key.h"
#include "tim.h"
/*---------------------------------------------------------------------------
**	Function	: KEY_GPIO_Config
**	Parameters	:
**	Retval		:
**	Description	: 
**	Attention	: 注意修改.h文件中的硬件相关宏定义
---------------------------------------------------------------------------*/
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(KEY_0_GPIO_RCC_Periph,ENABLE);
	RCC_APB2PeriphClockCmd(KEY_1_GPIO_RCC_Periph,ENABLE);
	RCC_APB2PeriphClockCmd(KEY_2_GPIO_RCC_Periph,ENABLE);
	RCC_APB2PeriphClockCmd(KEY_3_GPIO_RCC_Periph,ENABLE);

	GPIO_InitStructure.GPIO_Pin =  KEY_0_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(KEY_0_GPIO_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  KEY_1_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(KEY_1_GPIO_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  KEY_2_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(KEY_2_GPIO_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  KEY_3_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(KEY_3_GPIO_Port, &GPIO_InitStructure);	
}
/*---------------------------------------------------------------------------
**	Function	:  KEY_ScanPin
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:  注意修改Key动作时的IO电平
---------------------------------------------------------------------------*/

unsigned char KEY_ScanPin(void)
{
	if(GPIO_ReadInputDataBit(KEY_0_GPIO_Port,KEY_0_GPIO_Pin) == 0)		
		return	KEY_ID_0;
	if(GPIO_ReadInputDataBit(KEY_1_GPIO_Port,KEY_1_GPIO_Pin) == 0)		
		return	KEY_ID_1;
	if(GPIO_ReadInputDataBit(KEY_2_GPIO_Port,KEY_2_GPIO_Pin) == 0)		
		return	KEY_ID_2;
	if(GPIO_ReadInputDataBit(KEY_3_GPIO_Port,KEY_3_GPIO_Pin) == 0)		
		return	KEY_ID_3;

	return KEY_ID_NONE;
}
/*---------------------------------------------------------------------------
**	Function	:	KEY_GetValue
**	Parameters	:
**	Retval		:	KeyValue = （KEY_ID | KEY_EVENT）
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
unsigned char KEY_GetValue(void)
{	
	u8 KeyValue = KEY_ID_NONE|KEY_EVENT_NONE;
	static u8 	KeyState =  KEY_STATE_INIT;
	static u8 	KeyIDTemp =  KEY_ID_NONE;
							
	static vu32 KeyJitterTime;
	static vu32 KeyPressedTime;

	u8 KeyID = KEY_ScanPin();
		
	switch(KeyState)
	{
		case KEY_STATE_INIT :
		{
			if(KeyID != KEY_ID_NONE)
			{
				KeyState = KEY_STATE_JITTER;
				KeyJitterTime = TIM_GetTime();
			}
		}break;
		
		case KEY_STATE_JITTER:
		{
			if(TIM_IsExpired(KeyJitterTime+ 20))
			{
				if(KeyID != KEY_ID_NONE)
				{
					KeyState = KEY_STATE_PRESSED;
					KeyPressedTime =  TIM_GetTime();
					KeyIDTemp = KeyID;
				}
				else
				{
					KeyState = KEY_STATE_INIT;
				}	
			}			
		}break;	
								 
		case KEY_STATE_PRESSED:
		{	
			if( KeyID == KEY_ID_NONE )
			{
				KeyState = KEY_STATE_INIT;
				return 	KeyIDTemp|KEY_EVENT_SHORT;	
			}
			
			if(TIM_IsExpired(KeyPressedTime + 1000))
			{
				KeyState = KEY_STATE_LONG;	
			}	
		}break;

		case KEY_STATE_LONG:
		{
			KeyState = KEY_STATE_RELEASED;
			return 	KeyIDTemp|KEY_EVENT_LONG;											
		}

		case KEY_STATE_RELEASED:
		{
			if(KeyID == KEY_ID_NONE)
				KeyState = KEY_STATE_INIT;		
		}break;

		default:break;		
	}
	
	return KeyValue;	
}
