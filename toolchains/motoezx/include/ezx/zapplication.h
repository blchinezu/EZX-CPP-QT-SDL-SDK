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

#if !defined(__ZAPPLICATION_H__)
#define __ZAPPLICATION_H__

/*
 * This is the main application class for EZX applications.
 * It supports a lot of stuff, including the native IPC,
 * single-instancing mechanism, input method, theming, etc..
 * I don't know how it all works, at least not yet.
 */

#include <qobject.h>
#include <qapplication.h>
#include <qlist.h>
#include <quuid.h>
#include <qwindowsystem_qws.h>
#include <qintdict.h>
#include <zglobal.h>

/* Q prefix, but implemented in ezxappbase */
class QTestCaptureHandler;
class ZInputMethodState;

class THEME_CONFIG {
public:
	QString		m_string_0;
	QString		m_string_4;
	QPalette	m_palette_8;
	int		m_unk_c;
	QString		m_string_10;
	QString		m_string_14;
	QString		m_string_18;
	QString		m_string_1c;
	QString		m_string_20;
	QString		m_string_24;
	QString		m_string_28;
	QString		m_string_2c;
	QString		m_string_30;
};

class UTIL_WordCompFilter {
public:
	int		m_unk_0;
	int		m_unk_4;
	int		m_unk_8;
	int		m_unk_c;
	int		m_unk_10;
	int		m_i_14;
	QRect		m_rect_18;
	int		m_unk_28;
	int		m_unk_2c;
	int		m_unk_30;
	QPalette	m_palette_34;
};

class ZKbContext : public QObject {
	Q_OBJECT
public:
	ZKbContext(QWidget*);
	virtual ~ZKbContext();

	bool setupConnection(QWidget*);
	void destroyConnection(void);

public slots:
	void slotBufferUpdate(int, int);
	void slotCursorChanged(int, int);
	void slotFeedbackContext(void);

public:
	int	m_unk_24;
	int	m_i_28;
	int	m_i_2c;
};

class ZApplicationData {
public:
	ZApplicationData(void);

	void enqueueMsg(QCString const&, QCString const&, QArray<char> const&);
	bool needShowKB(QWidget*);
	QCollection::Item appendEditor(int, QCString const&);
	void destructData(void);
	void getTouchPanelSoundInfo(void);
	void getMsgs(QString);
	void getTheme(void);
	void sendMsgq(void);

	int			m_unk_0;
	int			m_unk_4;

	// "General_Mouse_PressHold_Ani.gif"
	QString			m_string_8;
	// "General_Cursor_Waiting_Ani.gif"
	QString			m_string_c;

	int			m_unk_10;
	int			m_unk_14;
	QString			m_string_18;
	int			m_unk_1c;
	int			m_unk_20;
	bool			m_b_24;
	bool			m_b_25;
	int			m_i_28;
	bool			m_b_2c;
	bool			m_b_2d;
	int			m_i_30;
	int			m_i_34;
	int			m_i_38;
	int			m_i_3c;
	int			m_i_40;
	bool			m_b_44;
	QStrList		*m_editablewidgets_48;
	THEME_CONFIG		m_themeconfig_4c;

	int			m_unk_84;
	int			m_unk_88;
	char			m_tpsound_8c[256];
	int			m_i_18c;

	int			m_unk_190;
	bool			m_b_194;
	QMovie			*m_movie_198;
	int			m_i_19c;
	QGList			m_list_1a0;
	QIntDict<int>		m_intdict_1c0;	
	UTIL_WordCompFilter	m_wordcompfilter_1dc;
	ZKbContext		m_kbcontext_214;
};

class ZApplication : public QApplication {
	Q_OBJECT

public:
	ZApplication(int &argc, char **argv,
		     QApplication::Type t = QApplication::GuiClient);

	/* Reimplemented virtual methods */
	virtual ~ZApplication();
	virtual bool eventFilter(QObject*, QEvent*);
	// removed by Ketut P. Kumajaya <kumajaya@bluebottle.com>
	// virtual bool vieventFilter(QObject*, QEvent*);
	virtual void timerEvent(QTimerEvent*);
	// virtual void setMainWidget(QWidget*); // blackhawk
	virtual bool qwsEventFilter(QWSEvent*);

	/* New virtual methods */
	// virtual void insertStr(QWSEvent*); // blackhawk
	virtual void tryQuit(void);
	// virtual bool hardKeyEventFilter(QKeyEvent*); // blackhawk

public slots:
	virtual void slotShutdown(void);
	virtual void slotQuickQuit(void);
	virtual void slotUsbStorageInOut(bool);
	virtual void slotClickAppIcon(void);
	virtual void slotRaise(void);

	/* Non-virtual methods */

signals:
	void appMessage(QCString const&, QArray<char> const&);
	void shutdown(void);
	void usbStorageInOut(bool);
	void signalRaise(void);
	void clickAppIcon(void);
	void signalAppLaunched(int);
	void signalOpenDoc(QString const&);
	void signalCmdLine(QString const&);
	void signalBridgeMessage(QArray<char> const&);
	void signalBridgeMessage(QCString const&, QArray<char> const&);
	void signalBridgeMessageWithoutRaise(QCString const&,
					     QArray<char> const&);
	void kbStateChanged(bool, QUuid const&, int);
	void signalMasterClear(void);
	void signalMasterReset(void);
	void signalHomeKeyClicked(void);
	void editableWidgetClicked(int, bool);
	void systemMessage(QCString const&, QArray<char> const&);

public slots:
	void animationTimeOut(void);
	void animationStatus(int);
	void animationUpdate(QRect const&);
	void slotCursorSelected(QWSCursor*);
	void slotSystemMessage(QCString const&, QArray<char> const&);
	void slotServerMessage(QCString const&, QArray<char> const&);
	void slotAppMessage(QCString const&, QArray<char> const&);
	void pidMessage(QCString const&, QArray<char> const&);
	void updateWindowInfo(QWSWindow*, QWSServer::WindowEvent);
	void resetMouseMode(void);
	void resetPressHoldStatus(void);

public:
	// changed by Ketut P. Kumajaya <kumajaya@bluebottle.com>
	static int getMouseMode(QWidget*);
	// changed by Ketut P. Kumajaya <kumajaya@bluebottle.com>
	static void setMouseMode(QWidget*, int);

	int applyStyle(void);
	bool getKBState(void);
	void loadString(QString const&);
	int initPalette(void);
	int applyPalette(void);
	EZX_FONT_SIZE_T initTextSize(void);
	EZX_FONT_SIZE_T changeTextSize(void);
	void loadEZXFonts(void);
	bool createChannel(void);
	void setAutoInvokeKb(bool);
	bool getAutoInvokeKb(void);
	void setAutoInvokeKb(QWidget*, bool);
	void setAutoHideKb(bool);
	bool getAutoHideKb(void);
	int resetPHTimer(void);
	void startShowPHCursor(int, QString const&);
	void stopShowPHCursor(void);
	void startShowWaitCursor(int, QString const&);
	void stopShowWaitCursor(void);

	QRect getEditorRect(int, int, bool);
	void registerEditor(int);
	void showMainWidget(QWidget*);
	ZInputMethodState *getKbStateAgent(void);
	void raiseAppWindows(void);
	void soundTouchPanel(QWSEvent*);
	void enableTouchSound(bool);
	void createTouchSoundMsgQueue(void);
	int getTouchSoundMsgQueue(void);
	void setMaxWindowRect(QRect const&);
	void updateIMNameList(void);	// stub
	QUuid getDefaultKbMethod(bool);
	void setDefaultKbMethod(QUuid const&);
	void showInputWidgetAux(int, int, int, int);
	void manipulateAppWindows(int);
	void removeEditableWidget(char const*);
	void editableWidgetClicked(QWidget*, bool);
	// void enableHardKeyEventFilter(bool); // blackhawk
	bool getHardKeyEventFilter(void);
	void registerEditableWidget(char const*);
	void setFocusToLatestWindow(int);	// stub
	void clientManipulateAppWindows(int, QValueList<int>&);
	void serverManipulateAppWindows(int, QString const&);
	int exec(void);
	void setEnv(QString const&);
	void flushMsgs(void);
	QGList *getIMList(void);
	void quickQuit(void);


	ZApplicationData	*m_zappdata_44;

	/*
	 * Init with "EZX/QtServer"
	 * Connect received to slotServerMessage
	 */
	QCopChannel		*m_qcc_48;

	/*
	 * Init with "EZX/System"
	 * Connect received to slotSystemMessage
	 */
	QCopChannel		*m_qcc_4c;

	/*
	 * Init with "EZX/Application/" + apptitle
	 * Connect received to slotAppMessage
	 */
	QCopChannel		*m_qcc_50;

	/*
	 * createChannel()
	 * Init with "EZX/Application/" + apptitle
	 * Connect received to pidMessage
	 */
	QCopChannel		*m_qcc_54;

	QString			m_string_58;
	bool			m_touchsound_5c;
	int			m_tsmsgq_60;
	bool			m_b_64;
	bool			m_autohidekb_65;
	bool			m_b_66;
	int			m_i_68;
	int			m_unk_6c;
	QTestCaptureHandler	*m_caphand_70;
};

#endif /* !defined(__ZAPPLICATION_H__) */
