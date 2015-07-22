//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxam,dmnative,ezx-cmseccert,ezxdrmsp,ezxphone
*************************************************************/
#ifndef AM_APPDATAINTERFACE_H
#define AM_APPDATAINTERFACE_H
#include <AM_RegistryManager.h>

class AM_AppLnk;
class AM_AppObject;
class AM_RegistryManager;


class AM_AppDataInterface :public QObject
{
	Q_OBJECT
public:
	AM_AppDataInterface(AM_RegistryManager*, QObject*, char const*);
	virtual ~AM_AppDataInterface();
	
	AM_RESULT_CODE_T changeOrder(QString const&, QList<QString> const&);
	AM_RESULT_CODE_T changeFolder(QString const&, QString const&, QString const&, int);
	AM_RESULT_CODE_T createFolder(QString const&, QString const&, QString const&, QString const&);
	AM_RESULT_CODE_T deleteFolder(QString const&);
	AM_AppObject* getAppObject(QString const&);
	
	voAM_RESULT_CODE_T id getAllAppList(QList<AM_AppObject>&);
	AM_Folder* getRootFolder();
	AM_RegistryManager* getRegistryManager();
	AM_AppLnk* getAppLnkBySerialId(QString const& appid);
	AM_RESULT_CODE_T  modifyApp(QString const&, QString const&, QString const&, QString const&);
	
	AM_AppObject*getJavaObj(int const&);
	AM_AppLnk* getAppLnkById(QUuid const&);
	AM_AppObject*getAppObjById(QUuid const&);
	AM_RESULT_CODE_T  getAutoRunApps(QList<AM_AppLnk>&);
	
signals:
	void folderChanged(AM_Folder const*);
	
private:
				
};

#endif //AM_APPDATAINTERFACE_H

