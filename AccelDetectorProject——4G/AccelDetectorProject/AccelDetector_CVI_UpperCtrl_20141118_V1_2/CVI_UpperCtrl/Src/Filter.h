  

#ifndef _FILTER_H
#define _FILTER_H

#define MAX_QSIZE	128

typedef double QElemType;

typedef enum
{
	QUEUE_OK,
	QUEUE_ERR,
	QUEUE_EMPTY,
	QUEUE_FULL,
	QUEUE_ENTER_PERMITTED,
}QueueState_t;

typedef struct  
{  
  QElemType *base; /* ��ʼ���Ķ�̬����洢�ռ� */  
  int front; /* ͷָ�룬�����в��գ�ָ�����ͷԪ�� */  
  int rear;  /* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/  
}Queue_t;


QueueState_t 		InitQueue(Queue_t *Q);
void 				DestroyQueue(Queue_t *Q);
void 				ClearQueue(Queue_t *Q);
QueueState_t 		QueueEmpty(Queue_t *Q);
QueueState_t 		GetQueueState(Queue_t *Q);
int 				QueueLength(Queue_t *Q);
QueueState_t 		EnQueue(Queue_t *Q,QElemType e);
QueueState_t 		DeQueue(Queue_t *Q,QElemType *e);


void	MiddelValue(double *src,double *dest,int src_len,int win_len);
void 	MovingAverage(double *src,double *dest,int src_len,int win_len);

double 	GetMiddleValue(double *src,int src_len); 
double 	GetAverageValue(double *src,int src_len);

void 	RunIntegral(double *src,double *dest,int *time_stamp,double static_value,int src_len);
































#endif
