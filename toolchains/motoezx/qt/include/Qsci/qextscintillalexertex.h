// This defines the interface to the QextScintillaLexerTeX class.
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


#ifndef QEXTSCINTILLALEXERTEX_H
#define QEXTSCINTILLALEXERTEX_H


#include <qobject.h>

#include <qextscintillaglobal.h>
#include <qextscintillalexer.h>


//! \brief The QextScintillaLexerTeX class encapsulates the Scintilla TeX
//! lexer.
class QEXTSCINTILLA_EXPORT QextScintillaLexerTeX : public QextScintillaLexer
{
	Q_OBJECT

public:
	//! This enum defines the meanings of the different styles used by the
	//! TeX lexer.
	enum {
		//! The default.
		Default = 0,

		//! A special.
		Special = 1,

		//! A group.
		Group = 2,

		//! A symbol.
		Symbol = 3,

		//! A command.
		Command = 4,

		//! Text.
		Text = 5
	};

	//! Construct a QextScintillaLexerTeX with parent \a parent and name
	//! \a name.  \a parent is typically the QextScintilla instance.
	QextScintillaLexerTeX(QObject *parent = 0,const char *name = 0);

	//! Destroys the QextScintillaLexerTeX instance.
	virtual ~QextScintillaLexerTeX();

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

	//! Returns the set of keywords for the keyword set \set recognised by
	//! the lexer as a space separated string.
	const char *keywords(int set) const;

	//! Returns the descriptive name for style number \a style.  If the
	//! style is invalid for this language then QString::null is returned.
	//! This is intended to be used in user preference dialogs.
	QString description(int style) const;

private:
#if defined(Q_DISABLE_COPY)
	QextScintillaLexerTeX(const QextScintillaLexerTeX &);
	QextScintillaLexerTeX &operator=(const QextScintillaLexerTeX &);
#endif
};

#endif
