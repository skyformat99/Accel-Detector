
#ifndef _QUEUE_H
#define _QUEUE_H
#include "stm32f10x.h"

#define MAX_QSIZE	128

typedef vs16 QElemType;

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
  QElemType *base; /* 初始化的动态分配存储空间 */  
  int front; /* 头指针，若队列不空，指向队列头元素 */  
  int rear;  /* 尾指针，若队列不空，指向队列尾元素的下一个位置*/  
}Queue_t;


QueueState_t 		InitQueue(Queue_t *Q);
void 				DestroyQueue(Queue_t *Q);
void 				ClearQueue(Queue_t *Q);
QueueState_t 		QueueEmpty(Queue_t *Q);
QueueState_t 		GetQueueState(Queue_t *Q);
int 				QueueLength(Queue_t *Q);
QueueState_t 		EnQueue(Queue_t *Q,QElemType e);
QueueState_t 		DeQueue(Queue_t *Q,QElemType *e);


extern Queue_t	QueueFilterInput;


#endif

