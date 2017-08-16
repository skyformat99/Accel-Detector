
#include"stm32f10x.h"
#include"led.h"
/*---------------------------------------------------------------------------
**	Function	:	LED_GPIO_Config
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:	注意修改.h文件中的硬件相关宏
---------------------------------------------------------------------------*/
void LED_GPIO_Config()
{	
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(LED_0_GPIO_RCC_Periph,ENABLE);	
   	RCC_APB2PeriphClockCmd(LED_1_GPIO_RCC_Periph,ENABLE);

	GPIO_InitStructure.GPIO_Pin =  LED_0_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_0_GPIO_Port, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  LED_1_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_1_GPIO_Port, &GPIO_InitStructure);

	//Initial OFF
	//GPIO_WriteBit(LED_0_GPIO_Port, LED_0_GPIO_Pin, 1);
	//GPIO_WriteBit(LED_1_GPIO_Port, LED_1_GPIO_Pin, 1);
}
