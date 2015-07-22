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

#if !defined(__EZX_UTIL_DIALOG_H__)
#define __EZX_UTIL_DIALOG_H__

#include <ezxutillistbox.h>
#include <zpushbutton.h>
#include <zbasedialog.h>


class UTIL_Dialog : public ZBaseDialog
{
	Q_OBJECT
public:
	enum DialogType {
		DTOnApp = 0,
        DTOnContent,
        DTOnNotify
	};
    UTIL_Dialog(UTIL_Dialog::DialogType dt,
            bool,
            QWidget *parent = 0,
            char const *name = 0,
            int modal = ZBaseDialog::NO_MODAL,
            WFlags f = 0);
    virtual ~UTIL_Dialog();

    QString getDlgTitle();
    virtual void setDlgTitle(QString);
    bool getHasTitle();
    virtual void setHasTitle(bool);
    QWidget *getDlgContent();
    virtual void setDlgContent(QWidget*);
    QWidget *getDlgCst();
    virtual void setDlgCst(QWidget*);

public:
	DialogType	m_dtype;	// 0xc8
	bool		m_consp2;	// 0xcc
	bool		m_boold0;	// 0xd0
	QWidget		*m_qwd4;	// 0xd4
	QWidget		*m_qwd8;	// 0xd8
};


class UTIL_DlgCST : public QWidget
{
    Q_OBJECT
public:
    enum DlgCstType {
        CstOk = 0,
        CstOkCancel,
        Cst3,
        Cst4,   // 3 Buttons but small width
        Cst5,   // 3 Buttons
        Cst6
    };

    ZPushButton *getBtn1();
    ZPushButton *getBtn2();
    ZPushButton *getBtn3();

    UTIL_DlgCST(QWidget *parent = 0, UTIL_DlgCST::DlgCstType dct = CstOk);

    virtual ~UTIL_DlgCST();

    ZPushButton     *m_btn_b8;
    ZPushButton     *m_btn_bc;
    ZPushButton     *m_btn_c0;
    DlgCstType       m_csttype;
};


class UTIL_ListBoxDlg : public UTIL_Dialog
{
    Q_OBJECT
public:

    UTIL_ListBoxDlg(
            UTIL_Dialog::DialogType dt,
            UTIL_DlgCST::DlgCstType dct,
            bool,
            QWidget *parent = 0,
            const char *name = 0,
            int modal = ZBaseDialog::NO_MODAL,
            WFlags f = 0);

    virtual ~UTIL_ListBoxDlg();

    UTIL_ListBox *getListBox();
};

#endif  /* !defined(__EZX_UTIL_DIALOG_H__) */
