

#include "disp.h"
#include "lm240120.h"
#include "rtc.h"
#include "tim.h"




void DispIndiction(uint x,uint y,uchar *pstr)
{
	LM_DispStr8_8(x,y,pstr);
}

void ClearIndiction(uint x,uint y)
{
	LM_DispStr8_8(x,y,"                                ");
}

void RTC_Display(void)
{
//	static u32 PreviousSecond = 0;
//	static u32 CurrentSecond = 1;

//	CurrentSecond = RTC_GetSec();

//	if(CurrentSecond != PreviousSecond)
	{
		LM_DispStr(10,12,(char *)RTC_GetCalStr());
		LM_DispChar(10 + 25*8,12,' ');
//		PreviousSecond = CurrentSecond;
	}		
}

void DispVersionInfo(void)
{
	u32 i;
	LM_DispStr(18,4,"Welcome");
	LM_DispStr(18,8,"Elevator Speed Detector");
	LM_DispStr(18,10,"HW : 2014-07-31 v1.1");
	LM_DispStr(18,12,"SW : 2014-11-18 v1.1");
	i  = TIM_GetTime()+2000;	
	while(!TIM_IsExpired(i))
	{
			;
	}
}






