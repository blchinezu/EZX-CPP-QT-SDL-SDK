// This defines the interface to the QextScintillaLexerProperties class.
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


#ifndef QEXTSCINTILLALEXERPROPERTIES_H
#define QEXTSCINTILLALEXERPROPERTIES_H


#include <qobject.h>

#include <qextscintillaglobal.h>
#include <qextscintillalexer.h>


//! \brief The QextScintillaLexerProperties class encapsulates the Scintilla
//! Properties lexer.
class QEXTSCINTILLA_EXPORT QextScintillaLexerProperties : public QextScintillaLexer
{
	Q_OBJECT

public:
	//! This enum defines the meanings of the different styles used by the
	//! Properties lexer.
	enum {
		//! The default.
		Default = 0,

		//! A comment.
		Comment = 1,

		//! A section.
		Section = 2,

		//! An assignment operator.
		Assignment = 3,

		//! A default value.
		DefaultValue = 4
	};

	//! Construct a QextScintillaLexerProperties with parent \a parent and
	//! name \a name.  \a parent is typically the QextScintilla instance.
	QextScintillaLexerProperties(QObject *parent = 0,const char *name = 0);

	//! Destroys the QextScintillaLexerProperties instance.
	virtual ~QextScintillaLexerProperties();

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

	//! Returns the end-of-line fill for style number \a style.
	bool eolFill(int style) const;

	//! Returns the font for style number \a style.
	QFont font(int style) const;

	//! Returns the descriptive name for style number \a style.  If the
	//! style is invalid for this language then QString::null is returned.
	//! This is intended to be used in user preference dialogs.
	QString description(int style) const;

	//! Returns the background colour of the text for style number
	//! \a style.
	//!
	//! \sa color()
	QColor paper(int style) const;

	//! Causes all properties to be refreshed by emitting the
	//! propertyChanged() signal as required.
	void refreshProperties();

	//! Returns TRUE if trailing blank lines are included in a fold block.
	//!
	//! \sa setFoldCompact()
	bool foldCompact() const;

public slots:
	//! If \a fold is TRUE then trailing blank lines are included in a fold
	//! block. The default is TRUE.
	//!
	//! \sa foldCompact()
	virtual void setFoldCompact(bool fold);

protected:
	//! The lexer's properties are read from the settings \a qs.  \a prefix
	//! (which has a trailing '/') should be used as a prefix to the key of
	//! each setting.  TRUE is returned if there is no error.
	//!
	//! \sa writeProperties()
	bool readProperties(QSettings &qs,const QString &prefix);

	//! The lexer's properties are written to the settings \a qs.
	//! \a prefix (which has a trailing '/') should be used as a prefix to
	//! the key of each setting.  TRUE is returned if there is no error.
	//!
	//! \sa readProperties()
	bool writeProperties(QSettings &qs,const QString &prefix) const;

private:
	void setCompactProp();

	bool fold_compact;

#if defined(Q_DISABLE_COPY)
	QextScintillaLexerProperties(const QextScintillaLexerProperties &);
	QextScintillaLexerProperties &operator=(const QextScintillaLexerProperties &);
#endif
};

#endif
