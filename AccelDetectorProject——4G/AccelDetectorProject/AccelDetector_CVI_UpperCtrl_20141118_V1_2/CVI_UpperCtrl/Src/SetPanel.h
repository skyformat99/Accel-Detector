/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2014. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL_SET                        1       /* callback function: SetPanelCB */
#define  PANEL_SET_DECORATION             2
#define  PANEL_SET_UNITS                  3
#define  PANEL_SET_UNIT_VEL_MILLI_METER   4
#define  PANEL_SET_DIR_VERTICAL_3         5
#define  PANEL_SET_DIR_VERTICAL_2         6
#define  PANEL_SET_DIR_LANDING_3          7
#define  PANEL_SET_DIR_LANDING_2          8
#define  PANEL_SET_DIR_LANDING_1          9
#define  PANEL_SET_FILTER_TYPE_MV         10
#define  PANEL_SET_FILTER_TYPE_MA         11
#define  PANEL_SET_FILTER_TYPE_NONE       12
#define  PANEL_SET_DIR_VERTICAL_1         13
#define  PANEL_SET_UNIT_VEL_METER         14
#define  PANEL_SET_UNIT_ACCEL_3           15
#define  PANEL_SET_UNIT_ACCEL_2           16
#define  PANEL_SET_UNIT_ACCEL_1           17
#define  PANEL_SET_DECORATION_2           18
#define  PANEL_SET_ANALYSIS               19
#define  PANEL_SET_DECORATION_3           20
#define  PANEL_SET_DECORATION_4           21
#define  PANEL_SET_DECORATION_5           22
#define  PANEL_SET_RECORD_INTERVAL        23
#define  PANEL_SET_STATIC_TIME            24
#define  PANEL_SET_FILTER_WIN_LEN         25
#define  PANEL_SET_BUTTON_SET_CANCEL      26      /* callback function: SetCancel */
#define  PANEL_SET_DECORATION_7           27
#define  PANEL_SET_BUTTON_SET_AFFIRM      28      /* callback function: SetAffirm */
#define  PANEL_SET_DECORATION_6           29
#define  PANEL_SET_STR_ACCEL              30
#define  PANEL_SET_STR_VERTICAL           31
#define  PANEL_SET_STR_VELOCITY           32
#define  PANEL_SET_STR_LANDING            33
#define  PANEL_SET_STR_FILTER             34
#define  PANEL_SET_STR_WIN_LEN            35
#define  PANEL_SET_DECORATION_8           36
#define  PANEL_SET_STR_STATIC_TIME        37
#define  PANEL_SET_STR_RECORD_INTERVAL    38


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK SetAffirm(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SetCancel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SetPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
