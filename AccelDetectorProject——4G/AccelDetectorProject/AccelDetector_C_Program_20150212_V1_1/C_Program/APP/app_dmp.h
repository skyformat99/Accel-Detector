

#ifndef _APP_DMP_H
#define _APP_DMP_H


#define q30  1073741824.0f

//dmp_read_fifo �õ���ԭʼ����
typedef struct
{
	short 			gyro[3];
	short 			accel[3];
	long			quat[4];
	unsigned long	timestamp;
	short 			sensors;
	unsigned char 	more;	
}MPU6000_DMP_OriginalData_t;

//����֮�����̬����,ע��ǰ������Ķ���
typedef struct
{	//Y��������Ϊǰ������
	float Roll;		//�������������Y����ת
	float Yaw;	   	//���򣬽�������Z����ת
	float Pitch;	//��������������X����ת		
}MPU6000_Attitude_t;

extern MPU6000_DMP_OriginalData_t 		MPU6000_DMP_OriginalData;//dmp_read_fifo �õ���ԭʼ����
extern MPU6000_Attitude_t				MPU6000_Attitude; //����֮�����̬����,ע��ǰ������Ķ���
extern float q0,q1,q2,q3;	 //������Ԫ���������ʱ����





#endif


