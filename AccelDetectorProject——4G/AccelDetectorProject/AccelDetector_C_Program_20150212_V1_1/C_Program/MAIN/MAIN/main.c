#include <stdio.h>
#include "stm32f10x.h"
#include "nvic.h"
#include "rcc.h"
#include "usart.h"
#include "tim.h"	 
#include "delay.h"
#include "led.h"
#include "key.h"
#include "ir.h"
#include "stdio.h"
#include "rtc.h"
#include "adc.h"  
#include "disp.h"

#include "mpu6000.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "app_dmp.h"

#include "sdcard.h"
#include "diskio.h"
#include "ff.h"
#include "string.h"

#include "menu.h"
#include "item.h"

#include "param.h"
#include "flash.h"

#include "filter.h"
#include "sim900a.h"

#define DEBUG

int main(void)
{
	QElemType QElem;
	
	u8 res=1;
	u8 index  = 31; 
	int length = 0;
	char buf[500];
	char tempstr[100];
  char* str1 = "POST /api/insert/sensor/suda002 HTTP/1.1\r\nHost:115.159.190.34\r\nAccept:*/*\r\n";
	char* str2 = "Content-Type:application/json\r\nConnection:close\r\n\r\n";
	delay_init();	    	 //延时函数初始化	 
	NVIC_Config();
	RCC_Config(); 
	USART1_Config();        //log信息 9600
	USART2_Init(115200);	//初始化串口2 
// 	RTC_Config(); 
	
// 	BAT_GPIO_Config();
// 	BAT_ADC_Config();
	
// 	TIM_Config();
	
// #ifndef DEBUG
// 	IWDT_Init(4,625);//1000ms
// #endif
				  	
// 	LED_GPIO_Config();
// 	KEY_GPIO_Config();
	
	//IR_GPIO_Config();
	//IR_TIM_Config();
	//IR_Init( &IR_Frame);

	MPU6000_Config();
	UART1SendString("系统初始化完毕\r\n",strlen("系统初始化完毕\r\n"));
	
		
		
	
	//LM_GPIO_Config();		
	//LM_Init();	
	//LM_Clear();
	//LM_BL_Cmd(ENABLE);

//	DispVersionInfo();	
	//DispOneWindow(&MainMenu);
	
	InitConfigParam(&ConfigParam);
	InitMeasureParam(&MeasureParam);
	InitSchedParam(&SchedParam);
		
		res=1;
		while(res)
		{
			res=GSM_Dect();
			delay_ms(2000);
		}
	while(SD_Initialize()!=0);	
	while(1)
	{	
// #ifndef DEBUG
// 		if(TIM_IsExpired(SchedParam.IWDT_Time))
// 		{
// 			IWDT_Feed();
// 			SchedParam.IWDT_Time = TIM_GetTime() + 500;	//500ms feed IWDT		
// 		}
// #endif	
		//MENU_GetInput();
				
		//MeasureParam.OriginalAccel[0] = MPU6000_GetAccel(ACCEL_XOUT_H,ACCEL_XOUT_L);
		//MeasureParam.OriginalAccel[1] = MPU6000_GetAccel(ACCEL_YOUT_H,ACCEL_YOUT_L);		
		MeasureParam.OriginalAccel[2] = MPU6000_GetAccel(ACCEL_ZOUT_H,ACCEL_ZOUT_L);
		
		DeQueue( &QueueFilterInput,&QElem );
		EnQueue( &QueueFilterInput,MeasureParam.OriginalAccel[2]);
		
		//MeasureParam.FilteredAccel[2] = GetAverageValue(&QueueFilterInput);
//		MeasureParam.FilteredAccel[2] = ((vs16)GetMiddleValue(&QueueFilterInput)/100)*100;
		MeasureParam.FilteredAccel[2] = (GetAverageValue(&QueueFilterInput)-16384)/16384*2*9.8;
		
		res=1;
		while(res)
		{
			res=SIM900A_CONNECT_SERVER_SEND_INFOR((u8*)"115.159.190.34",(u8*)"80");
		}
		sprintf(tempstr,"{\"index\":%d,\"data\":%.2f}",index,MeasureParam.FilteredAccel[2]);
		length = strlen(tempstr);
		sprintf(buf, "%sContent-Length:%d\r\n%s%s\r\n",str1,length,str2,tempstr); 
		//sim900a_send_cmd(buf,NULL,0);
		SIM900A_GPRS_SEND_DATA((u8*)buf);
		//delay_ms(200);
		index++;
		
// 		if(TIM_IsExpired(SchedParam.TimeStamp) && (SchedParam.State != MEASURE_RIDE)) 
// 		{
// 			SchedParam.TimeStamp = TIM_GetTime() + 100;
// 			BAT_DispPower(&Bat);
// 			RTC_Display();			 
// 		}	
// 		
// 		switch(SchedParam.State)
// 		{
// 			case CONFIG_PARAM :
// 			{								
// 				ProcessConfig( & ConfigParam);
// 				
// 				if(MeasureParam.State == TRIGGER_OCCUR)
// 				{
// 					SchedParam.State = MEASURE_RIDE;
// 					SchedParam.TimeStamp = TIM_GetTime();	
// 				}
// 				
// 			}break;
// 			
// 			case MEASURE_RIDE :
// 			{
// 				ProcessMeasure( & MeasureParam);
// 			}break;
// 			
// 			default :break;
// 		}//end of switch(SchedParam.State)
 	}//end of while(1)
}//end of main










