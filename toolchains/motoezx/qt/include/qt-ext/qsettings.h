

#ifndef QSETTINGS_H
#define QSETTINGS_H

#include <ZConfig.h>
#include <qobject.h>
#include <qvariant.h>

class QSettings :public ZConfig,public QObject
{
public:
	enum Format { NativeFormat, IniFormat, InvalidFormat };
	enum Scope { UserScope, SystemScope };
	enum Status { NoError, AccessError, FormatError };
	
	QSettings( const QString & organization, const QString & application = QString(), QObject * parent = 0 );
	QSettings( Scope scope, const QString & organization, const QString & application = QString(), QObject * parent = 0 );
	QSettings( Format format, Scope scope, const QString & organization, const QString & application = QString(), QObject * parent = 0 );
	QSettings( const QString & fileName, Format format, QObject * parent = 0 );
	QSettings( QObject * parent = 0 );
	~QSettings() {};

	//QStringList allKeys () const
	QString applicationName ();// const;
	//void beginGroup ( const QString & prefix )
	//int beginReadArray ( const QString & prefix )
	//void beginWriteArray ( const QString & prefix, int size = -1 )
	//QStringList childGroups () const
	//QStringList childKeys () const
	//void clear ()
	//bool contains ( const QString & key ) const
	//void endArray ()
	//void endGroup ()
	//bool fallbacksEnabled () const
	QString fileName ();// const;
	//Format format () const
	//QString group () const
	//QTextCodec * iniCodec () const
	bool isWritable () ;//const;
	QString organizationName ();// const;
	//void remove ( const QString & key )
	//Scope scope () const
	//void setArrayIndex ( int i )
	//void setFallbacksEnabled ( bool b )
	//void setIniCodec ( QTextCodec * codec )
	//void setIniCodec ( const char * codecName )
	void setValue ( const QString & key, const QVariant & value );
	//Status status () const
	//void sync ()
	QVariant value ( const QString & key, const QVariant & defaultValue = QVariant() ) ;//const;


	//static Format defaultFormat ()
	//static Format registerFormat ( const QString & extension, ReadFunc readFunc, WriteFunc writeFunc, Qt::CaseSensitivity caseSensitivity = Qt::CaseSensitive )
	//static void setDefaultFormat ( Format format )
	//static void setPath ( Format format, Scope scope, const QString & path )
};

#endif // QSETTINGS_H

