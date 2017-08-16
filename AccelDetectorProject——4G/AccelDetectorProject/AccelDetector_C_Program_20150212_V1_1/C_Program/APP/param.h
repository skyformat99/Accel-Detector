

#ifndef _PARAM_H
#define _PARAM_H

#include "stm32f10x.h"
#include "ff.h"

#ifndef NULL
#define NULL	((void *)0)
#endif

#define STORE_DATA_INTERVAL		10

/*---------------------------------------------------------------------------------*/
typedef enum
{
	INIT_SCHED_PARAM,
	CONFIG_PARAM,
	MEASURE_RIDE,
}SchedState_t;

typedef struct
{
	SchedState_t		State;
	u32					TimeStamp;
	u32 				IWDT_Time;
}SchedParam_t;

extern 	SchedParam_t	SchedParam;
void 	InitSchedParam(SchedParam_t *p);

/*---------------------------------------------------------------------------------*/


typedef enum
{
	INIT_CONFIG_PARAM,
	START_CALIBRATE,
	FINISH_CALIBRATE,
}ConfigState_t;

typedef enum
{
	KEY_CTRL,
	IR_CTRL
}CtrlMode_t;

//in order to operate in flash,this structure should always aligned to 4 bytes
#pragma pack(4)

typedef struct
{
	ConfigState_t	State;		//offset0
	u32				TimeStamp;	//offset1	
	CtrlMode_t		CtrlMode;	//offset2
	
	u32				CalibrateTimeStamp;
	vs16			CalibrateAccel[3];
	u32				CalibrateTimeAutoStop;
	double			PreviousStaticAccelValue[3];
	
	double			StaticAccelValue[3];
	double			StaticAccelSum[3];
	u32				StaticAccelCnt[3];
	u32				RangeSelected;
}ConfigParam_t;

#pragma pack()

extern 	ConfigParam_t	ConfigParam;
void 	InitConfigParam(ConfigParam_t *p);
void 	ProcessConfig(ConfigParam_t *p);
/*---------------------------------------------------------------------------------*/
#define FILE_PATH_LENGTH	28

typedef enum
{
	INIT_MEASURE_PARAM,
	INIT_FS,
	WAIT_FOR_NEXT_TRIGGER,
	TRIGGER_OCCUR,
	TRIGGER_DELAY,
	GET_FILE_PATH,
	OPEN_FILE,
	STORE_DATA,
	CLOSE_FILE,
}MeasureState_t;

typedef struct
{
	MeasureState_t	State;
	u32				TimeStamp;
	
	FATFS 			FatFs;
	DIR				FileDir;
	FIL 			File;
	FILINFO			FileInfo;
	FRESULT			FileResult;
	
	char 			FilePath[FILE_PATH_LENGTH];	
	char * 			FilePathPtr;
	
	vs16			OriginalAccel[3]; //0-X;1-Y;2-Z
	double			FilteredAccel[3];
	double			Velocity[3];
	
				
}MeasureParam_t;

extern 	MeasureParam_t	MeasureParam;
void 	InitMeasureParam(MeasureParam_t *p);
void 	ProcessMeasure(MeasureParam_t *p);


#endif



