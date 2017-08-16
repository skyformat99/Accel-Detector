#include <analysis.h>
#include <ansi_c.h>
#include "MainPanel.h"
#include <userint.h>
#include "AnalysisPanel.h"
#include"myinclude.h"

static int 				AnalysisPanelHandle;  
/*------------------------------------------------------------------------------------------------------------*/
void CVICALLBACK Analysis (int menuBar, int menuItem, void *callbackData,
		int panel)
{
		if ((AnalysisPanelHandle = LoadPanel (0, "AnalysisPanel.uir", PANEL_ANAL)) < 0)
			QuitUserInterface (0);
		
		DisplayPanel (AnalysisPanelHandle);	
}
/*------------------------------------------------------------------------------------------------------------*/ 
int CVICALLBACK AnalysisPanelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			
			DiscardPanel (AnalysisPanelHandle); 

			break;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------*/
void DrawGraph(Msg_t	*Msg)
{	
	
	if(FileLoad.FileState == NO_FILE_LOAD)
		return;
	SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_XAXIS_OFFSET, -0.001*RecordResume.PtrTimeStamp[0]);
	SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_XAXIS_OFFSET, -0.001*RecordResume.PtrTimeStamp[0]); 
	SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_3, ATTR_XAXIS_OFFSET, -0.001*RecordResume.PtrTimeStamp[0]);
	switch(Msg->Src)
	{
/*---------------------------------------------------------------------------*/
		case SRC_RAW_ACCEL_X:
			switch(Param.Unit_Accel) 
			{
				case LSB:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 1.0);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel X / LSB");
				break ;
				
				case METERS_QUATER_SECOND:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 9.8/16384);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel X / M/S^2");
				break;
				
				case MILLI_GRAVITY:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 9800.0/16384);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel X / mG"); 
				break;
				
			}
			DeleteGraphPlot (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, -1, VAL_IMMEDIATE_DRAW);
			PlotXY (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, 
					RecordResume.PtrTimeStamp, 
					RecordResume.PtrRawAccel_X, 
					RecordResume.RecordTotal, 
					VAL_INTEGER, VAL_DOUBLE,
					VAL_THIN_LINE,
					VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
		break;//break for case SRC_RAW_ACCEL_X:
 /*---------------------------------------------------------------------------*/ 
		case SRC_RAW_ACCEL_Y:
			switch(Param.Unit_Accel) 
			{
				case LSB:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 1.0);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel Y / LSB");
				break ;
				
				case METERS_QUATER_SECOND:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 9.8/16384);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel Y / M/S^2");
				break;
				
				case MILLI_GRAVITY:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 9800.0/16384);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel Y / mG"); 
				break;
				
			}
			DeleteGraphPlot (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, -1, VAL_IMMEDIATE_DRAW);
			PlotXY (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, 
					RecordResume.PtrTimeStamp, 
					RecordResume.PtrRawAccel_Y, 
					RecordResume.RecordTotal, 
					VAL_INTEGER, VAL_DOUBLE,
					VAL_THIN_LINE,
					VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
		break;//break for case SRC_RAW_ACCEL_Y:
/*---------------------------------------------------------------------------*/ 			
		case SRC_RAW_ACCEL_Z:
			switch(Param.Unit_Accel) 
			{
				case LSB:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 1.0);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel Z / LSB");
				break ;
				
				case METERS_QUATER_SECOND:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 9.8/16384);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel Z / M/S^2");
				break;
				
				case MILLI_GRAVITY:
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YAXIS_GAIN, 9800.0/16384);
				SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, ATTR_YNAME, "Raw Accel Z / mG"); 
				break;
				
			}
			DeleteGraphPlot (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, -1, VAL_IMMEDIATE_DRAW);
			PlotXY (AnalysisPanelHandle, PANEL_ANAL_GRAPH_1, 
					RecordResume.PtrTimeStamp, 
					RecordResume.PtrRawAccel_Z, 
					RecordResume.RecordTotal, 
					VAL_INTEGER, VAL_DOUBLE,
					VAL_THIN_LINE,
					VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
		break;//break for case SRC_RAW_ACCEL_Z:
/*---------------------------------------------------------------------------*/
		case SRC_FILTER_TYPE_NONE:
		case SRC_FILTER_TYPE_MV:
		case SRC_FILTER_TYPE_MA:
		case SRC_FILTER_LEN :
		case SRC_FILTERED_ACCEL_Z:
		case SRC_VEL_FILTERED_Z: 
				
			switch(Param.Unit_Accel)
			{
				case LSB:
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_YNAME, "Filtered Accel Z  LSB");
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_YAXIS_GAIN, 1.0);
					break;
				case METERS_QUATER_SECOND:
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_YNAME, "Filtered Accel Z  M/S^2");
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_YAXIS_GAIN, 9.8/16384);
					break;
				case MILLI_GRAVITY:
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_YNAME, "Filtered Accel Z  mG");
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_YAXIS_GAIN, 9800.0/16384);
					break;
			}
			
			switch(Param.Unit_Velocity)
			{
				case METERS_SECOND:
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_3, ATTR_YNAME, "Filtered Speed Z  M/S");
					break;
				case MILLI_METERS_SECOND:
					SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_3, ATTR_YNAME, "Filtered Speed Z  MM/S"); 
					break;
			}
			
			switch(Param.Filter_Type)
			{
				case FILTER_NONE:
					break;
				case FILTER_MV:
					
					MiddelValue(	RecordResume.PtrRawAccel_Z,
									RecordResume.PtrFilteredAccel_Z,
									RecordResume.RecordTotal,
									Param.Filter_WinLen);
					break;
					
				case FILTER_MA:
					MovingAverage(	RecordResume.PtrRawAccel_Z,
									RecordResume.PtrFilteredAccel_Z,
									RecordResume.RecordTotal,
									Param.Filter_WinLen); 
					break;
			}
			
			DeleteGraphPlot (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
			PlotXY (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, 
					RecordResume.PtrTimeStamp, 
					RecordResume.PtrFilteredAccel_Z, 
					RecordResume.RecordTotal, 
					VAL_INTEGER, VAL_DOUBLE,
					VAL_THIN_LINE,
					VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			
			Param.StaticValue = GetAverageValue(RecordResume.PtrFilteredAccel_Z, RecordResume.RecordTotal);
			RunIntegral(	RecordResume.PtrFilteredAccel_Z,
							RecordResume.PtrFilteredVel_Z,
							RecordResume.PtrTimeStamp,
							Param.StaticValue,
							RecordResume.RecordTotal);
			switch(Param.Unit_Velocity)
			{
				case METERS_SECOND:
					for(int i=0;i<RecordResume.RecordTotal;i++)
						RecordResume.PtrFilteredVel_Z[i] = RecordResume.PtrFilteredVel_Z[i]*1.0/1000*9.8/16384;	
					break;
				case MILLI_METERS_SECOND:
					for(int i=0;i<RecordResume.RecordTotal;i++)
						RecordResume.PtrFilteredVel_Z[i] = RecordResume.PtrFilteredVel_Z[i]*1.0/1000*9800.0/16384;
					break;
			}
			
			if(Param.Velocity == VEL_FILTERED_Z)
			{
				DeleteGraphPlot (AnalysisPanelHandle, PANEL_ANAL_GRAPH_3, -1, VAL_IMMEDIATE_DRAW);
				PlotXY (AnalysisPanelHandle, PANEL_ANAL_GRAPH_3, 
						RecordResume.PtrTimeStamp, 
						RecordResume.PtrFilteredVel_Z, 
						RecordResume.RecordTotal, 
						VAL_INTEGER, VAL_DOUBLE,
						VAL_THIN_LINE,
						VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);	
			}
			

								  
		break;
/*---------------------------------------------------------------------------*/ 
		case SRC_VEL_RAW_Z:
				//对原始数据积分显示
				Param.StaticValue = GetAverageValue(RecordResume.PtrRawAccel_Z, RecordResume.RecordTotal);
				RunIntegral(	RecordResume.PtrRawAccel_Z,
								RecordResume.PtrRawVel_Z,
								RecordResume.PtrTimeStamp,
								Param.StaticValue,
								RecordResume.RecordTotal);
				switch(Param.Unit_Velocity)
				{
					case METERS_SECOND:
						for(int i=0;i<RecordResume.RecordTotal;i++)
							RecordResume.PtrRawVel_Z[i] = RecordResume.PtrRawVel_Z[i]*1.0/1000*9.8/16384;	
						break;
					case MILLI_METERS_SECOND:
						for(int i=0;i<RecordResume.RecordTotal;i++)
							RecordResume.PtrRawVel_Z[i] = RecordResume.PtrRawVel_Z[i]*1.0/1000*9800.0/16384;
						break;
				}
				
				DeleteGraphPlot (AnalysisPanelHandle, PANEL_ANAL_GRAPH_3, -1, VAL_IMMEDIATE_DRAW);
				PlotXY (AnalysisPanelHandle, PANEL_ANAL_GRAPH_3, 
						RecordResume.PtrTimeStamp, 
						RecordResume.PtrRawVel_Z, 
						RecordResume.RecordTotal, 
						VAL_INTEGER, VAL_DOUBLE,
						VAL_THIN_LINE,
						VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
				
		break;
		
		case SRC_FFT_ACCEL_Z:
			
/*			RecordResume.PtrFFTResult_Z =  (NIComplexNumber  * )malloc(FFTPoint*sizeof(NIComplexNumber ));    //added by  yz 2015-3-17  
			RecordResume.PtrFFTResultMag_Z =  (double  * )malloc(FFTPoint*sizeof(double ));    //added by  yz 2015-3-17   
			RecordResume.PtrFFTResultPhase_Z =  (double  * )malloc(FFTPoint*sizeof(double ));    //added by  yz 2015-3-17   
*/			
			int FFTPoint =  256;
			FFTEx (RecordResume.PtrRawAccel_Z, FFTPoint, RecordResume.RecordTotal, NULL, 0, RecordResume.PtrFFTResult_Z);
			
			for(int i =0;i<FFTPoint;i++)
			{
				ToPolar (	RecordResume.PtrFFTResult_Z[i].real,
							RecordResume.PtrFFTResult_Z[i].imaginary,
							&RecordResume.PtrFFTResultMag_Z[i],
							&RecordResume.PtrFFTResultPhase_Z[i]);
						
			}
			
			SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_XAXIS_OFFSET, 0.0);
			SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_XAXIS_GAIN, 1.0);
			SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_XNAME, "N"); 
			SetCtrlAttribute (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, ATTR_YNAME, "Raw Z FFT");
			
			DeleteGraphPlot (AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
			PlotY (	AnalysisPanelHandle, PANEL_ANAL_GRAPH_2, 
					RecordResume.PtrFFTResultMag_Z, FFTPoint, 
					VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
/*			
			free(RecordResume.PtrFFTResult_Z);//added by  yz 2015-3-17 
			free(RecordResume.PtrFFTResultMag_Z);//added by  yz 2015-3-17   
			free(RecordResume.PtrFFTResultPhase_Z);//added by  yz 2015-3-17  
*/	
		break;
	}
}
/*------------------------------------------------------------------------------------------------------------*/

int CVICALLBACK ChangeFilterType (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{   
	int FilterTypeCtrlValue = 0;
	Msg_t	Msg; 
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal (AnalysisPanelHandle, PANEL_ANAL_RING_FILTER_TYPE,&FilterTypeCtrlValue );
			GetCtrlVal (AnalysisPanelHandle, PANEL_ANAL_NUMERIC_FILETER_LEN,&Param.Filter_WinLen ); 
			if(FilterTypeCtrlValue != Param.Filter_Type)
			{
				switch(FilterTypeCtrlValue)
				{
					case FILTER_NONE:
						Param.Filter_Type = FILTER_NONE; 
						Msg.Src = SRC_FILTER_TYPE_NONE;
						break;
					case FILTER_MV:
						Param.Filter_Type = FILTER_MV;
						Msg.Src = SRC_FILTER_TYPE_MV;
						break;
					case FILTER_MA:
						Param.Filter_Type = FILTER_MA; 
						Msg.Src = SRC_FILTER_TYPE_MA;
						break;
				}

				
				Msg.Param = &Param ; 
				DrawGraph(&Msg); 
				
			}

			break;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------*/  
int CVICALLBACK ChangeFilterLen (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int FilterLenCtrlValue = 0; 
	Msg_t	Msg; 
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (AnalysisPanelHandle, PANEL_ANAL_NUMERIC_FILETER_LEN,&FilterLenCtrlValue );
			
			if(FilterLenCtrlValue != Param.Filter_WinLen)
			{
				Param.Filter_WinLen =  FilterLenCtrlValue;
				Msg.Src = SRC_FILTER_LEN;
				Msg.Param = &Param ; 
				DrawGraph(&Msg); 
			}
			break;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------*/  
int CVICALLBACK ChangeRawAccel (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int RawAccelCtrlValue = 0; 
	Msg_t	Msg;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (AnalysisPanelHandle, PANEL_ANAL_RING_RAW_ACCEL,&RawAccelCtrlValue );
			if(RawAccelCtrlValue != Param.Raw_Accel)
			{
//				Param.Raw_Accel =  RawAccelCtrlValue;

				switch(RawAccelCtrlValue)
				{
					case RAW_ACCEL_X:
						Param.Raw_Accel = RAW_ACCEL_X; 
						Msg.Src =  SRC_RAW_ACCEL_X;
						break;
					case RAW_ACCEL_Y:
						Param.Raw_Accel = RAW_ACCEL_Y; 
						Msg.Src =  SRC_RAW_ACCEL_Y;
						break;
					case RAW_ACCEL_Z:
						Param.Raw_Accel = RAW_ACCEL_Z; 
						Msg.Src =  SRC_RAW_ACCEL_Z;
						break;
				}
				
				Msg.Param = &Param ;
				DrawGraph(&Msg);
			}
			break;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------*/ 
int CVICALLBACK ChangeVelocity (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{   
	int VelocityCtrlValue = 0;
	Msg_t	Msg;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (AnalysisPanelHandle, PANEL_ANAL_RING_VELOCITY,&VelocityCtrlValue );
			if(VelocityCtrlValue != Param.Velocity)
			{
//				Param.Velocity =  VelocityCtrlValue;
				switch(VelocityCtrlValue)
				{
					case VEL_RAW_Z:
						Param.Velocity = VEL_RAW_Z; 
						Msg.Src =  SRC_VEL_RAW_Z;
						break;
					case VEL_FILTERED_Z:
						Param.Velocity = VEL_FILTERED_Z;
						Msg.Src =  SRC_VEL_FILTERED_Z;  
						break;
				}

			}

			Msg.Param = &Param ;
			DrawGraph(&Msg);
			break;
	}
	return 0;
}
/*------------------------------------------------------------------------------------------------------------*/ 
int CVICALLBACK Annotate (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double  Cursor_X,Cursor_Y,Gain_X,Gain_Y,Offset_X,Offset_Y;
	char 	Annotation_XY[64] =" ";
	switch (event)
	{
		case EVENT_COMMIT:

			break;
			
		case EVENT_VAL_CHANGED:
			
			GetCtrlAttribute (AnalysisPanelHandle, control, ATTR_XAXIS_GAIN, &Gain_X);
			GetCtrlAttribute (AnalysisPanelHandle, control, ATTR_YAXIS_GAIN, &Gain_Y);
			GetCtrlAttribute (AnalysisPanelHandle, control, ATTR_XAXIS_OFFSET, &Offset_X);
			GetCtrlAttribute (AnalysisPanelHandle, control, ATTR_YAXIS_OFFSET, &Offset_Y);
			GetGraphCursor (AnalysisPanelHandle, control, 1, &Cursor_X,&Cursor_Y ); 
			
			sprintf(Annotation_XY,"%.2f,%.2f",Cursor_X*Gain_X+Offset_X,Cursor_Y*Gain_Y+Offset_Y);
			
			SetAnnotationAttribute (AnalysisPanelHandle, control, 1, ATTR_ANNOTATION_CAPTION, Annotation_XY);
			SetAnnotationAttribute (AnalysisPanelHandle, control, 1, ATTR_ANNOTATION_XVALUE, Cursor_X);
			SetAnnotationAttribute (AnalysisPanelHandle, control, 1, ATTR_ANNOTATION_YVALUE, Cursor_Y);
			break;
	}
	return 0;
}

int CVICALLBACK ChangeAccelProcess (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ProcessAccelCtrlValue = 0;
	Msg_t	Msg;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (AnalysisPanelHandle, PANEL_ANAL_RING_PROCESS_ACCEL,&ProcessAccelCtrlValue );
			if(ProcessAccelCtrlValue != Param.Process_Accel)
			{
				switch(ProcessAccelCtrlValue)
				{
					case FILTER_X:
						Param.Process_Accel =  FILTER_X;
						Msg.Src =  SRC_FILTERED_ACCEL_X;
						break;
					case FILTER_Y:
						Param.Process_Accel =  FILTER_Y;
						Msg.Src =  SRC_FILTERED_ACCEL_Y;
						break;
					case FILTER_Z:
						Param.Process_Accel =  FILTER_Z;
						Msg.Src =  SRC_FILTERED_ACCEL_Z;
						break;
					case FFT_X:
						//implement here
						Param.Process_Accel =  FFT_X;
						Msg.Src =  SRC_FFT_ACCEL_X;
						break;
					case FFT_Y:
						//implement here  
						Param.Process_Accel =  FFT_Y;
						Msg.Src =  SRC_FFT_ACCEL_Y;
						break;
					case FFT_Z:
						Param.Process_Accel =  FFT_Z;
						Msg.Src =  SRC_FFT_ACCEL_Z;
						break;
				}
				
				Msg.Param = &Param ;
				DrawGraph(&Msg);
			}

			break;
	}
	return 0;
}
