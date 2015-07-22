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

#if !defined(__ZGLOBAL_H__)
#define __ZGLOBAL_H__

/*
 * ZGlobal class seemingly containing only static members.
 */

#include <qrect.h>
#include <qmap.h>
#include <quuid.h>
#include <qpopupmenu.h>

enum EZX_FONT_SIZE_T {
	FONT_SIZE_UNK = 0,
};

class ZGlobal {
public:
	enum KbFlags {
		KBF_NONE = 0,
	};

	static QRect getCst1_1R(void);
	static QRect getCst3_1R(void);
	static QRect getCst3_2R(void);
	static QRect getCst3_3R(void);
	static QRect getCSTRect(void);
	static QRect getScreenR(void);
	static QRect getContentR(void);
	static QRect getCst2a_1R(void);
	static QRect getCst2a_2R(void);
	static QRect getCst2b_1R(void);
	static QRect getCst2b_2R(void);
	static QRect getCst2c_1R(void);
	static QRect getCst2c_2R(void);
	static QRect getCst3a_1R(void);
	static QRect getCst3a_2R(void);
	static QRect getCst3a_3R(void);
	static QRect getCst3b_1R(void);
	static QRect getCst3b_2R(void);
	static QRect getCst3b_3R(void);
	static QRect getCst3c_1R(void);
	static QRect getCst3c_2R(void);
	static QRect getCst3c_3R(void);
	static QRect getCst4a_1R(void);
	static QRect getCst4a_2R(void);
	static QRect getCst4a_3R(void);
	static QRect getCst4a_4R(void);
	static QRect getCst4b_1R(void);
	static QRect getCst4b_2R(void);
	static QRect getCst4b_3R(void);
	static QRect getCst4b_4R(void);
	static QRect getDlgA1_1R(void);
	static QRect getDlgB1_1R(void);
	static QRect getDlgB2_1R(void);
	static QRect getDlgB2_2R(void);
	static QRect getDlgCstLR(void);
	static QRect getDlgCstMR(void);
	static QRect getDlgCstSR(void);
	static QRect getDlgA2a_1R(void);
	static QRect getDlgA2a_2R(void);
	static QRect getDlgA2b_1R(void);
	static QRect getDlgA2b_2R(void);
	static QRect getDlgA3a_1R(void);
	static QRect getDlgA3a_2R(void);
	static QRect getDlgA3a_3R(void);
	static QRect getDlgA3b_1R(void);
	static QRect getDlgA3b_2R(void);
	static QRect getDlgA3b_3R(void);
	static QRect getDlgA3c_1R(void);
	static QRect getDlgA3c_2R(void);
	static QRect getDlgA3c_3R(void);
	static QRect getDlgLargeR(void);
	static QRect getDlgSmallR(void);
	static QRect getDlgMiddleR(void);
	static QRect getDlgTitleLR(void);
	static QRect getDlgTitleMR(void);
	static QRect getDlgTitleSR(void);
	static QRect getStatusBarR(void);
	static QRect getDesktopRect(void);
	static QRect getSubContentR(void);
	static QRect getKbR(void);
	static QRect getCstR(void);
	static QRect getGNBRect(void);
	static QRect getGnbR(void);
	static QRect diffRect(QRect, QRect);
	static QRect getHomeR(void);
	static QRect getDlgLargeConR(void);
	static QRect getDlgSmallConR(void);
	static QRect hideInputWidget(void);
	static QRect getDlgMiddleConR(void);
	static QRect getSmallContentR(void);
	static QRect getMainWidgetRect(void);

	static QRect mapFromGlobalR(QWidget*, QRect);
	static int getLineHeight(void);
	static int getLineSpace(void);
	static void getPopupMenuTopLeft(QWidget*, QPopupMenu*, QPoint&);

	static void setInputMethod(int, QUuid const&, ZGlobal::KbFlags, bool);
	static void setInputMethod(QUuid const&, ZGlobal::KbFlags);

	static void showInputWidget(int, int, bool);
	static void hideInputWidgetAux(int, int, bool);

	static int getFontSize(EZX_FONT_SIZE_T);
};

#endif  /* !defined(__ZGLOBAL_H__) */
