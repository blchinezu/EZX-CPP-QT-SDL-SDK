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

    //����ĺ������óɹ�����-2, ���ܺ�(����)<0����-1.

    //����LCD����������,��Χ0-100
    int PM_setupBklightBrightness(int Brightness);

    //����LCD������˯��ʱ��,��λ: ��
    int PM_setupBklightSleepTime(int SleepTime);

    int PM_setupFlipStatus(int Status);

    int PM_setupIgnoreBpSignal(int BpSignal);

    //���ü��̵�˯��ʱ��,��λ: ��
    int PM_setupKeylightSleepTime(int SleepTime);

    //����LCD˯��ʱ��,��λ: ��
    int PM_setupLcdSleepTime(int SleepTime);

    int PM_setupPowerSavingMode(int Mode);
    int PM_setupUseroffSupport(int Support);
};


#endif
