//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxaid,ezxam,dmnative,ezxphone,ezx-cmseccert,ezxdrmsp,ezxssl,ezxtapi,ezxflex,ezxdrmsecuretime,ezxdrmcipher
*************************************************************/
#ifndef AM_APPLOCKMANAGER_H
#define AM_APPLOCKMANAGER_H

#include <AM_RegistryManager.h>

class AM_AppLockManager :public AM_RegistryManager
{
	Q_OBJECT
public:
	AM_AppLockManager(QObject* parent=0, char const* name=0);
	~AM_AppLockManager();
	
	AM_RESULT_CODE_T getAppName(QUuid const&, QString&);
	AM_RESULT_CODE_T lookUpAppName(QString const&, QUuid const&, QString&);
	
	virtual int getAppLockValue(QUuid const&);

	AM_AppLockManager* instance();
	
signals:
	void appNameChanged(QString const&);
	void appLockValueChanged();
	
public slots:
	void slotReloadAppName(QString const&);
	void slotChannelMessage(QCString const&, QArray<char> const&);
	void slotReloadAppLockValue();
	
private:
		
	
};

#endif //AM_APPLOCKMANAGER_H

