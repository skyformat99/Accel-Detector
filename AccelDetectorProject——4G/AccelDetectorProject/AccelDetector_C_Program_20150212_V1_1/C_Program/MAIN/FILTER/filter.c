
#include "stm32f10x.h"
#include "queue.h"
#include "stdlib.h"
#include "filter.h"

double GetAverageValue(Queue_t *Q)
{
	int i;
	double Sum = 0.0;
	
	for(i=0;i<QueueLength(Q);i++)
		Sum += *(Q->base + i);	

	return Sum/QueueLength(Q);
}
/*--------------------------------------------------------------------------------*/
static int FilterComp(const void*a,const void*b)
{
	return *(QElemType*)a-*(QElemType*)b;
}

double GetMiddleValue(Queue_t *Q)
{
	qsort(Q->base,QueueLength(Q),sizeof(QElemType),FilterComp);

	return (*(Q->base + QueueLength(Q)/2));
}











