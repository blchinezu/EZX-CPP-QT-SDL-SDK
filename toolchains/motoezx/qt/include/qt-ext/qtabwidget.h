#ifndef QTABWIDGET_H
#define QTABWIDGET_H
#include <qwidget.h>
#include <qiconset.h>

#include <qwidget.h>
class QWidgetStack;
class QTabWidgetData;
class QHButtonGroup;
class Q_EXPORT QTabWidget : public QWidget
{
	Q_OBJECT
public:
	QTabWidget( QWidget *parent, const char *name=0, WFlags f=0);
	QTabWidget( QWidget *parent=0, const char *name=0);
    ~QTabWidget();
    
    void addTab( QWidget *, const QString &);
    void insertTab( QWidget *, const QString &, int index = -1);
    void setTabEnabled( QWidget *, bool );
   // void showPage( QWidget * );
    void removePage( QWidget * );
   // QString tabLabel( QWidget * ); //### const in 3.0

   // QWidget * currentPage() const;
    // int currentPageIndex() const;
	void setCurrentPage( int );

    QSize sizeHint() const;
    QSize minimumSizeHint() const;
   // int margin() const;
   // void setMargin( int );

    //QSizePolicy sizePolicy() const;
    
    enum TabPosition { Top, Bottom };
    //TabPosition tabPosition() const;
   // void setTabPosition( TabPosition );

    enum TabShape { Rounded, Triangular };
    void setTabShape( TabShape s );
    
signals:
    void currentChanged( QWidget * );
    void selected( const QString& ); // obsolete

protected:
    void setTabBar( QHButtonGroup* );

private slots:
    void showTab( int i );
private:
    QTabWidgetData *d;
    void init();
};

#endif // QTABWIDGET_H  
