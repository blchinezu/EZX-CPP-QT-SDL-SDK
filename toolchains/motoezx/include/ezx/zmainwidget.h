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

#if !defined(__ZMAINWIDGET_H__)
#define __ZMAINWIDGET_H__

/*
 * Main application widget.  Creates regions for each part of the EZX
 * user interface.  Upholds the system look-and-feel.  One of these
 * is typically passed to ZApplication::setMainWidget().
 */

#include <qlabel.h>
#include <qlayout.h>
#include <quuid.h>
#include <zglobal.h>
#include <zpushbutton.h>

class ZMainWidgetData;		// Unenumerated private class

class ZMainWidget : public QWidget {
	Q_OBJECT

public:
	/*
	 * Virtual methods - ORDER IS IMPORTANT
	 * These are overridden methods from QWidget and its parents.
	 * See other documentation for a description of what they do.
	 */
	virtual ~ZMainWidget();
	// virtual bool event(QEvent*); // blackhawk
	virtual void show(void);
	virtual void hide(void);
	// virtual void keyPressEvent(QKeyEvent*); // blackhawk
	// virtual bool qwsEvent(QWSEvent*); // blackhawk
	virtual void paletteChange(QPalette const&);

	/* Below are virtual methods that originate with ZMainWidget */

	/*
	 * Assigns the content area widget.  Any existing
	 * widget will be destroyed.  This must be called prior
	 * to any attempts to display this widget.
	 * If widget is NULL, a new ZScrollView will be created.
	 *
	 * Return value:
	 *	true		Content widget assigned
	 *	false		Failure allocating a default ZScrollView.
	 */
	virtual bool setContentWidget(QWidget *widget);

	/*
	 * Identical to setContentWidget, except sets the bottom
	 * toolbar widget, and creates a QFrame by default.
	 */
	virtual bool setCSTWidget(QWidget *widget);

public slots:
	virtual void hideInputWidget(void);
	virtual void slotPopupMenu(int);
	virtual void invokeInputWidget(void);
	// virtual void updateInputWidgetState(int, bool); // blackhawk

public:
	virtual int showToolBar(void);		// stub
	virtual int setToolBar(QUuid const&);	// stub
	virtual int hideToolBar(void);		// stub
	virtual void setupInputMethodsPopupMenu(void);

	QWidget *getContentWidget(void);
	QWidget *getCSTWidget(bool b = TRUE); // blackhawk
	QLabel *getTitleBarWidget(void);

	/*
	 * Main constructor: Creates a three-zone main app widget.
	 *	-> A title bar area at the top with the given text.
	 *	-> A content area
	 *	-> A lower toolbar area ("CST")
	 *
	 * If editmode is true, it will also set up a virtual
	 * keyboard widget.
	 */
	ZMainWidget(QString const &titlebar_caption,
		    bool editmode,
		    QWidget *parent,
		    char const *obj_name,
		    unsigned int widget_flags);

	ZMainWidget(bool editmode,
		    QWidget *parent,
		    char const *obj_name,
		    unsigned int widget_flags);

	ZMainWidget(QWidget *parent,
		    char const *obj_name,
		    unsigned int widget_flags);

	void init(bool, QString const&);

	bool getKbState(void);
	bool getEditMode(void);

	void checkMenuItem(QPopupMenu*, QString, bool);

	/* Seemingly deprecated, returns m_id8, no other refs */
	int getKbPopupMenu(void);

	ZPushButton *getKbBtn(void);

	void setInputMethod(QUuid const&, ZGlobal::KbFlags f);
	void setInputMethods(QWidget*, QUuid const&, ZGlobal::KbFlags);
	void setInputMethods(QWidget*, QUuid const&, QValueList<QUuid> const&,
			     ZGlobal::KbFlags);
	void showWithInputMethod(QUuid const&, ZGlobal::KbFlags);
	void setPreDefinedKBFuncs(void);
	void setFavoriteInputMethods(QValueList<QUuid> const&);
	QUuid getCurrentInputMethodName(bool);
	void updateAppDefaultInputMethod(void);
	void getIMList(void);

public slots:
	void popupKBMenu(void);
	void removeWidgetInputMethod(void);
	void objectDestroyed(void);
	void slotAppMessage(QCString const&, QArray<char> const&);

signals:
	void kbStateChanged(bool);
	void kbStateChanged(bool, QUuid const&, int);

public:
	/* Data members */
	QWidget			*m_content_widget_b8;
	QWidget			*m_toolbar_widget_bc;
	QVBoxLayout		*m_vbox_c0;
	int			m_editmode_c4;	// seemingly bool but aligned
	int			m_kbstate_c8;	// seemingly bool but aligned
	ZPushButton		*m_kbbutton_cc;
	int			m_i_d8;
	ZMainWidgetData		*m_data_d4;
};

#endif  /* !defined(__ZMAINWIDGET_H__) */
