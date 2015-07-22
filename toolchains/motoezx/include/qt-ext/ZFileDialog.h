/*********************************************************************************************
    This file is part of ZEditor (Text Editor for EZX)
    Copyright (C) 2010 Wangbin <wbsecg1@gmail.com>
 	(aka. nukin in ccmove & novesky in http://forum.motorolafans.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*********************************************************************************************/

#ifndef ZFILEDIALG_H
#define ZFILEDIALG_H

#include <qdir.h>

#include <ezxutildialog.h>
#include "fileview.h"


class FileView;

class ZFileDialog : public UTIL_Dialog
{
	Q_OBJECT
public:
	ZFileDialog(QWidget* p=0,const QString& dir="/",const QString& nameFilter="*", int filter=QDir::All |QDir::Hidden |QDir::System, \
	int sort=QDir::Name | QDir::DirsFirst | QDir::IgnoreCase);
	~ZFileDialog();
	void setTitle(const QString& t) { setDlgTitle(t);}
	
	void setDir(const QString& dir) { browser->setDir(dir);}
	//void setFilter(const QString& f) { browser->setFilter(f); }
	QString getFileAbsPath() const { return browser->getAbsPath();}
	QString getDir() const { return browser->getFolder();}
	
	static QString getFileDirect(QWidget* p=0,const QString& dir="/mmc/mmca1",const QString& filter="*"); //return filepath or null
	static QString getDirDirect(QWidget* p=0);
public slots:
	void dirUp();
private:
	FileView* browser;
	
};

#endif //ZFILEDIALG_H

