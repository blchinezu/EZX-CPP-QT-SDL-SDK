/*------------------------------------------------------------------------------
  (c) Copyright Motorola 2002, All rights reserved.
  Motorola Confidential Proprietary
  Contains confidential proprietary information of Motorola, Inc.
  Reverse engineering is prohibited.
  The copyright notice does not imply publication.
  ------------------------------------------------------------------------------
  DESCRIPTION:

      1. This file is the header file of connection API. Connection API
         provides the interfaces to application to use the connection services.

  ------------------------------------------------------------------------------
  REVISION HISTORY:

      Date           Author               Reference
      --------    ------------    --------------------------
      02-09-09    Yuan Huailin        created
      02-10-25    Yuan Huailin        redefine the APIs

------------------------------------------------------------------------------*/
#ifndef CONN_API_H
#define CONN_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*---------------        MACROS        ---------------*/
#define CONCTL_UPRESULT_OK        1
#define CONCTL_UPRESULT_FAIL      2
#define CONCTL_UPRESULT_TIMEOUT   3
#define CONCTL_RESULT_BROKEN      4
#define CONCTL_RESULT_NOTHING     5
#define CONCTL_RESULT_SWITCH      6

#define CONCTL_SYN                0
#define CONCTL_ASYN               1

#ifndef CONCTL_MAXPROFILENAMELEN
#define CONCTL_MAXPROFILENAMELEN  62
#endif

#define CONN_PHYSIC_GPRS          1
#define CONN_PHYSIC_CSD           2
#define CONN_PHYSIC_UART          3
#define CONN_PHYSIC_IRDA          4
#define CONN_PHYSIC_USB           5
#define CONN_PHYSIC_BL            6

#define CONN_VPN_ALIVE            1   /*  VPN tunnel is on, VPN application is running */
#define CONN_VPN_HIDE             2   /*  VPN tunnel is on, VPN applicaton will quit */

#define CONNSOCKFILE  "/tmp/connsock.ipc"

/*---------------       TYPEDEFS       ---------------*/
/* operation types, used by CONN_CTRL_ConnOpen */
typedef enum tagConnCMD
{
    CONCTL_CMD_TOP = 0,
    /* popup a window to let user make choice */
    CONCTL_CMD_UP_POPUPSELECTION, 

    /* use system default profile */
    CONCTL_CMD_UP_USEDEFAULT,

    /* use profile specified by application */
    CONCTL_CMD_UP_USESPEC,

    /* use current connected profile, if none, will fail */
    CONCTL_CMD_UP_CURRENT,

    CONCTL_CMD_BOTTOM    
}CONCTL_CMD_T;

/*---------------      PROTOTYPES      ---------------*/
/*
 * FUNCTION    : int CONN_CTRL_Init(unsigned short usStyle)
 * DESCRIPTION : Initialize global variables, and setup style
 * ARGUMENTS   : usStyle, CONCTL_SYN or CONCTL_ASYN
 * RETURN VALUE: -1 - operation failed
 *                0 - operation succeed
 */
int CONN_CTRL_Init(unsigned short usStyle);

/*
 * FUNCTION    : void CONN_CTRL_SetBrokenHandler(void (*Handler)(int reserve))
 * DESCRIPTION :
 *     Setup callback function. When connection broken abnormally, Handler will
 *     be called. In SYNC mode, a timer is used to detect this. In ASYNC mode,
 *     application must provide timer mechanism, i.e. call CONN_CTRL_Poll 
 *     periodically.
 *     Application can setup broken handler only after initialization.
 * ARGUMENTS   : Handler, callback function
 * RETURN VALUE: NONE
 */
void CONN_CTRL_SetBrokenHandler(void (*Handler)(int reserve));

/*
 * FUNCTION    : void CONN_CTRL_SetSwitchHandler(void (*Handler)(int reserve))
 * DESCRIPTION :
 *     Setup callback function. When current connection switch from GPRS to CSD
 *     automatically, Handler will be called.
 *     Application need not setup this callback function, if it does not care 
 *     about this. This is also true for BROKEN handler.
 *     Similar to BROKEN handler, this should be called after initialization.
 * ARGUMENTS   : Handler, callback function
 * RETURN VALUE: NONE
 */
void CONN_CTRL_SetSwitchHandler(void (*Handler)(int reserve));

/* 
 * FUNCTION    : int CONN_CTRL_ConnOpen(CONCTL_CMD_T eCmd,
 *             :     void * profileName, unsigned uSeconds, int * piResult)
 * DESCRIPTION :
 *     Setup a connection. There are four kinds of operation, and two styles.
 *     For SYNC mode, this function will wait for the reply for "uSeconds" 
 *     seconds. If no internal error detected, 0 will be returned, piResult 
 *     set appropriately. Otherwize(like open socket failed), -1 will be returned,
 *     piResult will contain no value
 *     For ASYNC mode, return values are also 0 and -1, but the last two 
 *     parameters are not used. Application must call CONN_CTRL_Poll to get 
 *     the result.
 *     If application specified POPUP operation(eCmd == CONCTL_CMD_UP_POPUPSELECTION),
 *     a dialog will be first displayed to ask user to make choice, or to notify user
 *     when there is no profile available. The time used by user is not count in 
 *     the TIMEOUT value.
 *     Add new operation mode(CONCTL_CMD_UP_CURRENT). If no current connection, 
 *     operation will fail
 * ARGUMENTS   :
 *     eCmd - operation type, refer to type definition
 *     profileName - which profile to connect, used when eCmd is CONCTL_CMD_UP_USESPEC
 *     uSeconds - time out value, in seconds, only used for SYNC mode
 *     piResult - OUT parameter, only for SYNC mode, is one of the below
 *                CONCTL_UPRESULT_OK, CONCTL_UPRESULT_FAIL, CONCTL_UPRESULT_TIMEOUT
 * RETURN VALUE:  0 - normal case, still need to further check piResult, or for ASYNC mode
 *                    call CONN_CTRL_Poll and check the return value.
 *               -1 - find internal error or usage error
 */
int CONN_CTRL_ConnOpen(CONCTL_CMD_T eCmd, void * profileName, unsigned uSeconds, int * piResult);

/*
 * FUNCTION    : void CONN_CTRL_ConnClose(int reserve)
 * DESCRIPTION : 
 *     Pull down current (LOGICAL) connection. Application needs to call this function 
 *     only when a connection has been successfully opened before, and broken handler 
 *     has not been called afterward.
 *     For SYNC mode, if open connection request timed out, this request will be automatically
 *     canceled. Therefore application need not to call CONN_CTRL_ConnClose for this case.
 * ARGUMENTS   : reserve is not used, for compatibility purpose
 * RETURN VALUE: NONE
 */
void CONN_CTRL_ConnClose(int reserve);

/*
 * FUNCTION    : void CONN_CTRL_Release()
 * DESCRIPTION : Turn API to uninitialized state
 * ARGUMENTS   : NONE
 * RETURN VALUE: NONE
 */
void CONN_CTRL_Release(void);

/*
 * FUNCTION    : int CONN_CTRL_Poll(int reserve, unsigned uSeconds)
 * DESCRIPTION :
 *     Used for ASYNC mode operation, will wait upto "uSeconds" seconds, read and
 *     interpret any message from CONNECTION CONTROLLER, and return corresponding
 *     value
 *     If there is no active connection, -1 is returned immediately.
 *
 *     If CONNECTION SETUP is ongoing, CONCTL_UPRESULT_OK or CONCTL_UPRESULT_FAIL
 *     or CONCTL_UPRESULT_TIMEOUT can be returned.
 *     If CONCTL_UPRESULT_TIMEOUT is returned, CONNECTION SETUP process is still 
 *     going on, application should allow more time for this to complete. This is
 *     very different to SYNC mode operation. In SYNC mode operation, when timeout
 *     is detected, CONNECTION SETUP process is stopped before CONCTL_UPRESULT_TIMEOUT
 *     is returned, application has to call CONN_CTRL_ConnOpen again with larger
 *     timeout value.
 *
 *     If CONNECTION is already open, CONCTL_RESULT_BROKEN, CONCTL_RESULT_NOTHING or
 *     CONCTL_RESULT_SWITCH can be returned. CONCTL_RESULT_NOTHING is returned if get 
 *     no message from CONNECTION CONTROLLER in specified time. If BROKEN message is 
 *     detected, broken  handler is called(if set) and then CONCTL_RESULT_BROKEN is 
 *     returned. if SWITCH message is detected, switch handler is called(if set) and 
 *     then CONCTL_RESULT_SWITCH is returned.
 * 
 * ARGUMENTS   : reserve - not used, uSeconds - time out value
 * RETURN VALUE: refer to DESCRIPTION
 */
int CONN_CTRL_Poll(int reserve, unsigned uSeconds);

/*
 * FUNCTION    : int CONN_CTRL_GetConnInfo(char* buf, int buflen, int * type)
 * DESCRIPTION : Get profile name and physical type of current connection
 * ARGUMENTS   : buf - OUT parameter, will contain active profile name
 *               buflen - buffer length
 *               type - OUT parameter, contain current physical link type
 * RETURN VALUE: 0 - succeed, OUT parameter is filled with appropriate value
 *               -1 - failed
 */
int CONN_CTRL_GetConnInfo(char* buf, int buflen, int * type);

/*
 * FUNCTION    : int CONN_CTRL_SetVpnState(int vpnFlag )
 * DESCRIPTION : THIS API CAN ONLY USED BY VPN!!!
 *               to allow VPN to quit, but still keep the VPN tunnel
 * ARGUMENTS   : vpnFlag - VPN APPLICATION quit or start
 * RETURN VALUE: 0 - succeed
 *               -1 - failed
 */
int CONN_CTRL_SetVpnState(int vpnFlag );

#ifdef __cplusplus
}
#endif

#endif
