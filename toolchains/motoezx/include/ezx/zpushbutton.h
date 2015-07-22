/*
 * Unofficial EZX Native Software Development Kit
 * Copyright (C) 2005 Sam Revitch <samr7@cs.washington.edu>
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

#if !defined(__ZPUSHBUTTON_H__)
#define __ZPUSHBUTTON_H__

#include <qtoolbutton.h>
#include <qstring.h>

class ZDirectPixmap;
class ZResFileReader;

/* Apparent base class for ZSkin */
class ZResReader {
public:
	virtual ~ZResReader();

	/* Types inferred from ZSkin */
	virtual bool exists(QString const&) = 0;
	virtual bool get(QString const&, unsigned char**, int*) const = 0;
	virtual QString getFirstID(void); // stub
	virtual QString getNextID(void);  // stub
};

class ZSkin : public ZResReader {
public:
	/* Reimplemented virtual methods */
	virtual bool exists(QString const&) const;
	virtual bool get(QString const&, unsigned char**, int*) const;

	/* New virtual methods */
	virtual QPixmap getQPixmap(QString const&) const;
	virtual QImage getQImage(QString const&) const;
	virtual QBitmap getQBitmap(QString const&) const;
	virtual QMovie getQMovie(QString const&) const;

	/* Non-virtual methods */
	ZSkin(QString const&, QString const&, QString const&, QString const&);
	ZSkin(void);
	void init(QString const&, QString const&,
		  QString const&, QString const&);

	static void reloadSkin();
	static ZSkin *defaultSkin;
	static ZSkin *skin();

	ZResFileReader	*m_resfilereader_4;
	ZResFileReader	*m_resfilereader_8;
	ZResFileReader	*m_resfilereader_c;
	ZResFileReader	*m_resfilereader_10;
};


class ZPushButton : public QToolButton {
	Q_OBJECT
public:
	/* Reimplemented virtual methods */
	// removed by Ketut P. Kumajaya <kumajaya@bluebottle.com>
	// virtual ~ZPushButton();
	virtual void setMinimumSize(int, int);
	virtual void setPalette(QPalette const&);

public slots:
	virtual void polish(void);

public:
	virtual void resize(int, int);
	virtual void setGeometry(int, int, int, int);
	virtual void setGeometry(QRect const&);
	virtual QSize sizeHint(void) const;
	virtual void paintEvent(QPaintEvent*);
	virtual void setText(QString const&);
	virtual void drawButton(QPainter*);
	virtual void resize(QSize const&);
	virtual QString text(void) const;

public slots:
	/* New virtual methods */
	virtual void popupPressed(void);

public:
	ZPushButton(QWidget*, int, int, int);
	ZPushButton(QString const&, QWidget*, int, int, int);
	ZPushButton(QString const&, QString const&, QWidget*, int, int, int);

	void setResourceID(QString const&);
	void init(QString const&, QString const&, int, int, int);
	int flags(void) const;
	void setFlags(int);
	void setPopup(QPopupMenu*);
	QString resourceID(void) const;
	QPixmap drawActive(void) const;
	QPixmap drawNormal(void) const;
	QPixmap fade(QPixmap const&) const;

	QPixmap active(void) const;
	QPixmap normal(void) const;
	QPixmap disabled(void) const;

	QPixmap activePixmap(void) const;
	QPixmap normalPixmap(void) const;
	QPixmap disabledPixmap(void) const;
	QPixmap activeOverlayPixmap(void) const;
	QPixmap normalOverlayPixmap(void) const;
	QPixmap disabledOverlayPixmap(void) const;
	QPixmap activeOverlay(void) const;
	QPixmap normalOverlay(void) const;
	QPixmap disabledOverlay(void) const;

	void dim1(ZDirectPixmap&, int, int, int) const;
	void dim2(ZDirectPixmap&, int, int, int) const;
	void dim3(ZDirectPixmap&, int, int, int) const;
	void dim4(ZDirectPixmap&, int, int, int) const;
	void dim5(ZDirectPixmap&, int, int, int) const;

	void drawGrad(ZDirectPixmap&, int, int, int, int,
		      QColor const&, QColor const&) const;
	void drawHLine(ZDirectPixmap&, int, int, int, QColor const&) const;
	void drawVLine(ZDirectPixmap&, int, int, int, QColor const&) const;

	static int defaultWidth;
	static int defaultHeight;
	static int multSixTenths;
	static int minWidth;
	static int minHeight;

	QString		m_resid_114;
	QString		m_string_118;
	int		m_flags_11c;
};

#endif /* !defined(__ZPUSHBUTTON_H__) */
