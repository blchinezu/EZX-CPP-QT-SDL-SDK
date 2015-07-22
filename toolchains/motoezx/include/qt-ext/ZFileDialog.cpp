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
/**********to do******************
*color dialog
*bkmode: desktop/not color
***************************/

#include "ZFileDialog.h"

#include <qhbox.h>
#include <qlabel.h>
#include <qlayout.h>

#include <ZPushButton.h>
#include <ZScrollView.h>

ZFileDialog::ZFileDialog(QWidget* p,const QString& dir,const QString& nameFilter,int filter,int sort)
	:UTIL_Dialog(UTIL_Dialog::DTLargeSize,true,p,"OpenFile Dialog",1,0)
{
	setHasTitle(true);
	setDlgTitle(tr("Select a file plz"));
   //QVBox *cw = new QVBox(this);
   //setDlgContent(cw);
	browser=new FileView(nameFilter,filter, this/*getDlgContent()*/,sort, "browser");
	setDlgContent(browser);
	browser->setDir(dir);

	QHBox *hb = new QHBox(this);
	setDlgCst(hb);

	ZPushButton *okBtn = new ZPushButton(hb, 0, -1, -1);
	okBtn->setText(tr("OK"));	
	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));
	
	ZPushButton *cancelBtn=new ZPushButton(hb, 0, -1, -1);
	cancelBtn->setText(tr("Cancel"));	
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
	
	ZPushButton *backBtn=new ZPushButton(hb, 0, -1, -1);
	backBtn->setText(tr("Back"));
	connect(browser,SIGNAL(rootDir(bool)),backBtn,SLOT(setDisabled(bool)));
	connect(backBtn,SIGNAL(clicked()),this,SLOT(dirUp()));
}

ZFileDialog::~ZFileDialog()
{}

void ZFileDialog::dirUp()
{
	QString dirNow=browser->getFolder();
	int index=dirNow.findRev("/");
	if(index!=0) browser->setDir(dirNow.left(index));  // 即/xxx
	else browser->setDir("/");
}

QString ZFileDialog::getFileDirect(QWidget* p,const QString& dir,const QString& filter)
{
	QString s="";
	ZFileDialog* dlg=new ZFileDialog(p,dir,filter);
	if(dlg->exec()==QDialog::Accepted)
		s=dlg->getFileAbsPath();
	
	delete dlg;
	return s;
}

QString ZFileDialog::getDirDirect(QWidget* p)
{
	QString s="";
	ZFileDialog* dlg=new ZFileDialog(p,"/mmc/mmca1","*",QDir::Dirs |QDir::Hidden);
	if(dlg->exec()==QDialog::Accepted)
		s=dlg->getDir();
	
	delete dlg;
	return s;
}

