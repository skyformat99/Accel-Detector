
#include "stm32f10x.h"
#include "graph.h"
#include "lm240120.h"
#include "tim.h"
#include "led.h"
#include "Key.h"
#include "param.h"
#include "queue.h"
#include "param.h"

double RANGE_ACCEL[3] = {(25.0/(16384*0.1)),(25.0/(16384*0.2)),(25.0/(16384*0.4))};
double RANGE_VEL[3] = {(25.0/1000),(25.0/2000),(25.0/4000)};

#define RANGE_ACCEL_SELECTED	RANGE_ACCEL[ConfigParam.RangeSelected]
#define RANGE_VEL_SELECTED		RANGE_VEL[ConfigParam.RangeSelected]

//#define PANEL_ACCEL_UNIT	(25.0/(16384*0.1))	//25 pixels -- 0.1g
//#define PANEL_ACCEL_UNIT	(25.0/(16384*0.4))	//25 pixels -- 0.4g
#define STATIC_ACCEL_Z		(ConfigParam.StaticAccelValue[2])

//#define PANEL_VEL_UNIT		(25.0/1000)		//25 pixels -- 1000mm/s
//#define PANEL_VEL_UNIT	(25.0/4000)		//25 pixels -- 4000mm/s
#define STATIC_VEL_Z		0.0

vu8 LM_SW_GraphBufffer[LM_ROW_LEN][LM_COLUMN_LEN];//added by  yz 2015-02-03
/*-----------------------------------------------------------------------------*/
GraphParam_t	GraphParam;

void InitGraphParam(GraphParam_t *p)
{
	p->TimeStamp = TIM_GetTime();
	p->State = CLEAR_SCREEN;
}

void ProcessGraph(GraphParam_t *p)
{
	double TempAccel = 0;
	double TempVel = 0;
		
	if(TIM_IsExpired(p->TimeStamp))
	{
		p->TimeStamp = TIM_GetTime()+ 500;
		GPIO_WriteBit(	LED_1_GPIO_Port, LED_1_GPIO_Pin, 
					(BitAction)(GPIO_ReadInputDataBit(LED_1_GPIO_Port, LED_1_GPIO_Pin)^0x01));
	}
	
	switch(p->State)
	{
		case CLEAR_SCREEN :
		{								
			PanelInit();
			MeasureParam.Velocity[0] = 0.0;
			MeasureParam.Velocity[1] = 0.0;
			MeasureParam.Velocity[2] = 0.0;
			
			p->TimeStamp = TIM_GetTime();
			p->TimeRefreshPoint = TIM_GetTime();
			p->TimeStampIntegral = TIM_GetTime();
			p->State = DRAW_CURVE;

			
		}break;
		
		case DRAW_CURVE:
		{
			if(TIM_IsExpired(p->TimeRefreshPoint))
			{
				p->TimeRefreshPoint = TIM_GetTime() + 100;	
				
				PanelAccel.Index++;				
				if(PanelAccel.Index > PanelAccel.LengthX)
				{
					PanelAccel.Index = 0;
					PanelInit();
				}
					
				TempAccel = (MeasureParam.FilteredAccel[2] - STATIC_ACCEL_Z)*RANGE_ACCEL_SELECTED;
				TempVel = (MeasureParam.Velocity[2] - STATIC_VEL_Z)*RANGE_VEL_SELECTED;
				
				if(TempAccel > 25)
					TempAccel = 25;
				if(TempAccel < -25)
					TempAccel = -25;
				
				if(TempVel > 25)
					TempVel = 25;
				if(TempVel < -25)
					TempVel = -25;

//				PanelDrawPoint(	PanelAccel.LogicalZeroX,PanelAccel.LogicalZeroY,
//								PanelAccel.Index,
//								(MeasureParam.OriginalAccel[2] - STATIC_ACCEL_Z)*PANEL_ACCEL_UNIT);
				
				PanelDrawPoint(	PanelAccel.LogicalZeroX,PanelAccel.LogicalZeroY,
								PanelAccel.Index,TempAccel );
												
				PanelDrawPoint(	PanelVel.LogicalZeroX,PanelVel.LogicalZeroY,
								PanelAccel.Index,TempVel);
			}
			
			if(TIM_IsExpired(p->TimeStampIntegral))
			{
				p->TimeStampIntegral = TIM_GetTime() + STORE_DATA_INTERVAL;
				MeasureParam.Velocity[2] += (MeasureParam.OriginalAccel[2] - STATIC_ACCEL_Z)*
											(STORE_DATA_INTERVAL)*9.8/16384;
			}
									
		}break;

		default:break;
	}	
}

/*--------------------------------------------------------------------------*/
Panel_t PanelAccel;
Panel_t PanelVel;

void PanelAccelStructureInit(Panel_t *p)
{
	p->LengthX = 240;
	p->LengthY = 50;
	p->PhyZeroX = 0;
	p->PhyZeroY = 0;
	p->LogicalZeroX = p->PhyZeroX;
	p->LogicalZeroY = p->PhyZeroY + p->LengthY/2;	
}

void PanelVelStructureInit(Panel_t *p)
{
	p->LengthX = 240;
	p->LengthY =50;
	p->PhyZeroX = 0;
	p->PhyZeroY = 51;
	p->LogicalZeroX = p->PhyZeroX;
	p->LogicalZeroY = p->PhyZeroY + p->LengthY/2;
	p->Index = 0;
	p->TimeStamp = TIM_GetTime();
	
}

void PanelInit(void)
{
	u16 i,j;
	
	LM_Clear();
	
	for(i=0;i<LM_ROW_LEN;i++)
	{
		for(j=0;j<LM_COLUMN_LEN;j++)
			LM_SW_GraphBufffer[i][j] = 0X00;
	}
	
	PanelAccelStructureInit( &PanelAccel);
	PanelVelStructureInit( &PanelVel);
	
	PanelDrawCoordinate(&PanelAccel);
	PanelDrawCoordinate(&PanelVel);
	
	PanelAccel.Index = 0;
	PanelVel.Index = 0;
	
//	MeasureParam.Velocity[0] = 0.0;
//	MeasureParam.Velocity[1] = 0.0;
//	MeasureParam.Velocity[2] = 0.0;
	
}

void PanelDrawCoordinate(Panel_t *p)
{
	u16 i;
	
	DispIndiction(0,14,"Measure...");
	DispIndiction(90,14,"Press Esc to stop");
	if(ConfigParam.RangeSelected == 0)
	{
		DispIndiction(0,13,"0.1 G , 1.0 M/S");
	}
	
	if(ConfigParam.RangeSelected == 1)
	{
		DispIndiction(0,13,"0.2 G , 2.0 M/S");
	}
	
	if(ConfigParam.RangeSelected == 2)
	{
		DispIndiction(0,13,"0.4 G , 4.0 M/S");
	}
	
	for(i=0;i<p->LengthY;i++)//Y
	{
		LM_SW_DrawPoint(p->PhyZeroX,p->PhyZeroY+i);
		LM_SW_DrawPoint(p->PhyZeroX+p->LengthX-1,p->PhyZeroY+i);
	}
	
	for(i=0;i<p->LengthX;i++)//X
	{
		LM_SW_DrawPoint(p->PhyZeroX+i,p->PhyZeroY);
		LM_SW_DrawPoint(p->PhyZeroX+i,p->PhyZeroY+p->LengthY);
	}
	
	for(i=0;i<p->LengthX;i++)//Middle
	{
		if(i%3)
			LM_SW_DrawPoint(p->LogicalZeroX+i,p->LogicalZeroY);			
	}

	
}

/*--------------------------------------------------------------------------*/
void LM_SW_DrawPoint(u16 x,u16 y)
{
	u8 PageIndex,ColumnIndex;
	u8 CurrentValue;
	
	PageIndex = y/8;
	ColumnIndex = x;
	CurrentValue = LM_SW_GraphBufffer[PageIndex][ColumnIndex];
	
	if( !(CurrentValue & (0x01<<y%8)) )	
	{	
		LM_SW_GraphBufffer[PageIndex][ColumnIndex] |= 0x01<<y%8 ;
		
		LM_SdCmd(PageIndex|0xb0);               // 设置页地址
		LM_SdCmd(ColumnIndex&0x0f);               // 设置列地址低4位
		LM_SdCmd((ColumnIndex>>4)|0x10);          // 设置列地址高4位
		LM_SdData(LM_SW_GraphBufffer[PageIndex][ColumnIndex]);
	}
	
}

void LM_SW_ClearPoint(u16 x,u16 y)
{
	u8 PageIndex,ColumnIndex;
	u8 CurrentValue;
	
	PageIndex = y/8;
	ColumnIndex = x;
	CurrentValue = LM_SW_GraphBufffer[PageIndex][ColumnIndex];
	
	if((CurrentValue | (0x01<<y%8)))
	{
		LM_SW_GraphBufffer[PageIndex][ColumnIndex] &= ~(0x01<<y%8) ;
		
		LM_SdCmd(PageIndex|0xb0);               // 设置页地址
		LM_SdCmd(ColumnIndex&0x0f);               // 设置列地址低4位
		LM_SdCmd((ColumnIndex>>4)|0x10);          // 设置列地址高4位
		LM_SdData(LM_SW_GraphBufffer[PageIndex][ColumnIndex]);
	}				
}

void PanelDrawPoint(u16 ZeroX,u16 ZeroY,s16 X,s16 Y)
{
	LM_SW_DrawPoint(ZeroX + X,ZeroY-Y);	
}

void PanelClearPoint(u16 ZeroX,u16 ZeroY,s16 X,s16 Y)
{
	LM_SW_ClearPoint(ZeroX + X,ZeroY-Y); 	
}



