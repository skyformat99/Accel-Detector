#ifndef FILEBROWSER_H__
#define FILEBROWSER_H__

#ifdef __cplusplus
    extern "C" {
#endif

#include <cvidef.h>
#include <userint.h>

#if defined (_NI_mswin32_) && _NI_mswin32_
#define ROOT_LEVEL_STRING               "My Computer" // use this string for rootPath to browse all drives
#elif defined (_NI_linux_) && _NI_linux_
#define ROOT_LEVEL_STRING               "/" // use this string for rootPath to browse all drives
#endif

// these are the restrictions on the size of the filter buffer being set
#define MAX_FILTER_EXTENSIONS           10          // this should be enough for most uses
#define MAX_FILTER_BUFFER_LENGTH        1024

#define MAX_TIMESTRING_LEN              100

// these are the possible values of ATTR_TIME_FORMAT
enum ATTR_TIME_FORMAT_VALUE {
    TIME_FORMAT_UNITEDSTATES,                   // ie January 1, 1990
    TIME_FORMAT_EUROPEAN,                       // ie 1 January 1990
    TIME_FORMAT_FUNCTION,                       // defined by a user supplied function
    TIME_FORMAT_NUM_VALUES,
    TIME_FORMAT_FIRST   = TIME_FORMAT_UNITEDSTATES,
    TIME_FORMAT_LAST    = TIME_FORMAT_NUM_VALUES
};
typedef int (CVICALLBACK *FileBrowserTimeFormatPtr)(char* string, int day, int month, int year, int hours, int minutes, int seconds);

// this is the complete external API
int CVIFUNC     FileBrowser_Create(int panel, int control, char* startPath);
int CVIFUNC     FileBrowser_Revert(int panel, int control);
int CVIFUNC     FileBrowser_GetAttribute(int panel, int control, int attribute, void* data);
int CVIFUNC_C   FileBrowser_SetAttribute(int panel, int control, int attribute, ...);
int CVIFUNC     FileBrowser_GetSelectedFiles(int panel, int control, char*** files);
int CVIFUNC     FileBrowser_Refresh(int panel, int control, int index);


// here are the available attributes that can be set
#define ATTR_START_PATH                 150
#define ATTR_FILE_FILTER                151
#define ATTR_DIRECTORIES_ONLY           152
#define ATTR_BROWSE_FLOPPYDRIVES        153
#define ATTR_BROWSE_HARDDRIVES          154
#define ATTR_BROWSE_NETWORKDRIVES       155
#define ATTR_BROWSE_CDROMDRIVES         156
#define ATTR_BROWSE_RAMDISK             157
#define ATTR_BROWSE_UNKNOWN             158
#define ATTR_TIME_FORMAT                159
#define ATTR_TIME_FORMAT_FUNCTION       160
#define ATTR_COLUMN_SIZE_VISIBLE        161
#define ATTR_COLUMN_TIME_VISIBLE        162
#define ATTR_COLUMN_TYPE_VISIBLE        163
#define ATTR_ICONS_VISIBLE              164
#define ATTR_PATH_RELATIVE              165

#ifdef __cplusplus
    }
#endif

#endif // !DEFINED FILEBROWSER_H__
