/*
    ruthfox(foxe6) add
    2008.1.7
    
    EMail: ruthfox@163.com
*/    

#ifndef _EZXPM_H_
#define _EZXPM_H_

extern "C"
{
    //int PM_app_connect();
    //int PM_app_disconnect();
    //int PM_app_reqSend();
    //int PM_app_sendMsg();
    //int PM_app_sendMsg2();
    //int PM_app_touchOnBklight();

    //下面的函数调用成功返回-2, 功能号(内置)<0返回-1.

    //设置LCD背景灯亮度,范围0-100
    int PM_setupBklightBrightness(int Brightness);

    //设置LCD背景灯睡眠时间,单位: 分
    int PM_setupBklightSleepTime(int SleepTime);

    int PM_setupFlipStatus(int Status);

    int PM_setupIgnoreBpSignal(int BpSignal);

    //设置键盘灯睡眠时间,单位: 分
    int PM_setupKeylightSleepTime(int SleepTime);

    //设置LCD睡眠时间,单位: 分
    int PM_setupLcdSleepTime(int SleepTime);

    int PM_setupPowerSavingMode(int Mode);
    int PM_setupUseroffSupport(int Support);
};


#endif
