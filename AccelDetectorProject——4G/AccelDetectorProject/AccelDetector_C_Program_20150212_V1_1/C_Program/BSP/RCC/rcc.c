#include"rcc.h"
#include"stm32f10x.h"

/******************************************************************
*	������void RCC_Config(void)
*	ʱ�����ã���Ҫ���ǿ�������ʱ��
*
******************************************************************/
void RCC_Config (void)
{ 	
	ErrorStatus HSEStartUpStatus;
	RCC_DeInit();
    RCC_HSEConfig(RCC_HSE_ON);				//�����ⲿ����ʹ�ܣ�8.000MHz
	HSEStartUpStatus = RCC_WaitForHSEStartUp();		
	if(HSEStartUpStatus == SUCCESS)
  	{
	    RCC_HCLKConfig(RCC_SYSCLK_Div1);	//AHBʱ�� = ϵͳʱ�� = 72MHz
	    RCC_PCLK1Config(RCC_HCLK_Div2);		//APB1ʱ�� = HCLK / 2 = 36MHz
		RCC_PCLK2Config(RCC_HCLK_Div1); 	//APB2ʱ�� = HCLK = 72MHz								 	
	    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  //PLLԴ��HSE=8.000MHz��9��Ƶ��SYSCLK = 72MHz
	    RCC_PLLCmd(ENABLE);
	    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)	;
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08)
		;
  	}

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);	  //ʹ��ADC1ʱ��  
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);

}




