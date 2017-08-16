
#ifndef _LM240120_H
#define _LM240120_H

#include "stm32f10x.h"
//#include "app_menu.h"



typedef char 	uchar;
typedef u16 	uint;


#define LM_BL_GPIO_Port	 		GPIOC
#define LM_BL_GPIO_Pin			GPIO_Pin_5
#define LM_BL_GPIO_RCC_Periph	RCC_APB2Periph_GPIOC

#define LM_CS_GPIO_Port	 		GPIOB
#define LM_CS_GPIO_Pin			GPIO_Pin_0
#define LM_CS_GPIO_RCC_Periph	RCC_APB2Periph_GPIOB

#define LM_RST_GPIO_Port	 	GPIOB
#define LM_RST_GPIO_Pin			GPIO_Pin_1
#define LM_RST_GPIO_RCC_Periph	RCC_APB2Periph_GPIOB

#define LM_DC_GPIO_Port	 		GPIOB
#define LM_DC_GPIO_Pin			GPIO_Pin_2
#define LM_DC_GPIO_RCC_Periph	RCC_APB2Periph_GPIOB

#define LM_WR_GPIO_Port	 		GPIOE
#define LM_WR_GPIO_Pin			GPIO_Pin_7
#define LM_WR_GPIO_RCC_Periph	RCC_APB2Periph_GPIOE

#define LM_DATA_BUS_Port	 		GPIOE
#define LM_DATA_BUS_RCC_Periph		RCC_APB2Periph_GPIOE

extern u8 const ASCIITAB[];


extern void LM_GPIO_Config(void);
extern void LM_SdCmd(u8 Command);   //send command
extern void LM_SdData(u8 DData);   //send data

extern void LM_Init(void);
extern void LM_BL_Cmd(FunctionalState NewState);
extern void LM_Clear(void);

extern void LM_DrawPoint(u16 x,u16 y);
extern void LM_DispChar(u16 x,u16 y,char Char);
extern void LM_DispStr(uint x,uint y,uchar *pstr);
extern void LM_DispIndicator(u16 x,u16 y);
extern void LM_DispCharWithLine(u16 x,u16 y,char Char);

extern void LM_DispChar8_8(u16 x,u16 y,char Char);
extern void LM_DispStr8_8(uint x,uint y,uchar *pstr);
//void LM_SetContrast(u8 ContrastLevel);
//extern void LM_DrawPoint(uint x,uint y);
//extern void LM_DrawLine(uint x1,uint y1,uint x2,uint y2);

void DispIndiction(uint x,uint y,uchar *pstr);
void ClearIndiction(uint x,uint y);
void LM_WriteColumn(u8 x,u8 y,u8 CharCode);



#endif 





