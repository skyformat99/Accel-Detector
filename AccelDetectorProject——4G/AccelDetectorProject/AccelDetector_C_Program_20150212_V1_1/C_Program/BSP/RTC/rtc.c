
#include"stm32f10x.h"
#include"rtc.h"
#include<time.h>
/*---------------------------------------------------------------------------
**	Function	: RTC_Configuration
**	Parameters	:
**	Retval		:
**	Description	: Ӳ���������
**	Attention	:
---------------------------------------------------------------------------*/
void RTC_Configuration(void)
{
	//����PWR��BKP��ʱ�ӣ�from APB1��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

	//�������
	PWR_BackupAccessCmd(ENABLE);

	//���ݼĴ���ģ�鸴λ
	BKP_DeInit();

	//�ⲿ32.768K
	RCC_LSEConfig(RCC_LSE_ON);
	//�ȴ��ȶ�
	while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);

	//RTCʱ��Դ���ó�LSE���ⲿ32.768K��
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

	//RTC����
	RCC_RTCCLKCmd(ENABLE);

	//��������Ҫ�ȴ�APB1ʱ����RTCʱ��ͬ�������ܶ�д�Ĵ���
	RTC_WaitForSynchro();

	//��д�Ĵ���ǰ��Ҫȷ����һ�������Ѿ�����
	RTC_WaitForLastTask();

	//����RTC��Ƶ����ʹRTCʱ��Ϊ1Hz
	//RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1)
	RTC_SetPrescaler(32767);

	//�ȴ��Ĵ���д�����
	RTC_WaitForLastTask();   

	//�ȴ�д�����
	RTC_WaitForLastTask();

	return;
}
/*---------------------------------------------------------------------------
**	Function	: RTC_Config
**	Parameters	:
**	Retval		:
**	Description	: Ӳ���������
**	Attention	:
---------------------------------------------------------------------------*/
void RTC_Config(void)
{
	//������BKP�ĺ󱸼Ĵ���1�У�����һ�������ַ�YZ_RTC_SPECIAL_CHECK
	//��һ���ϵ��󱸵�Դ����󣬸üĴ������ݶ�ʧ��
	//����RTC���ݶ�ʧ����Ҫ��������
	if (BKP_ReadBackupRegister(BKP_DR1) != YZ_RTC_SPECIAL_CHECK)
	{
		//��������RTC
		RTC_Configuration();
		//������ɺ���󱸼Ĵ�����д�����ַ�YZ_RTC_SPECIAL_CHECK
		BKP_WriteBackupRegister(BKP_DR1, YZ_RTC_SPECIAL_CHECK);
	}
	else
	{
		//���󱸼Ĵ���û�е��磬��������������RTC
		//�������ǿ�������RCC_GetFlagStatus()�����鿴���θ�λ����
		if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
		{
			//�����ϵ縴λ
		}
		else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
		{
			//�����ⲿRST�ܽŸ�λ
		}

		//��ȻRTCģ�鲻��Ҫ�������ã��ҵ���������󱸵����Ȼ����
		//����ÿ���ϵ�󣬻���Ҫʹ��RTCCLK???????
		RCC_RTCCLKCmd(ENABLE);
		//�ȴ�RTCʱ����APB1ʱ��ͬ��
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
**	Retval		: Ӳ����أ�����FWLib�е�RTC_GetCounter
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
**	Retval		: Ӳ����أ�����FWLib�е�RTC_SetCounter
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
**	Retval		: C��׼�⣬ʱ���ʽת��
**	Description	:
**	Attention	: 1���˺�����Cal�൱�ڿ��е�Broken-down time format
**				  2���˺�����Sec�൱�ڿ��еĵ�Calender time format
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
**	Retval		: C��׼�⣬ʱ���ʽת��
**	Description	:
**	Attention	: 1���˺�����Cal�൱�ڿ��е�Broken-down time format
**				  2���˺�����Sec�൱�ڿ��еĵ�Calender time format
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
**	Description	: ��APP�Ľӿ�
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
**	Description	: ��APP�Ľӿ�
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
**	Description	: ��APP�Ľӿڣ����ؿɴ�ӡ��ASCII�ַ���
**	Attention	:
---------------------------------------------------------------------------*/
char * RTC_GetCalStr(void)
{
	return asctime(RTC_ConvSecToCal(RTC_GetSec()));	
}











