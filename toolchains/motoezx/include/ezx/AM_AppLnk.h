//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxaid,ezxam,dmnative,ezxphone,ezx-cmseccert,ezxdrmsp,ezxssl,ezxtapi,ezxflex,ezxdrmsecuretime,ezxdrmcipher
*************************************************************/
#ifndef AM_APPLNK_H
#define AM_APPLNK_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <AM_AppObject.h>
//class AM_LauncherInterface;

class AM_AppLnk : public AM_AppObject
{

public:
    AM_AppLnk();
    virtual ~AM_AppLnk();

private:
    AM_AppLnk(const AM_AppLnk & rhs);
    AM_AppLnk & operator=(const AM_AppLnk &rhs);

public:
    virtual QString getExecFullPath() const;

	virtual int getAppLockValue() const;
	virtual bool getAppLockEnabled() const;
	virtual AM_RESULT_CODE_T setAppLockValue(int);
	virtual AM_RESULT_CODE_T setAppLockEnabled(bool);
	
	virtual AM_RESULT_CODE_T createObject(QMap<QString, QString> const&);
	QString getGidByString(QString const&);
	QString getUidByString(QString const&);
	
	virtual AM_RESULT_CODE_T dump();
	virtual AM_RESULT_CODE_T invoke(AM_LauncherInterface const&);
	
private:

};

#endif

