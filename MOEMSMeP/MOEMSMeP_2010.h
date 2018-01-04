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

#define  PANEL                            1
#define  PANEL_CBClose                    2       /* control type: command, callback function: CVICB_GUIMainClose */
#define  PANEL_CBLEDOff                   3       /* control type: command, callback function: CVICB_GUIMainLEDOff */
#define  PANEL_CBStartMotor1              4       /* control type: command, callback function: CVICB_GUIMainStartMotorOne */
#define  PANEL_CBLEDOn                    5       /* control type: command, callback function: CVICB_GUIMainLEDOn */
#define  PANEL_CBdirectionMotor2          6       /* control type: textButton, callback function: CVICB_GUIMainMotorTwoDirection */
#define  PANEL_CBdirection                7       /* control type: textButton, callback function: CVICB_GUIMainMotorOneDirection */
#define  PANEL_CB_Mode1                   8       /* control type: command, callback function: CVI_MAIN_WINDOW_MODEI */
#define  PANEL_CB_HalfMode                9       /* control type: command, callback function: CVICB_GUIMain_HalfMode */
#define  PANEL_CB_QuarterStepMode         10      /* control type: command, callback function: CVICB_GUIMain_QuarterStepMode */
#define  PANEL_CB_SixteenthStepMode       11      /* control type: command, callback function: CVICB_GUIMain_SixteenthStepMode */
#define  PANEL_CBStartMotor2              12      /* control type: command, callback function: CVICB_GUIMainStartMotorTwo */
#define  PANEL_CB_CCWButton               13      /* control type: pictButton, callback function: CVICB_GUIMainWaferRotateCCW */
#define  PANEL_CB_CWButton                14      /* control type: pictButton, callback function: CVICB_GUIMainWafeRotateCW */
#define  PANEL_CB_DownButton              15      /* control type: pictButton, callback function: CVICB_GUIMainWaferDown */
#define  PANEL_CB_UpButton                16      /* control type: pictButton, callback function: CVICB_GUIMain_waferUP */
#define  PANEL_DECORATION_2               17      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_10              18      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_8               19      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION                 20      /* control type: deco, callback function: (none) */
#define  PANEL_CBITabWafer                21      /* control type: tab, callback function: (none) */
#define  PANEL_CVI_NUMERIC_2              22      /* control type: numeric, callback function: (none) */
#define  PANEL_CVI_NUMERIC                23      /* control type: numeric, callback function: (none) */
#define  PANEL_CVI_Frequency              24      /* control type: numeric, callback function: CB_CVI_MAIN_FREQUENCY */
#define  PANEL_DECORATION_3               25      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_7               26      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_4               27      /* control type: deco, callback function: (none) */
#define  PANEL_CB_EightStepMode           28      /* control type: command, callback function: CVICB_GUIMain_EightStepMode */
#define  PANEL_CB_Mode2_1                 29      /* control type: command, callback function: CVI_MAIN_WINDOW_MODE_2_1 */
#define  PANEL_CB_HalfMode_2              30      /* control type: command, callback function: CVICB_GUIMain_HalfMode_2 */
#define  PANEL_CB_Quartermode_2           31      /* control type: command, callback function: CVICB_GUIMain_QuarterMode_2 */
#define  PANEL_CB_EightMode_2             32      /* control type: command, callback function: CVICB_GUIMain_EightMode_2 */
#define  PANEL_CB_SixteenthMode_2         33      /* control type: command, callback function: CVICB_GUIMain_SixteenthStepMode_2 */
#define  PANEL_CB_FREQUENCY_2             34      /* control type: numeric, callback function: CB_CVI_MAIN_FREQUENCY_2 */
#define  PANEL_DECORATION_5               35      /* control type: deco, callback function: (none) */
#define  PANEL_CB_CALIBRATE_X             36      /* control type: command, callback function: CVICB_GUIMain_CALIBRATE_X */
#define  PANEL_CB_Calibrate_Y             37      /* control type: command, callback function: CVICB_GUIMainCalibrate_Y */
#define  PANEL_CB_DefultSM_1              38      /* control type: command, callback function: CVICB_GUI_SM1_START */
#define  PANEL_DECORATION_6               39      /* control type: deco, callback function: (none) */
#define  PANEL_CB_COUNTER_2               40      /* control type: numeric, callback function: CVI_GUI_MAIN_COUNTER_2 */
#define  PANEL_CB_COUNTER                 41      /* control type: numeric, callback function: CVI_GUI_MAIN_COUNTER_1 */
#define  PANEL_CB_COUNTER_RESET_2         42      /* control type: command, callback function: CBI_MAIN_COUNTER_RESET_2 */
#define  PANEL_CB_RESET_COUNTER_1         43      /* control type: command, callback function: CBI_MAIN_COUNTER_RESET_1 */
#define  PANEL_CB_LINEAR_SCALE            44      /* control type: numeric, callback function: CBI_LINEAR_SCALE */
#define  PANEL_CB_MEGA_ENCODER_CUNTR      45      /* control type: command, callback function: CBI_MEGA_ENCODER_CUNTR */
#define  PANEL_CB_SWITCH                  46      /* control type: command, callback function: CBI_SWITCH */
#define  PANEL_CB_GET_CNT                 47      /* control type: command, callback function: CBI_GET_CNT */
#define  PANEL_CB_X_RESET                 48      /* control type: command, callback function: CBI_X_RESET */
#define  PANEL_CB_CANVAS                  49      /* control type: canvas, callback function: CBI_CANVAS */
#define  PANEL_CB_CHK_DEVIATION           50      /* control type: command, callback function: CB_SUB_PENL_CHK_DEVIATION */
#define  PANEL_WCT_AS_deg                 51      /* control type: numeric, callback function: CVI_CB_MAIN_WCTUpdate */
#define  PANEL_WCT_YS_mm                  52      /* control type: numeric, callback function: CVI_CB_MAIN_WCTUpdate */
#define  PANEL_WCT_XS_mm                  53      /* control type: numeric, callback function: CVI_CB_MAIN_WCTUpdate */
#define  PANEL_WM_A_deg                   54      /* control type: numeric, callback function: (none) */
#define  PANEL_WM_R_mm                    55      /* control type: numeric, callback function: (none) */
#define  PANEL_WM_Y_mm                    56      /* control type: numeric, callback function: (none) */
#define  PANEL_WM_X_mm                    57      /* control type: numeric, callback function: (none) */
#define  PANEL_WC_A_deg                   58      /* control type: numeric, callback function: (none) */
#define  PANEL_WC_R_mm                    59      /* control type: numeric, callback function: (none) */
#define  PANEL_WC_Y_mm                    60      /* control type: numeric, callback function: (none) */
#define  PANEL_WC_X_mm                    61      /* control type: numeric, callback function: (none) */
#define  PANEL_MC_A_deg                   62      /* control type: numeric, callback function: (none) */
#define  PANEL_MC_R_mm                    63      /* control type: numeric, callback function: (none) */
#define  PANEL_MC_Y_mm                    64      /* control type: numeric, callback function: (none) */
#define  PANEL_MC_X_mm                    65      /* control type: numeric, callback function: (none) */
#define  PANEL_MACHINECORDINATESYSTE      66      /* control type: textMsg, callback function: (none) */
#define  PANEL_DECORATION_11              67      /* control type: deco, callback function: (none) */
#define  PANEL_WAFERCORDINATESYSTEM       68      /* control type: textMsg, callback function: (none) */
#define  PANEL_WAFERTRANSFORMATION        69      /* control type: textMsg, callback function: (none) */
#define  PANEL_CB_DATA_3                  70      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_DATA_4                  71      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_DATA_1                  72      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_DATA_2                  73      /* control type: numeric, callback function: (none) */
#define  PANEL_TB_MoveMotors              74      /* control type: textButton, callback function: (none) */
#define  PANEL_TABLE                      75      /* control type: table, callback function: (none) */
#define  PANEL_CBCalibration              76      /* control type: command, callback function: CVICB_Calibration */
#define  PANEL_CBSetChip2                 77      /* control type: command, callback function: CVICB_SetChip2 */
#define  PANEL_CBSetChip1                 78      /* control type: command, callback function: CVICB_SetChip1 */

     /* tab page panel controls */
#define  TABPANEL_CBIWaferMap_4_Inch      2       /* control type: table, callback function: CVICB_GUItabFourInchWaferMap */
#define  TABPANEL_CVI_X_DIE_2_DIE         3       /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE_4_X */
#define  TABPANEL_CVI_DIE_2_DIE           4       /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE */
#define  TABPANEL_CB_X_CALI_FACTOR        5       /* control type: numeric, callback function: CBI_X_CALI_FACTOR */
#define  TABPANEL_CB_Y_CALI_FACTOR        6       /* control type: numeric, callback function: CBI_Y_CALI_FACTOR */
#define  TABPANEL_DECORATION              7       /* control type: deco, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_2_CBIWaferMap_6_Inch    2       /* control type: table, callback function: CVICB_GUItabSixInchWaferMap */
#define  TABPANEL_2_CB_TOOGLE_SHOW_FILL_2 3       /* control type: textButton, callback function: CBI_TOGGLE_SHOW_2 */
#define  TABPANEL_2_CVI_X_DIE_2_DIE_2     4       /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE_4_X_2 */
#define  TABPANEL_2_CVI_DIE_2_DIE_2       5       /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE_2 */
#define  TABPANEL_2_CB_X_CALI_FACTOR_2    6       /* control type: numeric, callback function: CBI_X_CALI_FACTOR_2 */
#define  TABPANEL_2_CB_Y_CALI_FACTOR_2    7       /* control type: numeric, callback function: CBI_Y_CALI_FACTOR_2 */
#define  TABPANEL_2_CB_SET_REF_DIE_2      8       /* control type: textButton, callback function: CBI_SET_REFERENCE_DIE_2 */
#define  TABPANEL_2_CB_PROG_MOVE_TG_2     9       /* control type: textButton, callback function: CBI_PROG_MOVE_TGL_2 */
#define  TABPANEL_2_CLEAR_ALL_2           10      /* control type: command, callback function: CBI_GUI_TAB_CLEAR_ALL_2 */
#define  TABPANEL_2_DECORATION            11      /* control type: deco, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_CB_MENU_MOEM             2
#define  MENUBAR_DB_Indicators            3
#define  MENUBAR_DB_Indicators_CB_CHILD_INDICATORS 4 /* callback function: CBI_GUI_MAIN_INDICATORS_CHILD */
#define  MENUBAR_CB_help                  5
#define  MENUBAR_CB_help_CB_Help_child    6       /* callback function: CBI_GUI_HELP_CHILD */
#define  MENUBAR_CB_About                 7
#define  MENUBAR_CB_About_CB_About_child  8       /* callback function: CBI_About */


     /* Callback Prototypes: */

int  CVICALLBACK CB_CVI_MAIN_FREQUENCY(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_CVI_MAIN_FREQUENCY_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_SUB_PENL_CHK_DEVIATION(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK CBI_About(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK CBI_CANVAS(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GET_CNT(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK CBI_GUI_HELP_CHILD(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK CBI_GUI_MAIN_INDICATORS_CHILD(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK CBI_GUI_TAB_CLEAR_ALL_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_LINEAR_SCALE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_MAIN_COUNTER_RESET_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_MAIN_COUNTER_RESET_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_MEGA_ENCODER_CUNTR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_PROG_MOVE_TGL_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_SET_REFERENCE_DIE_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_SWITCH(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_TOGGLE_SHOW_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_X_CALI_FACTOR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_X_CALI_FACTOR_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_X_RESET(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_Y_CALI_FACTOR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_Y_CALI_FACTOR_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_CB_MAIN_WCTUpdate(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_GUI_MAIN_COUNTER_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_GUI_MAIN_COUNTER_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_MAIN_WINDOW_MODE_2_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_MAIN_WINDOW_MODEI(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE_4_X(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE_4_X_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_Calibration(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUI_SM1_START(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_CALIBRATE_X(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_EightMode_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_EightStepMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_HalfMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_HalfMode_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_QuarterMode_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_QuarterStepMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_SixteenthStepMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_SixteenthStepMode_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMain_waferUP(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainCalibrate_Y(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainClose(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainLEDOff(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainLEDOn(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainMotorOneDirection(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainMotorTwoDirection(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainStartMotorOne(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainStartMotorTwo(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainWaferDown(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainWafeRotateCW(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUIMainWaferRotateCCW(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUItabFourInchWaferMap(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_GUItabSixInchWaferMap(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_SetChip1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVICB_SetChip2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
