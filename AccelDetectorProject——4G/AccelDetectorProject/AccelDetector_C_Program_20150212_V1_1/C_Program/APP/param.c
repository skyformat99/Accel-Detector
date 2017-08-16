
#include "param.h"
#include "tim.h"

#include "ff.h"
#include "rtc.h"
#include "lm240120.h"
#include "disp.h"
#include "adc.h"
#include "graph.h"
#include "led.h"
#include "key.h"
#include "ir.h"
#include "menu.h"
#include "item.h"
#include "flash.h"
#include "stdio.h"
#include "filter.h"
#include "mpu6000.h"


SchedParam_t	SchedParam;
MeasureParam_t	MeasureParam;
ConfigParam_t	ConfigParam;
/*--------------------------------------------------------------------------*/
void InitSchedParam(SchedParam_t *p)
{
	p->State = CONFIG_PARAM;
	p->TimeStamp = TIM_GetTime();
	p->IWDT_Time = TIM_GetTime();	
	
	Bat.XLength = 16;
	Bat.YLength = 8;
	Bat.X = 220;
	Bat.Y = 0;
	Bat.EmptyPercent = 80;
	
}
/*--------------------------------------------------------------------------*/
void InitConfigParam(ConfigParam_t *p)
{	
	FlashLoadConfigParam(&ConfigParam,FLASH_DATA_ADDR);
	
	if(p->CtrlMode != IR_CTRL && p->CtrlMode != KEY_CTRL)//new chip,first program
	{
		p->CtrlMode = KEY_CTRL;
		
		FlashStoreConfigParam(FLASH_DATA_ADDR,&ConfigParam);
		FlashLoadConfigParam(&ConfigParam,FLASH_DATA_ADDR);
	}
	
	if(p->RangeSelected != 0 && p->RangeSelected != 1 && p->RangeSelected != 2 )
	{
		p->RangeSelected = 0;
		FlashStoreConfigParam(FLASH_DATA_ADDR,&ConfigParam);
		FlashLoadConfigParam(&ConfigParam,FLASH_DATA_ADDR);		
	}
	
	p->TimeStamp = TIM_GetTime();
	p->CalibrateTimeStamp = TIM_GetTime();
}

void ProcessConfig(ConfigParam_t *p)
{
	char AccelString[3][15];
		
	switch(p->State)
	{
		case INIT_CONFIG_PARAM:
		{
					
		}break;
		
		case START_CALIBRATE:
		{	
			p->StaticAccelSum[2] += MeasureParam.OriginalAccel[2];
			p->StaticAccelCnt[2] += 1;
			if(p->StaticAccelCnt[2] != 0)
				p->StaticAccelValue[2] = p->StaticAccelSum[2]/p->StaticAccelCnt[2];
			
			if(TIM_IsExpired(p->CalibrateTimeStamp))
			{
				p->CalibrateTimeStamp = TIM_GetTime()+ 500;
				
				GPIO_WriteBit(	LED_1_GPIO_Port, LED_1_GPIO_Pin, 
							(BitAction)(GPIO_ReadInputDataBit(LED_1_GPIO_Port, LED_1_GPIO_Pin)^0x01));
				
				sprintf(AccelString[0],"X:%6d",MeasureParam.OriginalAccel[0]);
				sprintf(AccelString[1],"Y:%6d",MeasureParam.OriginalAccel[1]);
				sprintf(AccelString[2],"Z:%6d",MeasureParam.OriginalAccel[2]);
				
				LM_DispStr(8,4,AccelString[0]);
				LM_DispStr(8,6,AccelString[1]);
				LM_DispStr(8,8,AccelString[2]);
				
				sprintf(AccelString[2],"SZ:%4f",ConfigParam.StaticAccelValue[2]);
				
				LM_DispStr(80,8,AccelString[2]);								
			}
			// caculate calibrate data here
			if(TIM_IsExpired(p->CalibrateTimeAutoStop + 5000))//no change within 5 senconds
			{				
				if(  0.5 > p->PreviousStaticAccelValue[2] - p->StaticAccelValue[2] && 
					-0.5 < p->PreviousStaticAccelValue[2] - p->StaticAccelValue[2])
				{
					ConfigParam.State = FINISH_CALIBRATE;
					ConfigParam.TimeStamp = TIM_GetTime();					
				}	

				p->CalibrateTimeAutoStop = TIM_GetTime();
				p->PreviousStaticAccelValue[2] = p->StaticAccelValue[2];				
			}
			else
			{
				if(  0.5 < p->PreviousStaticAccelValue[2] - p->StaticAccelValue[2] || 
					-0.5 > p->PreviousStaticAccelValue[2] - p->StaticAccelValue[2])
				{
					p->CalibrateTimeAutoStop = TIM_GetTime();
					p->PreviousStaticAccelValue[2] = p->StaticAccelValue[2];
				}
			}												
		}break;
		
		case FINISH_CALIBRATE:
		{
			//store calibrate data to flash
			//load  calibrate data from flash			
			GPIO_WriteBit(	LED_1_GPIO_Port, LED_1_GPIO_Pin,(BitAction)0);
			ClearIndiction(60,11);
			DispIndiction(8,11,"Calibration Succeed");
			
			p->State = INIT_CONFIG_PARAM;
			p->TimeStamp = TIM_GetTime();			
		}
		
		default:break;
	}		
}

/*--------------------------------------------------------------------------*/
void InitMeasureParam(MeasureParam_t *p)
{
	InitQueue( &QueueFilterInput);
	while(GetQueueState( &QueueFilterInput) != QUEUE_FULL)
	{
		MeasureParam.OriginalAccel[0] = MPU6000_GetAccel(ACCEL_XOUT_H,ACCEL_XOUT_L);
		MeasureParam.OriginalAccel[1] = MPU6000_GetAccel(ACCEL_YOUT_H,ACCEL_YOUT_L);		
		MeasureParam.OriginalAccel[2] = MPU6000_GetAccel(ACCEL_ZOUT_H,ACCEL_ZOUT_L);
		
		 EnQueue(&QueueFilterInput,MeasureParam.OriginalAccel[2]);
	}
	
	p->FilePathPtr = NULL;
	if(f_mount(0,& p->FatFs) != FR_OK)
	{
		DispIndiction(60,11,"f_mount failed");
		p->State = INIT_FS;
		p->TimeStamp = TIM_GetTime();
	}
	else
	{
		p->State = WAIT_FOR_NEXT_TRIGGER;
		p->TimeStamp = TIM_GetTime();
	}
}

void ProcessMeasure(MeasureParam_t *p)
{	
	switch(p->State)
	{
		case INIT_MEASURE_PARAM :
		{
			
		}break;
		
		case INIT_FS :
		{
			if(f_mount(0,& p->FatFs) != FR_OK)
			{
				DispIndiction(60,11,"f_mount failed");
				p->State = INIT_FS;
				p->TimeStamp = TIM_GetTime();
			}
			else
			{
				p->State = WAIT_FOR_NEXT_TRIGGER;
				p->TimeStamp = TIM_GetTime();
			}
		}break;
		
		case WAIT_FOR_NEXT_TRIGGER :
		{			
			p->TimeStamp = TIM_GetTime();
			
		}break;
		
		case TRIGGER_OCCUR :	//trigger by item_start
		{
			ClearIndiction(60,11);
			
			p->State = TRIGGER_DELAY;
			p->TimeStamp = TIM_GetTime();			
		}break;
		
		case TRIGGER_DELAY :
		{
			if(ConfigParam.CtrlMode == IR_CTRL)
			{
				p->State = GET_FILE_PATH;
				p->TimeStamp = TIM_GetTime();
			}
			else
			{
				if(TIM_IsExpired(p->TimeStamp + 2000))
				{
					p->State = GET_FILE_PATH;
					p->TimeStamp = TIM_GetTime();
				}
				else
				{
					BAT_DispPower(&Bat);
					RTC_Display();
					DispIndiction(60,11,"Trigger Delay");
				}
			}
		}break;
		
		case GET_FILE_PATH :
		{
			/*"MON JUN 23 18:06:15 20140"*/
			p->FilePathPtr = RTC_GetCalStr();
			/*"2014 18_06_15 MON JUN 23.txt"*/
			p->FilePath[0] = p->FilePathPtr[20];//2
			p->FilePath[1] = p->FilePathPtr[21];//0
			p->FilePath[2] = p->FilePathPtr[22];//1
			p->FilePath[3] = p->FilePathPtr[23];//4
			p->FilePath[4] = ' ';
			p->FilePath[5] = p->FilePathPtr[11];//1
			p->FilePath[6] = p->FilePathPtr[12];//8
			p->FilePath[7] = '_';
			p->FilePath[8] = p->FilePathPtr[14];//0
			p->FilePath[9] = p->FilePathPtr[15];//6
			p->FilePath[10] ='_';
			p->FilePath[11] = p->FilePathPtr[17];//1
			p->FilePath[12] = p->FilePathPtr[18];//5
			p->FilePath[13] = ' ';
			p->FilePath[14] = p->FilePathPtr[0];//M
			p->FilePath[15] = p->FilePathPtr[1];//O
			p->FilePath[16] = p->FilePathPtr[2];//N
			p->FilePath[17] = ' ';
			p->FilePath[18] = p->FilePathPtr[4];//J
			p->FilePath[19] = p->FilePathPtr[5];//U
			p->FilePath[20] = p->FilePathPtr[6];//N
			p->FilePath[21] = ' ';
			p->FilePath[22] = p->FilePathPtr[8];//2
			p->FilePath[23] = p->FilePathPtr[9];//3
			p->FilePath[24] = '.';
			p->FilePath[25] = 't';
			p->FilePath[26] = 'x';
			p->FilePath[27] = 't';
			
			p->State = OPEN_FILE;
			p->TimeStamp = TIM_GetTime();
		}
		
		case OPEN_FILE :
		{			
			if(	f_open(	&p->File,p->FilePath,FA_CREATE_ALWAYS|FA_WRITE) != FR_OK)
			{	
				DispIndiction(60,11,"f_open failed");
				
				SchedParam.State = CONFIG_PARAM;
				SchedParam.TimeStamp = TIM_GetTime();
				
				InheritStart.State = INIT;
				InheritStart.Time = TIM_GetTime();
								
				p->State = INIT_FS;
				p->TimeStamp = TIM_GetTime();
			}
			else
			{		
				p->State = STORE_DATA;
				p->TimeStamp = TIM_GetTime();
				InitGraphParam(& GraphParam );
			}
		}break;
		
		case STORE_DATA :
		{	
			if(TIM_IsExpired(p->TimeStamp))
			{
				p->TimeStamp = TIM_GetTime()+ STORE_DATA_INTERVAL;
			
				f_printf(	&(p->File),"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
							p->OriginalAccel[0],p->OriginalAccel[1],p->OriginalAccel[2],
							0,0,0,TIM_GetTime());
			}
						
			ProcessGraph(& GraphParam);	//added by yz 2015-02-05
			
		}break;
		
		case CLOSE_FILE :	//trigger by item_stop
		{
			if(f_close(&p->File) !=FR_OK)
			{
//				LM_Clear();
				DispIndiction(60,11,"f_close failed");				
			}
			else
			{
				GPIO_WriteBit(	LED_1_GPIO_Port, LED_1_GPIO_Pin, (BitAction)0);				
				LM_Clear();
				DispOneWindow( & MeasureMenu);
				DispIndiction(60,11,"Measure Succeed");
				
				SchedParam.State = CONFIG_PARAM;
				SchedParam.TimeStamp = TIM_GetTime();
				
				p->State = WAIT_FOR_NEXT_TRIGGER;
				p->TimeStamp = TIM_GetTime();
			}
		}break;
		
		default :break;
	}		
}

