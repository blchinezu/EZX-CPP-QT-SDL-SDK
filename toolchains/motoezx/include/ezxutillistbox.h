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

#if !defined(__EZX_UTIL_LISTBOX_H__)
#define __EZX_UTIL_LISTBOX_H__

#include <qlist.h>
#include <qlistbox.h>

/*
 * This is a QListBox derived class that supports lists with pixmap
 * columns and radio buttons or checkboxes.  The tasks application
 * uses it for the "delete tasks" dialog, and several other apps use
 * it as well.  There is another interesting class called
 * UTIL_ListBoxClipper that should also be investigated.
 */

class ItemInfo;

class UTIL_ListBoxItem : public QListBoxItem {

public:
	UTIL_ListBoxItem(QListBox *parent, QString caption, bool radio = false);

	//QPixmap itemPixmap();
	QString getItemType();
	bool setMaxLines(int);
	unsigned int getReservedData();
	void setReservedData(unsigned int);
	QFont font();
	bool isOn();
	int state();
	bool isDown();
	bool setFont(const QFont &);
	void setLink(const QColor &, bool);
	//QString itemText();
	QPixmap getPixmap(int);
	QString getString(int);
	bool isChecked();
	void setActive();
	void setPixmap(int, const QPixmap &);
	void setString(int, const QString &);
	int getMaxLines() const;
	int perfectWidth(const QListBox *) const;
	int perfectHeight(const QListBox *) const;

	virtual ~UTIL_ListBoxItem();

	virtual QString text() const;
	virtual int height(const QListBox *) const;
	virtual int width(const QListBox *) const;
	virtual void paint(QPainter *);
	virtual void setText(const QString &);
	virtual void drawCheckboxButton(QPainter *, int, int&);
	virtual void drawRadioboxButton(QPainter *, int, int&);
	virtual void drawUnderLine(QPainter*, const QPoint &, const QPoint &);

	QList<ItemInfo>		m_list20;
	int			m_unk40;
	int			m_state44;
	bool			m_b48;
	int			m_unk4c;
	int			m_unk50;
	unsigned int		m_resdata54;
	QFont			m_font58;
	bool			m_b60;
	int			m_maxlines64;
	bool			m_b68;
	QColor			m_color6c;
	int			m_unk74;

	// 0x78
};


typedef QList<UTIL_ListBoxItem> UTIL_ListBoxItemList;

class UTIL_ListBox : public QListBox {
	Q_OBJECT
 public:
    UTIL_ListBox(QString, QWidget *parent = 0, WFlags f = 0);
    UTIL_ListBox(QWidget *parent = 0, WFlags f = 0);

	void removeItem(int);
	void selectBtns(UTIL_ListBoxItem *);
	void updateItem(QListBoxItem *);
	bool itemChecked(int);
	bool itemChecked(UTIL_ListBoxItem *);
	UTIL_ListBoxItemList *itemsChecked();
	virtual void keyPressEvent(QKeyEvent *);
	virtual void mouseMoveEvent(QMouseEvent *);
	virtual void mousePressEvent(QMouseEvent *);
	//virtual void sendItemPackage(QListBoxItem*);
	virtual void mouseReleaseEvent(QMouseEvent *);
	void init(QString, QWidget *, unsigned int);
	void clear();
	void checkItem(int, bool);
	void checkItem(UTIL_ListBoxItem*, bool);
	virtual void paintCell(QPainter *, int, int);

	/*
	 * This constructor sets the widget's name to "ezx_util_list".
	 * The string argument appears to be a format string of some
	 * sort describing column widths.
	 */
    virtual ~UTIL_ListBox();

	int		m_ie0;
	int		m_ie4;
	char		m_ie8;
	QString		m_strec;
};

#endif  /* !defined(__EZX_UTIL_LISTBOX_H__) */
