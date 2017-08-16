

#ifndef _IR_H
#define _IR_H

#include "stm32f10x.h"
/*-----------------------------------------------------
1(0x00)		2(0x01)		3(0x02)	
4(0x04)		5(0x05)		6(0x06)		
7(0x08)		8(0x09)		9(0x0a)	
*(0x0c)		0(0x0d)		#(0x0e)	

			up(0x11)	
left(0x14)	ok(0x15)	right(0x16)	
			dn(0x19)	
			
//redefinied 

-----------------------------------------------------*/
#define IR_PAD_NUM_1	0x00
#define IR_PAD_NUM_2	0x01
#define IR_PAD_NUM_3	0x02
#define IR_PAD_NUM_4	0x04
#define IR_PAD_NUM_5	0x05
#define IR_PAD_NUM_6	0x06
#define IR_PAD_NUM_7	0x08
#define IR_PAD_NUM_8	0x09
#define IR_PAD_NUM_9	0x0A
#define IR_PAD_STAR		0x0C
#define IR_PAD_NUM_0	0x0D
#define IR_PAD_CROSS	0x0E

#define IR_PAD_UP		0x11
#define IR_PAD_LEFT		0x14
#define IR_PAD_OK		0x15
#define IR_PAD_RIGHT	0x16
#define IR_PAD_DN		0x19

#define IR_CTRL_ID		0X00

typedef enum
{
	IR_GET_HEADER,
	IR_GET_ADDR,
	IR_GET_ADDR_COMP,
	IR_GET_CMD,
	IR_GET_CMD_COMP,
	IR_GET_END,
	IR_GET_CNT,

}IR_FrameState_t;

typedef union
{
	vu32 BitStream;
	
	struct
	{
		vu8 Addr;
		vu8 AddrComp;
		vu8 Cmd;
		vu8 CmdComp;
	}Structure;
		
}IR_FrameBuffer_t;

typedef struct
{
	IR_FrameState_t		State;
	IR_FrameBuffer_t	Buffer;
	u32 TimeStamp;
	u32 PreTime;
	u32 ThisTime;
	u32	RcvBitCnt;
	u32	IsRcvNewFrame;

}IR_Frame_t;

#define IR_GPIO_Port	 		GPIOC
#define IR_GPIO_Pin				GPIO_Pin_1
#define IR_GPIO_RCC_Periph		RCC_APB2Periph_GPIOC

#define IR_GPIO_INT_Port_Source 	GPIO_PortSourceGPIOC
#define IR_GPIO_INT_Pin_Source 		GPIO_PinSource1
#define IR_GPIO_INT_EXTI_Line 		EXTI_Line1
#define IR_GPIO_INT_NVIC_Channel	EXTI1_IRQn

extern IR_Frame_t	IR_Frame;
extern vu32			G_IsIrEventOccured;

void IR_GPIO_Config(void);
void IR_TIM_Config(void);
u32  IR_GetTime(void);
u8   IR_IsTimeExpired(u32 PeriodBased100us);
void IR_Init(IR_Frame_t	*p);
void IR_Process(IR_Frame_t	*p);

unsigned char IR_GetValue(void);

#endif



