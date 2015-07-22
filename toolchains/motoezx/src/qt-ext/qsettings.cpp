#include "qsettings.h"


QSettings::QSettings( const QString & organization, const QString & application, QObject * parent)
	:ZConfig("settings.cfg",false),QObject(parent)
{
	//Q_UNUSED(parent);
	writeEntry("QSettings","Orgnization",organization);
	writeEntry("QSettings","Application",application);
	
}

QSettings::QSettings( Scope scope, const QString & organization, const QString & application, QObject * parent)
	:ZConfig("settings.cfg",false),QObject(parent)
{
	//Q_UNUSED(parent);
	Q_UNUSED(scope);
	writeEntry("QSettings","Orgnization",organization);
	writeEntry("QSettings","Application",application);
	
}

QSettings::QSettings( Format format, Scope scope, const QString & organization, const QString & application, QObject * parent)
	:ZConfig("settings.cfg",false),QObject(parent)
{
	//Q_UNUSED(parent);
	Q_UNUSED(format);
	Q_UNUSED(scope);
	writeEntry("QSettings","Orgnization",organization);
	writeEntry("QSettings","Application",application);
	
}
	
QSettings::QSettings( const QString & fileName, Format format, QObject * parent)
	:ZConfig(fileName,false),QObject(parent)
{
	//Q_UNUSED(parent);
	Q_UNUSED(format);
}

QString QSettings::applicationName()// const
{
	return readEntry("QSettings","Application");
}

QString QSettings::organizationName()// const
{
	return readEntry("QSettings","Orgnization");
}

QVariant QSettings::value( const QString & key, const QVariant & defaultValue )// const
{
	//QStringList list=split("/",key);
	int p=key.findRev("/",key.length());
	QString gname=key.left(p);
	QString k=key.right(key.length()-p-1);
	QString val=readEntry(gname,k,defaultValue.toString());
	return QVariant(val);
}

void QSettings::setValue ( const QString & key, const QVariant & value )
{
	int p=key.findRev("/",key.length());
	QString gname=key.left(p);
	QString k=key.right(key.length()-p-1);
	writeEntry(gname,k,value.toString());
}

	
