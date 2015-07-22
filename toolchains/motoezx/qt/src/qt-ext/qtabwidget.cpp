#include "qtabwidget.h"
#include <qwidgetstack.h>
#include <ZPushButton.h>
#include <qhbuttongroup.h>
#include <qlayout.h>

#define ZDEBUG qDebug("file: %s, function: %s, line: %d",__FILE__,__FUNCTION__,__LINE__);
class QTabWidgetData
{
public:
    QTabWidgetData()
	: tabs(0), stack(0), dirty( TRUE ), pos( QTabWidget::Top ), shape( QTabWidget::Rounded )
	{};
    ~QTabWidgetData(){};
    QHButtonGroup *tabs;
    QWidgetStack* stack;
    bool dirty;
    QTabWidget::TabPosition pos;
    QTabWidget::TabShape shape;
};


QTabWidget::QTabWidget( QWidget *parent, const char *name, WFlags f )
    : QWidget( parent, name, f )
{
    init();
}

QTabWidget::QTabWidget( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
    init();
}

QTabWidget::~QTabWidget()
{
    delete d;
}


void QTabWidget::init()
{
	QVBoxLayout *vb=new QVBoxLayout(this);
    vb->setAutoAdd(true);
    d = new QTabWidgetData;
    d->tabs=new QHButtonGroup( this, "tab control" );
    setTabBar( d->tabs ); 

    d->stack = new QWidgetStack( this, "tab pages" );
    d->stack->installEventFilter( this );

    //d->stack->setFrameStyle( QFrame::StyledPanel | QFrame::Raised );
    d->stack->setFrameStyle( QFrame::StyledPanel );
    //d->stack->setLineWidth( style().defaultFrameWidth() );
    d->stack->setLineWidth( 1 );

    setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding ) );
    setFocusPolicy( TabFocus );
    //setFocusProxy( d->tabs );
}

void QTabWidget::setTabBar( QHButtonGroup* tb)
{
	ZDEBUG
    if ( tb->parentWidget() != this )
	tb->reparent( this, QPoint(0,0), TRUE );
    delete d->tabs;
    d->tabs = tb;ZDEBUG
    connect( d->tabs, SIGNAL(clicked(int)), SLOT(showTab(int)) );
    //setUpLayout();
}

void QTabWidget::addTab( QWidget *child, const QString &label)
{
    int id = d->tabs->insert(new ZPushButton("",label,d->tabs));//tabcount++;//s->addTab( tab );
    d->stack->addWidget( child, id );
    if ( d->stack->frameStyle() != ( QFrame::StyledPanel ) )
	d->stack->setFrameStyle( QFrame::StyledPanel );
    d->stack->raiseWidget(child);//
}

void QTabWidget::insertTab( QWidget *child, const QString &label, int index)
{
    int id = d->tabs->insert(new ZPushButton("",label,d->tabs),index);//d->tabs->insertTab( tab, index );
    d->stack->addWidget( child, id );
    /*if ( d->stack->frameStyle() != ( QFrame::StyledPanel | QFrame::Raised ) )
	d->stack->setFrameStyle( QFrame::StyledPanel | QFrame::Raised );*/
    if ( d->stack->frameStyle() != ( QFrame::StyledPanel ) )
	d->stack->setFrameStyle( QFrame::StyledPanel );
    //setUpLayout();
    d->stack->raiseWidget(child);//
}

void QTabWidget::showTab( int i )
{
    if ( d->stack->widget( i ) ) {
	d->stack->raiseWidget( i );
	//emit selected( d->tabs->tab( i )->label );
	emit currentChanged( d->stack->widget( i ) );
    }
}

void QTabWidget::removePage( QWidget * w )
{
    int id = d->stack->id( w );
    if ( id >= 0 ) {
	//d->tabs->setTabEnabled( id, FALSE );
	d->stack->removeWidget( w );
	d->tabs->remove( d->tabs->find(id) );
	//setUpLayout();
	
	if ( d->tabs->count() == 0 ) 
	    d->stack->setFrameStyle( QFrame::NoFrame );
    }
}

void QTabWidget::setTabEnabled( QWidget* w, bool enable)
{
    int id = d->stack->id( w );
    if ( id >= 0 ) {
	w->setEnabled( enable );
	d->tabs->find(id)->setEnabled( enable );
    }
}

void QTabWidget::setCurrentPage( int id )
{
    //d->tabs->setCurrentTab( id );
    showTab( id );
}

void QTabWidget::setTabShape( TabShape s )
{
    /*if ( d->shape == s )
	return;
    d->shape = s;
    if ( d->pos == Top ) {
	if ( s == Rounded )
	    d->tabs->setShape( QTabBar::RoundedAbove );
	else
	    d->tabs->setShape( QTabBar::TriangularAbove );
    } else {
	if ( s == Rounded )
	    d->tabs->setShape( QTabBar::RoundedBelow );
	else
	    d->tabs->setShape( QTabBar::TriangularBelow );
    }
    d->tabs->layoutTabs();
   setUpLayout();*/ 
}

QSize QTabWidget::sizeHint() const
{
    QSize s( d->stack->sizeHint() );
    QSize t( d->tabs->sizeHint() );
    return QSize( QMAX( s.width(), t.width()),
		  s.height() + t.height() );
}

QSize QTabWidget::minimumSizeHint() const
{
    QSize s( d->stack->minimumSizeHint() );
    QSize t( d->tabs->minimumSizeHint() );
    return QSize( QMAX( s.width(), t.width()),
		  s.height() + t.height() );
}

