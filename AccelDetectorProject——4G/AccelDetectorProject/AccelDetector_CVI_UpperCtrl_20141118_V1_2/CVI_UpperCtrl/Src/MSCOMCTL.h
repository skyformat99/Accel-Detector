#ifndef _MSCOMCTLLIB_H
#define _MSCOMCTLLIB_H

#if defined(INCLUDE_AFTER_WINDOWS_H) && !defined(_INC_WINDOWS)
#error  This header must be included before utility.h and formatio.h
#error  because it includes cviauto.h which includes Windows SDK headers.
#endif /* INCLUDE_AFTER_WINDOWS_H */

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> Type Library Specific Types */

enum MSComctlLibEnum_TabStyleConstants
{
	MSComctlLibConst_tabTabs = 0,
	MSComctlLibConst_tabButtons = 1,
	MSComctlLibConst_tabFlatButtons = 2,
	_MSComctlLib_TabStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_TabWidthStyleConstants
{
	MSComctlLibConst_tabJustified = 0,
	MSComctlLibConst_tabNonJustified = 1,
	MSComctlLibConst_tabFixed = 2,
	_MSComctlLib_TabWidthStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_MousePointerConstants
{
	MSComctlLibConst_ccDefault = 0,
	MSComctlLibConst_ccArrow = 1,
	MSComctlLibConst_ccCross = 2,
	MSComctlLibConst_ccIBeam = 3,
	MSComctlLibConst_ccIcon = 4,
	MSComctlLibConst_ccSize = 5,
	MSComctlLibConst_ccSizeNESW = 6,
	MSComctlLibConst_ccSizeNS = 7,
	MSComctlLibConst_ccSizeNWSE = 8,
	MSComctlLibConst_ccSizeEW = 9,
	MSComctlLibConst_ccUpArrow = 10,
	MSComctlLibConst_ccHourglass = 11,
	MSComctlLibConst_ccNoDrop = 12,
	MSComctlLibConst_ccArrowHourglass = 13,
	MSComctlLibConst_ccArrowQuestion = 14,
	MSComctlLibConst_ccSizeAll = 15,
	MSComctlLibConst_ccCustom = 99,
	_MSComctlLib_MousePointerConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_OLEDropConstants
{
	MSComctlLibConst_ccOLEDropNone = 0,
	MSComctlLibConst_ccOLEDropManual = 1,
	_MSComctlLib_OLEDropConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_PlacementConstants
{
	MSComctlLibConst_tabPlacementTop = 0,
	MSComctlLibConst_tabPlacementBottom = 1,
	MSComctlLibConst_tabPlacementLeft = 2,
	MSComctlLibConst_tabPlacementRight = 3,
	_MSComctlLib_PlacementConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_TabSelStyleConstants
{
	MSComctlLibConst_tabTabStandard = 0,
	MSComctlLibConst_tabTabOpposite = 1,
	_MSComctlLib_TabSelStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_AppearanceConstants
{
	MSComctlLibConst_ccFlat = 0,
	MSComctlLibConst_cc3D = 1,
	_MSComctlLib_AppearanceConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_BorderStyleConstants
{
	MSComctlLibConst_ccNone = 0,
	MSComctlLibConst_ccFixedSingle = 1,
	_MSComctlLib_BorderStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ToolbarStyleConstants
{
	MSComctlLibConst_tbrStandard = 0,
	MSComctlLibConst_tbrFlat = 1,
	_MSComctlLib_ToolbarStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ToolbarTextAlignConstants
{
	MSComctlLibConst_tbrTextAlignBottom = 0,
	MSComctlLibConst_tbrTextAlignRight = 1,
	_MSComctlLib_ToolbarTextAlignConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ValueConstants
{
	MSComctlLibConst_tbrUnpressed = 0,
	MSComctlLibConst_tbrPressed = 1,
	_MSComctlLib_ValueConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ButtonStyleConstants
{
	MSComctlLibConst_tbrDefault = 0,
	MSComctlLibConst_tbrCheck = 1,
	MSComctlLibConst_tbrButtonGroup = 2,
	MSComctlLibConst_tbrSeparator = 3,
	MSComctlLibConst_tbrPlaceholder = 4,
	MSComctlLibConst_tbrDropdown = 5,
	_MSComctlLib_ButtonStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_SbarStyleConstants
{
	MSComctlLibConst_sbrNormal = 0,
	MSComctlLibConst_sbrSimple = 1,
	_MSComctlLib_SbarStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_PanelAlignmentConstants
{
	MSComctlLibConst_sbrLeft = 0,
	MSComctlLibConst_sbrCenter = 1,
	MSComctlLibConst_sbrRight = 2,
	_MSComctlLib_PanelAlignmentConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_PanelAutoSizeConstants
{
	MSComctlLibConst_sbrNoAutoSize = 0,
	MSComctlLibConst_sbrSpring = 1,
	MSComctlLibConst_sbrContents = 2,
	_MSComctlLib_PanelAutoSizeConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_PanelBevelConstants
{
	MSComctlLibConst_sbrNoBevel = 0,
	MSComctlLibConst_sbrInset = 1,
	MSComctlLibConst_sbrRaised = 2,
	_MSComctlLib_PanelBevelConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_PanelStyleConstants
{
	MSComctlLibConst_sbrText = 0,
	MSComctlLibConst_sbrCaps = 1,
	MSComctlLibConst_sbrNum = 2,
	MSComctlLibConst_sbrIns = 3,
	MSComctlLibConst_sbrScrl = 4,
	MSComctlLibConst_sbrTime = 5,
	MSComctlLibConst_sbrDate = 6,
	MSComctlLibConst_sbrKana = 7,
	_MSComctlLib_PanelStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_OrientationConstants
{
	MSComctlLibConst_ccOrientationHorizontal = 0,
	MSComctlLibConst_ccOrientationVertical = 1,
	_MSComctlLib_OrientationConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ScrollingConstants
{
	MSComctlLibConst_ccScrollingStandard = 0,
	MSComctlLibConst_ccScrollingSmooth = 1,
	_MSComctlLib_ScrollingConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_LabelEditConstants
{
	MSComctlLibConst_tvwAutomatic = 0,
	MSComctlLibConst_tvwManual = 1,
	_MSComctlLib_LabelEditConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_TreeLineStyleConstants
{
	MSComctlLibConst_tvwTreeLines = 0,
	MSComctlLibConst_tvwRootLines = 1,
	_MSComctlLib_TreeLineStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_TreeStyleConstants
{
	MSComctlLibConst_tvwTextOnly = 0,
	MSComctlLibConst_tvwPictureText = 1,
	MSComctlLibConst_tvwPlusMinusText = 2,
	MSComctlLibConst_tvwPlusPictureText = 3,
	MSComctlLibConst_tvwTreelinesText = 4,
	MSComctlLibConst_tvwTreelinesPictureText = 5,
	MSComctlLibConst_tvwTreelinesPlusMinusText = 6,
	MSComctlLibConst_tvwTreelinesPlusMinusPictureText = 7,
	_MSComctlLib_TreeStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_OLEDragConstants
{
	MSComctlLibConst_ccOLEDragManual = 0,
	MSComctlLibConst_ccOLEDragAutomatic = 1,
	_MSComctlLib_OLEDragConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListArrangeConstants
{
	MSComctlLibConst_lvwNone = 0,
	MSComctlLibConst_lvwAutoLeft = 1,
	MSComctlLibConst_lvwAutoTop = 2,
	_MSComctlLib_ListArrangeConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListLabelEditConstants
{
	MSComctlLibConst_lvwAutomatic = 0,
	MSComctlLibConst_lvwManual = 1,
	_MSComctlLib_ListLabelEditConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListSortOrderConstants
{
	MSComctlLibConst_lvwAscending = 0,
	MSComctlLibConst_lvwDescending = 1,
	_MSComctlLib_ListSortOrderConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListViewConstants
{
	MSComctlLibConst_lvwIcon = 0,
	MSComctlLibConst_lvwSmallIcon = 1,
	MSComctlLibConst_lvwList = 2,
	MSComctlLibConst_lvwReport = 3,
	_MSComctlLib_ListViewConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListPictureAlignmentConstants
{
	MSComctlLibConst_lvwTopLeft = 0,
	MSComctlLibConst_lvwTopRight = 1,
	MSComctlLibConst_lvwBottomLeft = 2,
	MSComctlLibConst_lvwBottomRight = 3,
	MSComctlLibConst_lvwCenter = 4,
	MSComctlLibConst_lvwTile = 5,
	_MSComctlLib_ListPictureAlignmentConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListTextBackgroundConstants
{
	MSComctlLibConst_lvwTransparent = 0,
	MSComctlLibConst_lvwOpaque = 1,
	_MSComctlLib_ListTextBackgroundConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListColumnAlignmentConstants
{
	MSComctlLibConst_lvwColumnLeft = 0,
	MSComctlLibConst_lvwColumnRight = 1,
	MSComctlLibConst_lvwColumnCenter = 2,
	_MSComctlLib_ListColumnAlignmentConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_TickStyleConstants
{
	MSComctlLibConst_sldBottomRight = 0,
	MSComctlLibConst_sldTopLeft = 1,
	MSComctlLibConst_sldBoth = 2,
	MSComctlLibConst_sldNoTicks = 3,
	_MSComctlLib_TickStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_TextPositionConstants
{
	MSComctlLibConst_sldAboveLeft = 0,
	MSComctlLibConst_sldBelowRight = 1,
	_MSComctlLib_TextPositionConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ImageComboStyleConstants
{
	MSComctlLibConst_ImgCboDropdownCombo = 0,
	MSComctlLibConst_ImgCboSimpleCombo = 1,
	MSComctlLibConst_ImgCboDropdownList = 2,
	_MSComctlLib_ImageComboStyleConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_VB4AppearanceConstants
{
	MSComctlLibConst_vbFlat = 0,
	MSComctlLibConst_vb3D = 1,
	_MSComctlLib_VB4AppearanceConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_DragOverConstants
{
	MSComctlLibConst_ccEnter = 0,
	MSComctlLibConst_ccLeave = 1,
	MSComctlLibConst_ccOver = 2,
	_MSComctlLib_DragOverConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ClipBoardConstants
{
	MSComctlLibConst_ccCFText = 1,
	MSComctlLibConst_ccCFBitmap = 2,
	MSComctlLibConst_ccCFMetafile = 3,
	MSComctlLibConst_ccCFDIB = 8,
	MSComctlLibConst_ccCFPalette = 9,
	MSComctlLibConst_ccCFEMetafile = 14,
	MSComctlLibConst_ccCFFiles = 15,
	MSComctlLibConst_ccCFRTF = -16639,
	_MSComctlLib_ClipBoardConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_OLEDropEffectConstants
{
	MSComctlLibConst_ccOLEDropEffectNone = 0,
	MSComctlLibConst_ccOLEDropEffectCopy = 1,
	MSComctlLibConst_ccOLEDropEffectMove = 2,
	MSComctlLibConst_ccOLEDropEffectScroll = -2147483648,
	_MSComctlLib_OLEDropEffectConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ErrorConstants
{
	MSComctlLibConst_ccInvalidProcedureCall = 5,
	MSComctlLibConst_ccOutOfMemory = 7,
	MSComctlLibConst_ccTypeMismatch = 13,
	MSComctlLibConst_ccObjectVariableNotSet = 91,
	MSComctlLibConst_ccInvalidPropertyValue = 380,
	MSComctlLibConst_ccSetNotSupportedAtRuntime = 382,
	MSComctlLibConst_ccSetNotSupported = 383,
	MSComctlLibConst_ccSetNotPermitted = 387,
	MSComctlLibConst_ccGetNotSupported = 394,
	MSComctlLibConst_ccInvalidPicture = 481,
	MSComctlLibConst_ccInvalidObjectUse = 425,
	MSComctlLibConst_ccWrongClipboardFormat = 461,
	MSComctlLibConst_ccDataObjectLocked = 672,
	MSComctlLibConst_ccExpectedAnArgument = 673,
	MSComctlLibConst_ccRecursiveOleDrag = 674,
	MSComctlLibConst_ccFormatNotByteArray = 675,
	MSComctlLibConst_ccDataNotSetForFormat = 676,
	MSComctlLibConst_ccIndexOutOfBounds = 35600,
	MSComctlLibConst_ccElemNotFound = 35601,
	MSComctlLibConst_ccNonUniqueKey = 35602,
	MSComctlLibConst_ccInvalidKey = 35603,
	MSComctlLibConst_ccElemNotPartOfCollection = 35605,
	MSComctlLibConst_ccCollectionChangedDuringEnum = 35606,
	MSComctlLibConst_ccWouldIntroduceCycle = 35614,
	MSComctlLibConst_ccMissingRequiredArg = 35607,
	MSComctlLibConst_ccBadObjectReference = 35610,
	MSComctlLibConst_ccCircularReference = 35700,
	MSComctlLibConst_ccCol1MustBeLeftAligned = 35604,
	MSComctlLibConst_ccReadOnlyIfHasImages = 35611,
	MSComctlLibConst_ccImageListMustBeInitialized = 35613,
	MSComctlLibConst_ccNotSameSize = 35615,
	MSComctlLibConst_ccImageListLocked = 35617,
	MSComctlLibConst_ccMaxPanelsExceeded = 35616,
	MSComctlLibConst_ccMaxButtonsExceeded = 35619,
	MSComctlLibConst_ccInvalidSafeModeProcCall = 680,
	_MSComctlLib_ErrorConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_TreeRelationshipConstants
{
	MSComctlLibConst_tvwFirst = 0,
	MSComctlLibConst_tvwLast = 1,
	MSComctlLibConst_tvwNext = 2,
	MSComctlLibConst_tvwPrevious = 3,
	MSComctlLibConst_tvwChild = 4,
	_MSComctlLib_TreeRelationshipConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListFindItemWhereConstants
{
	MSComctlLibConst_lvwText = 0,
	MSComctlLibConst_lvwSubItem = 1,
	MSComctlLibConst_lvwTag = 2,
	_MSComctlLib_ListFindItemWhereConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ListFindItemHowConstants
{
	MSComctlLibConst_lvwWhole = 0,
	MSComctlLibConst_lvwPartial = 1,
	_MSComctlLib_ListFindItemHowConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MSComctlLibEnum_ImageDrawConstants
{
	MSComctlLibConst_imlNormal = 0,
	MSComctlLibConst_imlTransparent = 1,
	MSComctlLibConst_imlSelected = 2,
	MSComctlLibConst_imlFocus = 3,
	_MSComctlLib_ImageDrawConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
typedef CAObjHandle MSComctlLibObj_IVBDataObjectFiles;
typedef CAObjHandle MSComctlLibObj_ITabs;
typedef CAObjHandle MSComctlLibObj_Font;
typedef CAObjHandle MSComctlLibObj_IFontDisp;
typedef long MSComctlLibType_OLE_HANDLE;
typedef CAObjHandle MSComctlLibObj_Picture;
typedef CAObjHandle MSComctlLibObj_IPictureDisp;
typedef CAObjHandle MSComctlLibObj_ITab;
typedef long MSComctlLibType_OLE_XPOS_PIXELS;
typedef long MSComctlLibType_OLE_YPOS_PIXELS;
typedef CAObjHandle MSComctlLibObj_IVBDataObject;
typedef CAObjHandle MSComctlLibObj_IButtons;
typedef CAObjHandle MSComctlLibObj_IControls;
typedef CAObjHandle MSComctlLibObj_IButton;
typedef CAObjHandle MSComctlLibObj_IButtonMenu;
typedef CAObjHandle MSComctlLibObj_IButtonMenus;
typedef CAObjHandle MSComctlLibObj_IPanels;
typedef CAObjHandle MSComctlLibObj_IPanel;
typedef CAObjHandle MSComctlLibObj_INode;
typedef CAObjHandle MSComctlLibObj_INodes;
typedef unsigned long MSComctlLibType_OLE_COLOR;
typedef CAObjHandle MSComctlLibObj_IColumnHeaders;
typedef CAObjHandle MSComctlLibObj_IListItem;
typedef CAObjHandle MSComctlLibObj_IListItems;
typedef CAObjHandle MSComctlLibObj_IColumnHeader;
typedef CAObjHandle MSComctlLibObj_IListSubItems;
typedef CAObjHandle MSComctlLibObj_IListSubItem;
typedef CAObjHandle MSComctlLibObj_IImages;
typedef CAObjHandle MSComctlLibObj_IImage;
typedef CAObjHandle MSComctlLibObj_IComboItem;
typedef CAObjHandle MSComctlLibObj_IComboItems;
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnKeyDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short *keyCode,
                                                                         short  shift);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short *keyAscii);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnKeyUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData,
                                                                       short *keyCode,
                                                                       short  shift);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short  button,
                                                                           short  shift,
                                                                           MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                           MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short  button,
                                                                           short  shift,
                                                                           MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                           MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short  button,
                                                                         short  shift,
                                                                         MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                         MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnBeforeClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             short *cancel);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              MSComctlLibObj_IVBDataObject *data,
                                                                              long *allowedEffects);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 long *effect,
                                                                                 VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IVBDataObject *data,
                                                                            short *dataFormat);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 long *effect);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IVBDataObject *data,
                                                                             long *effect,
                                                                             short *button,
                                                                             short *shift,
                                                                             float *x,
                                                                             float *y,
                                                                             short *state);
typedef HRESULT (CVICALLBACK *ITabStripEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IVBDataObject *data,
                                                                             long *effect,
                                                                             short *button,
                                                                             short *shift,
                                                                             float *x,
                                                                             float *y);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnButtonClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IButton  button);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                      void *caCallbackData);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short  button,
                                                                          short  shift,
                                                                          MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                          MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short  button,
                                                                          short  shift,
                                                                          MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                          MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData,
                                                                        short  button,
                                                                        short  shift,
                                                                        MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                        MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IVBDataObject *data,
                                                                             long *allowedEffects);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long *effect,
                                                                                VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           MSComctlLibObj_IVBDataObject *data,
                                                                           short *dataFormat);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long *effect);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IVBDataObject *data,
                                                                            long *effect,
                                                                            short *button,
                                                                            short *shift,
                                                                            float *x,
                                                                            float *y,
                                                                            short *state);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IVBDataObject *data,
                                                                            long *effect,
                                                                            short *button,
                                                                            short *shift,
                                                                            float *x,
                                                                            float *y);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnButtonMenuClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                MSComctlLibObj_IButtonMenu  buttonMenu);
typedef HRESULT (CVICALLBACK *IToolbarEventsRegOnButtonDropDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               MSComctlLibObj_IButton  button);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnPanelClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IPanel  panel);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnPanelDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                MSComctlLibObj_IPanel  panel);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            short  button,
                                                                            short  shift,
                                                                            MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                            MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            short  button,
                                                                            short  shift,
                                                                            MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                            MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short  button,
                                                                          short  shift,
                                                                          MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                          MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               MSComctlLibObj_IVBDataObject *data,
                                                                               long *allowedEffects);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                  void *caCallbackData,
                                                                                  long *effect,
                                                                                  VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IVBDataObject *data,
                                                                             short *dataFormat);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                  void *caCallbackData,
                                                                                  long *effect);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              MSComctlLibObj_IVBDataObject *data,
                                                                              long *effect,
                                                                              short *button,
                                                                              short *shift,
                                                                              float *x,
                                                                              float *y,
                                                                              short *state);
typedef HRESULT (CVICALLBACK *IStatusBarEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              MSComctlLibObj_IVBDataObject *data,
                                                                              long *effect,
                                                                              short *button,
                                                                              short *shift,
                                                                              float *x,
                                                                              float *y);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              short  button,
                                                                              short  shift,
                                                                              MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                              MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              short  button,
                                                                              short  shift,
                                                                              MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                              MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            short  button,
                                                                            short  shift,
                                                                            MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                            MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 MSComctlLibObj_IVBDataObject *data,
                                                                                 long *allowedEffects);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    long *effect,
                                                                                    VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               MSComctlLibObj_IVBDataObject *data,
                                                                               short *dataFormat);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    long *effect);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                MSComctlLibObj_IVBDataObject *data,
                                                                                long *effect,
                                                                                short *button,
                                                                                short *shift,
                                                                                float *x,
                                                                                float *y,
                                                                                short *state);
typedef HRESULT (CVICALLBACK *IProgressBarEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                MSComctlLibObj_IVBDataObject *data,
                                                                                long *effect,
                                                                                short *button,
                                                                                short *shift,
                                                                                float *x,
                                                                                float *y);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnBeforeLabelEdit_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 short *cancel);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnAfterLabelEdit_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                short *cancel,
                                                                                char **newString);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnCollapse_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          MSComctlLibObj_INode  node);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnExpand_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData,
                                                                        MSComctlLibObj_INode  node);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnNodeClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           MSComctlLibObj_INode  node);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnKeyDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short *keyCode,
                                                                         short  shift);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnKeyUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData,
                                                                       short *keyCode,
                                                                       short  shift);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short *keyAscii);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short  button,
                                                                           short  shift,
                                                                           MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                           MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short  button,
                                                                           short  shift,
                                                                           MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                           MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short  button,
                                                                         short  shift,
                                                                         MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                         MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnNodeCheck_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           MSComctlLibObj_INode  node);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              MSComctlLibObj_IVBDataObject *data,
                                                                              long *allowedEffects);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 long *effect,
                                                                                 VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IVBDataObject *data,
                                                                            short *dataFormat);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 long *effect);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IVBDataObject *data,
                                                                             long *effect,
                                                                             short *button,
                                                                             short *shift,
                                                                             float *x,
                                                                             float *y,
                                                                             short *state);
typedef HRESULT (CVICALLBACK *ITreeViewEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IVBDataObject *data,
                                                                             long *effect,
                                                                             short *button,
                                                                             short *shift,
                                                                             float *x,
                                                                             float *y);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnBeforeLabelEdit_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                short *cancel);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnAfterLabelEdit_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               short *cancel,
                                                                               char **newString);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnColumnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IColumnHeader  columnHeader);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnItemClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          MSComctlLibObj_IListItem  item);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnKeyDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData,
                                                                        short *keyCode,
                                                                        short  shift);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnKeyUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                      void *caCallbackData,
                                                                      short *keyCode,
                                                                      short  shift);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short *keyAscii);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short  button,
                                                                          short  shift,
                                                                          MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                          MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short  button,
                                                                          short  shift,
                                                                          MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                          MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData,
                                                                        short  button,
                                                                        short  shift,
                                                                        MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                        MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                      void *caCallbackData);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             MSComctlLibObj_IVBDataObject *data,
                                                                             long *allowedEffects);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long *effect,
                                                                                VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           MSComctlLibObj_IVBDataObject *data,
                                                                           short *dataFormat);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long *effect);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IVBDataObject *data,
                                                                            long *effect,
                                                                            short *button,
                                                                            short *shift,
                                                                            float *x,
                                                                            float *y,
                                                                            short *state);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IVBDataObject *data,
                                                                            long *effect,
                                                                            short *button,
                                                                            short *shift,
                                                                            float *x,
                                                                            float *y);
typedef HRESULT (CVICALLBACK *ListViewEventsRegOnItemCheck_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          MSComctlLibObj_IListItem  item);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                     void *caCallbackData);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnKeyDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData,
                                                                       short *keyCode,
                                                                       short  shift);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData,
                                                                        short *keyAscii);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnKeyUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                     void *caCallbackData,
                                                                     short *keyCode,
                                                                     short  shift);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short  button,
                                                                         short  shift,
                                                                         MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                         MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short  button,
                                                                         short  shift,
                                                                         MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                         MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData,
                                                                       short  button,
                                                                       short  shift,
                                                                       MSComctlLibType_OLE_XPOS_PIXELS  x,
                                                                       MSComctlLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnScroll_CallbackType) (CAObjHandle caServerObjHandle,
                                                                      void *caCallbackData);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                      void *caCallbackData);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            MSComctlLibObj_IVBDataObject *data,
                                                                            long *allowedEffects);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long *effect,
                                                                               VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          MSComctlLibObj_IVBDataObject *data,
                                                                          short *dataFormat);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long *effect);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           MSComctlLibObj_IVBDataObject *data,
                                                                           long *effect,
                                                                           short *button,
                                                                           short *shift,
                                                                           float *x,
                                                                           float *y,
                                                                           short *state);
typedef HRESULT (CVICALLBACK *ISliderEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           MSComctlLibObj_IVBDataObject *data,
                                                                           long *effect,
                                                                           short *button,
                                                                           short *shift,
                                                                           float *x,
                                                                           float *y);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnDropdown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnKeyDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short  keyCode,
                                                                           short  shift);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnKeyUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short  keyCode,
                                                                         short  shift);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            short *keyAscii);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnOLEStartDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                MSComctlLibObj_IVBDataObject *data,
                                                                                long *allowedEffects);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnOLEGiveFeedback_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                   void *caCallbackData,
                                                                                   long *effect,
                                                                                   VBOOL *defaultCursors);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnOLESetData_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              MSComctlLibObj_IVBDataObject *data,
                                                                              short *dataFormat);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnOLECompleteDrag_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                   void *caCallbackData,
                                                                                   long *effect);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnOLEDragOver_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               MSComctlLibObj_IVBDataObject *data,
                                                                               long *effect,
                                                                               short *button,
                                                                               short *shift,
                                                                               float *x,
                                                                               float *y,
                                                                               short *state);
typedef HRESULT (CVICALLBACK *DImageComboEventsRegOnOLEDragDrop_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               MSComctlLibObj_IVBDataObject *data,
                                                                               long *effect,
                                                                               short *button,
                                                                               short *shift,
                                                                               float *x,
                                                                               float *y);
/* NICDBLD_END> Type Library Specific Types */

extern const IID MSComctlLib_IID_ITabStrip;
extern const IID MSComctlLib_IID_IToolbar;
extern const IID MSComctlLib_IID_IStatusBar;
extern const IID MSComctlLib_IID_IProgressBar;
extern const IID MSComctlLib_IID_ITreeView;
extern const IID MSComctlLib_IID_IListView;
extern const IID MSComctlLib_IID_IImageList;
extern const IID MSComctlLib_IID_ISlider;
extern const IID MSComctlLib_IID_IImageCombo;
extern const IID MSComctlLib_IID_ITabStripEvents;
extern const IID MSComctlLib_IID_IToolbarEvents;
extern const IID MSComctlLib_IID_IStatusBarEvents;
extern const IID MSComctlLib_IID_IProgressBarEvents;
extern const IID MSComctlLib_IID_ITreeViewEvents;
extern const IID MSComctlLib_IID_ListViewEvents;
extern const IID MSComctlLib_IID_ISliderEvents;
extern const IID MSComctlLib_IID_DImageComboEvents;
extern const IID MSComctlLib_IID_IVBDataObject;
extern const IID MSComctlLib_IID_IVBDataObjectFiles;
extern const IID MSComctlLib_IID_ITabs;
extern const IID MSComctlLib_IID_ITab;
extern const IID MSComctlLib_IID_IButtons;
extern const IID MSComctlLib_IID_IButton;
extern const IID MSComctlLib_IID_IButtonMenus;
extern const IID MSComctlLib_IID_IButtonMenu;
extern const IID MSComctlLib_IID_IPanels;
extern const IID MSComctlLib_IID_IPanel;
extern const IID MSComctlLib_IID_INodes;
extern const IID MSComctlLib_IID_INode;
extern const IID MSComctlLib_IID_IListItems;
extern const IID MSComctlLib_IID_IListItem;
extern const IID MSComctlLib_IID_IColumnHeaders;
extern const IID MSComctlLib_IID_IColumnHeader;
extern const IID MSComctlLib_IID_IListSubItems;
extern const IID MSComctlLib_IID_IListSubItem;
extern const IID MSComctlLib_IID_IImages;
extern const IID MSComctlLib_IID_IImage;
extern const IID MSComctlLib_IID_IControls;
extern const IID MSComctlLib_IID_IComboItem;
extern const IID MSComctlLib_IID_IComboItems;

HRESULT CVIFUNC MSComctlLib_IVBDataObjectClear (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectGetData (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short sFormat, VARIANT *pvData);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectGetFormat (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    short sFormat,
                                                    VBOOL *pbFormatSupported);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectSetData (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT vValue,
                                                  VARIANT vFormat);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectGetFiles (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IVBDataObjectFiles *pFiles);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectFilesGetItem (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long lIndex,
                                                       char **bstrItem);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectFilesGetCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *plCount);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectFilesAdd (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *bstrFilename,
                                                   VARIANT vIndex);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectFilesClear (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectFilesRemove (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT vIndex);

HRESULT CVIFUNC MSComctlLib_IVBDataObjectFiles_NewEnum (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        LPUNKNOWN *ppUnk);

HRESULT CVIFUNC MSComctlLib_NewITabStrip (int panel, const char *label, int top,
                                          int left, int *controlID,
                                          int *UILError);

HRESULT CVIFUNC MSComctlLib_ITabStripGetTabs (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_ITabs *ppTabs);

HRESULT CVIFUNC MSComctlLib_ITabStripSetByRefTabs (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_ITabs ppTabs);

HRESULT CVIFUNC MSComctlLib_ITabStripGetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_ITabStripSetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_ITabStripGetFont (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_IFontDisp *ppFontDisp);

HRESULT CVIFUNC MSComctlLib_ITabStripSetByRefFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IFontDisp ppFontDisp);

HRESULT CVIFUNC MSComctlLib_ITabStripGethWnd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_ITabStripSethWnd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibType_OLE_HANDLE phWnd);

HRESULT CVIFUNC MSComctlLib_ITabStripGetMouseIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp *ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ITabStripSetMouseIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ITabStripSetByRefMouseIcon (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ITabStripGetMultiRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pbMultiRow);

HRESULT CVIFUNC MSComctlLib_ITabStripSetMultiRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL pbMultiRow);

HRESULT CVIFUNC MSComctlLib_ITabStripGetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum MSComctlLibEnum_TabStyleConstants *psStyle);

HRESULT CVIFUNC MSComctlLib_ITabStripSetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum MSComctlLibEnum_TabStyleConstants psStyle);

HRESULT CVIFUNC MSComctlLib_ITabStripGetTabFixedWidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       short *psTabFixedWidth);

HRESULT CVIFUNC MSComctlLib_ITabStripSetTabFixedWidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       short psTabFixedWidth);

HRESULT CVIFUNC MSComctlLib_ITabStripGetTabWidthStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_TabWidthStyleConstants *psTabWidthStyle);

HRESULT CVIFUNC MSComctlLib_ITabStripSetTabWidthStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_TabWidthStyleConstants psTabWidthStyle);

HRESULT CVIFUNC MSComctlLib_ITabStripGetClientTop (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   float *pfClientTop);

HRESULT CVIFUNC MSComctlLib_ITabStripSetClientTop (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   float pfClientTop);

HRESULT CVIFUNC MSComctlLib_ITabStripGetClientLeft (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    float *pfClientLeft);

HRESULT CVIFUNC MSComctlLib_ITabStripSetClientLeft (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    float pfClientLeft);

HRESULT CVIFUNC MSComctlLib_ITabStripGetClientHeight (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      float *pfClientHeight);

HRESULT CVIFUNC MSComctlLib_ITabStripSetClientHeight (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      float pfClientHeight);

HRESULT CVIFUNC MSComctlLib_ITabStripGetClientWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float *pfClientWidth);

HRESULT CVIFUNC MSComctlLib_ITabStripSetClientWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float pfClientWidth);

HRESULT CVIFUNC MSComctlLib_ITabStripGetMousePointer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_MousePointerConstants *psMousePointer);

HRESULT CVIFUNC MSComctlLib_ITabStripSetMousePointer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_MousePointerConstants psMousePointer);

HRESULT CVIFUNC MSComctlLib_ITabStripGetImageList (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle *ppImageList);

HRESULT CVIFUNC MSComctlLib_ITabStripSetImageList (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_ITabStripSetByRefImageList (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_ITabStripGetTabFixedHeight (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        short *psTabFixedHeight);

HRESULT CVIFUNC MSComctlLib_ITabStripSetTabFixedHeight (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        short psTabFixedHeight);

HRESULT CVIFUNC MSComctlLib_ITabStripGetShowTips (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pbShowTips);

HRESULT CVIFUNC MSComctlLib_ITabStripSetShowTips (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL pbShowTips);

HRESULT CVIFUNC MSComctlLib_ITabStripGetSelectedItem (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_ITab *ppSelectedItem);

HRESULT CVIFUNC MSComctlLib_ITabStripSetByRefSelectedItem (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           MSComctlLibObj_ITab ppSelectedItem);

HRESULT CVIFUNC MSComctlLib_ITabStripSetSelectedItem (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT ppSelectedItem);

HRESULT CVIFUNC MSComctlLib_ITabStripGetOLEDropMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_ITabStripSetOLEDropMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_ITabStripRefresh (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITabStripOLEDrag (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITabStripAboutBox (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITabStripGetHotTracking (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pbHotTracking);

HRESULT CVIFUNC MSComctlLib_ITabStripSetHotTracking (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pbHotTracking);

HRESULT CVIFUNC MSComctlLib_ITabStripGetMultiSelect (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pbMultiSelect);

HRESULT CVIFUNC MSComctlLib_ITabStripSetMultiSelect (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pbMultiSelect);

HRESULT CVIFUNC MSComctlLib_ITabStripGetPlacement (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_PlacementConstants *penumPlacement);

HRESULT CVIFUNC MSComctlLib_ITabStripSetPlacement (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_PlacementConstants penumPlacement);

HRESULT CVIFUNC MSComctlLib_ITabStripGetSeparators (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pbSeparators);

HRESULT CVIFUNC MSComctlLib_ITabStripSetSeparators (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pbSeparators);

HRESULT CVIFUNC MSComctlLib_ITabStripGetTabMinWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float *pflTabMinWidth);

HRESULT CVIFUNC MSComctlLib_ITabStripSetTabMinWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float pflTabMinWidth);

HRESULT CVIFUNC MSComctlLib_ITabStripGetTabStyle (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum MSComctlLibEnum_TabSelStyleConstants *penumTabStyle);

HRESULT CVIFUNC MSComctlLib_ITabStripSetTabStyle (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum MSComctlLibEnum_TabSelStyleConstants penumTabStyle);

HRESULT CVIFUNC MSComctlLib_ITabStripDeselectAll (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITabsGetCount (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, short *psCount);

HRESULT CVIFUNC MSComctlLib_ITabsSetCount (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, short psCount);

HRESULT CVIFUNC MSComctlLib_ITabsGetControlDefault (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pvIndex,
                                                    MSComctlLibObj_ITab *ppTab);

HRESULT CVIFUNC MSComctlLib_ITabsSetByRefControlDefault (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT pvIndex,
                                                         MSComctlLibObj_ITab ppTab);

HRESULT CVIFUNC MSComctlLib_ITabsGetItem (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT pvIndex,
                                          MSComctlLibObj_ITab *ppTab);

HRESULT CVIFUNC MSComctlLib_ITabsSetByRefItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT pvIndex,
                                               MSComctlLibObj_ITab ppTab);

HRESULT CVIFUNC MSComctlLib_ITabsRemove (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, VARIANT pvIndex);

HRESULT CVIFUNC MSComctlLib_ITabsClear (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITabsAdd (CAObjHandle objectHandle,
                                      ERRORINFO *errorInfo, VARIANT pvIndex,
                                      VARIANT pvKey, VARIANT pvCaption,
                                      VARIANT pvImage,
                                      MSComctlLibObj_ITab *ppTab);

HRESULT CVIFUNC MSComctlLib_ITabs_NewEnum (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           CAObjHandle *ppNewEnum);

HRESULT CVIFUNC MSComctlLib_ITabGet_ObjectDefault (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **pbstrCaption);

HRESULT CVIFUNC MSComctlLib_ITabSet_ObjectDefault (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *pbstrCaption);

HRESULT CVIFUNC MSComctlLib_ITabGetCaption (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            char **pbstrCaption);

HRESULT CVIFUNC MSComctlLib_ITabSetCaption (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            const char *pbstrCaption);

HRESULT CVIFUNC MSComctlLib_ITabGetTag (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_ITabSetTag (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_ITabGetIndex (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, short *psIndex);

HRESULT CVIFUNC MSComctlLib_ITabSetIndex (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, short psIndex);

HRESULT CVIFUNC MSComctlLib_ITabGetKey (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_ITabSetKey (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_ITabGetToolTipText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_ITabSetToolTipText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_ITabGetWidth (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, float *pfWidth);

HRESULT CVIFUNC MSComctlLib_ITabSetWidth (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, float pfWidth);

HRESULT CVIFUNC MSComctlLib_ITabGetHeight (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, float *pfHeight);

HRESULT CVIFUNC MSComctlLib_ITabSetHeight (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, float pfHeight);

HRESULT CVIFUNC MSComctlLib_ITabGetTop (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, float *pfTop);

HRESULT CVIFUNC MSComctlLib_ITabSetTop (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, float pfTop);

HRESULT CVIFUNC MSComctlLib_ITabGetLeft (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, float *pfLeft);

HRESULT CVIFUNC MSComctlLib_ITabSetLeft (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, float pfLeft);

HRESULT CVIFUNC MSComctlLib_ITabGetSelected (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL *pbSelected);

HRESULT CVIFUNC MSComctlLib_ITabSetSelected (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL pbSelected);

HRESULT CVIFUNC MSComctlLib_ITabGetImage (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT *pvImage);

HRESULT CVIFUNC MSComctlLib_ITabSetImage (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT pvImage);

HRESULT CVIFUNC MSComctlLib_ITabGetHighLighted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pbHighLighted);

HRESULT CVIFUNC MSComctlLib_ITabSetHighLighted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL pbHighLighted);

HRESULT CVIFUNC MSComctlLib_ITabSetByRefTag (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_NewIToolbar (int panel, const char *label, int top,
                                         int left, int *controlID, int *UILError);

HRESULT CVIFUNC MSComctlLib_IToolbarGetAppearance (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_AppearanceConstants *pnAppearance);

HRESULT CVIFUNC MSComctlLib_IToolbarSetAppearance (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_AppearanceConstants pnAppearance);

HRESULT CVIFUNC MSComctlLib_IToolbarGetAllowCustomize (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pbAllowCustomize);

HRESULT CVIFUNC MSComctlLib_IToolbarSetAllowCustomize (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pbAllowCustomize);

HRESULT CVIFUNC MSComctlLib_IToolbarGetButtons (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                MSComctlLibObj_IButtons *ppButtons);

HRESULT CVIFUNC MSComctlLib_IToolbarSetByRefButtons (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibObj_IButtons ppButtons);

HRESULT CVIFUNC MSComctlLib_IToolbarGetControls (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_IControls *ppControls);

HRESULT CVIFUNC MSComctlLib_IToolbarGetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_IToolbarSetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_IToolbarGethWnd (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_IToolbarSethWnd (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             MSComctlLibType_OLE_HANDLE phWnd);

HRESULT CVIFUNC MSComctlLib_IToolbarGetMouseIcon (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  MSComctlLibObj_IPictureDisp *ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IToolbarSetMouseIcon (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IToolbarSetByRefMouseIcon (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IToolbarGetMousePointer (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_MousePointerConstants *psMousePointer);

HRESULT CVIFUNC MSComctlLib_IToolbarSetMousePointer (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_MousePointerConstants psMousePointer);

HRESULT CVIFUNC MSComctlLib_IToolbarGetImageList (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CAObjHandle *ppImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarSetImageList (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarSetByRefImageList (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarGetShowTips (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *bShowTips);

HRESULT CVIFUNC MSComctlLib_IToolbarSetShowTips (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL bShowTips);

HRESULT CVIFUNC MSComctlLib_IToolbarGetBorderStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_BorderStyleConstants *psBorderStyle);

HRESULT CVIFUNC MSComctlLib_IToolbarSetBorderStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_BorderStyleConstants psBorderStyle);

HRESULT CVIFUNC MSComctlLib_IToolbarGetWrappable (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pbWrappable);

HRESULT CVIFUNC MSComctlLib_IToolbarSetWrappable (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL pbWrappable);

HRESULT CVIFUNC MSComctlLib_IToolbarGetButtonHeight (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float *pfButtonHeight);

HRESULT CVIFUNC MSComctlLib_IToolbarSetButtonHeight (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float pfButtonHeight);

HRESULT CVIFUNC MSComctlLib_IToolbarGetButtonWidth (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    float *pfButtonWidth);

HRESULT CVIFUNC MSComctlLib_IToolbarSetButtonWidth (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    float pfButtonWidth);

HRESULT CVIFUNC MSComctlLib_IToolbarGetHelpContextID (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *plHelpContextID);

HRESULT CVIFUNC MSComctlLib_IToolbarSetHelpContextID (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long plHelpContextID);

HRESULT CVIFUNC MSComctlLib_IToolbarGetHelpFile (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pbstrHelpFile);

HRESULT CVIFUNC MSComctlLib_IToolbarSetHelpFile (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pbstrHelpFile);

HRESULT CVIFUNC MSComctlLib_IToolbarGetOLEDropMode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IToolbarSetOLEDropMode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IToolbarRefresh (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IToolbarCustomize (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IToolbarSaveToolbar (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *key,
                                                 const char *subkey,
                                                 const char *value);

HRESULT CVIFUNC MSComctlLib_IToolbarRestoreToolbar (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *key,
                                                    const char *subkey,
                                                    const char *value);

HRESULT CVIFUNC MSComctlLib_IToolbarOLEDrag (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IToolbarAboutBox (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IToolbarGetDisabledImageList (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CAObjHandle *ppDisabledImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarSetDisabledImageList (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CAObjHandle ppDisabledImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarSetByRefDisabledImageList (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               CAObjHandle ppDisabledImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarGetHotImageList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CAObjHandle *ppHotImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarSetHotImageList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CAObjHandle ppHotImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarSetByRefHotImageList (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CAObjHandle ppHotImageList);

HRESULT CVIFUNC MSComctlLib_IToolbarGetStyle (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              enum MSComctlLibEnum_ToolbarStyleConstants *penumStyle);

HRESULT CVIFUNC MSComctlLib_IToolbarSetStyle (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              enum MSComctlLibEnum_ToolbarStyleConstants penumStyle);

HRESULT CVIFUNC MSComctlLib_IToolbarGetTextAlignment (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_ToolbarTextAlignConstants *penumTextAlignment);

HRESULT CVIFUNC MSComctlLib_IToolbarSetTextAlignment (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_ToolbarTextAlignConstants penumTextAlignment);

HRESULT CVIFUNC MSComctlLib_IButtonsGetCount (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              short *psCount);

HRESULT CVIFUNC MSComctlLib_IButtonsSetCount (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              short psCount);

HRESULT CVIFUNC MSComctlLib_IButtonsGetControlDefault (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT index,
                                                       MSComctlLibObj_IButton *ppButton);

HRESULT CVIFUNC MSComctlLib_IButtonsSetByRefControlDefault (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT index,
                                                            MSComctlLibObj_IButton ppButton);

HRESULT CVIFUNC MSComctlLib_IButtonsGetItem (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT index,
                                             MSComctlLibObj_IButton *ppButton);

HRESULT CVIFUNC MSComctlLib_IButtonsSetByRefItem (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT index,
                                                  MSComctlLibObj_IButton ppButton);

HRESULT CVIFUNC MSComctlLib_IButtonsRemove (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VARIANT index);

HRESULT CVIFUNC MSComctlLib_IButtonsClear (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IButtonsAdd (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, VARIANT index,
                                         VARIANT key, VARIANT caption,
                                         VARIANT style, VARIANT image,
                                         MSComctlLibObj_IButton *ppButton);

HRESULT CVIFUNC MSComctlLib_IButtons_NewEnum (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CAObjHandle *ppDispatch);

HRESULT CVIFUNC MSComctlLib_IButtonGet_ObjectDefault (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstr_ObjectDefault);

HRESULT CVIFUNC MSComctlLib_IButtonSet_ObjectDefault (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *pbstr_ObjectDefault);

HRESULT CVIFUNC MSComctlLib_IButtonGetCaption (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               char **pbstrCaption);

HRESULT CVIFUNC MSComctlLib_IButtonSetCaption (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *pbstrCaption);

HRESULT CVIFUNC MSComctlLib_IButtonGetTag (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IButtonSetTag (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IButtonGetEnabled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_IButtonSetEnabled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_IButtonGetIndex (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             short *psIndex);

HRESULT CVIFUNC MSComctlLib_IButtonSetIndex (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, short psIndex);

HRESULT CVIFUNC MSComctlLib_IButtonGetKey (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IButtonSetKey (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IButtonGetToolTipText (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IButtonSetToolTipText (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IButtonGetVisible (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL *pbVisible);

HRESULT CVIFUNC MSComctlLib_IButtonSetVisible (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL pbVisible);

HRESULT CVIFUNC MSComctlLib_IButtonGetWidth (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             float *pfWidth);

HRESULT CVIFUNC MSComctlLib_IButtonSetWidth (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, float pfWidth);

HRESULT CVIFUNC MSComctlLib_IButtonGetHeight (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              float *pfHeight);

HRESULT CVIFUNC MSComctlLib_IButtonSetHeight (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              float pfHeight);

HRESULT CVIFUNC MSComctlLib_IButtonGetTop (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, float *pfTop);

HRESULT CVIFUNC MSComctlLib_IButtonSetTop (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, float pfTop);

HRESULT CVIFUNC MSComctlLib_IButtonGetLeft (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, float *pfLeft);

HRESULT CVIFUNC MSComctlLib_IButtonSetLeft (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, float pfLeft);

HRESULT CVIFUNC MSComctlLib_IButtonGetValue (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             enum MSComctlLibEnum_ValueConstants *psValue);

HRESULT CVIFUNC MSComctlLib_IButtonSetValue (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             enum MSComctlLibEnum_ValueConstants psValue);

HRESULT CVIFUNC MSComctlLib_IButtonGetStyle (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             enum MSComctlLibEnum_ButtonStyleConstants *psStyle);

HRESULT CVIFUNC MSComctlLib_IButtonSetStyle (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             enum MSComctlLibEnum_ButtonStyleConstants psStyle);

HRESULT CVIFUNC MSComctlLib_IButtonGetDescription (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **pbstrDescription);

HRESULT CVIFUNC MSComctlLib_IButtonSetDescription (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *pbstrDescription);

HRESULT CVIFUNC MSComctlLib_IButtonGetImage (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VARIANT *pvImage);

HRESULT CVIFUNC MSComctlLib_IButtonSetImage (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VARIANT pvImage);

HRESULT CVIFUNC MSComctlLib_IButtonGetMixedState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pbMixedState);

HRESULT CVIFUNC MSComctlLib_IButtonSetMixedState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL pbMixedState);

HRESULT CVIFUNC MSComctlLib_IButtonGetButtonMenus (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IButtonMenus *ppButtonMenus);

HRESULT CVIFUNC MSComctlLib_IButtonSetByRefButtonMenus (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        MSComctlLibObj_IButtonMenus ppButtonMenus);

HRESULT CVIFUNC MSComctlLib_IButtonSetByRefTag (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IButtonMenusGetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short *psCount);

HRESULT CVIFUNC MSComctlLib_IButtonMenusSetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short psCount);

HRESULT CVIFUNC MSComctlLib_IButtonMenusGetControlDefault (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VARIANT index,
                                                           MSComctlLibObj_IButtonMenu *ppButtonMenu);

HRESULT CVIFUNC MSComctlLib_IButtonMenusSetByRefControlDefault (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT index,
                                                                MSComctlLibObj_IButtonMenu ppButtonMenu);

HRESULT CVIFUNC MSComctlLib_IButtonMenusGetItem (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT index,
                                                 MSComctlLibObj_IButtonMenu *ppButtonMenu);

HRESULT CVIFUNC MSComctlLib_IButtonMenusSetByRefItem (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT index,
                                                      MSComctlLibObj_IButtonMenu ppButtonMenu);

HRESULT CVIFUNC MSComctlLib_IButtonMenusRemove (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT index);

HRESULT CVIFUNC MSComctlLib_IButtonMenusClear (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IButtonMenusAdd (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT index,
                                             VARIANT key, VARIANT text,
                                             MSComctlLibObj_IButtonMenu *ppButtonMenu);

HRESULT CVIFUNC MSComctlLib_IButtonMenus_NewEnum (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CAObjHandle *ppDispatch);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGet_ObjectDefault (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrObjectDefault);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSet_ObjectDefault (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pbstrObjectDefault);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGetIndex (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short *psIndex);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSetIndex (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short psIndex);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGetKey (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSetKey (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGetParent (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  MSComctlLibObj_IButton *ppParent);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSetByRefParent (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       MSComctlLibObj_IButton ppParent);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGetTag (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSetTag (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGetText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSetText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IButtonMenuGetVisible (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pbVisible);

HRESULT CVIFUNC MSComctlLib_IButtonMenuSetVisible (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pbVisible);

HRESULT CVIFUNC MSComctlLib_NewIStatusBar (int panel, const char *label, int top,
                                           int left, int *controlID,
                                           int *UILError);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetSimpleText (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrSimpleText);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetSimpleText (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrSimpleText);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetStyle (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                enum MSComctlLibEnum_SbarStyleConstants *psStyle);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetStyle (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                enum MSComctlLibEnum_SbarStyleConstants psStyle);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetPanels (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_IPanels *ppPanels);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetByRefPanels (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IPanels ppPanels);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetMousePointer (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_MousePointerConstants *psMousePointer);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetMousePointer (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_MousePointerConstants psMousePointer);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetMouseIcon (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibObj_IPictureDisp *ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetMouseIcon (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetByRefMouseIcon (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetShowTips (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *bShowTips);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetShowTips (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL bShowTips);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetPanelProperties (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrPanelProperties);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetPanelProperties (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pbstrPanelProperties);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetOLEDropMode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetOLEDropMode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetEnabled (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetEnabled (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_IStatusBarGetFont (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibObj_IFontDisp *ppFont);

HRESULT CVIFUNC MSComctlLib_IStatusBarSetByRefFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibObj_IFontDisp ppFont);

HRESULT CVIFUNC MSComctlLib_IStatusBarGethWnd (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_IStatusBarSethWnd (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibType_OLE_HANDLE phWnd);

HRESULT CVIFUNC MSComctlLib_IStatusBarRefresh (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IStatusBarOLEDrag (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IStatusBarAboutBox (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IPanelsGetCount (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, short *sCount);

HRESULT CVIFUNC MSComctlLib_IPanelsSetCount (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, short sCount);

HRESULT CVIFUNC MSComctlLib_IPanelsGetControlDefault (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT index,
                                                      MSComctlLibObj_IPanel *ppPanel);

HRESULT CVIFUNC MSComctlLib_IPanelsSetByRefControlDefault (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VARIANT index,
                                                           MSComctlLibObj_IPanel ppPanel);

HRESULT CVIFUNC MSComctlLib_IPanelsAdd (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, VARIANT index,
                                        VARIANT key, VARIANT text, VARIANT style,
                                        VARIANT picture,
                                        MSComctlLibObj_IPanel *ppPanel);

HRESULT CVIFUNC MSComctlLib_IPanelsClear (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IPanelsGetItem (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VARIANT index,
                                            MSComctlLibObj_IPanel *ppPanel);

HRESULT CVIFUNC MSComctlLib_IPanelsSetByRefItem (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT index,
                                                 MSComctlLibObj_IPanel ppPanel);

HRESULT CVIFUNC MSComctlLib_IPanelsRemove (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT index);

HRESULT CVIFUNC MSComctlLib_IPanels_NewEnum (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             CAObjHandle *ppNewEnum);

HRESULT CVIFUNC MSComctlLib_IPanelGet_ObjectDefault (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IPanelSet_ObjectDefault (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IPanelGetAlignment (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                enum MSComctlLibEnum_PanelAlignmentConstants *psAlignment);

HRESULT CVIFUNC MSComctlLib_IPanelSetAlignment (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                enum MSComctlLibEnum_PanelAlignmentConstants psAlignment);

HRESULT CVIFUNC MSComctlLib_IPanelGetAutoSize (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum MSComctlLibEnum_PanelAutoSizeConstants *psAutoSize);

HRESULT CVIFUNC MSComctlLib_IPanelSetAutoSize (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum MSComctlLibEnum_PanelAutoSizeConstants psAutoSize);

HRESULT CVIFUNC MSComctlLib_IPanelGetBevel (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum MSComctlLibEnum_PanelBevelConstants *psBevel);

HRESULT CVIFUNC MSComctlLib_IPanelSetBevel (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum MSComctlLibEnum_PanelBevelConstants psBevel);

HRESULT CVIFUNC MSComctlLib_IPanelGetEnabled (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_IPanelSetEnabled (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_IPanelGetIndex (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, short *sIndex);

HRESULT CVIFUNC MSComctlLib_IPanelSetIndex (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, short sIndex);

HRESULT CVIFUNC MSComctlLib_IPanelGetKey (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IPanelSetKey (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IPanelGetLeft (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, float *pfLeft);

HRESULT CVIFUNC MSComctlLib_IPanelSetLeft (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, float pfLeft);

HRESULT CVIFUNC MSComctlLib_IPanelGetMinWidth (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               float *pfMinWidth);

HRESULT CVIFUNC MSComctlLib_IPanelSetMinWidth (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               float pfMinWidth);

HRESULT CVIFUNC MSComctlLib_IPanelGetPicture (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_IPictureDisp *ppPicture);

HRESULT CVIFUNC MSComctlLib_IPanelSetByRefPicture (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp ppPicture);

HRESULT CVIFUNC MSComctlLib_IPanelGetStyle (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum MSComctlLibEnum_PanelStyleConstants *psStyle);

HRESULT CVIFUNC MSComctlLib_IPanelSetStyle (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum MSComctlLibEnum_PanelStyleConstants psStyle);

HRESULT CVIFUNC MSComctlLib_IPanelGetTag (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IPanelSetTag (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IPanelGetText (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IPanelSetText (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IPanelGetToolTipText (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IPanelSetToolTipText (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IPanelGetVisible (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL *pbVisible);

HRESULT CVIFUNC MSComctlLib_IPanelSetVisible (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL pbVisible);

HRESULT CVIFUNC MSComctlLib_IPanelGetWidth (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, float *pfWidth);

HRESULT CVIFUNC MSComctlLib_IPanelSetWidth (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, float pfWidth);

HRESULT CVIFUNC MSComctlLib_IPanelSetPicture (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_IPictureDisp ppPicture);

HRESULT CVIFUNC MSComctlLib_IPanelSetByRefTag (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_NewIProgressBar (int panel, const char *label,
                                             int top, int left, int *controlID,
                                             int *UILError);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetControlDefault (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           float *pfValue);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetControlDefault (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           float pfValue);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetMax (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                float *pfMax);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetMax (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                float pfMax);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetMin (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                float *pfMin);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetMin (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                float pfMin);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetMousePointer (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MSComctlLibEnum_MousePointerConstants *pMousePointers);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetMousePointer (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MSComctlLibEnum_MousePointerConstants pMousePointers);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetMouseIcon (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IPictureDisp *ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetByRefMouseIcon (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           MSComctlLibObj_IPictureDisp ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetMouseIcon (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IPictureDisp ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  float *pfValue);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  float pfValue);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetOLEDropMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetOLEDropMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetAppearance (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_AppearanceConstants *penumAppearances);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetAppearance (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_AppearanceConstants penumAppearances);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetBorderStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_BorderStyleConstants *penumBorderStyles);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetBorderStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_BorderStyleConstants penumBorderStyles);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *bEnabled);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL bEnabled);

HRESULT CVIFUNC MSComctlLib_IProgressBarGethWnd (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_IProgressBarOLEDrag (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IProgressBarAboutBox (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetOrientation (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_OrientationConstants *penumOrientation);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetOrientation (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_OrientationConstants penumOrientation);

HRESULT CVIFUNC MSComctlLib_IProgressBarGetScrolling (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_ScrollingConstants *penumScrolling);

HRESULT CVIFUNC MSComctlLib_IProgressBarSetScrolling (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_ScrollingConstants penumScrolling);

HRESULT CVIFUNC MSComctlLib_IProgressBarRefresh (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_NewITreeView (int panel, const char *label, int top,
                                          int left, int *controlID,
                                          int *UILError);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetDropHighlight (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       MSComctlLibObj_INode *ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetByRefDropHighlight (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            MSComctlLibObj_INode ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetDropHighlight (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetHideSelection (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pbHideSelection);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetHideSelection (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pbHideSelection);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetImageList (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle *ppImageList);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetByRefImageList (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetImageList (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetIndentation (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float *pfIndentation);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetIndentation (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     float pfIndentation);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetLabelEdit (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_LabelEditConstants *psLabelEdit);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetLabelEdit (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_LabelEditConstants psLabelEdit);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetLineStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_TreeLineStyleConstants *psLineStyle);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetLineStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_TreeLineStyleConstants psLineStyle);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetMousePointer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_MousePointerConstants *psMousePointer);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetMousePointer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_MousePointerConstants psMousePointer);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetMouseIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp *ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetMouseIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetByRefMouseIcon (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetNodes (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibObj_INodes *ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetByRefNodes (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibObj_INodes ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetPathSeparator (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pbstrPathSeparator);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetPathSeparator (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *pbstrPathSeparator);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetSelectedItem (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_INode *ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetByRefSelectedItem (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           MSComctlLibObj_INode ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetSelectedItem (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetSorted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pbSorted);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetSorted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL pbSorted);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum MSComctlLibEnum_TreeStyleConstants *psStyle);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum MSComctlLibEnum_TreeStyleConstants psStyle);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetOLEDragMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDragConstants *psOLEDragMode);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetOLEDragMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDragConstants psOLEDragMode);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetOLEDropMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetOLEDropMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetAppearance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_AppearanceConstants *psAppearance);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetAppearance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_AppearanceConstants psAppearance);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetBorderStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_BorderStyleConstants *psBorderStyle);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetBorderStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_BorderStyleConstants psBorderStyle);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetFont (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_IFontDisp *ppFont);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetFont (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_IFontDisp ppFont);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetByRefFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IFontDisp ppFont);

HRESULT CVIFUNC MSComctlLib_ITreeViewGethWnd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_ITreeViewSethWnd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibType_OLE_HANDLE phWnd);

HRESULT CVIFUNC MSComctlLib_ITreeViewHitTest (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, float x,
                                              float y,
                                              MSComctlLibObj_INode *ppNode);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetVisibleCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *plVisibleCount);

HRESULT CVIFUNC MSComctlLib_ITreeViewStartLabelEdit (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITreeViewRefresh (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITreeViewAboutBox (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITreeViewOLEDrag (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetCheckboxes (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pbCheckboxes);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetCheckboxes (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pbCheckboxes);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetFullRowSelect (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pbFullRowSelect);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetFullRowSelect (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pbFullRowSelect);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetHotTracking (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pbHotTracking);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetHotTracking (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pbHotTracking);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetScroll (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pbScroll);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetScroll (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL pbScroll);

HRESULT CVIFUNC MSComctlLib_ITreeViewGetSingleSel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pbSingleSel);

HRESULT CVIFUNC MSComctlLib_ITreeViewSetSingleSel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pbSingleSel);

HRESULT CVIFUNC MSComctlLib_INodesGetCount (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, short *psCount);

HRESULT CVIFUNC MSComctlLib_INodesSetCount (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, short psCount);

HRESULT CVIFUNC MSComctlLib_INodesGetControlDefault (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT index,
                                                     MSComctlLibObj_INode *ppNode);

HRESULT CVIFUNC MSComctlLib_INodesSetControlDefault (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT index,
                                                     MSComctlLibObj_INode ppNode);

HRESULT CVIFUNC MSComctlLib_INodesAdd (CAObjHandle objectHandle,
                                       ERRORINFO *errorInfo, VARIANT relative,
                                       VARIANT relationship, VARIANT key,
                                       VARIANT text, VARIANT image,
                                       VARIANT selectedImage,
                                       MSComctlLibObj_INode *ppNode);

HRESULT CVIFUNC MSComctlLib_INodesClear (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_INodesGetItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT index,
                                           MSComctlLibObj_INode *ppNode);

HRESULT CVIFUNC MSComctlLib_INodesSetItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT index,
                                           MSComctlLibObj_INode ppNode);

HRESULT CVIFUNC MSComctlLib_INodesRemove (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT index);

HRESULT CVIFUNC MSComctlLib_INodes_NewEnum (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            CAObjHandle *ppNewEnum);

HRESULT CVIFUNC MSComctlLib_INodeGet_ObjectDefault (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pbstrText);

HRESULT CVIFUNC MSComctlLib_INodeSet_ObjectDefault (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_INodeGetChild (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           MSComctlLibObj_INode *ppChild);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefChild (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                MSComctlLibObj_INode ppChild);

HRESULT CVIFUNC MSComctlLib_INodeGetChildren (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              short *psChildren);

HRESULT CVIFUNC MSComctlLib_INodeSetChildren (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              short psChildren);

HRESULT CVIFUNC MSComctlLib_INodeGetExpanded (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL *pbExpanded);

HRESULT CVIFUNC MSComctlLib_INodeSetExpanded (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL pbExpanded);

HRESULT CVIFUNC MSComctlLib_INodeGetExpandedImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *pExpandedImage);

HRESULT CVIFUNC MSComctlLib_INodeSetExpandedImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT pExpandedImage);

HRESULT CVIFUNC MSComctlLib_INodeGetFirstSibling (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  MSComctlLibObj_INode *ppFirstSibling);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefFirstSibling (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       MSComctlLibObj_INode ppFirstSibling);

HRESULT CVIFUNC MSComctlLib_INodeGetFullPath (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              char **pbstrFullPath);

HRESULT CVIFUNC MSComctlLib_INodeSetFullPath (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *pbstrFullPath);

HRESULT CVIFUNC MSComctlLib_INodeGetImage (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT *pImage);

HRESULT CVIFUNC MSComctlLib_INodeSetImage (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT pImage);

HRESULT CVIFUNC MSComctlLib_INodeGetIndex (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, short *psIndex);

HRESULT CVIFUNC MSComctlLib_INodeSetIndex (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, short psIndex);

HRESULT CVIFUNC MSComctlLib_INodeGetKey (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_INodeSetKey (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo,
                                         const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_INodeGetLastSibling (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_INode *ppLastSibling);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefLastSibling (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_INode ppLastSibling);

HRESULT CVIFUNC MSComctlLib_INodeGetNext (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          MSComctlLibObj_INode *ppNext);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefNext (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibObj_INode ppNext);

HRESULT CVIFUNC MSComctlLib_INodeGetParent (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            MSComctlLibObj_INode *ppParent);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefParent (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_INode ppParent);

HRESULT CVIFUNC MSComctlLib_INodeGetPrevious (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_INode *ppPrevious);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefPrevious (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_INode ppPrevious);

HRESULT CVIFUNC MSComctlLib_INodeGetRoot (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          MSComctlLibObj_INode *ppRoot);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefRoot (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibObj_INode ppRoot);

HRESULT CVIFUNC MSComctlLib_INodeGetSelected (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL *pbSelected);

HRESULT CVIFUNC MSComctlLib_INodeSetSelected (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL pbSelected);

HRESULT CVIFUNC MSComctlLib_INodeGetSelectedImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *pSelectedImage);

HRESULT CVIFUNC MSComctlLib_INodeSetSelectedImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT pSelectedImage);

HRESULT CVIFUNC MSComctlLib_INodeGetSorted (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            VBOOL *pbSorted);

HRESULT CVIFUNC MSComctlLib_INodeSetSorted (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VBOOL pbSorted);

HRESULT CVIFUNC MSComctlLib_INodeGetTag (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_INodeSetTag (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_INodeGetText (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, char **bstrText);

HRESULT CVIFUNC MSComctlLib_INodeSetText (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          const char *bstrText);

HRESULT CVIFUNC MSComctlLib_INodeGetVisible (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL *pbVisible);

HRESULT CVIFUNC MSComctlLib_INodeSetVisible (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL pbVisible);

HRESULT CVIFUNC MSComctlLib_INodeCreateDragImage (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  MSComctlLibObj_IPictureDisp *ppDragImage);

HRESULT CVIFUNC MSComctlLib_INodeEnsureVisible (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pbEnsureVisible);

HRESULT CVIFUNC MSComctlLib_INodeGetBackColor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibType_OLE_COLOR *pocBackColor);

HRESULT CVIFUNC MSComctlLib_INodeSetBackColor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibType_OLE_COLOR pocBackColor);

HRESULT CVIFUNC MSComctlLib_INodeGetBold (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VBOOL *pbBold);

HRESULT CVIFUNC MSComctlLib_INodeSetBold (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VBOOL pbBold);

HRESULT CVIFUNC MSComctlLib_INodeGetChecked (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL *pbChecked);

HRESULT CVIFUNC MSComctlLib_INodeSetChecked (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL pbChecked);

HRESULT CVIFUNC MSComctlLib_INodeGetForeColor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibType_OLE_COLOR *pocForeColor);

HRESULT CVIFUNC MSComctlLib_INodeSetForeColor (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibType_OLE_COLOR pocForeColor);

HRESULT CVIFUNC MSComctlLib_INodeSetByRefTag (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_NewIListView (int panel, const char *label, int top,
                                          int left, int *controlID,
                                          int *UILError);

HRESULT CVIFUNC MSComctlLib_IListViewGetArrange (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum MSComctlLibEnum_ListArrangeConstants *pArrange);

HRESULT CVIFUNC MSComctlLib_IListViewSetArrange (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum MSComctlLibEnum_ListArrangeConstants pArrange);

HRESULT CVIFUNC MSComctlLib_IListViewGetColumnHeaders (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       MSComctlLibObj_IColumnHeaders *ppIColumnHeaders);

HRESULT CVIFUNC MSComctlLib_IListViewSetColumnHeaders (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       MSComctlLibObj_IColumnHeaders ppIColumnHeaders);

HRESULT CVIFUNC MSComctlLib_IListViewGetDropHighlight (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       MSComctlLibObj_IListItem *ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefDropHighlight (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            MSComctlLibObj_IListItem ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListViewSetDropHighlight (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListViewGetHideColumnHeaders (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pfHide);

HRESULT CVIFUNC MSComctlLib_IListViewSetHideColumnHeaders (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pfHide);

HRESULT CVIFUNC MSComctlLib_IListViewGetHideSelection (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pfHide);

HRESULT CVIFUNC MSComctlLib_IListViewSetHideSelection (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pfHide);

HRESULT CVIFUNC MSComctlLib_IListViewGetIcons (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CAObjHandle *ppIcons);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefIcons (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CAObjHandle ppIcons);

HRESULT CVIFUNC MSComctlLib_IListViewSetIcons (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CAObjHandle ppIcons);

HRESULT CVIFUNC MSComctlLib_IListViewGetListItems (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IListItems *ppListItems);

HRESULT CVIFUNC MSComctlLib_IListViewSetListItems (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IListItems ppListItems);

HRESULT CVIFUNC MSComctlLib_IListViewGetLabelEdit (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_ListLabelEditConstants *pRet);

HRESULT CVIFUNC MSComctlLib_IListViewSetLabelEdit (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_ListLabelEditConstants pRet);

HRESULT CVIFUNC MSComctlLib_IListViewGetLabelWrap (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pfOn);

HRESULT CVIFUNC MSComctlLib_IListViewSetLabelWrap (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pfOn);

HRESULT CVIFUNC MSComctlLib_IListViewGetMouseIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp *ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IListViewSetMouseIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefMouseIcon (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IListViewGetMousePointer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_MousePointerConstants *pnIndex);

HRESULT CVIFUNC MSComctlLib_IListViewSetMousePointer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MSComctlLibEnum_MousePointerConstants pnIndex);

HRESULT CVIFUNC MSComctlLib_IListViewGetMultiSelect (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pfOn);

HRESULT CVIFUNC MSComctlLib_IListViewSetMultiSelect (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pfOn);

HRESULT CVIFUNC MSComctlLib_IListViewGetSelectedItem (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IListItem *ppListItem);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefSelectedItem (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           MSComctlLibObj_IListItem ppListItem);

HRESULT CVIFUNC MSComctlLib_IListViewSetSelectedItem (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT ppListItem);

HRESULT CVIFUNC MSComctlLib_IListViewGetSmallIcons (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CAObjHandle *ppImageList);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefSmallIcons (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IListViewSetSmallIcons (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IListViewGetSorted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pfOn);

HRESULT CVIFUNC MSComctlLib_IListViewSetSorted (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, VBOOL pfOn);

HRESULT CVIFUNC MSComctlLib_IListViewGetSortKey (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short *psKey);

HRESULT CVIFUNC MSComctlLib_IListViewSetSortKey (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short psKey);

HRESULT CVIFUNC MSComctlLib_IListViewGetSortOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_ListSortOrderConstants *pOrder);

HRESULT CVIFUNC MSComctlLib_IListViewSetSortOrder (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_ListSortOrderConstants pOrder);

HRESULT CVIFUNC MSComctlLib_IListViewGetView (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              enum MSComctlLibEnum_ListViewConstants *pnView);

HRESULT CVIFUNC MSComctlLib_IListViewSetView (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              enum MSComctlLibEnum_ListViewConstants pnView);

HRESULT CVIFUNC MSComctlLib_IListViewGetOLEDragMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDragConstants *psOLEDragMode);

HRESULT CVIFUNC MSComctlLib_IListViewSetOLEDragMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDragConstants psOLEDragMode);

HRESULT CVIFUNC MSComctlLib_IListViewGetOLEDropMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IListViewSetOLEDropMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IListViewGetAppearance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_AppearanceConstants *pnAppearance);

HRESULT CVIFUNC MSComctlLib_IListViewSetAppearance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_AppearanceConstants pnAppearance);

HRESULT CVIFUNC MSComctlLib_IListViewGetBackColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibType_OLE_COLOR *pcrBack);

HRESULT CVIFUNC MSComctlLib_IListViewSetBackColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibType_OLE_COLOR pcrBack);

HRESULT CVIFUNC MSComctlLib_IListViewGetBorderStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_BorderStyleConstants *pnStyle);

HRESULT CVIFUNC MSComctlLib_IListViewSetBorderStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MSComctlLibEnum_BorderStyleConstants pnStyle);

HRESULT CVIFUNC MSComctlLib_IListViewGetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *pfEnabled);

HRESULT CVIFUNC MSComctlLib_IListViewSetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL pfEnabled);

HRESULT CVIFUNC MSComctlLib_IListViewGetFont (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_IFontDisp *ppFontDisp);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IFontDisp ppFontDisp);

HRESULT CVIFUNC MSComctlLib_IListViewGetForeColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibType_OLE_COLOR *pcrFore);

HRESULT CVIFUNC MSComctlLib_IListViewSetForeColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibType_OLE_COLOR pcrFore);

HRESULT CVIFUNC MSComctlLib_IListViewGethWnd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_IListViewSethWnd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibType_OLE_HANDLE phWnd);

HRESULT CVIFUNC MSComctlLib_IListViewFindItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *sz, VARIANT where,
                                               VARIANT index, VARIANT fPartial,
                                               MSComctlLibObj_IListItem *ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListViewGetFirstVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IListItem *ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListViewHitTest (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, float x,
                                              float y,
                                              MSComctlLibObj_IListItem *ppListItem);

HRESULT CVIFUNC MSComctlLib_IListViewStartLabelEdit (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IListViewOLEDrag (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IListViewRefresh (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IListViewAboutBox (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IListViewGetAllowColumnReorder (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pfAllowColumnReorder);

HRESULT CVIFUNC MSComctlLib_IListViewSetAllowColumnReorder (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pfAllowColumnReorder);

HRESULT CVIFUNC MSComctlLib_IListViewGetCheckboxes (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pfCheckboxes);

HRESULT CVIFUNC MSComctlLib_IListViewSetCheckboxes (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pfCheckboxes);

HRESULT CVIFUNC MSComctlLib_IListViewGetFlatScrollBar (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pfFlatScrollBar);

HRESULT CVIFUNC MSComctlLib_IListViewSetFlatScrollBar (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pfFlatScrollBar);

HRESULT CVIFUNC MSComctlLib_IListViewGetFullRowSelect (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pfFullRowSelect);

HRESULT CVIFUNC MSComctlLib_IListViewSetFullRowSelect (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pfFullRowSelect);

HRESULT CVIFUNC MSComctlLib_IListViewGetGridLines (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pfGridLines);

HRESULT CVIFUNC MSComctlLib_IListViewSetGridLines (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pfGridLines);

HRESULT CVIFUNC MSComctlLib_IListViewGetHotTracking (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pfHotTracking);

HRESULT CVIFUNC MSComctlLib_IListViewSetHotTracking (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pfHotTracking);

HRESULT CVIFUNC MSComctlLib_IListViewGetHoverSelection (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pfHoverSelection);

HRESULT CVIFUNC MSComctlLib_IListViewSetHoverSelection (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pfHoverSelection);

HRESULT CVIFUNC MSComctlLib_IListViewGetPicture (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_IPictureDisp *ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IListViewSetPicture (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_IPictureDisp ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefPicture (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IPictureDisp ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IListViewGetPictureAlignment (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum MSComctlLibEnum_ListPictureAlignmentConstants *psAlignment);

HRESULT CVIFUNC MSComctlLib_IListViewSetPictureAlignment (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum MSComctlLibEnum_ListPictureAlignmentConstants psAlignment);

HRESULT CVIFUNC MSComctlLib_IListViewGetColumnHeaderIcons (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CAObjHandle *ppImageList);

HRESULT CVIFUNC MSComctlLib_IListViewSetByRefColumnHeaderIcons (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IListViewSetColumnHeaderIcons (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IListViewGetTextBackground (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_ListTextBackgroundConstants *penumTextBackground);

HRESULT CVIFUNC MSComctlLib_IListViewSetTextBackground (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_ListTextBackgroundConstants penumTextBackground);

HRESULT CVIFUNC MSComctlLib_IListItemsGetCount (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long *plCount);

HRESULT CVIFUNC MSComctlLib_IListItemsSetCount (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long plCount);

HRESULT CVIFUNC MSComctlLib_IListItemsGetControlDefault (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT index,
                                                         MSComctlLibObj_IListItem *ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListItemsAdd (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT index,
                                           VARIANT key, VARIANT text,
                                           VARIANT icon, VARIANT smallIcon,
                                           MSComctlLibObj_IListItem *ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListItemsClear (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IListItemsGetItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT index,
                                               MSComctlLibObj_IListItem *ppIListItem);

HRESULT CVIFUNC MSComctlLib_IListItemsRemove (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT index);

HRESULT CVIFUNC MSComctlLib_IListItems_NewEnum (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                LPUNKNOWN *ppNewEnum);

HRESULT CVIFUNC MSComctlLib_IListItemGetDefault (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IListItemSetDefault (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IListItemGetText (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IListItemSetText (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IListItemGetGhosted (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *pfOn);

HRESULT CVIFUNC MSComctlLib_IListItemSetGhosted (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL pfOn);

HRESULT CVIFUNC MSComctlLib_IListItemGetHeight (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                float *pflHeight);

HRESULT CVIFUNC MSComctlLib_IListItemSetHeight (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                float pflHeight);

HRESULT CVIFUNC MSComctlLib_IListItemGetIcon (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT *pnIndex);

HRESULT CVIFUNC MSComctlLib_IListItemSetIcon (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT pnIndex);

HRESULT CVIFUNC MSComctlLib_IListItemGetIndex (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long *plIndex);

HRESULT CVIFUNC MSComctlLib_IListItemSetIndex (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long plIndex);

HRESULT CVIFUNC MSComctlLib_IListItemGetKey (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IListItemSetKey (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IListItemGetLeft (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              float *pflLeft);

HRESULT CVIFUNC MSComctlLib_IListItemSetLeft (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              float pflLeft);

HRESULT CVIFUNC MSComctlLib_IListItemGetSelected (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pfOn);

HRESULT CVIFUNC MSComctlLib_IListItemSetSelected (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL pfOn);

HRESULT CVIFUNC MSComctlLib_IListItemGetSmallIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *pnIndex);

HRESULT CVIFUNC MSComctlLib_IListItemSetSmallIcon (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT pnIndex);

HRESULT CVIFUNC MSComctlLib_IListItemGetTag (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IListItemSetTag (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IListItemGetTop (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, float *pflTop);

HRESULT CVIFUNC MSComctlLib_IListItemSetTop (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, float pflTop);

HRESULT CVIFUNC MSComctlLib_IListItemGetWidth (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               float *pflWidth);

HRESULT CVIFUNC MSComctlLib_IListItemSetWidth (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               float pflWidth);

HRESULT CVIFUNC MSComctlLib_IListItemGetSubItems (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short index, char **pbstrItem);

HRESULT CVIFUNC MSComctlLib_IListItemSetSubItems (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short index,
                                                  const char *pbstrItem);

HRESULT CVIFUNC MSComctlLib_IListItemCreateDragImage (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IPictureDisp *ppImage);

HRESULT CVIFUNC MSComctlLib_IListItemEnsureVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pfVisible);

HRESULT CVIFUNC MSComctlLib_IListItemSetByRefTag (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IListItemGetListSubItems (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IListSubItems *ppSubItems);

HRESULT CVIFUNC MSComctlLib_IListItemSetListSubItems (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IListSubItems ppSubItems);

HRESULT CVIFUNC MSComctlLib_IListItemGetChecked (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *pfChecked);

HRESULT CVIFUNC MSComctlLib_IListItemSetChecked (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL pfChecked);

HRESULT CVIFUNC MSComctlLib_IListItemGetForeColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibType_OLE_COLOR *pcrFore);

HRESULT CVIFUNC MSComctlLib_IListItemSetForeColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibType_OLE_COLOR pcrFore);

HRESULT CVIFUNC MSComctlLib_IListItemGetToolTipText (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IListItemSetToolTipText (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IListItemGetBold (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VBOOL *pfBold);

HRESULT CVIFUNC MSComctlLib_IListItemSetBold (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VBOOL pfBold);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersGetCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *plCount);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersSetCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long plCount);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersGetControlDefault (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT index,
                                                             MSComctlLibObj_IColumnHeader *ppIColumnHeader);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersAdd_PreVB98 (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT index,
                                                       VARIANT key, VARIANT text,
                                                       VARIANT width,
                                                       VARIANT alignment,
                                                       MSComctlLibObj_IColumnHeader *ppIColumnHeader);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersClear (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersGetItem (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT index,
                                                   MSComctlLibObj_IColumnHeader *ppIColumnHeader);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersRemove (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT index);

HRESULT CVIFUNC MSComctlLib_IColumnHeaders_NewEnum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    LPUNKNOWN *ppUnknown);

HRESULT CVIFUNC MSComctlLib_IColumnHeadersAdd (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT index, VARIANT key,
                                               VARIANT text, VARIANT width,
                                               VARIANT alignment, VARIANT icon,
                                               MSComctlLibObj_IColumnHeader *ppIColumnHeader);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetDefault (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetDefault (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetText (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetText (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_ListColumnAlignmentConstants *pnAlignment);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetAlignment (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_ListColumnAlignmentConstants pnAlignment);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetIndex (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *plIndex);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetIndex (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long plIndex);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetKey (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetKey (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetLeft (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  float *pflLeft);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetLeft (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  float pflLeft);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetSubItemIndex (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          short *psIndex);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetSubItemIndex (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          short psIndex);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetTag (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetTag (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   float *pflWidth);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   float pflWidth);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetByRefTag (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetIcon (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT *pnIndex);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetIcon (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT pnIndex);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderGetPosition (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short *piPosition);

HRESULT CVIFUNC MSComctlLib_IColumnHeaderSetPosition (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short piPosition);

HRESULT CVIFUNC MSComctlLib_IListSubItemsGetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *plCount);

HRESULT CVIFUNC MSComctlLib_IListSubItemsSetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long plCount);

HRESULT CVIFUNC MSComctlLib_IListSubItemsGetControlDefault (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT index,
                                                            MSComctlLibObj_IListSubItem *ppIListSubItem);

HRESULT CVIFUNC MSComctlLib_IListSubItemsAdd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT index, VARIANT key,
                                              VARIANT text, VARIANT reportIcon,
                                              VARIANT toolTipText,
                                              MSComctlLibObj_IListSubItem *ppIListSubItem);

HRESULT CVIFUNC MSComctlLib_IListSubItemsClear (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IListSubItemsGetItem (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT index,
                                                  MSComctlLibObj_IListSubItem *ppIListSubItem);

HRESULT CVIFUNC MSComctlLib_IListSubItemsRemove (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT index);

HRESULT CVIFUNC MSComctlLib_IListSubItems_NewEnum (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   LPUNKNOWN *ppNewEnum);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetDefault (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetDefault (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetText (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetText (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetForeColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibType_OLE_COLOR *pcrFore);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetForeColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibType_OLE_COLOR pcrFore);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetBold (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *pfBold);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetBold (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL pfBold);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetReportIcon (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT *pnIndex);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetReportIcon (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT pnIndex);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetToolTipText (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetToolTipText (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *pbstrToolTipText);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetIndex (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *plIndex);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetIndex (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long plIndex);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetKey (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetKey (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IListSubItemGetTag (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetTag (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IListSubItemSetByRefTag (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_NewIImageList (int panel, const char *label, int top,
                                           int left, int *controlID,
                                           int *UILError);

HRESULT CVIFUNC MSComctlLib_IImageListGetImageHeight (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short *psImageHeight);

HRESULT CVIFUNC MSComctlLib_IImageListSetImageHeight (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short psImageHeight);

HRESULT CVIFUNC MSComctlLib_IImageListGetImageWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     short *psImageWidth);

HRESULT CVIFUNC MSComctlLib_IImageListSetImageWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     short psImageWidth);

HRESULT CVIFUNC MSComctlLib_IImageListGetMaskColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibType_OLE_COLOR *pclrMaskColor);

HRESULT CVIFUNC MSComctlLib_IImageListSetMaskColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibType_OLE_COLOR pclrMaskColor);

HRESULT CVIFUNC MSComctlLib_IImageListGetUseMaskColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pbState);

HRESULT CVIFUNC MSComctlLib_IImageListSetUseMaskColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pbState);

HRESULT CVIFUNC MSComctlLib_IImageListGetListImages (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibObj_IImages *ppListImages);

HRESULT CVIFUNC MSComctlLib_IImageListSetByRefListImages (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          MSComctlLibObj_IImages ppListImages);

HRESULT CVIFUNC MSComctlLib_IImageListGethImageList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibType_OLE_HANDLE *phImageList);

HRESULT CVIFUNC MSComctlLib_IImageListSethImageList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibType_OLE_HANDLE phImageList);

HRESULT CVIFUNC MSComctlLib_IImageListGetBackColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibType_OLE_COLOR *pclrBackColor);

HRESULT CVIFUNC MSComctlLib_IImageListSetBackColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    MSComctlLibType_OLE_COLOR pclrBackColor);

HRESULT CVIFUNC MSComctlLib_IImageListOverlay (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT key1, VARIANT key2,
                                               MSComctlLibObj_IPictureDisp *ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IImageListAboutBox (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IImagesGetCount (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             short *psCount);

HRESULT CVIFUNC MSComctlLib_IImagesSetCount (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, short psCount);

HRESULT CVIFUNC MSComctlLib_IImagesGetControlDefault (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT index,
                                                      MSComctlLibObj_IImage *ppListImage);

HRESULT CVIFUNC MSComctlLib_IImagesSetByRefControlDefault (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VARIANT index,
                                                           MSComctlLibObj_IImage ppListImage);

HRESULT CVIFUNC MSComctlLib_IImagesAdd (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo, VARIANT index,
                                        VARIANT key, VARIANT picture,
                                        MSComctlLibObj_IImage *ppListImage);

HRESULT CVIFUNC MSComctlLib_IImagesClear (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IImagesGetItem (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VARIANT index,
                                            MSComctlLibObj_IImage *item);

HRESULT CVIFUNC MSComctlLib_IImagesSetByRefItem (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT index,
                                                 MSComctlLibObj_IImage item);

HRESULT CVIFUNC MSComctlLib_IImagesRemove (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT index);

HRESULT CVIFUNC MSComctlLib_IImages_NewEnum (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             CAObjHandle *ppNewEnum);

HRESULT CVIFUNC MSComctlLib_IImageGetIndex (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, short *psIndex);

HRESULT CVIFUNC MSComctlLib_IImageSetIndex (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, short psIndex);

HRESULT CVIFUNC MSComctlLib_IImageGetKey (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IImageSetKey (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IImageGetTag (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IImageSetTag (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo, VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IImageGetPicture (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              MSComctlLibObj_IPictureDisp *ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IImageSetByRefPicture (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   MSComctlLibObj_IPictureDisp ppPictureDisp);

HRESULT CVIFUNC MSComctlLib_IImageDraw (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        MSComctlLibType_OLE_HANDLE hDC,
                                        VARIANT x, VARIANT y, VARIANT style);

HRESULT CVIFUNC MSComctlLib_IImageExtractIcon (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               MSComctlLibObj_IPictureDisp *ppIconDisp);

HRESULT CVIFUNC MSComctlLib_IImageSetByRefTag (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_NewISlider (int panel, const char *label, int top,
                                        int left, int *controlID, int *UILError);

HRESULT CVIFUNC MSComctlLib_ISliderGet_Value (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              long *plValue);

HRESULT CVIFUNC MSComctlLib_ISliderSet_Value (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, long plValue);

HRESULT CVIFUNC MSComctlLib_ISliderGetLargeChange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *plLargeChange);

HRESULT CVIFUNC MSComctlLib_ISliderSetLargeChange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long plLargeChange);

HRESULT CVIFUNC MSComctlLib_ISliderGetSmallChange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *plSmallChange);

HRESULT CVIFUNC MSComctlLib_ISliderSetSmallChange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long plSmallChange);

HRESULT CVIFUNC MSComctlLib_ISliderGetMax (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, long *plMax);

HRESULT CVIFUNC MSComctlLib_ISliderSetMax (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, long plMax);

HRESULT CVIFUNC MSComctlLib_ISliderGetMin (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, long *plMin);

HRESULT CVIFUNC MSComctlLib_ISliderSetMin (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, long plMin);

HRESULT CVIFUNC MSComctlLib_ISliderGetOrientation (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_OrientationConstants *pOrientation);

HRESULT CVIFUNC MSComctlLib_ISliderSetOrientation (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_OrientationConstants pOrientation);

HRESULT CVIFUNC MSComctlLib_ISliderGetSelectRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pbSelectRange);

HRESULT CVIFUNC MSComctlLib_ISliderSetSelectRange (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pbSelectRange);

HRESULT CVIFUNC MSComctlLib_ISliderGetSelStart (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long *plSelStart);

HRESULT CVIFUNC MSComctlLib_ISliderSetSelStart (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long plSelStart);

HRESULT CVIFUNC MSComctlLib_ISliderGetSelLength (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *plSelLength);

HRESULT CVIFUNC MSComctlLib_ISliderSetSelLength (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long plSelLength);

HRESULT CVIFUNC MSComctlLib_ISliderGetTickStyle (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum MSComctlLibEnum_TickStyleConstants *pTickStyle);

HRESULT CVIFUNC MSComctlLib_ISliderSetTickStyle (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum MSComctlLibEnum_TickStyleConstants pTickStyle);

HRESULT CVIFUNC MSComctlLib_ISliderGetTickFrequency (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *plTickFrequency);

HRESULT CVIFUNC MSComctlLib_ISliderSetTickFrequency (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long plTickFrequency);

HRESULT CVIFUNC MSComctlLib_ISliderGetValue (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long *plValue);

HRESULT CVIFUNC MSComctlLib_ISliderSetValue (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long plValue);

HRESULT CVIFUNC MSComctlLib_ISliderGetMouseIcon (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_IPictureDisp *ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ISliderSetMouseIcon (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ISliderSetByRefMouseIcon (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_ISliderGetMousePointer (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_MousePointerConstants *psMousePointer);

HRESULT CVIFUNC MSComctlLib_ISliderSetMousePointer (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_MousePointerConstants psMousePointer);

HRESULT CVIFUNC MSComctlLib_ISliderGetEnabled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_ISliderSetEnabled (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_ISliderGethWnd (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_ISliderSethWnd (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            MSComctlLibType_OLE_HANDLE phWnd);

HRESULT CVIFUNC MSComctlLib_ISliderGetBorderStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_BorderStyleConstants *psBorderStyle);

HRESULT CVIFUNC MSComctlLib_ISliderSetBorderStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_BorderStyleConstants psBorderStyle);

HRESULT CVIFUNC MSComctlLib_ISliderGetOLEDropMode (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_ISliderSetOLEDropMode (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_ISliderRefresh (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ISliderClearSel (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ISliderDoClick (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ISliderGetGetNumTicks (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *plNumTicks);

HRESULT CVIFUNC MSComctlLib_ISliderOLEDrag (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ISliderAboutBox (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ISliderGetText (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            char **pbstrText);

HRESULT CVIFUNC MSComctlLib_ISliderSetText (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_ISliderGetTextPosition (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_TextPositionConstants *penumTextPosition);

HRESULT CVIFUNC MSComctlLib_ISliderSetTextPosition (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum MSComctlLibEnum_TextPositionConstants penumTextPosition);

HRESULT CVIFUNC MSComctlLib_IControlsGetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long *plCount);

HRESULT CVIFUNC MSComctlLib_IControlsGetItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, long index,
                                              CAObjHandle *ppDisp);

HRESULT CVIFUNC MSComctlLib_IControls_NewEnum (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               LPUNKNOWN *ppUnk);

HRESULT CVIFUNC MSComctlLib_IComboItemGet_ObjectDefault (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IComboItemSet_ObjectDefault (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IComboItemGetImage (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT *pvImage);

HRESULT CVIFUNC MSComctlLib_IComboItemSetImage (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT pvImage);

HRESULT CVIFUNC MSComctlLib_IComboItemGetIndentation (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short *psIndent);

HRESULT CVIFUNC MSComctlLib_IComboItemSetIndentation (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short psIndent);

HRESULT CVIFUNC MSComctlLib_IComboItemGetIndex (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long *plIndex);

HRESULT CVIFUNC MSComctlLib_IComboItemSetIndex (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long plIndex);

HRESULT CVIFUNC MSComctlLib_IComboItemGetKey (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              char **pbstrKey);

HRESULT CVIFUNC MSComctlLib_IComboItemSetKey (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *pbstrKey);

HRESULT CVIFUNC MSComctlLib_IComboItemGetSelected (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pbSelected);

HRESULT CVIFUNC MSComctlLib_IComboItemSetSelected (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pbSelected);

HRESULT CVIFUNC MSComctlLib_IComboItemGetSelImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *pvImage);

HRESULT CVIFUNC MSComctlLib_IComboItemSetSelImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT pvImage);

HRESULT CVIFUNC MSComctlLib_IComboItemGetTag (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT *pvTag);

HRESULT CVIFUNC MSComctlLib_IComboItemSetTag (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IComboItemSetByRefTag (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT pvTag);

HRESULT CVIFUNC MSComctlLib_IComboItemGetText (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IComboItemSetText (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IComboItemsGet_CollectionDefault (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT index,
                                                              MSComctlLibObj_IComboItem *ppComboItem);

HRESULT CVIFUNC MSComctlLib_IComboItemsSet_CollectionDefault (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT index,
                                                              MSComctlLibObj_IComboItem ppComboItem);

HRESULT CVIFUNC MSComctlLib_IComboItemsGetCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *plCount);

HRESULT CVIFUNC MSComctlLib_IComboItemsSetCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long plCount);

HRESULT CVIFUNC MSComctlLib_IComboItemsGetItem (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT index,
                                                MSComctlLibObj_IComboItem *ppComboItem);

HRESULT CVIFUNC MSComctlLib_IComboItemsSetItem (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT index,
                                                MSComctlLibObj_IComboItem ppComboItem);

HRESULT CVIFUNC MSComctlLib_IComboItemsAdd (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VARIANT index,
                                            VARIANT key, VARIANT text,
                                            VARIANT image, VARIANT selImage,
                                            VARIANT indentation,
                                            MSComctlLibObj_IComboItem *ppComboItem);

HRESULT CVIFUNC MSComctlLib_IComboItemsClear (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IComboItemsRemove (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT index);

HRESULT CVIFUNC MSComctlLib_IComboItems_NewEnum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CAObjHandle *ppNewEnum);

HRESULT CVIFUNC MSComctlLib_NewIImageCombo (int panel, const char *label,
                                            int top, int left, int *controlID,
                                            int *UILError);

HRESULT CVIFUNC MSComctlLib_IImageComboGetText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IImageComboSetText (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IImageComboGetBackColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibType_OLE_COLOR *pocBackColor);

HRESULT CVIFUNC MSComctlLib_IImageComboSetBackColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibType_OLE_COLOR pocBackColor);

HRESULT CVIFUNC MSComctlLib_IImageComboGetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pbEnabled);

HRESULT CVIFUNC MSComctlLib_IImageComboSetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pbEnabled);

HRESULT CVIFUNC MSComctlLib_IImageComboGetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                MSComctlLibObj_IFontDisp *ppFont);

HRESULT CVIFUNC MSComctlLib_IImageComboSetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                MSComctlLibObj_IFontDisp ppFont);

HRESULT CVIFUNC MSComctlLib_IImageComboSetByRefFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibObj_IFontDisp ppFont);

HRESULT CVIFUNC MSComctlLib_IImageComboGetForeColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibType_OLE_COLOR *pocForeColor);

HRESULT CVIFUNC MSComctlLib_IImageComboSetForeColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibType_OLE_COLOR pocForeColor);

HRESULT CVIFUNC MSComctlLib_IImageComboGethWnd (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                MSComctlLibType_OLE_HANDLE *phWnd);

HRESULT CVIFUNC MSComctlLib_IImageComboSethWnd (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                MSComctlLibType_OLE_HANDLE phWnd);

HRESULT CVIFUNC MSComctlLib_IImageComboGetImageList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CAObjHandle *ppImageList);

HRESULT CVIFUNC MSComctlLib_IImageComboSetByRefImageList (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IImageComboSetImageList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CAObjHandle ppImageList);

HRESULT CVIFUNC MSComctlLib_IImageComboGetIndentation (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       short *psIndent);

HRESULT CVIFUNC MSComctlLib_IImageComboSetIndentation (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       short psIndent);

HRESULT CVIFUNC MSComctlLib_IImageComboGetComboItems (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      MSComctlLibObj_IComboItems *ppComboItems);

HRESULT CVIFUNC MSComctlLib_IImageComboSetByRefComboItems (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           MSComctlLibObj_IComboItems ppComboItems);

HRESULT CVIFUNC MSComctlLib_IImageComboGetLocked (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pbLocked);

HRESULT CVIFUNC MSComctlLib_IImageComboSetLocked (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL pbLocked);

HRESULT CVIFUNC MSComctlLib_IImageComboGetMouseIcon (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibObj_IPictureDisp *ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IImageComboSetMouseIcon (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IImageComboSetByRefMouseIcon (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          MSComctlLibObj_IPictureDisp ppMouseIcon);

HRESULT CVIFUNC MSComctlLib_IImageComboGetMousePointer (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_MousePointerConstants *penumMousePointer);

HRESULT CVIFUNC MSComctlLib_IImageComboSetMousePointer (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MSComctlLibEnum_MousePointerConstants penumMousePointer);

HRESULT CVIFUNC MSComctlLib_IImageComboGetOLEDragMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_OLEDragConstants *psOLEDragMode);

HRESULT CVIFUNC MSComctlLib_IImageComboSetOLEDragMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_OLEDragConstants psOLEDragMode);

HRESULT CVIFUNC MSComctlLib_IImageComboGetOLEDropMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_OLEDropConstants *psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IImageComboSetOLEDropMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MSComctlLibEnum_OLEDropConstants psOLEDropMode);

HRESULT CVIFUNC MSComctlLib_IImageComboGetSelectedItem (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        MSComctlLibObj_IComboItem *ppIComboItem);

HRESULT CVIFUNC MSComctlLib_IImageComboSetByRefSelectedItem (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MSComctlLibObj_IComboItem ppIComboItem);

HRESULT CVIFUNC MSComctlLib_IImageComboSetSelectedItem (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT ppIComboItem);

HRESULT CVIFUNC MSComctlLib_IImageComboGetSelLength (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *plSelLength);

HRESULT CVIFUNC MSComctlLib_IImageComboSetSelLength (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long plSelLength);

HRESULT CVIFUNC MSComctlLib_IImageComboGetSelStart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *plSelStart);

HRESULT CVIFUNC MSComctlLib_IImageComboSetSelStart (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long plSelStart);

HRESULT CVIFUNC MSComctlLib_IImageComboGetSelText (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **pbstrText);

HRESULT CVIFUNC MSComctlLib_IImageComboSetSelText (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *pbstrText);

HRESULT CVIFUNC MSComctlLib_IImageComboGetStyle (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum MSComctlLibEnum_ImageComboStyleConstants *penumStyle);

HRESULT CVIFUNC MSComctlLib_IImageComboSetStyle (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum MSComctlLibEnum_ImageComboStyleConstants penumStyle);

HRESULT CVIFUNC MSComctlLib_IImageComboGetUsePathSep (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pbUsePathSep);

HRESULT CVIFUNC MSComctlLib_IImageComboSetUsePathSep (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pbUsePathSep);

HRESULT CVIFUNC MSComctlLib_IImageComboAboutBox (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IImageComboGetFirstVisible (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        MSComctlLibObj_IComboItem *ppIComboItem);

HRESULT CVIFUNC MSComctlLib_IImageComboRefresh (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_IImageComboOLEDrag (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnClick (CAObjHandle serverObject,
                                                       ITabStripEventsRegOnClick_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnKeyDown (CAObjHandle serverObject,
                                                         ITabStripEventsRegOnKeyDown_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnKeyPress (CAObjHandle serverObject,
                                                          ITabStripEventsRegOnKeyPress_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnKeyUp (CAObjHandle serverObject,
                                                       ITabStripEventsRegOnKeyUp_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnMouseDown (CAObjHandle serverObject,
                                                           ITabStripEventsRegOnMouseDown_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnMouseMove (CAObjHandle serverObject,
                                                           ITabStripEventsRegOnMouseMove_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnMouseUp (CAObjHandle serverObject,
                                                         ITabStripEventsRegOnMouseUp_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnBeforeClick (CAObjHandle serverObject,
                                                             ITabStripEventsRegOnBeforeClick_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                              ITabStripEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                                 ITabStripEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnOLESetData (CAObjHandle serverObject,
                                                            ITabStripEventsRegOnOLESetData_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                                 ITabStripEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                             ITabStripEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITabStripEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                             ITabStripEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnButtonClick (CAObjHandle serverObject,
                                                            IToolbarEventsRegOnButtonClick_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnChange (CAObjHandle serverObject,
                                                       IToolbarEventsRegOnChange_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnClick (CAObjHandle serverObject,
                                                      IToolbarEventsRegOnClick_CallbackType callbackFunction,
                                                      void *callbackData,
                                                      int enableCallbacks,
                                                      int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnMouseDown (CAObjHandle serverObject,
                                                          IToolbarEventsRegOnMouseDown_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnMouseMove (CAObjHandle serverObject,
                                                          IToolbarEventsRegOnMouseMove_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnMouseUp (CAObjHandle serverObject,
                                                        IToolbarEventsRegOnMouseUp_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnDblClick (CAObjHandle serverObject,
                                                         IToolbarEventsRegOnDblClick_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                             IToolbarEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                                IToolbarEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnOLESetData (CAObjHandle serverObject,
                                                           IToolbarEventsRegOnOLESetData_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                                IToolbarEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                            IToolbarEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                            IToolbarEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnButtonMenuClick (CAObjHandle serverObject,
                                                                IToolbarEventsRegOnButtonMenuClick_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_IToolbarEventsRegOnButtonDropDown (CAObjHandle serverObject,
                                                               IToolbarEventsRegOnButtonDropDown_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnPanelClick (CAObjHandle serverObject,
                                                             IStatusBarEventsRegOnPanelClick_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnPanelDblClick (CAObjHandle serverObject,
                                                                IStatusBarEventsRegOnPanelDblClick_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnMouseDown (CAObjHandle serverObject,
                                                            IStatusBarEventsRegOnMouseDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnMouseMove (CAObjHandle serverObject,
                                                            IStatusBarEventsRegOnMouseMove_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnMouseUp (CAObjHandle serverObject,
                                                          IStatusBarEventsRegOnMouseUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnClick (CAObjHandle serverObject,
                                                        IStatusBarEventsRegOnClick_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnDblClick (CAObjHandle serverObject,
                                                           IStatusBarEventsRegOnDblClick_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                               IStatusBarEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                                  IStatusBarEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnOLESetData (CAObjHandle serverObject,
                                                             IStatusBarEventsRegOnOLESetData_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                                  IStatusBarEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                              IStatusBarEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MSComctlLib_IStatusBarEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                              IStatusBarEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnMouseDown (CAObjHandle serverObject,
                                                              IProgressBarEventsRegOnMouseDown_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnMouseMove (CAObjHandle serverObject,
                                                              IProgressBarEventsRegOnMouseMove_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnMouseUp (CAObjHandle serverObject,
                                                            IProgressBarEventsRegOnMouseUp_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnClick (CAObjHandle serverObject,
                                                          IProgressBarEventsRegOnClick_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                                 IProgressBarEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                                    IProgressBarEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnOLESetData (CAObjHandle serverObject,
                                                               IProgressBarEventsRegOnOLESetData_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                                    IProgressBarEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                                IProgressBarEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_IProgressBarEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                                IProgressBarEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnBeforeLabelEdit (CAObjHandle serverObject,
                                                                 ITreeViewEventsRegOnBeforeLabelEdit_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnAfterLabelEdit (CAObjHandle serverObject,
                                                                ITreeViewEventsRegOnAfterLabelEdit_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnCollapse (CAObjHandle serverObject,
                                                          ITreeViewEventsRegOnCollapse_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnExpand (CAObjHandle serverObject,
                                                        ITreeViewEventsRegOnExpand_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnNodeClick (CAObjHandle serverObject,
                                                           ITreeViewEventsRegOnNodeClick_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnKeyDown (CAObjHandle serverObject,
                                                         ITreeViewEventsRegOnKeyDown_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnKeyUp (CAObjHandle serverObject,
                                                       ITreeViewEventsRegOnKeyUp_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnKeyPress (CAObjHandle serverObject,
                                                          ITreeViewEventsRegOnKeyPress_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnMouseDown (CAObjHandle serverObject,
                                                           ITreeViewEventsRegOnMouseDown_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnMouseMove (CAObjHandle serverObject,
                                                           ITreeViewEventsRegOnMouseMove_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnMouseUp (CAObjHandle serverObject,
                                                         ITreeViewEventsRegOnMouseUp_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnClick (CAObjHandle serverObject,
                                                       ITreeViewEventsRegOnClick_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnDblClick (CAObjHandle serverObject,
                                                          ITreeViewEventsRegOnDblClick_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnNodeCheck (CAObjHandle serverObject,
                                                           ITreeViewEventsRegOnNodeCheck_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                              ITreeViewEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                                 ITreeViewEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnOLESetData (CAObjHandle serverObject,
                                                            ITreeViewEventsRegOnOLESetData_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                                 ITreeViewEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                             ITreeViewEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_ITreeViewEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                             ITreeViewEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnBeforeLabelEdit (CAObjHandle serverObject,
                                                                ListViewEventsRegOnBeforeLabelEdit_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnAfterLabelEdit (CAObjHandle serverObject,
                                                               ListViewEventsRegOnAfterLabelEdit_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnColumnClick (CAObjHandle serverObject,
                                                            ListViewEventsRegOnColumnClick_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnItemClick (CAObjHandle serverObject,
                                                          ListViewEventsRegOnItemClick_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnKeyDown (CAObjHandle serverObject,
                                                        ListViewEventsRegOnKeyDown_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnKeyUp (CAObjHandle serverObject,
                                                      ListViewEventsRegOnKeyUp_CallbackType callbackFunction,
                                                      void *callbackData,
                                                      int enableCallbacks,
                                                      int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnKeyPress (CAObjHandle serverObject,
                                                         ListViewEventsRegOnKeyPress_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnMouseDown (CAObjHandle serverObject,
                                                          ListViewEventsRegOnMouseDown_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnMouseMove (CAObjHandle serverObject,
                                                          ListViewEventsRegOnMouseMove_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnMouseUp (CAObjHandle serverObject,
                                                        ListViewEventsRegOnMouseUp_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnClick (CAObjHandle serverObject,
                                                      ListViewEventsRegOnClick_CallbackType callbackFunction,
                                                      void *callbackData,
                                                      int enableCallbacks,
                                                      int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnDblClick (CAObjHandle serverObject,
                                                         ListViewEventsRegOnDblClick_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                             ListViewEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                                ListViewEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnOLESetData (CAObjHandle serverObject,
                                                           ListViewEventsRegOnOLESetData_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                                ListViewEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                            ListViewEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                            ListViewEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_ListViewEventsRegOnItemCheck (CAObjHandle serverObject,
                                                          ListViewEventsRegOnItemCheck_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnClick (CAObjHandle serverObject,
                                                     ISliderEventsRegOnClick_CallbackType callbackFunction,
                                                     void *callbackData,
                                                     int enableCallbacks,
                                                     int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnKeyDown (CAObjHandle serverObject,
                                                       ISliderEventsRegOnKeyDown_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnKeyPress (CAObjHandle serverObject,
                                                        ISliderEventsRegOnKeyPress_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnKeyUp (CAObjHandle serverObject,
                                                     ISliderEventsRegOnKeyUp_CallbackType callbackFunction,
                                                     void *callbackData,
                                                     int enableCallbacks,
                                                     int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnMouseDown (CAObjHandle serverObject,
                                                         ISliderEventsRegOnMouseDown_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnMouseMove (CAObjHandle serverObject,
                                                         ISliderEventsRegOnMouseMove_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnMouseUp (CAObjHandle serverObject,
                                                       ISliderEventsRegOnMouseUp_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnScroll (CAObjHandle serverObject,
                                                      ISliderEventsRegOnScroll_CallbackType callbackFunction,
                                                      void *callbackData,
                                                      int enableCallbacks,
                                                      int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnChange (CAObjHandle serverObject,
                                                      ISliderEventsRegOnChange_CallbackType callbackFunction,
                                                      void *callbackData,
                                                      int enableCallbacks,
                                                      int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                            ISliderEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                               ISliderEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnOLESetData (CAObjHandle serverObject,
                                                          ISliderEventsRegOnOLESetData_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                               ISliderEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                           ISliderEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_ISliderEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                           ISliderEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnChange (CAObjHandle serverObject,
                                                          DImageComboEventsRegOnChange_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnDropdown (CAObjHandle serverObject,
                                                            DImageComboEventsRegOnDropdown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnClick (CAObjHandle serverObject,
                                                         DImageComboEventsRegOnClick_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnKeyDown (CAObjHandle serverObject,
                                                           DImageComboEventsRegOnKeyDown_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnKeyUp (CAObjHandle serverObject,
                                                         DImageComboEventsRegOnKeyUp_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnKeyPress (CAObjHandle serverObject,
                                                            DImageComboEventsRegOnKeyPress_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnOLEStartDrag (CAObjHandle serverObject,
                                                                DImageComboEventsRegOnOLEStartDrag_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnOLEGiveFeedback (CAObjHandle serverObject,
                                                                   DImageComboEventsRegOnOLEGiveFeedback_CallbackType callbackFunction,
                                                                   void *callbackData,
                                                                   int enableCallbacks,
                                                                   int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnOLESetData (CAObjHandle serverObject,
                                                              DImageComboEventsRegOnOLESetData_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnOLECompleteDrag (CAObjHandle serverObject,
                                                                   DImageComboEventsRegOnOLECompleteDrag_CallbackType callbackFunction,
                                                                   void *callbackData,
                                                                   int enableCallbacks,
                                                                   int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnOLEDragOver (CAObjHandle serverObject,
                                                               DImageComboEventsRegOnOLEDragOver_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MSComctlLib_DImageComboEventsRegOnOLEDragDrop (CAObjHandle serverObject,
                                                               DImageComboEventsRegOnOLEDragDrop_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);
#ifdef __cplusplus
    }
#endif
#endif /* _MSCOMCTLLIB_H */
