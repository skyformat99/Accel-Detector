
#ifndef _GRAPH_H
#define _GRAPH_H

#include "stm32f10x.h"
#include "graph.h"

typedef enum
{
	CLEAR_SCREEN,
	DRAW_CURVE,
}GraphState_t;

typedef struct
{
	GraphState_t	State;
	u32				TimeStamp;
	u32 			TimeRefreshPoint;
	u32				TimeStampIntegral;
}GraphParam_t;

extern GraphParam_t	GraphParam;
extern void InitGraphParam(GraphParam_t *p);
extern void ProcessGraph(GraphParam_t *p);


/*-----------------------------------------------------------------------*/


#define LM_ROW_LEN		16
#define LM_COLUMN_LEN	240

extern  vu8 LM_SW_GraphBufffer[LM_ROW_LEN][LM_COLUMN_LEN];//added by  yz 2015-02-03


typedef struct 
{
	u16 PhyZeroX;
	u16 PhyZeroY;
	u16 LogicalZeroX;
	u16 LogicalZeroY;
	u16 LengthX;
	u16 LengthY;
	
	vu32 TimeStamp;
	u16  Index;
	
}Panel_t;

extern Panel_t PanelAccel;
extern Panel_t PanelVel;

void PanelAccelStructureInit(Panel_t *p);
void PanelVelStructureInit(Panel_t *p);

void PanelInit(void);
void PanelDrawCoordinate(Panel_t *p);
void PanelDrawPoint(u16 ZeroX,u16 ZeroY,s16 X,s16 Y);
void PanelClearPoint(u16 ZeroX,u16 ZeroY,s16 X,s16 Y);

/*-----------------------------------------------------------------------*/

void LM_SW_DrawPoint(u16 x,u16 y);
void LM_SW_ClearPoint(u16 x,u16 y);



#endif




