/*
 * Unofficial EZX Native Software Development Kit
 * Copyright (C) 2006 Ketut P. Kumajaya <kumajaya@bluebottle.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Further, this software is distributed without any warranty that it is
 * free of the rightful claim of any third person regarding infringement
 * or the like.  Any license provided herein, whether implied or
 * otherwise, applies only to this software file.  Patent licenses, if
 * any, provided herein do not apply to combinations of this program with
 * other software, or any other product whatsoever.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#if !defined(__UTIL_SLIDER_H__)
#define __UTIL_SLIDER_H__

#include <qwidget.h>
#include <qrangecontrol.h>

class QTimer;


class UTIL_Slider : public QWidget, public QRangeControl
{
    Q_OBJECT
	
public:
    UTIL_Slider(Qt::Orientation, QWidget *parent, int width, int height);
    UTIL_Slider(const QString &, Qt::Orientation, QWidget *parent, int width, int height);
    UTIL_Slider(int minValue, int maxValue, int pageStep, int value, Qt::Orientation, QWidget *parent, int width, int height);
    UTIL_Slider(const QString &, int minValue, int maxValue, int pageStep, int value, Qt::Orientation, QWidget *parent, int width, int height);
    UTIL_Slider(const QPixmap &, const QPixmap &, const QPixmap &, const QPixmap &, Qt::Orientation, QWidget *parent, int width, int height);
    UTIL_Slider(const QPixmap &, const QPixmap &, const QPixmap &, const QPixmap &, int minValue, int maxValue, int pageStep, int value, Qt::Orientation, QWidget *parent, int width, int height);

    virtual void	setOrientation( Qt::Orientation );
    Qt::Orientation orientation() const;
    virtual void	setTracking( bool enable );
    bool	tracking() const;
    QRect	sliderRect() const;
    QSize	sizeHint() const;
    QSizePolicy sizePolicy() const;
    QSize	minimumSizeHint() const;

    int	 minValue() const;
    int	 maxValue() const;
    void setMinValue( int );
    void setMaxValue( int );
    int	 lineStep() const;
    int	 pageStep() const;
    void setLineStep( int );
    void setPageStep( int );
    int  value() const;

public slots:
    virtual void	setValue( int );
    void	addStep();
    void	subtractStep();

signals:
    void	valueChanged( int value );
    void	sliderPressed();
    void	sliderMoved( int value );
    void	sliderReleased();

protected:
    void	resizeEvent( QResizeEvent * );
    void	paintEvent( QPaintEvent * );

    void	keyPressEvent( QKeyEvent * );
    void	mousePressEvent( QMouseEvent * );
    void	mouseReleaseEvent( QMouseEvent * );
    void	mouseMoveEvent( QMouseEvent * );
    void	wheelEvent( QWheelEvent * );
    void	focusInEvent( QFocusEvent *e );
    void	focusOutEvent( QFocusEvent *e );

    void	valueChange();
    void	rangeChange();

private slots:

private:
    void	init(const QString &, const QPixmap &, const QPixmap &, const QPixmap &, const QPixmap &, Qt::Orientation, int, int width, int height);
    int		positionFromValue( int ) const;
    int		valueFromPosition( int ) const;
    void	reallyMoveSlider( int );
    int		available() const;

    QTimer	*timer;
    QCOORD	sliderPos;
    int		sliderVal;
    QCOORD	clickOffset;
    bool	track;
    Qt::Orientation orient;

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    UTIL_Slider( const UTIL_Slider & );
    UTIL_Slider &operator=( const UTIL_Slider & );
#endif
};

inline bool UTIL_Slider::tracking() const
{
    return track;
}

inline UTIL_Slider::Orientation UTIL_Slider::orientation() const
{
    return orient;
}

#endif // __UTIL_SLIDER_H__
