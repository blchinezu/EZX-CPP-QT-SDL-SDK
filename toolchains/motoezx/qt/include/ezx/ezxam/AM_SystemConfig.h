//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_SYSTEMCONFIG_H
#define AM_SYSTEMCONFIG_H

class AM_SystemConfig
{
public:
	AM_SystemConfig();
	~AM_SystemConfig();
	
	QString DRMUid();
	QString ezxGid();
	QString ezxUid();
	
private:
	QString m_drmuid, m_ezxuid, m_ezxgid;		
};

#endif //AM_SYSTEMCONFIG_H

