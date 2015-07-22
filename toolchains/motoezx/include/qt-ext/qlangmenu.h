#ifndef QLANGMENU_H
#define QLANGMENU_H


#include "qabstractlanglist.h"

#ifdef QAbstractLangList_QT4
#define QLangMenu_QT4
#endif

class QAction;

#ifdef QLangMenu_QT4
#include <QMenu>
//#define Q_MENU QMenu
class QActionGroup;
#else
#include <qpopupmenu.h>
#define QMenu QPopupMenu
#endif //QLangMenu_QT4

class QLangMenu :public QMenu,public QAbstractLangList
{
    Q_OBJECT;
public:
    QLangMenu(QWidget* parent=0,const QString& langCode=QString(),const QString& qmfilter="*", const QString &qmd="i18n",const QString &conf="i18n.cfg");
    virtual ~QLangMenu() {ZDEBUG};

    void clear();
    void insertItem(int index,const QString& name,const QIcon& f=QIcon());
    void setItemText(int index,const QString& name);
    void setCurrentIndex(int index);

signals:
    void langChanged(); //use changEvent in Qt4

public slots:
	void setLangId(int);
#ifdef QLangMenu_QT4
    //void switchLanguage(QAction *);  //qt-2.3.8 error
#endif //QLangMenu_QT    
    

private:
#ifdef QLangMenu_QT4
    QActionGroup *languageActionGroup;
#else
#endif //QLangMenu_QT4

};

#endif // QLANGMENU_H
