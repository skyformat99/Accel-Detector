#include <analysis.h>
#include <ansi_c.h>
 
#include"myinclude.h"
#include"filter.h"




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
/*--------------------------------------------------------------------------------------------------------*/
double GetAverageValue(double *src,int src_len)
{
	double sum = 0.0;
	for(int i=0;i<src_len;i++)
		sum += *(src + i);	

	return sum/src_len;
}
/*--------------------------------------------------------------------------------------------------------*/  
/*double GetMiddleValue(double *src,int src_len)
{
	double *SortArray = (double*)malloc(src_len*sizeof(double));
	for(int i=0;i<src_len;i++)
		 SortArray[i] = src[i];
	Sort (SortArray, src_len, ANALYSIS_SORT_ASCENDING, SortArray);
	
	return   SortArray[src_len/2];
}
*/
/*--------------------------------------------------------------------------------------------------------*/ 
void	MiddelValue(double *src,double *dest,int src_len,int win_len) 
{
	int i,j;
//	double buffer[win_len];
	double *buffer=(double*)malloc(win_len*sizeof(double));
	
	for(i=0;i<src_len-win_len;i++)
	{
		for(j=0;j<win_len;j++)
			buffer[j] = src[i+j];
		
		Sort (buffer, win_len, ANALYSIS_SORT_ASCENDING, buffer);
		
		dest[i] = buffer[win_len/2];
	}
	
	for(i=0;i<win_len;i++)
	{
		dest[src_len-win_len+i] = src[src_len-win_len+i];	
	}
	free(buffer);
}
/*--------------------------------------------------------------------------------------------------------*/ 
void MovingAverage(double *src,double *dest,int src_len,int win_len)
{
	int i,j;
	double sum = 0;
	
	for(i=0;i<src_len-win_len;i++)
	{
		for(j=0;j<win_len;j++)
		{
			sum += src[i+j];
		}
		
		dest[i] = sum/win_len;
		sum = 0;
	}
	
	for(i=0;i<win_len;i++)
	{
		dest[src_len-win_len+i] = src[src_len-win_len+i];	
	}
}
/*--------------------------------------------------------------------------------------------------------*/ 
void RunIntegral(double *src,double *dest,int *time_stamp,double static_value,int src_len)
{
	double delta_vel;
	
	for(int i=1;i<src_len-1;i++)
	{
		delta_vel =(src[i]-static_value)*(time_stamp[i]-time_stamp[i-1]);
		dest[i] = dest[i-1]+delta_vel;
	}
		
	
	dest[src_len-1] = dest[src_len-2];
}




























