


#include "app_dmp.h"



MPU6000_DMP_OriginalData_t 		MPU6000_DMP_OriginalData;//dmp_read_fifo �õ���ԭʼ����
MPU6000_Attitude_t				MPU6000_Attitude; 		//����֮�����̬����,ע��ǰ������Ķ���

float q0=1.0f,q1=0.0f,q2=0.0f,q3=0.0f;	//������Ԫ���������ʱ����
