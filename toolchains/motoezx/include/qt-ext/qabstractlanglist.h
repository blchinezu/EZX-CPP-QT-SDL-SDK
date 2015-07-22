#ifndef QABSTRACTLANGLIST_H
#define QABSTRACTLANGLIST_H

//gcc版本对宏的定义有影响
#if (__GNUC__ < 4)
#   if QT_VERSION >= 0x040000
#   define QAbstractLangList_QT4
#   define NO_EZX
#   endif
#else
#   define QAbstractLangList_QT4 (QT_VERSION >= 0x040000)
#   define NO_EZX (QT_VERSION >= 0x040000)
#endif

#ifdef QAbstractLangList_QT4
#include "QLangWidget_global.h"
#include <QLocale>
#include <QStringList>
#include <QIcon>
#else
#	define QLANGWIDGETSHARED_EXPORT Q_EXPORT
#include <qstringlist.h>
#include <qpixmap.h>

#	define QIcon QPixmap
#endif //QAbstractLangList_QT4

#ifndef ZDEBUG
#define ZDEBUG qDebug("file: %s, function: %s, line: %d",__FILE__,__FUNCTION__,__LINE__);
#endif //ZDEBUG


class QWidget;
class QTranslator;

struct QAbstractLangListPrivate;

//inherits QList
class QLANGWIDGETSHARED_EXPORT QAbstractLangList
{
public:
    //first parameter langId should be improved. change to const QString langCode
    QAbstractLangList(const QString& langCode=QString(),const QString& qmfilter="*",const QString &qmd="i18n",const QString &conf="i18n.cfg");
    virtual ~QAbstractLangList() =0;

    void setQmFilter(const QString& qf);
    void setConfigFile(const QString& file);
    void setQmDir(const QString& dir);
    void setThisQmDir(const QString& dir); //dir of qabstractlanglist-lc_cc.qm
    int langIndex(const QString& langCode);
    QString langCode(int);
    void changeSysText();
    void setCurrentLangCode(const QString&);
#ifdef QAbstractLangList_QT4
    void setCurrentLang(QLocale::Language lang);
#endif //QAbstractLangList_QT4
    void updateLangList();
    int langCount();
    QIcon flag(const QString& langCode);

    virtual void clear();
    virtual void insertItem(int ,const QString&,const QIcon& ) {ZDEBUG};
    virtual void setItemText(int ,const QString& ) {ZDEBUG};
    virtual void setCurrentIndex(int ) {ZDEBUG};
    //virtual findQms();
    virtual bool changeLangIndex(int);

private:
    QAbstractLangListPrivate* d;

};


extern QString find_syslang(const QString& );
extern QString find_lang(const QString&);

#endif // QABSTRACTLANGLIST_H
