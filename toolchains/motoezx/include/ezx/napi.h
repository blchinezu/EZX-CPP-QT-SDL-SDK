#ifndef _NAPI_H_
#define _NAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/*-------------------------------------------------------------------------
 *
 *  Hearder Name: napi.h
 *
 *  General Description:  Network Application Programming Interface
 *
 *-------------------------------------------------------------------------
 *
 *                  Motorola Confidential Proprietary
 *       Template ID and version: IL93-TMP-01-0107  Version 1.10
 *        (c) Copyright Motorola 2002-2003, All Rights Reserved
 *
 *
 *-------------------------------------------------------------------------
 */

/**
 *@file napi.h
 *@brief This file defines network application programming interface on EZX platform
 *@author Xia Weizhong
 *@date 2003-12-08
 *@version 1.0
 */

/* four possible open modes */
/**
 *@enum NAPI_OPEN_MODE_T
 *@brief This defines the four possible open modes
 */
typedef enum {
    USER_SELECT  = 1, /**<Ask end user to make choice among the profiles.*/
    SYS_DEFAULT  = 2, /**<Use system default profile.*/
    APP_SPECIFIC = 3, /**<Use application defined profile.*/
    USE_CURRENT  = 4  /**<Attach to current active connection.*/
} NAPI_OPEN_MODE_T;

/* what is the actual physical type */
/**
 *@def NAPI_LINK_GPRS
 *@brief Define GPRS physical link type.
 */
#define NAPI_LINK_GPRS   1
/**
 *@def NAPI_LINK_CSD
 *@brief Define CSD physical link type.
 */
#define NAPI_LINK_CSD    2

/* return values for NAPI_POLL */
/**
 *@def NAPI_RESULT_SUCCESS
 *@brief A return value of NAPI_Poll(), connection start successfully.
 */
#define NAPI_RESULT_SUCCESS       1
/**
 *@def NAPI_RESULT_FAILURE
 *@brief Also return value of NAPI_Poll(), failed to start connection.
 */
#define NAPI_RESULT_FAILURE       2
/**
 *@def NAPI_RESULT_CONNECTING
 *@brief Return value of NAPI_Poll(), is still starting network.
 */
#define NAPI_RESULT_CONNECTING    3
/**
 *@def NAPI_RESULT_BROKEN
 *@brief Return value of NAPI_Poll(), connection broken unexpectedly.
 */
#define NAPI_RESULT_BROKEN        4
/**
 *@def NAPI_RESULT_NOTHING
 *@brief Return value of NAPI_Poll(), nothing happened.
 */
#define NAPI_RESULT_NOTHING       5
/**
 *@def NAPI_RESULT_SWITCH
 *@brief Return value of NAPI_Poll(), switch from GPRS to CSD.
 */
#define NAPI_RESULT_SWITCH        6

/* maximal supported profile name length */
/**
 *@def MAX_PROFILE_NAME_LEN
 *@brief maximal supported profile name length
 */
#define MAX_PROFILE_NAME_LEN      62

/**
 *@fn  int NAPI_Init(void)
 *@brief make ready for using NAPI
 *@param NONE
 *@retval -1  operation failed
 *@retval  0  operation succeed
 */
int NAPI_Init(void);

/**
 *@fn int NAPI_SetBrokenHandler(void (*handler)(int reserve) )
 *@brief Setup broken callback function. When connection broken unexpectedly, 
 * handler will be called. Application must provide timer mechanism,
 * i.e. call NAPI_Poll() periodically. Application can setup broken
 * handler only after initialization.
 *@param handler callback function
 *@retval -1  operation failed
 *@retval  0  operation succeed
 */
int NAPI_SetBrokenHandler(void (*handler)(int reserve) );

/**
 *@fn int NAPI_SetSwitchHandler(void (*handler)(int reserve) )
 *@brief Setup switch callback function. When current connection switch from
 * GPRS to CSD, the switch handler will be called. Similar to broken
 * handler, this should be called after initialization.
 *@param handler callback function
 *@retval -1  operation failed
 *@retval  0  operation succeed
 */
int NAPI_SetSwitchHandler(void (*handler)(int reserve) );

/**
 *@fn int NAPI_IsProfileValid( char* profileName );
 *@brief Check if the profile name exists.
 *@param profileName which profile check for
 *@retval UNKNOWN
 */
int NAPI_IsProfileValid( char* profileName );

/**
 *@fn int NAPI_OpenLink(NAPI_OPEN_MODE_T OpenMode, char* profileName)
 *@brief start connection per request
 *@param OpenMode the style the application want to use to start the
 * connection. There are four possible open modes, which are ::USER_SELECT,
 * ::SYS_DEFAULT, ::APP_SPECIFIC and ::USE_CURRENT.
 *@param profileName which profile to connect, used when OpenMode is ::USE_SPECIFIC
 *@retval -1  operation failed
 *@retval  0  normal case, still need to check return value of NAPI_Poll().
 */
int NAPI_OpenLink(NAPI_OPEN_MODE_T OpenMode, char* profileName);

/**
 *@fn void NAPI_CloseLink(void)
 *@brief Pull down current logical connection.
 *@param NONE
 *@return NONE
 *@note Application needs to call this function only when a connection has 
 * been successfully opened before, and broken handler has not been called
 * afterward.
 */
void NAPI_CloseLink(void);

/**
 *@fn void NAPI_DeInit(void)
 *@brief Return NAPI to uninitialized state
 *@param NONE
 *@return NONE
 */
void NAPI_DeInit(void);

/**
 *@fn int NAPI_Poll(void)
 *@brief Read and interpret any message from CONNECTION CONTROLLER, 
 * and return corresponding value.
 *@param NONE
 *@return -1, if there is no active connection. otherwize return ::NAPI_RESULT_SUCCESS,
 * or ::NAPI_RESULT_FAILURE, or ::NAPI_RESULT_CONNECTING, or ::NAPI_RESULT_BROKEN,
 * or ::NAPI_RESULT_SWITCH, or ::NAPI_RESULT_NOTHING.
 */
int NAPI_Poll(void);

/**
 *@fn int NAPI_Fini(void)
 *@brief End the connection
 *@param NONE
 *@return UNKNOWN
 */
void NAPI_Fini(void);

/**
 *@fn int NAPI_GetLinkInfo(char* profileName, int length, int* linkType)
 *@brief Get profile name and physical type of current connection
 *@param profileName OUT parameter, will contain active profile name.
 *@param length IN parameter, buffer length
 *@param linkType OUT parameter, contain current physical link type,
 * possible values are ::NAPI_LINK_GPRS and ::NAPI_LINK_CSD.
 *@retval  0 succeed, OUT parameters are filled with appropriate value.
 *@retval -1 failed, there is no active connection.
 */
int NAPI_GetLinkInfo(char* profileName, int length, int * linkType);
/* //libezxnapi
41f5b3ac T NAPI_Attach //
41f5b644 T NAPI_BindSocket2Link//
41f5bf6c T NAPI_BuildIPSecTunnel//
41f5bce0 T NAPI_CloseLink
41f5f13c T NAPI_CreateProfile//
41f5d1d4 T NAPI_DeleteProfile//
41f5ba14 T NAPI_Drop
41f5bf14 T NAPI_Fini
41f5c52c T NAPI_GetDeviceInfo
41f5e744 T NAPI_GetDiskSpace
41f5e098 T NAPI_GetHostByName
41f5e410 T NAPI_GetMaxProfiles
41f5d2fc T NAPI_GetProfileIDByName
41f5d554 T NAPI_GetProfileNameByID
41f5b74c T NAPI_Hold
41f5a6ec T NAPI_Init
41f5d2c4 T NAPI_IsProfileValid
41f5c894 T NAPI_ListAllProfile
41f5cb04 T NAPI_ModifyProfile
41f5b17c T NAPI_OpenLink
41f5f808 T NAPI_ReadProfile
41f5cf34 T NAPI_RenameProfile
41f5d830 T NAPI_SetProfileNameByID
41f5c1cc T NAPI_UmaBuildSecureTunnel
41f5dda8 T SendFlip2Dsm
41f5da20 T sendAlarm2Dsm*/

#ifdef __cplusplus
}
#endif

#endif
