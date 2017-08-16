#include "SetPanel.h"
#include <userint.h>
#include "MainPanel.h"
#include"myinclude.h"  


Param_t					Param; 
static int 				SetPanelHandle; 
/*---------------------------------------------------------------------------------------------------------*/
void CVICALLBACK Setting (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	
		if ((SetPanelHandle = LoadPanel (0, "SetPanel.uir", PANEL_SET)) < 0)
		QuitUserInterface (0);
		
/*		Param.Unit_Accel = METERS_QUATER_SECOND;
		Param.Unit_Velocity = METERS_SECOND;
		Param.Direction_Vertical = VERTICAL_Z;
		Param.Direction_Landing = LANDING_X;
		Param.Filter_Type = FILTER_MV;
		Param.Raw_Accel = RAW_ACCEL_Z;
		Param.Filtered_Accel = FILTERED_ACCEL_Z;
		Param.Velocity = VEL_RAW_Z;
*/		
		if(Param.Unit_Velocity == METERS_SECOND)
			SetCtrlVal (SetPanelHandle,PANEL_SET_UNIT_VEL_METER , 1);
		if(Param.Unit_Velocity == MILLI_METERS_SECOND)
			SetCtrlVal (SetPanelHandle,PANEL_SET_UNIT_VEL_MILLI_METER, 1);

		
		
		DisplayPanel (SetPanelHandle);	
}
/*---------------------------------------------------------------------------------------------------------*/
int CVICALLBACK SetPanelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			DiscardPanel (SetPanelHandle);

			break;
	}
	return 0;
}
/*---------------------------------------------------------------------------------------------------------*/
int CVICALLBACK SetAffirm (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{   
	int TempCtrlValue;

	switch (event)
	{
		case EVENT_COMMIT:
			
			/*-----------------------------------------------------------------------------------------------*/
			GetCtrlVal (SetPanelHandle, PANEL_SET_UNIT_ACCEL_1, &TempCtrlValue);
			
			if(TempCtrlValue == 1)
				Param.Unit_Accel = LSB; 
			
			GetCtrlVal (SetPanelHandle, PANEL_SET_UNIT_ACCEL_2, &TempCtrlValue);
			
			if(TempCtrlValue == 1)
				Param.Unit_Accel = METERS_QUATER_SECOND; 

			GetCtrlVal (SetPanelHandle, PANEL_SET_UNIT_ACCEL_3, &TempCtrlValue);
			
			if((TempCtrlValue == 1))
				Param.Unit_Accel = MILLI_GRAVITY; 
				
/*-----------------------------------------------------------------------------------------------*/	
			GetCtrlVal (SetPanelHandle, PANEL_SET_UNIT_VEL_METER, &TempCtrlValue); 
			if(TempCtrlValue == 1)
				Param.Unit_Velocity= METERS_SECOND;
			GetCtrlVal (SetPanelHandle, PANEL_SET_UNIT_VEL_MILLI_METER, &TempCtrlValue);
			if(TempCtrlValue == 1)
				Param.Unit_Velocity= MILLI_METERS_SECOND;
/*-----------------------------------------------------------------------------------------------*/	
			GetCtrlVal (SetPanelHandle, PANEL_SET_DIR_VERTICAL_1, &TempCtrlValue);
			if(TempCtrlValue == 1)
				Param.Direction_Vertical= VERTICAL_X;
			if(GetCtrlVal (SetPanelHandle, PANEL_SET_DIR_VERTICAL_2, &TempCtrlValue)&&(TempCtrlValue == 1))
				Param.Direction_Vertical= VERTICAL_Y;
			if(GetCtrlVal (SetPanelHandle, PANEL_SET_DIR_VERTICAL_3, &TempCtrlValue)&&(TempCtrlValue == 1))
				Param.Direction_Vertical= VERTICAL_Z;
/*-----------------------------------------------------------------------------------------------*/
			GetCtrlVal (SetPanelHandle, PANEL_SET_DIR_LANDING_1, &TempCtrlValue);
			if(TempCtrlValue == 1)
				Param.Direction_Landing= LANDING_X;
			GetCtrlVal (SetPanelHandle, PANEL_SET_DIR_LANDING_2, &TempCtrlValue);
			if(TempCtrlValue == 1)
				Param.Direction_Landing= LANDING_Y;
			if(GetCtrlVal (SetPanelHandle, PANEL_SET_DIR_LANDING_3, &TempCtrlValue)&&(TempCtrlValue == 1))
				Param.Direction_Landing= LANDING_Z;
/*-----------------------------------------------------------------------------------------------*/	
/*			GetCtrlVal (SetPanelHandle, PANEL_SET_FILTER_TYPE_1, &TempCtrlValue);
			if(TempCtrlValue == 1)
				Param.Filter_Type= FILTER_NONE;
			GetCtrlVal (SetPanelHandle, PANEL_SET_FILTER_TYPE_2, &TempCtrlValue);
			if(TempCtrlValue == 1)
				Param.Filter_Type= FILTER_MA;
			GetCtrlVal (SetPanelHandle, PANEL_SET_FILTER_TYPE_3, &TempCtrlValue);
			if(TempCtrlValue == 1)
				Param.Filter_Type= FILTER_MV;
*/
/*-----------------------------------------------------------------------------------------------*/	 			
			GetCtrlVal (SetPanelHandle, PANEL_SET_FILTER_WIN_LEN, &Param.Filter_WinLen);
			GetCtrlVal (SetPanelHandle, PANEL_SET_RECORD_INTERVAL, &Param.Record_Interval);
			GetCtrlVal (SetPanelHandle, PANEL_SET_STATIC_TIME, &Param.Static_Time);
/*-----------------------------------------------------------------------------------------------*/
			MessagePopup ("Param Set", "Param Set Succeed"); 

			break;
	}
	return 0;
}
/*---------------------------------------------------------------------------------------------------------*/
int CVICALLBACK SetCancel (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
