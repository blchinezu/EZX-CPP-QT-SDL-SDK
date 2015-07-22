// This defines the interface to the QextScintillaLexerCSS class.
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


#ifndef QEXTSCINTILLALEXERCSS_H
#define QEXTSCINTILLALEXERCSS_H


#include <qobject.h>

#include <qextscintillaglobal.h>
#include <qextscintillalexer.h>


//! \brief The QextScintillaLexerCSS class encapsulates the Scintilla CSS
//! lexer.
class QEXTSCINTILLA_EXPORT QextScintillaLexerCSS : public QextScintillaLexer
{
	Q_OBJECT

public:
	//! This enum defines the meanings of the different styles used by the
	//! CSS lexer.
	enum {
		//! The default.
		Default = 0,

		//! A tag.
		Tag = 1,

		//! A class selector.
		ClassSelector = 2,

		//! A pseudo-class.
		PseudoClass = 3,

		//! An pseudo-class.
		UnknownPseudoClass = 4,

		//! An operator.
		Operator = 5,

		//! A CSS1 property.
		CSS1Property = 6,

		//! An unknown property.
		UnknownProperty = 7,

		//! A value.
		Value = 8,

		//! A comment.
		Comment = 9,

		//! An ID selector.
		IDSelector = 10,

		//! An important value.
		Important = 11,

		//! An @-rule.
		AtRule = 12,

		//! A double-quoted string.
		DoubleQuotedString = 13,

		//! A single-quoted string.
		SingleQuotedString = 14,

		//! A CSS2 property.
		CSS2Property = 15,

		//! An attribute.
		Attribute = 16
	};

	//! Construct a QextScintillaLexerCSS with parent \a parent and name
	//! \a name.  \a parent is typically the QextScintilla instance.
	QextScintillaLexerCSS(QObject *parent = 0,const char *name = 0);

	//! Destroys the QextScintillaLexerCSS instance.
	virtual ~QextScintillaLexerCSS();

	//! Returns the name of the language.
	const char *language() const;

	//! Returns the name of the lexer.  Some lexers support a number of
	//! languages.
	const char *lexer() const;

	//! \internal Returns a space separated list of words or characters in
	//! a particular style that define the end of a block for
	//! auto-indentation.  The styles is returned via \a style.
	const char *blockEnd(int *style = 0) const;

	//! \internal Returns a space separated list of words or characters in
	//! a particular style that define the start of a block for
	//! auto-indentation.  The styles is returned via \a style.
	const char *blockStart(int *style = 0) const;

	//! \internal Returns the string of characters that comprise a word.
	const char *wordCharacters() const;

	//! Returns the foreground colour of the text for style number
	//! \a style.
	//!
	//! \sa paper()
	QColor color(int style) const;

	//! Returns the font for style number \a style.
	QFont font(int style) const;

	//! Returns the set of keywords for the keyword set \set recognised by
	//! the lexer as a space separated string.
	const char *keywords(int set) const;

	//! Returns the descriptive name for style number \a style.  If the
	//! style is invalid for this language then QString::null is returned.
	//! This is intended to be used in user preference dialogs.
	QString description(int style) const;

	//! Causes all properties to be refreshed by emitting the
	//! propertyChanged() signal as required.
	void refreshProperties();

	//! Returns TRUE if multi-line comment blocks can be folded.
	//!
	//! \sa setFoldComments()
	bool foldComments() const;

	//! Returns TRUE if trailing blank lines are included in a fold block.
	//!
	//! \sa setFoldCompact()
	bool foldCompact() const;

public slots:
	//! If \a fold is TRUE then multi-line comment blocks can be folded.
	//! The default is FALSE.
	//!
	//! \sa foldComments()
	virtual void setFoldComments(bool fold);

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
	bool readProperties(QSettings &qs,const QString &prefix);

	//! The lexer's properties are written to the settings \a qs.
	//! \a prefix (which has a trailing '/') should be used as a prefix to
	//! the key of each setting.  TRUE is returned if there is no error.
	//!
	bool writeProperties(QSettings &qs,const QString &prefix) const;

private:
	void setCommentProp();
	void setCompactProp();

	bool fold_comments;
	bool fold_compact;

#if defined(Q_DISABLE_COPY)
	QextScintillaLexerCSS(const QextScintillaLexerCSS &);
	QextScintillaLexerCSS &operator=(const QextScintillaLexerCSS &);
#endif
};

#endif
