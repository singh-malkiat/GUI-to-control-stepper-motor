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
#define  PANEL_CBITabWafer                21      /* control type: tab, callback function: CBI_TabCB_Wafer */
#define  PANEL_TEST_LED                   22      /* control type: LED, callback function: CVI_MAIN_TEST_LED */
#define  PANEL_TEST_TOGGLEBUTTON          23      /* control type: textButton, callback function: CB_TEST_TB */
#define  PANEL_CVI_NUMERIC_2              24      /* control type: numeric, callback function: CB_CVI_MAIN_NUMERIC_2 */
#define  PANEL_CVI_NUMERIC                25      /* control type: numeric, callback function: CB_CVI_MAIN_NUMERIC */
#define  PANEL_CVI_Frequency              26      /* control type: numeric, callback function: CB_CVI_MAIN_FREQUENCY */
#define  PANEL_DECORATION_3               27      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_7               28      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_4               29      /* control type: deco, callback function: (none) */
#define  PANEL_CB_EightStepMode           30      /* control type: command, callback function: CVICB_GUIMain_EightStepMode */
#define  PANEL_CB_Mode2_1                 31      /* control type: command, callback function: CVI_MAIN_WINDOW_MODE_2_1 */
#define  PANEL_CB_HalfMode_2              32      /* control type: command, callback function: CVICB_GUIMain_HalfMode_2 */
#define  PANEL_CB_Quartermode_2           33      /* control type: command, callback function: CVICB_GUIMain_QuarterMode_2 */
#define  PANEL_CB_EightMode_2             34      /* control type: command, callback function: CVICB_GUIMain_EightMode_2 */
#define  PANEL_CB_SixteenthMode_2         35      /* control type: command, callback function: CVICB_GUIMain_SixteenthStepMode_2 */
#define  PANEL_CB_FREQUENCY_2             36      /* control type: numeric, callback function: CB_CVI_MAIN_FREQUENCY_2 */
#define  PANEL_DECORATION_5               37      /* control type: deco, callback function: (none) */
#define  PANEL_CB_CALIBRATE_X             38      /* control type: command, callback function: CVICB_GUIMain_CALIBRATE_X */
#define  PANEL_CB_Calibrate_Y             39      /* control type: command, callback function: CVICB_GUIMainCalibrate_Y */
#define  PANEL_CB_DefultSM_1              40      /* control type: command, callback function: CVICB_GUI_SM1_START */
#define  PANEL_DECORATION_6               41      /* control type: deco, callback function: (none) */
#define  PANEL_CB_COUNTER_2               42      /* control type: numeric, callback function: CVI_GUI_MAIN_COUNTER_2 */
#define  PANEL_CB_COUNTER                 43      /* control type: numeric, callback function: CVI_GUI_MAIN_COUNTER_1 */
#define  PANEL_CB_COUNTER_RESET_2         44      /* control type: command, callback function: CBI_MAIN_COUNTER_RESET_2 */
#define  PANEL_CB_RESET_COUNTER_1         45      /* control type: command, callback function: CBI_MAIN_COUNTER_RESET_1 */
#define  PANEL_CB_QUICK_SETTING           46      /* control type: command, callback function: CBI_MAIN_QUICK_SETTINGS */
#define  PANEL_CB_LINEAR_SCALE            47      /* control type: numeric, callback function: CBI_LINEAR_SCALE */
#define  PANEL_CB_MEGA_ENCODER_CUNTR      48      /* control type: command, callback function: CBI_MEGA_ENCODER_CUNTR */
#define  PANEL_CB_SWITCH                  49      /* control type: command, callback function: CBI_SWITCH */
#define  PANEL_CB_GET_CNT                 50      /* control type: command, callback function: CBI_GET_CNT */
#define  PANEL_CB_X_RESET                 51      /* control type: command, callback function: CBI_X_RESET */
#define  PANEL_CB_CANVAS                  52      /* control type: canvas, callback function: CBI_CANVAS */
#define  PANEL_CB_CHK_DEVIATION           53      /* control type: command, callback function: CB_SUB_PENL_CHK_DEVIATION */
#define  PANEL_CB_WFR_TRMN_ANGL_SHFT      54      /* control type: numeric, callback function: CVI_CB_MAIN_WCTUpdate */
#define  PANEL_CB_WFR_TRMN_Y_SHIFT        55      /* control type: numeric, callback function: CVI_CB_MAIN_WCTUpdate */
#define  PANEL_CB_WFR_TRMN_X_SHIFT        56      /* control type: numeric, callback function: CVI_CB_MAIN_WCTUpdate */
#define  PANEL_CB_WFR_C_SYS_ANGLE         57      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_WFR_C_SYS_RADIUS_m      58      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_WFR_C_SYS_Y_mm          59      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_WFR_C_SYS_X_mm          60      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_MC_CRD_SYS_ANGLE        61      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_MC_CRD_SYS_RAD_mm       62      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_MC_CRD_SYS_Y_mm         63      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_MC_CRD_SYS_X_mm         64      /* control type: numeric, callback function: (none) */
#define  PANEL_MACHINECORDINATESYSTE      65      /* control type: textMsg, callback function: (none) */
#define  PANEL_DECORATION_11              66      /* control type: deco, callback function: (none) */
#define  PANEL_WAFERCORDINATESYSTEM       67      /* control type: textMsg, callback function: (none) */
#define  PANEL_WAFERTRANSFORMATION        68      /* control type: textMsg, callback function: (none) */
#define  PANEL_CB_DATA_3                  69      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_DATA_4                  70      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_DATA_1                  71      /* control type: numeric, callback function: (none) */
#define  PANEL_CB_DATA_2                  72      /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_CBIWaferMap_4_Inch      2       /* control type: table, callback function: CVICB_GUItabFourInchWaferMap */
#define  TABPANEL_CB_SET_MOVE             3       /* control type: command, callback function: CBI_GUI_TAB_MOVE_1 */
#define  TABPANEL_CB_SAVE_MOVE_STATE      4       /* control type: command, callback function: CBI_GUI_TAB_SAVE_MOVE_STATE */
#define  TABPANEL_CB_CLEAR                5       /* control type: command, callback function: CBI_GIU_TAB_CLEAR */
#define  TABPANEL_CB_SAVE_DATA            6       /* control type: command, callback function: CBI_GUI_TAB_SAVE_DATA */
#define  TABPANEL_CB_CLEAR_ALL            7       /* control type: command, callback function: CBI_GUI_TAB_CLEAR_ALL */
#define  TABPANEL_CB_FILL_AUTO            8       /* control type: command, callback function: CBI_GUI_TABS_AUTO_FILL */
#define  TABPANEL_CB_TOOGLE_SHOW_FILLED   9       /* control type: textButton, callback function: CBI_TOGGLE_SHOW */
#define  TABPANEL_CVI_X_DIE_2_DIE         10      /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE_4_X */
#define  TABPANEL_CVI_DIE_2_DIE           11      /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE */
#define  TABPANEL_CB_X_CALI_FACTOR        12      /* control type: numeric, callback function: CBI_X_CALI_FACTOR */
#define  TABPANEL_CB_Y_CALI_FACTOR        13      /* control type: numeric, callback function: CBI_Y_CALI_FACTOR */
#define  TABPANEL_CB_PROGRAMMED_MOVE_TG   14      /* control type: textButton, callback function: CBI_PROGRAMMED_MOVE_TGL */
#define  TABPANEL_DECORATION              15      /* control type: deco, callback function: (none) */
#define  TABPANEL_CB_SET_REF_CMD          16      /* control type: command, callback function: CBI_SET_REF_CMD */

     /* tab page panel controls */
#define  TABPANEL_2_CBIWaferMap_6_Inch    2       /* control type: table, callback function: CVICB_GUItabSixInchWaferMap */
#define  TABPANEL_2_CB_FILL_AUTO_2        3       /* control type: command, callback function: CBI_GUI_TABS_AUTO_FILL_2 */
#define  TABPANEL_2_CB_TOOGLE_SHOW_FILL_2 4       /* control type: textButton, callback function: CBI_TOGGLE_SHOW_2 */
#define  TABPANEL_2_CVI_X_DIE_2_DIE_2     5       /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE_4_X_2 */
#define  TABPANEL_2_CVI_DIE_2_DIE_2       6       /* control type: ring, callback function: CVI_SLCT_DIE_2_DIE_2 */
#define  TABPANEL_2_CB_X_CALI_FACTOR_2    7       /* control type: numeric, callback function: CBI_X_CALI_FACTOR_2 */
#define  TABPANEL_2_CB_Y_CALI_FACTOR_2    8       /* control type: numeric, callback function: CBI_Y_CALI_FACTOR_2 */
#define  TABPANEL_2_CB_SET_REF_DIE_2      9       /* control type: textButton, callback function: CBI_SET_REFERENCE_DIE_2 */
#define  TABPANEL_2_CB_PROG_MOVE_TG_2     10      /* control type: textButton, callback function: CBI_PROG_MOVE_TGL_2 */
#define  TABPANEL_2_CLEAR_ALL_2           11      /* control type: command, callback function: CBI_GUI_TAB_CLEAR_ALL_2 */
#define  TABPANEL_2_DECORATION            12      /* control type: deco, callback function: (none) */


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
int  CVICALLBACK CB_CVI_MAIN_NUMERIC(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_CVI_MAIN_NUMERIC_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_SUB_PENL_CHK_DEVIATION(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CB_TEST_TB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK CBI_About(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK CBI_CANVAS(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GET_CNT(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GIU_TAB_CLEAR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK CBI_GUI_HELP_CHILD(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK CBI_GUI_MAIN_INDICATORS_CHILD(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK CBI_GUI_TAB_CLEAR_ALL(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GUI_TAB_CLEAR_ALL_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GUI_TAB_MOVE_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GUI_TAB_SAVE_DATA(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GUI_TAB_SAVE_MOVE_STATE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GUI_TABS_AUTO_FILL(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_GUI_TABS_AUTO_FILL_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_LINEAR_SCALE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_MAIN_COUNTER_RESET_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_MAIN_COUNTER_RESET_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_MAIN_QUICK_SETTINGS(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_MEGA_ENCODER_CUNTR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_PROG_MOVE_TGL_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_PROGRAMMED_MOVE_TGL(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_SET_REF_CMD(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_SET_REFERENCE_DIE_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_SWITCH(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_TabCB_Wafer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_TOGGLE_SHOW(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_TOGGLE_SHOW_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_X_CALI_FACTOR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_X_CALI_FACTOR_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_X_RESET(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_Y_CALI_FACTOR(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CBI_Y_CALI_FACTOR_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_CB_MAIN_WCTUpdate(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_GUI_MAIN_COUNTER_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_GUI_MAIN_COUNTER_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_MAIN_TEST_LED(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_MAIN_WINDOW_MODE_2_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_MAIN_WINDOW_MODEI(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE_4_X(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CVI_SLCT_DIE_2_DIE_4_X_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
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


#ifdef __cplusplus
    }
#endif
