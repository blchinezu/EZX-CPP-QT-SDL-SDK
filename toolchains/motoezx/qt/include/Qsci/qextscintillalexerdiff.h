// This defines the interface to the QextScintillaLexerDiff class.
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


#ifndef QEXTSCINTILLALEXERDIFF_H
#define QEXTSCINTILLALEXERDIFF_H


#include <qobject.h>

#include <qextscintillaglobal.h>
#include <qextscintillalexer.h>


//! \brief The QextScintillaLexerDiff class encapsulates the Scintilla Diff
//! lexer.
class QEXTSCINTILLA_EXPORT QextScintillaLexerDiff : public QextScintillaLexer
{
	Q_OBJECT

public:
	//! This enum defines the meanings of the different styles used by the
	//! Diff lexer.
	enum {
		//! The default.
		Default = 0,

		//! A comment.
		Comment = 1,

		//! A command.
		Command = 2,

		//! A header.
		Header = 3,

		//! A position.
		Position = 4,

		//! A removed line.
		LineRemoved = 5,

		//! An added line.
		LineAdded = 6
	};

	//! Construct a QextScintillaLexerDiff with parent \a parent and name
	//! \a name.  \a parent is typically the QextScintilla instance.
	QextScintillaLexerDiff(QObject *parent = 0,const char *name = 0);

	//! Destroys the QextScintillaLexerDiff instance.
	virtual ~QextScintillaLexerDiff();

	//! Returns the name of the language.
	const char *language() const;

	//! Returns the name of the lexer.  Some lexers support a number of
	//! languages.
	const char *lexer() const;

	//! \internal Returns the string of characters that comprise a word.
	const char *wordCharacters() const;

	//! Returns the foreground colour of the text for style number
	//! \a style.
	//!
	//! \sa paper()
	QColor color(int style) const;

	//! Returns the descriptive name for style number \a style.  If the
	//! style is invalid for this language then QString::null is returned.
	//! This is intended to be used in user preference dialogs.
	QString description(int style) const;

private:
#if defined(Q_DISABLE_COPY)
	QextScintillaLexerDiff(const QextScintillaLexerDiff &);
	QextScintillaLexerDiff &operator=(const QextScintillaLexerDiff &);
#endif
};

#endif
