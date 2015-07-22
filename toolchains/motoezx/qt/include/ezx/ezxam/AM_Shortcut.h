//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_SHORTCUT_H
#define AM_SHORTCUT_H
#include <AM_AppObject.h>

class AM_Shortcut : public AM_AppObject
{
public:
	AM_Shortcut();
	virtual ~AM_Shortcut();

	virtual AM_RESULT_CODE_T createObject(QMap<QString, QString> const&);
	virtual AM_RESULT_CODE_T setAppLockValue(int);
	virtual AM_RESULT_CODE_T invoke(AM_LauncherInterface const&);
	
	virtual int getAppLockValue() const;
	
};

#endif //AM_SHORTCUT_H

