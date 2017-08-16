#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f10x.h"

// extern void delay_nus( u32 nus );
// extern void delay_nms( u32 nms );

void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);
#endif



