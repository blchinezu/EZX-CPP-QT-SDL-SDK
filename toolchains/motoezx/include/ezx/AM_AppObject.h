//write by wangbin wbsecg1@gmail.com
/********************************************************
**libezxam.so.1.0.0
**2010年 07月 06日 星期二 18:11:58 CST

libraries depends:
	ezxaid,ezxam,dmnative,ezxphone,ezx-cmseccert,ezxdrmsp,ezxssl,ezxtapi,ezxflex,ezxdrmsecuretime,ezxdrmcipher
*************************************************************/

#ifndef AM_APPOBJECT_H
#define AM_APPOBJECT_H

#include <AM_Defs.h>

typedef QMap< QString, QString > AppRecord;
class AM_LauncherInterface;

class AM_AppObject
{
public:
	
	enum Type
    {
        InvalidType = 0,    
        Folder = 1,         
        Application = 2,    
        EmbeddedLink = 3,   
        Shortcut = 4        
    };
    
    enum IconType { Big, Small, Ani };
    
    
    AM_AppObject();
    AM_AppObject( AM_AppObject::Type t);
    virtual ~AM_AppObject();
    
    virtual AM_RESULT_CODE_T init(); //segfault
    
    virtual AM_RESULT_CODE_T createObject(QMap<QString, QString> const&);
    
    int getSize();
	QString setName(QString const&);
	QString getVender();
	QString getDefaultName();
	virtual AM_RESULT_CODE_T setAppLockValue(int);
	virtual AM_RESULT_CODE_T setAppLockEnabled(bool);
	virtual AM_RESULT_CODE_T dump();
	
	virtual AM_RESULT_CODE_T invoke(AM_LauncherInterface const&);
	
	virtual QString getBigIcon(QPixmap&);
	virtual QString getBigIcon() const;
	virtual QString getSmallIcon(QPixmap&) const;
	virtual int getAppLockValue() const;
	virtual QString getAnimationIcon(QPixmap&) const;
	virtual bool getAppLockEnabled() const;
	virtual QString getIcon(QPixmap&, AM_AppObject::IconType) const;
	virtual QString getName() const;
	virtual QString getPath() const;

private:
    AM_AppObject(const AM_AppObject & rhs);
    AM_AppObject & operator=(const AM_AppObject & rhs);

protected:
    bool mLockEnabled;
    Type mType;
    QString mBigIcon;
    QString mSmallIcon;
    QString mAniIcon;
    QString m_icon;
    QString mName, m_defaultName;
    QString m_vender;
    int m_lockValue;
    int m_size;
    QString m_appPath;

};
#endif
