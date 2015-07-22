//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxaid,ezxam,dmnative,ezxphone,ezx-cmseccert,ezxdrmsp,ezxssl,ezxtapi,ezxflex,ezxdrmsecuretime,ezxdrmcipher
*************************************************************/
/*

libezxappbase.so.1
libdmnative.so.02
libezxphone.so.1
libezx-cmseccert.so
libezxdrmsp.so.1

*/

#ifndef AM_REGISTRYMANAGER_H
#define AM_REGISTRYMANAGER_H

#ifndef __cplusplus
#error "This is C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <qvaluelist.h>
#include <qstring.h>
#include <qstringlist.h>
#include <quuid.h>
#include <qlist.h>
#include <AM_Global.h>

#include "AM_Defs.h"

class AM_RegistryObject;
class AM_Folder;
class AM_AppObject;
class AM_AppLnk;
class ZConfig;

class AM_AppDataInterface;


class AM_RegistryManager : public QObject
{
    Q_OBJECT

public:

    struct LockableAppObject
    {
        const AM_AppObject * appObject;
        int lockValue;
    };
    
    
    enum RegFileType {Type1,Type2,Types,Type4,Type5};

	enum AM_AppRecord {};
	enum SystemFolder {sys1,sys2,sys3,sys4};
	enum OpenWithApp {app1,app2,app3,app4};
	
    AM_RegistryManager(QObject * parent = 0, const char * name = 0);

    ~AM_RegistryManager();
    
    AM_RESULT_CODE_T clearAppMap();
    AM_RESULT_CODE_T changeOrder(QString const&, QList<QString> const&);
	
	static QUuid createUuid();
	
    const AM_Folder * getRootFolder() const;

    const AM_AppLnk * getAppLnk(const QUuid & appId) const;	
    
	AM_RESULT_CODE_T createFolder(QString const&, QString const&, QString const&, QString const&);
	AM_RESULT_CODE_T deleteFolder(QString const&);
	AM_RESULT_CODE_T changeFolder(QString const&, QString const&, QString const&, int);

	AM_RESULT_CODE_T initRegistry();//????
	AM_RESULT_CODE_T initRegistryFiles();
    
	AM_RESULT_CODE_T loadRegistry();
    AM_RESULT_CODE_T loadMenuTree();
    
    AM_RESULT_CODE_T createObject(AM_RegistryManager::RegFileType, ZConfig&, ZConfig&);
    
    AM_RESULT_CODE_T changeFileAttr(QString const&);
	AM_RESULT_CODE_T copyTextFile(QString const&, QString const&);
    
    AM_RESULT_CODE_T addAppToRegistry(AM_RegistryManager::AM_AppRecord const&, QString&, QString const&, AM_Global::Device, int);
    
    QString getConfigFileName(AM_RegistryManager::RegFileType);
    AM_RESULT_CODE_T createConfigFile(AM_RegistryManager::RegFileType);
    
    AM_RESULT_CODE_T getSystemFolderName(QString const&, QString&);
    AM_RESULT_CODE_T getSystemFolderUidAM_AppRecord(AM_RegistryManager::SystemFolder, QString&);
	
	AM_RESULT_CODE_T getAutoRunApps(QList<AM_AppLnk>&) const;
	AM_RESULT_CODE_T addAppToAutoRun(QUuid const& appID);
	AM_RESULT_CODE_T addAppToAutoRun(QString const&);///appName??
	AM_RESULT_CODE_T removeAppFromAutoRun(QUuid const&appID);
	AM_RESULT_CODE_T removeAppFromAutoRun(QString const&);///
	AM_RESULT_CODE_T addAppToMainMenu(QString const&, QString const&, int);
	AM_RESULT_CODE_T removeAppFromMainMenu(QString const&, bool);

	
	AM_RESULT_CODE_T getAppParentFolderUid(QString const&, QString&);
	AM_RESULT_CODE_T checkAndUpdateCardApp(AM_AppObject&);
	
	virtual int getAppLockValue(QUuid const& appid) const;
	AM_RESULT_CODE_T getAppNameByFullPath(QString const&, QString&) const;
	AM_RESULT_CODE_T getAppAutoStartStatusFromDmt(QString const&) const;
	
	void handleCardPlugIn(AM_RegistryManager::RegFileType);
	void handleCardPlugOut();
	
	AM_RESULT_CODE_T notifyRemoveAppFromFolder(QString const& app, QString const& folder); //?
	AM_RESULT_CODE_T notifyAddAppToFolder(QString const&, QString const&, int);
	AM_RESULT_CODE_T modifyApp(QString const&, QString const&, QString const&, QString const&);
	
	AM_AppObject* getJavaObj(int const&) const;
	AM_AppObject* getAppObject(QString const&) const;
	AM_RESULT_CODE_T getAllAppList(QList<AM_AppObject>&) const;
	AM_AppObject* getAppObjById(QUuid const&) const;
	
	AM_RESULT_CODE_T getOpenWithApps(QString const& app, QList<AM_RegistryManager::OpenWithApp>&) const;
	AM_RESULT_CODE_T getInstalledAppList(QList<AM_AppLnk>&, bool) const;
	
	AM_RESULT_CODE_T setAppLockValue(QUuid const&, int);
	AM_RESULT_CODE_T getLockEnabledAppList(QList<AM_AppObject>&) const;
		

signals:
	void addAppToFolder(QString const&, QString const&, int);	
	void folderChanged(AM_Folder const*);
	void appLockValueChanged();
	void appInstalled(AM_Global::Device, QString const&, QString const&, int);

private slots:
	void slotAddAppToFolder(QString const&, QString const&, int);
	void slotAppInstalled(AM_Global::Device, QString const&, QString const&, int);
	void slotAppUnInstalled(QString const&, QString const&);
	virtual void slotChannelMessage(QCString const&, QArray<char> const&);
	void slotHotPlugForceUpdate(QCString const&, QArray<char> const&);
	virtual void slotReloadAppLockValue();

private:
    AM_AppDataInterface * m_impl;

};

#endif 
