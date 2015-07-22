#include "QProgressIndicator.h"

#include <qpainter.h>

QProgressIndicator::QProgressIndicator(QWidget* parent)
        : QWidget(parent),
        m_angle(0),
        m_timerId(-1),
        m_delay(40),
        m_displayedWhenStopped(false)
       // m_color(Qt::black)
{
	m_fadecols=0;
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    //setFocusPolicy(Qt::NoFocus);
    setBackgroundMode(NoBackground);
    setColor(Qt::black,Qt::white);
}

bool QProgressIndicator::isAnimated () const
{
    return (m_timerId != -1);
}

void QProgressIndicator::setDisplayedWhenStopped(bool state)
{
    m_displayedWhenStopped = state;

    update();
}

bool QProgressIndicator::isDisplayedWhenStopped() const
{
    return m_displayedWhenStopped;
}

void QProgressIndicator::startAnimation()
{
    m_angle = 0;

    if (m_timerId == -1)
        m_timerId = startTimer(m_delay);
}

void QProgressIndicator::stopAnimation()
{
    if (m_timerId != -1)
        killTimer(m_timerId);

    m_timerId = -1;

    update();
}

void QProgressIndicator::setAnimationDelay(int delay)
{
    if (m_timerId != -1)
        killTimer(m_timerId);

    m_delay = delay;

    if (m_timerId != -1)
        m_timerId = startTimer(m_delay);
}

void QProgressIndicator::setColor(const QColor & color1, const QColor & color2)
{
    m_color1 = color1;
    m_color2 = color2;
    
    delete [] m_fadecols;
	//m_fade = s;
	m_fadecols = new QColor [12];//m_fade];

	int rt=m_color1.red(), gt=m_color1.green(), bt=m_color1.blue();
	int rf=m_color2.red(), gf=m_color2.green(), bf=m_color2.blue();

	/*int rt, gt, bt;
	int rf, gf, bf;
	
	colorGroup ( ). color ( QColorGroup::Highlight ). rgb ( &rf, &gf, &bf );
	colorGroup ( ). color ( QColorGroup::Background ). rgb ( &rt, &gt, &bt );*/
	
	for ( int i = 0; i < 12; i++ ) 
		m_fadecols [i]. setRgb ( rf + ( rt - rf ) * i / 12, gf + ( gt - gf ) * i / 12, bf + ( bt - bf ) * i / 12 );

    update();
}

QSize QProgressIndicator::sizeHint() const
{
    return QSize(120,120);
}

int QProgressIndicator::heightForWidth(int w) const
{
    return w;
}

void QProgressIndicator::timerEvent(QTimerEvent * /*event*/)
{
    m_angle = (m_angle+30)%360;

    update();
}

void QProgressIndicator::paintEvent(QPaintEvent * /*event*/)
{
    if (!m_displayedWhenStopped && !isAnimated())
        return;

    int width = qMin(this->width(), this->height());
    
    QPainter p(this);
   // p.setRenderHint(QPainter::Antialiasing);
    
    int outerRadius = (width-1)/2;
    int innerRadius = (width-1)*0.5*0.38;

    int capsuleHeight = outerRadius - innerRadius;
   
    int capsuleWidth  = (width > 32 ) ? capsuleHeight *.23 : capsuleHeight *.35;
    int capsuleRadius = 60;//capsuleWidth/2;  //different from qt4

    for (int i=0; i<12; i++)
    {
        //QColor color = m_color;
        //color.setAlphaF(1.0f - (i/12.0f));
        p.setPen(Qt::NoPen);
        p.setBrush(m_fadecols[i]);       
        p.save();
        p.translate(rect().center().x(),rect().center().y());
       	p.rotate(m_angle - i*30.0f);
        p.drawRoundRect(-capsuleWidth/2, -(innerRadius+capsuleHeight), capsuleWidth, capsuleHeight, capsuleRadius, capsuleRadius);
        p.restore();
    }
}
