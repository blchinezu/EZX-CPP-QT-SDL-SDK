
/*
41afedb8 T AM_RegistryManager::createUuid()
41afd464 T AM_RegistryManager::changeOrder(QString const&, QList<QString> const&)
41af6058 T AM_RegistryManager::clearAppMap()
41b16e14 T AM_RegistryManager::appInstalled(AM_Global::Device, QString const&, QString const&, int)
41afe0bc T AM_RegistryManager::changeFolder(QString const&, QString const&, QString const&, int)
41aff114 T AM_RegistryManager::copyTextFile(QString const&, QString const&)
41afb384 T AM_RegistryManager::createFolder(QString const&, QString const&, QString const&, QString const&)
41af8330 T AM_RegistryManager::createObject(AM_RegistryManager::RegFileType, ZConfig&, ZConfig&)
41afcac8 T AM_RegistryManager::deleteFolder(QString const&)
41af6514 T AM_RegistryManager::initRegistry()
41afa684 T AM_RegistryManager::loadMenuTree()
41af8084 T AM_RegistryManager::loadRegistry()
41b16cdc T AM_RegistryManager::folderChanged(AM_Folder const*)
41b17174 T AM_RegistryManager::addAppToFolder(QString const&, QString const&, int)
41b17010 T AM_RegistryManager::appUnInstalled(QString const&, QString const&)
41afef34 T AM_RegistryManager::changeFileAttr(QString const&)
41b16860 T AM_RegistryManager::initMetaObject()
41b068c4 T AM_RegistryManager::addAppToAutoRun(QUuid const&)
41b06588 T AM_RegistryManager::addAppToAutoRun(QString const&)
41af67b8 T AM_RegistryManager::setAppLockValue(QUuid const&, int)
41b0081c T AM_RegistryManager::addAppToMainMenu(QString const&, QString const&, int)
41b01508 T AM_RegistryManager::addAppToRegistry(AM_RegistryManager::AM_AppRecord const&, QString&, QString const&, AM_Global::Device, int)
41afef80 T AM_RegistryManager::createConfigFile(AM_RegistryManager::RegFileType)
41b08a70 T AM_RegistryManager::handleCardPlugIn(AM_RegistryManager::RegFileType)
41b07194 T AM_RegistryManager::slotAppInstalled(AM_Global::Device, QString const&, QString const&, int)
41b16974 T AM_RegistryManager::staticMetaObject()
41af7210 T AM_RegistryManager::getConfigFileName(AM_RegistryManager::RegFileType)
41b0a52c T AM_RegistryManager::handleCardPlugOut()
41af7ef8 T AM_RegistryManager::initRegistryFiles()
41b087b4 T AM_RegistryManager::getSystemFolderUid(AM_RegistryManager::SystemFolder, QString&)
41b08348 T AM_RegistryManager::slotAddAppToFolder(QString const&, QString const&, int)
41b07e2c T AM_RegistryManager::slotAppUnInstalled(QString const&, QString const&)
41aff470 T AM_RegistryManager::slotChannelMessage(QCString const&, QArray<char> const&)
41b16df0 T AM_RegistryManager::appLockValueChanged()
41b083cc T AM_RegistryManager::getSystemFolderName(QString const&, QString&)
41b0b2fc T AM_RegistryManager::notifyAddAppToFolder(QString const&, QString const&, int)
41b06970 T AM_RegistryManager::removeAppFromAutoRun(QUuid const&)
41b06a1c T AM_RegistryManager::removeAppFromAutoRun(QString const&)
41b0b940 T AM_RegistryManager::checkAndUpdateCardApp(AM_AppObject&)
41b0885c T AM_RegistryManager::getAppParentFolderUid(QString const&, QString&)
41b05674 T AM_RegistryManager::removeAppFromMainMenu(QString const&, bool)
41b08928 T AM_RegistryManager::slotHotPlugForceUpdate(QCString const&, QArray<char> const&)
41aff8d8 T AM_RegistryManager::slotReloadAppLockValue()
41b0b408 T AM_RegistryManager::notifyRemoveAppFromFolder(QString const&, QString const&)
41afd844 T AM_RegistryManager::modifyApp(QString const&, QString const&, QString const&, QString const&)
41af5ab4 T AM_RegistryManager::AM_RegistryManager(QObject*, char const*)
41af5ab0 T AM_RegistryManager::AM_RegistryManager(QObject*, char const*)
41af5ab8 T AM_RegistryManager::AM_RegistryManager(QObject*, char const*)
41af5ddc T AM_RegistryManager::~AM_RegistryManager()
41af5dd4 T AM_RegistryManager::~AM_RegistryManager()
41af5dcc T AM_RegistryManager::~AM_RegistryManager()
41af5de4 T AM_RegistryManager::~AM_RegistryManager()
41af6da8 T AM_RegistryManager::getJavaObj(int const&) const
41b17320 W AM_RegistryManager::metaObject() const
41af6ecc T AM_RegistryManager::getAppObject(QString const&) const
41af6f6c T AM_RegistryManager::getAllAppList(QList<AM_AppObject>&) const
41af6ca0 T AM_RegistryManager::getAppObjById(QUuid const&) const
41af6e48 T AM_RegistryManager::getRootFolder() const
41afffd4 T AM_RegistryManager::getAutoRunApps(QList<AM_AppLnk>&) const
41af6698 T AM_RegistryManager::getAppLockValue(QUuid const&) const
41b00094 T AM_RegistryManager::getOpenWithApps(QString const&, QList<AM_RegistryManager::OpenWithApp>&) const
41b064b4 T AM_RegistryManager::getInstalledAppList(QList<AM_AppLnk>&, bool) const
41b0aab8 T AM_RegistryManager::getAppNameByFullPath(QString const&, QString&) const
41af6530 T AM_RegistryManager::getLockEnabledAppList(QList<AM_AppObject>&) const
41b0ae70 T AM_RegistryManager::getAppAutoStartStatusFromDmt(QString const&) const


libezxappbase.so.1
libdmnative.so.02
libezxphone.so.1
libezx-cmseccert.so
libezxdrmsp.so.1

*/



// Copyright (c) 25-Apr-07 - 2008 Motorola, Inc. All rights reserved.


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

#include "AM_Defs.h"

class AM_RegistryObject;
class AM_Folder;
class AM_AppObject;
class AM_AppLnk;

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

    AM_RegistryManager(QObject * parent = 0, const char * name = 0);

    ~AM_RegistryManager();
	
	static QUuid createUuid();
	
    const AM_Folder * getRootFolder() const;

    const AM_AppLnk * getAppLnk(const QUuid & appId) const;	

    AM_RESULT_CODE_T initRegistry();//????
	
	AM_RESULT_CODE_T addAppToAutoRun(QUuid const& appID);
	AM_RESULT_CODE_T addAppToAutoRun(QString const&);///appName??
	AM_RESULT_CODE_T removeAppFromAutoRun(QUuid const&appID);
	AM_RESULT_CODE_T removeAppFromAutoRun(QString const&);///
	
	void getAutoRunApps(QList<AM_AppLnk>& autoStartList) const;
	AM_RESULT_CODE_T getAppLockValue(QUuid const& appid) const;
	//getOpenWithApps(QString const&, QList<AM_RegistryManager::OpenWithApp>&) const
	//AM_RegistryManager::getInstalledAppList(QList<AM_AppLnk>&, bool) const
	AM_RESULT_CODE_T getAppNameByFullPath(QString const&, QString&) const;
	AM_RESULT_CODE_T getLockEnabledAppList(QList<AM_AppObject>&) const;
	AM_RESULT_CODE_T getAppAutoStartStatusFromDmt(QString const&) const;
		

signals:

    void signalFolderOrderUpdated(const QString &folderUid);
	
	void folderChanged(AM_Folder const*);
	
    void signalRegistryObjectUpdated(const QString &uid);

    void signalRegistryObjectMoved(const QString &uid, 
            const QString &srcFolderUid, const QString &destFolderUid);

    void signalAppObjectAdded(const QString &uid, const QString &folderUid);

    void signalAppObjectRemoved(const QString &uid, const QString &folderUid);

    void signalCardPlugged(const QStringList & folderUids);

    void signalCardUnplugged(const QStringList & folderUids);

private slots:
    void slotFolderOrderUpdated(const QString & folderUid);
    void slotRegistryObjectUpdated(const QString & uid);
    void slotRegistryObjectMoved(const QString &uid, 
            const QString &srcFolderUid, const QString &destFolderUid);
    void slotAppObjectAdded(const QString &uid, const QString &folderUid);
    void slotAppObjectRemoved(const QString &uid, const QString &folderUid);
    void slotCardPlugged(const QStringList & folderUids);
    void slotCardUnplugged(const QStringList & folderUids);

private:
    AM_AppDataInterface * m_impl;

};

#endif 
