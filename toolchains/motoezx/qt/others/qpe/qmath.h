/**********************************************************************
** Copyright (C) 2001 Trolltech AS.  All rights reserved.
**
** This file is part of the Qtopia Environment.
**
** Licensees holding valid Qtopia Developer license may use this
** file in accordance with the Qtopia Developer License Agreement
** provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
** THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
** PURPOSE.
**
** email sales@trolltech.com for information about Qtopia License
** Agreements.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/
#ifndef QMATH_H
#define QMATH_H

#ifdef __cplusplus
extern "C"
{
#endif

double qSqrt( double value );
double qSin( double a );
double qCos( double a );
double qATan2( double y, double x );
double qATan( double a );
double qASin( double a );
double qTan( double a );
double qFloor( double a );
double qFabs( double a );

#ifdef __cplusplus
}
#endif

#endif
