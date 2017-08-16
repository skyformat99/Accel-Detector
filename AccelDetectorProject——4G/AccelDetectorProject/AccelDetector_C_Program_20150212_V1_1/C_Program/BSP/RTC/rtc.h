
#ifndef _RTC_H
#define _RTC_H

#include<time.h>

/* �����ַ� */
//������س�����Ҫ�޸�RTC������Ҫ�޸Ĵ˴��ĺ궨��
#define YZ_RTC_SPECIAL_CHECK	 0x2015

typedef struct tm	RTC_Cal_t;
typedef	time_t		RTC_Sec_t;

//Ӳ������
extern void 		RTC_Configuration(void);
extern void 		RTC_Config(void);
//Ӳ���Ĵ������
extern RTC_Sec_t  	RTC_GetSec(void);
extern void 		RTC_SetSec(const RTC_Sec_t Sec);
//ʱ���ʽת��
extern RTC_Sec_t	RTC_ConvCalToSec(RTC_Cal_t *p);
extern RTC_Cal_t *	RTC_ConvSecToCal(RTC_Sec_t Sec);

//��APP�Ľӿ�
extern RTC_Sec_t  	RTC_GetSec(void);
extern RTC_Cal_t *	RTC_GetCal(void);
extern void 		RTC_SetCal(RTC_Cal_t *p);
extern char *		RTC_GetCalStr(void);



#endif





