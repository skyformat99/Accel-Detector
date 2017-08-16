


#include "app_dmp.h"



MPU6000_DMP_OriginalData_t 		MPU6000_DMP_OriginalData;//dmp_read_fifo 得到的原始数据
MPU6000_Attitude_t				MPU6000_Attitude; 		//解算之后的姿态数据,注意前进方向的定义

float q0=1.0f,q1=0.0f,q2=0.0f,q3=0.0f;	//用于四元数计算的临时变量
