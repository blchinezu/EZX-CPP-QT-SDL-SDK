// This defines the interface to the QextScintillaLexer class.
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


#ifndef QEXTSCINTILLALEXER_H
#define QEXTSCINTILLALEXER_H


#include <qobject.h>
#include <qstring.h>
#include <qcolor.h>
#include <qfont.h>

#include <qextscintillaglobal.h>


class QSettings;


//! \brief The QextScintillaLexer class is an abstract class used as a base for
//! specific language lexers.
//!
//! A Scintilla lexer scans the text breaking it up into separate language
//! objects, e.g. keywords, strings, operators.  The lexer then uses a
//! different style to draw each object.  A style is identified by a style
//! number and has a number of attributes, including colour and font.  A
//! specific language lexer will implement appropriate default styles which can
//! be overriden by an application by further sub-classing the specific
//! language lexer.
//!
//! A specific language lexer may provide one or more sets of words to be
//! recognised as keywords.  Most lexers only provide one set, but some may
//! support languages embedded in other languages and provide several sets.
//!
//! QextScintillaLexer provides convenience methods for saving and restoring
//! user preferences for fonts and colours.
class QEXTSCINTILLA_EXPORT QextScintillaLexer : public QObject
{
	Q_OBJECT

public:
	//! Construct a QextScintillaLexer with parent \a parent and name
	//! \a name.  \a parent is typically the QextScintilla instance.
	QextScintillaLexer(QObject *parent = 0,const char *name = 0);

	//! Destroys the QextScintillaLexer instance.
	virtual ~QextScintillaLexer();

	//! Returns the name of the language.  It must be re-implemented by a
	//! sub-class.
	virtual const char *language() const = 0;

	//! Returns the name of the lexer.  Some lexers support a number of
	//! languages.  It must be re-implemented by a sub-class.
	virtual const char *lexer() const = 0;

	//! Returns the auto-indentation style.  The default is 0 if the
	//! language is block structured, or QextScintilla::AiMaintain if not.
	//!
	//! \sa setAutoIndentStyle(), QextScintilla::AiMaintain,
	//! QextScintilla::AiOpening, QextScintilla::AiClosing
	int autoIndentStyle();

	//! \internal Returns a space separated list of words or characters in
	//! a particular style that define the end of a block for
	//! auto-indentation.  The style is returned via \a style.
	virtual const char *blockEnd(int *style = 0) const;

	//! \internal Returns the number of lines prior to the current one when
	//! determining the scope of a block when auto-indenting.
	virtual int blockLookback() const;

	//! \internal Returns a space separated list of words or characters in
	//! a particular style that define the start of a block for
	//! auto-indentation.  The style is returned via \a style.
	virtual const char *blockStart(int *style = 0) const;

	//! \internal Returns a space separated list of keywords in a
	//! particular style that define the start of a block for
	//! auto-indentation.  The style is returned via \a style.
	virtual const char *blockStartKeyword(int *style = 0) const;

	//! \internal Returns the style used for braces for brace matching.
	virtual int braceStyle() const;

	//! \internal Returns the number of style bits needed by the lexer.
	//! The default is 5.
	virtual int styleBits() const;

	//! \internal Returns the string of characters that comprise a word.
	//! The default is 0 which implies the upper and lower case alphabetic
	//! characters and underscore.
	virtual const char *wordCharacters() const;

	//! Returns the foreground colour of the text for style number
	//! \a style.  The default colour is black.
	//!
	//! \sa paper()
	virtual QColor color(int style) const;

	//! Returns the end-of-line for style number \a style.  The default is
	//! FALSE.
	virtual bool eolFill(int style) const;

	//! Returns the font for style number \a style.  The default font is
	//! that returned by defaultFont().
	//!
	//! \sa defaultFont()
	virtual QFont font(int style) const;

	//! Returns the set of keywords for the keyword set \set recognised by
	//! the lexer as a space separated string.  0 is returned if there is
	//! no such set.
	virtual const char *keywords(int set) const;

	//! Returns the descriptive name for style number \a style.  If the
	//! style is invalid for this language then QString::null is returned.
	//! This is intended to be used in user preference dialogs.
	virtual QString description(int style) const = 0;

	//! Returns the background colour of the text for style number
	//! \a style.  The default colour is white.
	//!
	//! \sa color()
	virtual QColor paper(int style) const;

	//! Returns the default font for all styles.
	//!
	//! \sa setDefaultFont()
	virtual QFont defaultFont() const;

	//! Causes all properties to be refreshed by emitting the
	//! propertyChanged() signal as required.
	virtual void refreshProperties();

	//! The colour, paper, font and end-of-line for each style number, and
	//! all lexer specific properties are read from the settings \a qs.
	//! \a prefix is prepended to the key of each entry.  TRUE is returned
	//! if there was no error.
	//!
	//! \sa writeSettings(), QextScintilla::setLexer()
	bool readSettings(QSettings &qs,const char *prefix = "/Scintilla");

	//! The colour, paper, font and end-of-line for each style number, and
	//! all lexer specific properties are written to the settings \a qs.
	//! \a prefix is prepended to the key of each entry.  TRUE is returned
	//! if there was no error.
	//!
	//! \sa readSettings()
	bool writeSettings(QSettings &qs,
			   const char *prefix = "/Scintilla") const;

public slots:
	//! The auto-indentation style is set to \a autoindentstyle.
	//!
	//! \sa autoIndentStyle(), QextScintilla::AiMaintain,
	//! QextScintilla::AiOpening, QextScintilla::AiClosing
	virtual void setAutoIndentStyle(int autoindentstyle);

	//! The foreground colour for style number \a style is set to \a c.  If
	//! \a style is -1 then the colour is set for all styles.
	virtual void setColor(const QColor &c,int style = -1);

	//! Returns the default font for all styles.
	//!
	//! \sa defaultFont()
	virtual void setDefaultFont(const QFont &f);

	//! The end-of-line fill for style number \a style is set to
	//! \a eoffill.  If \a style is -1 then the fill is set for all styles.
	virtual void setEolFill(bool eoffill,int style = -1);

	//! The font for style number \a style is set to \a f.  If \a style is
	//! -1 then the font is set for all styles.
	virtual void setFont(const QFont &f,int style = -1);

	//! The background colour for style number \a style is set to \a c.  If
	//! \a style is -1 then the colour is set for all styles.
	virtual void setPaper(const QColor &c,int style = -1);

signals:
	//! This signal is emitted when the foreground colour of style number
	//! \a style has changed.  The new colour is \a c.
	void colorChanged(const QColor &c,int style);

	//! This signal is emitted when the end-of-file fill of style number
	//! \a style has changed.  The new fill is \a eoffilled.
	void eolFillChanged(bool eoffilled,int style);

	//! This signal is emitted when the font of style number \a style has
	//! changed.  The new font is \a f.
	void fontChanged(const QFont &f,int style);

	//! This signal is emitted when the background colour of style number
	//! \a style has changed.  The new colour is \a c.
	void paperChanged(const QColor &c,int style);

	//! This signal is emitted when the value of the lexer property \a prop
	//! needs to be changed.  The new value is \a val.
	void propertyChanged(const char *prop,const char *val);

protected:
	//! The lexer's properties are read from the settings \a qs.  \a prefix
	//! (which has a trailing '/') should be used as a prefix to the key of
	//! each setting.  TRUE is returned if there is no error.
	//!
	virtual bool readProperties(QSettings &qs,const QString &prefix);

	//! The lexer's properties are written to the settings \a qs.
	//! \a prefix (which has a trailing '/') should be used as a prefix to
	//! the key of each setting.  TRUE is returned if there is no error.
	//!
	virtual bool writeProperties(QSettings &qs,const QString &prefix) const;

private:
	int autoIndStyle;
	QFont defFont;

#if defined(Q_DISABLE_COPY)
	QextScintillaLexer(const QextScintillaLexer &);
	QextScintillaLexer &operator=(const QextScintillaLexer &);
#endif
};

#endif
