// This defines the interface to the QextScintillaLexerPOV class.
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


#ifndef QEXTSCINTILLALEXERPOV_H
#define QEXTSCINTILLALEXERPOV_H


#include <qobject.h>

#include <qextscintillaglobal.h>
#include <qextscintillalexer.h>


//! \brief The QextScintillaLexerPOV class encapsulates the Scintilla POV
//! lexer.
class QEXTSCINTILLA_EXPORT QextScintillaLexerPOV : public QextScintillaLexer
{
	Q_OBJECT

public:
	//! This enum defines the meanings of the different styles used by the
	//! POV lexer.
	enum {
		//! The default.
		Default = 0,

		//! A comment.
		Comment = 1,

		//! A comment line.
		CommentLine = 2,

		//! A number.
		Number = 3,

		//! An operator.
		Operator = 4,

		//! An identifier
		Identifier = 5,

		//! A string.
		String = 6,

		//! The end of a line where a string is not closed.
		UnclosedString = 7,

		//! A directive.
		Directive = 8,

		//! A bad directive.
		BadDirective = 9,

		//! Objects, CSG and appearance.
		ObjectsCSGAppearance = 10,

		//! Types, modifiers and items.
		TypesModifiersItems = 11,

		//! Predefined identifiers.
		PredefinedIdentifiers = 12,

		//! Predefined identifiers.
		PredefinedFunctions = 13,

		//! A keyword defined in keyword set number 6.  The class must
		//! be sub-classed and re-implement keywords() to make use of
		//! this style.
		KeywordSet6 = 14,

		//! A keyword defined in keyword set number 7.  The class must
		//! be sub-classed and re-implement keywords() to make use of
		//! this style.
		KeywordSet7 = 15,

		//! A keyword defined in keyword set number 8.  The class must
		//! be sub-classed and re-implement keywords() to make use of
		//! this style.
		KeywordSet8 = 16
	};

	//! Construct a QextScintillaLexerPOV with parent \a parent and name
	//! \a name.  \a parent is typically the QextScintilla instance.
	QextScintillaLexerPOV(QObject *parent = 0,const char *name = 0);

	//! Destroys the QextScintillaLexerPOV instance.
	virtual ~QextScintillaLexerPOV();

	//! Returns the name of the language.
	const char *language() const;

	//! Returns the name of the lexer.  Some lexers support a number of
	//! languages.
	const char *lexer() const;

	//! \internal Returns the style used for braces for brace matching.
	int braceStyle() const;

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

	//! Returns TRUE if directives can be folded.
	//!
	//! \sa setFoldDirectives()
	bool foldDirectives() const;

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

	//! If \a fold is TRUE then directives can be folded.  The default is
	//! FALSE.
	//!
	//! \sa foldDirectives()
	virtual void setFoldDirectives(bool fold);

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
	void setDirectiveProp();

	bool fold_comments;
	bool fold_compact;
	bool fold_directives;

#if defined(Q_DISABLE_COPY)
	QextScintillaLexerPOV(const QextScintillaLexerPOV &);
	QextScintillaLexerPOV &operator=(const QextScintillaLexerPOV &);
#endif
};

#endif
