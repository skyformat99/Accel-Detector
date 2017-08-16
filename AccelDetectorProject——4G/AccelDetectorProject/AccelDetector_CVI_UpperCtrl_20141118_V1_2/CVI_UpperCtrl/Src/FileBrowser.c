#include <cvidef.h>
#if defined (_NI_mswin32_) && _NI_mswin32_
#include <windows.h>    // needed for the few API calls necessary for drive letter related issues
#include <shellapi.h>   // needed for file type icon retrieval
#elif defined (_NI_linux_) && _NI_linux_
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define HIWORD(x)   (((x) >> 16) & 0x0000ffff)
#define LOWORD(x)   (((x) >>  0) & 0x0000ffff)
#endif
#include <userint.h>
#include <toolbox.h>
#include <utility.h>
#include <ansi_c.h>
#include "FileBrowser.h"

#define CHAIN_KEY                       "NI_CVI_FILEBROWSER_CTRL"
#define COLUMN_DOESNT_EXIST             -2
#define TIME_STR                        "Time"
#define SIZE_STR                        "Size"
#define TYPE_STR                        "File Type"
#define NAME_STR                        "Name"
#define FOLDERS_STR                     "Folders"

// the units labels for the size column
#define BYTE_STR                        "B"
#define KILOBYTE_STR                    "KB"
#define MEGABYTE_STR                    "MB"
#define GIGABYTE_STR                    "GB"

// this is the number of files to process when adding to the tree before
// making a call to ProcessDrawEvents()
#define PROCESS_DRAW_EVENTS_FREQUENCY   100

#define DIR_STR                         "DIR"
#define FILE_STR                        "FILE"
#define MAX_TAGBASE_STRLEN              5       // length of "FILE"+1

#define DEFERRED_CALL_DELAY             5e-3 // this should be long enough for other events (like redraw) to get processed
#define KEYPRESS_DELAY                  1.0
#define IDLE_TRACK_INTERVAL             0.3
#define DRAG_TRACK_INTERVAL             0.1

#define DRAG_WIDTH                      5
#define MIN_TREE_WIDTH                  20
#define DEFAULT_FILE_COLUMN_WIDTH       150
#define DEFAULT_SIZE_COLUMN_WIDTH       75
#define DEFAULT_TIME_COLUMN_WIDTH       125
#define DEFAULT_TYPE_COLUMN_WIDTH       150
#if defined (_NI_mswin32_) && _NI_mswin32_
#define PATH_SEPARATOR                  "\\"
#elif defined (_NI_linux_) && _NI_linux_
#define PATH_SEPARATOR                  "/"
#endif

typedef struct _Tracking {
    int     enabled;
    int     cursor;
    int     startX;
    int     treeLeft;
    int     treeWidth;
    int     listWidth;
    int     treeInvisible;
    int     listInvisible;
} Tracking;

typedef struct _FileBrowser {
    char        *rootPath;                  // path to the root of the tree
    int         panel;                      // user's panel
    int         frame;
    int         frameThickness;
    int         tree;                       // user's tree
    int         list;
    int         drag;
    int         timerKey;
    Tracking    tracking;                   // info for tracking the mouse when using drag bar
    int         directoriesOnly;            // whether or not to browse directories only
    int         rootIndex;                  // index of the root node of the tree
    char        **fileFilter;               // what files to filter
    int         browseFloppydrives;         // the following determine whether or not to browse various types of drives
    int         browseHarddrives;
    int         browseNetworkdrives;
    int         browseCDRomdrives;
    int         browseRamdiskdrives;
    int         browseUnknowndrives;
    int         columnIndexSize;            // index for the size column.  COLUMN_DOESNT_EXIT if it doesn't exist
    int         columnIndexTime;            // index for the time column
    int         columnIndexType;            // index for the type column
    int         timeFormat;                 // US or European time format
    int         relativePaths;              // whether to return relative or absolute paths
#if defined (_NI_mswin32_) && _NI_mswin32_
    int         fileIconsVisible;           // whether or not to show icons
    ListType    fileTypeIconsList;          // list of the icons for different file types
#endif
    FileBrowserTimeFormatPtr formatter;     // optional function to format the time however desired
    int         lockHandle;                 // multithread lock
    int         saveWidth;
    char        *chainKey;
    int         discarding;
} FileBrowser;


#if defined (_NI_mswin32_) && _NI_mswin32_
static HMODULE  shell32module=NULL;         // address of shell32.dll in memory
static DWORD_PTR (__stdcall *SHGetFileInfoPtr)(LPCTSTR, DWORD, SHFILEINFO*, UINT, UINT);    // pointer to SHGetFileInfo function in shell32.dll
#endif

// the data we post for deferred callbacks
typedef struct _CallbackData {
    int         panel;
    int         ctrl;
    int         index;
    int         keyCol;
    double      time1;
    double      time2;
} CallbackData;

#if defined (_NI_mswin32_) && _NI_mswin32_
typedef struct _FileTypeData {
    HICON       handle;
    int         sysImageIndex;
    int         treeImageIndex;
} FileTypeData;
#elif defined (_NI_linux_) && _NI_linux_
typedef unsigned int UINT;
#endif

//////////////////////////////////////////////////////////////////////////
// Forward Declarations
static int CVIFUNC      GetUniqueChainKey (const char* baseName, int panel, int control, char** name);
static void CVIFUNC     DiscardFileBrowser(FileBrowser* info);
static int CVICALLBACK  TimerKeyCb(int panel, int control, int event, void *cbData,
                                      int eventData1, int eventData2);
static int CVICALLBACK  FileBrowserCb(int panel, int control, int event, void *cbData, int eventData1, int eventData2);
static int CVICALLBACK  DragBarCb(int panel, int control, int event, void *cbData, int eventData1, int eventData2);
static int CVICALLBACK  FileBrowserPanelCb(int panel, int event, void *callbackData, int eventData1, int eventData2);
static int CVIFUNC      IsDir(int panel, int control, int index, int* result);
static int CVIFUNC      IsDirFromDisk(char* fileName, int* result);
static int CVIFUNC      IsHidden(char* fileName, int* result);
static int CVIFUNC      PopulateFoldersOnExpand(int panel, int control, int index);
static int CVIFUNC      PopulateFolder(int panel, int control, int index);
static int CVIFUNC      PopulateFolderWithPath(int panel, int control, int index, char* startPath);
static int CVIFUNC      InsertIntoFolders(FileBrowser *info, int index, char* fileName,
                                char* startPath, char* tagBase);
static int CVIFUNC      InsertIntoList(FileBrowser *info, char* fileName,
                                char* startPath, char* tagBase);
static int CVIFUNC      IsFileValid(char* fileName, char** filters);
static void CVICALLBACK PopulateFoldersOnExpandWrapper(void *cbdata);
static int CVIFUNC      GetFileBrowserPtr(int panel, int control, FileBrowser** ptr);
static int CVIFUNC      SetTreeStartPath(FileBrowser* info, char* path);
static int CVIFUNC      PopulateTreeOnExpandAll(int panel, int control, int index);
static int CVIFUNC      SetTreeFileFilter(FileBrowser* info, char* filter);
static int CVIFUNC      MakeFilterString(FileBrowser* info, char* buffer);
static int CVIFUNC      SetDirectoriesOnlyState(FileBrowser* info, int num);
#if defined (_NI_mswin32_) && _NI_mswin32_
static int CVIFUNC      SetBrowseDriveTypeState(int panel, int control, int* type, UINT flag, int num);
static int CVIFUNC      AddDriveTypeToTree(FileBrowser* info, UINT type);
static int CVIFUNC      RemoveDriveType(FileBrowser* info, UINT type);
#endif
static int CVIFUNC      SetTreeColumnState(FileBrowser* info, int* column, int state, char* columnName);
static int CVIFUNC      PopulateTreeColumnsForItem(FileBrowser* info, int index);
static int CVIFUNC      PopulateTreeColumnSize(FileBrowser* info, int index);
static int CVIFUNC      PopulateTreeColumnTime(FileBrowser* info, int index);
static int CVIFUNC      PopulateTreeColumnType(FileBrowser* info, int index);
static int CVIFUNC      ResetTreeColumnValues(FileBrowser* info);
#if defined (_NI_mswin32_) && _NI_mswin32_
static int CVIFUNC      AssignIconToTreeItem(FileBrowser* info, int control, int index);
static int CVIFUNC      GetFileIcon(FileBrowser* info, char* fileName, int* treeBitmap, int flags);
static int CVIFUNC      GetCVIBitmapFromHIcon(HICON icon, int* bitmap);
static int CVICALLBACK  FileTypeDataCompare(void* item1, void* item2);
static int CVICALLBACK  FileTypeDataDispose(int index, void* item, void* data);
static int CVIFUNC      SetIconsVisibleState(FileBrowser* info, int state);
#endif
static int CVIFUNC      Refresh(FileBrowser *info, int index);
static int CVICALLBACK  TreeSortCallback(int panel, int control, int item1, int item2, int keyCol, void* callbackData);
static int CVIFUNC      PopulateListFromFolderIndex(FileBrowser *info, int index);
static int CVIFUNC      PopulateListFromPath(FileBrowser *info, char *startPath);
#if defined (_NI_mswin32_) && _NI_mswin32_
static int CVIFUNC      UpdateTreeImages(FileBrowser *info, int oldIndex);
#endif
static int CVIFUNC      KeyWillChangeSelection(int panel, int control, int keyCode);
static int CVIFUNC      GetIndexFromPath(int panel, int control, char *separator,
                                            char *path, int level, int *treeIndex);

///////////////////////////////////////////////////////////////////////////////
// FileBrowser API functions //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Converts the input TreeCtrl into a FileBrowser.
// panel: handle of panel on which the tree is present
// control: control id of the tree to convert
int CVIFUNC FileBrowser_Create (int panel, int control, char* startPath)
{
    int error = 0;
    FileBrowser *info = NULL;
    short locked = FALSE;
    int stringLength = 0;
    char initialFileFilter[] = ".*";
    int     top, left, height, width, color, zPlane, scrollBars, tabPos, bgColor;
    int     listLeft, treeWidth, frameThickness, dragLeft;
    char    buf[256];
    int     ctrlStyle, labStyle = 0;

    // Create and initialize the file browser.
    nullChk(info = calloc (1, sizeof (FileBrowser)));
    info->fileFilter        = NULL;
    info->rootPath          = NULL;
    info->lockHandle        = -1;
#if defined (_NI_mswin32_) && _NI_mswin32_
    info->fileTypeIconsList = NULL;
#endif
    info->directoriesOnly   = 0; // default to browsing both files and directories
    info->columnIndexSize   = COLUMN_DOESNT_EXIST;
    info->columnIndexTime   = COLUMN_DOESNT_EXIST;
    info->timeFormat        = TIME_FORMAT_UNITEDSTATES;
    info->formatter         = NULL;
#if defined (_NI_mswin32_) && _NI_mswin32_
    info->fileIconsVisible  = TRUE;
#endif
    info->relativePaths     = FALSE;
    info->frame             = 0;
    info->drag              = 0;
    info->list              = 0;
    info->timerKey          = 0;
    info->chainKey          = NULL;
    info->discarding        = FALSE;

#if defined (_NI_mswin32_) && _NI_mswin32_
    // Load a dll because we don't link to shell32.lib by default. This
    // way nothing special is needed to compile.
    if( shell32module==NULL ) {
        shell32module = LoadLibrary("shell32");
        assert(shell32module);
        *(FARPROC*)&SHGetFileInfoPtr = GetProcAddress(shell32module,"SHGetFileInfoA");
        assert(SHGetFileInfoPtr);
    }
#endif
    // Make a lock and aquire it.
    errChk(CmtNewLock(NULL, 0, &info->lockHandle));
    errChk(CmtGetLock(info->lockHandle));
    locked = TRUE;

    info->panel = panel;
    info->tree = control;

    errChk(GetCtrlAttribute (panel, control, ATTR_CTRL_STYLE, &ctrlStyle));
    if (ctrlStyle == CTRL_TREE_LS)
        labStyle = 1;
    else if (ctrlStyle != CTRL_TREE)
        {
        errChk(UIEControlNotTypeExpectedByFunction);
        }

    // create additional controls
    errChk(info->frame      = NewCtrl(panel, (labStyle) ? CTRL_RECESSED_BOX_LS : CTRL_RECESSED_BOX, "", 0, 0));
    errChk(info->drag       = NewCtrl(panel, (labStyle) ? CTRL_RAISED_BOX_LS : CTRL_RAISED_BOX, "", 0, 0));
    errChk(info->list       = NewCtrl(panel, (labStyle) ? CTRL_TREE_LS : CTRL_TREE, "", 0, 0));
    errChk(info->timerKey   = NewCtrl(panel, CTRL_TIMER, 0, -100, -100));

    GetCtrlAttribute(panel, info->tree, ATTR_TOP,    &top);
    GetCtrlAttribute(panel, info->tree, ATTR_LEFT,   &left);
    GetCtrlAttribute(panel, info->tree, ATTR_WIDTH,  &width);
    GetCtrlAttribute(panel, info->tree, ATTR_HEIGHT, &height);

    // configure frame
    errChk(SetCtrlAttribute(panel, info->frame, ATTR_TOP,    top));
    errChk(SetCtrlAttribute(panel, info->frame, ATTR_LEFT,   left));
    errChk(SetCtrlAttribute(panel, info->frame, ATTR_WIDTH,  width));
    errChk(SetCtrlAttribute(panel, info->frame, ATTR_HEIGHT, height));

    // configure tree
    errChk(ClearListCtrl(panel, info->tree));
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_FRAME_VISIBLE, FALSE)); // changes the top and left by the width of the frame
    GetCtrlAttribute(panel, info->tree, ATTR_FRAME_THICKNESS, &frameThickness);
    treeWidth = width/3;
    info->saveWidth = width;
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_WIDTH, treeWidth));
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_SELECTION_MODE, VAL_SELECTION_SINGLE));
    errChk(SetTreeItemAttribute(panel, info->tree, VAL_DFLT_FOR_NEW_OBJECTS, ATTR_COLLAPSED, TRUE));
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_COLUMN_LABELS_VISIBLE, TRUE));
    errChk(SetTreeColumnAttribute(panel, info->tree, 0, ATTR_VERTICAL_GRID_VISIBLE, FALSE));
    errChk(SetTreeColumnAttribute (panel, info->tree, 0, ATTR_LABEL_TEXT, FOLDERS_STR));
    errChk(SetTreeColumnAttribute (panel, info->tree, 0, ATTR_LABEL_JUSTIFY,
                                   VAL_CENTER_CENTER_JUSTIFIED));
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_DATA_TYPE, VAL_STRING));
#if defined (_NI_mswin32_) && _NI_mswin32_
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_SHOW_IMAGES, TRUE));

#endif
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_ENABLE_DRAG_DROP, FALSE));
    errChk(GetUniqueChainKey(CHAIN_KEY, panel, info->tree, &(info->chainKey)));
    errChk(ChainCtrlCallback(info->panel, info->tree, FileBrowserCb, info, info->chainKey));

    // configure drag bar
    dragLeft = left + treeWidth + frameThickness;
    errChk(SetCtrlAttribute(panel, info->drag, ATTR_TOP,    top + frameThickness));
    errChk(SetCtrlAttribute(panel, info->drag, ATTR_LEFT,   dragLeft));
    errChk(SetCtrlAttribute(panel, info->drag, ATTR_WIDTH,  DRAG_WIDTH));
    errChk(SetCtrlAttribute(panel, info->drag, ATTR_HEIGHT, height - 2*frameThickness));
    errChk(InstallCtrlCallback(panel, info->drag, DragBarCb, info));
    errChk(EnableExtendedMouseEvents(panel, info->drag, DRAG_TRACK_INTERVAL));

    // configure list
    listLeft = dragLeft + DRAG_WIDTH;
    errChk(SetCtrlAttribute(panel, info->list, ATTR_FRAME_VISIBLE, FALSE));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_TOP,    top + frameThickness));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_LEFT,   listLeft));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_WIDTH,  width - treeWidth - DRAG_WIDTH - 2*frameThickness));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_HEIGHT, height - 2*frameThickness));
    GetCtrlAttribute(panel, info->tree, ATTR_LABEL_TEXT, buf);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_LABEL_TEXT, buf));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_COLUMN_LABELS_VISIBLE, TRUE));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_SHOW_CONNECTION_LINES, FALSE));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_SHOW_PLUS_MINUS, FALSE));
    errChk(SetTreeColumnAttribute(panel, info->list, 0, ATTR_LABEL_TEXT, NAME_STR));
    errChk(SetTreeColumnAttribute(panel, info->list, 0, ATTR_VERTICAL_GRID_VISIBLE, FALSE));
    errChk(SetTreeColumnAttribute(panel, info->list, 0, ATTR_COLUMN_WIDTH, DEFAULT_FILE_COLUMN_WIDTH));
    errChk(SetTreeColumnAttribute(panel, info->list, 0, ATTR_LABEL_JUSTIFY,
                                   VAL_CENTER_CENTER_JUSTIFIED));
    errChk(info->columnIndexSize = InsertTreeColumn(panel, info->list, -1, SIZE_STR));
    errChk(SetTreeColumnAttribute(panel, info->list, info->columnIndexSize, ATTR_VERTICAL_GRID_VISIBLE, FALSE));
    errChk(SetTreeColumnAttribute(panel, info->list, info->columnIndexSize, ATTR_COLUMN_WIDTH, DEFAULT_SIZE_COLUMN_WIDTH));
    errChk(SetTreeCellAttribute(panel, info->list, VAL_DFLT_FOR_NEW_OBJECTS, info->columnIndexSize, ATTR_LABEL_JUSTIFY, VAL_RIGHT_JUSTIFIED));
    errChk(info->columnIndexTime = InsertTreeColumn(panel, info->list, -1, TIME_STR));
    errChk(SetTreeColumnAttribute(panel, info->list, info->columnIndexTime, ATTR_VERTICAL_GRID_VISIBLE, FALSE));
    errChk(SetTreeColumnAttribute(panel, info->list, info->columnIndexTime, ATTR_COLUMN_WIDTH, DEFAULT_TIME_COLUMN_WIDTH));
    info->columnIndexType = COLUMN_DOESNT_EXIST;
    errChk(SetTreeItemAttribute(panel, info->list, VAL_DFLT_FOR_NEW_OBJECTS, ATTR_COLLAPSED, TRUE));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_DATA_TYPE, VAL_STRING));
#if defined (_NI_mswin32_) && _NI_mswin32_
    errChk(SetCtrlAttribute(panel, info->list, ATTR_SHOW_IMAGES, TRUE));
#endif
    errChk(SetCtrlAttribute(panel, info->list, ATTR_ENABLE_DRAG_DROP, FALSE));
    errChk(InstallCtrlCallback(panel, info->list, FileBrowserCb, info));

    // configure key timer
    errChk(SetCtrlAttribute(panel, info->timerKey, ATTR_ENABLED, FALSE));
    errChk(SetCtrlAttribute(panel, info->timerKey, ATTR_INTERVAL, KEYPRESS_DELAY));
    errChk(InstallCtrlCallback(panel, info->timerKey, TimerKeyCb, info));

    // z plane
    GetCtrlAttribute(panel, info->tree, ATTR_ZPLANE_POSITION, &zPlane);
    errChk(SetCtrlAttribute(panel, info->drag, ATTR_ZPLANE_POSITION, zPlane));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_ZPLANE_POSITION, zPlane));
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_ZPLANE_POSITION, zPlane));
    errChk(SetCtrlAttribute(panel, info->frame, ATTR_ZPLANE_POSITION, zPlane));

    // list label
    GetCtrlAttribute(panel, info->tree, ATTR_LABEL_TOP, &top);
    GetCtrlAttribute(panel, info->tree, ATTR_LABEL_LEFT, &left);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_LABEL_TOP, top));
    errChk(SetCtrlAttribute(panel, info->list, ATTR_LABEL_LEFT, left));

    // colors
    GetCtrlAttribute(panel, info->tree, ATTR_FRAME_COLOR, &color);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_FRAME_COLOR, color));
    errChk(SetCtrlAttribute(panel, info->frame, ATTR_FRAME_COLOR, color));
    errChk(SetCtrlAttribute(panel, info->drag, ATTR_FRAME_COLOR, color));
    GetCtrlAttribute(panel, info->tree, ATTR_COLUMN_LABELS_COLOR, &color);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_COLUMN_LABELS_COLOR, color));
    GetCtrlAttribute(panel, info->tree, ATTR_TREE_BGCOLOR, &bgColor);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_TREE_BGCOLOR, bgColor));
    GetCtrlAttribute(panel, info->tree, ATTR_SCROLL_BAR_COLOR, &color);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_SCROLL_BAR_COLOR, color));
    errChk(SetTreeCellAttribute(panel, info->list, VAL_DFLT_FOR_NEW_OBJECTS, info->columnIndexSize, ATTR_LABEL_BGCOLOR, color));
    errChk(SetTreeCellAttribute(panel, info->list, VAL_DFLT_FOR_NEW_OBJECTS, 0, ATTR_LABEL_BGCOLOR, bgColor));
    errChk(SetTreeCellAttribute(panel, info->list, VAL_DFLT_FOR_NEW_OBJECTS, info->columnIndexSize,
                                    ATTR_LABEL_BGCOLOR, bgColor));
    errChk(SetTreeCellAttribute(panel, info->list, VAL_DFLT_FOR_NEW_OBJECTS, info->columnIndexTime,
                                    ATTR_LABEL_BGCOLOR, bgColor));

    // scroll bars
    GetCtrlAttribute(panel, info->tree, ATTR_SCROLL_BARS, &scrollBars);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_SCROLL_BARS, scrollBars));
    GetCtrlAttribute(panel, info->tree, ATTR_SCROLL_BAR_SIZE, &scrollBars);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_SCROLL_BAR_SIZE, scrollBars));

    // tab order
    GetCtrlAttribute(panel, info->tree, ATTR_CTRL_TAB_POSITION, &tabPos);
    errChk(SetCtrlAttribute(panel, info->list, ATTR_CTRL_TAB_POSITION, tabPos+1));

    errChk(ChainPanelCallback (info->panel, FileBrowserPanelCb, info, info->chainKey));

#if defined (_NI_mswin32_) && _NI_mswin32_
    nullChk(info->fileTypeIconsList = ListCreate(sizeof(FileTypeData)));
#endif
    info->frameThickness = frameThickness;
    // Set the default types of drives to browse.
    // This is currently set to only harddrives, because all other types
    // might cause a read error on startup if there is no media, no network
    // connection, etc.
    info->browseFloppydrives    = FALSE;
    info->browseHarddrives      = TRUE;
    info->browseNetworkdrives   = FALSE;
    info->browseCDRomdrives     = FALSE;
    info->browseRamdiskdrives   = FALSE;
    info->browseUnknowndrives   = FALSE;

    // Set the initial file filter.
    stringLength = strlen(initialFileFilter);
    nullChk(info->fileFilter = calloc(2, sizeof(char*)));
    nullChk(info->fileFilter[0] = calloc(stringLength+1, sizeof(char)));
    CmbStrCpy(info->fileFilter[0], initialFileFilter);

    errChk(CmtReleaseLock(info->lockHandle));
    locked = FALSE;

    errChk(SetTreeStartPath(info, startPath));

Error:
    if(error < 0) {
        if(locked)
            CmtReleaseLock(info->lockHandle);
        DiscardFileBrowser(info);
    }
    return error;
}

// ****************************************************************************
// Reverts the input FileBrowser into a tree control.
int CVIFUNC FileBrowser_Revert (int panel, int control)
{
    int error = 0;
    FileBrowser* info;

    errChk(GetFileBrowserPtr(panel, control, &info));

    errChk(SetCtrlAttribute(panel, info->tree, ATTR_FRAME_VISIBLE, TRUE)); // changes the top and left by the width of the frame
    errChk(SetCtrlAttribute(panel, info->tree, ATTR_WIDTH, info->saveWidth));
    DiscardFileBrowser(info);
Error:
    return error;
}

// ****************************************************************************
int CVIFUNC FileBrowser_GetAttribute(int panel, int control, int attribute,  void* data)
{
    int error = 0;
    FileBrowser* info;

    errChk(GetFileBrowserPtr(panel, control, &info));

    switch(attribute) {
        case ATTR_START_PATH:
            CmbStrCpy(data, info->rootPath);
            break;
        case ATTR_FILE_FILTER:
            errChk(MakeFilterString(info, data));
            break;
        case ATTR_DIRECTORIES_ONLY:
            *(int*)data = info->directoriesOnly;
            break;
        case ATTR_BROWSE_FLOPPYDRIVES:
            *(int*)data = info->browseFloppydrives;
            break;
        case ATTR_BROWSE_HARDDRIVES:
            *(int*)data = info->browseHarddrives;
            break;
        case ATTR_BROWSE_NETWORKDRIVES:
            *(int*)data = info->browseNetworkdrives;
            break;
        case ATTR_BROWSE_CDROMDRIVES:
            *(int*)data = info->browseCDRomdrives;
            break;
        case ATTR_BROWSE_RAMDISK:
            *(int*)data = info->browseRamdiskdrives;
            break;
        case ATTR_BROWSE_UNKNOWN:
            *(int*)data = info->browseUnknowndrives;
            break;
        case ATTR_TIME_FORMAT:
            *(int*)data = info->timeFormat;
            break;
        case ATTR_TIME_FORMAT_FUNCTION:
            *(FileBrowserTimeFormatPtr*)data = info->formatter;
            break;
        case ATTR_COLUMN_SIZE_VISIBLE:
            *(int*)data = info->columnIndexSize != COLUMN_DOESNT_EXIST ? TRUE : FALSE;
            break;
        case ATTR_COLUMN_TIME_VISIBLE:
            *(int*)data = info->columnIndexTime != COLUMN_DOESNT_EXIST ? TRUE : FALSE;
            break;
        case ATTR_COLUMN_TYPE_VISIBLE:
            *(int*)data = info->columnIndexType != COLUMN_DOESNT_EXIST ? TRUE : FALSE;
            break;
        case ATTR_ICONS_VISIBLE:
#if defined (_NI_mswin32_) && _NI_mswin32_
            *(int*)data = info->fileIconsVisible;
#elif defined (_NI_linux_) && _NI_linux_
            *(int*)data = FALSE;
#endif
            break;
        case ATTR_PATH_RELATIVE:
            *(int*)data = info->relativePaths;
            break;
        default:
            errChk(UIEInvalidAttribute);
            break;
    }

Error:
    return error;
}

// ****************************************************************************
int CVIFUNC_C FileBrowser_SetAttribute(int panel, int control, int attribute, ...)
{
    int         error = UIENoError;
    FileBrowser* info;
    va_list     args;
    char*       string;
    int         num;

    errChk(GetFileBrowserPtr(panel, control, &info));
    errChk(SetWaitCursor(1));

    // Initialize the args list.
    va_start(args, attribute);

    // Figure out the attribute and handle it appropriately.
    switch(attribute) {
        case ATTR_START_PATH:
            string = va_arg(args, char*);
            errChk(SetTreeStartPath(info, string));
            break;
        case ATTR_FILE_FILTER:
            string = va_arg(args, char*);
            errChk(SetTreeFileFilter(info, string));
            break;
        case ATTR_DIRECTORIES_ONLY:
            num = va_arg(args, int);
            errChk(SetDirectoriesOnlyState(info, num));
            break;
        case ATTR_BROWSE_FLOPPYDRIVES:
            num = va_arg(args, int);
#if defined (_NI_mswin32_) && _NI_mswin32_
            errChk(SetBrowseDriveTypeState(panel, control, &info->browseFloppydrives, DRIVE_REMOVABLE, num));
#endif
            break;
        case ATTR_BROWSE_HARDDRIVES:
            num = va_arg(args, int);
#if defined (_NI_mswin32_) && _NI_mswin32_
                errChk(SetBrowseDriveTypeState(panel, control, &info->browseHarddrives, DRIVE_FIXED, num));
#endif
            break;
        case ATTR_BROWSE_NETWORKDRIVES:
            num = va_arg(args, int);
#if defined (_NI_mswin32_) && _NI_mswin32_
            errChk(SetBrowseDriveTypeState(panel, control, &info->browseNetworkdrives, DRIVE_REMOTE, num));
#endif
            break;
        case ATTR_BROWSE_CDROMDRIVES:
            num = va_arg(args, int);
#if defined (_NI_mswin32_) && _NI_mswin32_
            errChk(SetBrowseDriveTypeState(panel, control, &info->browseCDRomdrives, DRIVE_CDROM, num));
#endif
            break;
        case ATTR_BROWSE_RAMDISK:
            num = va_arg(args, int);
#if defined (_NI_mswin32_) && _NI_mswin32_
            errChk(SetBrowseDriveTypeState(panel, control, &info->browseRamdiskdrives, DRIVE_RAMDISK, num));
#endif
            break;
        case ATTR_BROWSE_UNKNOWN:
            num = va_arg(args, int);
#if defined (_NI_mswin32_) && _NI_mswin32_
            errChk(SetBrowseDriveTypeState(panel, control, &info->browseUnknowndrives, DRIVE_UNKNOWN, num));
#endif
            break;
        case ATTR_TIME_FORMAT:
            num = va_arg(args, int);
            if(num >= TIME_FORMAT_FIRST && num < TIME_FORMAT_LAST)
                info->timeFormat = num;
            else
                errChk(UIEValueIsInvalidOrOutOfRange);
            errChk(ResetTreeColumnValues(info));
            break;
        case ATTR_TIME_FORMAT_FUNCTION:
            info->formatter = va_arg(args, FileBrowserTimeFormatPtr);
            if(info->timeFormat == TIME_FORMAT_FUNCTION)
                errChk(ResetTreeColumnValues(info));
            break;
        case ATTR_COLUMN_SIZE_VISIBLE:
            num = va_arg(args, int) ? TRUE : FALSE;
            errChk(SetTreeColumnState(info, &info->columnIndexSize, num, SIZE_STR));
            if(info->columnIndexSize != COLUMN_DOESNT_EXIST)
                {
                errChk(SetTreeColumnAttribute(panel, info->list, info->columnIndexSize, ATTR_COLUMN_WIDTH, DEFAULT_SIZE_COLUMN_WIDTH));
                errChk(SetTreeCellAttribute(panel, info->list, VAL_DFLT_FOR_NEW_OBJECTS, info->columnIndexSize, ATTR_LABEL_JUSTIFY, VAL_RIGHT_JUSTIFIED));
                }
            break;
        case ATTR_COLUMN_TIME_VISIBLE:
            num = va_arg(args, int) ? TRUE : FALSE;
            errChk(SetTreeColumnState(info, &info->columnIndexTime, num, TIME_STR));
            if(info->columnIndexTime != COLUMN_DOESNT_EXIST)
                errChk(SetTreeColumnAttribute(panel, info->list, info->columnIndexTime, ATTR_COLUMN_WIDTH, DEFAULT_TIME_COLUMN_WIDTH));
            break;
        case ATTR_COLUMN_TYPE_VISIBLE:
            num = va_arg(args, int) ? TRUE : FALSE;
            errChk(SetTreeColumnState(info, &info->columnIndexType, num, TYPE_STR));
            if(info->columnIndexType != COLUMN_DOESNT_EXIST)
                errChk(SetTreeColumnAttribute(panel, info->list, info->columnIndexType, ATTR_COLUMN_WIDTH, DEFAULT_TYPE_COLUMN_WIDTH));
            break;
        case ATTR_ICONS_VISIBLE:
            num = va_arg(args, int) ? TRUE : FALSE;
#if defined (_NI_mswin32_) && _NI_mswin32_
            errChk(SetIconsVisibleState(info, num));
#endif
            break;
        case ATTR_PATH_RELATIVE:
            info->relativePaths = va_arg(args, int) ? TRUE : FALSE;
            break;
        default:
            errChk(UIEInvalidAttribute);
            break;
    }

Error:
    va_end(args);
    SetWaitCursor(0);
    return error;
}

// ****************************************************************************
// Returns a list of all selected files.
// Note that this function dynamically allocates an array of strings, to which
// files points, which contains dynamically allocated strings.  All of these
// must be freed by the caller.
int CVIFUNC FileBrowser_GetSelectedFiles(int panel, int control, char*** files)
{
    int error = 0;
    int i;
    FileBrowser* info = NULL;
    ListType list;                              // list to hold filenames as we retrieve them
    int numSelected = -1;                       // number of selected items
    int itemIndex = -1;                         // current item index
    char itemVal[MAX_PATHNAME_LEN] = "";        // value of the current item
    char* itemValPtr = NULL;                    // pointer to somewhere in itemVal
    char* path = NULL;                          // pointer to the current path string

    *files = NULL;

    list = ListCreate(sizeof(char*));
    errChk(GetFileBrowserPtr(panel, control, &info));

    errChk(GetNumTreeItems(info->panel, info->list, VAL_ALL, info->rootIndex, VAL_FIRST, VAL_NEXT_PLUS_SELF, VAL_SELECTED, &numSelected));

    // If none are selected, don't proceed.
    if(numSelected < 1) {
        nullChk(*files = calloc(1, sizeof(char*))); // calloc initializes memory to zeros, so it is already a NULL
        return error;
    }

    // Get all of the selected items and put them in a list.
    errChk(GetTreeItem(info->panel, info->list, VAL_ALL, info->rootIndex, VAL_FIRST, VAL_NEXT_PLUS_SELF, VAL_SELECTED, &itemIndex));

    while(itemIndex >= 0) {
        errChk(GetValueFromIndex(info->panel, info->list, itemIndex, itemVal));
        // If we are using relative paths, strip off the starting path from each.
        // Root level doesn't have anything extra in paths to strip off.
        if(info->relativePaths && CmbStrCmp((unsigned char *)info->rootPath,
                                            (unsigned char *)ROOT_LEVEL_STRING)) {
            assert(CmbStrStr((unsigned char *)itemVal, (unsigned char *)info->rootPath));
            itemValPtr = CmbStrCmp((unsigned char *)info->rootPath, (unsigned char *)itemVal) ?
                                            itemVal + strlen(info->rootPath) + 1 : itemVal;
            assert(itemValPtr < itemVal + strlen(itemVal));
        }
        else
            itemValPtr = itemVal;
        nullChk(path = calloc(strlen(itemValPtr)+1, sizeof(char)));
        CmbStrCpy(path, itemValPtr);
        if(!ListInsertItem(list, &path, END_OF_LIST)) {
            error = -1;
            goto Error;
        }
        errChk(GetTreeItem(info->panel, info->list, VAL_ALL, info->rootIndex, itemIndex, VAL_NEXT, VAL_SELECTED, &itemIndex));
    }

    // Now put all of the items in the list in the final structure to return.
    nullChk(*files = calloc(ListNumItems(list)+1, sizeof(char*)));
    ListGetItems(list, *files, 1, numSelected);

    ListDispose(list);
Error:
    if(error < 0 && *files != NULL) {
        for(i=0; *files[i] != NULL; i++)
            free(*files[i]);
        free(*files);
    }
    return error;
}

// ****************************************************************************
// Refreshes all descendents of index
int CVIFUNC FileBrowser_Refresh(int panel, int control, int index)
{
    int error = 0;
    FileBrowser* info;

    errChk(GetFileBrowserPtr(panel, control, &info));

    errChk(SetWaitCursor(1));

    errChk(Refresh(info, index));

Error:
    SetWaitCursor(0);
    return error;
}


///////////////////////////////////////////////////////////////////////////////
// Internal functions  ////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Generates a unique string based on baseName, and user's panel and control
static int CVIFUNC GetUniqueChainKey (const char* baseName, int panel, int control, char** name)
{
    int         error = 0;
    char        buffer[100], *uniqueName = NULL;

#if defined (_NI_mswin32_) && _NI_mswin32_
    sprintf(buffer, "_%d_%d_%d", GetCurrentProcessId(), panel, control);
#elif defined (_NI_linux_) && _NI_linux_
    sprintf(buffer, "_%d_%d_%d", getpid(), panel, control);
#endif
    nullChk(uniqueName = malloc(sizeof(char) * (strlen(baseName) + strlen(buffer) + 1)));
    strcpy(uniqueName, baseName);
    strcat(uniqueName, buffer);

    *name = uniqueName;
    uniqueName = NULL;

Error:
    free (uniqueName);
    return error;
}

// ****************************************************************************
// Release all resources held by this FileBrowser.
static void CVIFUNC DiscardFileBrowser(FileBrowser* info)
{
    int i, BOLE, lockHandle = -1;
    
    if(info != NULL) 
        {
        if (!info->discarding)
            {
            if (info->lockHandle != -1)
                {
                lockHandle = info->lockHandle;
                CmtGetLock(lockHandle);
                }
            info->discarding = TRUE;
            free(info->rootPath);
            info->rootPath = NULL;
            if (info->fileFilter)
                {
                for(i=0; info->fileFilter[i] != NULL; i++)
                    {
                    free(info->fileFilter[i]);
                    info->fileFilter[i] = NULL;
                    }
                free(info->fileFilter);
                info->fileFilter = NULL;
                }
            UnchainCtrlCallback(info->panel, info->tree, info->chainKey);
            UnchainPanelCallback(info->panel, info->chainKey);
        #if defined (_NI_mswin32_) && _NI_mswin32_
            if(info->fileTypeIconsList != NULL){
                ListApplyToEach(info->fileTypeIconsList, 1, FileTypeDataDispose, NULL);
                ListDispose(info->fileTypeIconsList);
                info->fileTypeIconsList = NULL;
            }
        #endif
            /* turn off because some controls could have already been discarded
                if DiscardFileBrowser because the panel is being discarded */
            BOLE = SetBreakOnLibraryErrors(0);
            if (info->frame)
                {
                DiscardCtrl(info->panel, info->frame);
                info->frame = 0;
                }
            if (info->drag)
                {
                DiscardCtrl(info->panel, info->drag);
                info->drag = 0;
                }
            if (info->list)
                {
                DiscardCtrl(info->panel, info->list);
                info->list = 0;
                }
            if (info->timerKey)
                {
                DiscardCtrl(info->panel, info->timerKey);
                info->timerKey = 0;
                }
            SetBreakOnLibraryErrors(BOLE);
            free(info->chainKey);
            info->chainKey = NULL;

            info->lockHandle = -1;
            if(lockHandle != -1)
                {
                CmtReleaseLock(lockHandle);
                CmtDiscardLock(lockHandle);
                }

            free(info);
            }
        }
}


// ****************************************************************************
static void CVICALLBACK SortFileBrowser (void *callbackData)
{
    CallbackData *data = callbackData;

    SetWaitCursor (1);
    SortTreeItems(data->panel, data->ctrl, data->index, data->keyCol, FALSE, FALSE,
                            TreeSortCallback, NULL);
    SetWaitCursor (0);
    free(data);
}

// ****************************************************************************
static int CVICALLBACK TimerKeyCb(int panel, int control, int event, void *cbData,
                                      int eventData1, int eventData2)
{
    FileBrowser     *info = (FileBrowser *)cbData;
    int             index;

    if (info && event == EVENT_TIMER_TICK)
        {
        GetCtrlIndex(info->panel, info->tree, &index);
        PopulateListFromFolderIndex(info, index);
        SetCtrlAttribute(info->panel, info->timerKey, ATTR_ENABLED, FALSE);
        }
    return 0;
}

// ****************************************************************************
// does not take the frame into account
static int CVIFUNC GetBrowserRect(FileBrowser *info, int *top, int *left, int *bottom, int *right)
{
    int     tTop, tLeft, height, width;
    GetCtrlBoundingRect(info->panel, info->frame, &tTop, &tLeft, &height, &width);
    if (top)
        *top = tTop + info->frameThickness;
    if (left)
        *left = tLeft + info->frameThickness;
    if (bottom)
        *bottom = tTop + height - info->frameThickness;
    if (right)
        *right = tLeft + width - info->frameThickness;
    return 0;
}

// ****************************************************************************
static int CVICALLBACK  DragBarCb(int panel, int control, int event, void *cbData,
                                    int eventData1, int eventData2)
{
    int             error = 0;
    FileBrowser     *info = (FileBrowser *)cbData;
    int             treeLeft, treeWidth, listLeft, listWidth, x, y, dragLeft, labelLeft;
    int             newTreeWidth, newListWidth, newListLeft, dragHeight, dragTop;
    int             browserLeft, browserRight;
    Rect            dragR;

    switch (event)
        {
        case EVENT_LEFT_CLICK:
            errChk(GetCtrlAttribute(info->panel, info->tree, ATTR_LEFT,    &treeLeft));
            errChk(GetCtrlAttribute(info->panel, info->tree, ATTR_WIDTH,   &treeWidth));
            errChk(GetCtrlAttribute(info->panel, info->list, ATTR_LEFT,    &listLeft));
            errChk(GetCtrlAttribute(info->panel, info->list, ATTR_WIDTH,   &listWidth));
            errChk(GetCtrlAttribute(info->panel, info->drag, ATTR_LEFT,    &dragLeft));
            info->tracking.enabled    = TRUE;
            info->tracking.startX     = dragLeft;
            info->tracking.treeLeft   = treeLeft;
            info->tracking.treeWidth  = treeWidth;
            info->tracking.listWidth  = listWidth;
            break;
        case EVENT_MOUSE_MOVE:
            GetCtrlAttribute(info->panel, info->drag, ATTR_LEFT,   &dragLeft);
            GetCtrlAttribute(info->panel, info->drag, ATTR_TOP,    &dragTop);
            GetCtrlAttribute(info->panel, info->drag, ATTR_HEIGHT, &dragHeight);
            dragR = MakeRect(dragTop, dragLeft, dragHeight, DRAG_WIDTH);
            y = eventData1;
            x = eventData2;
            // set the cursor
            if (info->tracking.enabled || RectContainsPoint(dragR, MakePoint(x, y)))
                {

                errChk(SetMouseCursor(VAL_SIZE_EW_CURSOR));
                info->tracking.cursor = TRUE;
                } 
            else if (!info->tracking.enabled && info->tracking.cursor)
                {
                errChk(SetMouseCursor(VAL_DEFAULT_CURSOR));
                info->tracking.cursor = FALSE;
                }
                
            if (info->tracking.enabled)
                {
                x = eventData2;
                GetBrowserRect(info, NULL, &browserLeft, NULL, &browserRight);
                if (x < browserLeft)
                    x = browserLeft;
                else if (x > browserRight - DRAG_WIDTH)
                    x = browserRight - DRAG_WIDTH;
                errChk(SetCtrlAttribute(info->panel, info->drag, ATTR_LEFT, x));
                }
            break;
        case EVENT_LEFT_MOUSE_UP:
            if (info->tracking.enabled)
                {
                info->tracking.enabled = FALSE;
                GetBrowserRect(info, NULL, &browserLeft, NULL, &browserRight);
                GetCtrlAttribute(info->panel, info->drag, ATTR_LEFT, &dragLeft);
                if (dragLeft <= browserLeft + MIN_TREE_WIDTH)
                    {
                    errChk(SetCtrlAttribute(info->panel, info->tree, ATTR_VISIBLE, FALSE));
                    info->tracking.treeInvisible = TRUE;
                    newTreeWidth = MIN_TREE_WIDTH;
                    newListLeft  = info->tracking.treeLeft + DRAG_WIDTH;
                    newListWidth = browserRight - browserLeft - DRAG_WIDTH;
                    dragLeft     = browserLeft;
                    }
                else if (info->tracking.treeInvisible)
                    {
                    errChk(SetCtrlAttribute(info->panel, info->tree, ATTR_VISIBLE, TRUE));
                    info->tracking.treeInvisible = FALSE;
                    }

                if (dragLeft + DRAG_WIDTH >= browserRight - MIN_TREE_WIDTH)
                    {
                    errChk(SetCtrlAttribute(info->panel, info->list, ATTR_VISIBLE, FALSE));
                    info->tracking.listInvisible = TRUE;
                    newListWidth = MIN_TREE_WIDTH;
                    newListLeft  = browserRight - DRAG_WIDTH;
                    newTreeWidth = browserRight - browserLeft - DRAG_WIDTH;
                    dragLeft     = browserRight - DRAG_WIDTH;
                    }
                else if (info->tracking.listInvisible)
                    {
                    errChk(SetCtrlAttribute(info->panel, info->list, ATTR_VISIBLE, TRUE));
                    info->tracking.listInvisible = FALSE;
                    }

                if (!info->tracking.treeInvisible && !info->tracking.listInvisible)
                    {
                    newTreeWidth = dragLeft - browserLeft;
                    newListLeft  = dragLeft + DRAG_WIDTH;
                    newListWidth = browserRight - newListLeft;
                    }

                treeLeft = info->tracking.treeLeft;
                errChk(SetCtrlAttribute(info->panel, info->tree, ATTR_WIDTH,      newTreeWidth));
                errChk(SetCtrlAttribute(info->panel, info->list, ATTR_LEFT,       newListLeft));
                errChk(SetCtrlAttribute(info->panel, info->list, ATTR_WIDTH,      newListWidth));
                errChk(GetCtrlAttribute(info->panel, info->tree, ATTR_LABEL_LEFT, &labelLeft));
                errChk(SetCtrlAttribute(info->panel, info->list, ATTR_LABEL_LEFT, labelLeft));
                errChk(SetCtrlAttribute(info->panel, info->drag, ATTR_LEFT,       dragLeft));
                }
            break;
        }
Error:
    return 0;
}

// ****************************************************************************
static int CVIFUNC KeyWillChangeSelection(int panel, int control, int keyCode)
{
    int index, collapsed;

    if (keyCode == VAL_UP_ARROW_VKEY ||
        keyCode == VAL_DOWN_ARROW_VKEY)
        return TRUE;

    if (keyCode == VAL_LEFT_ARROW_VKEY ||
        keyCode == VAL_RIGHT_ARROW_VKEY)
        {
        GetCtrlIndex(panel, control, &index);
        GetTreeItemAttribute(panel, control, index, ATTR_COLLAPSED, &collapsed);
        if (keyCode == VAL_LEFT_ARROW_VKEY && collapsed)
            return TRUE;
        if (keyCode == VAL_RIGHT_ARROW_VKEY && !collapsed)
            return TRUE;
        }

    if (keyCode & VAL_VKEY_MASK)
        return FALSE;
    if (keyCode & VAL_MODIFIER_KEY_MASK)
        return FALSE;

    return TRUE;
}

// ****************************************************************************
static int CVICALLBACK FileBrowserPanelCb(int panel, int event, void *callbackData,
                        int eventData1, int eventData2)
{
    FileBrowser     *info = (FileBrowser *)callbackData;

    if (info)
        switch (event)
            {
            case EVENT_CLOSE:
                DiscardFileBrowser(info);
                break;
            }

    return 0;
}

// ****************************************************************************
// Callback function for all tree events
static int CVICALLBACK FileBrowserCb(int panel, int control, int event, void *cbData,
                                      int eventData1, int eventData2)
{
    int             error = 0, retVal = 0;
    CallbackData    *data;
    int             descending, sortSubtrees, keyCol, index, area;
    Point           pt;
    FileBrowser     *info = (FileBrowser *)cbData;
    int             zPlaneTree, zPlaneList, timerKeyEnabled;

    switch (event) {
        case EVENT_VAL_CHANGED:
            if (eventData1 == ACTIVE_ITEM_CHANGE && control == info->tree)
                {
#if defined (_NI_mswin32_) && _NI_mswin32_
                UpdateTreeImages(info, eventData2);
#endif
                GetCtrlAttribute(info->panel, info->timerKey, ATTR_ENABLED, &timerKeyEnabled);
                if (!timerKeyEnabled)
                    {
                    GetCtrlIndex(info->panel, info->tree, &index);
                    PopulateListFromFolderIndex(info, index);
                    }
                }
            break;
        case EVENT_KEYPRESS:
            if (control == info->tree)
                {
                if (KeyWillChangeSelection(panel, control, eventData1))
                    {
                    ResetTimer(info->panel, info->timerKey);
                    errChk(SetCtrlAttribute(info->panel, info->timerKey, ATTR_ENABLED, 1));
                    }
                else if (eventData1 == VAL_F5_VKEY)
                    {
                    GetCtrlIndex(panel, control, &index);
                    errChk(Refresh(info, index));
                    }
                }
            break;
        case EVENT_EXPAND:
            if(eventData1) // if this is an "expand all" or "expand subtree"
                {
                SetWaitCursor(1);
                PopulateTreeOnExpandAll(panel, control, eventData2);
                SetWaitCursor(0);
                }
            else {
                nullChk(data = malloc(sizeof(CallbackData)));  // note: this must be free'd by the receiver!
                data->panel = panel;
                data->ctrl = control;
                data->index = eventData2;
                // This is delayed instead of immediate so that a draw event can take place before the work
                // gets done, so that the expanding of the tree will be drawn immediately.
                nullChk(PostDelayedCall((DelayedCallbackFunc)PopulateFoldersOnExpandWrapper, data, DEFERRED_CALL_DELAY));
                }
            break;
        case EVENT_SORT:
            descending = LOWORD(eventData1);
            sortSubtrees = HIWORD(eventData1);
            keyCol = eventData2;
            GetCtrlIndex(panel, control, &index);
            errChk(SortTreeItems(panel, control, index, keyCol, descending, sortSubtrees,
                                    TreeSortCallback, NULL));
            retVal = 1;
            break;
        case EVENT_LEFT_CLICK:
            pt.y = eventData1;
            pt.x = eventData2;
            GetIndexFromPoint(panel, control, pt, NULL, &area, &keyCol);
            if (area == VAL_COLUMN_LABEL_AREA)
                {
                GetCtrlIndex (panel, control, &index);
                nullChk(data = malloc(sizeof(CallbackData)));  // note: this must be free'd by the receiver!
                data->panel = panel;
                data->ctrl = control;
                data->index = index;
                data->keyCol = keyCol;
                PostDeferredCall (SortFileBrowser, data);
                }
            break;
        case EVENT_GOT_FOCUS:
            if (control == info->tree)
                {
                GetCtrlAttribute(panel, info->tree, ATTR_ZPLANE_POSITION, &zPlaneTree);
                GetCtrlAttribute(panel, info->list, ATTR_ZPLANE_POSITION, &zPlaneList);
                if (zPlaneTree > zPlaneList)
                    {
                    errChk(SetCtrlAttribute(panel, info->tree, ATTR_ZPLANE_POSITION, zPlaneList));
                    errChk(SetCtrlAttribute(panel, info->list, ATTR_ZPLANE_POSITION, zPlaneTree));
                    }
                }
            else if (control == info->list)
                {
                GetCtrlAttribute(panel, info->tree, ATTR_ZPLANE_POSITION, &zPlaneTree);
                GetCtrlAttribute(panel, info->list, ATTR_ZPLANE_POSITION, &zPlaneList);
                if (zPlaneList > zPlaneTree)
                    {
                    errChk(SetCtrlAttribute(panel, info->list, ATTR_ZPLANE_POSITION, zPlaneTree));
                    errChk(SetCtrlAttribute(panel, info->tree, ATTR_ZPLANE_POSITION, zPlaneList));
                    }
                }
            break;
        case EVENT_DISCARD:
            DiscardFileBrowser(info);
            break;
        }
Error:
    if(error < 0)
        free(data);
    return retVal;
}

// ****************************************************************************
static void CVICALLBACK PopulateFoldersOnExpandWrapper(void *cbdata)
{
    int error = 0;
    char errorstr[100];
    CallbackData *data = cbdata;
    int panel = data->panel;
    int control = data->ctrl;
    int index = data->index;
    errChk(SetWaitCursor(1));
    free(data);
    errChk(PopulateFoldersOnExpand(panel, control, index));

Error:
    SetWaitCursor(0);
    if(error < 0) {
        sprintf(errorstr, "Returned error %d", error);
        MessagePopup("Tree Expand Error", errorstr);
    }
}

// ****************************************************************************
// Returns whether or not the node at index is a directory.  Sets result to
// TRUE or FALSE.
static int CVIFUNC IsDir(int panel, int control, int index, int* result)
{
    int error = 0;
    char tag[MAX_TREE_ITEM_TAG_LEN] = "";
    errChk(GetTreeItemTag(panel, control, index, tag));
    if(!CmbStrNCmp((unsigned char *)tag, (unsigned char *)DIR_STR, 3))
        *result = TRUE;
    else
        *result = FALSE;

Error:
    return error;
}

// ****************************************************************************
// Returns whether or not the file on disk is a directory.  Sets result to
// TRUE or FALSE.
static int CVIFUNC IsDirFromDisk(char* fileName, int* result)
{
    int error = 0;
    int breakOnLibraryErrorState;               // whether or not we were originally breaking on library errors
    int dontcare;
    int dir = 0;                                // non-zero if it's a directory, 0 if it's a file

    if(result == NULL)
        goto Error;

    // GetFileAttrs fails on some special Windows files such as pagefile.sys and returns an error
    // here.  We handle the error and problem, so we turn off error breaking for this function.
    breakOnLibraryErrorState = SetBreakOnLibraryErrors(FALSE);

    dir = GetFileAttrs(fileName, &dontcare, &dontcare, &dontcare, &dontcare);

    // Set it back to what it was before.
    SetBreakOnLibraryErrors(breakOnLibraryErrorState);

    // If we get a file not found, it is most likely a special Windows file.
    if(dir == -1)
        dir = 0;
    else
        errChk(dir);

    *result = dir ? TRUE : FALSE;
Error:
    return error;
}

#if 0 /* not needed */
// ****************************************************************************
// Returns whether or not the file on disk has the hidden attribute.  If we get
// a file not found error, we assume that the file is hidden.  Sets result to
// TRUE or FALSE.
static int CVIFUNC IsHidden(char* fileName, int* result)
{

    int error = 0;
    int breakOnLibraryErrorState;               // whether or not we were originally breaking on library errors
    int dontcare;
    int hidden = 0;                             // non-zero if it's a directory, 0 if it's a file

    if(result == NULL)
        goto Error;

    // GetFileAttrs fails on some special Windows files such as pagefile.sys and returns an error
    // here.  We handle the error and problem, so we turn off error breaking for this function.
    breakOnLibraryErrorState = SetBreakOnLibraryErrors(FALSE);

    error = GetFileAttrs(fileName, &dontcare, &dontcare, &hidden, &dontcare);

    // Set it back to what it was before.
    SetBreakOnLibraryErrors(breakOnLibraryErrorState);

    // If we get a file not found, it is most likely a special Windows file
    if(error == -1) {
        error = 0;
        hidden = 1;
    }
    else
        errChk(error);

    *result = hidden ? TRUE : FALSE;
Error:
    return error;
}
#endif /* 0 */

// ****************************************************************************
// Populates all the branches one layer below node at index.
static int CVIFUNC PopulateFoldersOnExpand(int panel, int control, int index)
{
    int error = 0;
    int childIndex = -1;            // index of the current child

    // Set it up for the first iteration.
    errChk(GetTreeItem(panel, control, VAL_CHILD, index, VAL_FIRST, VAL_NEXT_PLUS_SELF, 0, &childIndex));

    // Look at the proper number of children and populate each of them.
    while(childIndex >= 0) {
        errChk(PopulateFolder(panel, control, childIndex));
        errChk(GetTreeItem(panel, control, VAL_CHILD, index, childIndex, VAL_NEXT, 0, &childIndex));
    }
Error:
    return error;
}

#if defined (_NI_mswin32_) && _NI_mswin32_
// ****************************************************************************
// Updates the old active and the new active item's image
static int CVIFUNC UpdateTreeImages(FileBrowser *info, int oldIndex)
{
    int     error = 0;
    int     imageIndex, newIndex;
    char    fileName[MAX_PATHNAME_LEN];                 // the filename we are looking up

    GetCtrlIndex(info->panel, info->tree, &newIndex);
    errChk(GetValueFromIndex(info->panel, info->tree, newIndex, fileName));

    errChk(GetFileIcon(info, fileName, &imageIndex, SHGFI_OPENICON));
    if (imageIndex >= 0)
        {
        errChk(SetTreeItemAttribute(info->panel, info->tree, newIndex, ATTR_IMAGE_INDEX, imageIndex));
        errChk(SetTreeItemAttribute(info->panel, info->tree, newIndex, ATTR_COLLAPSED_IMAGE_INDEX, imageIndex));
        }

    if (oldIndex >= 0)
        {
        errChk(GetValueFromIndex(info->panel, info->tree, oldIndex, fileName));
        errChk(GetFileIcon(info, fileName, &imageIndex, 0));
        if (imageIndex >= 0)
            {
            errChk(SetTreeItemAttribute(info->panel, info->tree, oldIndex, ATTR_IMAGE_INDEX, imageIndex));
            errChk(SetTreeItemAttribute(info->panel, info->tree, oldIndex, ATTR_COLLAPSED_IMAGE_INDEX, imageIndex));
            }
        }
Error:
    return error;
}
#endif

// ****************************************************************************
// Populates the list with the files in the current folder
static int CVIFUNC PopulateListFromFolderIndex(FileBrowser *info, int index)
{
    int     error = 0;
    int     length = 0;                             // length of the path
    char    startPath[MAX_PATHNAME_LEN];            // path to where we're looking

    errChk(GetTreeItemPathLength(info->panel, info->tree, index, PATH_SEPARATOR, &length));
    assert(MAX_PATHNAME_LEN > length);
    errChk(GetTreeItemPath(info->panel, info->tree, index, PATH_SEPARATOR, startPath));
    errChk(PopulateListFromPath(info, startPath));

Error:
    return error;
}

// ****************************************************************************
// Populate a branch of the tree with the directories under it.
// index: the index of the node in the tree that we are populating
static int CVIFUNC PopulateFolder(int panel, int control,int index)
{
    int error = 0;
    int numChildren = -1;                       // number of already existing children
    int length = 0;                             // length of the path
    char startPath[MAX_PATHNAME_LEN];           // path to where we're looking
    int dir = 0;                                // TRUE if it's a directory, FALSE if it's a file

    errChk(GetTreeItemNumChildren(panel, control, index, &numChildren));

    errChk(IsDir(panel, control, index, &dir));

    // if it already has children, we don't want to repopulate it with same data again
    // and if it isn't a directory, we don't need to try
    if(numChildren <= 0 && dir)
        {
        // Get the path of the node.
        errChk(GetTreeItemPathLength(panel, control, index, PATH_SEPARATOR, &length));
        assert(MAX_PATHNAME_LEN > length);
        errChk(GetTreeItemPath(panel, control, index, PATH_SEPARATOR, startPath));

        errChk(PopulateFolderWithPath(panel, control, index, startPath));
    }

Error:
    return error;
}

#if defined (_NI_mswin32_) && _NI_mswin32_
// ****************************************************************************
// Populate the level under "My Computer", which is all available drive letters.
static int CVIFUNC PopulateRootLevel(FileBrowser *info, int control)
{
    int     error = 0;
    DWORD   drives = 0;                         // bitmask of available drive letters
    DWORD   mask;                                   // a mask to isolate the bit we're currently viewing
    char    driveString[3] = "a:";                  // string holding the current drive letter plus a colon
    char    drivePath[4];                           // full path of drive string
    UINT    driveType = 0;                          // what type of drive this is
    int     insert = FALSE;

    // We must make a win32 api call to find all available drive letters.
    drives = GetLogicalDrives();

    // Look at each bit to see which drive letters are available.
    for(driveString[0] = 'a', mask = 0x01; driveString[0] <= 'z'; driveString[0]++, mask <<= 1)
        {
        if(drives & mask)
            {
            // If we aren't browsing floppies, check to see what type of drive this is and only
            // do the insert if it is not a floppy drive.
            CmbStrCpy(drivePath, driveString);
            CmbStrCat(drivePath, PATH_SEPARATOR);
            driveType = GetDriveType(drivePath);
            switch(driveType)
                {
                case DRIVE_REMOVABLE:
                    if(info->browseFloppydrives)
                        insert = TRUE;
                    break;
                case DRIVE_FIXED:
                    if(info->browseHarddrives)
                        insert = TRUE;
                    break;
                case DRIVE_REMOTE:
                    if(info->browseNetworkdrives)
                        insert = TRUE;
                    break;
                case DRIVE_CDROM:
                    if(info->browseCDRomdrives)
                        insert = TRUE;
                    break;
                case DRIVE_RAMDISK:
                    if(info->browseRamdiskdrives)
                        insert = TRUE;
                    break;
                case DRIVE_UNKNOWN:
                    if(info->browseUnknowndrives)
                        insert = TRUE;
                    break;
                default:
                    errChk(UIEValueIsInvalidOrOutOfRange);
                }
            if (insert)
                {
                if (control == info->tree)
                    errChk(InsertIntoFolders(info, info->rootIndex, driveString, "", DIR_STR));
                else
                    errChk(InsertIntoList(info, driveString, "", DIR_STR));
                insert = FALSE;
                }
            }
        }

Error:
    return error;
}
#endif

// ****************************************************************************
// Populate the tree with all directories under index (no files).
static int CVIFUNC PopulateFolderWithPath(int panel, int control,int index, char* startPath)
{
    int             error = 0;
    FileBrowser*    info = NULL;                            // the current file browser data structure
    int             proceed = TRUE;                         // whether or not to keep looking at files
    char            fileName[MAX_FILENAME_LEN];             // the filename we get back from the library
    char            absFileName[MAX_PATHNAME_LEN];          // absolute file name we need for the GetFileAttrs function
    char            searchPath[MAX_PATHNAME_LEN];           // where to search for files
    char            tagBase[MAX_TAGBASE_STRLEN] = DIR_STR;  // tag base for each inserted item: will be either "FILE" or "DIR"
    int             prevBreakOnLibraryErrors;
    int             insertedDir = FALSE;

    prevBreakOnLibraryErrors = SetBreakOnLibraryErrors (0);
    errChk(GetFileBrowserPtr(panel, control, &info));

#if defined (_NI_mswin32_) && _NI_mswin32_
    if(CmbStrCmp((unsigned char *)startPath, (unsigned char *)ROOT_LEVEL_STRING) == 0)
        {
        errChk(PopulateRootLevel(info, info->tree));
        goto Error;
        }

    // If the root is "My Computer", strip that off the path so it is a real file path.
    if(CmbStrStr((unsigned char *)startPath, (unsigned char *)ROOT_LEVEL_STRING) != NULL)
        {
        startPath = (char *)CmbStrChr((unsigned char *)startPath, (unsigned int)PATH_SEPARATOR[0]);
        startPath++; // now go one past the backslash
        }
#elif defined (_NI_linux_) && _NI_linux_
    if(CmbStrCmp((unsigned char *)startPath, (unsigned char *)ROOT_LEVEL_STRING) != 0)
        if(CmbStrEqN((unsigned char *)startPath, (unsigned char *)ROOT_LEVEL_STRING PATH_SEPARATOR, strlen (ROOT_LEVEL_STRING PATH_SEPARATOR)))
            startPath++; // skip first of two leading '/'
#endif
    errChk(MakePathname(startPath, "*", searchPath));

    // Get the first file.  If there aren't any, that's ok.  There won't be any children for this node
    error = GetFirstFile(searchPath,0,1,1,1,1,1,fileName);
    if(error == -1 || error == -6) 
        { // if no matching files found, don't look for any more
        error = 0;
        proceed = FALSE;
        }

    // Keep adding files until there aren't anymore.
    while(proceed)
        {
        int ro,sys,hid,arc;

        errChk(MakePathname(startPath,fileName,absFileName));
        if (GetFileAttrs(absFileName,&ro,&sys,&hid,&arc)==1)
            {
            errChk(InsertIntoFolders(info, index, fileName, startPath, tagBase));
            insertedDir = TRUE;
            }
        error = GetNextFile(fileName);
        if(error == -1)
            { // if no matching files found, don't look for any more
            error = 0;
            proceed = FALSE;
            }
        else
            errChk(error);
        }
        
    if (insertedDir)
        SortTreeItems(panel, control, index+1, 0, FALSE, FALSE, TreeSortCallback, NULL);

Error:
    SetBreakOnLibraryErrors(prevBreakOnLibraryErrors);
    return error;
}


// ****************************************************************************
// Populate the tree with all files and directories in startPath
static int CVIFUNC PopulateListFromPath(FileBrowser *info, char *path)
{
    int         error = 0;
    int         proceed = TRUE;                 // whether or not to keep looking at files
    char        fileName[MAX_FILENAME_LEN];     // the filename we get back from the library
    char        searchPath[MAX_PATHNAME_LEN];   // where to search for files
    char        absFileName[MAX_PATHNAME_LEN];  // absolute path of the file
    char        *tagBase;                       // tag base for each inserted item: will be either "FILE" or "DIR"
    int         dir = 0;                        // whether or not it is a directory
    int         insertedFile = FALSE, insert;

    ClearListCtrl(info->panel, info->list);
    errChk(ProcessDrawEvents());

    SetWaitCursor(1);

#if defined (_NI_mswin32_) && _NI_mswin32_
    // If we are trying to populate directly under the root, we don't want to do anything here
    // because it will just be drive letters, which are treated specially.
    if (CmbStrCmp((unsigned char *)path, (unsigned char *)ROOT_LEVEL_STRING) == 0)
        {
        PopulateRootLevel(info, info->list);
        goto Error;
        }

    // If the root is "My Computer", strip that off the path so it is a real file path.
    if (CmbStrStr((unsigned char *)path, (unsigned char *)ROOT_LEVEL_STRING) != NULL) {
        path = (char *)CmbStrChr((unsigned char *)path, (unsigned int)PATH_SEPARATOR[0]);
        path++; // now go one past the backslash
    }

#elif defined (_NI_linux_) && _NI_linux_
    if(CmbStrCmp((unsigned char *)path, (unsigned char *)ROOT_LEVEL_STRING) != 0)
        if(CmbStrEqN((unsigned char *)path, (unsigned char *)ROOT_LEVEL_STRING PATH_SEPARATOR, strlen (ROOT_LEVEL_STRING PATH_SEPARATOR)))
            path++; // skip first of two leading '/'
#endif
    errChk(MakePathname(path, "*", searchPath));

    // Get the first file.  If there aren't any, that's ok.  There won't be any children for this node.
    error = GetFirstFile (searchPath, 1, 1, 1, 1, 1, 1, fileName);
    if (error == -1) { // if no matching files found, don't look for any more
        error = 0;
        proceed = FALSE;
    }

    // Keep adding files until there aren't anymore.
    while (proceed)
        {
        insert = FALSE;
        errChk(MakePathname(path, fileName, absFileName));
        errChk(IsDirFromDisk(absFileName, &dir));
        if (dir)
            insert = TRUE;
        if (!insert && !info->directoriesOnly && IsFileValid(fileName, info->fileFilter))
            insert = TRUE;

        if (insert)
            {// only add the file if it should be there
            if (dir)
                tagBase = DIR_STR;
            else
                tagBase = FILE_STR;

            errChk(InsertIntoList(info, fileName, path, tagBase));
            insertedFile = TRUE;
            }
        error = GetNextFile(fileName);
        if (error == -1)
            { // if no matching files found, don't look for any more
            error = 0;
            proceed = FALSE;
            }
        }

    if (insertedFile)
        {
        SortTreeItems(info->panel, info->list, 0, 0, FALSE, FALSE,
                                TreeSortCallback, NULL);
        SetCtrlIndex(info->panel, info->list, 0);
        }
Error:
    SetWaitCursor(0);
    return error;
}

// ****************************************************************************
// Inserts an entry into the list.
// Parameters:  fileName    - name of the item to appear on the label
//              startPath   - directory in which filename is located
//              tagBase     - either "DIR" for directories of "FILE" for files
//
// Returns either the index of the file inserted or an error.
static int CVIFUNC InsertIntoList(FileBrowser *info, char* fileName,
                                      char* startPath, char* tagBase)
{
    int     error = 0;
    char    absoluteFileName[MAX_PATHNAME_LEN]; // full path of the filename
    int     newItemIndex = -1;                      // index of newly created node

    // Get the full path of the filename to insert as the items value.
    // If startPath is empty, that means it is a drive letter, so just skip the startPath.
    if(startPath[0] == '\0')
        CmbStrCpy(absoluteFileName, fileName);
    else
        errChk(MakePathname(startPath, fileName, absoluteFileName));

    errChk(newItemIndex = InsertTreeItem(info->panel, info->list, VAL_SIBLING, 0, VAL_LAST, fileName,
                            tagBase, NULL, absoluteFileName));

#if defined (_NI_mswin32_) && _NI_mswin32_
    errChk(AssignIconToTreeItem(info, info->list, newItemIndex));
#endif
    errChk(PopulateTreeColumnsForItem(info, newItemIndex));
    error = newItemIndex;

Error:
    return error;
}

// ****************************************************************************
// Inserts a dir into the folder tree.
// Parameters:  index       - parent of the new item
//              fileName    - name of the item to appear on the label
//              startPath   - directory in which filename is located
//              tagBase     - either "DIR" for directories of "FILE" for files
//
// Returns either the index of the file inserted or an error.
static int CVIFUNC InsertIntoFolders(FileBrowser *info, int index, char* fileName,
                                      char* startPath, char* tagBase)
{
    int     error = 0;
    char    absoluteFileName[MAX_PATHNAME_LEN]; // full path of the filename
    int     newItemIndex = -1;                      // index of newly created node

    // Get the full path of the filename to insert as the items value.
    // If startPath is empty, that means it is a drive letter, so just skip the startPath.
    if(startPath[0] == '\0')
        CmbStrCpy(absoluteFileName, fileName);
    else
        errChk(MakePathname(startPath, fileName, absoluteFileName));

    // now add the item
    errChk(newItemIndex = InsertTreeItem(info->panel, info->tree, VAL_CHILD, index, VAL_LAST,
                                         fileName, tagBase, NULL, absoluteFileName));
#if defined (_NI_mswin32_) && _NI_mswin32_
    errChk(AssignIconToTreeItem(info, info->tree, newItemIndex));
#endif
    error = newItemIndex;

Error:
    return error;
}

// ****************************************************************************
// Checks to see whether fileName fits within filters.  If it has one of the extensions
// in filters, it returns TRUE.  Otherwise, it returns FALSE.
static int CVIFUNC IsFileValid(char* fileName, char** filters)
{
    int i;
    char* lastPeriod = NULL;

    assert(filters != NULL);  // so we don't try to dereference NULL

    // Sometimes Windows finds invalid filenames and returns them
    // as a single question mark.  Since question marks are not valid
    // characters in a filename, we will filter them all out
    if(CmbStrChr((unsigned char *)fileName, (unsigned int)'?') != NULL)
        return FALSE;

    if(CmbStrCmp((unsigned char *)filters[0], (unsigned char *)".*") == 0) // allow all files for .*
        return TRUE;

    // Find the last period, which begins the extension.
    lastPeriod = (char *)CmbStrRChr((unsigned char *)fileName, (unsigned int)'.');
    if(lastPeriod == NULL)
        return FALSE;

    // Look in each extension to see if it matches the file.
    for(i=0; filters[i] != NULL && i < MAX_FILTER_EXTENSIONS; i++) {
        // Do lowercase comparison so that it is not case sensitive.
        if(CmbStrICmp((unsigned char *)filters[i], (unsigned char *)lastPeriod) == 0)
            return TRUE;
    }
    return FALSE;
}

// ****************************************************************************
// Returns a pointer to the FileBrowser data structure.
static int CVIFUNC GetFileBrowserPtr(int panel, int control, FileBrowser** ptr)
{
    int     error = 0;
    char    *chainKey = NULL;

    errChk(GetUniqueChainKey(CHAIN_KEY, panel, control, &chainKey));
    errChk(GetChainedCallbackData (panel, control, chainKey, (void**)ptr));

Error:
    free(chainKey);
    return error;
}

// ****************************************************************************
// Clears the tree and initializes it from the start path.
static int CVIFUNC SetTreeStartPath(FileBrowser* info, char* path)
{
    int error = 0;
    int size = 0;
    short locked = FALSE;
    char str[MAX_PATHNAME_LEN] = "";

    errChk(ClearListCtrl(info->panel, info->tree)); // if there's something in the tree, we clear it
    errChk(ClearListCtrl(info->panel, info->list)); // if there's something in the list, we clear it

    errChk(CmtGetLock(info->lockHandle));
    locked = TRUE;
    if (path != info->rootPath)
        {
#if defined (_NI_linux_) && _NI_linux_
        if((CmbStrCmp((unsigned char *)path, (unsigned char *)ROOT_LEVEL_STRING) != 0)
            && CmbStrEqN((unsigned char *)path, (unsigned char *)ROOT_LEVEL_STRING PATH_SEPARATOR, strlen (ROOT_LEVEL_STRING PATH_SEPARATOR)))
            path++; // skip first of two leading '/'
#endif
        free(info->rootPath);
        size = strlen(path);
        nullChk(info->rootPath = calloc(size+1, sizeof (char)));
        CmbStrCpy(info->rootPath, path);
        }
    if(CmbStrCmp((unsigned char *)info->rootPath, (unsigned char *)ROOT_LEVEL_STRING))
        CmbStrCpy(str, info->rootPath);

    // Now we make the root node, then populate one level under it.
    errChk(info->rootIndex = InsertTreeItem(info->panel, info->tree, VAL_SIBLING, 0, VAL_FIRST, info->rootPath, DIR_STR, NULL, str));

    errChk(CmtReleaseLock(info->lockHandle));
    locked = FALSE;

#if defined (_NI_mswin32_) && _NI_mswin32_
    errChk(AssignIconToTreeItem(info, info->tree, info->rootIndex));
#endif
    errChk(PopulateFolder(info->panel, info->tree, info->rootIndex));
    errChk(PopulateListFromFolderIndex(info, info->rootIndex));

Error:
    if(error < 0) {
        if(locked)
            CmtReleaseLock(info->lockHandle);
    }
    return error;
}

// ****************************************************************************
// This function operates recursively over the entire file system under the node
// index.  If index is the tree root on the first call, this does an expand all.
// If it is a lower node, it does an expand subtree
static int CVIFUNC PopulateTreeOnExpandAll(int panel, int control, int index)
{
    int error = 0;
    int childIndex = -1;            // index of the current child

    errChk(GetTreeItem(panel, control, VAL_CHILD, index, VAL_FIRST, VAL_NEXT_PLUS_SELF, 0, &childIndex));

    while(childIndex >= 0) {
        errChk(PopulateFolder(panel, control, childIndex));
        errChk(PopulateTreeOnExpandAll(panel, control, childIndex));
        errChk(GetTreeItem(panel, control, VAL_CHILD, index, childIndex, VAL_NEXT, 0, &childIndex));
    }

Error:
    return error;
}

// ****************************************************************************
// Sets the current fileFilter to filter and applies the filter to the entire
// tree that exists currently.  Subsequent populatings of the tree will
// automatically have the filter applied to them.
static int CVIFUNC SetTreeFileFilter(FileBrowser* info, char* filter)
{
    int error = 0;
    int i;
    int size = 0, index;
    short locked = FALSE;
    char* extensions[MAX_FILTER_EXTENSIONS];        // temp storage of each individual extension
    int extensionsUsed;                             // number of extensions being used
    char myFilter[MAX_FILTER_BUFFER_LENGTH];        // copy of filter
    char* myFilterPtr = myFilter;                   // so we can move the beginnging of the string
    char* loc = NULL;                               // current location in myFilter
    char oldExtensions[MAX_FILTER_BUFFER_LENGTH];   // a buffer holding the old set of filters
    char newExtensions[MAX_FILTER_BUFFER_LENGTH];   // a buffer holding the new set of filters

    errChk(MakeFilterString(info, oldExtensions));

    // First we need to parse the filter into proper format.

    // Get a copy we can modify and ensure it is null terminated.
    StringCopyMax(myFilter, filter, MAX_FILTER_BUFFER_LENGTH);

    // Make sure there isn't any white space that will interfere with the parsing.
    myFilterPtr = SkipWhiteSpace(myFilterPtr);

    // Check if there is a ".*" anywhere, and if there is, ignore all of the rest.
    // Or check if we were passed an empty string.  If so, treat it like ".*"
    loc = (char *)CmbStrStr((unsigned char *)myFilter, (unsigned char *)".*");
    if(loc != NULL || CmbStrCmp((unsigned char *)myFilterPtr, (unsigned char *)"") == 0) {
        nullChk(extensions[0] = calloc(strlen(".*")+1, sizeof(char)));
        CmbStrCpy(extensions[0], ".*");
        extensionsUsed = 1;
    }
    else {
        loc = myFilter; // So that the condition on the for loop won't fail immediately unless it should,
                        // and we won't try to dereference a null pointer.

        for(extensionsUsed=0; *loc != '\0' && extensionsUsed < MAX_FILTER_EXTENSIONS; extensionsUsed++) {
            myFilterPtr = SkipWhiteSpace(myFilterPtr);              // remove any leading white space
            loc = (char *)CmbStrChr((unsigned char *)myFilterPtr, (unsigned int)';');   // find the first semicolon (the delimiting character)
            if(loc == NULL) // if there is no ';', find a NULL instead
                loc = (char *)CmbStrChr((unsigned char *)myFilterPtr, (unsigned int)'\0'); // we are guaranteed to find a NULL because StringCopyMax put one there
            size = loc - myFilterPtr;           // compute the length of the string including  the semicolon
            if(size < 1) // then we are done
                break;
            if(myFilterPtr[0] != '.') // filter MUST start with a period
                errChk(UIEValueIsInvalidOrOutOfRange);
            nullChk(extensions[extensionsUsed] = calloc(size+1, sizeof(char)));

            // Copy it into the storage, truncating the ';' because StringCopyMax will put a \0 within
            // the specified size.
            StringCopyMax(extensions[extensionsUsed], myFilterPtr, size+1);

            // Now, set up for the next one.
            myFilterPtr = loc + 1;
        }
    }

    // Now we copy the strings into permanent storage
    // and delete what is currently there now.
    errChk(CmtGetLock(info->lockHandle));
    locked = TRUE;
    for(i=0; info->fileFilter[i] != NULL; i++)
        free(info->fileFilter[i]);
    free(info->fileFilter);

    // Allocate space, including enough for null termination.
    nullChk(info->fileFilter = calloc(extensionsUsed+1, sizeof(char*)));

    // Copy them into the new array.
    for(i=0; i < extensionsUsed; i++)
        info->fileFilter[i] = extensions[i];

    errChk(CmtReleaseLock(info->lockHandle));
    locked = FALSE;

    errChk(MakeFilterString(info, newExtensions));

    if(CmbStrCmp((unsigned char *)oldExtensions, (unsigned char *)newExtensions))
        {
        GetCtrlIndex(info->panel, info->tree, &index);
        errChk(PopulateListFromFolderIndex(info, index)); // Go through the entire tree and apply the new filter.
        }

Error:
    if(locked)
        CmtReleaseLock(info->lockHandle);
    return error;
}

// ****************************************************************************
// Combines all the buffer path elements into a string that buffer points to.
static int CVIFUNC MakeFilterString(FileBrowser* info, char* buffer)
{
    int i;

    // Make sure we don't dereference null pointers.
    assert(info->fileFilter != NULL);
    assert(info->fileFilter[0] != NULL);

    // Copy in the first element.
    CmbStrCpy(buffer, info->fileFilter[0]);

    // Copy each additional element.
    for(i=1; i < MAX_FILTER_EXTENSIONS && info->fileFilter[i] != NULL; i++) {
        CmbStrCat(buffer, "; ");
        CmbStrCat(buffer, info->fileFilter[i]);
    }
    return 0;
}

// ****************************************************************************
// Sets the variable to keep track of the change and applies the change to the current tree.
static int CVIFUNC SetDirectoriesOnlyState(FileBrowser* info, int num)
{
    int     error = 0;
    short   locked = FALSE;                     // whether or not we're locked right now
    int     index;

    // If they're equal, no state change, so don't do anything.
    if((info->directoriesOnly && num) || (!info->directoriesOnly && !num))
        goto Error;

    errChk(CmtGetLock(info->lockHandle));
    locked = TRUE;

    info->directoriesOnly = (num != 0) ? TRUE : FALSE;

    errChk(CmtReleaseLock(info->lockHandle));
    locked = FALSE;

    GetCtrlIndex(info->panel, info->tree, &index);
    errChk(PopulateListFromFolderIndex(info, index));

Error:
    return error;
}

#if defined (_NI_mswin32_) && _NI_mswin32_
// ****************************************************************************
// Changes whether a particular type of drive is currently browsable.
// Variables:
// type: must point to an int in the FileBrowser structure for this tree
// flag: must be one of the following, as documented in MSDN help for GetDriveType():
//          DRIVE_UNKNOWN
//          DRIVE_NO_ROOT_DIR
//          DRIVE_REMOVABLE
//          DRIVE_FIXED
//          DRIVE_REMOTE
//          DRIVE_CDROM
//          DRIVE_RAMDISK
static int CVIFUNC SetBrowseDriveTypeState(int panel, int control, int* type, UINT flag, int num)
{
    int error = 0;
    FileBrowser* info = NULL;
    short locked = FALSE;                       // whether or not we're locked right now

    // If they're equal, no state change, so don't do anything.
    if((*type && num) || (!*type && !num))
        goto Error;

    errChk(GetFileBrowserPtr(panel, control, &info));

    errChk(CmtGetLock(info->lockHandle));
    locked = TRUE;

    *type = (num != 0) ? TRUE : FALSE;

    errChk(CmtReleaseLock(info->lockHandle));
    locked = FALSE;

    // If we're not browsing at the root level, no changes need to be made.
    if(CmbStrCmp((unsigned char *)info->rootPath, (unsigned char *)ROOT_LEVEL_STRING))
        goto Error;

    // If we are now browsing a type, find which ones need to be added.
    if(*type ==  TRUE)
        errChk(AddDriveTypeToTree(info, flag));

    // If we are now not browsing a type, find out if we need to remove anything.
    else
        errChk(RemoveDriveType(info, flag));
Error:
    return error;
}

// ****************************************************************************
// Adds all drive letters of type into the tree.
// See comment above SetBrowseDriveTypeStatus() for values of type
static int CVIFUNC AddDriveTypeToTree(FileBrowser* info, UINT type)
{
    int error = 0;
    UINT driveType = 0;                         // what type of drive this is
    DWORD drives = 0;                           // bitmask of available drive letters
    DWORD mask;                                 // a mask to isolate the bit we're currently viewing
    char driveString[3] = "a:";                 // string holding the current drive letter plus a colon
    char drivePath[4];                          // full path of drive string
    int index, numListItems;

    // We must make a win32 api call to find all available drive letters.
    drives = GetLogicalDrives();

    // Now we look at each bit to see which drive letters are available.
    for(driveString[0] = 'a', mask = 0x01; driveString[0] <= 'z'; driveString[0]++, mask <<= 1) {
        if(drives & mask) {
            CmbStrCpy(drivePath, driveString);
            CmbStrCat(drivePath, PATH_SEPARATOR);
            driveType = GetDriveType(drivePath);
            // Add any drive that is the correct type
            if(driveType == type)
                {
                errChk(index = InsertIntoFolders(info, info->rootIndex, driveString, "", DIR_STR));
                errChk(PopulateFolder(info->panel, info->tree, index));

                GetCtrlIndex(info->panel, info->tree, &index);
                if (0 == index) { // on "My Computer"
                    errChk(InsertIntoList(info, driveString, "", DIR_STR));
                }
            }
        }
    }
    GetNumListItems(info->panel, info->list, &numListItems);
    if (numListItems)
        {
        errChk(SortTreeItems(info->panel, info->list, 0, 0, FALSE, FALSE, TreeSortCallback, NULL));
        }
    errChk(SortTreeItems(info->panel, info->tree, 1, 0, FALSE, FALSE, TreeSortCallback, NULL));

Error:
    return error;
}


// ****************************************************************************
// Removes all drive letters of type from the browser.
// See comment above SetBrowseDriveTypeStatus() for values of type.
static int CVIFUNC RemoveDriveType(FileBrowser* info, UINT type)
{
    int error = 0;
    int index = -1;                             // index of the current item
    int nextIndex = -1;                         // index of the next item
    int listIndex, numListItems;
    char tag[MAX_TREE_ITEM_TAG_LEN] = "";       // tag of the next item
    char label[MAX_FILENAME_LEN];               // label of the current item
    UINT driveType = 0;                         // what type of drive this is

    errChk(GetTreeItem(info->panel, info->tree, VAL_CHILD, info->rootIndex, VAL_FIRST, VAL_NEXT_PLUS_SELF, 0, &index));
    while(index >= 0) {
        // Get the next one and a handle for it.
        errChk(GetTreeItem(info->panel, info->tree, VAL_CHILD, info->rootIndex, index, VAL_NEXT, 0, &nextIndex));
        if(nextIndex >= 0)
            errChk(GetTreeItemTag(info->panel, info->tree, nextIndex, tag));
        else
            tag[0] = '\0';

        // Check on this one in tree
        errChk(GetLabelFromIndex(info->panel, info->tree, index, label));
        GetNumListItems(info->panel, info->list, &numListItems);
        if (numListItems)
            GetTreeItemFromLabel(info->panel, info->list, VAL_ALL, 0, VAL_FIRST,
                                        VAL_NEXT_PLUS_SELF, 0, label, &listIndex);
        else
            listIndex = -1;
        CmbStrCat(label, PATH_SEPARATOR);
        driveType = GetDriveType(label);
        if(driveType == type)
            {
            errChk(DeleteListItem(info->panel, info->tree, index, 1));
            if (listIndex >= 0)
                errChk(DeleteListItem(info->panel, info->list, listIndex, 1));
            }

        // Iterate again.
        errChk(GetTreeItemFromTag(info->panel, info->tree, tag, &index));
    }

    GetCtrlIndex(info->panel, info->tree, &index);
    PopulateListFromFolderIndex(info, index);
Error:
    return error;
}
#endif
// ****************************************************************************
// Set whether a column is visible or not.
static int CVIFUNC SetTreeColumnState(FileBrowser* info, int* column, int state, char* columnName)
{
    int error = 0;

    if((state == FALSE && *column == COLUMN_DOESNT_EXIST) || (state == TRUE && *column != COLUMN_DOESNT_EXIST))
        goto Error;

    if(state == FALSE) {
        // These column numbers will change if an earlier column is removed, so we must correct them.
        if(*column < info->columnIndexSize)
            info->columnIndexSize--;
        if(*column < info->columnIndexTime)
            info->columnIndexTime--;
        if(*column < info->columnIndexType)
            info->columnIndexType--;
        errChk(DeleteTreeColumn(info->panel, info->list, *column));
        *column = COLUMN_DOESNT_EXIST;
    }
    else // state == TRUE
        errChk(*column = InsertTreeColumn(info->panel, info->list, -1, columnName));

    errChk(ResetTreeColumnValues(info));

Error:
    return error;
}

// ****************************************************************************
// Fills in all of the columns for item index
static int CVIFUNC PopulateTreeColumnsForItem(FileBrowser* info, int index)
{
    int error = 0;
    char label[MAX_FILENAME_LEN] = "";

    errChk(GetLabelFromIndex(info->panel, info->list, index, label));

    // If this is a drive letter or this is "my computer", we don't want to continue.
    // Drive letters are the only items that will have a colon in their label.
    if(CmbStrChr((unsigned char *)label, (unsigned int)':') != NULL)
        goto Error;

    errChk(PopulateTreeColumnSize(info, index));
    errChk(PopulateTreeColumnTime(info, index));
    errChk(PopulateTreeColumnType(info, index));

Error:
    return error;
}

// ****************************************************************************
// Fill in the value for the size column, if it exists, for the item.
static int CVIFUNC PopulateTreeColumnSize(FileBrowser* info, int index)
{
    int     error = 0;
    char    val[MAX_PATHNAME_LEN] = "";             // the value of the item
    char    sizeString[100] = "";                       // the string containing the size and units
    int     isDir;

    if(info->columnIndexSize == COLUMN_DOESNT_EXIST)
        goto Error;

    errChk(GetValueFromIndex(info->panel, info->list, index, val));

    // If this isn't a directory or "my computer", fill in the size.
    // Otherwise, just leave it as an empty string.
    errChk(IsDir(info->panel, info->list, index, &isDir));
    if(!isDir) {
        long size = -1;                             // file size
        char units[5];                              // the units of the size

        errChk(GetFileSize (val, &size));

        // Convert the size to the appropriate units.
        // Use a unit only if the file has at least 10 of them, so that we'll still have reasonable precision.
        // The 0.5 added to each one in the adjustment is so that it will be rounded up or down correctly.
        if(size > 1e10) { // gigabytes == 1073741824 bytes
            size = ((double)size / 1073741824) + 0.5;
            CmbStrCpy(units, GIGABYTE_STR);
        }
        else if(size > 1e7) { // megabytes == 1048576 bytes
            size = ((double)size / 1048576) + 0.5;
            CmbStrCpy(units, MEGABYTE_STR);
        }
        else if(size > 1e4) { // kilobytes == 1024 bytes
            size = ((double)size / 1024) + 0.5;
            CmbStrCpy(units, KILOBYTE_STR);
        }
        else // bytes
            CmbStrCpy(units, BYTE_STR);

        sprintf(sizeString, "%ld %2s", size, units);
    }

    errChk(SetTreeCellAttribute(info->panel, info->list, index, info->columnIndexSize, ATTR_LABEL_TEXT, sizeString));

Error:
    return error;
}

// ****************************************************************************
// Fills in the value for the time column, if it exists, for index.
static int CVIFUNC PopulateTreeColumnTime(FileBrowser* info, int index)
{
    int error = 0;
    int seconds = -1;                               // these hold the parts of the time
    int minutes = -1;
    int hours   = -1;
    int day     = -1;
    int month   = -1;
    int year    = -1;
    char path[MAX_PATHNAME_LEN] = "";               // the value of the item
    char timeString[MAX_TIMESTRING_LEN] = "";       // the string containing the full time and date
    int  BOLE;

    // If the column doesn't exist, we don't want to continue.
    if(info->columnIndexTime == COLUMN_DOESNT_EXIST)
        goto Error;

    errChk(GetValueFromIndex(info->panel, info->list, index, path));

    BOLE = SetBreakOnLibraryErrors(0);
    if( (error=GetFileDate(path,&month,&day,&year))<0
     || (error=GetFileTime(path,&hours,&minutes,&seconds))<0 ) {
        *timeString = '\0';
        goto SetTime;
    }
    SetBreakOnLibraryErrors(BOLE);

    if(info->timeFormat == TIME_FORMAT_UNITEDSTATES)
        sprintf(timeString, "   %.2d/%.2d/%.4d %.2d:%.2d:%.2d", month, day, year, hours, minutes, seconds);
    else if(info->timeFormat == TIME_FORMAT_EUROPEAN)
        sprintf(timeString, "   %.2d/%.2d/%.4d %.2d:%.2d:%.2d", day, month, year, hours, minutes, seconds);
    else {
        if(info->formatter == NULL) // If there is no function, fall back to the US standard.
            sprintf(timeString, "   %.2d/%.2d/%.4d %.2d:%.2d:%.2d", month, day, year, hours, minutes, seconds);
        else
            errChk(info->formatter(timeString, day, month, year, hours, minutes, seconds));
    }

SetTime:
    errChk(SetTreeCellAttribute(info->panel, info->list, index, info->columnIndexTime, ATTR_LABEL_TEXT, timeString));

Error:
    return error;
}

// ****************************************************************************
// Fills in the value for the type column, if it exists, for index.
static int CVIFUNC PopulateTreeColumnType(FileBrowser* info, int index)
{
    int error = 0;
    char val[MAX_PATHNAME_LEN] = "";                // the value of the item
#if defined (_NI_mswin32_) && _NI_mswin32_
    DWORD_PTR win_error;
    SHFILEINFO fileInfo;
#elif defined (_NI_linux_) && _NI_linux_
    struct stat fileInfo;
#endif

    if(info->columnIndexType == COLUMN_DOESNT_EXIST)
        goto Error;

    errChk(GetValueFromIndex(info->panel, info->list, index, val));

#if defined (_NI_mswin32_) && _NI_mswin32_
    win_error = (*SHGetFileInfoPtr)(val, 0, &fileInfo, sizeof(fileInfo), SHGFI_TYPENAME);
    if(!win_error)
        errChk(UIEUnableToOpenFile);

    errChk(SetTreeCellAttribute(info->panel, info->list, index, info->columnIndexType, ATTR_LABEL_TEXT, fileInfo.szTypeName));
#elif defined (_NI_linux_) && _NI_linux_
    if (stat (val, &fileInfo) == -1)
        errChk(UIEUnableToOpenFile);
    errChk(SetTreeCellAttribute(info->panel, info->list, index, info->columnIndexType, ATTR_LABEL_TEXT,
        S_ISDIR(fileInfo.st_mode) ? "Directory" : S_ISLNK(fileInfo.st_mode) ? "Link" : "File"));
#endif

Error:
    return error;
}

// ****************************************************************************
// Refreshes the values of all columns for all items.
static int CVIFUNC ResetTreeColumnValues(FileBrowser* info)
{
    int error = 0;
    int index = -1;

    errChk(GetTreeItem(info->panel, info->list, VAL_ALL, 0, VAL_FIRST, VAL_NEXT_PLUS_SELF, 0, &index));
    while(index >= 0) {
        errChk(PopulateTreeColumnsForItem(info, index));
        errChk(GetTreeItem(info->panel, info->list, VAL_ALL, 0, index, VAL_NEXT, 0, &index));
    }

Error:
    return error;
}

#if defined (_NI_mswin32_) && _NI_mswin32_
// ****************************************************************************
// Assigns the correct icon to the node at index.
static int CVIFUNC AssignIconToTreeItem(FileBrowser* info, int control, int index)
{
    int     error = 0;
    int     treeBitmap = -1;
    char    fileName[MAX_PATHNAME_LEN];                 // the filename we are looking up
    int     dir = -1;

    errChk(GetValueFromIndex(info->panel, control, index, fileName));

    errChk(IsDir(info->panel, control, index, &dir));

    // If it's a directory, it will have different images for open and closed,
    // so we must get those separately.
    if(dir && control == info->tree)
        {
        errChk(GetFileIcon(info, fileName, &treeBitmap, 0));
        errChk(SetTreeItemAttribute(info->panel, control, index, ATTR_COLLAPSED_IMAGE_INDEX, treeBitmap));
        errChk(SetTreeItemAttribute(info->panel, control, index, ATTR_IMAGE_INDEX, treeBitmap));
        }
    // For files, the icon is the same for both states because files are never really
    // open like folders are.
    else
        {
        errChk(GetFileIcon(info, fileName, &treeBitmap, 0));

        // Now assign the image to the node.
        errChk(SetTreeItemAttribute(info->panel, control, index, ATTR_IMAGE_INDEX, treeBitmap));
        errChk(SetTreeItemAttribute(info->panel, control, index, ATTR_COLLAPSED_IMAGE_INDEX, treeBitmap));
        }

Error:
    return error;
}

// ****************************************************************************
// Converts a Windows HICON resource into a LabWindows/CVI bitmap.  Sets bitmap to the
// handle of the new LabWindows/CVI bitmap.
static int CVIFUNC GetCVIBitmapFromHIcon(HICON icon, int* bitmap)
{
    int error = 0;
    int i, j;
    DWORD_PTR win_error;
    unsigned char bitmapData[16*16*4];                  // 16 lines x 16 pixels/line x 4 bytes per pixel
    unsigned char maskData[16*4];                       // 16 lines x 4 bytes per line
    unsigned char squishedMaskData[16*2];               // 16 lines x 2 bytes per line
    unsigned char alpha[16*16];                         // 16 lines x 16 pixels/line x 1 byte per pixel
    int rowSize, hasAlpha = 0;
    ICONINFO iconInfo;
    BITMAPINFO bitmapInfo;
    BITMAPINFO maskInfo;


    HDC hdc = GetDC(NULL);

    bitmapInfo.bmiHeader.biSize         = maskInfo.bmiHeader.biSize         = sizeof(BITMAPINFOHEADER);
    bitmapInfo.bmiHeader.biBitCount                                         = 32;   // This must be 32 bit, not 24, or else there will be a byte order problem.
                                          maskInfo.bmiHeader.biBitCount     = 1;
    bitmapInfo.bmiHeader.biWidth        = maskInfo.bmiHeader.biWidth        = 16;
    bitmapInfo.bmiHeader.biHeight       = maskInfo.bmiHeader.biHeight       = -16;  // negative to make the image top to bottom instead of bottom to top
    bitmapInfo.bmiHeader.biPlanes       = maskInfo.bmiHeader.biPlanes       = 1;
    bitmapInfo.bmiHeader.biCompression  = maskInfo.bmiHeader.biCompression  = BI_RGB;

    rowSize = (bitmapInfo.bmiHeader.biWidth * bitmapInfo.bmiHeader.biBitCount + 31) / 32 * 4;


    win_error = GetIconInfo(icon, &iconInfo);
    if(!win_error)
        errChk(UIEInvalidImageType);

    win_error = GetDIBits(hdc, iconInfo.hbmColor, 0, 16, bitmapData, &bitmapInfo, DIB_RGB_COLORS);
    if(!win_error)
        errChk(UIEInvalidImageType);
    win_error = GetDIBits(hdc, iconInfo.hbmMask, 0, 16, maskData, &maskInfo, DIB_RGB_COLORS);
    if(!win_error)
        errChk(UIEInvalidImageType);

    for(i=0; i<16*4;i++) maskData[i] = ~(maskData[i]);


    // The mask we get back from Windows is 4 byte aligned, i.e. 2 bytes of padding on each line.
    // Here we are removing the 2nd half of each line
    for(i=0; i<16; i++) {
        squishedMaskData[i*2] = maskData[i*4];
        squishedMaskData[i*2+1] = maskData[i*4+1];
    }
    
    for (i=0; i<16; i++)
        for (j=0; j<16; ++j)
            {
            alpha[i*16+j] = bitmapData[i*16*4+j*4+3];
            if (alpha[i*16+j])
                hasAlpha = 1;
            }


    // Add this bitmap to LabWindows/CVI.
    errChk(NewBitmapEx(rowSize,                         // bytes per row
                     bitmapInfo.bmiHeader.biBitCount,   // bitmap color depth
                     bitmapInfo.bmiHeader.biWidth,      // bitmap width
                     -bitmapInfo.bmiHeader.biHeight,    // bitmap height: negative because we used a negative height to get a top-to-bottom image
                     NULL,                              // color table: unused for 32 bpp
                     (unsigned char*)bitmapData,        // the bitmap itself
                     (unsigned char*)squishedMaskData,  // the mask (with no line padding)
                     (hasAlpha) ? (unsigned char*)alpha : 0,
                     bitmap                             // the handle returned
                     ));

    if(!DeleteDC(hdc))
        errChk(UIEOperationFailed);
    if(!DeleteObject(iconInfo.hbmColor))
        errChk(UIEOperationFailed);
    if(!DeleteObject(iconInfo.hbmMask))
        errChk(UIEOperationFailed);

Error:
    return error;
}

// ****************************************************************************
// Gets a tree icon for fileName, either from the file browser's cache of icons, or from Windows
// if the icon hasn't been loaded yet.
// Flags must be either 0 or SHGFI_OPENICON.
static int CVIFUNC GetFileIcon(FileBrowser* info, char* fileName, int* treeBitmap, int flags)
{
    int error = 0;
    int listIndex = -1;
    SHFILEINFO fileInfo;
    DWORD_PTR win_error;
    char filenameBuffer[MAX_PATHNAME_LEN];
    int bitmapID = -1;
    char* colonLoc = NULL;
    FileTypeData newType;
    FileTypeData cachedData;

    *treeBitmap = -1;

    assert(flags == SHGFI_OPENICON || flags == 0);

    // Check if this is a drive, not a normal directory.
    colonLoc = (char *)CmbStrRChr((unsigned char *)fileName, (unsigned int)':');
    if(colonLoc != NULL && !CmbStrCmp((unsigned char *)":", (unsigned char *)colonLoc)) {
        // Put a backslash on the end of the filename because that is Windows standard.
        CmbStrCpy(filenameBuffer, fileName);
        CmbStrCat(filenameBuffer, PATH_SEPARATOR);
        fileName = filenameBuffer;
    }

    // Get the icon system image index and a handle to it.
    win_error = (*SHGetFileInfoPtr)(fileName, 0, &fileInfo, sizeof(fileInfo), SHGFI_ICON | SHGFI_SMALLICON | SHGFI_SHELLICONSIZE | flags);
    if(!win_error)
        return 0;   // Do not throw an error here; some files do not have icons.

    // Set up the search structure and perform the search.
    newType.sysImageIndex = fileInfo.iIcon;
    newType.handle = fileInfo.hIcon;
    listIndex = ListBinSearch(info->fileTypeIconsList, &newType, FileTypeDataCompare);

    // If we find a cache entry, use its icon and free the one we just got from Windows.
    if(listIndex > 0) {
        ListGetItem(info->fileTypeIconsList, &cachedData, listIndex);
        *treeBitmap = cachedData.treeImageIndex;
        DestroyIcon(fileInfo.hIcon);
    }
    // If we didn't find it, use the handle we just got from Windows to make a tree icon, and
    // keep the handle afterwards to make sure that the system icon index that we're using
    // for a key doesn't change.
    else {
        errChk(GetCVIBitmapFromHIcon(newType.handle, &bitmapID));

        // Add it from LabWindows/CVI to the tree and return the handle.
        errChk(AddTreeImage(info->panel, info->tree, bitmapID));
        errChk(*treeBitmap = AddTreeImage(info->panel, info->list, bitmapID));

        // Now add it to the cache list.
        newType.treeImageIndex = *treeBitmap;
        if(!ListInsertInOrder(info->fileTypeIconsList, &newType, FileTypeDataCompare))
            errChk(UIEOperationFailed);
    }
Error:
    if(bitmapID != -1)
        DiscardBitmap(bitmapID);
    return error;
}

// ****************************************************************************
// Callback function for the filetypes list.  Compares the two items to put them
// in alphabetic order by extension.
static int CVICALLBACK FileTypeDataCompare(void* item1, void* item2)
{
    if(((FileTypeData*)item1)->sysImageIndex > ((FileTypeData*)item2)->sysImageIndex)
        return -1;
    else if(((FileTypeData*)item1)->sysImageIndex < ((FileTypeData*)item2)->sysImageIndex)
        return 1;
    else
        return 0;
}

// ****************************************************************************
// Callback funcion for the filetypes list.  Frees all of the HICON handles.
// This should be called only if the cache is being cleared and its memory freed.
static int CVICALLBACK FileTypeDataDispose(int index, void* item, void* data)
{
    DestroyIcon(((FileTypeData*)item)->handle);
    return 0;
}

// ****************************************************************************
// Set whether icons are visible or not.
static int CVIFUNC SetIconsVisibleState(FileBrowser* info, int state)
{
    int error = 0;
    int locked = FALSE;
    int index;

    if(state == info->fileIconsVisible)
        goto Error;

    errChk(CmtGetLock(info->lockHandle));
    locked = TRUE;
    info->fileIconsVisible = state;
    errChk(CmtReleaseLock(info->lockHandle));
    locked = FALSE;

    errChk(SetCtrlAttribute(info->panel, info->tree, ATTR_SHOW_IMAGES, info->fileIconsVisible));
    errChk(SetCtrlAttribute(info->panel, info->list, ATTR_SHOW_IMAGES, info->fileIconsVisible));

    // If we just turned on icons, go through the tree and add them to all files.
    if(info->fileIconsVisible) {
        errChk(GetTreeItem(info->panel, info->tree, VAL_ALL, 0, VAL_FIRST, VAL_NEXT_PLUS_SELF, 0, &index));
        while(index >= 0) {
            errChk(AssignIconToTreeItem(info, info->tree, index));
            errChk(GetTreeItem(info->panel, info->tree, VAL_ALL, 0, index, VAL_NEXT, 0, &index));
        }
    }
Error:
    if(locked)
        CmtReleaseLock(info->lockHandle);
    return error;
}

#if 0 /* not needed */
static int CVIFUNC RefreshDriveTypes(FileBrowser *info, int add, int type)
{
    int error=0;

    errChk(RemoveDriveType(info,type));
    if( add )
        errChk(AddDriveTypeToTree(info,type));

Error:
    return error;
}
#endif /* 0 */
#endif
// ****************************************************************************
static int CVIFUNC GetLevelFromPath(char *separator, char *path)
{
    char    *ptr = path;
    int     sepLen, level = 0;

    sepLen = strlen(separator);
    while (ptr = strstr(ptr, separator))
        {
        level++;
        ptr += sepLen;
        }
    return level;
}

// ****************************************************************************
static int CVIFUNC PopulateTreeToPath(FileBrowser *info, char *path)
{
    int     error = 0;
    int     index, curLevel = 0, pathLevel, done = FALSE;

    pathLevel = GetLevelFromPath(PATH_SEPARATOR, path);

    while (!done)
        {
        done = GetIndexFromPath(info->panel, info->tree, PATH_SEPARATOR, path, curLevel, &index);
        if (index < 0)
            break;
        PopulateFolder(info->panel, info->tree, index);
        errChk(PopulateFoldersOnExpand(info->panel, info->tree, index));
        if (curLevel == pathLevel)
            break;
        ++curLevel;
        }

Error:
    return error;
}

// ****************************************************************************
// returns TRUE if the full path was used
static int CVIFUNC GetIndexFromPath(int panel, int control, char *separator,
                                    char *path, int level, int *treeIndex)
{
    int     error = 0;
    int     usedFullPath = FALSE;
    int     sepLen, index, siblingIndex, numChildren, lastIndex = -1;
    char    *curLabel, *ptr;
    char    buf[MAX_PATHNAME_LEN];
    FileBrowser *info;
    int     lookForRoot = TRUE;

    errChk(GetFileBrowserPtr(panel, control, &info));
    curLabel = path + strlen(info->rootPath);
    sepLen = strlen(separator);
    index = -1;

    while (TRUE)
        {
        if (lookForRoot)
            {
            lookForRoot = FALSE;
            CmbStrCpy (buf, info->rootPath);
            ptr = curLabel;
            if (CmbStrEq ((unsigned char *)path, (unsigned char *)info->rootPath))
                usedFullPath = TRUE;
            }
        else
            {
            ptr = strstr(curLabel, separator);
            if (!ptr)
                {
                ptr = curLabel + strlen(curLabel);
                usedFullPath = TRUE;
                }
            strncpy(buf, curLabel, ptr-curLabel);
            buf[ptr-curLabel] = 0;
            }
        if (!usedFullPath)
            curLabel = ptr + sepLen;
        siblingIndex = index + 1;
        lastIndex = index;
        GetTreeItemFromLabel(panel, control, VAL_SIBLING, siblingIndex, VAL_FIRST, VAL_NEXT_PLUS_SELF, 0, buf, &index);
        if (index < 0)
            break;
        lastIndex = index;
        GetTreeItemNumChildren(panel, control, index, &numChildren);
        if (!numChildren)
            break;
        if (level-- == 0)
            break;
        }

    if (treeIndex)
        *treeIndex = lastIndex;
Error:
    return usedFullPath;
}

// ****************************************************************************
// Refreshes the files that are descendents of index
static int CVIFUNC Refresh(FileBrowser *info, int index)
{
    int     error = 0;
    int     numChildren;
    char    path[MAX_PATHNAME_LEN];

    if (index == -1)
        index = 0;

    GetTreeItemPath(info->panel, info->tree, index, PATH_SEPARATOR, path);

    errChk(GetTreeItemNumChildren(info->panel, info->tree, index, &numChildren));
    if (numChildren)
        {
        errChk(DeleteListItem(info->panel, info->tree, index+1, -1)); // delete all children
        }

    errChk(PopulateTreeToPath(info, path));
    errChk(PopulateListFromPath(info, path));

Error:
    return error;
}

// ****************************************************************************
static long ConvertStringToBytes (char *str)
{
    char *ptr;
    long bytes = 0;

    bytes = strtol (str, &ptr, 10);
    RemoveSurroundingWhiteSpace(ptr);
    if (CmbStrEqI((unsigned char *)ptr, (unsigned char *)KILOBYTE_STR))
        bytes = bytes * 1024;
    else if (CmbStrEqI((unsigned char *)ptr, (unsigned char *)MEGABYTE_STR))
        bytes = bytes * 1048576;
    else if (CmbStrEqI((unsigned char *)ptr, (unsigned char *)GIGABYTE_STR))
        bytes = bytes * 1073741824;
    return bytes;
}

// ****************************************************************************
// Callback function for tree sort calls.  Sorts so that directories appear
// before files, and other than that, things are sorted alphabetically, case-insensitive.
static int CVICALLBACK TreeSortCallback(int panel, int control, int item1, int item2, int keyCol, void* callbackData)
{
    int item1isDir = FALSE;
    int item2isDir = FALSE;
    long size1, size2;
    char item1val[MAX_FILENAME_LEN] = "";
    char item2val[MAX_FILENAME_LEN] = "";

    IsDir(panel, control, item1, &item1isDir);
    IsDir(panel, control, item2, &item2isDir);

    if(item1isDir && !item2isDir)
        return -1;
    else if(item2isDir && !item1isDir)
        return 1;
    else {
        GetTreeColumnAttribute (panel, control, keyCol, ATTR_LABEL_TEXT, item1val);
        if (CmbStrEqI((unsigned char *)SIZE_STR, (unsigned char *)item1val))
            {
            GetTreeCellAttribute (panel, control, item1, keyCol, ATTR_LABEL_TEXT, item1val);
            GetTreeCellAttribute (panel, control, item2, keyCol, ATTR_LABEL_TEXT, item2val);
            size1 = ConvertStringToBytes(item1val);
            size2 = ConvertStringToBytes(item2val);
            if (size1 < size2)
                return -1;
            else if (size2 < size1)
                return 1;
            else
                return 0;
            }
        else
            {
            GetTreeCellAttribute (panel, control, item1, keyCol, ATTR_LABEL_TEXT, item1val);
            GetTreeCellAttribute (panel, control, item2, keyCol, ATTR_LABEL_TEXT, item2val);
            return CmbStrICmp((unsigned char *)item1val, (unsigned char *)item2val);
            }
    }
}

