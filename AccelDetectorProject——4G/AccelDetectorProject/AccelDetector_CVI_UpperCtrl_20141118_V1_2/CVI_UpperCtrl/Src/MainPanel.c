#include <cvirte.h>		
#include <userint.h>
#include "MainPanel.h"
#include"myinclude.h"

static int MainPanelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((MainPanelHandle = LoadPanel (0, "MainPanel.uir", PANEL_MAIN)) < 0)
		return -1;
	
	Param.Unit_Accel = LSB;
	Param.Unit_Velocity = METERS_SECOND;
	Param.Direction_Vertical = VERTICAL_Z;
	Param.Direction_Landing = LANDING_X;
//	Param.Filter_Type = FILTER_MV;
//	Param.Raw_Accel = RAW_ACCEL_Z;
//	Param.Filtered_Accel = FILTERED_ACCEL_Z;
//	Param.Velocity = VEL_RAW_Z;
	
	DisplayPanel (MainPanelHandle);
	RunUserInterface ();
	DiscardPanel (MainPanelHandle);
	return 0;
}

int CVICALLBACK MainPanelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
