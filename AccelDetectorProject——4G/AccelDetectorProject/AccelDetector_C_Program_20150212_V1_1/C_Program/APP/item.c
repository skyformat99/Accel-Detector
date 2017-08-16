
#include "item.h"
#include "menu.h"
#include "rtc.h"
#include "lm240120.h"
#include "param.h"
#include "tim.h"
#include "led.h"
#include "flash.h"

ItemInherit_t	InheritSetTimeData = {INIT};
ItemInherit_t	InheritStart = {INIT};
ItemInherit_t	InheritExit = {INIT};
ItemInherit_t	InheritCalibrate = {INIT};

/*------------------------Menu & Item Obj---------------------------------------------*/
												 //FirstItem,CurrntFocus
Window_t	MainMenu = 			{"Main Menu",60,0,&Measure,NULL};
Window_t	ConfigureMenu = 	{"Configure Menu",60,0,&SetRange,NULL};
Window_t	MeasureMenu = 		{"Measure Menu",60,0,&Start,NULL};
Window_t	SetCtrlModeMenu = 	{"Set Ctrl Mode",60,0,&IR_CtrlMode,NULL};
Window_t	SetRangeMenu = 		{"Set Range",60,0,&SetRange_1,NULL};

/*-----------------------------------------------------------------------------------
1,next brother field shoud never be NULL
2,All items in one specific windows Obj construct cycle-linked-list
3,If next brother appear as NULL, one NULL pointer dereference will case haed fault
----------------------------------------------------------------------------------*/													//Window,Father,BigSon,NextBrother
Item_t		Measure = 		{"Measure",60,4,&MainMenu,NULL,&Start,&Calibrate};

Item_t		Calibrate = 		{"Calibrate",60,6,&MainMenu,NULL,NULL,&Configure,
									Esc_Calibrate,
									UpDn_Calibrate,
									Right_Calibrate,
									Enter_Calibrate};

Item_t		Configure = 	{"Configure",60,8,&MainMenu,NULL,&SetRange,&Measure};									


/*------------------------------*/
Item_t		SetRange = 			{"Set Range",60,4,&ConfigureMenu,&Configure,&SetRange_1,&SetCtrlMode};
Item_t		SetCtrlMode = 		{"Set Ctrl Mode",60,6,&ConfigureMenu,&Configure,&IR_CtrlMode,&SetTimeDate};
Item_t		SetTimeDate = 		{"Set Time & Date",60,8,&ConfigureMenu,&Configure,NULL,&SetRange,
									Esc_SetTimeDate,
									UpDn_SetTimeDate,
									Right_SetTimeDate,
									Enter_SetTimeDate};
/*------------------------------*/
Item_t		Start = {	"Start",60,4,&MeasureMenu,&Measure,NULL,&Exit,
						Esc_Start,
						UpDn_Start,
						Right_Start,
						Enter_Start};
Item_t		Exit = 	{	"Exit",60,6,&MeasureMenu,&Measure,NULL,&Start,
						Esc_Exit,
						UpDn_Exit,
						Right_Exit,
						Enter_Exit};

Item_t		IR_CtrlMode = 	{	"IR",60,4,&SetCtrlModeMenu,&SetCtrlMode,NULL,&KEY_CtrlMode,
								NULL,
								NULL,
								NULL,
								Enter_IR_CtrlMode};

Item_t		KEY_CtrlMode = {	"KEY",60,6,&SetCtrlModeMenu,&SetCtrlMode,NULL,&IR_CtrlMode,
								NULL,
								NULL,
								NULL,
								Enter_KEY_CtrlMode};

Item_t		SetRange_1 = 	{"0.1 G , 1.0 M/S",60,4,&SetRangeMenu,&SetRange,NULL,&SetRange_2,
								NULL,
								NULL,
								NULL,
								Enter_SetRange_1};

Item_t		SetRange_2 = 	{"0.2 G , 2.0 M/S",60,6,&SetRangeMenu,&SetRange,NULL,&SetRange_3,
								NULL,
								NULL,
								NULL,
								Enter_SetRange_2};

Item_t		SetRange_3 = 	{"0.4 G , 4.0 M/S",60,8,&SetRangeMenu,&SetRange,NULL,&SetRange_1,
								NULL,
								NULL,
								NULL,							
								Enter_SetRange_3};
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void UserInputSelectOneBit(ItemInput_t *Ptr)
{
	LM_DispCharWithLine(Ptr->X,Ptr->Y,Ptr->BitNum + 0x30);
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void UserInputDisSelectOneBit(ItemInput_t *Ptr)
{
	LM_DispChar(Ptr->X,Ptr->Y,' ');
	LM_DispChar(Ptr->X,Ptr->Y,Ptr->BitNum + 0x30);
}

void Esc_SetTimeDate()
{
	switch(InheritSetTimeData.State)
	{
		case INIT:
		{
			Esc_Com();			
		}break;
		
		case PROCESS:
		{
			InheritSetTimeData.State = INIT;
			InheritSetTimeData.Focus  = 13;
			
			DispOneWindow(& ConfigureMenu);
			
		}break;
			
		default:break;
		
	}	
}

void UpDn_SetTimeDate()
{
	if(InheritSetTimeData.State == PROCESS)
	{
		InheritSetTimeData.Input[InheritSetTimeData.Focus].BitNum++;
		if(InheritSetTimeData.Input[InheritSetTimeData.Focus].BitNum >9)
			InheritSetTimeData.Input[InheritSetTimeData.Focus].BitNum = 0;
		//year:1xxx or 2xxx
		if(InheritSetTimeData.Input[13].BitNum > 2)
			InheritSetTimeData.Input[13].BitNum = 1;	
		//mon:0x or 1x
		if(InheritSetTimeData.Input[9].BitNum > 1)
			InheritSetTimeData.Input[9].BitNum = 0;	
		if(InheritSetTimeData.Input[9].BitNum == 1)
		{
			if(InheritSetTimeData.Input[8].BitNum > 2)
				InheritSetTimeData.Input[8].BitNum = 0;	
		}
		//day:0x , 1x, 2x, or 3x
		if(InheritSetTimeData.Input[7].BitNum > 3)
			InheritSetTimeData.Input[7].BitNum = 0;
		
		if(InheritSetTimeData.Input[7].BitNum == 3)
		{
			if(InheritSetTimeData.Input[6].BitNum > 1)
				InheritSetTimeData.Input[6].BitNum = 0;	
		}
		//hour:0x,1x,2x
		if(InheritSetTimeData.Input[5].BitNum > 2)
			InheritSetTimeData.Input[5].BitNum = 0;
		
		if(InheritSetTimeData.Input[5].BitNum == 2)
		{
			if(InheritSetTimeData.Input[4].BitNum > 3)
				InheritSetTimeData.Input[4].BitNum = 0;
		}
		
		if(InheritSetTimeData.Input[3].BitNum > 5)
			InheritSetTimeData.Input[3].BitNum = 0;
		
		if(InheritSetTimeData.Input[1].BitNum > 5)
			InheritSetTimeData.Input[1].BitNum = 0;
		
		LM_DispCharWithLine(	InheritSetTimeData.Input[InheritSetTimeData.Focus].X,
								InheritSetTimeData.Input[InheritSetTimeData.Focus].Y,
								InheritSetTimeData.Input[InheritSetTimeData.Focus].BitNum+0x30);
	}
	else
	{
		UpDn_Com();
	}
}

void Right_SetTimeDate()
{
	if(InheritSetTimeData.State == PROCESS)
	{
		InheritSetTimeData.Focus--;
		if(InheritSetTimeData.Focus < 0)
		{
			InheritSetTimeData.Focus = 13;
			UserInputSelectOneBit(&InheritSetTimeData.Input[InheritSetTimeData.Focus]);
			UserInputDisSelectOneBit(&InheritSetTimeData.Input[0]);
			return;		
		}
				
		UserInputSelectOneBit(&InheritSetTimeData.Input[InheritSetTimeData.Focus]);	
		UserInputDisSelectOneBit(&InheritSetTimeData.Input[InheritSetTimeData.Focus + 1]);
	}
}

void Enter_SetTimeDate()
{
	static RTC_Cal_t RTC_CalSet;
	u8 i;
	switch(InheritSetTimeData.State)
	{
		case INIT :
		{
			InheritSetTimeData.State = PROCESS;
			
			LM_Clear();
			LM_DispStr(60,0,(char *)"Set Time & Date");
			DispIndiction(20,11,"Press Enter To Save");
			
			InheritSetTimeData.Input[13].BitNum = (RTC_GetCal()->tm_year + 1900)/1000;
			InheritSetTimeData.Input[13].X = 68;InheritSetTimeData.Input[13].Y = 4;
			
			InheritSetTimeData.Input[12].BitNum = ((RTC_GetCal()->tm_year + 1900)/100)%10;
			InheritSetTimeData.Input[12].X = 76;InheritSetTimeData.Input[12].Y = 4;

			InheritSetTimeData.Input[11].BitNum = ((RTC_GetCal()->tm_year + 1900)/10)%10;
			InheritSetTimeData.Input[11].X = 84;InheritSetTimeData.Input[11].Y = 4;

			InheritSetTimeData.Input[10].BitNum = (RTC_GetCal()->tm_year + 1900)%10;
			InheritSetTimeData.Input[10].X = 92;InheritSetTimeData.Input[10].Y = 4;
			
			LM_DispChar(100,4,'-');
			InheritSetTimeData.Input[9].BitNum =( RTC_GetCal()->tm_mon +1)/10;
			InheritSetTimeData.Input[9].X = 108;InheritSetTimeData.Input[9].Y = 4;

			InheritSetTimeData.Input[8].BitNum =( RTC_GetCal()->tm_mon + 1)%10;
			InheritSetTimeData.Input[8].X = 116;InheritSetTimeData.Input[8].Y = 4;
			
			LM_DispChar(124,4,'-');
			InheritSetTimeData.Input[7].BitNum = RTC_GetCal()->tm_mday/10;
			InheritSetTimeData.Input[7].X = 132;InheritSetTimeData.Input[7].Y = 4;

			InheritSetTimeData.Input[6].BitNum = RTC_GetCal()->tm_mday%10;
			InheritSetTimeData.Input[6].X = 140;InheritSetTimeData.Input[6].Y = 4;
			
			InheritSetTimeData.Input[5].BitNum = RTC_GetCal()->tm_hour /10;
			InheritSetTimeData.Input[5].X = 68;InheritSetTimeData.Input[5].Y = 6;

			InheritSetTimeData.Input[4].BitNum = RTC_GetCal()->tm_hour%10;
			InheritSetTimeData.Input[4].X = 76;InheritSetTimeData.Input[4].Y = 6;

			LM_DispChar(84,6,':');
			InheritSetTimeData.Input[3].BitNum = RTC_GetCal()->tm_min/10;
			InheritSetTimeData.Input[3].X = 92;InheritSetTimeData.Input[3].Y = 6;

			InheritSetTimeData.Input[2].BitNum = RTC_GetCal()->tm_min%10;
			InheritSetTimeData.Input[2].X = 100;InheritSetTimeData.Input[2].Y = 6;

			LM_DispChar(108,6,':');
			InheritSetTimeData.Input[1].BitNum = RTC_GetCal()->tm_sec/10;
			InheritSetTimeData.Input[1].X = 116;InheritSetTimeData.Input[1].Y = 6;

			InheritSetTimeData.Input[0].BitNum = RTC_GetCal()->tm_sec%10;
			InheritSetTimeData.Input[0].X = 124;InheritSetTimeData.Input[0].Y = 6;
			
			for(i=0;i<14;i++)
			{
				LM_DispChar(InheritSetTimeData.Input[i].X,
							InheritSetTimeData.Input[i].Y,
							InheritSetTimeData.Input[i].BitNum+0x30);
			}

			UserInputSelectOneBit(&InheritSetTimeData.Input[InheritSetTimeData.Focus]);
		}break;
		
		case PROCESS :
		{
			RTC_CalSet.tm_year = 	InheritSetTimeData.Input[13].BitNum*1000+
									InheritSetTimeData.Input[12].BitNum*100+
									InheritSetTimeData.Input[11].BitNum*10+
									InheritSetTimeData.Input[10].BitNum;
			RTC_CalSet.tm_mon = 	InheritSetTimeData.Input[9].BitNum*10 + 
									InheritSetTimeData.Input[8].BitNum;
			RTC_CalSet.tm_mday = 	InheritSetTimeData.Input[7].BitNum*10+
									InheritSetTimeData.Input[6].BitNum;		
			RTC_CalSet.tm_hour =  	InheritSetTimeData.Input[5].BitNum*10+
									InheritSetTimeData.Input[4].BitNum + 8;
			RTC_CalSet.tm_min =  	InheritSetTimeData.Input[3].BitNum*10+
									InheritSetTimeData.Input[2].BitNum;
			RTC_CalSet.tm_sec =  	InheritSetTimeData.Input[1].BitNum*10+
									InheritSetTimeData.Input[0].BitNum;

			RTC_Configuration();
			RTC_SetCal(&RTC_CalSet);
			BKP_WriteBackupRegister(BKP_DR1, YZ_RTC_SPECIAL_CHECK);
			
		}break;
				
		default :break;
	}	
}


void Esc_Start(void)
{
	switch(InheritStart.State)
	{
		case INIT:
		{
			Esc_Com();			
		}break;
		
		case PROCESS:
		{	
			if(MeasureParam.State == STORE_DATA )
			{
				InheritStart.State = INIT;
				InheritStart.Time = TIM_GetTime();
				
				MeasureParam.State = CLOSE_FILE;
				MeasureParam.TimeStamp = TIM_GetTime();		
			}
												
		}break;
		
		default:break;
	}
		
	
}

void UpDn_Start(void)
{
	switch(InheritStart.State)
	{
		case INIT:
		{
			UpDn_Com();
		}break;
		
		default:break;
	}
	
}
void Right_Start(void)
{

}

void Enter_Start(void)
{
	switch(InheritStart.State)
	{
		case INIT:
		{						
			if(MeasureParam.State == WAIT_FOR_NEXT_TRIGGER || MeasureParam.State == INIT_FS)
			{	
				InheritStart.State = PROCESS;
				InheritStart.Time = TIM_GetTime();
				
				MeasureParam.State = TRIGGER_OCCUR;
				MeasureParam.TimeStamp = TIM_GetTime();		
			}							
		}break;
		
		case PROCESS:
		{
			
		}break;
		
		default:break;
	}
	
	
}
void Esc_Exit(void)
{
	Esc_Com();
}
void UpDn_Exit(void)
{
	UpDn_Com();
}
void Right_Exit(void)
{
	Right_Com();	//select next brother
}
void Enter_Exit(void)
{
	Esc_Com();	
}

void Enter_IR_CtrlMode(void)
{
	if(ConfigParam.CtrlMode == IR_CTRL)
	{
		ClearIndiction(60,11);
		DispIndiction(60,11,"Already IR Mode");
	}
	
	if(ConfigParam.CtrlMode == KEY_CTRL)
	{
		ConfigParam.CtrlMode = IR_CTRL;
		FlashStoreConfigParam(FLASH_DATA_ADDR,&ConfigParam);
		ClearIndiction(60,11);
		DispIndiction(60,11,"IR Mode Set Success");		
	}	
}

void Enter_KEY_CtrlMode(void)
{
	if(ConfigParam.CtrlMode == KEY_CTRL)
	{
		ClearIndiction(60,11);
		DispIndiction(60,11,"Already KEY Mode");
	}
	
	if(ConfigParam.CtrlMode == IR_CTRL)
	{
		ConfigParam.CtrlMode = KEY_CTRL;
		FlashStoreConfigParam(FLASH_DATA_ADDR,&ConfigParam);
		ClearIndiction(60,11);
		DispIndiction(60,11,"KEY Mode Set Success");	
	}			
}

void Esc_Calibrate(void)
{
	static u8 i=0;
	
	switch(InheritCalibrate.State)
	{
		case INIT:
		{
			Esc_Com();
		}break;
		
		case PROCESS:
		{	
			if(ConfigParam.State == INIT_CONFIG_PARAM)	//Auto Stop
			{				
				i=0;
				InheritCalibrate.State = INIT;
				InheritCalibrate.Time = TIM_GetTime();
				DispOneWindow(& MainMenu);	
			}
			else
			{
				i++;
				if(i==1)
				{
					ConfigParam.State = FINISH_CALIBRATE;
					ConfigParam.TimeStamp = TIM_GetTime();
				}
				
				if(i>=2)
				{					
					i=0;
					InheritCalibrate.State = INIT;
					InheritCalibrate.Time = TIM_GetTime();
					DispOneWindow(& MainMenu);				
				}		
			}
					
		}break;
		
		default :break;
	}

}
	
void UpDn_Calibrate(void)
{
	switch(InheritCalibrate.State)
	{
		case INIT:
		{
			UpDn_Com();
		}break;
		
		case PROCESS:
		{
			
		}break;
		
		default :break;
	}
}
	
void Right_Calibrate(void)
{
	
}
	
void Enter_Calibrate(void)
{	
	switch(InheritCalibrate.State)
	{
		case INIT:
		{
			InheritCalibrate.State = PROCESS;
			InheritCalibrate.Time = TIM_GetTime();
			
			ConfigParam.State = START_CALIBRATE;
			ConfigParam.TimeStamp = TIM_GetTime();
			ConfigParam.CalibrateTimeAutoStop = TIM_GetTime();
			ConfigParam.PreviousStaticAccelValue[2]=0;
			
			LM_Clear();
			LM_DispStr(60,0,"Calibrate");
			ClearIndiction(60,11);
			DispIndiction(8,11,"Auto Stop or Esc to Finish");
			
			ConfigParam.StaticAccelSum[2] = 0.0;
			ConfigParam.StaticAccelCnt[2] = 1;
			
		}break;
		
		case PROCESS:
		{
	
		}break;
		
		default :break;
	}
}

void Enter_SetRange_1(void)
{
	if(ConfigParam.RangeSelected == 0)
	{
		ClearIndiction(20,11);
		DispIndiction(20,11,"Already 0.1G , 1.0 M/S");		
	}
	else
	{
		ConfigParam.RangeSelected = 0;
		FlashStoreConfigParam(FLASH_DATA_ADDR,&ConfigParam);
		FlashLoadConfigParam(&ConfigParam,FLASH_DATA_ADDR);
		ClearIndiction(10,11);
		DispIndiction(10,11,"Set 0.1G , 1.0 M/S Succeed");
	}	
}

void Enter_SetRange_2(void)
{
	if(ConfigParam.RangeSelected == 1)
	{
		ClearIndiction(20,11);
		DispIndiction(20,11,"Already 0.2G , 2.0 M/S");	
	}
	else
	{
		ConfigParam.RangeSelected = 1;
		FlashStoreConfigParam(FLASH_DATA_ADDR,&ConfigParam);
		FlashLoadConfigParam(&ConfigParam,FLASH_DATA_ADDR);
		ClearIndiction(10,11);
		DispIndiction(10,11,"Set 0.2G , 2.0 M/S Succeed");
	}	
}

void Enter_SetRange_3(void)
{
	if(ConfigParam.RangeSelected == 2)
	{
		ClearIndiction(20,11);
		DispIndiction(20,11,"Already 0.4G , 4.0 M/S");	
	}
	else
	{
		ConfigParam.RangeSelected = 2;
		FlashStoreConfigParam(FLASH_DATA_ADDR,&ConfigParam);
		FlashLoadConfigParam(&ConfigParam,FLASH_DATA_ADDR);
		ClearIndiction(10,11);
		DispIndiction(10,11,"Set 0.4G , 4.0 M/S Succeed");
	}	
}




