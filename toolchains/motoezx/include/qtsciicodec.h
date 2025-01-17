/****************************************************************************
** $Id: qt/src/3rdparty/tools/qtsciicodec.h   2.3.6   edited 2002-06-07 $
**
** Definition of QTSCIICodec class
**
*****************************************************************************/

// Contributed by Hans Petter Bieker <bieker@kde.org>
// See the documentation for their license statement for the code as
// it was at the time of contribution.

#ifndef QTSCIICODEC_H
#define QTSCIICODEC_H

#ifndef QT_H
#include "qtextcodec.h"
#endif // QT_H

#ifndef QT_NO_TSCIICODEC

class Q_EXPORT QTsciiCodec : public QTextCodec {
public:
    virtual int mibEnum() const;
    const char* name() const;

    QCString fromUnicode(const QString& uc, int& len_in_out) const;
    QString toUnicode(const char* chars, int len) const;

    int heuristicContentMatch(const char* chars, int len) const;
    int heuristicNameMatch(const char* hint) const;
};

#endif

#endif
