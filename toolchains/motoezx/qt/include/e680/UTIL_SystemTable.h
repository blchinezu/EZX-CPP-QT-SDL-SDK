#ifndef UTIL_SYATEMTABLE_H
#define UTIL_SYATEMTABLE_H


//---------------------------------------------
//
//Header Name: 
//
//General Description:   
//
//---------------------------------------------
//Motorola Confidential Proprietary
//Advance Technology and software operations
//(c)Copyright Motorola 2002, All Rights Reserved
//
// Revision History:
//                             Modification     Tracking
// Author                          Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Li Jianbing                  03/23/2002                  Created 
// Yu Jianping                  12/29/2003      Libdd68167  Add countryId
// Wang Guochen/a17530          04/12/2004      LIBdd96947  Implement CPHS in Utility for A780
// Wang Guochen/a17530          04/23/2004      LIBee02317  Implement A780 CPHS phase2 in Utility
// Jamshid Wang/a5036c          06/15/2004      LIBdd95397  Support the EMU PIHF feature
// Wang Jingbo/w20607           07/22/2004      LIBee02317  add notifycationStatus
//                                                          and phoneCallIconIndex
// Hu Yingbo/w4765c             11/03/2004      LIBff32134  add mmsLaunchCamera
//                                                           and addrLaunchCamera
// Sun Xu/a18310                03/11/2005      LIBff72767  Implement BT VR
// ZHANG Qian / e2437c          03/22/2005     LIBff86970   Add notification pop-up status for Chameleon
// Sun Xu/a18310                04/04/2005      LIBff87040  Implement BT in-band ringtone
// Wang Jun/w4781c              04/07/2005      LIBff86395  Add CSD call stat and CFU stat
// ZHANG Qian / e2437c          08/10/2005     LIBgg63396   Add CLI Idle status for Chameleon.
// Hongxuan Fan / a21936        10/19/2005      LIBgg71325  Add BtFunLight status.

#include "UTIL_SystemTableDefine.h"


void UTIL_CreateSystemStatusTable();
void UTIL_ReleaseSystemTable();
void UTIL_CreateApplicationManagerStatusTable();
void UTIL_ReleaseApplicationManagerStatusTable();
void *UTIL_GetApplicationManagerTableAddress();
//void UTIL_CreatePowerOnStatusTable();
//void UTIL_ReleasePowerOnStatusTable();
//void *UTIL_GetPowerOnTableAddress();


#ifdef __cplusplus
extern "C"
{
#endif

SYSTEM_TABLE_T *UTIL_GetTableAddress();

/*
 * headset status
** 0 : no headset
** 1 : mono headset
** 2 : stereo headset
*/
int UTIL_GetHeadsetStatus();
void UTIL_SetHeadsetStatus(int s);

int UTIL_GetPhoneAudioDeviceStatus();
void UTIL_SetPhoneAudioDeviceStatus(int s);


/*
 * line number status
 * 0: line number 1, 
 * 1: line number 2
 */
int UTIL_GetPhoneLine();
void UTIL_SetPhoneLine(int s);

//int UTIL_GetCallChargeType();
//void UTIL_SetCallChargeType(int s);


/*
 * caller restrict id status 
 * 0: network controlled
 * 1: hide id
 * 2: show id
 */
//int UTIL_GetRestrictId();
//void UTIL_SetRestrictId(int s);

/*
 * caller restrict next id status 
 * 0: network controlled
 * 1: hide id enabled
 * 2: show id enabled
 */
//int UTIL_GetRestrictNextId();
//void UTIL_SetRestrictNextId(int s);

/*
 * the lock state of the hash of the JTAG and public keys. 
 * -1: error occurs.
 * 0:  the keys are unlocked
 * 1:  the keys are locked
 */
//int  UTIL_GetSecurityKeyLockState();
//void UTIL_SetSecurityKeyLockState(int s);

bool UTIL_GetPhoneInCall();
void UTIL_SetPhoneInCall(bool flag);

int UTIL_GetChargeStatus();
void UTIL_SetChargeStatus(int);

int UTIL_GetIncomingCallStatus();
void UTIL_SetIncomingCallStatus(int);

int UTIL_GetBTHSStatus();
void UTIL_SetBTHSStatus(int flag);

/*
 * 0: RF is open
 * 1: RF is close 
 */
int  UTIL_GetRFMode();
void UTIL_SetRFMode(int s);

/*
 * 0: Charge only
 * 1: PowerOn Normal
 * 2: Auto Power On
 * 3: Power PDA Mode
 * 255: Invalid value
 */
int  UTIL_GetPowerOnMode(); 
void UTIL_SetPowerOnMode(int s);

enum
{
    SYSTEM_POWNER_ON_PROCESS_BEFORE=0, //before power on process
    SYSTEM_POWNER_ON_PROCESS_ON,    //power on process
    SYSTEM_POWNER_ON_PROCESS_END,   //power on process end
};

void UTIL_SetPowerOnProcess(int s);
int UTIL_GetPowerOnProcess();
/*
 * 0: Sim available
 * 1: Sim bad
 * 2: No Sim
 * 3: Good Sim
 * 4: Invalid Value
 * 255: Unknown
 */
int  UTIL_GetSimCardStatus();
void UTIL_SetSimCardStatus(int s);

/*
 * Refer Pin status enumeration defined in UTIL_SystemTableDefine.h
 */
int  UTIL_GetPinStatus();
void UTIL_SetPinStatus(int s);

//int UTIL_GetSubsidyStatus();
//void UTIL_SetSubsidyStatus(int s);

/*
 * 0: AlarmServer has not loaded completely, not allowed to power off in auto-power-on mode
 * 1: AlarmServer has been launched, phone could be power off.
 */
//int UTIL_GetAlarmServerStatus();
//void UTIL_SetAlarmServerStatus(int s);

/*
 * 0: Gprs feature on
 * 1: Gprs feature off
 */
int  UTIL_GetGprsFeatureStatus();
void UTIL_SetGprsFeatureStatus(int s);

/* 
 * 0: Bluetooth is power down
 * 1: Bluetooth is power on
 * 2: Bluetooth is discoverable
 */
int  UTIL_GetBtStatus();
void UTIL_SetBtStatus(int s);

/* 
 *   0: Bluetooth is not connected
 * >=1: Bluetooth is connected
 */
int  UTIL_GetBtConnCount();
void UTIL_SetBtConnCount(int s);

/*
 * 0: Home
 * 1: Roam
 */
int  UTIL_GetRoamStatus();
void UTIL_SetRoamStatus(int s);

/*
 * 0 - 5
 */
int  UTIL_GetSignalQuality();
void UTIL_SetSignalQuality(int s);
 
/*
 * Get registered network id
 * Max length = 15 bytes
 */
void UTIL_GetNetworkId(char ntid[UTILITY_NETWORKID_LENGTH]);
void UTIL_SetNetworkId(const char ntid[UTILITY_NETWORKID_LENGTH]);

//int UTIL_GetNetworkStatus();
//void UTIL_SetNetworkStatus(int status);

//int UTIL_GetDialHyphenation();
//void UTIL_SetDialHyphenation(int status);

/* 
 * Get Current network name
 * Max length = 61 bytes (in utf8 format)
 */
void UTIL_GetServiceName(char srvnm[UTILITY_SERVICENAME_LENGTH]);
void UTIL_SetServiceName(const char srvnm[UTILITY_SERVICENAME_LENGTH]);

/* 
 * Get Service provider name
 * Max length = 61 bytes (in utf8 format)
 */
void UTIL_GetSpnName(char srvnm[UTILITY_SERVICENAME_LENGTH]);
void UTIL_SetSpnName(const char srvnm[UTILITY_SERVICENAME_LENGTH]);

//void UTIL_GetOrgSpnName(char srvnm[UTILITY_SERVICENAME_LENGTH]);
//void UTIL_SetOrgSpnName(const char srvnm[UTILITY_SERVICENAME_LENGTH]);

int UTIL_GetPhoneSystemStatus();
int UTIL_GetSIMPinBatteryStatus();

enum
{
    SYSTEM_PHONE_LOCK_UNLOCK=0,
    SYSTEM_PHONE_LOCK_LOCK=1
};
int  UTIL_GetPhoneLockStatus();
void UTIL_SetPhoneLockStatus(int s);

/*  
**            0:  no battery.   
**            1:  unchargable battery.
**            2:  chargable battery.  
**            3:  invalid battery.
**/
int  UTIL_GetBatteryStatus();
void UTIL_SetBatteryStatus(int s);
int  UTIL_GetBatteryLevel();
void UTIL_SetBatteryLevel(int s);

/*
** Îª1Ê±ÆÁÄ»Ëø×¡¡£
** SYSTEM_FLIP_CLOSE: close  //0
** SYSTEM_FLIP_OPEN: open    //1
*/
int UTIL_GetFlipStatus();
void UTIL_SetFlipStatus(int s);

/*
 * 0: Data connection is close
 * 1: Data connection is open
 */
int  UTIL_GetDataConnStatus();
void UTIL_SetDataConnStatus(int s);

#ifdef A780_CEBUS
//short UTIL_GetCEBus();
//void UTIL_SetCEBus(short ce);
#endif

#ifdef EMU_EIHF
short UTIL_GetEMUBus_Acc_Status();
void UTIL_SetEMUBus_Acc_Status(short em);
#endif

AUDIO_PATH_T UTIL_GetPhoneAudioPath();
void UTIL_SetPhoneAudioPath(AUDIO_PATH_T p);
//AUDIO_PATH_T UTIL_GetCurrentSystemAudioPath();
//void UTIL_SetCurrentSystemAudioPath(AUDIO_PATH_T p);


int UTIL_GetPhoneApplicationStatus();
void UTIL_SetPhoneApplicationStatus(bool started);


// set or retrieve the notification status
// 0 means there is no any notification
// 1 means there are some notifications
int UTIL_GetNotificationStatus();
void UTIL_SetNotificationStatus(int s);

// set or retrieve the index of phone call icon
int UTIL_GetPhoneCallIconIndex();
void UTIL_SetPhoneCallIconIndex(int index);

// set or retrieve the mmsLaunchCamera flag
int UTIL_GetMMSLaunchCamera();
void UTIL_SetMMSLaunchCamera(bool started);

// set or retrieve the addrLaunchCamera flag
int UTIL_GetAddrLaunchCamera();
void UTIL_SetAddrLaunchCamera(bool started);
 
/*
 * 0: No Service
 * 1: In Service
 */
int  UTIL_GetGprsServiceStatus();
void UTIL_SetGprsServiceStatus(int s);

/*
 * 0: Deattached
 * 1: Attached
 */
int  UTIL_GetGprsAttachStatus();
void UTIL_SetGprsAttachStatus(int s);

/*
 * 0: Deactivated
 * 1: Activated
 */
int  UTIL_GetGprsActivatedStatus();
void UTIL_SetGprsActivatedStatus(int s);

/*
 * 0: No Service
 * 1: In Service
 */
int  UTIL_GetEgprsServiceStatus();
void UTIL_SetEgprsServiceStatus(int s);

/*
 * 0: Disactived
 * 1: Actived
 */
int  UTIL_GetEgprsTransStatus();
void UTIL_SetEgprsTransStatus(int s);

/* 
 * 0: Idle
 * 1: busy
 */
int  UTIL_GetIrdaBusyStatus();
void UTIL_SetIrdaBusyStatus(int s);

int UTIL_GetAMApplicationStatus();
void UTIL_SetAMApplicationStatus(bool started);


int UTIL_GetPowerOffStatus();
void UTIL_SetPowerOffStatus(bool started);

void UTIL_SetThemeInfo(const struct UTIL_ThemeInfo_T& );
void UTIL_GetThemeInfo(struct UTIL_ThemeInfo_T*);

#ifdef MAKE_UISTYLE_CHAMELEON
//void UTIL_SetWidgetSkinnableProp( const struct ZWidgetSkinProps& );
//void UTIL_GetWidgetSkinnableProp( struct ZWidgetSkinProps * );
#endif

void UTIL_SetTPSoundInfo(const struct UTIL_TPSoundInfo_T& tp);
void UTIL_GetTPSoundInfo(struct UTIL_TPSoundInfo_T*);

void UTIL_SetHKSoundInfo(const struct UTIL_TPSoundInfo_T& tp);
void UTIL_GetHKSoundInfo(struct UTIL_TPSoundInfo_T*);

int UTIL_GetBtHandfreeStatus();
void UTIL_SetBtHandfreeStatus(int s);

bool UTIL_GetDlgPriority(int p);
void UTIL_SetDlgPriority(int p);
void UTIL_ResetDlgPriority(int p);

int UTIL_GetCountryId();
void UTIL_SetCountryId(int value);

/* 
 * Set CPHS Information.
 */
void UTIL_SetCphsInfo(const CPHS_INFO_T cphsInfo);

/* 
*  Get CPHS Shortform Operator Name Status
 * 0: Disable
 * 1: Enable
 */
int  UTIL_GetCphsOpnShortformSatus();

/* 
*  Get CPHS CSP Status
 * 0: Disable
 * 1: Enable
 */
int  UTIL_GetCphsCspStatus();

/* 
*  Get CPHS Voice Mailbox Status
 * 0: Disable
 * 1: Enable
 */
int  UTIL_GetCphsVMStatus();

/* 
 * Get CPHS SIM Card Status.
 * 0: NON-CPHS Card
 * 1: CPHS Card
 */
int  UTIL_GetCphsSimCardStatus();

/* 
 * Get/Set CPHS Line Lock flag.
 * 0: Unlocked
 * 1: Locked
 */
int UTIL_GetCphsLineLockStatus();
void UTIL_SetCphsLineLockStatus(int lock_status);

/* 
 * Get CPHS Operator Name String
 * Max length = 61 bytes (in utf8 format)
 */
void UTIL_GetCphsOperatorName(char opn[UTILITY_SERVICENAME_LENGTH]);
void UTIL_SetCphsOperatorName(const char opn[UTILITY_SERVICENAME_LENGTH]);


bool UTIL_GetTTYDeviceStatus();
void UTIL_SetTTYDeviceStatus(bool);

/*
 * status: 0:no data call; 1: CSD call; 2: GPRS call; 3:both CSD and GPRS
 *         Note: this status contains internal and external data call status
 */
void UTIL_SetDataCallStatus(unsigned char status);
void UTIL_GetDataCallStaus(unsigned char* status);

/**
 * transparency: true - enabled, false - disabled
 */
void UTIL_SetTransparency(bool enabled);
void UTIL_GetTransparency(bool* enabled);

/**
 * blending color: hex bit value of QRgb
 */
void UTIL_SetBlendingColor(unsigned int color);
void UTIL_GetBlendingColor(unsigned int* color);

/**
 * blendingPercentage: 0 ~ 100, 0 - Opaque, 100 - total Transparent
 */
void UTIL_SetBlendingPercentage(int percent);
void UTIL_GetBlendingPercentage(int* percent);

/**
 * blendingCST: 0 ~ 100, 0 - Opaque, 100 - total Transparent
 */
void UTIL_SetBlendingCST(int percent);
void UTIL_GetBlendingCST(int* percent);

/**
 * blendingGNB: 0 ~ 100, 0 - Opaque, 100 - total Transparent
 */
void UTIL_SetBlendingGNB(int percent);
void UTIL_GetBlendingGNB(int* percent);

/**
 * blendingStatusBar: 0 ~ 100, 0 - Opaque, 100 - total Transparent
 */
void UTIL_SetBlendingStatusBar(int percent);
void UTIL_GetBlendingStatusBar(int* percent);

/**
 * blendingScrollBar: 0 ~ 100, 0 - Opaque, 100 - total Transparent
 */
void UTIL_SetBlendingScrollBar(int percent);
void UTIL_GetBlendingScrollBar(int* percent);

void UTIL_SetTotalDuration(unsigned int  secs);
void UTIL_GetTotalDuration(unsigned int* secs);

void UTIL_SetTotalDataBytes(unsigned int totalbytes, unsigned int sentbytes, unsigned int recvedbytes);
void UTIL_GetTotalDataBytes(unsigned int* totalbytes, unsigned int* sentbytes, unsigned int* recvedbytes);


void UTIL_SetUSBConnectionStatus(int);
int UTIL_GetUSBConnectionStatus();

void UTIL_SetUSBChargingStatus(int);
int UTIL_GetUSBChargingStatus();

void UTIL_SetUSBDeviceType(int);
int UTIL_GetUSBDeviceType();




//void UTIL_SetEMUDeviceType(int);
//int UTIL_GetEMUDeviceType();

void UTIL_SetEarpieceSafety(int);
int UTIL_GetEarpieceSafety();


void UTIL_SetBatteryPercent(char bcs, char bcl);
void UTIL_GetBatteryPercent(char *bcs, char *bcl);

#ifdef EMU_PIHF_FEATURE
//added for emu carkit
//void UTIL_SetEMUSPDStatus(short);
//short UTIL_GetEMUSPDStatus();

//void UTIL_SetVRStatus(short);
//short UTIL_GetVRStatus();
#endif //EMU_PIHF_FEATURE

void UTIL_SetUsbMassStorage(unsigned char storage);
void UTIL_GetUsbMassStorage(unsigned char* storage);

void UTIL_SetTimingPhoneLock(int);
int UTIL_GetTimingPhoneLock();

//idle focus status. true:focus in, false:focus out
//void UTIL_SetIdleFocus(bool focusIn);
//int UTIL_GetIdleFocus();

//hide item state on call state screen menu. true:enable hide item, false:disable hide item
//void UTIL_SetHideState(bool hideAvailable);
//int UTIL_GetHideState();

// CLI idle status. 1: Idle, 0: Task.
#ifdef MAKE_UISTYLE_CHAMELEON
#ifdef MAKE_CLI_ENABLE
//void UTIL_SetCLIIdleStatus( int atIdle );
//int UTIL_GetCLIIdleStatus();
#endif
#endif

//screensaver is runing or not
//void UTIL_SetScreensaverStatus(unsigned char status);
//void UTIL_GetScreensaverStatus(unsigned char* status);

/*
 * CSD call status 
 * FALSE : no CSD call, 
 * TRUE :  has a CSD call
 */
//void UTIL_SetCSDCallStatus(bool hasCsdCall);
//int UTIL_GetCSDCallStatus();

/*
 * call forward status 
 * FALSE : not forward all, 
 * TRUE :  forward all
 */
//void UTIL_SetCallForwardStatus(bool isForwardAll);
//int UTIL_GetCallForwardStatus();

/*
 * call connected status
 * FALSE: has no connected call
 * TRUE: has connected call
 */
//void UTIL_SetCallConnectedStatus(bool hasConnectedCall);
//int UTIL_GetCallConnectedStatus();

/*
 *sideKey lock status.
 *true:lock,
 *false:unlock
 *UTIL_SetSideKeyLock: called by Martinique main diaplay Idle to set sidekey state 
 *UTIL_GetSideKeyLock: called by Martinique CLI Idle, keylock screen will be shown if sidekey locked
 */
//void UTIL_SetSideKeyLock(bool isLock);
//int UTIL_GetSideKeyLock();

/*
 *
 * sim lock/unlock status. true:lock, false:unlock
 *
 */
//void UTIL_SetSimLock(bool isLock);
//int UTIL_GetSimLock();

/*
 *
 * verify PIN1 procedure status, 
 * SYSTEM_VERIFY_PIN_STATUS_NO,  it is not in verify procedure
 * SYSTEM_VERIFY_PIN_STATUS_YES, it is in the verify procedure
 *
 */
//void UTIL_SetVerifyPin1Status(int status);
//int UTIL_GetVerifyPin1Status();


/*
 * get/set mmcsd pluged in/pluged out status.
 * 1: mmcsd pluged in.
 * 0: mmcsd pluged out.
 */
void UTIL_SetMMCSDStatus( unsigned char );
int  UTIL_GetMMCSDStatus();

/** 
* @brief When the STK doesn't support SETUP MENU command, 
*        the stkSetupMenuStatus should be set to false.
*/
//void UTIL_SetSTKSetupMenuStatus(bool bSetupMenu) ;
//bool  UTIL_GetSTKSetupMenuStatus(void);

/** 
* @brief get status at which stage system processes poweron.
*
*/
//void UTIL_SetPowerOnHandleStatus(int);
//int  UTIL_GetPowerOnHandleStatus(void);

//void  UTIL_SetPowerOnCliUIStatus(int);
//int  UTIL_GetPowerOnCliUIStatus(void);

//void UTIL_SetPowerOnModuleRunningStatus(int);
//int  UTIL_GetPowerOnModuleRunningStatus(void);

//void UTIL_SetEFEMMode(int);
//int  UTIL_GetEFEMMode(void);


//void UTIL_SetBtScoReadyForVr(bool);
//char UTIL_GetBtScoReadyForVr(void);

#ifdef MAKE_UISTYLE_CHAMELEON
// Notification pop-up status.
unsigned int UTIL_GetNotiPopupStatus();
//void UTIL_SetNotiPopupStatus( unsigned int );
#endif

//WIFI-related
//int UTIL_GetWifiCampStatus( void );
//void UTIL_SetWifiCampStatus( int );
//int UTIL_GetWifiSignalBar( void );
//void UTIL_SetWifiSignalBar( int );
//int UTIL_GetWifiConnectionInProgress( void );
//void UTIL_SetWifiConnectionInProgress( int );
//int UTIL_GetWifiLingertime( void );
//void UTIL_SetWifiLingertime( int );
//int UTIL_GetWifiUMALingertime( void );
//void UTIL_SetWifiUMALingertime( int );

//int UTIL_GetCPHSCallForwardStatus( void );
//void UTIL_SetCPHSCallForwardStatus( int );

//bool UTIL_GetChargeCompletedStatus();
//void UTIL_SetChargeCompletedStatus(bool completed);
//bool UTIL_GetLowBatteryStatus();
//void UTIL_SetLowBatteryStatus(bool low);
//bool UTIL_GetOpeatorLogoStatus();
//void UTIL_SetOpeatorLogoStatus(bool logo);
//bool UTIL_GetSpnDisplayedStatus();
//void UTIL_SetSpnDisplayedStatus(bool spn);
//bool UTIL_GetCallBarringStatus();
//void UTIL_SetCallBarringStatus(bool bar);
//bool UTIL_GetKeypadLockStatus();
//void UTIL_SetKeypadLockStatus(bool key);


//void UTIL_SetBtA2dpStatus(char status);
//char UTIL_GetBtA2dpStatus(void);

#ifdef MAKE_UISTYLE_CHAMELEON
//void UTIL_SetBtFunLightStatus(char status);
//char UTIL_GetBtFunLightStatus(void);
#endif


//void UTIL_GetCarrierKeySettings( bool &contextual, bool &inCallEnabled, bool &pnh );

enum
{
    APPLOCK_SESSION_LOCKED=0,// application lock session is locked status
    APPLOCK_SESSION_UNLOCKED=1//application lock session is unlocked status
};
//int  UTIL_GetAppLockSessionStatus();
//void UTIL_SetAppLockSessionStatus(int s);

//int UTIL_GetEnteringSubsidyCode();
//void UTIL_SetEnteringSubsidyCode(int s);

// get and set the sim card change status
//bool UTIL_GetSimCardChangedStatus();
//void UTIL_SetSimCardChangedStatus();

// get and set language open layout engine flag
//bool UTIL_GetLanOpenLayout();
//void UTIL_SetLanOpenLayout(bool bOpen);

#ifdef __cplusplus
}
#endif

#endif
