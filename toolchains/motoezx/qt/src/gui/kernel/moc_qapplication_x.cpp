/****************************************************************************
** QApplication_X meta object code from reading C++ file 'qapplication_x.h'
**
** Created: Fri Aug 27 21:49:45 2010
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.6   edited 2002-11-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "qapplication_x.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QApplication_X::className() const
{
    return "QApplication_X";
}

QMetaObject *QApplication_X::metaObj = 0;

#ifdef QWS
static class QApplication_X_metaObj_Unloader {
public:
    ~QApplication_X_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QApplication_X" );
    }
} QApplication_X_metaObj_unloader;
#endif

void QApplication_X::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(ZApplication::className(), "ZApplication") != 0 )
	badSuperclassWarning("QApplication_X","ZApplication");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QApplication_X::tr(const char* s)
{
    return qApp->translate( "QApplication_X", s, 0 );
}

QString QApplication_X::tr(const char* s, const char * c)
{
    return qApp->translate( "QApplication_X", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QApplication_X::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) ZApplication::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QApplication_X", "ZApplication",
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
