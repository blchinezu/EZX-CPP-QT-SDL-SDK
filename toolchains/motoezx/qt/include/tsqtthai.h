/*****************************************************************************
 *
 *  tsqtthai.h - glue to support WTLE Thai shaping in Qt.
 *
 *  Copyright: (C) 2003 Agfa Monotype Corporation
 *
 *  This software is furnished under a license and may be used and
 *  copied only in accordance with the terms of such license and with
 *  the inclusion of the above copyright notice. This software or any
 *  other copies thereof may not be provided or otherwise made
 *  available to any other person except as allowed under license.
 *  No title to and ownership of the software is hereby transferred.
 *
 *  Encoding:   US_ASCII    Tab Size:   8  Indentation:    4
 *  $Header:   I:/BULL/DisplayImaging/archives/wtle/product/source/privincl/tsthai.h_v   1.2   Jan 26 2004 16:31:20   ritarip  $
 *
 ****************************************************************************/

#ifndef TSQTTHAI_H
#define TSQTTHAI_H

#include "qarray.h"
#include "qstring.h"

const ushort UniZwsp = 0x200b;
const ushort UniZwNbsp = 0xfeff;

const uchar UniThaiRow = 0x0e;

int TsRemapPosition(const QArray<int> &map, int position);

QString &TsProcessThai(QString &thai, QArray<int> *map = NULL);

#endif /* TSQTTHAI_H */
