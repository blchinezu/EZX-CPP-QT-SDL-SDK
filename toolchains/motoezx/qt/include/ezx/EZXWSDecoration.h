/****************************************************************************
** $Id: EZXWSDecoration.h,v 1.3 2003/03/11 03:22:17 a18604 Exp $
**
*****************************************************************************/
//-------------------------------------------------------------------------
//
//Header Name: EZXWSDecoration.h
//
//General Description:  EZXWSDecoration class declare file.
//
//-------------------------------------------------------------------------
//Motorola Confidential Proprietary
//Advance Technology and software operations
//(c)Copyright Motorola 2003, All Rights Reserved
//
// Revision History:
//                             Modification     Tracking
// Author                          Date          Number     Description of Changes
// -------------------------   ------------    ----------   -------------------------
// Kenny Yu (a18604)           03/12/2003                   Created 
// -------------------------   ------------    ----------   -------------------------

#include "qwsmanager_qws.h"

class QPixmap;
class QWidget;
class QRegion;

class EZXWSDecoration : public QWSDecoration
{
public:
    EZXWSDecoration();
    virtual ~EZXWSDecoration();

    virtual QRegion region(const QWidget *, const QRect &, QWSDecoration::Region);
    virtual void paint(QPainter *, const QWidget *);
    //virtual void paintButton(QPainter *, const QWidget *, QWSDecoration::Region, int/* state*/){} //remove for e6

private:
    bool needWS(const QWidget *w)
    {
	return  (w->inherits( "QDialog" ) || w->inherits( "QSemiModal" ));
    }

};
