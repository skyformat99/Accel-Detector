
#include "stm32f10x.h"
#include "flash.h"
#include "param.h"
#include "string.h"

u32 FlashStoreConfigParam(u32 FlashBaseAddr,ConfigParam_t *p)
{
	//time sequence: read->modify->write
	//erase firsly,then write with format of vu32
	
	u32 i;
	ConfigParam_t	TempConfigparam;
	vu32 			*BasePtr = (vu32 *)&TempConfigparam;//for write back

	FLASH_Status FlashStatus = FLASH_COMPLETE; 	
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	
	memcpy(&TempConfigparam,p,sizeof(ConfigParam_t));//read
	
	TempConfigparam.CtrlMode = p->CtrlMode;
	//modify other config param here
//	TempConfigparam.StaticAccelValue[0] = p->StaticAccelValue[0]; 
//	TempConfigparam.StaticAccelValue[1] = p->StaticAccelValue[1]; 
//	TempConfigparam.StaticAccelValue[2] = p->StaticAccelValue[2]; 
	
	TempConfigparam.RangeSelected = p->RangeSelected;
	
	FlashStatus = FLASH_ErasePage(FlashBaseAddr);
	if(FlashStatus != FLASH_COMPLETE)
		return 1;
	
	for(i=0;i<sizeof(ConfigParam_t)/sizeof(vu32);i++)
	{
		FlashStatus = FLASH_ProgramWord( FlashBaseAddr + i*4, *BasePtr++);
	}
	
	FLASH_Lock();
	
	return 0;		
}

u32 FlashLoadConfigParam(ConfigParam_t *p,u32 FlashBaseAddr)
{
	p->CtrlMode = ((ConfigParam_t *)FlashBaseAddr)->CtrlMode;
	// load other config param,never load TimeStamp and other state var
//	p->StaticAccelValue[0] = ((ConfigParam_t *)FlashBaseAddr)->StaticAccelValue[0] ; 
//	p->StaticAccelValue[1] = ((ConfigParam_t *)FlashBaseAddr)->StaticAccelValue[1]; 
//	p->StaticAccelValue[2] = ((ConfigParam_t *)FlashBaseAddr)->StaticAccelValue[2]; 
	
	p->RangeSelected = ((ConfigParam_t *)FlashBaseAddr)->RangeSelected;
	
	return 0;
}





