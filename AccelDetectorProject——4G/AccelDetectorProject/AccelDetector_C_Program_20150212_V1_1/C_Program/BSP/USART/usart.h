#ifndef _UART_H
#define _UART_H

#include "stm32f10x.h"
/*---------------------------------------------------------------------------
**	Ӳ����غ궨��
---------------------------------------------------------------------------*/
#define USART2_MAX_RECV_LEN		1024				//�����ջ����ֽ���
#define USART2_MAX_SEND_LEN		1024				//����ͻ����ֽ���
#define USART2_RX_EN 			1					//0,������;1,����.

extern u8  USART2_RX_BUF[USART2_MAX_RECV_LEN]; 		//���ջ���,���USART2_MAX_RECV_LEN�ֽ�
extern u8  USART2_TX_BUF[USART2_MAX_SEND_LEN]; 		//���ͻ���,���USART2_MAX_SEND_LEN�ֽ�
extern u16 USART2_RX_STA;   						//��������״̬
extern u8 USART2_RX_REC_ATCOMMAD;


#define	DBG_TX_Port				GPIOA
#define	DBG_TX_Pin				GPIO_Pin_9
#define	DBG_TX_RCC_Periph		(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA)

#define	DBG_RX_Port				GPIOA
#define	DBG_RX_Pin				GPIO_Pin_10
#define	DBG_RX_RCC_Periph		(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA)

extern void USART1_Config(void);
void UART1SendString(u8 *cmd,u16 len);
void UART1SendByte(unsigned char SendData);
void USART2_Init(u32 bound);				//����2��ʼ��
void UART_DMA_Config(DMA_Channel_TypeDef*DMA_CHx,u32 cpar,u32 cmar);
void UART_DMA_Enable(DMA_Channel_TypeDef*DMA_CHx,u16 len);
void TIM4_Set(u8 sta);
void TIM4_Init(u16 arr,u16 psc);
void u2_printf(char* fmt, ...);
#endif


