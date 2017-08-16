
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

	  /* Configure the NVIC Preemption Priority Bits[�������ȼ���] */  
	  //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//��Ƕ���ж�
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
}

