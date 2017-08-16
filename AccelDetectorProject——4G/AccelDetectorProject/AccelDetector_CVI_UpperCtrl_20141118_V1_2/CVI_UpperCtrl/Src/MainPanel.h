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

#define  PANEL_MAIN                       1       /* callback function: MainPanelCB */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_FILE                     2
#define  MENUBAR_FILE_FILE_LOAD           3       /* callback function: LoadFile */
#define  MENUBAR_SETTING                  4
#define  MENUBAR_SETTING_SETTING          5       /* callback function: Setting */
#define  MENUBAR_ANALYSIS                 6
#define  MENUBAR_ANALYSIS_ANALYSIS        7       /* callback function: Analysis */


     /* Callback Prototypes: */

void CVICALLBACK Analysis(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK LoadFile(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK MainPanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK Setting(int menubar, int menuItem, void *callbackData, int panel);


#ifdef __cplusplus
    }
#endif
