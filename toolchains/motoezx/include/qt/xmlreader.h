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
#ifndef XMLREADER_H
#define XMLREADER_H

#include <qstring.h>
#include <qxml.h>
#include <qmap.h>

class Node
{
public:
    Node();
    ~Node();

    void addChild( Node *child );

    void setAttributes( const QXmlAttributes &a );
    QMap<QString, QString> attributeMap();
    QString attribute( const QString& name );

    Node *nextNode() const { return next; }
    Node *prevNode() const { return prev; }
    Node *parentNode() const { return parent; }
    Node *lastChild() const { return last; }
    Node *firstChild() const { return first; }

    void setTagName( const QString &s ) { tagN = s; }
    QString tagName() const { return tagN; }
    void setData( const QString &s ) { dt = s; }
    QString data() const { return dt; }
    QString subData(const QString& tag) const;
    void appendData( const QString s ) { dt += s; }


private:
    QMap<QString, QString> attributes;
    QString dt, tagN;

    Node *parent, *prev, *next, *first, *last;
};

class XmlHandlerPrivate;
class XmlHandler : public QXmlDefaultHandler
{
public:
    XmlHandler();
    ~XmlHandler();

    bool startDocument();
    bool endDocument();
    bool startElement( const QString &ns, const QString &ln, const QString &qName,
		       const QXmlAttributes &attr );
    bool endElement( const QString &ns, const QString &ln, const QString &qName );
    bool characters( const QString &ch );

    Node *firstNode() const { return tree; }

private:
    Node *node, *tree;
    XmlHandlerPrivate *d;
};



#endif
