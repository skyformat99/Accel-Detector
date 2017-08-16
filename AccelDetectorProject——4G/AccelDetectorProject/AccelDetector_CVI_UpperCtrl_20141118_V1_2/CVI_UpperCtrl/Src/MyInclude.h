
#ifndef _MYINCLUDE_H
#define _MYINCLUDE_H
#include"filter.h"
#include <analysis.h>   
/*--------------------------------------------------------------------------------------------*/  
typedef enum
{
	NO_FILE_LOAD,
	OLD_FILE_LOAD,
	NEW_FILE_LOAD
}FileState_t;
/*--------------------------------------------------------------------------------------------*/  
typedef struct
{
	char			**FilesPath;
	int 			FileHandle;
	
	FileState_t			FileState;
	
	long 				FileSize;

}FileLoad_t;

/*--------------------------------------------------------------------------------------------*/  
typedef struct
{
		double 		RecordTotal;
		
		double 		*PtrRawAccel_X;
		double 		*PtrRawAccel_Y;
		double 		*PtrRawAccel_Z;
		double 		*PtrFilteredAccel_X;
		double 		*PtrFilteredAccel_Y;
		double 		*PtrFilteredAccel_Z;
		double		*PtrRawVel_Z;
		double		*PtrFilteredVel_Z;
		
		int		 	*PtrTimeStamp;
		
		NIComplexNumber  	*PtrFFTResult_Z;
		double				*PtrFFTResultMag_Z;
		double				*PtrFFTResultPhase_Z; 
		
}RecordResume_t;
/*--------------------------------------------------------------------------------------------*/
typedef enum
{
	LSB,
	METERS_QUATER_SECOND,
	MILLI_GRAVITY,
	
}Param_Unit_Accel_t;
/*-----------------------------------------------------------------------*/ 
typedef enum
{
	METERS_SECOND,
	MILLI_METERS_SECOND,
	
}Param_Unit_Velocity_t;
/*-----------------------------------------------------------------------*/ 
typedef enum
{
	VERTICAL_X,
	VERTICAL_Y,
	VERTICAL_Z,
	
}Param_Direction_Vertical_t;
/*-----------------------------------------------------------------------*/ 
typedef enum
{
	LANDING_X,
	LANDING_Y,
	LANDING_Z,
	
}Param_Direction_Landing_t;
/*-----------------------------------------------------------------------*/ 
typedef enum
{
	FILTER_NONE,
	FILTER_MV = 1,
	FILTER_MA = 2,
	
}Param_Filter_Type_t;
/*-----------------------------------------------------------------------*/  
typedef enum
{
	RAW_ACCEL_X =1,
	RAW_ACCEL_Y =2,
	RAW_ACCEL_Z =3,
}Param_Raw_Accel_t;
/*-----------------------------------------------------------------------*/  
typedef enum
{
	FILTER_X =1,
	FILTER_Y =2, 
	FILTER_Z =3, 
	FFT_X = 4,
	FFT_Y = 5,
	FFT_Z = 6
}Param_Process_Accel_t;
/*-----------------------------------------------------------------------*/  
typedef enum
{
	VEL_RAW_Z =1,
	VEL_FILTERED_Z =2, 
}Param_Velocity_t;
/*-----------------------------------------------------------------------*/ 
typedef struct
{
	Param_Unit_Accel_t					Unit_Accel;	
	Param_Unit_Velocity_t	    		Unit_Velocity;
	Param_Direction_Vertical_t			Direction_Vertical;
	Param_Direction_Landing_t			Direction_Landing;	
	unsigned int 						Record_Interval; 
	
	Param_Filter_Type_t					Filter_Type;
	unsigned int 						Filter_WinLen;
	Param_Raw_Accel_t					Raw_Accel;
	Param_Process_Accel_t				Process_Accel;
	Param_Velocity_t					Velocity;

	unsigned int 						Static_Time;    //通过这个时间和Record_Interval，求得无外界加速度时候的静态AD值
	double								StaticValue;
	
}Param_t;

typedef enum
{
	SRC_FILTER_TYPE_NONE,
	SRC_FILTER_TYPE_MV,
	SRC_FILTER_TYPE_MA,
	SRC_FILTER_LEN,
	SRC_RAW_ACCEL_X,
	SRC_RAW_ACCEL_Y,
	SRC_RAW_ACCEL_Z,
	SRC_FILTERED_ACCEL_X,
	SRC_FILTERED_ACCEL_Y,
	SRC_FILTERED_ACCEL_Z,
	SRC_VEL_RAW_Z,
	SRC_VEL_FILTERED_Z,
	
	SRC_FFT_ACCEL_X, 
	SRC_FFT_ACCEL_Y, 
	SRC_FFT_ACCEL_Z, 
	
}Msg_Src_t;
/*--------------------------------------------------------------------------------------------*/
typedef struct
{
	Msg_Src_t 		Src;
	Param_t			*Param;
	
}Msg_t;
/*--------------------------------------------------------------------------------------------*/
extern FileLoad_t		FileLoad;
extern RecordResume_t	RecordResume;
extern Param_t			Param;  


#endif



























