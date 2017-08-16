
#include "stm32f10x.h"
#include "tim.h"

u32 G_Time;
u32 G_Time3;

/*************************************************************************************
*	函数：void TIM_Config(void)
*	T = (TIM_Period + 1)*(TIM_Prescaler + 1)/TIM_CLK	
*	TIM_ClockDivision 一般置为0X00
*
**************************************************************************************/
void TIM_Config(void)//TIM2用作通用定时器
{	 
	NVIC_InitTypeDef NVIC_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

	TIM_TimeBaseStructure.TIM_Period = 719;	 //基本分频
	TIM_TimeBaseStructure.TIM_Prescaler = 99;	 //预分频	   //1ms
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x00;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, & TIM_TimeBaseStructure);

//TIM2_IRQn----------------------------------//	
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStruct);

	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE); //允许TIM2溢出中断
		
	TIM_Cmd(TIM2, ENABLE); //启动TIM2	
		
}


u32 TIM_GetTime(void)
{
	return G_Time;	
}

u8 TIM_IsExpired(u32 PeriodBased10Ms)
{
	u32 time_now;
	time_now = G_Time;

	if (time_now > PeriodBased10Ms)
	{
//		if ((time_now - PeriodBased10Ms) > 0)
		if ((time_now - PeriodBased10Ms) < 0x80000000)
			return 1;
		else
		  	return 0;
	}
	else
	{ 
//		if ((PeriodBased10Ms - time_now) < 0)
		if ((PeriodBased10Ms - time_now) > 0x80000000)
		  	return 1;
		else
		 	return 0;
	}
}

/*Time Interval to Reset = ((4*2^Pre)*Reload )/(40KHz)   */
/**/
void IWDT_Init(u8 prer,u16 rlr)
{
	/* Enable write access to IWDG_PR and IWDG_RLR registers */
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	/* Set IWDG prescaler to 8 */
	IWDG_SetPrescaler(prer);
	/* Set IWDG reload value to 0xFFF */
	IWDG_SetReload(rlr);
	/* Reload IWDG counter */
	IWDG_ReloadCounter();
	/* Enable IWDG */
	IWDG_Enable();
}

void IWDT_Feed(void)
{
	IWDG_ReloadCounter();
}

void TIM3_Config(void)
{	 
	NVIC_InitTypeDef NVIC_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	TIM_TimeBaseStructure.TIM_Period = 719;	 //基本分频
	TIM_TimeBaseStructure.TIM_Prescaler = 9;	 //预分频	   //100us
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x00;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, & TIM_TimeBaseStructure);

//TIM2_IRQn----------------------------------//	
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStruct);

	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许TIM3溢出中断
		
	TIM_Cmd(TIM3, ENABLE); //启动TIM3	
		
}

u32 TIM3_GetTime(void)
{
	return G_Time3;	
}

u8 TIM3_IsExpired(u32 PeriodBased10Ms)
{
	u32 time_now;
	time_now = G_Time3;

	if (time_now > PeriodBased10Ms)
	{
//		if ((time_now - PeriodBased10Ms) > 0)
		if ((time_now - PeriodBased10Ms) < 0x80000000)
			return 1;
		else
		  	return 0;
	}
	else
	{ 
//		if ((PeriodBased10Ms - time_now) < 0)
		if ((PeriodBased10Ms - time_now) > 0x80000000)
		  	return 1;
		else
		 	return 0;
	}
}

