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

#if !defined(__ZBASEDIALOG_H__)
#define __ZBASEDIALOG_H__

/*
 * Nearly inconsequential base class for EZX dialog boxes.
 * Supports their notion of modality.
 */

#include <qdialog.h>

class ZBaseDialog : public QDialog {
	Q_OBJECT

public:
	// virtual bool event(QEvent*); // blackhawk
	// virtual bool eventFilter(QObject*, QEvent*); // blackhawk
	virtual bool qwsEvent(QWSEvent*);
	virtual void done(int);
	virtual void accept(void);
	virtual void reject(void);
	ZBaseDialog(QWidget *parent,
		    char const *name,
		    int modal = 0,
		    unsigned int x = 0);
	virtual ~ZBaseDialog();

	int m_modality;		// 0xc4
};

#endif  /* !defined(__ZBASEDIALOG_H__) */
