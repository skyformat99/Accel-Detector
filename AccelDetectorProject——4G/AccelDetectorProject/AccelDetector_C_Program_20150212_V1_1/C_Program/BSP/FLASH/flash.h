
#ifndef _FLASH_H
#define _FLASH_H

#include "stm32f10x.h"
#include "param.h"

#define FLASH_DATA_ADDR (0X0807f800)	//page255

extern u32 FlashStoreConfigParam(u32 FlashBaseAddr,ConfigParam_t *p);
extern u32 FlashLoadConfigParam(ConfigParam_t *p,u32 FlashBaseAddr);


#endif





