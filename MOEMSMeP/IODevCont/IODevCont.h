// **************************************************************************
//
// Data Name:              MOEMSMeP.c
// Version:                12-02-a
// Programm Titel:         MEMS Measurement Program (MEMSMeP)
// Programm Language:      LabWindows/CVI 2010
// Autor:                  Malkiat Singh
//
// **************************************************************************


struct IODEVCONT
{
	int lHardwareConnected;
	int lIODevCont;
	int lSimulate;
	int lRS232PortNumber;
	
	char szLastAVRMeasage[100];
};

struct IODEVCONT	hIODevCont;


// ***** Public *************************************************************

extern int IODevContCreate (void);
extern int IODevContDispose(void);

extern int IODevContSwitchLEDOn(void);
extern int IODevContSwitchLEDOff(void);

extern int IODevContStatusLED_2On(void);
extern int IODevContStatusLED_2_OFF(void);




extern int IODevContStartMotorOne(int lNoOfSteps);
extern int IODevContStartMotorTwo(int lNoOfSteps);

extern int IODevContSetNumberOfSteps(int lNumberOfSteps);
extern int IODevContSetNumberOfStepsForMotor2(int lNumberOfSteps_2); 


extern int IODevContDirectionMotorOne(int second_direction);
extern int IODevContDirectionMotorTwo(int second_direction_2);
	   
	   
extern int IODevContModeONE(void);
extern int IODevContModeHalf(void); 
extern int IODevContModeQuarter(void);
extern int IODevContModeEight(void);
extern int IODevContModeSixteenth(void);

extern int IODevContModeONE_2(void);
extern int IODevContModeHalf_2(void); 
extern int IODevContModeQuarter_2(void);
extern int IODevContModeEight_2(void);
extern int IODevContModeSixteenth_2(void);



extern int IODevContSetFrq(int iclock); 
extern int IODevContSetFrqTwo(int iclock_2);

 					
extern int IODevContmega_encoder_counter(void); 
extern int IODevConts_switch(void); 
extern int IODevContx_axis_reset(void);
extern int IODevContX_axis_get_count(void);

extern int IODevContX_axis_fetch_count(void);  
extern int IODevContUpdateMotorStatus(void);    

extern int IODevContStartMotorOneAdv	(void);
extern int IODevContStopMotorOne		(void);
extern int IODevContStartMotorTwoAdv	(void);
extern int IODevContStopMotorTwo		(void);

extern int IODevContCounterSMOneGet		(void);
extern int IODevContCounterSMOneSet		(int lCounter);
extern int IODevContCounterSMOneReset	(void);
extern int IODevContCounterSMTwoGet		(void);
extern int IODevContCounterSMTwoSet		(int lCounter);
extern int IODevContCounterSMTwoReset	(void);
