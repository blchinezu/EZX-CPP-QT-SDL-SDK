//--------------------------------------------------------------------------------------------------
//                                                                               
//
//                            Motorola Confidential Proprietary
//                   Template ID and version: IL93-TMP-01-0107  Version 1.10
//                    (c) Copyright Motorola XXXX-XXXX, All Rights Reserved
//   
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Developer Name/ID            MM/DD/YYYY     CSGceXXXXX   BRIEF description of changes made   
//
// Tim Zhao/w19411              6/25/2002                       created first time
// Yao Jianfeng/a18004          03/05/2004     LIBdd83804   Modify AM and setup for IM and RealOne.
// Yao Jianfeng/a18004          9/16/2002      LIBdd46519   Implement Storage and 
//                                                          application interface for WVIMPs 
// Li Shaoheng/a3020c           03/03/2004     LIBdd76533   WAP Push Message Support 
// Lisa Wang/a17783             09/22/2004     LIBff15642   Port fmradio to 680i
// 
//
//--------------------------------------------------------------------------------------------------

#ifndef __AM_GLOBAL_H__
#define __AM_GLOBAL_H__

#include <qstring.h>
#include <qimage.h>
#include <quuid.h>
#include <qcopchannel_qws.h>

#include <sys/types.h>
#include <sys/time.h>
//#include "ezxlog_define.h"

//
// added by zhu jintao
//
#define	AM_GLOBAL_MSG__SENDSMS_QSTRING_QSTRING                      "sendSms( QString, QString )"
#define	AM_GLOBAL_MSG__SENDSMS_NOEDITOR_QSTRING_QSTRING             "sendSmsNoEditor( QString, QString )"
#define	AM_GLOBAL_MSG__SENDMMS_QSTRING_QSTRING_BOOL_APPS            "sendMms( QString, QString, bool, Apps )"
#define	AM_GLOBAL_MSG__OPENMMSFILE_QSTRING                          "openMmsFile( QString )"
#define	AM_GLOBAL_MSG__SENDWAPPUSHMSGTOMESSAGINGCENTER_QBYTEARRAY   "sendWapPushMsgToMessagingCenter( QByteArray )"
#define	AM_GLOBAL_MSG__SENDWAPPROVISIONEVENTTOMESSAGINGCENTER_INT   "sendWapProvisionEventToMessagingCenter( int )"
#define	AM_GLOBAL_MSG__SENDPHONESTATUSTOMESSAGINGCENTER_INT         "sendPhoneStatusToMessagingCenter( int )"
#if 0
// these variables are obsoleted! by w21004
extern const int AM_Installed_App_Start_Num;
extern const int AM_Installed_App_Mime_Start_Num;
extern const int AM_Installed_App_On_PlugCard_Start_Num;
extern const int AM_Installed_App_On_PlugCard_Mime_Start_Num;
extern const int AM_Config_App_Start_Num;
extern const int AM_Config_App_Mime_Start_Num;
extern const int AM_Preload_JavaApp_Start_Num;
extern const int AM_Preload_JavaApp_Mime_Start_Num;
// end comment by w21004
#endif
//
// for debug, print out class name, number function name, line number, time, pid, and your own comment 
//
#if 0
#define AM_Global_Debug( comment )										\
do														\
{														\
    tms *tms_ = NULL;												\
	qDebug( "\n############################%s::%s, line:%d pid:%d, time:%d, %s\n",				\
		__FILE__, __FUNCTION__, __LINE__, getpid(), (int)times( tms_ ), QString( comment ).latin1() );	\
} while ( 0 )
#else
#define AM_Global_Debug( comment )
#endif

#define AM_SAFE_DELETE(p) if(p!=0){delete p; p = 0;}


typedef QString AM_AppObjSerialID;  // Type definition of app uid
typedef QUuid   AM_APPID_T;         // Type definition of application id.

class AM_Global
{
public:
    enum Device
    {
        InvalidDevice = -1,     ///< used for initialization only
        Flash1 = 0,             ///< there are read-only file system and writable file system
        Flash2 = 1,             ///< DOC file system, for storing user data
        Card1 = 2,              ///< can be plug in and plug out
        Card2 = 3,              ///< can be plug in and plug out
        Preload = 4             ///< virtual device used by preload java apps
    };

    /**
     * in order to avoid confusing, using the name in UI Spec and UI Style Guide
     * because UI team always change the application names
     * so you see, the names are confusing and urgely
     */
    enum Apps
    {
        //
        // just only for initialization
        //
        InvalidApp = -1,

        //
        // GNB applications
        //
        Home = 0,
        Addressbook = 1,
        Notifications = 2,
        Compose = 3,            ///< EMS and MMS on GNB
        Call = 4,               ///< It is phone, to avoiding confusion, use UI name

        //
        // home applications
        //
        RecentCall = 61,
        MMCApp = 62,
        EMail = 64,
        People = 65,
        Calendar = 66,
        Tasks = 67,
        Notes = 68,
        VoiceRecorder = 69,
        Clock = 70,
        MediaPlayer = 71,
        Camera = 72,
        DrawingPad = 73,
        PictureViewer = 74,
        Games = 75,
        PersonalSetting = 76,
        SystemSetup = 77,
        Calculator = 79,
        FileManagement = 81,
        Inetsetup = 82,
        STK = 83,
        Link = 84,
        Browser = 85,
        Modem = 86,
        WorldClock = 87,
        Syncml = 88,
        RingComposer = 89,
        AlarmClock = 91,
        BlueTooth = 92,
        JavaApp = 93,
        MideDemo = 94,
        VideoDemo = 95,
        InitialSetup = 96,
        PowerSetup = 97,
        SecuritySetup = 98,
        Certificates = 99,
        Wvimps = 100,
        Provision = 102,
        Camcord = 103,
        CameraKey = 104,
        Radio = 105,

        //
        // Preload applications
        // 
        MotoVPN = 600,
        GoTone = 601,
        Service = 602,
        Picsel = 603,
        AlertStyle = 604,
        VOD = 605
    };

//REFACTORY:Move to  AM_HomeScreenConfig Begin
    //
    // get global geometry size
    //
    inline static int getGnbHeight(void);
    inline static int getCstShortButtonWidth(void);
    inline static int getCstLongButtonWidth(void);
    inline static int getCstHeight(void);
    inline static const QSize getSmallIconSize(void);
    inline static const QSize getBigIconSize(void);

    /**
     * get the GNB length
     *
     * @param
     *
     * @return the GNB height
     *
     */
    static int getGnbLength(void);
    static int getScreenWidth(void);
    static int getScreenLength(void);
//REFACTORY:Move to  AM_HomeScreenConfig End

    //
    // get shared channel
    //
    static QCString getShakeHandWithPhoneChannel(void);

    static QCString getLauncherChannel(void);

    //
    // get global shared directories
    //
    static QString getNativeDir(void);
    static QString getPreloadDir(void);

    static QString getInstalledQtDir(AM_Global::Device device = Flash2);
    static QString getInstCardDir(void);
    static QString getInstalledQtTmpDir(AM_Global::Device device = Flash2);
    static QString getInstalledThemeDir(void);

#if 0
    static QString getInstalledQtDir(int uid);
    static Device getDeviceByUid(int uid);
#endif

    static QString getAppWriteAmDir(void);

    /**
     * judge whether an application should be displayed on home
     *
     * @param app a application uid
     *
     * @return if the application should be displayed on home, return true
     * else return false
     */
#if 0
    static bool isVisibleApp(const Apps app);   //REFACTORY:Move to AM_AppsGlobal
#endif

    /// XXX static QString AM_Global::getExecNames( void );//REFACTORY:Move to AM_AppsGlobal

    //REFACTORY:Move to AM_MessageBox Begin
    //
    // international message box dialog
    //
    static void systemBusyMessageBox(void);
    static void memoryFullMessageBox(void);
    static void installFailedMessageBox(void);
    static void installCompleteMessageBox(void);
    static void uninstallFailedMessageBox(void);
    static void uninstallCompleteMessageBox(void);
    static void errorOkMessageBox(const QString & info);

#if 0
    static QString trOkString(void);    //REFACTORY:delete it
#endif
    static QString trWaitString(void);  //REFACTORY:delete it
    //REFACTORY:Move to AM_MessageBox End

    //
    // check flash memory full
    //
    static bool flashIsFull(void);      //REFACTORY: Move to AM_DeviceGlobal  //not exists in e6

    //
    // get a directory's size including sub-directories
    //
    static int getDirSize(const QString & dirName);
    static bool ensureMkDir(const QString & dirName);

    //
    // get EZX user's uid and pid
    //
    inline static unsigned int getEZXUid(void); //not exists in e6

    //
    // get "drm" user's UID, added by Gao Liangtao, 2004, 04/26
    //
    inline static unsigned int getDRMUid(void);//not exists in e6
    inline static unsigned int getEZXGid(void);//not exists in e6

    //REFACTORY: Move to AM_HomeScreenGlobal Begin
    static bool notifyUpdateHomeViews(void);
    static bool slideApp(Apps name, const QCString & message);
#if 0
    static void setFixedSize(void);
#endif
    //REFACTORY: Move to AM_HomeScreenGlobal End

    /**
     * judge whether a file is a valid wall paper
     *
     * @param fileName the file name want to judge
     *
     * @return if the file can be used for wall paper return true, else return false
     */
    //REFACTORY: Move to AM_DesktopGlobal
    static bool isWallPaperFile(const QString & fileName);

    //
    // fileName is the image file, it can be png file, bmp file, gif file, jpeg file.
    // if the file not exists, then do nothing. if it is not a image file, then maybe 
    // meet some problem
    //
    //REFACTORY: Move to AM_DesktopGlobal
    static bool setWallPaper(const QString & fileName);

    //
    // utility for sending wap-push-msg to messaging-center 
    // NOTE:    
    // * pBuf should be pointer to "struct WAP_PUSH_MSG_S"
    // * nSize should be sizeof( struct WAP_PUSH_MSG_S )
    //                  
    //REFACTORY: Move to AM_AppsGlobal Begin
    static bool sendWapPushMsgToMessagingCenter(char *pBuf, int nSize);

    //
    // for the wapProvisionEvent, pls refer to the header file "MSGCTR_ENG_WapProvisionDefs.h"
    // EZX__APP_EV_MSGG_PROV_ALERT_START,
    // EZX__APP_EV_MSGG_PROV_RESORT,
    //
    static bool sendWapProvisionEventToMessagingCenter(int wapProvisionEvent);

    //
    // utility for sending SMS 
    //
    static bool sendSms(const QString & qstrDestPhoneNumber = QString::null, 
                        const QString & qstrContent = QString::null);
    static bool sendSmsNoEditor(const QString & qstrDestPhoneNumber, const QString & qstrContent);
	static bool sendMmsAddrSubBody(QString  const&,QString  const&,QString  const&); //add for e6
    //
    // utility for sending MMS 
    // (1) toList: QString, its format is as follows:
    // contactName1:entryValue1,entryType1;contactName2:entryValue2,entryType2;
    // contactName:  is the name of attendee;
    // entryValue: phone number if entryType is phone, email address if entryType is email;
    // entryType: 0 stands for phone number, 1 stands for email address.
    // (2) fullFileName :QString, the temp file name including full path.
    // (3) autodeleteflag : indicates if the file represented by the parameter qstrFullFileName will be deleted by the function sendMms.
    // 
    // (4) appName : application
    //
    static bool sendMms(const QString & qstrToList, const QString & qstrFullFileName,
                        bool autodeleteflag, AM_Global::Apps appName);

    //
    // utility for openning MMS file
    // 
    static bool openMmsFile(const QString & qstrMmsFileName);

    //REFACTORY: Move to AM_AppsGlobal End

 
    // CMCC Feature
    static bool CMCCFlexBitEnable();
    static bool CMCCA780FlexBitEnable();
    static bool CMCC2FlexBitEnable();

    static unsigned int getBlockSize(const QString & fileName);
    static unsigned int getBlockSize(const char *filename);

private:
#if 0
    static void setDesktopBackground(const QImage & image);     //REFACTORY:: delete it
#endif

    //
    // show wall paper, only internal class AM_Desktop and AM_Launcher can use it
    //
    //static void showWallPaper( void );
};

inline int
AM_Global::getGnbHeight(void)
{
    return 45;
}

inline unsigned int
AM_Global::getEZXUid(void)
{
    return 2000;
}
inline unsigned int
AM_Global::getDRMUid(void)
{
    return 518;
}
inline unsigned int
AM_Global::getEZXGid(void)
{
    return 233;
}

inline int
AM_Global::getCstShortButtonWidth(void)
{
    return 43;
}

inline int
AM_Global::getCstLongButtonWidth(void)
{
    return 154;
}

inline int
AM_Global::getCstHeight(void)
{
    return 35;
}

inline const QSize
AM_Global::getSmallIconSize(void)
{
    return QSize(30, 25);
}

inline const QSize
AM_Global::getBigIconSize(void)
{
    return QSize(90, 30);
}

#endif // __AM_GLOBAL_H__
