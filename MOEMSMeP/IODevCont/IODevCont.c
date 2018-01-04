// **************************************************************************
//
// Data Name:              MOEMSMeP.c
// Version:                08-29-a
// Programm Titel:         MOEMS Measurement Program (MOEMSMeP)
// Programm Language:      LabWindows/CVI 2010
// Autor:                  Malkiat Singh
//
// **************************************************************************


#include <userint.h>
#include "MOEMSMeP_2010.h"
#include <formatio.h>
#include <rs232.h>
#include <ansi_c.h>
#include "IODevCont.h"


// ***** Prototypen *********************************************************

static int IODevContInit			(void);
static int IODevContOpenComPort		(void);
static int IODevContCloseComPort	(void);


// ***** Public *************************************************************

// ***** Create *************************************************************

int	IODevContCreate(void)
{
	if (hIODevCont.lHardwareConnected == 0)
		return 1;
	
	if (hIODevCont.lIODevCont == 1)
		IODevContDispose();

	IODevContInit();
	
	hIODevCont.lIODevCont = 1;
	
	return 0;
}


// ***** Dispose ************************************************************

int IODevContDispose(void)
{
//	if (hIODevCont.lHardwareConnected == 0)
//		return 1;
	
	if (hIODevCont.lIODevCont == 0)
		return 2;
	
	IODevContCloseComPort();
	
	hIODevCont.lIODevCont = 0;
	
	return 0;
}


// ***** Switch LED On ******************************************************

int IODevContSwitchLEDOn(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<LedOn\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Switch LED Off *****************************************************

int IODevContSwitchLEDOff(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<LedOff\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ************************* Status LED 2 ON ******************************** 

int IODevContStatusLED_2On(void) 
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<StatusLED2:On\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ************************* Status LED 2 Off *******************************

int IODevContStatusLED_2_OFF(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<StatusLED2:Off\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Move Motor 1 *******************************************************

int IODevContStartMotorOne(int lNoOfSteps)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<MoveSM_1 %i\r\n", lNoOfSteps);
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
//	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Start Motor 1 ******************************************************

int IODevContStartMotorOneAdv(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Start:SM:1\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContStartMotorOneAdv");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
//	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Stop Motor 1 *******************************************************

int IODevContStopMotorOne(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Stop:SM:1\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContStopMotorOne");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
//	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Set Number Of Steps ************************************************

int IODevContSetNumberOfSteps(int lNumberOfSteps)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


/*	Fmt (szOutputBuffer, "%s<noofsteps\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);

	Fmt (szOutputBuffer, "%s<%i\r\n", lNumberOfSteps);
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
*/	
	return 0;
}


// *********************** Direction Motor 1 ********************************

 
int IODevContDirectionMotorOne(int second_direction)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;

	if (second_direction==1)
		
		Fmt (szOutputBuffer, "%s<Clockwise_1\r\n");
	else
		Fmt (szOutputBuffer, "%s<CounterClockwise_1\r\n");	
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);
 
	return 0;
}
																		 
//*********************** MOTOR 1: Frequency ********************************

int IODevContSetFrq(int Frequency_1)

{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Frequency_1 %i\r\n",Frequency_1);
	
	//printf("szOutputBuffer, %s ,Frequency_1 %i\n",szOutputBuffer,Frequency_1);  // output buffer checking
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	
//	printf(" szInputBuffer, %s ,Frequency_1 %i\n", szInputBuffer,Frequency_1); 	   // Input buffer checking

	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead-1, szInputBuffer);	   //		[w*] specifying string size  and having a value of lbyte read
	
	//Fmt (szInputBufferTerm, "%s", szInputBuffer);	   //[w*] specifying string size 
	
	printf("%s\n", szInputBufferTerm);

	return 0;
}

//***********************MODE ONE********************************************

int IODevContModeONE(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<FullMode_1\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

//*********************** HALF MODE *****************************************

int IODevContModeHalf(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<HalfMode_1\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}
//*********************** QUARTER MODE **************************************

int IODevContModeQuarter(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<QuarterStep_1\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

//*********************** EIGHTH MODE ***************************************

int IODevContModeEight(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<EighthStep_1\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


//*********************** SIXTEENTH MODE ************************************
int IODevContModeSixteenth(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<SixteenthStep_1\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


/***************************************************************************/
/* Move Motor 2															   */
/***************************************************************************/

int IODevContStartMotorTwo(int lNoOfSteps)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<MoveSM_2 %i\r\n", lNoOfSteps);
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
//	printf("%s\n", szInputBufferTerm);

	return 0;
}

// ***** Start Motor 2 ******************************************************

int IODevContStartMotorTwoAdv(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Start:SM:2\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContStartMotorTwoAdv");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
//	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Stop Motor 2 *******************************************************

int IODevContStopMotorTwo(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Stop:SM:2\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContStopMotorTwo");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
//	printf("%s\n", szInputBufferTerm);

	return 0;
}


// **************** Set Number Of Steps For Second Motor ********************

int IODevContSetNumberOfStepsForMotor2(int lNumberOfSteps_2)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;

/*
	Fmt (szOutputBuffer, "%s<NoOfStepsForMotorTwo\r\n");		// Setting number of steps for motor two function input defined in atmel programm
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
//	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);

	Fmt (szOutputBuffer, "%s<%i\r\n", lNumberOfSteps_2);
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
*/	
	return 0;
}




// **************** Set Direction Of Motor Two ******************************

int IODevContDirectionMotorTwo(int second_direction_2)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;

	if (second_direction_2==1)
		
		Fmt (szOutputBuffer, "%s<Clockwise_2\r\n");
	else
		Fmt (szOutputBuffer, "%s<CounterClockwise_2\r\n");	
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);
 
	return 0;
}

//*********************** MOTOR 2: FREQUENCY ********************************

int IODevContSetFrqTwo(int iclock_2)

{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Frequency_2 %i\r\n",iclock_2);
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead-1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


//*********************** MOTOR 2: MODE ONE *********************************

int IODevContModeONE_2(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<FullMode_2\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

//*********************** MOTOR 2: HALF MODE ********************************

int IODevContModeHalf_2(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<HalfMode_2\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}
//*********************** MOTOR 2: QUARTER MODE *****************************

int IODevContModeQuarter_2(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<QuarterStep_2\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

//*********************** MOTOR 2: EIGHTH MODE ******************************

int IODevContModeEight_2(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<EighthStep_2\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


//*********************** MOTOR 2: SIXTEENTH MODE ***************************
int IODevContModeSixteenth_2(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<SixteenthStep_2\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// **************************************************************************
// * Counter Functions 
// **************************************************************************

// ***** Counter SM1 Get ****************************************************

int IODevContCounterSMOneGet(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;
	int		lCounterSM1;


	Fmt (szOutputBuffer, "%s<Counter:SM:1:Get\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContCounterSMOneGet");
	}
	
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);
	
	Scan (szInputBufferTerm, "%s>Counter:SM:1:\t%i", &lCounterSM1);

	return lCounterSM1;
}


// ***** Counter SM1 Set ****************************************************

int IODevContCounterSMOneSet(int lCounter)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;
	int		lCounterSM2;


	Fmt (szOutputBuffer, "%s<Counter:SM:1:Set %i\r\n", lCounter);
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContCounterSMTwoSet");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Counter SM1 Reset **************************************************

int IODevContCounterSMOneReset(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Counter:SM:1:Reset\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContCounterSMOneReset");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Counter SM2 Get ****************************************************

int IODevContCounterSMTwoGet(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;
	int		lCounterSM2;


	Fmt (szOutputBuffer, "%s<Counter:SM:2:Get\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContCounterSMTwoGet");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	Scan (szInputBufferTerm, "%s>Counter:SM:2:\t%i", &lCounterSM2);

	return lCounterSM2;
}


// ***** Counter SM2 Set ****************************************************

int IODevContCounterSMTwoSet(int lCounter)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;
	int		lCounterSM2;


	Fmt (szOutputBuffer, "%s<Counter:SM:2:Set %i\r\n", lCounter);
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContCounterSMTwoSet");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// ***** Counter SM2 Reset **************************************************

int IODevContCounterSMTwoReset(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<Counter:SM:2:Reset\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	
	
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContCounterSMOneReset");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


//*************************************************************************** 
					  //** FOR HCTL DECODER **//
//*************************************************************************** 

int IODevContmega_encoder_counter(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<mega_encoder_counter\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

int IODevConts_switch(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<s_switch\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

int IODevContx_axis_reset(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<x_axis_reset\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

int IODevContX_axis_get_count(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<X_axis_get_count\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}

int IODevContUpdateMotorStatus(void)
{
	char	szOutputBuffer[110];
	char	szOutputBufferComp[110];
	char	szInputBuffer[110];
	char	szInputBufferTerm[110];
	int		lStatus;
	int		lBytesRead;


	Fmt (szOutputBuffer, "%s<UpdateMotorStatus\r\n");
	
	ComWrt (hIODevCont.lRS232PortNumber, szOutputBuffer, strlen(szOutputBuffer));

	lBytesRead = ComRdTerm (hIODevCont.lRS232PortNumber, szInputBuffer, 100, 10);
	if (lBytesRead < 0)
	{
		printf("Error:	ComRdTerm, IODevContSwitchRelaisOn");
	}
	Fmt (szInputBufferTerm, "%s<%s[w*]\0", lBytesRead - 1, szInputBuffer);
	printf("%s\n", szInputBufferTerm);

	return 0;
}


// *************************** Private **************************************

// **************************** Init ****************************************

static int IODevContInit(void)
{
	hIODevCont.lSimulate 			= 1;
//	hIODevCont.lIODevCont 			= 0;
//	hIODevCont.lRS232PortNumber 	= 0;
	
	IODevContOpenComPort();

	return 0;
}


// ***** Open COMPort *******************************************************

static int IODevContOpenComPort(void)
{
	hIODevCont.lSimulate = 0;
	
	if(OpenComConfig (hIODevCont.lRS232PortNumber, 0, 38400, 0, 8, 1, 1024, 1024) < 0)
	{
		hIODevCont.lSimulate = 1;
		printf("Error:   IODevCont - Switched to Simulation Mode\n");
	}

	if (hIODevCont.lSimulate == 0)
	{
		
    	SetComTime 	(hIODevCont.lRS232PortNumber, 60);
		SetCTSMode 	(hIODevCont.lRS232PortNumber, LWRS_HWHANDSHAKE_OFF);
    	SetXMode   	(hIODevCont.lRS232PortNumber, 0);
    
		FlushInQ	(hIODevCont.lRS232PortNumber);
    	FlushOutQ	(hIODevCont.lRS232PortNumber);
	}

	return 0;
}


// ***** Close COMPort ******************************************************

static int IODevContCloseComPort(void)
{
	if (hIODevCont.lSimulate == 0)
	{
		CloseCom (hIODevCont.lRS232PortNumber);
	}
	
	return 0;
}
