
#ifndef _RTC_H
#define _RTC_H

#include<time.h>

/* 特殊字符 */
//如果下载程序需要修改RTC，则需要修改此处的宏定义
#define YZ_RTC_SPECIAL_CHECK	 0x2015

typedef struct tm	RTC_Cal_t;
typedef	time_t		RTC_Sec_t;

//硬件配置
extern void 		RTC_Configuration(void);
extern void 		RTC_Config(void);
//硬件寄存器相关
extern RTC_Sec_t  	RTC_GetSec(void);
extern void 		RTC_SetSec(const RTC_Sec_t Sec);
//时间格式转化
extern RTC_Sec_t	RTC_ConvCalToSec(RTC_Cal_t *p);
extern RTC_Cal_t *	RTC_ConvSecToCal(RTC_Sec_t Sec);

//给APP的接口
extern RTC_Sec_t  	RTC_GetSec(void);
extern RTC_Cal_t *	RTC_GetCal(void);
extern void 		RTC_SetCal(RTC_Cal_t *p);
extern char *		RTC_GetCalStr(void);



#endif





