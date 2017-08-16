#include "MSCOMCTL.h"
#include <formatio.h>
#include <ansi_c.h>
#include "FileBrowser.h"
#include "FilePanel.h"
#include <userint.h>
#include "MainPanel.h"
#include"MyInclude.h"

static int 				FilePanelHandle;
static CAObjHandle 		ObjProgressBar; 
FileLoad_t				FileLoad; 
RecordResume_t			RecordResume;
double					Record_GetTotal(int FileHandle);
void 					Record_ResumeToArray(int FileHandle);

/*------------------------------------------------------------------------------------------------------------------*/
void CVICALLBACK LoadFile (int menuBar, int menuItem, void *callbackData,
		int panel)
{

	if ((FilePanelHandle = LoadPanel (0, "FilePanel.uir", PANEL_FILE)) < 0)
		QuitUserInterface (0);

	FileBrowser_Create(FilePanelHandle, PANEL_FILE_FILE_BROWSER, ROOT_LEVEL_STRING);
	FileBrowser_SetAttribute (FilePanelHandle, PANEL_FILE_FILE_BROWSER, ATTR_BROWSE_FLOPPYDRIVES, 1);
	
	RecordResume.PtrRawAccel_X = (double * )malloc(sizeof(double));
	RecordResume.PtrRawAccel_Y = (double * )malloc(sizeof(double)); 
	RecordResume.PtrRawAccel_Z = (double * )malloc(sizeof(double)); 
	RecordResume.PtrFilteredAccel_X = (double * )malloc(sizeof(double));
	RecordResume.PtrFilteredAccel_Y = (double * )malloc(sizeof(double));
	RecordResume.PtrFilteredAccel_Z = (double * )malloc(sizeof(double));
	RecordResume.PtrRawVel_Z = (double * )malloc(sizeof(double)); 
	RecordResume.PtrFilteredVel_Z =  (double * )malloc(sizeof(double));
	RecordResume.PtrTimeStamp = (int * )malloc(sizeof(int));
	RecordResume.PtrFFTResult_Z =  (NIComplexNumber  * )malloc(RecordResume.RecordTotal*sizeof(NIComplexNumber ));    //added by  yz 2015-3-17
	RecordResume.PtrFFTResultMag_Z =  (double  * )malloc(RecordResume.RecordTotal*sizeof(double ));    //added by  yz 2015-3-17   
	RecordResume.PtrFFTResultPhase_Z =  (double  * )malloc(RecordResume.RecordTotal*sizeof(double ));    //added by  yz 2015-3-17   
	
	DisplayPanel (FilePanelHandle);	
}
/*------------------------------------------------------------------------------------------------------------------*/
int CVICALLBACK FilePanelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			SetCtrlAttribute (FilePanelHandle, PANEL_FILE_PROGRESS_BAR, ATTR_VISIBLE, 0); 
			DiscardPanel (FilePanelHandle);
			break;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------------*/
int CVICALLBACK AffirmLoadFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	static char *TempFilePath="0";
	char RecordToal[256];
	
	switch (event)
	{
		case EVENT_COMMIT:
			FileLoad.FileState = NO_FILE_LOAD;
			//此函数必须由caller free
			FileBrowser_GetSelectedFiles (FilePanelHandle, PANEL_FILE_FILE_BROWSER, &FileLoad.FilesPath);
			
			if((FileLoad.FilesPath != NULL)&&(*FileLoad.FilesPath != NULL))
			{
				if(strcmp (TempFilePath, *FileLoad.FilesPath))//字符串不相等,选择了不同的文件
				{
					TempFilePath =  *FileLoad.FilesPath;
					FileLoad.FileState = NEW_FILE_LOAD;	   //导入新文件

				}
				else
				{   
					FileLoad.FileState = OLD_FILE_LOAD;	   //有文件导入，但是是旧文件
				}
			}
			
			switch(FileLoad.FileState)
			{
				case  NEW_FILE_LOAD :
					
					free(RecordResume.PtrRawAccel_X);
					free(RecordResume.PtrRawAccel_Y); 
					free(RecordResume.PtrRawAccel_Z);
					free(RecordResume.PtrFilteredAccel_X);
					free(RecordResume.PtrFilteredAccel_Y);
					free(RecordResume.PtrFilteredAccel_Z);
					free(RecordResume.PtrRawVel_Z);
					free(RecordResume.PtrFilteredVel_Z); 
					free(RecordResume.PtrTimeStamp);
					free(RecordResume.PtrFFTResult_Z);//added by  yz 2015-3-17 
					free(RecordResume.PtrFFTResultMag_Z);//added by  yz 2015-3-17   
					free(RecordResume.PtrFFTResultPhase_Z);//added by  yz 2015-3-17   
					
					FileLoad.FileHandle = OpenFile (*FileLoad.FilesPath, VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_ASCII);
					GetFileInfo (*FileLoad.FilesPath, &FileLoad.FileSize); 
					//这一语句 耗时很长 
					RecordResume.RecordTotal =  Record_GetTotal(FileLoad.FileHandle);
					//读取新文件之后，此处的malloc 没有free，当文件改变时，旧的malloc free之后，会有新的maloc 
					RecordResume.PtrRawAccel_X = (double * )malloc(RecordResume.RecordTotal*sizeof(double));
					RecordResume.PtrRawAccel_Y = (double * )malloc(RecordResume.RecordTotal*sizeof(double));
					RecordResume.PtrRawAccel_Z = (double * )malloc(RecordResume.RecordTotal*sizeof(double)); 
					RecordResume.PtrFilteredAccel_X = (double * )malloc(RecordResume.RecordTotal*sizeof(double)); 
					RecordResume.PtrFilteredAccel_Y = (double * )malloc(RecordResume.RecordTotal*sizeof(double)); 
					RecordResume.PtrFilteredAccel_Z = (double * )malloc(RecordResume.RecordTotal*sizeof(double));
					RecordResume.PtrRawVel_Z =  (double * )malloc(RecordResume.RecordTotal*sizeof(double));
					RecordResume.PtrFilteredVel_Z = (double * )malloc(RecordResume.RecordTotal*sizeof(double));
					RecordResume.PtrTimeStamp = (int * )malloc(RecordResume.RecordTotal*sizeof(int));
					RecordResume.PtrFFTResult_Z =  (NIComplexNumber  * )malloc(RecordResume.RecordTotal*sizeof(NIComplexNumber ));    //added by  yz 2015-3-17  
					RecordResume.PtrFFTResultMag_Z =  (double  * )malloc(RecordResume.RecordTotal*sizeof(double ));    //added by  yz 2015-3-17   
					RecordResume.PtrFFTResultPhase_Z =  (double  * )malloc(RecordResume.RecordTotal*sizeof(double ));    //added by  yz 2015-3-17   
					
					
					Record_ResumeToArray(FileLoad.FileHandle);//读到内存中
					
					

					sprintf(RecordToal,"New File Loaded\n%.0lf Records\n",RecordResume.RecordTotal);

					MessagePopup ("Affirm Load File ", RecordToal);
				
					CloseFile(FileLoad.FileHandle);
					
					break;
				case OLD_FILE_LOAD:
				 	MessagePopup ("Affirm Load File ", "Old File Loaded");
				 	break;
			}
 
			free(FileLoad.FilesPath);
			
			break;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------------*/  
//注意差1误差,此处为统计记录中的换行符总数，包括了最后一个结束换行符
double Record_GetTotal(int FileHandle)
{
	char c;
	double total = 0;
	long i = 0;
	
	SetCtrlAttribute (FilePanelHandle, PANEL_FILE_PROGRESS_BAR, ATTR_VISIBLE, 1);
	
	GetObjHandleFromActiveXCtrl (FilePanelHandle, PANEL_FILE_PROGRESS_BAR, &ObjProgressBar);
	MSComctlLib_IProgressBarSetMin (ObjProgressBar, NULL, 0.0);
	MSComctlLib_IProgressBarSetMax (ObjProgressBar, NULL, 100.0); 
	//设置进度条上的鼠标显示模式
//	MSComctlLib_IProgressBarSetMousePointer (ObjProgressBar, NULL, MSComctlLibConst_ccHourglass);

	while(ScanFile (FileHandle, "%c",&c)&&(c!='\0'))
	{  	
		 
		if(c=='\n')
		{
			total++; 
		}
		
		if(i++ > FileLoad.FileSize)
			i = 0;
		
		MSComctlLib_IProgressBarSetValue (ObjProgressBar, NULL, 100.0*(i+total)/FileLoad.FileSize);
	}
	 
	return total;
}
/*-------------------------------------------------------------------------------------------------------------------*/  
void Record_ResumeToArray(int FileHandle)
{																					
	int i = 0;							
	
	int *TempArray = (int * )malloc(RecordResume.RecordTotal*7*sizeof(int ));

	FileToArray (*FileLoad.FilesPath, TempArray, VAL_INTEGER, RecordResume.RecordTotal*7, 7, VAL_DATA_MULTIPLEXED , VAL_GROUPS_AS_COLUMNS, VAL_ASCII);

	for(i=0;i<RecordResume.RecordTotal;i++)
	{
		RecordResume.PtrRawAccel_X[i] = TempArray[7*i];	
		RecordResume.PtrRawAccel_Y[i] = TempArray[7*i+1];
		RecordResume.PtrRawAccel_Z[i] = TempArray[7*i+2];
		RecordResume.PtrFilteredAccel_X[i] = TempArray[7*i+3];
		RecordResume.PtrFilteredAccel_Y[i] = TempArray[7*i+4];
		RecordResume.PtrFilteredAccel_Z[i] = TempArray[7*i+5];
		RecordResume.PtrTimeStamp[i] = TempArray[7*i+6]; 
	}
	
	free(TempArray);
}
/*-------------------------------------------------------------------------------------------------------------------*/  
