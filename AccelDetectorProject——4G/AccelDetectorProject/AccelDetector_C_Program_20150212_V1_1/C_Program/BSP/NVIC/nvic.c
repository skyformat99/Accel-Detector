
#include "nvic.h"
#include "stm32f10x.h"

void NVIC_Config(void)
{	
	#ifdef  VECT_TAB_RAM  
	  /* Set the Vector Table base location at 0x20000000 */ 
	  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
	#else  /* VECT_TAB_FLASH  */
	  /* Set the Vector Table base location at 0x08000000 */ 
	  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
	#endif

	  /* Configure the NVIC Preemption Priority Bits[配置优先级组] */  
	  //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//无嵌套中断
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
}

