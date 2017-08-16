#ifndef _TIM_H
#define _TIM_H
#include "stm32f10x.h"

extern u32 G_Time;

extern void TIM_Config(void);
extern u32 	TIM_GetTime(void);
extern u8 	TIM_IsExpired(u32 PeriodBased10Ms);

void IWDT_Init(u8 prer,u16 rlr);
void IWDT_Feed(void);



extern 	u32 G_Time3;
void TIM3_Config(void);//for IR
u32  TIM3_GetTime(void);
u8 	 TIM3_IsExpired(u32 PeriodBased10Ms);


#endif


