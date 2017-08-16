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

#define  PANEL_FILE                       1       /* callback function: FilePanelCB */
#define  PANEL_FILE_PROGRESS_BAR          2
#define  PANEL_FILE_FILE_BROWSER          3
#define  PANEL_FILE_BUTTON_LOAD_FILE      4       /* callback function: AffirmLoadFile */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK AffirmLoadFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK FilePanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
