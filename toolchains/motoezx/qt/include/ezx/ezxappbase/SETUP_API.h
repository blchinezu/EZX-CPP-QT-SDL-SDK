/*
    ruthfox(foxe6) add
    2008.1.5
    
    EMail: ruthfox@163.com
*/

#ifndef _SETUP_API_H_
#define _SETUP_API_H_

enum SDK_SOUND_ALERT_TYPE_E{ssat0, ssat1, ssat2, ssat3, ssat4, ssat5};
enum SDK_USB_STATUS_E{sus0};//?

enum SDK_ALERT_STYLE_E{sasLoudness, sasVibrancyAndLoudness, sasVibrancyThenLoudness,
    sasBleat, sasVibrancyThenBleat, sasSlient, sasVibrancy};
    
enum SDK_USB_STATUS_E { s1, s2, s3, s4, s5 };

class SETUP_API   //类封装了SETUP_Utility的几个函数
{
public:
    void getLanguage(QString& Language);
    void getAPVersion(QString& Version);
    void getSoundFile(SDK_SOUND_ALERT_TYPE_E type, QString& FileName);
    void getUSBStatus(SDK_USB_STATUS_E& Status);
    void getWallpaper(QString& FileName);
    bool setUSBStatus(SDK_USB_STATUS_E Status);
    bool setWallpaper(QString FileName);

    //获取提示类型,如振动后响铃等.
    void getAlertStyle(SDK_ALERT_STYLE_E& Style);
    bool setAlertStyle(SDK_ALERT_STYLE_E Style);

    //获取/设置音量
    void getSoundVolume(int& Volume);
    bool setSoundVolume(int Volume);
};

#endif
