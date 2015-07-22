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

#if !defined(__EZX_UTIL_GRAPH_H__)
#define __EZX_UTIL_GRAPH_H__

#include <qpainter.h>
#include <qpoint.h>
#include <qcolor.h>
#include <qpixmap.h>

class UTIL_Graph {
	static void drawUnderLine(QPainter*, QColorGroup const&,
				  QPoint const&, QPoint const&);
	static void drawOutlineText(QPainter*, QColor, QColor, int, int,
				    int, int, int, QString const&,
				    int, QRect*, char**);
	static QPixmap createDisabledPixmap(QPixmap const&);
	static QPixmap drawNegativeColorPixmap(QPixmap const&);
	static void makeTitle(QWidget*, int);
};

#endif  /* !defined(__EZX_UTIL_GRAPH_H__) */
