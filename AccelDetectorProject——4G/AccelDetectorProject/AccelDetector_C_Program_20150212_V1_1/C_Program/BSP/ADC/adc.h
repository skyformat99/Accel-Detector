

#ifndef _ADC_H
#define _ADC_H

#include "stm32f10x.h"

#define BAT_GPIO_Port	 		GPIOC
#define BAT_GPIO_Pin			GPIO_Pin_0
#define BAT_GPIO_RCC_Periph		RCC_APB2Periph_GPIOC

#define BAT_ADC					ADC1
#define BAT_ADC_RCC_Periph		RCC_APB2Periph_ADC1


typedef struct
{
	s16 	X;
	s16		Y;
	
	s16		XLength;
	s16		YLength;
	
	u8		EmptyPercent;	
}Bat_t;

extern Bat_t	Bat;

void BAT_GPIO_Config(void);
void BAT_ADC_Config(void);
u16  BAT_ADC_GetResult(void);

void BAT_DispPower(Bat_t *p);

#endif


