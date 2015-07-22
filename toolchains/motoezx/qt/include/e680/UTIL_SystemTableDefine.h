#ifndef UTIL_SYATEMTABLEDEFINE_H
#define UTIL_SYATEMTABLEDEFINE_H


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
// Wang Jingbo/w20607           07/22/2004      LIBee02317  add notifycationStatus
//                                                          and phoneCallIconIndex
// Hu Yingbo/w4765c             10/03/2004      LIBff32134  add mmsLaunchCamera 
//                                                          add addrLaunchCamera
// Xu Haifeng/w19978            11/25/2004      LIBff40032  Merge cphs information numbers feature into E680i
// Sun Xu/a18310                03/04/2005      LIBff72767  Implement BT VR.
// ZHANG Qian / e2437c          03/22/2005     LIBff86970   Add notification pop-up status for Chameleon.
// Wang Jun(w4781c)             04/01/2005      LIBff86395  add phone statue update
// Sun Xu/a18310                04/04/2005      LIBff87040  Implement BT in-band ringtone
// ZHANG Qian / e2437c          08/10/2005     LIBgg63396   Add CLI Idle status for Chameleon.
// Tian Yang /e5764c            10/20/2005     LIBhh14547   Add Sim Card change status.
// Hongxuan Fan / a21936        10/19/2005      LIBgg71325  Add BtFunLight status.


#ifdef __cplusplus
extern "C" 
{
#endif

#define UTILITY_NETWORKID_LENGTH   16     //according to MAX_PLMN_NAME_LENGTH       (15+1)
#define UTILITY_SERVICENAME_LENGTH 61     //according to MAX_NT_SERVICE_NAME_LEN     41(unicode)

#define UTILITY_CPHS_VMNAME_LENGTH		61
#define UTILITY_CPHS_VMNUM_LENGTH		44

#define CEBUS_STATUS_MSG "EZX_CE_BUS"
#define UTIL_THEME_MAXFILELEN     256


#define EMU_ACCESSORY_EVENT_CHANNEL "/app/emu/event/chn"
#define EMU_ACCESSORY_EVENT_MESSAGE_CHARGER "/app/emu/msg/charger"
#define EMU_ACCESSORY_EVENT_MESSAGE_HEADSET "/app/emu/msg/hs"
#define EMU_ACCESSORY_EVENT_MESSAGE_CARKIT "/app/emu/msg/carkit"
#define EMU_ACCESSORY_EVENT_MESSAGE_USB "/app/emu/msg/usb"
#define EMU_ACCESSORY_EVENT_MESSAGE_USB_CURRENT_500MA "/app/emu/msg/usb/current/500ma"
#define EMU_ACCESSORY_EVENT_MESSAGE_USB_CURRENT_0MA "/app/emu/msg/usb/current/0ma"
#define EMU_ACCESSORY_EVENT_MESSAGE_OTHERS "/app/emu/msg/others"

#define SYSTEM_KEYPAD_REPORT_KEY_STATUS_CHANNEL  "/app/keypad/report/key"
#define SYSTEM_DRIVER_KEY_STATUS_MSG  "keyStatusMsg"

#define PHONE_IDLE_SCR_FOCUS_STAT_CHANNEL "/app/phone/msg/idlestat"
#define PHONE_IDLE_SCR_FOCUS_STAT_MSG "idleScrFocusStatMsg"

#define PHONE_AUDIO_PATH_STATUS_CHANNEL "/app/phone/sys/audio/path"
#define PHONE_AUDIO_PATH_STATUS_MSG "AudioPathUpdateMsg"

#define ACCESSORY_DEVICE_REPORT_MSG "A780_DEVICE_REPORT"

#define MAX_LANGUAGE_CODE_LEN 10

enum
{
    EMU_DEVICE_TYPE_NONE = 0,
    	
    EMU_DEVICE_TYPE_CHARGER,
    
    EMU_DEVICE_TYPE_CARKIT_MID,
    EMU_DEVICE_TYPE_CARKIT_FAST,
    EMU_DEVICE_TYPE_CARKIT_SMART,

    EMU_DEVICE_TYPE_CARKIT_HEADSET_STEREO,
    EMU_DEVICE_TYPE_CARKIT_HEADSET_EMU_MONO,
    EMU_DEVICE_TYPE_CARKIT_HEADSET_EMU_STEREO,

    EMU_DEVICE_TYPE_USB,
};


enum
{
    HEADSET_TYPE_COMMON_MONO = 0x01,
    HEADSET_TYPE_COMMON_STEREO = 0x02,
    HEADSET_TYPE_HIFI_35_WITHOUT_MIC = 0x04,
    HEADSET_TYPE_HIFI_35_WITH_MIC = 0x08,
};


typedef enum 
{
    PHONE_UI_UNKNOWN = 0,
    PHONE_UI_SEARCHING,
    PHONE_UI_REGISTERING,
    PHONE_UI_REGISTERED,
    PHONE_UI_NONETWORK,
    PHONE_UI_NETWORKBUSY,
    PHONE_UI_EMERGENCYONLY,
    PHONE_UI_BADSIMCARD
}PHONE_UI_NETWORK_STATUS_T;



enum
{
    DEVICE_TYPE_EMU_USB_0mA = 0,
    DEVICE_TYPE_EMU_USB_500MA,
};

enum
{
    USB_CONNECTION_STATUS_OUT = 0,
    USB_CONNECTION_STATUS_IN,
};

enum
{
    USB_EUM_DEVICE_TYPE_NONE = 0,
    USB_EUM_DEVICE_TYPE_NETMONITOR,
    USB_EUM_DEVICE_TYPE_MODEM_CABLE,
    USB_EUM_DEVICE_TYPE_APLOG_CABLE,
    USB_EUM_DEVICE_TYPE_CFG11_CABLE,
    USB_EUM_DEVICE_TYPE_DSPLOG_CABLE,
    USB_EUM_DEVICE_TYPE_USBNET_CABLE,
    USB_EUM_DEVICE_TYPE_PST_CABLE,
    USB_EUM_DEVICE_TYPE_MASSSTORGE_CABLE,
};


typedef enum
{
    AUDIO_PATH_NONE = 0,
    AUDIO_PATH_PHONE,   //earpiece
    AUDIO_PATH_HANDFREE,	
    AUDIO_PATH_HEADSET,	
    AUDIO_PATH_EMU_HEADSET,	
    AUDIO_PATH_BTHS,	 
    
    AUDIO_PATH_PIHF,
    AUDIO_PATH_EIHF,
    AUDIO_PATH_FM,
    AUDIO_PATH_BTCARKIT,

    AUDIO_PATH_FLIPRECEIVER,
    AUDIO_PATH_BT_A2DP,    

    AUDIO_PATH_AMOUNT,
}AUDIO_PATH_T;

enum
{
    Dialog_Priority_level0 = 0,
    Dialog_Priority_level1,
    Dialog_Priority_level2,
    Dialog_Priority_level3,
    Dialog_Priority_level4,
    Dialog_Priority_levelMax,
};

// for dial prefix hyphenation
typedef enum
{
  PHONE_SETUP_HYPHENATION_AUTO=0,
  PHONE_SETUP_HYPHENATION_ON,
  PHONE_SETUP_HYPHENATION_OFF,
}PHONE_SETUP_HYPHENATION_T;

struct UTIL_ThemeInfo_T
{
#ifdef MAKE_UISTYLE_TACTIUM
    int index;
    unsigned int bgRgb;
    unsigned int fgRgb;
    unsigned int btnRgb;
    unsigned int btnTxtRgb;
    unsigned int hlRgb;
    unsigned int hlTxtRgb;
    unsigned int brightTxtRgb;
    unsigned int disabledTxtRgb;
    unsigned int amBothlRgb;
    unsigned int amBothlTxtRgb;
    int txtSize;
    char logoIcon[UTIL_THEME_MAXFILELEN];
    char skinFile[UTIL_THEME_MAXFILELEN];
#endif
    char iconDir[UTIL_THEME_MAXFILELEN];
} __attribute__((packed));

struct UTIL_TPSoundInfo_T
{
    int type;
    int volume;
} __attribute__((packed));

typedef struct
{
    char phaseStatus;
    char voicemailStatus;
    char opnameShortformStatus;
    char cspStatus;
    char infoNumbersStatus;
    char sstStatus;
}CPHS_INFO_T;

typedef struct
{
    char cci_flag[2];
    char number[2][UTILITY_CPHS_VMNUM_LENGTH];
    char alpha_tag[2][UTILITY_CPHS_VMNAME_LENGTH];
}CPHS_VMN_T;

struct UTIL_ConnectedDuration
{
    unsigned int totoalsecs;
}__attribute__((packed));

struct UTIL_DataBytes
{
    unsigned int totalbytes;
    unsigned int totalsentbytes;
    unsigned int totalrecvedbytes;
}__attribute__((packed));

struct UTIL_DataCallMeter
{
    struct UTIL_ConnectedDuration duration;
    struct UTIL_DataBytes databytes;
    unsigned char type;     //0: No data call;1:GPRS; 2:CSD; 3:GPRS&CSD
} __attribute__((packed));

struct SYSTEM_TABLE_T
{
    AUDIO_PATH_T phoneAudioPath;
    short cebus;
    short emu;
    char powerOnMode;
    char powerOnProcess;
    int powerOnHandleStatus;
    int powerOnRunningStatus;
    int powerOnCLI;
    int efemMode;

    char phoneLock;
    char rfmode;
    char simcardStatus;
    char pinStatus;
    int subsidyStatus;
    int isCheckingSubsidy;
    int alarmServerStatus;    //AlarmServer launch status

    char batteryStatus;
    char batteryLevel;
    char batteryBCS;
    char batteryBCL;
    int lowBattery;
    int chargeCompleted;
    
    int operatorLogoDisplayed;
    int spnDisplayed;
    int callBarringStatus;
  
    char gprsFeatureStatus;
    char bluetoothStatus;
    char btConnCount;
    char roamStatus;
    char signalQuality;

    char notificationStatus;
    char phoneCallIconIndex;

    char mmsLaunchCamera;
    char addrLaunchCamera;
    
    char incomingCall;
    char BTHS;

#ifdef MAKE_UISTYLE_CHAMELEON    
    char btFunLightStatus;
#endif

    int headset;
    char phoneDevice;

    // Line number status
    char phoneLine;

    // call charge type
    int callChargeType;

    // caller restrict id status
    char restrictId;    
    char restrictNextId;    

    int securityKeyLockState;

    char phoneInCall;
    char chargeStatus;

    char gprsServiceStatus;
    char gprsAttachStatus;
    char gprsActivatedStatus;

    char filpStatus;

    char dataConnStatus;
    char phoneAppStatus;
    char stkSetupMenuStatus;

    char egprsServiceStatus;
    char egprsTransStatus;
    char irdaBusyStatus;

    char amAppStatus;
    char poweroff;
    int CountryId;

    struct UTIL_ThemeInfo_T theme;
#ifdef MAKE_UISTYLE_CHAMELEON
    struct ZWidgetSkinProps skinnableProp;
#endif
    struct UTIL_TPSoundInfo_T tpsound;
    struct UTIL_TPSoundInfo_T hksound;
    
    char networkId[UTILITY_NETWORKID_LENGTH]; 
    char cnnName[UTILITY_SERVICENAME_LENGTH];     //Current network name
    char spnName[UTILITY_SERVICENAME_LENGTH];     //Service provider name
    char orgSpnName[UTILITY_SERVICENAME_LENGTH];     //Service provider name
    
    int networkStatus; 
    int dialHyphenation;

    char btHandfreeStatus;
    char priorityDlg[Dialog_Priority_levelMax];

    // For CPHS
    CPHS_INFO_T cphsInfo;                              //6F16->CPHS Information
    CPHS_VMN_T cphsVMN;                                //6f17->Voice Mailbox Numbers
    int cphsVMCount[2];                                //Voice Messages Count for Line1/2
    char cphsLineLockStatus;                           //Line Lock status
    char cphsOpn[UTILITY_SERVICENAME_LENGTH];          //Operator Name String
    char cphsOpnShortform[UTILITY_SERVICENAME_LENGTH]; //Operator Name String Shortform
    char ttyDevice;

    //Data call meter
    struct UTIL_DataCallMeter dcm;

    //idle focus status
    char idleFocusStatus;

    //hide item state on call state menu.
    char isHideAvailable;

    // CLI Idle status
#ifdef MAKE_UISTYLE_CHAMELEON
#ifdef MAKE_CLI_ENABLE
    char cliIdleStatus;
#endif
#endif

    // CSD call status
    char csdCallStatus;

    // call forward status
    char callForwardStatus;
    int cphsCallForwardStatus;

    // call connected status;
    char callConnectedStatus;

    //side key lock status
    char sideKeyLockStatus;
    int keyPadLock;

    // sim Pin1 status
    char verifyPin1Status; // used in power on & verify Pin1 status, e2720c add.

    //sim lock status
    char simLockStatus;

    //Transparency
    char transparency;
    unsigned int blendingColor;
    int blendingPercentage;
    int blendingGNB;
    int blendingCST;
    int blendingStatusBar;
    int blendingScrollBar;

    //WIFI-related
    int wifiCamped;
    int wifiSignalBar;
    int wifiConnectionInProgress;
    int wifiLingertime;         //ON wifi AP linger time
    int wifiUMALingertime;      //ON UMA network linger time

    int usbConnection;
    int usbCharging;
    int usbDevType; 

    int emuDeviceType;

    int earpieceSafety;
    int audioPathNotInCall;

#ifdef EMU_PIHF_FEATURE
    short emuspd;
    short vr;
#endif

    //for screensaver and uns
    char screensaverStatus;

    char massStorage;
    int timingPhoneLock;

    char mmcsdExist;    // MMC/SD feature.

    char btScoReadyForVr;

    char btA2dpStatus;
#ifdef MAKE_UISTYLE_CHAMELEON
    unsigned int notiPopupStatus; // Notification pop-up status.
#endif

    char CarrierKeyContext;  // Whether support contextual behavior of Carrier key
    char CarrierKeyInCall;   // Whether enabled when in call connected or making call
    char CarrierKeyPnH;      // Whether support Carrier key press and hold

    char languageCode[MAX_LANGUAGE_CODE_LEN];
    char appLockSessionStatus;

    //for sim card change status
    char simCardChanged;

    //add by Cao Jinghua to support performance of layout engine 2006/02/23
    char lanOpenLayoutEngine;
    //end Cao Jinghua

}  __attribute__((packed));

enum
{
	ALS_LINE_1 = 0,
	ALS_LINE_2
};

enum
{
    ACEESORY_CEBUS_NONE_DEVICE = 0,
    ACEESORY_CEBUS_PC_POWERED_USB,
    ACEESORY_CEBUS_DUMB_TTY,
    ACEESORY_CEBUS_DUMB_DESKTOP_SPEAKERPHONE,
    ACEESORY_CEBUS_DUMB_PTT_HEADSET,
    ACEESORY_CEBUS_DUMB_FM_RADIO_HEADSET,
    ACEESORY_CEBUS_DUMB_IRDA_ADAPTER,
    ACEESORY_CEBUS_DUMB_CLIP_ON_SPEAKERPHONE,
    ACEESORY_CEBUS_DUMB_SMART_AUDIO_DEVICE,
    ACEESORY_CEBUS_DUMB_EIHF,
    ACEESORY_CEBUS_PHONE_POWERED_USB,
    ACEESORY_CEBUS_RS232_8_WIRES,
    ACEESORY_CEBUS_RS232_4_WIRES,
    ACEESORY_CEBUS_PUSHTOTALK_PTT,
};

enum
{
    SYSTEM_FULL_FEATURE = 0,
    SYSTEM_NOT_FULL_FEATURE,
};

enum
{
    SYSTEM_SIM_PIN_BATTERY_READY = 0,
    SYSTEM_SIM_PIN_BATTERY_NOT_READY,
};


/*
 * pin status enumeration
 */
enum
{
    SYSTEM_PIN_ENABLED = 2,
    SYSTEM_PIN_DISABLED = 3,
    SYSTEM_PIN_BLOCKED = 5,
    SYSTEM_PIN_PERMANENT_BLOCKED = 6,
    SYSTEM_PIN_CHECKED = 7,
    SYSTEM_PIN_UNKNOWN = 8,
    SYSTEM_PIN_INVALID = 255,
};

enum
{
    ACEESORY_EMU_NONE_DEVICE = 0,
    ACEESORY_EMU_EIHF_DEVICE
};

/*
 * batter status enumeration
 */
enum 
{
    SYSTEM_BATTERY_STATUS_NONE  = 0,
    SYSTEM_BATTERY_STATUS_UNCHARGABLE,
    SYSTEM_BATTERY_STATUS_CHARGABLE, 
    SYSTEM_BATTERY_STATUS_INVALID, 
    SYSTEM_BATTERY_STATUS_UNKOWN  = 255
};

/*
 * Sim status enumeration
 */
enum
{
    SYSTEM_SIM_STATUS_AVAILABLE = 0,
    SYSTEM_SIM_STATUS_BAD, 
    SYSTEM_SIM_STATUS_NONE,
    SYSTEM_SIM_STATUS_GOOD,
    SYSTEM_SIM_STATUS_INVALID,
    SYSTEM_SIM_STATUS_UNKNOWN = 255
};

/*
 * Power on mode enumeration
 */
enum
{
    SYSTEM_POWERON_MODE_CHARGE_ONLY = 0,
    SYSTEM_POWERON_MODE_NORMAL,
    SYSTEM_POWERON_MODE_AUTO,
    SYSTEM_POWERON_MODE_PDA_MODE = 3,
    SYSTEM_POWERON_MODE_UNKNOWN = 255
};


enum
{
    SYSTEM_POWERON_TRANSFER_STARTING = 0,	//< the first state: Starting
    SYSTEM_POWERON_TRANSFER_WAITING_POWER_ON_MODE,	//< waiting for power on mode 
    SYSTEM_POWERON_TRANSFER_WAITING_SIM_CARD,	 //< waiting for SIM Card status
    SYSTEM_POWERON_TRANSFER_WAITING_PIN,	     //< user is inputing PIN
    SYSTEM_POWERON_TRANSFER_WAITING_SUBSIDY,
    SYSTEM_POWERON_TRANSFER_WAITING_PHONE_LOCK,	 //< user is inputing phone lock password
    SYSTEM_POWERON_TRANSFER_WAITING_CHECK_AIRPLANE_MODE,	 //< user is inputing phone lock password

    //Displaying UI during poweron automatically,
    SYSTEM_POWERON_TRANSFER_WAITING_AUTO_POWERON_UI,

    SYSTEM_POWERON_TRANSFER_STK_RESET_WAITING_SIM_CARD,
    SYSTEM_POWERON_TRANSFER_STK_RESET_WAITING_PIN,

    SYSTEM_POWERON_TRANSFER_FINISHED,
    SYSTEM_POWERON_TRANSFER_NOT_FULLY_FINISHED,
};

enum
{
    SYSTEM_POWERON_SYNC_CLI_UI_NONE = 0,
    SYSTEM_POWERON_SYNC_CLI_UI_CHARGINGONLY,
    SYSTEM_POWERON_SYNC_CLI_UI_BADSIM,
    SYSTEM_POWERON_SYNC_CLI_UI_NOSIM,
    SYSTEM_POWERON_SYNC_CLI_UI_PINLOCK,
    SYSTEM_POWERON_SYNC_CLI_UI_PHONELOCK,
    SYSTEM_POWERON_SYNC_CLI_UI_ENTER_AIRPLANE,
    SYSTEM_POWERON_SYNC_CLI_UI_EXIT_AIRPLANE,
    SYSTEM_POWERON_SYNC_CLI_UI_END,
};


enum
{
    SYSTEM_SUBSIDY_STATUS_LOCK_OFF = 0,
    SYSTEM_SUBSIDY_STATUS_LOCK_ON,       
    SYSTEM__SUBSIDY_STATUS_LOCK_WAIT,     
    SYSTEM_SUBSIDY_STATUS_LOCK_UNKNOWN, 
    SYSTEM_SUBSIDY_STATUS_UNKNOWN = 255,
};


enum
{
    SYSTEM_VERIFY_PIN_STATUS_NO,
    SYSTEM_VERIFY_PIN_STATUS_YES,
};


#ifdef __cplusplus
}
#endif

#endif
