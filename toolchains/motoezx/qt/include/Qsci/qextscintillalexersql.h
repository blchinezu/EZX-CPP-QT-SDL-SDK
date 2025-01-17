// This defines the interface to the QextScintillaLexerSQL class.
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


#ifndef QEXTSCINTILLALEXERSQL_H
#define QEXTSCINTILLALEXERSQL_H


#include <qobject.h>

#include <qextscintillaglobal.h>
#include <qextscintillalexer.h>


//! \brief The QextScintillaLexerSQL class encapsulates the Scintilla SQL
//! lexer.
class QEXTSCINTILLA_EXPORT QextScintillaLexerSQL : public QextScintillaLexer
{
	Q_OBJECT

public:
	//! This enum defines the meanings of the different styles used by the
	//! SQL lexer.
	enum {
		//! The default.
		Default = 0,

		//! A comment.
		Comment = 1,

		//! A line comment.
		CommentLine = 2,

		//! \obsolete A line comment.
		LineComment = CommentLine,

		//! A JavaDoc/Doxygen style comment.
		CommentDoc = 3,

		//! A number.
		Number = 4,

		//! A keyword.
		Keyword = 5,

		//! A double-quoted string.
		DoubleQuotedString = 6,

		//! A single-quoted string.
		SingleQuotedString = 7,

		//! An SQL*Plus keyword.
		PlusKeyword = 8,

		//! An SQL*Plus prompt.
		PlusPrompt = 9,

		//! An operator.
		Operator = 10,

		//! An identifier
		Identifier = 11,

		//! An SQL*Plus comment.
		PlusComment = 13,

		//! A '#' line comment.
		CommentLineHash = 15,

		//! A JavaDoc/Doxygen keyword.
		CommentDocKeyword = 17,

		//! A JavaDoc/Doxygen keyword error.
		CommentDocKeywordError = 18,

		//! A keyword defined in keyword set number 5.  The class must
		//! be sub-classed and re-implement keywords() to make use of
		//! this style.
		KeywordSet5 = 19,

		//! A keyword defined in keyword set number 6.  The class must
		//! be sub-classed and re-implement keywords() to make use of
		//! this style.
		KeywordSet6 = 20,

		//! A keyword defined in keyword set number 7.  The class must
		//! be sub-classed and re-implement keywords() to make use of
		//! this style.
		KeywordSet7 = 21,

		//! A keyword defined in keyword set number 8.  The class must
		//! be sub-classed and re-implement keywords() to make use of
		//! this style.
		KeywordSet8 = 22,
	};

	//! Construct a QextScintillaLexerSQL with parent \a parent and name
	//! \a name.  \a parent is typically the QextScintilla instance.
	QextScintillaLexerSQL(QObject *parent = 0,const char *name = 0);

	//! Destroys the QextScintillaLexerSQL instance.
	virtual ~QextScintillaLexerSQL();

	//! Returns the name of the language.
	const char *language() const;

	//! Returns the name of the lexer.  Some lexers support a number of
	//! languages.
	const char *lexer() const;

	//! \internal Returns the style used for braces for brace matching.
	int braceStyle() const;

	//! Returns the foreground colour of the text for style number
	//! \a style.
	//!
	//! \sa paper()
	QColor color(int style) const;

	//! Returns the end-of-line fill for style number \a style.
	bool eolFill(int style) const;

	//! Returns the font for style number \a style.
	QFont font(int style) const;

	//! Returns the set of keywords for the keyword set \set recognised by
	//! the lexer as a space separated string.
	const char *keywords(int set) const;

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

	//! Returns TRUE if multi-line comment blocks can be folded.
	//!
	//! \sa setFoldComments()
	bool foldComments() const;

	//! Returns TRUE if trailing blank lines are included in a fold block.
	//!
	//! \sa setFoldCompact()
	bool foldCompact() const;

	//! Returns TRUE if backslash escapes are enabled.
	//!
	//! \sa setBackslashEscapes()
	bool backslashEscapes() const;

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

	//! If \a enable is TRUE then backslash escapes are enabled.  The
	//! default is FALSE.
	//!
	//! \sa backslashEscapes()
	virtual void setBackslashEscapes(bool enable);

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
	void setBackslashEscapesProp();

	bool fold_comments;
	bool fold_compact;
	bool backslash_escapes;


#if defined(Q_DISABLE_COPY)
	QextScintillaLexerSQL(const QextScintillaLexerSQL &);
	QextScintillaLexerSQL &operator=(const QextScintillaLexerSQL &);
#endif
};

#endif
