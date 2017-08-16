		  
#ifndef _KEY_H
#define	_KEY_H

#include "stm32f10x.h"
/*---------------------------------------------------------------------------
**	Date:20140826		Editor:YZ	

**	KEY_EVENT_SHORT		短按
**	KEY_EVENT_LONG		长按
**	KEY_EVENT_DOUBLE	双击,未实现，待实现
**	同时按下多个按键	未实现，待实现

**	How to use:

	while(1)
	{
		if(TIM_IsExpired(Param.KeyScanTime))
		{
			Param.KeyScanTime = TIM_GetTime()+10;	//10ms 扫描一次
			
			KeyThis = KEY_GetValue();
			if(	(KeyThis & 0xf0) == KEY_ID_0 && (KeyThis & 0x0F) == KEY_EVENT_LONG )
				some action here;
		}
			
	}
	
		
---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
**	硬件相关宏定义
---------------------------------------------------------------------------*/

#define KEY_0_GPIO_Port	 		GPIOA
#define KEY_0_GPIO_Pin			GPIO_Pin_0
#define KEY_0_GPIO_RCC_Periph	RCC_APB2Periph_GPIOA

#define KEY_1_GPIO_Port	 		GPIOA
#define KEY_1_GPIO_Pin			GPIO_Pin_1
#define KEY_1_GPIO_RCC_Periph	RCC_APB2Periph_GPIOA

#define KEY_2_GPIO_Port	 		GPIOA
#define KEY_2_GPIO_Pin			GPIO_Pin_2
#define KEY_2_GPIO_RCC_Periph	RCC_APB2Periph_GPIOA

#define KEY_3_GPIO_Port	 		GPIOA
#define KEY_3_GPIO_Pin			GPIO_Pin_3
#define KEY_3_GPIO_RCC_Periph	RCC_APB2Periph_GPIOA

/*-----------------按键编号--------------------*/
#define KEY_ID_0                0x10
#define KEY_ID_1				0x20
#define KEY_ID_2				0x30
#define KEY_ID_3				0x40

#define KEY_ID_NONE				0x00
/*-----------------按键状态--------------------*/
#define KEY_STATE_INIT       	0x01
#define KEY_STATE_JITTER 	 	0x02
#define KEY_STATE_PRESSED	 	0x03
#define KEY_STATE_LONG       	0x04
#define KEY_STATE_RELEASED   	0x05
/*----------------按键返回键值-----------------*/
#define KEY_EVENT_SHORT				0X01
#define KEY_EVENT_LONG				0X02
#define KEY_EVENT_DOUBLE			0X03

#define KEY_EVENT_NONE				0x00
/*---------------------------------------------*/
#define KEY_ID_ESC			KEY_ID_0
#define KEY_ID_UPDOWM		KEY_ID_1
#define KEY_ID_RIGHT		KEY_ID_2
#define KEY_ID_ENTER		KEY_ID_3

extern void 			KEY_GPIO_Config(void);
extern unsigned char 	KEY_ScanPin(void);
extern unsigned char 	KEY_GetValue(void);



#endif
