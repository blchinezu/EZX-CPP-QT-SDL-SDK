// This defines the interface to the QextScintillaCommand class.
//
// Copyright (c) 2005
// 	Riverbank Computing Limited <info@riverbankcomputing.co.uk>
// 
// This file is part of QScintilla.
// 
// This copy of QScintilla is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option) any
// later version.
// 
// QScintilla is supplied in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
// 
// You should have received a copy of the GNU General Public License along with
// QScintilla; see the file LICENSE.  If not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.


#ifndef QEXTSCINTILLACOMMAND_H
#define QEXTSCINTILLACOMMAND_H


#include <qstring.h>

#include <qextscintillaglobal.h>


class QextScintilla;


//! \brief The QextScintillaCommand class represents an internal editor command
//! that may have one or two keys bound to it.
//!
//! Methods are provided to change the keys bound to the command and to remove
//! a key binding.  Each command has a user friendly description of the command
//! for use in key mapping dialogs.
class QEXTSCINTILLA_EXPORT QextScintillaCommand
{
public:
	//! Binds the key \a key to the command.  If \a key is 0 then the key
	//! binding is removed.  If \a key is invalid then the key binding is
	//! unchanged.  Valid keys are any visible or control character or any
	//! of \c Key_Down, \c Key_Up, \c Key_Left, \c Key_Right, \c Key_Home,
	//! \c Key_End, \c Key_Prior, \c Key_Next, \c Key_Delete,
	//! \c Key_Insert, \c Key_Escape, \c Key_Backspace, \c Key_Tab and
	//! \c Key_Return.  Keys may be modified with any combination of
	//! \c SHIFT, \c CTRL and \c ALT.
	//!
	//! \sa key(), setAlternateKey(), validKey()
	void setKey(int key);

	//! Binds the alternate key \a altkey to the command.  If \a key is 0
	//! then the alternate key binding is removed.
	//!
	//! \sa alternateKey(), setKey(), validKey()
	void setAlternateKey(int altkey);

	//! The key that is currently bound to the command is returned.
	//!
	//! \sa setKey(), alternateKey()
	int key() const {return qkey;}

	//! The alternate key that is currently bound to the command is
	//! returned.
	//!
	//! \sa setAlternateKey(), key()
	int alternateKey() const {return qaltkey;}

	//! If the key \a key is valid then TRUE is returned.
	static bool validKey(int key);

	//! The user friendly description of the command is returned.
	QString description() const;

private:
	friend class QextScintillaCommandSet;

	QextScintillaCommand(QextScintilla *qs,int msg,int key,int altkey,
			     const char *desc);

	int msgId() const {return msgCmd;}
	void bindKey(int key,int &qk,int &scik);

	QextScintilla *qsCmd;
	int msgCmd;
	int qkey, scikey, qaltkey, scialtkey;
	const char *descCmd;

#if defined(Q_DISABLE_COPY)
	QextScintillaCommand(const QextScintillaCommand &);
	QextScintillaCommand &operator=(const QextScintillaCommand &);
#endif
};

#endif
