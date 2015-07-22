#ifndef QLANGCOMBO_H
#define QLANGCOMBO_H


#include "qabstractlanglist.h"

#ifdef QAbstractLangList_QT4
#define QLangCombo_QT4
#endif

#ifdef QLangCombo_QT4
#include <QComboBox>
#else
#include <qcombobox.h>
#include <qlistbox.h>
#endif //QLangCombo_QT4

class QLangCombo :public QComboBox, public QAbstractLangList
{
    Q_OBJECT;
public:
    QLangCombo(QWidget* parent=0,const QString& langCode=QString(),const QString& qmfilter="*", const QString &qmd="i18n",const QString &conf="i18n.cfg");
    virtual ~QLangCombo() {ZDEBUG};

    void clear();
    void insertItem(int index,const QString& name,const QIcon& f=QIcon());
    void setItemText(int index,const QString& name);
    void setCurrentIndex(int index);

signals:
    void langChanged(); //use changEvent in Qt4

public slots:
    void setLangIndex(int);


};

#endif // QLANGCOMBO_H
