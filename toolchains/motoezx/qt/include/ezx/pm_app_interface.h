/*
 *    File Name: pm_app_interface.h
 *    General Description: This header file contains application event structure and macros.
 *
 *    Motorola Confidential Proprietary
 *    Advanced Technology and Software Operations
 *    (c) Copyright Motorola 2002, All Rights Reserved
 *
 *    Revision History:
 *    Modification Tracking
 *    Author        Date Number    Description of Changes
 *    ------------    -------------    --------------------------
 *    Zhuang Xiaofan    12/25/2002    Create file
 *
 */

#ifndef _PM_APP_INTERFACE_H
#define _PM_APP_INTERFACE_H

#include <sys/types.h>
#include "EZX_TypeDefs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SOCKET_PATH        "/tmp/pmd-socket"
#define SEM_PATH                SOCKET_PATH
#define PROJ_ID            'a'
#define SLEP_ID            'b'

/*
 * app event
 */
enum {
    PM_APP_REQUEST = 0x8001,    /* request action */
    PM_APP_VOTE,            /* vote to keep ap and display alive */
    PM_APP_SETUP            /* set up */
};
 
/* app request action */
typedef enum {
    PM_APP_REQ_POWER_OFF,
    PM_APP_REQ_COVER_POWERDOWN,
    PM_APP_REQ_MASTER_CLEAR,
    PM_APP_REQ_MASTER_RESET,
    PM_APP_REQ_TCMD_POWER_OFF,
    PM_APP_REQ_TCMD_RESTART,
    PM_APP_REQ_TCMD_MASTER_CLEAR,
    PM_APP_REQ_TCMD_MASTER_RESET,
    PM_APP_REQ_TCMD_REFLASH,
    PM_APP_REQ_TCMD_PASSTHRU,
    PM_APP_REQ_SLEEP_ENABLE,
    PM_APP_REQ_LCD_DELAYSLEEP,
    PM_APP_REQ_BKLIGHT_ON
} PM_APP_REQUEST_T;

/* app vote for keep display and ap alive */
typedef enum {
    PM_APP_VOTE_CLEAR_ALL,
    PM_APP_VOTE_AP_ALIVE,
    PM_APP_VOTE_KEEP_ALL
} PM_APP_VOTE_T;

/* app notify setup */
typedef enum {
    PM_APP_SETUP_LCDSLEEP,
    PM_APP_SETUP_USEROFF,
    PM_APP_SETUP_FLIP,
    PM_APP_SETUP_IGNOREBP,
    PM_APP_SETUP_BKLIGHT,
    PM_APP_SETUP_POWERSAVE,
    PM_APP_SETUP_BLSLEEP,
        PM_APP_SETUP_KLSLEEP
} PM_APP_SETUP_T;

typedef struct {
    PM_APP_SETUP_T    id;
    union {
        UINT32    lcd_sleep_time;
        UINT32    useroff_enable;
        UINT32    flip_status;
        UINT32    ignore_enable;
        UINT32    bl_brightness;
        UINT32    power_saving;
                UINT32  bl_sleep_time;
                UINT32  kl_sleep_time; 
    } value;
} PM_APP_SETUP_BODY_T;

/*
 * app interface
 */
INT32 PM_app_connect();
INT32 PM_app_sendMsg(INT32 fd, UINT16 id, UINT8 *buf, UINT16 len);
INT32 PM_app_sendMsg2(INT32 fd, UINT16 id, UINT8 *buf, UINT16 len, pid_t pid);
void PM_app_disconnect(INT32 fd);

/*
 * packaged functions for messages
 */
INT32 PM_app_reqSend(PM_APP_REQUEST_T req);
INT32 PM_setupLcdSleepTime(UINT32 time);
INT32 PM_setupUseroffSupport(UINT32 enable);
INT32 PM_setupFlipStatus(UINT32 open);
INT32 PM_setupIgnoreBpSignal(UINT32 enable);
INT32 PM_setupBklightBrightness(UINT32 brightness);
INT32 PM_setupPowerSavingMode(UINT32 on);
INT32 PM_setupBklightSleepTime(UINT32 time);
INT32 PM_setupKeylightSleepTime(UINT32 time);

/**
 * PM_app_touchOnBklight - turn on lcd's backlight
 * 
 * Call this in your application when you only want to turn on the backlight.
 * This function only reset backlight's timer and does not reset lcd's timer, 
 * so when lcd is off, the backlight will not be turned on, 
 * when lcd's timer is expired, lcd and backlight will be turned off.
 */
INT32 PM_app_touchOnBklight();
#ifdef __cplusplus
}
#endif

#endif    /* _PM_APP_INTERFACE_H */
