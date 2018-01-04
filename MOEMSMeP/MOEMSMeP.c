// **************************************************************************
//
// Data Name:              MOEMSMeP.c
// Version:                12-02-a
// Programm Titel:         MEMS Measurement Program (MEMSMeP)
// Programm Language:      LabWindows/CVI 2010
// Autor:                  Malkiat Singh
// Company:			      
//
// **************************************************************************


#include "inifile.h"
#include <cvirte.h>		
#include <userint.h>

#include "MOEMSMeP_2010.h"

#include "IODevCont.h"
#include <ansi_c.h>
#include <math.h> 
#include <formatio.h>


// **************************************************************************
void changecolur(void);
void changecolour_1(void); 
void changecolour_2(void);

void index_function(void); 

int UpdateCoordinates(void);
int UpdateCounters(void);

int GUIMainSaveIniFile(void);
int GUIMainLoadIniFile(void);


// **********************Global Declaration**********************************

static int hGUIMainPanel;
static int hTabPanel0;
static IniText iniText;

int NumberOfSteps; 
int NumberOfSteps_2;

int second_direction;
int second_direction_2; 

int ConterValue = 0;  
int ConterValue_2 = 0;

int lNoOfSteps = 1;

int index;

static int counter_value_1= 0; // counter value storing variable
static int counter_value_2= 0; // counter2 value storing variable

static int load_move_state=0;

static int four_inch_SM_1[89];
static int four_inch_SM_2[89];

static float global_temp ;
static int array_index[2];

static int Ishow_toggled=0;
static int lprogrammableMove;

/**************************** SIX INCH VARIABLES ******************************/ 

static int six_inch_SM_1[289];
static int six_inch_SM_2[289];

static float die_distance_Y_2=8.6;
static float die_distance_X_2=8.6;

int Y_califactor_Linear_2=900;
int X_califactor_Circular_2=4700;




double D_cartasian_Y_mm_2;
double D_cartasian_X_mm_2;

double Fcartesian_X_array_mm_2 [18][18];
double Fcartesian_Y_array_mm_2 [18][18];

double Polar_angle_array_2[18][18];
double Polar_radius_array_2[18][18];

double radius_2;
double Angle_2;

int Steps_Linear_2[18][18];
int Steps_Circular_2[18][18]; 

int move_liner_algo_2=0;
int move_Circular_algo_2=0;

static int Ishow_toggled_2=0;
static int lprogMove_2;

int lsetRefDie_2=0;
int lclearAllSix=0;

/**************************** ALGO Variables  *****************************/
			
double Fcartesian_Y_array_mm [10][9];
double Fcartesian_X_array_mm [10][9];

static float die_distance=8.6;
static float die_distance_X=8.6;

double Polar_angle_array[10][9];
double Polar_radius_array[10][9];

int Y_califactor_Linear=900;
int X_califactor_Circular=4700; 

	
int Steps_Linear[10][9];
int Steps_Circular[10][9]; 

int Move_Programmed=0;

int lsetRefDie=0;
		
double pi = 3.141596;
double atan(double);
double angle = 0;			
double r=0;
double rad = 0;

int move_liner_algo=0;
int move_Circular_algo=0;

static int llinear_scl_val;
static int ldeviChk=0;

static int ldeviatedY;
static int ldeviatedX;

static int	lshifted_Y_1Quad;
static int	lshifted_X_1Quad;

static int	lshifted_Y_2Quad;
static int	lshifted_X_2Quad;

static int	lshifted_Y_3Quad;
static int	lshifted_X_3Quad;

static int	lshifted_Y_4Quad;
static int	lshifted_X_4Quad;



static int	linitial_Y_1Quad; 
static int	linitial_X_1Quad;

static int	linitial_Y_2Quad; 
static int	linitial_X_2Quad;
			
static int	linitial_Y_3Quad; 
static int	linitial_X_3Quad;


static int	linitial_Y_4Quad; 
static int	linitial_X_4Quad;

// **********************CORDINATE SYSTEM VARIABLES************************
				   
static float Fmcs_Y_mm; 
static float Fmcs_X_mm;

static float FmcsRad_mm;
static float FmcsAngle;

static int lcntr4M_C_Polar;
static int lcntr4M_C_CRD_SYSTEM;


// **************************************************************************
// ***** Main ***************************************************************

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((hGUIMainPanel = LoadPanel (0, "MOEMSMeP_2010.uir", PANEL)) < 0)
		return -1;
	
	GetPanelHandleFromTabPage (hGUIMainPanel, PANEL_CBITabWafer, 0, &hTabPanel0);
	
	GUIMainLoadIniFile();
	
//	hIODevCont.lRS232PortNumber = 15;
	hIODevCont.lHardwareConnected = 1;
	IODevContCreate();
	UpdateCounters();

//	CA_InitActiveXThreadStyleForCurrentThread (0 ,  COINIT_APARTMENTTHREADED );
	
	DisplayPanel (hGUIMainPanel);
	
	RunUserInterface ();
	
	GUIMainSaveIniFile();
	DiscardPanel (hGUIMainPanel); 
		

	IODevContDispose();
	
	return 0;
}


// **************************** QUIT ****************************************

int CVICALLBACK CVICB_GUIMainClose (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);

			break;
	}
	return 0;
}


// ************************** MainLEDOn **************************************


int CVICALLBACK CVICB_GUIMainLEDOn (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			IODevContSwitchLEDOn();
			break;
	}
	return 0;
}


// ***************************** MainLEDOff **********************************

int CVICALLBACK CVICB_GUIMainLEDOff (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			IODevContSwitchLEDOff();
			break;
	}
	return 0;
}


// *************************** StartMotorOne ********************************

int CVICALLBACK CVICB_GUIMainStartMotorOne (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal (panel, PANEL_CVI_NUMERIC, &lNoOfSteps);
			
			IODevContStartMotorOne(lNoOfSteps);
			UpdateCounters();
			
/*			if(second_direction == 1)
			{
				ConterValue = ConterValue + lNoOfSteps;   
				SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,ConterValue);	 // Counter Function
			}
			
			if(second_direction == 0)
			{
				ConterValue =  ConterValue - lNoOfSteps;
				SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,ConterValue);	 // Counter Function
			}
*/			
			// ATTR_DIMMED (1);
   			 //SetCtrlAttribute (hGUIMainPanel, PANEL_CBStartMotor1, ATTR_DISABLE_PANEL, 1);
			
			break;
	}
	return 0;
}


// ************************ MotorOneDirection *******************************

 int CVICALLBACK CVICB_GUIMainMotorOneDirection (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	switch (event)
	{
		
		case EVENT_COMMIT:
			
			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			//int second_direction;
			
			GetCtrlVal(hGUIMainPanel,PANEL_CBdirection,&second_direction);	   // UP CW and DOWN CCW
			IODevContDirectionMotorOne(second_direction);
			
			break;	  
	}
	return 0;
}  

//*************************** MOTOR ONE: MODE 1 ******************************


int CVICALLBACK CVI_MAIN_WINDOW_MODEI (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 
			 changecolour_1(); 
			 SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
		
			 IODevContModeONE();
			break;
	}
	return 0;
}

//*************************** MOTOR ONE: HALF MODE **************************

int CVICALLBACK CVICB_GUIMain_HalfMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolour_1();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			IODevContModeHalf();

			break;
	}
	return 0;
}

//*************************** MOTOR ONE: QUARTER STEP MODE ******************  

int CVICALLBACK CVICB_GUIMain_QuarterStepMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolour_1(); 
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			IODevContModeQuarter(); 

			break;
	}
	return 0;
}

//*************************** MOTOR ONE: EIGHT STEP MODE ********************

int CVICALLBACK CVICB_GUIMain_EightStepMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		 
			
			changecolour_1(); 
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
		
			IODevContModeEight();
			
			break;
	}
	return 0;
}


//************************** MOTOR ONE: SIXTEENTH STEP MODE *****************

int CVICALLBACK CVICB_GUIMain_SixteenthStepMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolour_1();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
		  	
			IODevContModeSixteenth();
			break;
	}
	return 0;
}

//************************** MOTOR TWO: START *******************************

int CVICALLBACK CVICB_GUIMainStartMotorTwo (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int lNoOfSteps = 1;
	
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal(panel, PANEL_CVI_NUMERIC_2, &lNoOfSteps);
			
		 	IODevContStartMotorTwo(lNoOfSteps);
			UpdateCounters();

/*			if(second_direction_2 == 1)
			{
				ConterValue_2 = ConterValue_2 + lNoOfSteps;   
				SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,ConterValue_2);	 // Counter Function
			}
			
		if(second_direction_2 == 0)
			{
				ConterValue_2 =  ConterValue_2 - lNoOfSteps;
				SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,ConterValue_2);	 // Counter Function
			}
			
*/			
			break;
	}
	return 0;
}


//************************** MOTOR TWO:DIRECTION *****************************

int CVICALLBACK CVICB_GUIMainMotorTwoDirection (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{   
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			
			GetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,&second_direction_2);
			IODevContDirectionMotorTwo(second_direction_2);
			break;
	}
	return 0;
}

//**************************  MOTOR TWO: FULL STEP MODE  *********************

int CVICALLBACK CVI_MAIN_WINDOW_MODE_2_1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			 changecolour_2();     
			 SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			 IODevContModeONE_2();
			break;
	}
	return 0;
}

//**************************  MOTOR TWO: HALF STEP MODE **********************

int CVICALLBACK CVICB_GUIMain_HalfMode_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 
			changecolour_2();     
			
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			IODevContModeHalf_2();
			break;
	}
	return 0;
}


//************************** MOTOR TWO: QUARTER STEP MODE *******************

int CVICALLBACK CVICB_GUIMain_QuarterMode_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 
			changecolour_2();     
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			IODevContModeQuarter_2();
			break;
	}
	return 0;
}

//**************************  MOTOR TWO: EIGHT STEP MODE *********************

int CVICALLBACK CVICB_GUIMain_EightMode_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolour_2();     
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			IODevContModeEight_2();
			break;
	}
	return 0;
}

//**************************  MOTOR TWO: SIXTEENTH STEP MODE *****************

int CVICALLBACK CVICB_GUIMain_SixteenthStepMode_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 
			changecolour_2();     
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			IODevContModeSixteenth_2();
			break;
	}
	return 0;
}

//*************************** UP Button ***************************************

int CVICALLBACK CVICB_GUIMain_waferUP (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
		break;
			
		case EVENT_LEFT_CLICK:
			SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,1);	   //define rotation of motor 2 as Anticlockwise by setting a value as 0 or 1
			CVICB_GUIMainMotorOneDirection (panel,control,EVENT_COMMIT, 0,0,0); 
			
			CVI_GUI_MAIN_COUNTER_1(panel,control,EVENT_COMMIT, 0,0,0); // just to update postion for new cordinate windows
//			MotorLoop();
			IODevContStartMotorOneAdv();
			UpdateCounters();
			
			break;

		case EVENT_LEFT_CLICK_UP:
			IODevContStopMotorOne();
			UpdateCounters();
			
			break;

	}
	return 0;
}


//***************************Down Button*************************************

int CVICALLBACK CVICB_GUIMainWaferDown (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
		//	SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,1);	   //define rotation of motor 2 as Anticlockwise by setting a value as 0 or 1
		//CVICB_GUIMainMotorOneDirection (panel,control,EVENT_COMMIT, 0,0,0); 
			
		break;
		
		case EVENT_LEFT_CLICK:
			SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,0);	   //define rotation of motor 2 as Anticlockwise by setting a value as 0 or 1
			CVICB_GUIMainMotorOneDirection (panel,control,EVENT_COMMIT, 0,0,0); 
//			MotorLoop_1();
			IODevContStartMotorOneAdv();
			UpdateCounters();
			
			break;

		case EVENT_LEFT_CLICK_UP:
			IODevContStopMotorOne();
			UpdateCounters();
			
			break;

	}
	return 0;
}


//***************************CW rotation Button******************************

int CVICALLBACK CVICB_GUIMainWafeRotateCW (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);

			break;
			
			
		case EVENT_LEFT_CLICK:
			SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,1);	   //define rotation of motor 2 as Anticlockwise by setting a value as 0 or 1
			CVICB_GUIMainMotorTwoDirection (panel,control,EVENT_COMMIT, 0,0,0);   
//			MotorLoop_2_1();
			IODevContStartMotorTwoAdv();
			UpdateCounters();

			break;
	
		case EVENT_LEFT_CLICK_UP:
			IODevContStopMotorTwo();
			UpdateCounters();
			
			break;
	}
	return 0;
}


//***************************CCW rotation Button*****************************

int CVICALLBACK CVICB_GUIMainWaferRotateCCW (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			 changecolur();
			 SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);

			break;
			
		case EVENT_LEFT_CLICK:
			SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,0);	   //define rotation of motor 1 as clockwise by setting a value as 0 or 1
		 	CVICB_GUIMainMotorTwoDirection (panel,control,EVENT_COMMIT, 0,0,0); 
//			MotorLoop_2_2();
			IODevContStartMotorTwoAdv();
			UpdateCounters();
			
			break;
	
		case EVENT_LEFT_CLICK_UP:
			IODevContStopMotorTwo();
			UpdateCounters();
			
			break;
	}
	return 0;
}


//******************************** MOTOR 1:FREQUENCY  *****************************

int CVICALLBACK CB_CVI_MAIN_FREQUENCY (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	int iclock;
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			GetCtrlVal (hGUIMainPanel, PANEL_CVI_Frequency, &iclock);
			IODevContSetFrq(iclock); 
			
			break;
	}
	return 0;
}

// *****************************MOTOR 2:FREQUENCY ***********************

int CVICALLBACK CB_CVI_MAIN_FREQUENCY_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int frequency_2;
	switch (event)
	{
		case EVENT_COMMIT:
			
			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			GetCtrlVal (hGUIMainPanel, PANEL_CB_FREQUENCY_2, &frequency_2);
			IODevContSetFrqTwo(frequency_2);
			
			break;
	}
	return 0;
}  


// ********************************  DEFULT MODE ****************************

int CVICALLBACK CVICB_GUI_SM1_START (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			changecolur();
			
			// ***** SM1 *****
			IODevContModeSixteenth();
			changecolour_1();
			SetCtrlAttribute(hGUIMainPanel,PANEL_CB_SixteenthStepMode,ATTR_LABEL_COLOR,VAL_DK_RED); 
			
			CVICB_GUIMainMotorOneDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
			SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,1);	   //define rotation of motor 1 as clockwise by setting a value as 0 or 1
		
			IODevContSetNumberOfSteps(100);
			SetCtrlVal (panel, PANEL_CVI_NUMERIC, 100);

			SetCtrlVal (hGUIMainPanel, PANEL_CVI_Frequency, 100000);
			IODevContSetFrq(100000);
	
			
			// ***** SM2 *****
			
			IODevContModeSixteenth_2();
			changecolour_2();
			SetCtrlAttribute(hGUIMainPanel,PANEL_CB_SixteenthMode_2,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			CVICB_GUIMainMotorTwoDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0); 
			SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,1);	   //define rotation of motor 1 as clockwise by setting a value as 0 or 1
		
			IODevContSetNumberOfStepsForMotor2(100); 
			SetCtrlVal (panel, PANEL_CVI_NUMERIC_2, 100);
		
			SetCtrlVal (hGUIMainPanel, PANEL_CB_FREQUENCY_2, 20000);
			IODevContSetFrqTwo(20000); 
		
			break;
	}
	return 0;
}


// **************************************************************************
// *******************************MENU **************************************

void CVICALLBACK CBI_About (int menuBar, int menuItem, void *callbackData,
		int panel)
{
		switch (menuItem)
		{
			case MENUBAR_CB_About_CB_About_child:
				printf("Fraunhofer ENAS\nTU Chemnitz\n");
			break;
		}
	    
}

void CVICALLBACK CBI_GUI_MAIN_INDICATORS_CHILD (int menuBar, int menuItem, void *callbackData,
		int panel)
{
		switch (menuItem)
		{
			case MENUBAR_DB_Indicators_CB_CHILD_INDICATORS:
				//printf("menu child");
			break;
		}
}			 

void CVICALLBACK CBI_GUI_HELP_CHILD (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	switch (menuItem)
		{
			case MENUBAR_CB_help_CB_Help_child:
				printf("Rerence commands in AT Mega128 are:help\n about\nAnd so on\n");
			break;
		}
}

void CVICALLBACK ConfigTestCallback (int menubar, int menuItem,
                                     void *callbackData, int panel)
{
	switch (menuItem)
		{
			case MENUBAR_CB_About_CB_About_child:
				printf("menu child");
			break;
		 }
}


// **************************************************************************
// ******************************* Counter **********************************

int CVICALLBACK CVI_GUI_MAIN_COUNTER_1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int  lCT_R_S;
		

	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER, &lCT_R_S);
//			counter_value_1 = eventData1;
			IODevContCounterSMOneSet(lCT_R_S);
			UpdateCounters();
			
			break;
	}
	return 0;
}


// **************************************************************************

int CVICALLBACK CVI_GUI_MAIN_COUNTER_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int lCT_A_S;
		

	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,&lCT_A_S);
//		 	counter_value_2=eventData1;
			IODevContCounterSMTwoSet(lCT_A_S);
			UpdateCounters();
			
			break;
	}
	return 0;
}


// ******************************* COUNTER RESET ****************************

int CVICALLBACK CBI_MAIN_COUNTER_RESET_1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
//			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,(ConterValue=0));
//			printf("Counter One is reset \n"); 
			IODevContCounterSMOneReset();
			UpdateCounters();
			UpdateCoordinates(); 
			
			break;
	}
	return 0;
}


// **************************************************************************

int CVICALLBACK CBI_MAIN_COUNTER_RESET_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
//			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,(ConterValue_2=0));
//			printf("Counter Two is reset \n");
			IODevContCounterSMTwoReset();
			UpdateCounters();
			UpdateCoordinates(); 
			
			break;
	}
	return 0;
}


// ********************************* CALIBRATE **************************

int CVICALLBACK CVICB_GUIMainCalibrate_Y (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			  load_move_state=5;
			break;
	}
	return 0;
}


// **************************************************************************

int CVICALLBACK CVICB_GUIMain_CALIBRATE_X (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				load_move_state=4;
			break;
	}
	return 0;
}

// **************************************************************************
//*************************** FOUR INCH WAFER MAP VARIABLES *****************

static int lprecounter1;
static int lprecounter2; 
			
static int lStepCountSM1;
static int lStepCountSM2;
double D_rows;
double D_coloums;

		
//*************************** FOUR INCH WAFER MAP ***************************

int CVICALLBACK CVICB_GUItabFourInchWaferMap (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	float	die_2_die_X_mm;
	float	die_2_die_Y_mm;
	
	double	Cal_R_S_per_mm;
	double	Cal_A_S_per_deg;
	
	double	WC_X_mm;
	double	WC_Y_mm;
	double	WC_R_mm;
	double	WC_A_deg;
	
	double	MC_X_mm;
	double	MC_Y_mm;
	double	MC_R_mm;
	double	MC_A_deg;
	
	double	WCT_XS_mm;
	double	WCT_YS_mm;
	double	WCT_AS_deg;
	
	double	cos2sin2;
	
	int		CT_R_S_Ist;
	int		CT_A_S_Ist;
	
	int		CT_R_S_Soll;
	int		CT_A_S_Soll;

	int		MoveMotors = 0;

	
	switch (event)
	{
		case EVENT_COMMIT:
			// eventData2 = Col
			// eventData1 = Row
			
			GetCtrlVal (hTabPanel0, TABPANEL_CVI_X_DIE_2_DIE,	&die_2_die_X_mm);
			GetCtrlVal (hTabPanel0, TABPANEL_CVI_DIE_2_DIE,		&die_2_die_Y_mm);
			
			GetCtrlVal (hTabPanel0, TABPANEL_CB_Y_CALI_FACTOR,	&Cal_R_S_per_mm);
			GetCtrlVal (hTabPanel0, TABPANEL_CB_X_CALI_FACTOR,	&Cal_A_S_per_deg);

			WC_X_mm =  (eventData2 - 6) * die_2_die_X_mm + die_2_die_X_mm / 2.0;
			WC_Y_mm = -(eventData1 - 5) * die_2_die_Y_mm;
			
			WC_R_mm = sqrt(WC_X_mm * WC_X_mm + WC_Y_mm * WC_Y_mm);
			WC_A_deg = atan2(WC_Y_mm, WC_X_mm) * 180.0/pi;
		
			SetCtrlVal (hGUIMainPanel, PANEL_WM_X_mm,  WC_X_mm);
			SetCtrlVal (hGUIMainPanel, PANEL_WM_Y_mm,  WC_Y_mm);
			SetCtrlVal (hGUIMainPanel, PANEL_WM_R_mm,  WC_R_mm);
			SetCtrlVal (hGUIMainPanel, PANEL_WM_A_deg, WC_A_deg);

			GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER,   &CT_R_S_Ist);
			GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER_2, &CT_A_S_Ist);
			
			GetCtrlVal (hGUIMainPanel, PANEL_TB_MoveMotors, &MoveMotors);			
			
//			CT_R_S_Soll = WC_R_mm  * (double) Cal_R_S_per_mm;
//			CT_A_S_Soll = WC_A_deg * (double) Cal_A_S_per_deg ;
			
			// Transformation
			GetCtrlVal (hGUIMainPanel, PANEL_WCT_XS_mm,	 &WCT_XS_mm);
			GetCtrlVal (hGUIMainPanel, PANEL_WCT_YS_mm,	 &WCT_YS_mm);
			GetCtrlVal (hGUIMainPanel, PANEL_WCT_AS_deg, &WCT_AS_deg);
			
			cos2sin2 = cos(WCT_AS_deg*pi/180.0) * cos(WCT_AS_deg*pi/180.0) + sin(WCT_AS_deg*pi/180.0) * sin(WCT_AS_deg*pi/180.0);
			
			MC_X_mm =  cos(WCT_AS_deg*pi/180.0)/cos2sin2*WC_X_mm + sin(WCT_AS_deg*pi/180.0)/cos2sin2*WC_Y_mm + ( cos(WCT_AS_deg*pi/180.0)*WCT_XS_mm+sin(WCT_AS_deg*pi/180.0)*WCT_YS_mm)/cos2sin2;
			MC_Y_mm = -sin(WCT_AS_deg*pi/180.0)/cos2sin2*WC_X_mm + cos(WCT_AS_deg*pi/180.0)/cos2sin2*WC_Y_mm + (-sin(WCT_AS_deg*pi/180.0)*WCT_XS_mm+cos(WCT_AS_deg*pi/180.0)*WCT_YS_mm)/cos2sin2;

			MC_R_mm  = sqrt (MC_X_mm * MC_X_mm + MC_Y_mm * MC_Y_mm);
			MC_A_deg = atan2(MC_Y_mm, MC_X_mm) * 180.0/pi;

			CT_R_S_Soll = MC_R_mm  * Cal_R_S_per_mm;
			CT_A_S_Soll = MC_A_deg * Cal_A_S_per_deg;
			
			
			if (MoveMotors == 1)
			{
				// ***** Radius *****
				if((CT_R_S_Soll - CT_R_S_Ist) < 0)	 // greater than1   || second_direction == 1
				{
//					printf("mode one is excuting");
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,0);
					CVICB_GUIMainMotorOneDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					
					IODevContStartMotorOne(abs(CT_R_S_Soll - CT_R_S_Ist));
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,CT_R_S_Soll);
				}
				
			 	if((CT_R_S_Soll - CT_R_S_Ist) > 0)	  // if value is less than 0   || second_direction == 0
				{
//					 printf("mode Two is excuting"); 
					 SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,1);
					 CVICB_GUIMainMotorOneDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					
					IODevContStartMotorOne(abs(CT_R_S_Soll - CT_R_S_Ist));
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,CT_R_S_Soll);
		  		}
				
				if ((CT_R_S_Soll - CT_R_S_Ist) == 0)
				{
//					 printf("You are at defined point on Linear scale");
				}

				
				// ***** Angle *****
				if((CT_A_S_Soll - CT_A_S_Ist) < 0)	 // greater than1   || second_direction == 1
				{
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,0);
					CVICB_GUIMainMotorTwoDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					IODevContStartMotorTwo(abs(CT_A_S_Soll - CT_A_S_Ist));
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,CT_A_S_Soll);
				}
				
			 	if((CT_A_S_Soll - CT_A_S_Ist) > 0)	  // if value is less than 0   || second_direction == 0
				{
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,1);
					CVICB_GUIMainMotorTwoDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
						   
					IODevContStartMotorTwo(abs(CT_A_S_Soll - CT_A_S_Ist));
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,CT_A_S_Soll);
		  		}
				
				if ((CT_A_S_Soll - CT_A_S_Ist) == 0)
				{
//					 printf("You are at defined point on Radial scale");
				}
				
				// ***** Update Koordinates *****
				UpdateCounters();
			}
			
			    
/*			changecolur();
			SetCtrlAttribute(panel,control,ATTR_LABEL_COLOR,VAL_DK_RED);
			
			index= (((eventData1-1)*10+eventData2)-1) ; //index=((row-1)10+coloum)-1
	
		    GetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER, & counter_value_1);
			GetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,& counter_value_2);
			
			
	if(ldeviChk==3)
	{
 		printf("eventDataY_Y=%d,eventDataX=%d\n",eventData1,eventData2);
		
		ldeviatedY= eventData1;
		ldeviatedX= eventData2; 
	}
			
//**************************** SAVE ****************************************
			
		if(load_move_state==1) //SAVE
		{
			SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(eventData2,eventData1),ATTR_CMD_BUTTON_COLOR,VAL_DK_RED);   //ATTR_CELL_DIMMED , ATTR_CMD_BUTTON_COLOR (Cell)
			printf("index=%d\n",index);	
			
			four_inch_SM_1[index]=counter_value_1;		   //particular selected index will have a value of a counter_value_1 
			four_inch_SM_2[index]=counter_value_2;		   //index= (((eventData1-1)*10+eventData2)-1) ; //index=((row-1)10+coloum)-1

		}
		
//**************************** CALIBRATE *************************************
		
		 if(load_move_state==4) //CALIBRATE   X= circular
		{
			SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(eventData2,eventData1),ATTR_CMD_BUTTON_COLOR,VAL_YELLOW);
			int lcaliDiceX;
			printf("Please select the 2nd dice on 90 Degree Circular scale\n"); 
			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,(ConterValue_2=0)); 
			printf("Counter Two is reset \n");
			lcaliDiceX=abs( counter_value_2) ;   //	counter_value_1 variable for counter value  
			SetCtrlVal(panel,TABPANEL_CB_X_CALI_FACTOR,lcaliDiceX);
			X_califactor_Circular=lcaliDiceX ;
			
		}

		 if(load_move_state==5) //CALIBRATE FOR Y AXIS i,e linear Scale
		{
			int Fcali1dice;
	 
			SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(eventData2,eventData1),ATTR_CMD_BUTTON_COLOR,VAL_CYAN);   //ATTR_CELL_DIMMED , ATTR_CMD_BUTTON_COLOR (Cell)

			printf("Please select the 2nd next dice on linear scale\n"); 
			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,(ConterValue=0));
			printf("Counter One is reset \n");
		
			Fcali1dice=abs(counter_value_1/2);   //	counter_value_1 variable for counter value  
			//printf("Fcali1dice=%d\n",Fcali1dice);
		
			SetCtrlVal(panel,TABPANEL_CB_Y_CALI_FACTOR,Fcali1dice);
			Y_califactor_Linear=Fcali1dice ;
	
		}
  
//***************************************************************************
		
		if(load_move_state==2) //MOVE
		{
			lprecounter1=four_inch_SM_1[index];		 //particular selected index will have a value of a lcounted steps i,e 10
			lprecounter2=four_inch_SM_2[index];

			{
				if((lprecounter1-counter_value_1)<0)	 // greater than1   || second_direction == 1
				{
					printf("mode one is excuting");
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,0);
					CVICB_GUIMainMotorOneDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					lStepCountSM1 = abs(lprecounter1-counter_value_1);
					IODevContStartMotorOne(lStepCountSM1);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,lprecounter1);
				}
				
			 	if((lprecounter1-counter_value_1)>0)	  // if value is less than 0   || second_direction == 0
				{
					 printf("mode Two is excuting"); 
					 SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,1);
					 CVICB_GUIMainMotorOneDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					lStepCountSM1 = abs(lprecounter1-counter_value_1);
					IODevContStartMotorOne(lStepCountSM1);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,lprecounter1);
		  		}
				
				if ((lprecounter1-counter_value_1)==0)
				{
					 printf("You are at defined point on Linear scale");
				}
		

	//**************************** MOTOR SECOND LOOPS *************************** 				
				
					if((lprecounter2-counter_value_2)<0)	 // greater than1   || second_direction == 1
				{
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,0);
					CVICB_GUIMainMotorTwoDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					lStepCountSM2 = abs(lprecounter2-counter_value_2);
					IODevContStartMotorTwo(lStepCountSM2);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,lprecounter2);
				}
				
			 	if((lprecounter2-counter_value_2)>0)	  // if value is less than 0   || second_direction == 0
				{
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,1);
					CVICB_GUIMainMotorTwoDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
						   
					lStepCountSM2 = abs(lprecounter2-counter_value_2);
					IODevContStartMotorTwo(lStepCountSM2);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,lprecounter2);
		  		}
				
				if ((lprecounter2-counter_value_2)==0)
				{
					 printf("You are at defined point on Radial scale");
				}
				
			}	 
	
		}
		
		if(load_move_state==3) //CLEAR
		{
			SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(eventData2,eventData1),ATTR_CMD_BUTTON_COLOR,VAL_OFFWHITE);   //ATTR_CELL_DIMMED , ATTR_CMD_BUTTON_COLOR (Cell)
			printf("index=%d\n",index);	
			
			four_inch_SM_1[index]=0;		   //particular selected index will have a value 0 
			four_inch_SM_2[index]=0;		   //index= (((eventData1-1)*10+eventData2)-1) ; //index=((row-1)10+coloum)-1
		}
		
		
		else   //READ VALUE
		{
			if(Ishow_toggled==0)
			{
		  		printf("READ:Element[%d] = %d\n", index, four_inch_SM_1[index] );
				printf("READ:Element[%d] = %d\n", index, four_inch_SM_2[index] );
			}

// x	Columns		D_coloums
// y	Rows		Temp1

			if(Ishow_toggled==1)
			{
				if (index<10)	// Row 0
					D_rows = 0;
				else
					D_rows = ((index / 10));		//x-vlaue, Row 1 to 8
				
				if ((index - D_rows * 10) == 0)	   // Column 0
					D_coloums = 0;
				else
					if(D_rows==0)			  // Row 0
						D_coloums=	(index);	//y-value
					else
						D_coloums=	(index - D_rows * 10);	//y-value Row 1 to 8
				
				printf("READ CARTASIAN X:Element[%d][%f,%f] = %.2f\n", index, D_coloums, D_rows, Fcartesian_X_array_mm[(int)D_coloums][(int)D_rows]);	
				printf("READ CARTASIAN Y:Element[%d] = %.2f\n", index, Fcartesian_Y_array_mm[(int)D_coloums][(int)D_rows]);
				
				printf("READ ANGLE:Element[%d] = %.2f\n", index, Polar_angle_array[(int)D_coloums][(int)D_rows]);
				printf("READ POLAR RADIUS:Element[%d] = %.2f\n", index, Polar_radius_array[(int)D_coloums][(int)D_rows]);
				printf("READ STEPS RADIUS:Element[%d] = %d\n", index, Steps_Linear[(int)D_coloums][(int)D_rows]);
				
				printf("READ STEPS ANGLE:Element[%d] = %.d\n", index, Steps_Circular[(int)D_coloums][(int)D_rows]); 
				
			}
		}

		if(lsetRefDie==1)
			
		{
			int k,l;
			for(k=1;k<11;k++)
			{
				for(l=1;l<10;l++)
				{
					SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(k,l),ATTR_CMD_BUTTON_COLOR,VAL_OFFWHITE);   //ATTR_CELL_DIMMED , ATTR_CMD_BUTTON_COLOR (Cell)            
				}
			}
					
				lsetRefDie=0 ;
				SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(eventData2,eventData1),ATTR_CMD_BUTTON_COLOR,VAL_MAGENTA);
				
			
			if (index<10)	// Row 0
					D_rows = 0;
				else
					D_rows = ((index / 10));		//x-vlaue, Row 1 to 8
				
				if ((index - D_rows * 10) == 0)	   // Column 0
					D_coloums = 0;
				else
					if(D_rows==0)			  // Row 0
						D_coloums=	(index);	//y-value
					else
						D_coloums=	(index - D_rows * 10);	//y-value Row 1 to 8
				
		  	ConterValue	=Steps_Linear[(int)D_coloums][(int)D_rows];
			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,(ConterValue));
			printf("Counter One is reset \n");

			ConterValue_2	=Steps_Circular[(int)D_coloums][(int)D_rows]; 
			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,(ConterValue_2));
			printf("Counter Two is reset \n");
			
		}
	
			
//***************************************************************************
						//PROGRAM MOVE//
//***************************************************************************			
			
	if(lprogrammableMove==1||lprogMove_2==1) //MOVE   Programmable
		{	
			
			SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(eventData2,eventData1),ATTR_CMD_BUTTON_COLOR,VAL_LT_GRAY);   //ATTR_CELL_DIMMED , ATTR_CMD_BUTTON_COLOR (Cell) 
			if (index<10)	// Row 0
					D_rows = 0;
				else
					D_rows = ((index / 10));		//x-vlaue, Row 1 to 8
				
				if ((index - D_rows * 10) == 0)	   // Column 0
					D_coloums = 0;
				else
					if(D_rows==0)			  // Row 0
						D_coloums=	(index);	//y-value
					else
						D_coloums=	(index - D_rows * 10);	//y-value Row 1 to 8

			lprecounter1=Steps_Linear[(int)D_coloums][(int)D_rows];	 //particular selected index will have a value of a lcounted steps i,e 10
			lprecounter2=Steps_Circular[(int)D_coloums][(int)D_rows];
			
				if((lprecounter1-counter_value_1)<0)	 // greater than1   || second_direction == 1
				{
					printf("mode one is excuting");
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,0);
					CVICB_GUIMainMotorOneDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					lStepCountSM1 = abs(lprecounter1-counter_value_1);
					IODevContStartMotorOne(lStepCountSM1);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,lprecounter1);
				}
				
			 	if((lprecounter1-counter_value_1)>0)	  // if value is less than 0   || second_direction == 0
				{
					 printf("mode Two is excuting"); 
					 SetCtrlVal(hGUIMainPanel,PANEL_CBdirection,1);
					 CVICB_GUIMainMotorOneDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					lStepCountSM1 = abs(lprecounter1-counter_value_1);
					IODevContStartMotorOne(lStepCountSM1);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,lprecounter1);
		  		}
				
				if ((lprecounter1-counter_value_1)==0)
				{
					 printf("You are at defined point_Circular");//	 Linear
				}
		

	//**************************** MOTOR SECOND LOOPS *************************** 				
				
					if((lprecounter2-counter_value_2)<0)	 // greater than1   || second_direction == 1
				{
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,0);
					CVICB_GUIMainMotorTwoDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
					
					lStepCountSM2 = abs(lprecounter2-counter_value_2);
					IODevContStartMotorTwo(lStepCountSM2);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,lprecounter2);
				}
				
			 	if((lprecounter2-counter_value_2)>0)	  // if value is less than 0   || second_direction == 0
				{
					SetCtrlVal(hGUIMainPanel,PANEL_CBdirectionMotor2,1);
					CVICB_GUIMainMotorTwoDirection (hGUIMainPanel,control,EVENT_COMMIT, 0,0,0);
						   
					lStepCountSM2 = abs(lprecounter2-counter_value_2);
					IODevContStartMotorTwo(lStepCountSM2);
					SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,lprecounter2);
		  		}
				
				if ((lprecounter2-counter_value_2)==0)
				{
					 printf("You are at defined point_Linear");// on Radial scale but now opposite due to change in steps linear into steps circular
				}
		
		  }
		  UpdateCoordinates(); 
		load_move_state=0;
*/		
		break;
	}
   return 0; 
}


//*************** MANUAL CALIBRATION FACTOR ADDITION ************************


int CVICALLBACK CBI_Y_CALI_FACTOR (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel,TABPANEL_CB_Y_CALI_FACTOR  ,&Y_califactor_Linear);
	 		 printf("Calibration Y factor is %d\n",Y_califactor_Linear);

			break;
	}
	return 0;
}

int CVICALLBACK CBI_X_CALI_FACTOR (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				GetCtrlVal(panel,TABPANEL_CB_X_CALI_FACTOR,&X_califactor_Circular);
	 		 printf("Calibration X factor is %d \n",X_califactor_Circular);

			break;
	}
	return 0;
}

//**************************** PROGRAMMED_MOVE BOTH *************************

int CVICALLBACK CBI_BOTH_PROG_MOVE (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
				  lprogrammableMove=1;
			break;
	}
	return 0;
}


// ************************************************************************** 
//************************** SIX INCH WAFER MAP *****************************

int CVICALLBACK CVICB_GUItabSixInchWaferMap (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
		
	switch (event)
	{
		case EVENT_COMMIT:
			index= (((eventData1-1)*10+eventData2)-1) ; //index=((row-1)10+coloum)-1
	
			GetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER, & counter_value_1);
			GetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,& counter_value_2);
			
	if(lclearAllSix==1) //CLEAR
		{
		int i,k,l;
		   for ( i = 0; i < 329; i++ )
		   {
		      six_inch_SM_1[ i ] = 0; /* set element at location i to i + 100 */
		   }
			for ( i = 0; i < 329; i++ )
		   {
		      six_inch_SM_2[ i ] = 0; /* set element at location i to i + 100 */
		   }		
		}
	else   //READ VALUE
		{
			if(Ishow_toggled_2==0)
			{
		  		printf("READ:Element[%d] = %d\n", index, six_inch_SM_1[index] );
				printf("READ:Element[%d] = %d\n", index, six_inch_SM_2[index] );
			}

// x	Columns		D_coloums
// y	Rows		Temp1

			if(Ishow_toggled_2==1)
			{
				if (index<10)	// Row 0
					D_rows = 0;
				else
					D_rows = ((index / 10));		//x-vlaue, Row 1 to 8
				
				if ((index - D_rows * 10) == 0)	   // Column 0
					D_coloums = 0;
				else
					if(D_rows==0)			  // Row 0
						D_coloums=	(index);	//y-value
					else
						D_coloums=	(index - D_rows * 10);	//y-value Row 1 to 8
				
				printf("READ:X= Element[%d][%f,%f] = %.2f\n", index, D_coloums, D_rows, Fcartesian_X_array_mm_2[(int)D_coloums][(int)D_rows]);	
				printf("READ:Y= Element[%d] = %.2f\n", index, Fcartesian_Y_array_mm_2[(int)D_coloums][(int)D_rows]);
				
				printf("READ:POLAR ANGLE = Element[%d] = %.2f\n", index, Polar_angle_array_2[(int)D_coloums][(int)D_rows]);
				printf("READ:POLAR RADIUS =Element[%d] = %.2f\n", index, Polar_radius_array_2[(int)D_coloums][(int)D_rows]);
				printf("READ:Steps_Linear = Element[%d] = %d\n", index, Steps_Linear_2[(int)D_coloums][(int)D_rows]);
				
				printf("READ:Steps_Circular = Element[%d] = %.d\n", index, Steps_Circular_2[(int)D_coloums][(int)D_rows]); 
				
			}
		}
		
		if(lsetRefDie==1)
		{
			if (index<10)	// Row 0
					D_rows = 0;
				else
					D_rows = ((index / 10));		//x-vlaue, Row 1 to 8
				
				if ((index - D_rows * 10) == 0)	   // Column 0
					D_coloums = 0;
				else
					if(D_rows==0)			  // Row 0
						D_coloums=	(index);	//y-value
					else
						D_coloums=	(index - D_rows * 10);	//y-value Row 1 to 8
				
		  	ConterValue	=Steps_Linear[(int)D_coloums][(int)D_rows];
			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER,(ConterValue));
			printf("Counter One is reset \n");

			ConterValue_2	=Steps_Circular[(int)D_coloums][(int)D_rows]; 
			SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2,(ConterValue_2));
			printf("Counter Two is reset \n");
		}
		
		break;
	}
   return 0; 
}


// **************************************************************************
// ********************* SIX INCH WAFER  BUTTONS ****************************

int CVICALLBACK CVI_SLCT_DIE_2_DIE_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			  GetCtrlVal(panel,TABPANEL_2_CVI_DIE_2_DIE_2  ,&die_distance_Y_2);
	 		 printf("die distance is %.1f\n",die_distance_Y_2);
			break;
	}
	return 0;
}

// **************************************************************************
int CVICALLBACK CVI_SLCT_DIE_2_DIE_4_X_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   GetCtrlVal(panel,TABPANEL_2_CVI_X_DIE_2_DIE_2,&die_distance_X_2);
	 		 printf("die distance is %.1f\n",die_distance_X_2);
			break;
	}
	return 0;
}

// ************************************************************************** 
int CVICALLBACK CBI_GUI_TAB_CLEAR_ALL_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			lclearAllSix=1;
			break;
	}
	return 0;
}

// **************************************************************************
int CVICALLBACK CBI_TOGGLE_SHOW_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					
			 int pressed_2=0;
			 
			GetCtrlVal ( panel,TABPANEL_2_CB_TOOGLE_SHOW_FILL_2, &pressed_2);
			  if (pressed_2==1)
			  {
			   Ishow_toggled_2=1;
			  }
			   else
			   {
				   Ishow_toggled_2=0;
			   }
			break;
	}
	return 0;
}

// **************************************************************************
int CVICALLBACK CBI_X_CALI_FACTOR_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal(panel,TABPANEL_2_CB_X_CALI_FACTOR_2,&X_califactor_Circular_2);
	 		 printf("Calibration X factor is %d \n",X_califactor_Circular_2);

			break;
	}
	return 0;
}

// **************************************************************************
int CVICALLBACK CBI_Y_CALI_FACTOR_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal(panel,TABPANEL_2_CB_Y_CALI_FACTOR_2,&Y_califactor_Linear_2);
	 		 printf("Calibration Y factor is %d\n",Y_califactor_Linear_2);

			break;
	}
	return 0;
}

// ************************************************************************** 
 int CVICALLBACK CBI_PROG_MOVE_TGL_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal(panel,TABPANEL_2_CB_PROG_MOVE_TG_2,&lprogMove_2);
	 		// printf("programmableMove is %d\n",lprogrammableMove);

			break;
	}
	return 0;
}

 // ************************************************************************** 
int CVICALLBACK CBI_SET_REFERENCE_DIE_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal(panel,TABPANEL_2_CB_SET_REF_DIE_2,&lsetRefDie_2);
			  printf("abc=%d\n",lsetRefDie_2);

			break;
	}
	return 0;
}

// **************************************************************************
// ******************* FOUR INCH WAFER TAB BUTTONS **************************

int CVICALLBACK CBI_GUI_TAB_SAVE_MOVE_STATE (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				load_move_state=1;
			break;
	}
	return 0;
}

int CVICALLBACK CBI_GUI_TAB_MOVE_1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 	load_move_state=2;
			break;
	}
	return 0;
}

// ******************************* CLEAR ************************************

int CVICALLBACK CBI_GIU_TAB_CLEAR (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 	load_move_state=3;
			break;
	}
	return 0;
}

// ******************************* CLEAR ALL ********************************


int CVICALLBACK CBI_GUI_TAB_CLEAR_ALL (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			int i,k,l;
		   for ( i = 0; i < 89; i++ )
		   {
		      four_inch_SM_1[ i ] = 0; /* set element at location i to i + 100 */
		   }
   
			for ( i = 0; i < 89; i++ )
		   {
		      four_inch_SM_2[ i ] = 0; /* set element at location i to i + 100 */
		   }		
			
			for(k=1;k<11;k++)
			{
				for(l=1;l<10;l++)
				{
					SetTableCellAttribute (panel, TABPANEL_CBIWaferMap_4_Inch, MakePoint(k,l),ATTR_CMD_BUTTON_COLOR,VAL_OFFWHITE);   //ATTR_CELL_DIMMED , ATTR_CMD_BUTTON_COLOR (Cell)            
				}
			}
			break;
	}
	return 0;
}

// ************************* SET_REFERENCE_DIE ******************************

int CVICALLBACK CBI_SET_REF_CMD (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			lsetRefDie=1;
			break;
	}
	return 0;
}


// ******************************* SAVE DATA ********************************

int CVICALLBACK CBI_GUI_TAB_SAVE_DATA (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			FILE *save_array = fopen("D:\\SAVE ARRAY\\array_data.txt", "w");
			int i;
	 for ( i = 3; i < 89; i++ )
		   {
		        //if 
			  	fprintf(save_array, "Chip%d have X Counter at= %d\t Y Counter at %d\n",i,four_inch_SM_1[i],four_inch_SM_2[i]); //saved array is name of defined file 
		   }
   
			fclose(save_array);
			break;
	}
	return 0;
}

// ************************* DIE DISTANCE SELECTION ************************

int CVICALLBACK CVI_SLCT_DIE_2_DIE (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 GetCtrlVal(panel,TABPANEL_CVI_DIE_2_DIE  ,&die_distance);
	 		 printf("die distance is %.1f\n",die_distance);

			break;
	}
	return 0;
}


int CVICALLBACK CVI_SLCT_DIE_2_DIE_4_X (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 
			 GetCtrlVal(panel,TABPANEL_CVI_X_DIE_2_DIE,&die_distance_X);
	 		 printf("die distance is %.2f\n",die_distance_X);

			break;
	}
	return 0;
}

 //**************************** TOGGLE SHOW FILLED  ********************************
 
 



// **************************************************************************
 						  //DEVIATION CALCULATION ALGO//
// ************************************************************************** 

 int CVICALLBACK CB_SUB_PENL_CHK_DEVIATION (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			  ldeviChk=3;

			break;
	}
	return 0;
}
 

// **************************************************************************
 						 //HCTL DECODER FUNCTIONS//
// **************************************************************************

int CVICALLBACK CBI_LINEAR_SCALE (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			GetCtrlVal(hGUIMainPanel,PANEL_CB_LINEAR_SCALE,&eventData1);
			llinear_scl_val=eventData1;

			break;
	}
	return 0;
}


int CVICALLBACK CBI_MEGA_ENCODER_CUNTR (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			/*int value; 
			FILE *x_file=fopen("C:\\Users\\s.malkiat.ENAS.000\\Desktop\\New Text Document.txt","r"); 
			fscanf (x_file,"%d",&value);
			fclose(x_file); */
		//	SetCtrlVal(hGUIMainPanel,PANEL_CB_LINEAR_SCALE,value);
			IODevContmega_encoder_counter(); 
			break;
	}
	return 0;
}


int CVICALLBACK CBI_GET_CNT (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int x;
			
			IODevContX_axis_get_count();
			x=IODevContX_axis_get_count();  
			printf("x=%d\n",x);
			
			SetCtrlVal(hGUIMainPanel,PANEL_CB_LINEAR_SCALE,x);
			break;
	}
	return 0;
}


int CVICALLBACK CBI_SWITCH (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			IODevConts_switch();  
			break;
	}
	return 0;
}


int CVICALLBACK CBI_X_RESET (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   IODevContx_axis_reset();
			break;
	}
	return 0;
}


// **************************************************************************
// ************************ Change Colour Functions ************************* 

void changecolur()
{
	
		SetCtrlAttribute(hGUIMainPanel,PANEL_CBStartMotor1,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CBdirectionMotor2,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CBdirection,ATTR_LABEL_COLOR,VAL_BLACK);
		
		SetCtrlAttribute(hGUIMainPanel,PANEL_CBStartMotor2,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_CCWButton,ATTR_LABEL_COLOR,VAL_BLACK);
		
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_CWButton,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_DownButton,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_UpButton,ATTR_LABEL_COLOR,VAL_BLACK);
		//SetCtrlAttribute(hGUIMainPanel,PANEL_CB_Calibrate ,ATTR_LABEL_COLOR,VAL_BLACK);
//		SetCtrlAttribute(hGUIMainPanel,PANEL_TEST_TOGGLEBUTTON,ATTR_LABEL_COLOR,VAL_BLACK);
		
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_DefultSM_1,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_FREQUENCY_2,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CVI_Frequency,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CVI_NUMERIC,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CVI_NUMERIC_2,ATTR_LABEL_COLOR,VAL_BLACK);

 }

void changecolour_1()
{
	
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_Mode1,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_HalfMode,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_QuarterStepMode,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_EightStepMode,ATTR_LABEL_COLOR,VAL_BLACK); 
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_SixteenthStepMode,ATTR_LABEL_COLOR,VAL_BLACK);
		
 }

void changecolour_2()
{
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_Mode2_1,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_HalfMode_2,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_Quartermode_2,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_EightMode_2,ATTR_LABEL_COLOR,VAL_BLACK);
		SetCtrlAttribute(hGUIMainPanel,PANEL_CB_SixteenthMode_2,ATTR_LABEL_COLOR,VAL_BLACK);
 }


//**************************** CANVAS *************************************

int CVICALLBACK CBI_CANVAS (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)

{			   
	int bitmapID; 
//	GetBitmapFromFile ( "C:\\Users\\s.malkiat.ENAS.000\\Desktop\\IMG_5485.JPG",&bitmapID);
//	 CanvasDrawBitmap ( hGUIMainPanel, PANEL_CB_CANVAS,bitmapID,  VAL_ENTIRE_OBJECT , VAL_ENTIRE_OBJECT );
	return 0;
}



//*************************************************************************
					 //CORDINATE SYSTEM FUNCTIONS//
//*************************************************************************
					 //MACHINE CORDINATE SYSTEM
// **************************************************************************
// **************************************************************************


int UpdateCoordinates(void)
{
	int		Counter_R_S;
	int		Counter_A_S;

	double	Cal_R_S_mm;
	double	Cal_A_S_deg;
	
	double	MC_X_mm;
	double	MC_Y_mm;
	
	double	MC_R_mm;
	double	MC_A_deg;
	
	double	WC_X_mm;
	double	WC_Y_mm;
	double	WC_R_mm;
	double	WC_A_deg;
	
	double	WCT_XS_mm;
	double	WCT_YS_mm;
	double	WCT_AS_deg;

	
	GetCtrlVal (hTabPanel0, TABPANEL_CB_Y_CALI_FACTOR,	&Cal_R_S_mm);
	GetCtrlVal (hTabPanel0, TABPANEL_CB_X_CALI_FACTOR,	&Cal_A_S_deg);
	
	GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER, 	&Counter_R_S);
	GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER_2, 	&Counter_A_S);
	
	GetCtrlVal (hTabPanel0, TABPANEL_CB_Y_CALI_FACTOR, &Cal_R_S_mm);
	GetCtrlVal (hTabPanel0, TABPANEL_CB_X_CALI_FACTOR, &Cal_A_S_deg);
	
	GetCtrlVal (hGUIMainPanel, PANEL_WCT_XS_mm,	 &WCT_XS_mm);
	GetCtrlVal (hGUIMainPanel, PANEL_WCT_YS_mm,	 &WCT_YS_mm);
	GetCtrlVal (hGUIMainPanel, PANEL_WCT_AS_deg, &WCT_AS_deg);


	MC_R_mm  = (double) Counter_R_S / Cal_R_S_mm;
	MC_A_deg = (double) Counter_A_S / Cal_A_S_deg;
	
	MC_X_mm = MC_R_mm * cos(MC_A_deg * pi/180.0);
	MC_Y_mm = MC_R_mm * sin(MC_A_deg * pi/180.0);
	
	WC_X_mm = +MC_X_mm * cos(WCT_AS_deg * pi/180.0) - MC_Y_mm * sin(WCT_AS_deg * pi/180.0) - WCT_XS_mm; 
	WC_Y_mm = +MC_X_mm * sin(WCT_AS_deg * pi/180.0) + MC_Y_mm * cos(WCT_AS_deg * pi/180.0) - WCT_YS_mm;
	
	WC_R_mm  = sqrt(WC_X_mm * WC_X_mm + WC_Y_mm * WC_Y_mm);
	WC_A_deg = atan2(WC_Y_mm, WC_X_mm) * 180.0/pi;
	
	SetCtrlVal (hGUIMainPanel, PANEL_MC_R_mm, MC_R_mm);
	SetCtrlVal (hGUIMainPanel, PANEL_MC_A_deg, MC_A_deg);

	SetCtrlVal (hGUIMainPanel, PANEL_MC_X_mm, MC_X_mm);
	SetCtrlVal (hGUIMainPanel, PANEL_MC_Y_mm, MC_Y_mm);

	
	SetCtrlVal (hGUIMainPanel, PANEL_WC_R_mm, WC_R_mm);
	SetCtrlVal (hGUIMainPanel, PANEL_WC_A_deg, 	WC_A_deg);

	SetCtrlVal (hGUIMainPanel, PANEL_WC_X_mm, 	WC_X_mm);
	SetCtrlVal (hGUIMainPanel, PANEL_WC_Y_mm, 	WC_Y_mm);

	return 0;
}


// **************************************************************************

int CVICALLBACK CVI_CB_MAIN_WCTUpdate (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			UpdateCoordinates();

			break;
	}
	return 0;
}


// **************************************************************************

int UpdateCounters(void)
{
	int lCounterSM1;
	int lCounterSM2;
	
	
	lCounterSM1 = IODevContCounterSMOneGet();
	lCounterSM2 = IODevContCounterSMTwoGet();
	
	SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER, lCounterSM1);
	SetCtrlVal(hGUIMainPanel,PANEL_CB_COUNTER_2, lCounterSM2);
	
	UpdateCoordinates();
	
	return 0;
}


// **************************************************************************

int CVICALLBACK CVICB_SetChip1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int		Counter_R_S;
	int		Counter_A_S;
	
	double	WM_X_mm;
	double	WM_Y_mm;

	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER, 	&Counter_R_S);
			GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER_2, 	&Counter_A_S);
			GetCtrlVal (hGUIMainPanel, PANEL_WM_X_mm, 	&WM_X_mm);
			GetCtrlVal (hGUIMainPanel, PANEL_WM_Y_mm, 	&WM_Y_mm);
			
			// Col, Row
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (2, 2), Counter_R_S);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (3, 2), Counter_A_S);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (4, 2), WM_X_mm);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (5, 2), WM_Y_mm);

			break;
	}
	return 0;
}


// **************************************************************************

int CVICALLBACK CVICB_SetChip2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int		Counter_R_S;
	int		Counter_A_S;

	double	WM_X_mm;
	double	WM_Y_mm;
	
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER, 	&Counter_R_S);
			GetCtrlVal (hGUIMainPanel, PANEL_CB_COUNTER_2, 	&Counter_A_S);
			GetCtrlVal (hGUIMainPanel, PANEL_WM_X_mm, 	&WM_X_mm);
			GetCtrlVal (hGUIMainPanel, PANEL_WM_Y_mm, 	&WM_Y_mm);
			
			// Col, Row
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (2, 3), Counter_R_S);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (3, 3), Counter_A_S);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (4, 3), WM_X_mm);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (5, 3), WM_Y_mm);


			break;
	}
	return 0;
}


// **************************************************************************

int CVICALLBACK CVICB_Calibration (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int		Counter_R_S_1 = 0;
	int		Counter_A_S_1 = 0;
	int		Counter_R_S_2 = 0;
	int		Counter_A_S_2 = 0;
	
	int		Counter_R_S;
	int		Counter_A_S;

	double	WM_X_mm_1 = 0;
	double	WM_Y_mm_1 = 0;
	double	WM_X_mm_2 = 0;
	double	WM_Y_mm_2 = 0;
	
	double	Cal_R_S_mm;
	double	Cal_A_S_deg;
	
	double	MC_X_mm_1;
	double	MC_Y_mm_1;
	double	MC_X_mm_2;
	double	MC_Y_mm_2;
	
	double	MC_R_mm;
	double	MC_A_deg;
	
	double	WC_X_mm;
	double	WC_Y_mm;
	double	WC_R_mm;
	double	WC_A_deg;
	
	double	WCT_XS_mm_1;
	double	WCT_YS_mm_1;
	double	WCT_AS_deg_1;
	double	WCT_XS_mm_2;
	double	WCT_YS_mm_2;
	double	WCT_AS_deg_2;
	
	double	a;
	double	phi;
	double	b;
	double	beta;
	double	alpha;
	double	gamma;
	double	c;
	double	d;
	double	r1, r2;
	
	double MC_dx_mm, MC_dy_mm;
	double MC_dphi_deg;
	
	double WM_dx_mm, WM_dy_mm;
	double WM_dphi_deg;

	double dphi;
	
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (hTabPanel0, TABPANEL_CB_Y_CALI_FACTOR,	&Cal_R_S_mm);
			GetCtrlVal (hTabPanel0, TABPANEL_CB_X_CALI_FACTOR,	&Cal_A_S_deg);
	
			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (2, 2), &Counter_R_S_1);
			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (3, 2), &Counter_A_S_1);
			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (4, 2), &WM_X_mm_1);
			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (5, 2), &WM_Y_mm_1);

			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (2, 3), &Counter_R_S_2);
			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (3, 3), &Counter_A_S_2);
			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (4, 3), &WM_X_mm_2);
			GetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (5, 3), &WM_Y_mm_2);
			
			a = abs(Counter_R_S_2 - Counter_R_S_1) / Cal_R_S_mm;
			
			phi = abs(Counter_A_S_2 - Counter_A_S_1) / Cal_A_S_deg;
			
			b = sqrt((WM_X_mm_2 - WM_X_mm_1) * (WM_X_mm_2 - WM_X_mm_1) + (WM_Y_mm_2 - WM_Y_mm_1) * (WM_Y_mm_2 - WM_Y_mm_1));
			
			beta = 180.0 - (180.0 - phi) / 2.0;
			
			alpha = asin(a / b * sin (beta * pi / 180.0)) * 180.0 / pi;
			
			gamma = 180.0 - alpha - beta;
			
			c = sqrt(a*a + b*b - 2 * a * b * cos(gamma * pi / 180.0));
			
			d = sqrt((c*c) / (2 * (1 - cos(phi * pi / 180.0))));
			
			r1 = d;
			
			r2 = d + a;
			
			MC_X_mm_1 = r1;
			MC_Y_mm_1 = 0;

			MC_X_mm_2 = r2 * cos(phi*pi/180.0);
			MC_Y_mm_2 = r2 * sin(phi*pi/180.0);
			
			MC_dx_mm = MC_X_mm_2 - MC_X_mm_1;
			MC_dy_mm = MC_Y_mm_2 - MC_Y_mm_1;
			
			MC_dphi_deg = 90.0 - atan2(MC_dy_mm, MC_dx_mm) * 180.0 / pi;
			
			WM_dx_mm = WM_X_mm_2 - WM_X_mm_1;
			WM_dy_mm = WM_Y_mm_2 - WM_Y_mm_1;
			
			WM_dphi_deg = 90.0 - atan2(WM_dy_mm, WM_dx_mm) * 180.0 / pi;
			
			dphi = MC_dphi_deg - WM_dphi_deg;
			
			WCT_XS_mm_1 = -(WM_X_mm_1 - MC_X_mm_1 * cos(dphi*pi/180.0) + MC_Y_mm_1 * sin(dphi*pi/180.0));
			WCT_YS_mm_1 = -(WM_Y_mm_1 - MC_X_mm_1 * sin(dphi*pi/180.0) - MC_Y_mm_1 * cos(dphi*pi/180.0));
			WCT_AS_deg_1 = dphi;
			
			WCT_XS_mm_2 = -(WM_X_mm_2 - MC_X_mm_2 * cos(dphi*pi/180.0) + MC_Y_mm_2 * sin(dphi*pi/180.0));
			WCT_YS_mm_2 = -(WM_Y_mm_2 - MC_X_mm_2 * sin(dphi*pi/180.0) - MC_Y_mm_2 * cos(dphi*pi/180.0));
			WCT_AS_deg_2 = dphi;

			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (6, 2), WCT_XS_mm_1);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (7, 2), WCT_YS_mm_1);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (8, 2), WCT_AS_deg_1);
			
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (6, 3), WCT_XS_mm_2);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (7, 3), WCT_YS_mm_2);
			SetTableCellVal (hGUIMainPanel, PANEL_TABLE, MakePoint (8, 3), WCT_AS_deg_2);

			MC_R_mm = r2;
			MC_A_deg = phi;
			
			SetCtrlVal (hGUIMainPanel, PANEL_WCT_XS_mm,	 WCT_XS_mm_2);
			SetCtrlVal (hGUIMainPanel, PANEL_WCT_YS_mm,	 WCT_YS_mm_2);
			SetCtrlVal (hGUIMainPanel, PANEL_WCT_AS_deg, WCT_AS_deg_2);
			
			Counter_R_S = MC_R_mm * Cal_R_S_mm;
			Counter_A_S = MC_A_deg * Cal_A_S_deg;
			
			IODevContCounterSMOneSet(Counter_R_S);
			IODevContCounterSMTwoSet(Counter_A_S);
			
			UpdateCounters();

			break;
	}
	return 0;
}


// ***** Save Ini-File ******************************************************

int GUIMainSaveIniFile(void)
{
	iniText = Ini_New (TRUE);
	
	Ini_PutInt (iniText, "IODevCont", "lRS232PortNumber", 	hIODevCont.lRS232PortNumber);

	Ini_WriteToFile (iniText, "settings.ini");
	Ini_Dispose (iniText);
	
	return 0;
}


// ***** Load Ini-File ******************************************************

int GUIMainLoadIniFile(void)
{
	iniText = Ini_New (TRUE);

	Ini_ReadFromFile (iniText, "settings.ini");
	

	Ini_GetInt (iniText, "IODevCont", "lRS232PortNumber", 	&hIODevCont.lRS232PortNumber);

	Ini_Dispose (iniText);
	
	return 0;
}

