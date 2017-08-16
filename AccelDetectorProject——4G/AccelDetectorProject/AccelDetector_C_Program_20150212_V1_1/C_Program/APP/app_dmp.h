

#ifndef _APP_DMP_H
#define _APP_DMP_H


#define q30  1073741824.0f

//dmp_read_fifo 得到的原始数据
typedef struct
{
	short 			gyro[3];
	short 			accel[3];
	long			quat[4];
	unsigned long	timestamp;
	short 			sensors;
	unsigned char 	more;	
}MPU6000_DMP_OriginalData_t;

//解算之后的姿态数据,注意前进方向的定义
typedef struct
{	//Y轴正方向为前进方向
	float Roll;		//横滚，将物体绕Y轴旋转
	float Yaw;	   	//航向，将物体绕Z轴旋转
	float Pitch;	//俯仰，将物体绕X轴旋转		
}MPU6000_Attitude_t;

extern MPU6000_DMP_OriginalData_t 		MPU6000_DMP_OriginalData;//dmp_read_fifo 得到的原始数据
extern MPU6000_Attitude_t				MPU6000_Attitude; //解算之后的姿态数据,注意前进方向的定义
extern float q0,q1,q2,q3;	 //用于四元数计算的临时变量





#endif


