/*
    ruthfox(foxe6) add
    2008.1.5
    
    EMail: ruthfox@163.com
*/

#ifndef _AMGLOBAL_H_
#define _AMGLOBAL_H_

class AM_Global// : public QObject() �ǲ��ǻ�δ֪
{
public:
    enum Apps{Apps_0, Apps_1, Apps_2, Apps_3, Apps_4, Apps_5, Apps_6, 
              Apps_7, Apps_8, Apps_9, Apps_A, Apps_B, Apps_C, Apps_D, 
              Apps_E, Apps_F, Apps_10, Apps_11, Apps_12, Apps_13, Apps_14, 
              Apps_15, Apps_16, Apps_17, Apps_18, Apps_19, Apps_1A, Apps_1B, 
              Apps_1C, Apps_1D, Apps_1E, Apps_1F, Apps_20, Apps_21, Apps_22, 
              Apps_23, Apps_24, Apps_25, Apps_26, Apps_27, Apps_28, Apps_29, 
              Apps_2A, Apps_2B, Apps_2C, Apps_2D, Apps_2E, Apps_2F, Apps_30, 
              Apps_31, Apps_32, Apps_33, Apps_34, Apps_35, Apps_36, Apps_37, 
              Apps_38, Apps_39, Apps_3A, Apps_3B, Apps_3C, Apps_3D, Apps_3E, 
              Apps_3F, Apps_40, Apps_41, Apps_42, Apps_43, Apps_44, Apps_45, 
              Apps_46, Apps_47, Apps_48, Apps_49, Apps_4A, Apps_4B, Apps_4C, 
              AppsAlarmClock, Apps_4E, Apps_4F, Apps_50, Apps_51, Apps_52, 
              Apps_53, Apps_54, Apps_55, Apps_56, Apps_57, Apps_58, Apps_59, 
              Apps_5A, Apps_5B, Apps_5C, Apps_5D, Apps_5E, Apps_5F, Apps_60, 
              Apps_61, Apps_62, Apps_63, Apps_64};
              
    enum Device{d0};

    static int getDirSize(const QString& File);
    static bool ensureMkDir(const QString& File);
    static int flashIsFull(void);
    static int openMmsFile(const QString&);
    static int getBlockSize(const char*);
    static int getBlockSize(const QString&);
    static int getGnbLength(void);
    static QString getNativeDir(void); //�ӻ��������л�ȡ"EZX_NATIVE_APP_PATH"��ֵ='/usr/SYSqtapp'
    static bool setWallPaper(const QString& FileName);
    /*static*/ int trWaitString(void);
    static QString getPreloadDir(void); //EZX_PRELOAD_APP_PATH='/usr/data_resource/preloadapps'
    static QString getInstCardDir(void); //JAVA_HOME_CARD1='/mmc/mmca1/.system/java'
    static int getScreenWidth(void);    //����240
    static int getScreenLength(void);   //����320
    static bool isWallPaperFile(const QString& FileName);

    //���Ͷ��Ź���,����ʾ�����ŵ������,����ʾ���ͳɹ��ĶԻ���;
    //��������_ZN20AM_LauncherInterface17sendBridgeMessageERK5QUuidRK6QArrayIcEb�����Ͷ���
    static bool sendSmsNoEditor(const QString& PhoneNumber, const QString& Content);

    static QString getAppWriteAmDir(void); //EZX_APP_WRITE_PATH='/ezx_user/download/appwrite/'
    static bool CMCCFlexBitEnable(void); //ֱ�ӷ���false
    static void errorOkMessageBox(const QString& Prompt); //��ʾһ��������Ϣ�Ի���,��һ��OK��ť��һ�����ͼ��
    /*static*/ QString getInstalledQtDir(AM_Global::Device);
    static bool CMCC2FlexBitEnable(void);
    static int getLauncherChannel(void);

    //��ʾ�����ŵĶԻ���,��ַ,����,�����Ѿ���д,�û������޸�.
    //��������_ZN20AM_LauncherInterface17sendBridgeMessageERK5QUuidRK6QArrayIcEb�����Ͷ���
    static bool sendMmsAddrSubBody(const QString& PhoneNumber, const QString& Subject, const QString& Body);

    static int getInstalledQtTmpDir(AM_Global::Device);
    static QString getInstalledThemeDir(void); //EZX_INSTALLED_THEME_PATH='/ezxlocal/.system/theme/'

    //��ʾһ���ֻ��ڴ�����,��ɾ��һЩ�ļ�...����Ϣ��
    static void memoryFullMessageBox(void);

    //��ʾһ��ϵͳæ����Ϣ��
    static void systemBusyMessageBox(void);

    static bool CMCCA780FlexBitEnable(void);
    static bool notifyUpdateHomeViews(void);

    //��ʾ��װʧ�ܶԻ���
    static void installFailedMessageBox(void);

    //��ʾ��װ�ɹ��Ի���
    static void installCompleteMessageBox(void);

    //��ʾж��ʧ�ܶԻ���
    static void uninstallFailedMessageBox(void);

    //��ʾж�سɹ��Ի���
    static void uninstallCompleteMessageBox(void);

    static QString getShakeHandWithPhoneChannel(void); //����"/AM/Phone/ShakeHand/Channel"

    static int sendWapPushMsgToMessagingCenter(char*, int);
    static int sendWapProvisionEventToMessagingCenter(int);

    //��ʾ�����ŵĶԻ���,��ַ,�����Ѿ���д,�û������޸�.
    //��������_ZN20AM_LauncherInterface17sendBridgeMessageERK5QUuidRK6QArrayIcEb�����Ͷ���
    static bool sendMms(const QString&, const QString&, bool, AM_Global::Apps);
    static bool sendMms(const QString&, const QString&, bool, AM_Global::Apps, const QString&);

    //��ʾ�����ŵĶԻ���,��ַ,�����Ѿ���д,�û������޸�.
    //��������_ZN20AM_LauncherInterface17sendBridgeMessageERK5QUuidRK6QArrayIcEb�����Ͷ���
    static bool sendSms(const QString&, const QString&);

    static bool slideApp(AM_Global::Apps, const QCString&);  //ֱ�ӷ���false
};

#endif

