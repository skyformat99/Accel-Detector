

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
/* ѭ�����еĻ������� */ 
QueueState_t InitQueue(Queue_t *Q)  
{ /* ����һ���ն���Q */  
  Q->base = (QElemType *)malloc(MAX_QSIZE*sizeof(QElemType));
  if(Q->base == NULL) /* �洢����ʧ�� */  
	return	QUEUE_ERR;
  Q->front=Q->rear=0;/*�ն���*/ 
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
{ /* ���ٶ���Q��Q���ٴ��� */  
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
{ /* ��Q��Ϊ�ն��� */  
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
{ /* ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE */  
  if(Q->front==Q->rear) /* ���пյı�־ */  
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
{ /* ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE */  
  if(Q->front==Q->rear) /* ���пյı�־ */  
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
{ /* ����Q��Ԫ�ظ����������еĳ��� */  
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
{ /* ����Ԫ��eΪQ���µĶ�βԪ�� */  
  if((Q->rear+1)%MAX_QSIZE==Q->front) /* ������ */  
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
{ /* �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR */  
  if(Q->front==Q->rear) /* ���п� */  
    return 	QUEUE_ERR;  
  *e=Q->base[Q->front];  
  Q->front=(Q->front+1)%MAX_QSIZE;  
  	return 	QUEUE_OK;  
}





