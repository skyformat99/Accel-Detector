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

#define	SD_CS   			PCout(4) //SD��Ƭѡ����	

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
// SD�����Ͷ���  
#define SD_TYPE_ERR     0X00
#define SD_TYPE_MMC     0X01
#define SD_TYPE_V1      0X02
#define SD_TYPE_V2      0X04
#define SD_TYPE_V2HC    0X06	   
// SD��ָ���  	   
#define CMD0    0       //����λ
#define CMD1    1
#define CMD8    8       //����8 ��SEND_IF_COND
#define CMD9    9       //����9 ����CSD����
#define CMD10   10      //����10����CID����
#define CMD12   12      //����12��ֹͣ���ݴ���
#define CMD16   16      //����16������SectorSize Ӧ����0x00
#define CMD17   17      //����17����sector
#define CMD18   18      //����18����Multi sector
#define CMD23   23      //����23�����ö�sectorд��ǰԤ�Ȳ���N��block
#define CMD24   24      //����24��дsector
#define CMD25   25      //����25��дMulti sector
#define CMD41   41      //����41��Ӧ����0x00
#define CMD55   55      //����55��Ӧ����0x01
#define CMD58   58      //����58����OCR��Ϣ
#define CMD59   59      //����59��ʹ��/��ֹCRC��Ӧ����0x00
//����д���Ӧ������
#define MSD_DATA_OK                0x05
#define MSD_DATA_CRC_ERROR         0x0B
#define MSD_DATA_WRITE_ERROR       0x0D
#define MSD_DATA_OTHER_ERROR       0xFF
//SD����Ӧ�����
#define MSD_RESPONSE_NO_ERROR      0x00
#define MSD_IN_IDLE_STATE          0x01
#define MSD_ERASE_RESET            0x02
#define MSD_ILLEGAL_COMMAND        0x04
#define MSD_COM_CRC_ERROR          0x08
#define MSD_ERASE_SEQUENCE_ERROR   0x10
#define MSD_ADDRESS_ERROR          0x20
#define MSD_PARAMETER_ERROR        0x40
#define MSD_RESPONSE_FAILURE       0xFF
 							   						 	 


extern u8  SD_Type;//SD��������

extern void SD_DisSelect(void);				//�ͷ�����
extern u8 	SD_Select(void);				//ʹ������
extern u8 	SD_WaitReady(void);				//�ȴ�SD��׼��
extern u8 	SD_GetResponse(u8 Response);
extern u8 	SD_RecvData(u8*buf,u16 len);
extern u8 	SD_SendBlock(u8*buf,u8 cmd);
extern u8 	SD_SendCmd(u8 cmd, u32 arg, u8 crc);
extern u8 	SD_GetCID(u8 *cid_data);		//��SD��CID
extern u8 	SD_GetCSD(u8 *csd_data);		//��SD��CSD
extern u32 	SD_GetSectorCount(void);		//��������

extern u8 	SD_Initialize(void);
extern u8 	SD_ReadDisk(u8*buf,u32 sector,u8 cnt);	//����
extern u8 	SD_WriteDisk(u8*buf,u32 sector,u8 cnt);	//д��
				    	                      
 
#endif
