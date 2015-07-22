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

#if !defined(__ZMESSAGEBOX_H__)
#define __ZMESSAGEBOX_H__

/*
 * Quick dialog box class, with 0-3 labeled buttons.
 */

#include <qlabel.h>
#include "zbasedialog.h"

class ZMessageBox : public ZBaseDialog {
	Q_OBJECT
public:
	static int information(QWidget *parent,
			       QPixmap const &icon,
			       QString const &caption,
			       QString const &lbutton_cap,
			       QString const &mbutton_cap = QString::null,
			       QString const &rbutton_cap = QString::null,
			       int modal = 1);

	static int timerMessage(QWidget *parent,
				QPixmap const &icon,
				QString const &caption,
				int timeout,
				int modal = 1);

	static int timerInformation(QWidget *parent,
				    QPixmap const &icon,
				    QString const &caption,
				    int timeout,
				    QString const &lbutton_cap,
				    QString const &mbutton_cap = QString::null,
				    QString const &rbutton_cap = QString::null,
				    int modal = 1);

	ZMessageBox(QWidget *parent,
		    QPixmap const &icon,
		    QString const &caption,
		    int timeout,
		    int modal = 1);

	ZMessageBox(QWidget *parent,
		    QPixmap const &icon,
		    QString const &caption,
		    QString const &lbutton_cap,
		    QString const &mbutton_cap,
		    QString const &rbutton_cap,
		    int modal = 1);

	virtual void adjustSize(void);
	virtual void resizeEvent(QResizeEvent*);
	virtual void keyPressEvent(QKeyEvent*);
	void resizeButtons(void);
	void setButtonText(int, QString const&);
	void setIconPixmap(QPixmap const&);
	void slotTimerDone(void);
	void slotButtonClicked(void);
	void slotTimerOutForDlgWithBtn(void);
	void init(int, int, int);
	void setText(QString const&);

	virtual ~ZMessageBox();

	int indexOf(int) const;

	QLabel		*m_qlabelc8;
	QLabel		*m_qlabelderivedcc;
};

#endif  /* !defined(__ZMESSAGEBOX_H__) */
