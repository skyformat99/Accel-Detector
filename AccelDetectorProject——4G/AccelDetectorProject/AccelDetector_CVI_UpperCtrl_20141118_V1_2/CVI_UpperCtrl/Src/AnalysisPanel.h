/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2015. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL_ANAL                       1       /* callback function: AnalysisPanelCB */
#define  PANEL_ANAL_RING_FILTER_TYPE      2       /* callback function: ChangeFilterType */
#define  PANEL_ANAL_RING_VELOCITY         3       /* callback function: ChangeVelocity */
#define  PANEL_ANAL_RING_PROCESS_ACCEL    4       /* callback function: ChangeAccelProcess */
#define  PANEL_ANAL_RING_RAW_ACCEL        5       /* callback function: ChangeRawAccel */
#define  PANEL_ANAL_DECORATION            6
#define  PANEL_ANAL_DECORATION_2          7
#define  PANEL_ANAL_GRAPH_3               8       /* callback function: Annotate */
#define  PANEL_ANAL_GRAPH_2               9       /* callback function: Annotate */
#define  PANEL_ANAL_GRAPH_1               10      /* callback function: Annotate */
#define  PANEL_ANAL_STR_RAW_ACCEL         11
#define  PANEL_ANAL_STR_ACCEL_PROCESS     12
#define  PANEL_ANAL_DECORATION_3          13
#define  PANEL_ANAL_STR_VELOCITY          14
#define  PANEL_ANAL_DECORATION_4          15
#define  PANEL_ANAL_NUMERIC_FILETER_LEN   16      /* callback function: ChangeFilterLen */
#define  PANEL_ANAL_STR_FILTER            17


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK AnalysisPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Annotate(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ChangeAccelProcess(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ChangeFilterLen(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ChangeFilterType(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ChangeRawAccel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ChangeVelocity(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
