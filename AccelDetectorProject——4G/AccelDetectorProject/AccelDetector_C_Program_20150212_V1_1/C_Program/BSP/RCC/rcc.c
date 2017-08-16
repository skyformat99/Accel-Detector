#include"rcc.h"
#include"stm32f10x.h"

/******************************************************************
*	函数：void RCC_Config(void)
*	时钟配置，不要忘记开启外设时钟
*
******************************************************************/
void RCC_Config (void)
{ 	
	ErrorStatus HSEStartUpStatus;
	RCC_DeInit();
    RCC_HSEConfig(RCC_HSE_ON);				//高速外部晶振使能，8.000MHz
	HSEStartUpStatus = RCC_WaitForHSEStartUp();		
	if(HSEStartUpStatus == SUCCESS)
  	{
	    RCC_HCLKConfig(RCC_SYSCLK_Div1);	//AHB时钟 = 系统时钟 = 72MHz
	    RCC_PCLK1Config(RCC_HCLK_Div2);		//APB1时钟 = HCLK / 2 = 36MHz
		RCC_PCLK2Config(RCC_HCLK_Div1); 	//APB2时钟 = HCLK = 72MHz								 	
	    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  //PLL源：HSE=8.000MHz，9倍频到SYSCLK = 72MHz
	    RCC_PLLCmd(ENABLE);
	    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)	;
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08)
		;
  	}

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);	  //使能ADC1时钟  
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);

}




