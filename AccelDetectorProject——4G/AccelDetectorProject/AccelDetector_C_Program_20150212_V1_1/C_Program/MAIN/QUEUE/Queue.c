

#include <stdlib.h>
#include "queue.h"

#ifndef NULL
#define NULL	((void *)0)
#endif

//s16 QueueArray[MAX_QSIZE];

Queue_t	QueueFilterInput;

/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
/* 循环队列的基本操作 */ 
QueueState_t InitQueue(Queue_t *Q)  
{ /* 构造一个空队列Q */  
  Q->base = (QElemType *)malloc(MAX_QSIZE*sizeof(QElemType));
  if(Q->base == NULL) /* 存储分配失败 */  
	return	QUEUE_ERR;
  Q->front=Q->rear=0;/*空队列*/ 
	return QUEUE_OK ;
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void DestroyQueue(Queue_t *Q)  
{ /* 销毁队列Q，Q不再存在 */  
  if(Q->base)  
    free(Q->base);  
  Q->base=NULL;  
  Q->front=Q->rear=0;  
}   
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void ClearQueue(Queue_t *Q)  
{ /* 将Q清为空队列 */  
  Q->front=Q->rear=0;  
}  
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
QueueState_t QueueEmpty(Queue_t *Q)  
{ /* 若队列Q为空队列，则返回TRUE；否则返回FALSE */  
  if(Q->front==Q->rear) /* 队列空的标志 */  
    return QUEUE_OK;  
  else  
    return QUEUE_ERR;  
} 
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
QueueState_t GetQueueState(Queue_t *Q)  
{ /* 若队列Q为空队列，则返回TRUE；否则返回FALSE */  
  if(Q->front==Q->rear) /* 队列空的标志 */  
    return QUEUE_EMPTY;  
  if((Q->rear+1)%MAX_QSIZE==Q->front)
    return QUEUE_FULL;

	return QUEUE_ENTER_PERMITTED; 
	 
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
int QueueLength(Queue_t *Q)  
{ /* 返回Q的元素个数，即队列的长度 */  
  return(Q->rear-Q->front+MAX_QSIZE)%MAX_QSIZE;  
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
QueueState_t EnQueue(Queue_t *Q,QElemType e)  
{ /* 插入元素e为Q的新的队尾元素 */  
  if((Q->rear+1)%MAX_QSIZE==Q->front) /* 队列满 */  
    return QUEUE_FULL;  
  Q->base[Q->rear]=e;  
  Q->rear=(Q->rear+1)%MAX_QSIZE;  
  return QUEUE_OK;  
} 
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
QueueState_t DeQueue(Queue_t *Q,QElemType *e)  
{ /* 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR */  
  if(Q->front==Q->rear) /* 队列空 */  
    return 	QUEUE_ERR;  
  *e=Q->base[Q->front];  
  Q->front=(Q->front+1)%MAX_QSIZE;  
  	return 	QUEUE_OK;  
}





