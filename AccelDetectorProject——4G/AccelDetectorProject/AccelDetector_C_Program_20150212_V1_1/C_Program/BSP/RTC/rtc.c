
#include"stm32f10x.h"
#include"rtc.h"
#include<time.h>
/*---------------------------------------------------------------------------
**	Function	: RTC_Configuration
**	Parameters	:
**	Retval		:
**	Description	: 硬件相关配置
**	Attention	:
---------------------------------------------------------------------------*/
void RTC_Configuration(void)
{
	//启用PWR和BKP的时钟（from APB1）
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

	//后备域解锁
	PWR_BackupAccessCmd(ENABLE);

	//备份寄存器模块复位
	BKP_DeInit();

	//外部32.768K
	RCC_LSEConfig(RCC_LSE_ON);
	//等待稳定
	while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);

	//RTC时钟源配置成LSE（外部32.768K）
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

	//RTC开启
	RCC_RTCCLKCmd(ENABLE);

	//开启后需要等待APB1时钟与RTC时钟同步，才能读写寄存器
	RTC_WaitForSynchro();

	//读写寄存器前，要确定上一个操作已经结束
	RTC_WaitForLastTask();

	//设置RTC分频器，使RTC时钟为1Hz
	//RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1)
	RTC_SetPrescaler(32767);

	//等待寄存器写入完成
	RTC_WaitForLastTask();   

	//等待写入完成
	RTC_WaitForLastTask();

	return;
}
/*---------------------------------------------------------------------------
**	Function	: RTC_Config
**	Parameters	:
**	Retval		:
**	Description	: 硬件相关配置
**	Attention	:
---------------------------------------------------------------------------*/
void RTC_Config(void)
{
	//我们在BKP的后备寄存器1中，存了一个特殊字符YZ_RTC_SPECIAL_CHECK
	//第一次上电或后备电源掉电后，该寄存器数据丢失，
	//表明RTC数据丢失，需要重新配置
	if (BKP_ReadBackupRegister(BKP_DR1) != YZ_RTC_SPECIAL_CHECK)
	{
		//重新配置RTC
		RTC_Configuration();
		//配置完成后，向后备寄存器中写特殊字符YZ_RTC_SPECIAL_CHECK
		BKP_WriteBackupRegister(BKP_DR1, YZ_RTC_SPECIAL_CHECK);
	}
	else
	{
		//若后备寄存器没有掉电，则无需重新配置RTC
		//这里我们可以利用RCC_GetFlagStatus()函数查看本次复位类型
		if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
		{
			//这是上电复位
		}
		else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
		{
			//这是外部RST管脚复位
		}

		//虽然RTC模块不需要重新配置，且掉电后依靠后备电池依然运行
		//但是每次上电后，还是要使能RTCCLK???????
		RCC_RTCCLKCmd(ENABLE);
		//等待RTC时钟与APB1时钟同步
		RTC_WaitForSynchro();

	}

#ifdef RTCClockOutput_Enable
	/* Enable PWR and BKP clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

	/* Allow access to BKP Domain */
	PWR_BackupAccessCmd(ENABLE);

	/* Disable the Tamper Pin */
	BKP_TamperPinCmd(DISABLE); /* To output RTCCLK/64 on Tamper pin, the tamper
								 functionality must be disabled */

	/* Enable RTC Clock Output on Tamper Pin */
	BKP_RTCOutputConfig(BKP_RTCOutputSource_CalibClock);
#endif

	return;
}
/*---------------------------------------------------------------------------
**	Function	: RTC_GetSec
**	Parameters	:
**	Retval		: 硬件相关，调用FWLib中的RTC_GetCounter
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
RTC_Sec_t  	RTC_GetSec(void)
{
	return RTC_GetCounter();  //stm32f10x_rtc.h
}
/*---------------------------------------------------------------------------
**	Function	: RTC_SetSec
**	Parameters	:
**	Retval		: 硬件相关，调用FWLib中的RTC_SetCounter
**	Description	:
**	Attention	: 
---------------------------------------------------------------------------*/
void RTC_SetSec(const RTC_Sec_t Sec)
{
	RTC_WaitForLastTask();	//stm32f10x_rtc.h
	RTC_SetCounter(Sec);   	//stm32f10x_rtc.h
}
/*---------------------------------------------------------------------------
**	Function	: RTC_ConvCalToSec
**	Parameters	:
**	Retval		: C标准库，时间格式转换
**	Description	:
**	Attention	: 1，此函数的Cal相当于库中的Broken-down time format
**				  2，此函数的Sec相当于库中的的Calender time format
---------------------------------------------------------------------------*/
RTC_Sec_t	RTC_ConvCalToSec(RTC_Cal_t *p)
{
	p->tm_year -= 1900;
	p->tm_mon -= 1;
	p->tm_hour -= 8;
	
	return mktime(p);	
}	
/*---------------------------------------------------------------------------
**	Function	: RTC_ConvSecToCal
**	Parameters	:
**	Retval		: C标准库，时间格式转换
**	Description	:
**	Attention	: 1，此函数的Cal相当于库中的Broken-down time format
**				  2，此函数的Sec相当于库中的的Calender time format
---------------------------------------------------------------------------*/
RTC_Cal_t *RTC_ConvSecToCal(RTC_Sec_t Sec)
{
	(localtime(&Sec)) -> tm_year += 1900;
	(localtime(&Sec)) -> tm_mon  += 1;
	(localtime(&Sec)) -> tm_hour += 8;
		
	return localtime(&Sec); 	
}
/*---------------------------------------------------------------------------
**	Function	: RTC_GetCal
**	Parameters	:
**	Retval		:
**	Description	: 给APP的接口
**	Attention	:
---------------------------------------------------------------------------*/
RTC_Cal_t 	*RTC_GetCal(void)
{
	return 	 RTC_ConvSecToCal(RTC_GetSec());
}
/*---------------------------------------------------------------------------
**	Function	: RTC_SetCal
**	Parameters	:
**	Retval		:
**	Description	: 给APP的接口
**	Attention	:
---------------------------------------------------------------------------*/
void RTC_SetCal(RTC_Cal_t *p)
{
	RTC_SetSec(RTC_ConvCalToSec(p));
}
/*---------------------------------------------------------------------------
**	Function	: RTC_GetCalStr
**	Parameters	:
**	Retval		:
**	Description	: 给APP的接口，返回可打印的ASCII字符串
**	Attention	:
---------------------------------------------------------------------------*/
char * RTC_GetCalStr(void)
{
	return asctime(RTC_ConvSecToCal(RTC_GetSec()));	
}











