#ifndef _SDCARD_H_
#define _SDCARD_H_		 
#include "sys.h"
#include"stm32f10x.h"


/*--------------------------------------Part 1---------------------------------------------------*/
//hardware map
//define SPI Channel right here
#define SD_USING_SPI		1
//#define SD_USING_SPI		2

#define	SD_CS_ENABLE		1
#define	SD_CS_DISABLE		0

#define	SD_CS   			PCout(4) //SD卡片选引脚	

#define SD_GPIO_CS_Port		GPIOC
#define SD_GPIO_CS_Pin		GPIO_Pin_4

#if(SD_USING_SPI == 1)

	#define SD_SPI				SPI1
	#define SD_SPI_Port			GPIOA

	#define SD_SPI_SCLK_Port	GPIOA
	#define SD_SPI_SCLK_Pin		GPIO_Pin_5

	#define SD_SPI_SDO_Port   	GPIOA
	#define SD_SPI_SDO_Pin   	GPIO_Pin_6

	#define SD_SPI_SDI_Port	GPIOA
	#define SD_SPI_SDI_Pin		GPIO_Pin_7			//PA7(STM_MOSI) TO MPU6000_SDI
		
	#define	SD_GPIO_RCC_Periph	RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOA
	#define	SD_SPI_RCC_Periph	RCC_APB2Periph_SPI1


#endif

#if(SD_USING_SPI == 2)

	#define SD_SPI				SPI2
	#define SD_SPI_Port		GPIOB

	#define SD_SPI_SCLK_Port	GPIOB
	#define SD_SPI_SCLK_Pin	GPIO_Pin_13

	#define SD_SPI_SDO_Port   	GPIOB
	#define SD_SPI_SDO_Pin   	GPIO_Pin_14

	#define SD_SPI_SDI_Port	GPIOB
	#define SD_SPI_SDI_Pin		GPIO_Pin_15

	#define	SD_GPIO_RCC_Periph	RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA
	#define	SD_SPI_RCC_Periph	RCC_APB1Periph_SPI2

#endif

extern void SD_GPIO_Config(void);
extern void SD_SPI_Config(void);
extern void SD_SPI_SpeedLow(void);
extern void SD_SPI_SpeedHigh(void);
extern u8 	SD_SPI_ReadWriteByte(u8 TxData);

/*--------------------------------------Part 2---------------------------------------------------*/	 						    	 
// SD卡类型定义  
#define SD_TYPE_ERR     0X00
#define SD_TYPE_MMC     0X01
#define SD_TYPE_V1      0X02
#define SD_TYPE_V2      0X04
#define SD_TYPE_V2HC    0X06	   
// SD卡指令表  	   
#define CMD0    0       //卡复位
#define CMD1    1
#define CMD8    8       //命令8 ，SEND_IF_COND
#define CMD9    9       //命令9 ，读CSD数据
#define CMD10   10      //命令10，读CID数据
#define CMD12   12      //命令12，停止数据传输
#define CMD16   16      //命令16，设置SectorSize 应返回0x00
#define CMD17   17      //命令17，读sector
#define CMD18   18      //命令18，读Multi sector
#define CMD23   23      //命令23，设置多sector写入前预先擦除N个block
#define CMD24   24      //命令24，写sector
#define CMD25   25      //命令25，写Multi sector
#define CMD41   41      //命令41，应返回0x00
#define CMD55   55      //命令55，应返回0x01
#define CMD58   58      //命令58，读OCR信息
#define CMD59   59      //命令59，使能/禁止CRC，应返回0x00
//数据写入回应字意义
#define MSD_DATA_OK                0x05
#define MSD_DATA_CRC_ERROR         0x0B
#define MSD_DATA_WRITE_ERROR       0x0D
#define MSD_DATA_OTHER_ERROR       0xFF
//SD卡回应标记字
#define MSD_RESPONSE_NO_ERROR      0x00
#define MSD_IN_IDLE_STATE          0x01
#define MSD_ERASE_RESET            0x02
#define MSD_ILLEGAL_COMMAND        0x04
#define MSD_COM_CRC_ERROR          0x08
#define MSD_ERASE_SEQUENCE_ERROR   0x10
#define MSD_ADDRESS_ERROR          0x20
#define MSD_PARAMETER_ERROR        0x40
#define MSD_RESPONSE_FAILURE       0xFF
 							   						 	 


extern u8  SD_Type;//SD卡的类型

extern void SD_DisSelect(void);				//释放总线
extern u8 	SD_Select(void);				//使能总线
extern u8 	SD_WaitReady(void);				//等待SD卡准备
extern u8 	SD_GetResponse(u8 Response);
extern u8 	SD_RecvData(u8*buf,u16 len);
extern u8 	SD_SendBlock(u8*buf,u8 cmd);
extern u8 	SD_SendCmd(u8 cmd, u32 arg, u8 crc);
extern u8 	SD_GetCID(u8 *cid_data);		//读SD卡CID
extern u8 	SD_GetCSD(u8 *csd_data);		//读SD卡CSD
extern u32 	SD_GetSectorCount(void);		//读扇区数

extern u8 	SD_Initialize(void);
extern u8 	SD_ReadDisk(u8*buf,u32 sector,u8 cnt);	//读块
extern u8 	SD_WriteDisk(u8*buf,u32 sector,u8 cnt);	//写块
				    	                      
 
#endif
