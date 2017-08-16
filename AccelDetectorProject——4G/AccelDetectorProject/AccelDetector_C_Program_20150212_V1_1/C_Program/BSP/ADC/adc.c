


#include "adc.h"
#include "stm32f10x.h"
#include "lm240120.h"
#include "stdlib.h"

Bat_t	Bat;

#define NORMAL_WORK_HIGH_ANALOGY	1933	//ADC input PORT,11.6/6 = 1.933v = 1933mv
#define NORMAL_WORK_LOW_ANALOGY		1600	//ADC input PORT,9.6 /6 = 1.600V = 1600mv

#define ADC_FULL_ANALOG				3300
#define ADC_FULL_DIGITAL			4096

#define NORMAL_WORK_HIGH_DIGITAL	NORMAL_WORK_HIGH_ANALOGY*\
									ADC_FULL_DIGITAL/ADC_FULL_ANALOG
#define NORMAL_WORK_LOW_DIGITAL		NORMAL_WORK_LOW_ANALOGY*\
									ADC_FULL_DIGITAL/ADC_FULL_ANALOG
									
#define ADC1_DATA_LEN	32

vu16	ADC1_RawData[ADC1_DATA_LEN];
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void BAT_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(BAT_GPIO_RCC_Periph,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  BAT_GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(BAT_GPIO_Port, &GPIO_InitStructure);
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void BAT_ADC_Config(void)
{
	ADC_InitTypeDef  ADC_InitStructure;
	
	RCC_APB2PeriphClockCmd(BAT_ADC_RCC_Periph,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //72M/6=12,ADC最大时间不能超过14M	
	
	ADC_DeInit(BAT_ADC);  //将外设 ADC1 的全部寄存器重设为缺省值
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	//模数转换工作转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	
	ADC_Init(BAT_ADC, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器   
	
	ADC_RegularChannelConfig(BAT_ADC,ADC_Channel_10, 1,ADC_SampleTime_1Cycles5); 
	
	ADC_Cmd (BAT_ADC,ENABLE);  
	
	ADC_ResetCalibration(BAT_ADC);	//重置指定的ADC1的校准寄存器
	 
	while(ADC_GetResetCalibrationStatus(BAT_ADC))//获取ADC1重置校准寄存器的状态,设置状态则等待
		;	
	
	ADC_StartCalibration(BAT_ADC);		//开始指定ADC1的校准状态
 
	while(ADC_GetCalibrationStatus(ADC1))	//获取指定ADC1的校准程序,设置状态则等待
		;	
	
	ADC_SoftwareStartConvCmd(BAT_ADC,ENABLE);
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
u16 BAT_ADC_GetResult(void)
{	
	while(ADC_GetFlagStatus(BAT_ADC, ADC_FLAG_EOC ) == RESET)//等待转换结束
		;
	return ADC_GetConversionValue(BAT_ADC);	//返回最近一次ADC1规则组的转换结果	
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
int comp(const void *a,const void *b)
{
	return*(int*)a-*(int*)b;
}

u8 BAT_GetEmpty(void)
{
	u8		EmptyPercent;
	u8 		i;		
	double	ADC1_AverageData = 0;
	double 	ADC1_TotalData = 0;
	
	for(i=0;i<ADC1_DATA_LEN;i++)
	{
		ADC1_RawData[i] = BAT_ADC_GetResult();
	}
	
	qsort((void *)ADC1_RawData,ADC1_DATA_LEN,sizeof(vu16),comp);
	
	for(i=1;i<ADC1_DATA_LEN-1;i++)
	{
		ADC1_TotalData += ADC1_RawData[i];
	}
	
	ADC1_AverageData = ADC1_TotalData / (ADC1_DATA_LEN - 2);
	
	if(ADC1_AverageData  > NORMAL_WORK_HIGH_DIGITAL)
	{
		ADC1_AverageData = NORMAL_WORK_HIGH_DIGITAL;
	}
	
	if(ADC1_AverageData < NORMAL_WORK_LOW_DIGITAL)
	{
		ADC1_AverageData = NORMAL_WORK_LOW_DIGITAL;
	}
	
	EmptyPercent = (100*(NORMAL_WORK_HIGH_DIGITAL - ADC1_AverageData)/
	(NORMAL_WORK_HIGH_DIGITAL-NORMAL_WORK_LOW_DIGITAL));
	
	return EmptyPercent;
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: Disp Empty Part rather than Full Part
---------------------------------------------------------------------------*/
void BAT_DispPower(Bat_t *p)
{
	u8 i;
	u8 Empty;

	p->EmptyPercent = BAT_GetEmpty();
	
	Empty = p->EmptyPercent*(p->XLength-1)/100;

	LM_WriteColumn(p->X-2,0,0x3c);
	LM_WriteColumn(p->X-1,0,0x3c);
		
	for(i=0;i<Empty;i++)
	{
		LM_WriteColumn(p->X+i,0,0x42);
	}
	
	for(i=Empty;i<p->XLength;i++)
	{
		LM_WriteColumn(p->X+i,0,0x7e);
	}	
}




