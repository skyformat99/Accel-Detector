

#ifndef _ITEM_H
#define _ITEM_H

#include "menu.h"
#include "item.h"


extern Window_t		MainMenu;
extern Window_t		MeasureMenu;
extern Window_t		ConfigureMenu;
extern Window_t		SetCtrlModeMenu;
extern Window_t	SetRangeMenu;

extern Item_t		Measure;
extern Item_t		Calibrate;
extern Item_t		Configure;
extern Item_t		SetRange;
extern Item_t		SetCtrlMode;
extern Item_t		SetTimeDate; 
extern Item_t		Start; 
extern Item_t		Exit;
extern Item_t		IR_CtrlMode;
extern Item_t		KEY_CtrlMode;
extern Item_t		SetRange_1;
extern Item_t		SetRange_2;
extern Item_t		SetRange_3;
/*-------------------------------------------------------------------------------*/

typedef struct
{
	u8 BitNum;	
	s16 X;
	s16 Y;	
}ItemInput_t;

typedef enum
{
	INIT,
	ENTER,
	PROCESS,
	EXIT,
}ItemState_t;

typedef struct
{	
	ItemState_t		State;
	vu32			Time;	
	ItemInput_t		Input[14];
	s8 				Focus;
}ItemInherit_t;

extern ItemInherit_t	InheritSetTimeData;
extern ItemInherit_t	InheritStart;
extern ItemInherit_t	InheritStop;
extern ItemInherit_t	InheritCalibrate;

void Esc_SetTimeDate(void);
void UpDn_SetTimeDate(void);
void Right_SetTimeDate(void);
void Enter_SetTimeDate(void);

void Esc_Start(void);
void UpDn_Start(void);
void Right_Start(void);
void Enter_Start(void);

void Esc_Exit(void);
void UpDn_Exit(void);
void Right_Exit(void);
void Enter_Exit(void);

void Enter_IR_CtrlMode(void);
void Enter_KEY_CtrlMode(void);

void Esc_Calibrate(void);
void UpDn_Calibrate(void);
void Right_Calibrate(void);
void Enter_Calibrate(void);

void Enter_SetRange_1(void);
void Enter_SetRange_2(void);
void Enter_SetRange_3(void);


#endif

