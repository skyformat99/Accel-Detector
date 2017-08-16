
#ifndef _LED_H
#define _LED_H
/*---------------------------------------------------------------------------
**	硬件相关宏定义
---------------------------------------------------------------------------*/
#define LED_0_GPIO_Port	 		GPIOD
#define LED_0_GPIO_Pin			GPIO_Pin_10
#define LED_0_GPIO_RCC_Periph	RCC_APB2Periph_GPIOD

#define LED_1_GPIO_Port	 		GPIOD
#define LED_1_GPIO_Pin			GPIO_Pin_11
#define LED_1_GPIO_RCC_Periph	RCC_APB2Periph_GPIOD


extern void LED_GPIO_Config(void);

#endif	
