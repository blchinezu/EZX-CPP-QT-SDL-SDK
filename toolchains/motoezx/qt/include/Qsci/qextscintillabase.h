// This class defines the "official" low-level API.
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


#ifndef QEXTSCINTILLABASE_H
#define QEXTSCINTILLABASE_H


#include <qobject.h>
#include <qwidget.h>

#include <qextscintillaglobal.h>


class ScintillaQt;
class QScrollBar;
class QColor;
class QPainter;
class QPixmap;


//! \brief The QextScintillaBase class implements the Scintilla editor widget
//! and its low-level API.
//!
//! Scintilla (http://www.scintilla.org) is a powerful C++ editor class that
//! supports many features including syntax styling, error indicators, code
//! completion and call tips. It is particularly useful as a programmer's
//! editor.
//!
//! QextScintillaBase is a port to Qt of Scintilla. It implements the standard
//! Scintilla API which consists of a number of messages each taking up to
//! two arguments.
//!
//! See QextScintilla for the implementation of a higher level API that is more
//! consistent with the rest of the Qt toolkit.
class QEXTSCINTILLA_EXPORT QextScintillaBase : public QWidget
{
	Q_OBJECT

public:
	//! The low-level Scintilla API is implemented as a set of messages
	//! each of which takes up to two parameters (\a wParam and \a lParam)
	//! and optionally return a value. This enum defines all the possible
	//! messages.
	//!
	//! \sa SendScintilla()
	enum
	{
		//!
		SCI_START = 2000,

		//!
		SCI_OPTIONAL_START = 3000,

		//!
		SCI_LEXER_START = 4000,

		//! This message appends some text to the end of the document.
		//! \a wParam is the length of the text.
		//! \a lParam is the text to be appended.
		SCI_ADDTEXT = 2001,

		//!
		SCI_ADDSTYLEDTEXT = 2002,

		//!
		SCI_INSERTTEXT = 2003,

		//!
		SCI_CLEARALL = 2004,

		//!
		SCI_CLEARDOCUMENTSTYLE = 2005,

		//!
		SCI_GETLENGTH = 2006,

		//!
		SCI_GETCHARAT = 2007,

		//! This message returns the current position.
		//! 
		//! \sa SCI_SETCURRENTPOS
		SCI_GETCURRENTPOS = 2008,

		//! This message returns the anchor.
		//! 
		//! \sa SCI_SETANCHOR
		SCI_GETANCHOR = 2009,

		//!
		SCI_GETSTYLEAT = 2010,

		//!
		SCI_REDO = 2011,

		//!
		SCI_SETUNDOCOLLECTION = 2012,

		//!
		SCI_SELECTALL = 2013,

		//! This message marks the current state of the text as the
		//! the save point. This is usually done when the text is saved
		//! or loaded.
		//! 
		//! \sa SCN_SAVEPOINTREACHED(), SCN_SAVEPOINTLEFT()
		SCI_SETSAVEPOINT = 2014,

		//!
		SCI_GETSTYLEDTEXT = 2015,

		//!
		SCI_CANREDO = 2016,

		//! This message returns the line that contains a particular
		//! instance of a marker.
		//! \a wParam is the handle of the marker.
		//!
		//! \sa SCI_MARKERADD
		SCI_MARKERLINEFROMHANDLE = 2017,

		//! This message removes a particular instance of a marker.
		//! \a wParam is the handle of the marker.
		//!
		//! \sa SCI_MARKERADD
		SCI_MARKERDELETEHANDLE = 2018,

		//!
		SCI_GETUNDOCOLLECTION = 2019,

		//!
		SCI_GETVIEWWS = 2020,

		//!
		SCI_SETVIEWWS = 2021,

		//!
		SCI_POSITIONFROMPOINT = 2022,

		//!
		SCI_POSITIONFROMPOINTCLOSE = 2023,

		//!
		SCI_GOTOLINE = 2024,

		//! This message clears the current selection and sets the
		//! current position.
		//! \a wParam is the new current position.
		//! 
		//! \sa SCI_SETCURRENTPOS
		SCI_GOTOPOS = 2025,

		//! This message sets the anchor.
		//! \a wParam is the new anchor.
		//! 
		//! \sa SCI_GETANCHOR
		SCI_SETANCHOR = 2026,

		//!
		SCI_GETCURLINE = 2027,

		//! This message returns the character position of the start of
		//! the text that needs to be syntax styled.
		//! 
		//! \sa SCN_STYLENEEDED()
		SCI_GETENDSTYLED = 2028,

		//!
		SCI_CONVERTEOLS = 2029,

		//!
		SCI_GETEOLMODE = 2030,

		//!
		SCI_SETEOLMODE = 2031,

		//!
		SCI_STARTSTYLING = 2032,

		//!
		SCI_SETSTYLING = 2033,

		//!
		SCI_GETBUFFEREDDRAW = 2034,

		//!
		SCI_SETBUFFEREDDRAW = 2035,

		//!
		SCI_SETTABWIDTH = 2036,

		//!
		SCI_GETTABWIDTH = 2121,

		//!
		SCI_SETCODEPAGE = 2037,

		//!
		SCI_SETUSEPALETTE = 2039,

		//! This message sets the symbol used to draw one of 32
		//! markers.  Some markers have pre-defined uses, see the
		//! SC_MARKNUM_* values.
		//! \a wParam is the number of the marker.
		//! \a lParam is the marker symbol and is one of the SC_MARK_*
		//! values.
		//!
		//! \sa SCI_MARKERADD, SCI_MARKERDEFINEPIXMAP
		SCI_MARKERDEFINE = 2040,

		//! This message sets the foreground colour used to draw a
		//! marker.  A colour is represented as a 24 bit value.  The 8
		//! least significant bits correspond to red, the middle 8 bits
		//! correspond to green, and the 8 most significant bits
		//! correspond to blue.  The default value is 0x000000.
		//! \a wParam is the number of the marker.
		//! \a lParam is the colour.
		//!
		//! \sa SCI_MARKERSETBACK
		SCI_MARKERSETFORE = 2041,

		//! This message sets the background colour used to draw a
		//! marker.  A colour is represented as a 24 bit value.  The 8
		//! least significant bits correspond to red, the middle 8 bits
		//! correspond to green, and the 8 most significant bits
		//! correspond to blue.  The default value is 0xffffff.
		//! \a wParam is the number of the marker.
		//! \a lParam is the colour.
		//!
		//! \sa SCI_MARKERSETFORE
		SCI_MARKERSETBACK = 2042,

		//! This message adds a marker to a line.  A handle for the
		//! marker is returned which can be used to track the marker's
		//! position.
		//! \a wParam is the line number.
		//! \a lParam is the number of the marker.
		//!
		//! \sa SCI_MARKERDELETE, SCI_MARKERDELETEALL,
		//! SCI_MARKERDELETEHANDLE
		SCI_MARKERADD = 2043,

		//! This message deletes a marker from a line.
		//! \a wParam is the line number.
		//! \a lParam is the number of the marker.
		//!
		//! \sa SCI_MARKERADD, SCI_MARKERDELETEALL
		SCI_MARKERDELETE = 2044,

		//! This message deletes all occurences of a marker.
		//! \a wParam is the number of the marker.  If \a wParam is -1
		//! then all markers are removed.
		//!
		//! \sa SCI_MARKERADD, SCI_MARKERDELETE
		SCI_MARKERDELETEALL = 2045,

		//! This message returns the 32 bit mask of markers at a line.
		//! \a wParam is the line number.
		SCI_MARKERGET = 2046,

		//! This message looks for the next line to contain at least
		//! one marker contained in a 32 bit mask of markers and
		//! returns the line number.
		//! \a wParam is the line number to start the search from.
		//! \a lParam is the mask of markers to search for.
		//!
		//! \sa SCI_MARKERPREVIOUS
		SCI_MARKERNEXT = 2047,

		//! This message looks for the previous line to contain at
		//! least one marker contained in a 32 bit mask of markers and
		//! returns the line number.
		//! \a wParam is the line number to start the search from.
		//! \a lParam is the mask of markers to search for.
		//!
		//! \sa SCI_MARKERNEXT
		SCI_MARKERPREVIOUS = 2048,

		//! This message sets the symbol used to draw one of the 32
		//! markers to a pixmap.  Pixmaps use the SC_MARK_PIXMAP marker
		//! symbol.
		//! \a wParam is the number of the marker.
		//! \a lParam is a pointer to a QPixmap instance.  Note that in
		//! other ports of Scintilla this is a pointer to either raw or
		//! textual XPM image data.
		//!
		//! \sa SCI_MARKERDEFINE
		SCI_MARKERDEFINEPIXMAP = 2049,

		//! This message sets what can be displayed in a margin.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//! \a lParam is the logical or of the SC_MARGIN_* values.
		//!
		//! \sa SCI_GETMARGINTYPEN
		SCI_SETMARGINTYPEN = 2240,

		//! This message returns what can be displayed in a margin.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//!
		//! \sa SCI_SETMARGINTYPEN
		SCI_GETMARGINTYPEN = 2241,

		//! This message sets the width of a margin in pixels.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//! \a lParam is the new margin width.
		//!
		//! \sa SCI_GETMARGINWIDTHN
		SCI_SETMARGINWIDTHN = 2242,

		//! This message returns the width of a margin in pixels.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//!
		//! \sa SCI_SETMARGINWIDTHN
		SCI_GETMARGINWIDTHN = 2243,

		//! This message sets the mask of a margin.  The mask is a 32
		//! value with one bit for each possible marker.  If a bit is
		//! set then the corresponding marker is displayed.  By
		//! default, all markers are displayed.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//! \a lParam is the new margin mask.
		//!
		//! \sa SCI_GETMARGINMASKN, SCI_MARKERDEFINE
		SCI_SETMARGINMASKN = 2244,

		//! This message returns the mask of a margin.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//!
		//! \sa SCI_SETMARGINMASKN
		SCI_GETMARGINMASKN = 2245,

		//! This message sets the sensitivity of a margin to mouse
		//! clicks.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//! \a lParam is non-zero to make the margin sensitive to mouse
		//! clicks. When the mouse is clicked the SCN_MARGINCLICK()
		//! signal is emitted.
		//!
		//! \sa SCI_GETMARGINSENSITIVEN, SCN_MARGINCLICK()
		SCI_SETMARGINSENSITIVEN = 2246,

		//! This message returns the sensitivity of a margin to mouse
		//! clicks.
		//! \a wParam is the number of the margin: 0, 1 or 2.
		//!
		//! \sa SCI_SETMARGINSENSITIVEN, SCN_MARGINCLICK()
		SCI_GETMARGINSENSITIVEN = 2247,

		//!
		SCI_STYLECLEARALL = 2050,

		//!
		SCI_STYLESETFORE = 2051,

		//!
		SCI_STYLESETBACK = 2052,

		//!
		SCI_STYLESETBOLD = 2053,

		//!
		SCI_STYLESETITALIC = 2054,

		//!
		SCI_STYLESETSIZE = 2055,

		//!
		SCI_STYLESETFONT = 2056,

		//!
		SCI_STYLESETEOLFILLED = 2057,

		//!
		SCI_STYLERESETDEFAULT = 2058,

		//!
		SCI_STYLESETUNDERLINE = 2059,

		//!
		SCI_STYLESETCASE = 2060,

		//!
		SCI_STYLESETCHARACTERSET = 2066,

		//!
		SCI_SETSELFORE = 2067,

		//!
		SCI_SETSELBACK = 2068,

		//!
		SCI_SETCARETFORE = 2069,

		//!
		SCI_ASSIGNCMDKEY = 2070,

		//!
		SCI_CLEARCMDKEY = 2071,

		//!
		SCI_CLEARALLCMDKEYS = 2072,

		//!
		SCI_SETSTYLINGEX = 2073,

		//!
		SCI_STYLESETVISIBLE = 2074,

		//!
		SCI_GETCARETPERIOD = 2075,

		//!
		SCI_SETCARETPERIOD = 2076,

		//!
		SCI_SETWORDCHARS = 2077,

		//!
		SCI_BEGINUNDOACTION = 2078,

		//!
		SCI_ENDUNDOACTION = 2079,

		//!
		SCI_INDICSETSTYLE = 2080,

		//!
		SCI_INDICGETSTYLE = 2081,

		//!
		SCI_INDICSETFORE = 2082,

		//!
		SCI_INDICGETFORE = 2083,

		//!
		SCI_SETWHITESPACEFORE = 2084,

		//!
		SCI_SETWHITESPACEBACK = 2085,

		//!
		SCI_SETSTYLEBITS = 2090,

		//!
		SCI_GETSTYLEBITS = 2091,

		//!
		SCI_SETLINESTATE = 2092,

		//!
		SCI_GETLINESTATE = 2093,

		//!
		SCI_GETMAXLINESTATE = 2094,

		//!
		SCI_GETCARETLINEVISIBLE = 2095,

		//!
		SCI_SETCARETLINEVISIBLE = 2096,

		//!
		SCI_GETCARETLINEBACK = 2097,

		//!
		SCI_SETCARETLINEBACK = 2098,

		//!
		SCI_STYLESETCHANGEABLE = 2099,

		//!
		SCI_AUTOCSHOW = 2100,

		//!
		SCI_AUTOCCANCEL = 2101,

		//!
		SCI_AUTOCACTIVE = 2102,

		//!
		SCI_AUTOCPOSSTART = 2103,

		//!
		SCI_AUTOCCOMPLETE = 2104,

		//!
		SCI_AUTOCSTOPS = 2105,

		//!
		SCI_AUTOCSETSEPARATOR = 2106,

		//!
		SCI_AUTOCGETSEPARATOR = 2107,

		//!
		SCI_AUTOCSELECT = 2108,

		//!
		SCI_AUTOCSETCANCELATSTART = 2110,

		//!
		SCI_AUTOCGETCANCELATSTART = 2111,

		//!
		SCI_AUTOCSETFILLUPS = 2112,

		//!
		SCI_AUTOCSETCHOOSESINGLE = 2113,

		//!
		SCI_AUTOCGETCHOOSESINGLE = 2114,

		//!
		SCI_AUTOCSETIGNORECASE = 2115,

		//!
		SCI_AUTOCGETIGNORECASE = 2116,

		//!
		SCI_USERLISTSHOW = 2117,

		//!
		SCI_AUTOCSETAUTOHIDE = 2118,

		//!
		SCI_AUTOCGETAUTOHIDE = 2119,

		//!
		SCI_AUTOCSETDROPRESTOFWORD = 2270,

		//!
		SCI_AUTOCGETDROPRESTOFWORD = 2271,

		//!
		SCI_SETINDENT = 2122,

		//!
		SCI_GETINDENT = 2123,

		//!
		SCI_SETUSETABS = 2124,

		//!
		SCI_GETUSETABS = 2125,

		//!
		SCI_SETLINEINDENTATION = 2126,

		//!
		SCI_GETLINEINDENTATION = 2127,

		//!
		SCI_GETLINEINDENTPOSITION = 2128,

		//!
		SCI_GETCOLUMN = 2129,

		//!
		SCI_SETHSCROLLBAR = 2130,

		//!
		SCI_GETHSCROLLBAR = 2131,

		//!
		SCI_SETINDENTATIONGUIDES = 2132,

		//!
		SCI_GETINDENTATIONGUIDES = 2133,

		//!
		SCI_SETHIGHLIGHTGUIDE = 2134,

		//!
		SCI_GETHIGHLIGHTGUIDE = 2135,

		//!
		SCI_GETLINEENDPOSITION = 2136,

		//!
		SCI_GETCODEPAGE = 2137,

		//!
		SCI_GETCARETFORE = 2138,

		//!
		SCI_GETUSEPALETTE = 2139,

		//! This message returns a non-zero value if the document is
		//! read-only.
		//! 
		//! \sa SCI_SETREADONLY
		SCI_GETREADONLY = 2140,

		//! This message sets the current position.
		//! \a wParam is the new current position.
		//! 
		//! \sa SCI_GETCURRENTPOS
		SCI_SETCURRENTPOS = 2141,

		//!
		SCI_SETSELECTIONSTART = 2142,

		//!
		SCI_GETSELECTIONSTART = 2143,

		//!
		SCI_SETSELECTIONEND = 2144,

		//!
		SCI_GETSELECTIONEND = 2145,

		//!
		SCI_SETPRINTMAGNIFICATION = 2146,

		//!
		SCI_GETPRINTMAGNIFICATION = 2147,

		//!
		SCI_SETPRINTCOLOURMODE = 2148,

		//!
		SCI_GETPRINTCOLOURMODE = 2149,

		//!
		SCI_FINDTEXT = 2150,

		//!
		SCI_FORMATRANGE = 2151,

		//!
		SCI_GETFIRSTVISIBLELINE = 2152,

		//!
		SCI_GETLINE = 2153,

		//!
		SCI_GETLINECOUNT = 2154,

		//!
		SCI_SETMARGINLEFT = 2155,

		//!
		SCI_GETMARGINLEFT = 2156,

		//!
		SCI_SETMARGINRIGHT = 2157,

		//!
		SCI_GETMARGINRIGHT = 2158,

		//! This message returns a non-zero value if the document has
		//! been modified.
		SCI_GETMODIFY = 2159,

		//!
		SCI_SETSEL = 2160,

		//!
		SCI_GETSELTEXT = 2161,

		//!
		SCI_GETTEXTRANGE = 2162,

		//!
		SCI_HIDESELECTION = 2163,

		//!
		SCI_POINTXFROMPOSITION = 2164,

		//!
		SCI_POINTYFROMPOSITION = 2165,

		//!
		SCI_LINEFROMPOSITION = 2166,

		//!
		SCI_POSITIONFROMLINE = 2167,

		//!
		SCI_LINESCROLL = 2168,

		//!
		SCI_SCROLLCARET = 2169,

		//!
		SCI_REPLACESEL = 2170,

		//! This message sets the read-only state of the document.
		//! \a wParam is the new read-only state of the document.
		//! 
		//! \sa SCI_GETREADONLY
		SCI_SETREADONLY = 2171,

		//!
		SCI_NULL = 2172,

		//!
		SCI_CANPASTE = 2173,

		//!
		SCI_CANUNDO = 2174,

		//! This message empties the undo buffer.
		SCI_EMPTYUNDOBUFFER = 2175,

		//!
		SCI_UNDO = 2176,

		//!
		SCI_CUT = 2177,

		//!
		SCI_COPY = 2178,

		//!
		SCI_PASTE = 2179,

		//!
		SCI_CLEAR = 2180,

		//! This message sets the text of the document.
		//! \a wParam is unused.
		//! \a lParam is the new text of the document.
		//! 
		//! \sa SCI_GETTEXT
		SCI_SETTEXT = 2181,

		//! This message gets the text of the document.
		//! \a wParam is size of the buffer that the text is copied to.
		//! \a lParam is the address of the buffer that the text is
		//! copied to.
		//! 
		//! \sa SCI_SETTEXT
		SCI_GETTEXT = 2182,

		//! This message returns the length of the document.
		SCI_GETTEXTLENGTH = 2183,

		//!
		SCI_GETDIRECTFUNCTION = 2184,

		//!
		SCI_GETDIRECTPOINTER = 2185,

		//!
		SCI_SETOVERTYPE = 2186,

		//!
		SCI_GETOVERTYPE = 2187,

		//!
		SCI_SETCARETWIDTH = 2188,

		//!
		SCI_GETCARETWIDTH = 2189,

		//!
		SCI_SETTARGETSTART = 2190,

		//!
		SCI_GETTARGETSTART = 2191,

		//!
		SCI_SETTARGETEND = 2192,

		//!
		SCI_GETTARGETEND = 2193,

		//!
		SCI_REPLACETARGET = 2194,

		//!
		SCI_REPLACETARGETRE = 2195,

		//!
		SCI_SEARCHINTARGET = 2197,

		//!
		SCI_SETSEARCHFLAGS = 2198,

		//!
		SCI_GETSEARCHFLAGS = 2199,

		//!
		SCI_CALLTIPSHOW = 2200,

		//!
		SCI_CALLTIPCANCEL = 2201,

		//!
		SCI_CALLTIPACTIVE = 2202,

		//!
		SCI_CALLTIPPOSSTART = 2203,

		//!
		SCI_CALLTIPSETHLT = 2204,

		//!
		SCI_CALLTIPSETBACK = 2205,

		//!
		SCI_CALLTIPSETFORE = 2206,

		//!
		SCI_CALLTIPSETFOREHLT = 2207,

		//!
		SCI_AUTOCSETMAXWIDTH = 2208,

		//!
		SCI_AUTOCGETMAXWIDTH = 2209,

		//!
		SCI_AUTOCSETMAXHEIGHT = 2210,

		//!
		SCI_AUTOCGETMAXHEIGHT = 2211,

		//!
		SCI_VISIBLEFROMDOCLINE = 2220,

		//!
		SCI_DOCLINEFROMVISIBLE = 2221,

		//!
		SCI_SETFOLDLEVEL = 2222,

		//!
		SCI_GETFOLDLEVEL = 2223,

		//!
		SCI_GETLASTCHILD = 2224,

		//!
		SCI_GETFOLDPARENT = 2225,

		//!
		SCI_SHOWLINES = 2226,

		//!
		SCI_HIDELINES = 2227,

		//!
		SCI_GETLINEVISIBLE = 2228,

		//!
		SCI_SETFOLDEXPANDED = 2229,

		//!
		SCI_GETFOLDEXPANDED = 2230,

		//!
		SCI_TOGGLEFOLD = 2231,

		//!
		SCI_ENSUREVISIBLE = 2232,

		//!
		SCI_SETFOLDFLAGS = 2233,

		//!
		SCI_ENSUREVISIBLEENFORCEPOLICY = 2234,

		//!
		SCI_WRAPCOUNT = 2235,

		//!
		SCI_SETTABINDENTS = 2260,

		//!
		SCI_GETTABINDENTS = 2261,

		//!
		SCI_SETBACKSPACEUNINDENTS = 2262,

		//!
		SCI_GETBACKSPACEUNINDENTS = 2263,

		//!
		SCI_SETMOUSEDWELLTIME = 2264,

		//!
		SCI_GETMOUSEDWELLTIME = 2265,

		//!
		SCI_WORDSTARTPOSITION = 2266,

		//!
		SCI_WORDENDPOSITION = 2267,

		//!
		SCI_SETWRAPMODE = 2268,

		//!
		SCI_GETWRAPMODE = 2269,

		//!
		SCI_SETLAYOUTCACHE = 2272,

		//!
		SCI_GETLAYOUTCACHE = 2273,

		//!
		SCI_SETSCROLLWIDTH = 2274,

		//!
		SCI_GETSCROLLWIDTH = 2275,

		//! This message returns the width of some text when rendered
		//! in a particular style.
		//! \a wParam is the style number and is one of the STYLE_*
		//! values or one of the styles defined by a lexer.
		//! \a lParam is a pointer to the text.
		SCI_TEXTWIDTH = 2276,

		//!
		SCI_SETENDATLASTLINE = 2277,

		//!
		SCI_GETENDATLASTLINE = 2278,

		//!
		SCI_TEXTHEIGHT = 2279,

		//!
		SCI_SETVSCROLLBAR = 2280,

		//!
		SCI_GETVSCROLLBAR = 2281,

		//!
		SCI_APPENDTEXT = 2282,

		//!
		SCI_GETTWOPHASEDRAW = 2283,

		//!
		SCI_SETTWOPHASEDRAW = 2284,

		//!
		SCI_AUTOCGETTYPESEPARATOR = 2285,

		//!
		SCI_AUTOCSETTYPESEPARATOR = 2286,

		//!
		SCI_TARGETFROMSELECTION = 2287,

		//!
		SCI_LINESJOIN = 2288,

		//!
		SCI_LINESSPLIT = 2289,

		//!
		SCI_SETFOLDMARGINCOLOUR = 2290,

		//!
		SCI_SETFOLDMARGINHICOLOUR = 2291,

		//!
		SCI_LINEDOWN = 2300,

		//!
		SCI_LINEDOWNEXTEND = 2301,

		//!
		SCI_LINEUP = 2302,

		//!
		SCI_LINEUPEXTEND = 2303,

		//!
		SCI_CHARLEFT = 2304,

		//!
		SCI_CHARLEFTEXTEND = 2305,

		//!
		SCI_CHARRIGHT = 2306,

		//!
		SCI_CHARRIGHTEXTEND = 2307,

		//!
		SCI_WORDLEFT = 2308,

		//!
		SCI_WORDLEFTEXTEND = 2309,

		//!
		SCI_WORDRIGHT = 2310,

		//!
		SCI_WORDRIGHTEXTEND = 2311,

		//!
		SCI_HOME = 2312,

		//!
		SCI_HOMEEXTEND = 2313,

		//!
		SCI_LINEEND = 2314,

		//!
		SCI_LINEENDEXTEND = 2315,

		//!
		SCI_DOCUMENTSTART = 2316,

		//!
		SCI_DOCUMENTSTARTEXTEND = 2317,

		//!
		SCI_DOCUMENTEND = 2318,

		//!
		SCI_DOCUMENTENDEXTEND = 2319,

		//!
		SCI_PAGEUP = 2320,

		//!
		SCI_PAGEUPEXTEND = 2321,

		//!
		SCI_PAGEDOWN = 2322,

		//!
		SCI_PAGEDOWNEXTEND = 2323,

		//!
		SCI_EDITTOGGLEOVERTYPE = 2324,

		//!
		SCI_CANCEL = 2325,

		//!
		SCI_DELETEBACK = 2326,

		//!
		SCI_TAB = 2327,

		//!
		SCI_BACKTAB = 2328,

		//!
		SCI_NEWLINE = 2329,

		//!
		SCI_FORMFEED = 2330,

		//!
		SCI_VCHOME = 2331,

		//!
		SCI_VCHOMEEXTEND = 2332,

		//!
		SCI_ZOOMIN = 2333,

		//!
		SCI_ZOOMOUT = 2334,

		//!
		SCI_DELWORDLEFT = 2335,

		//!
		SCI_DELWORDRIGHT = 2336,

		//!
		SCI_LINECUT = 2337,

		//!
		SCI_LINEDELETE = 2338,

		//!
		SCI_LINETRANSPOSE = 2339,

		//!
		SCI_LOWERCASE = 2340,

		//!
		SCI_UPPERCASE = 2341,

		//!
		SCI_LINESCROLLDOWN = 2342,

		//!
		SCI_LINESCROLLUP = 2343,

		//!
		SCI_DELETEBACKNOTLINE = 2344,

		//!
		SCI_HOMEDISPLAY = 2345,

		//!
		SCI_HOMEDISPLAYEXTEND = 2346,

		//!
		SCI_LINEENDDISPLAY = 2347,

		//!
		SCI_LINEENDDISPLAYEXTEND = 2348,

		//!
		SCI_MOVECARETINSIDEVIEW = 2401,

		//!
		SCI_LINELENGTH = 2350,

		//!
		SCI_BRACEHIGHLIGHT = 2351,

		//!
		SCI_BRACEBADLIGHT = 2352,

		//!
		SCI_BRACEMATCH = 2353,

		//!
		SCI_GETVIEWEOL = 2355,

		//!
		SCI_SETVIEWEOL = 2356,

		//!
		SCI_GETDOCPOINTER = 2357,

		//!
		SCI_SETDOCPOINTER = 2358,

		//!
		SCI_SETMODEVENTMASK = 2359,

		//!
		SCI_GETEDGECOLUMN = 2360,

		//!
		SCI_SETEDGECOLUMN = 2361,

		//!
		SCI_GETEDGEMODE = 2362,

		//!
		SCI_SETEDGEMODE = 2363,

		//!
		SCI_GETEDGECOLOUR = 2364,

		//!
		SCI_SETEDGECOLOUR = 2365,

		//!
		SCI_SEARCHANCHOR = 2366,

		//!
		SCI_SEARCHNEXT = 2367,

		//!
		SCI_SEARCHPREV = 2368,

		//!
		SCI_LINESONSCREEN = 2370,

		//!
		SCI_USEPOPUP = 2371,

		//!
		SCI_SELECTIONISRECTANGLE = 2372,

		//!
		SCI_SETZOOM = 2373,

		//!
		SCI_GETZOOM = 2374,

		//!
		SCI_CREATEDOCUMENT = 2375,

		//!
		SCI_ADDREFDOCUMENT = 2376,

		//!
		SCI_RELEASEDOCUMENT = 2377,

		//!
		SCI_GETMODEVENTMASK = 2378,

		//!
		SCI_SETFOCUS = 2380,

		//!
		SCI_GETFOCUS = 2381,

		//!
		SCI_SETSTATUS = 2382,

		//!
		SCI_GETSTATUS = 2383,

		//!
		SCI_SETMOUSEDOWNCAPTURES = 2384,

		//!
		SCI_GETMOUSEDOWNCAPTURES = 2385,

		//!
		SCI_SETCURSOR = 2386,

		//!
		SCI_GETCURSOR = 2387,

		//!
		SCI_SETCONTROLCHARSYMBOL = 2388,

		//!
		SCI_GETCONTROLCHARSYMBOL = 2389,

		//!
		SCI_WORDPARTLEFT = 2390,

		//!
		SCI_WORDPARTLEFTEXTEND = 2391,

		//!
		SCI_WORDPARTRIGHT = 2392,

		//!
		SCI_WORDPARTRIGHTEXTEND = 2393,

		//!
		SCI_SETVISIBLEPOLICY = 2394,

		//!
		SCI_DELLINELEFT = 2395,

		//!
		SCI_DELLINERIGHT = 2396,

		//!
		SCI_SETXOFFSET = 2397,

		//!
		SCI_GETXOFFSET = 2398,

		//!
		SCI_CHOOSECARETX = 2399,

		//!
		SCI_GRABFOCUS = 2400,

		//!
		SCI_SETXCARETPOLICY = 2402,

		//!
		SCI_SETYCARETPOLICY = 2403,

		//!
		SCI_LINEDUPLICATE = 2404,

		//! This message takes a copy of an image and registers it so
		//! that it can be refered to by a unique integer identifier.
		//! \a wParam is the image's identifier.
		//! \a lParam is a pointer to a QPixmap instance.  Note that in
		//! other ports of Scintilla this is a pointer to either raw or
		//! textual XPM image data.
		//!
		//! \sa SCI_CLEARREGISTEREDIMAGES
		SCI_REGISTERIMAGE = 2405,

		//!
		SCI_SETPRINTWRAPMODE = 2406,

		//!
		SCI_GETPRINTWRAPMODE = 2407,

		//! This message de-registers all currently registered images.
		//!
		//! \sa SCI_REGISTERIMAGE
		SCI_CLEARREGISTEREDIMAGES = 2408,

		//!
		SCI_STYLESETHOTSPOT = 2409,

		//!
		SCI_SETHOTSPOTACTIVEFORE = 2410,

		//!
		SCI_SETHOTSPOTACTIVEBACK = 2411,

		//!
		SCI_SETHOTSPOTACTIVEUNDERLINE = 2412,

		//!
		SCI_PARADOWN = 2413,

		//!
		SCI_PARADOWNEXTEND = 2414,

		//!
		SCI_PARAUP = 2415,

		//!
		SCI_PARAUPEXTEND = 2416,

		//!
		SCI_POSITIONBEFORE = 2417,

		//!
		SCI_POSITIONAFTER = 2418,

		//!
		SCI_COPYRANGE = 2419,

		//!
		SCI_COPYTEXT = 2420,

		//!
		SCI_SETSELECTIONMODE = 2422,

		//!
		SCI_GETSELECTIONMODE = 2423,

		//!
		SCI_GETLINESELSTARTPOSITION = 2424,

		//!
		SCI_GETLINESELENDPOSITION = 2425,

		//!
		SCI_LINEDOWNRECTEXTEND = 2426,

		//!
		SCI_LINEUPRECTEXTEND = 2427,

		//!
		SCI_CHARLEFTRECTEXTEND = 2428,

		//!
		SCI_CHARRIGHTRECTEXTEND = 2429,

		//!
		SCI_HOMERECTEXTEND = 2430,

		//!
		SCI_VCHOMERECTEXTEND = 2431,

		//!
		SCI_LINEENDRECTEXTEND = 2432,

		//!
		SCI_PAGEUPRECTEXTEND = 2433,

		//!
		SCI_PAGEDOWNRECTEXTEND = 2434,

		//!
		SCI_STUTTEREDPAGEUP = 2435,

		//!
		SCI_STUTTEREDPAGEUPEXTEND = 2436,

		//!
		SCI_STUTTEREDPAGEDOWN = 2437,

		//!
		SCI_STUTTEREDPAGEDOWNEXTEND = 2438,

		//!
		SCI_WORDLEFTEND = 2439,

		//!
		SCI_WORDLEFTENDEXTEND = 2440,

		//!
		SCI_WORDRIGHTEND = 2441,

		//!
		SCI_WORDRIGHTENDEXTEND = 2442,

		//!
		SCI_SETWHITESPACECHARS = 2443,

		//!
		SCI_SETCHARSDEFAULT = 2444,

		//!
		SCI_AUTOCGETCURRENT = 2445,

		//!
		SCI_ALLOCATE = 2446,

		//!
		SCI_HOMEWRAP = 2349,

		//!
		SCI_HOMEWRAPEXTEND = 2450,

		//!
		SCI_LINEENDWRAP = 2451,

		//!
		SCI_LINEENDWRAPEXTEND = 2452,

		//!
		SCI_VCHOMEWRAP = 2453,

		//!
		SCI_VCHOMEWRAPEXTEND = 2454,

		//!
		SCI_LINECOPY = 2455,

		//!
		SCI_FINDCOLUMN = 2456,

		//!
		SCI_GETCARETSTICKY = 2457,

		//!
		SCI_SETCARETSTICKY = 2458,

		//!
		SCI_TOGGLECARETSTICKY = 2459,

		//!
		SCI_SETWRAPVISUALFLAGS = 2460,

		//!
		SCI_GETWRAPVISUALFLAGS = 2461,

		//!
		SCI_SETWRAPVISUALFLAGSLOCATION = 2462,

		//!
		SCI_GETWRAPVISUALFLAGSLOCATION = 2463,

		//!
		SCI_SETWRAPSTARTINDENT = 2464,

		//!
		SCI_GETWRAPSTARTINDENT = 2465,

		//!
		SCI_STARTRECORD = 3001,

		//!
		SCI_STOPRECORD = 3002,

		//! This message sets the number of the lexer to use for syntax
		//! styling.
		//! \a wParam is the number of the lexer and is one of the
		//! SCLEX_* values.
		SCI_SETLEXER = 4001,

		//! This message returns the number of the lexer being used for
		//! syntax styling.
		SCI_GETLEXER = 4002,

		//!
		SCI_COLOURISE = 4003,

		//!
		SCI_SETPROPERTY = 4004,

		//!
		SCI_SETKEYWORDS = 4005,

		//! This message sets the name of the lexer to use for syntax
		//! styling.
		//! \a wParam is unused.
		//! \a lParam is the name of the lexer.
		SCI_SETLEXERLANGUAGE = 4006,

		//!
		SCI_LOADLEXERLIBRARY = 4007,

		//!
		SCI_GETPROPERTY = 4008,

		//!
		SCI_GETPROPERTYEXPANDED = 4009,

		//!
		SCI_GETPROPERTYINT = 4010,
	};

	enum
	{
		SC_WRAPVISUALFLAG_NONE = 0x0000,
		SC_WRAPVISUALFLAG_END = 0x0001,
		SC_WRAPVISUALFLAG_START = 0x0002
	};

	enum
	{
		SC_WRAPVISUALFLAGLOC_DEFAULT = 0x0000,
		SC_WRAPVISUALFLAGLOC_END_BY_TEXT = 0x0001,
		SC_WRAPVISUALFLAGLOC_START_BY_TEXT = 0x0002
	};

	//! This enum defines the different selection modes.
	//!
	//! \sa SCI_GETSELECTIONMODE, SCI_SETSELECTIONMODE
	enum
	{
		SC_SEL_STREAM = 0,
		SC_SEL_RECTANGLE = 1,
		SC_SEL_LINES = 2
	};

	enum
	{
		SCWS_INVISIBLE = 0,
		SCWS_VISIBLEALWAYS = 1,
		SCWS_VISIBLEAFTERINDENT = 2
	};

	enum
	{
		SC_EOL_CRLF = 0,
		SC_EOL_CR = 1,
		SC_EOL_LF = 2
	};

	enum
	{
		SC_CP_DBCS = 1,
		SC_CP_UTF8 = 65001
	};

	//! This enum defines the different marker symbols.
	//!
	//! \sa SCI_MARKERDEFINE
	enum
	{
		//! A circle.
		SC_MARK_CIRCLE = 0,

		//! A rectangle.
		SC_MARK_ROUNDRECT = 1,

		//! A triangle pointing to the right.
		SC_MARK_ARROW = 2,

		//! A smaller rectangle.
		SC_MARK_SMALLRECT = 3,

		//! An arrow pointing to the right.
		SC_MARK_SHORTARROW = 4,

		//! An invisible marker that allows code to track the movement
		//! of lines.
		SC_MARK_EMPTY = 5,

		//! A triangle pointing down.
		SC_MARK_ARROWDOWN = 6,

		//! A drawn minus sign.
		SC_MARK_MINUS = 7,

		//! A drawn plus sign.
		SC_MARK_PLUS = 8,

		//! A vertical line drawn in the background colour.
		SC_MARK_VLINE = 9,

		//! A bottom left corner drawn in the background colour.
		SC_MARK_LCORNER = 10,

		//! A vertical line with a centre right horizontal line drawn
		//! in the background colour.
		SC_MARK_TCORNER = 11,

		//! A drawn plus sign in a box.
		SC_MARK_BOXPLUS = 12,

		//! A drawn plus sign in a connected box.
		SC_MARK_BOXPLUSCONNECTED = 13,

		//! A drawn minus sign in a box.
		SC_MARK_BOXMINUS = 14,

		//! A drawn minus sign in a connected box.
		SC_MARK_BOXMINUSCONNECTED = 15,

		//! A rounded bottom left corner drawn in the background
		//! colour.
		SC_MARK_LCORNERCURVE = 16,

		//! A vertical line with a centre right curved line drawn in
		//! the background colour.
		SC_MARK_TCORNERCURVE = 17,

		//! A drawn plus sign in a circle.
		SC_MARK_CIRCLEPLUS = 18,

		//! A drawn plus sign in a connected box.
		SC_MARK_CIRCLEPLUSCONNECTED = 19,

		//! A drawn minus sign in a circle.
		SC_MARK_CIRCLEMINUS = 20,

		//! A drawn minus sign in a connected circle.
		SC_MARK_CIRCLEMINUSCONNECTED = 21,

		//! No symbol is drawn but the line of text is drawn with the
		//! same background colour.
		SC_MARK_BACKGROUND = 22,

		//! Three drawn dots.
		SC_MARK_DOTDOTDOT = 23,

		//! Three drawn arrows pointing right.
		SC_MARK_ARROWS = 24,

		//! An XPM format pixmap.
		SC_MARK_PIXMAP = 25,

		//! A full rectangle.
		SC_MARK_FULLRECT = 26,

		//! Characters can be used as symbols by adding this to the
		//! ASCII value of the character.
		SC_MARK_CHARACTER = 10000
	};

	enum
	{
		SC_MARKNUM_FOLDEREND = 25,
		SC_MARKNUM_FOLDEROPENMID = 26,
		SC_MARKNUM_FOLDERMIDTAIL = 27,
		SC_MARKNUM_FOLDERTAIL = 28,
		SC_MARKNUM_FOLDERSUB = 29,
		SC_MARKNUM_FOLDER = 30,
		SC_MARKNUM_FOLDEROPEN = 31,
		SC_MASK_FOLDERS = 0xfe000000
	};

	//! This enum defines what can be displayed in a margin.
	//!
	//! \sa SCI_GETMARGINTYPEN, SCI_SETMARGINTYPEN
	enum
	{
		//! The margin can display symbols.  Note that all margins can
		//! display symbols.
		SC_MARGIN_SYMBOL = 0,

		//! The margin will display line numbers.
		SC_MARGIN_NUMBER = 1
	};

	enum
	{
		STYLE_DEFAULT = 32,
		STYLE_LINENUMBER = 33,
		STYLE_BRACELIGHT = 34,
		STYLE_BRACEBAD = 35,
		STYLE_CONTROLCHAR = 36,
		STYLE_INDENTGUIDE = 37,
		STYLE_LASTPREDEFINED = 39,
		STYLE_MAX = 127
	};

	enum
	{
		SC_CHARSET_ANSI = 0,
		SC_CHARSET_DEFAULT = 1,
		SC_CHARSET_BALTIC = 186,
		SC_CHARSET_CHINESEBIG5 = 136,
		SC_CHARSET_EASTEUROPE = 238,
		SC_CHARSET_GB2312 = 134,
		SC_CHARSET_GREEK = 161,
		SC_CHARSET_HANGUL = 129,
		SC_CHARSET_MAC = 77,
		SC_CHARSET_OEM = 255,
		SC_CHARSET_RUSSIAN = 204,
		SC_CHARSET_SHIFTJIS = 128,
		SC_CHARSET_SYMBOL = 2,
		SC_CHARSET_TURKISH = 162,
		SC_CHARSET_JOHAB = 130,
		SC_CHARSET_HEBREW = 177,
		SC_CHARSET_ARABIC = 178,
		SC_CHARSET_VIETNAMESE = 163,
		SC_CHARSET_THAI = 222,
		SC_CHARSET_8859_15 = 1000,
	};

	enum
	{
		SC_CASE_MIXED = 0,
		SC_CASE_UPPER = 1,
		SC_CASE_LOWER = 2
	};

	enum
	{
		INDIC_MAX = 7,
		INDIC_PLAIN = 0,
		INDIC_SQUIGGLE = 1,
		INDIC_TT = 2,
		INDIC_DIAGONAL = 3,
		INDIC_STRIKE = 4,
		INDIC_HIDDEN = 5,
		INDIC_BOX = 6,
		INDIC0_MASK = 0x20,
		INDIC1_MASK = 0x40,
		INDIC2_MASK = 0x80,
		INDICS_MASK = 0xe0
	};

	enum
	{
		SC_PRINT_NORMAL = 0,
		SC_PRINT_INVERTLIGHT = 1,
		SC_PRINT_BLACKONWHITE = 2,
		SC_PRINT_COLOURONWHITE = 3,
		SC_PRINT_COLOURONWHITEDEFAULTBG = 4
	};

	enum
	{
		SCFIND_WHOLEWORD = 2,
		SCFIND_MATCHCASE = 4,
		SCFIND_WORDSTART = 0x00100000,
		SCFIND_REGEXP = 0x00200000,
		SCFIND_POSIX = 0x00400000
	};

	enum
	{
		SC_FOLDLEVELBASE = 0x00400,
		SC_FOLDLEVELWHITEFLAG = 0x01000,
		SC_FOLDLEVELHEADERFLAG = 0x02000,
		SC_FOLDLEVELBOXHEADERFLAG = 0x04000,
		SC_FOLDLEVELBOXFOOTERFLAG = 0x08000,
		SC_FOLDLEVELCONTRACTED = 0x10000,
		SC_FOLDLEVELUNINDENT = 0x20000,
		SC_FOLDLEVELNUMBERMASK = 0x00fff
	};

	enum
	{
		SC_FOLDFLAG_BOX = 0x0001,
		SC_FOLDFLAG_LINEBEFORE_EXPANDED = 0x0002,
		SC_FOLDFLAG_LINEBEFORE_CONTRACTED = 0x0004,
		SC_FOLDFLAG_LINEAFTER_EXPANDED = 0x0008,
		SC_FOLDFLAG_LINEAFTER_CONTRACTED = 0x0010,
		SC_FOLDFLAG_LEVELNUMBERS = 0x0040
	};

	enum
	{
		SC_TIME_FOREVER = 10000000
	};

	enum
	{
		SC_WRAP_NONE = 0,
		SC_WRAP_WORD = 1,
		SC_WRAP_CHAR = 2
	};

	enum
	{
		SC_CACHE_NONE = 0,
		SC_CACHE_CARET = 1,
		SC_CACHE_PAGE = 2,
		SC_CACHE_DOCUMENT = 3
	};

	enum
	{
		EDGE_NONE = 0,
		EDGE_LINE = 1,
		EDGE_BACKGROUND = 2
	};

	enum
	{
		SC_CURSORNORMAL = -1,
		SC_CURSORWAIT = 4
	};

	enum
	{
		VISIBLE_SLOP = 0x01,
		VISIBLE_STRICT = 0x04
	};

	enum
	{
		CARET_SLOP = 0x01,
		CARET_STRICT = 0x04,
		CARET_JUMPS = 0x10,
		CARET_EVEN = 0x08
	};

	enum
	{
		SC_MOD_INSERTTEXT = 0x1,
		SC_MOD_DELETETEXT = 0x2,
		SC_MOD_CHANGESTYLE = 0x4,
		SC_MOD_CHANGEFOLD = 0x8,
		SC_PERFORMED_USER = 0x10,
		SC_PERFORMED_UNDO = 0x20,
		SC_PERFORMED_REDO = 0x40,
		SC_MULTISTEPUNDOREDO = 0x80,
		SC_LASTSTEPINUNDOREDO = 0x100,
		SC_MOD_CHANGEMARKER = 0x200,
		SC_MOD_BEFOREINSERT = 0x400,
		SC_MOD_BEFOREDELETE = 0x800,
		SC_MULTILINEUNDOREDO = 0x1000,
		SC_MODEVENTMASKALL = 0x1fff
	};

	enum
	{
		SCK_DOWN = 300,
		SCK_UP = 301,
		SCK_LEFT = 302,
		SCK_RIGHT = 303,
		SCK_HOME = 304,
		SCK_END = 305,
		SCK_PRIOR = 306,
		SCK_NEXT = 307,
		SCK_DELETE = 308,
		SCK_INSERT = 309,
		SCK_ESCAPE = 7,
		SCK_BACK = 8,
		SCK_TAB = 9,
		SCK_RETURN = 13,
		SCK_ADD = 310,
		SCK_SUBTRACT = 311,
		SCK_DIVIDE = 312
	};

	//! This enum defines the different modifier keys.
	enum
	{
		//! Shift key.
		SCMOD_SHIFT = 1,

		//! Control key.
		SCMOD_CTRL = 2,

		//! Alt key.
		SCMOD_ALT = 4
	};

	//! This enum defines the different language lexers.
	//!
	//! \sa SCI_GETLEXER, SCI_SETLEXER
	enum
	{
		//! No lexer is selected and the SCN_STYLENEEDED signal is
		//! emitted so that the application can style the text as
		//! needed.  This is the default.
		SCLEX_CONTAINER = 0,

		//! Select the null lexer that does no syntax styling.
		SCLEX_NULL = 1,

		//! Select the Python lexer.
		SCLEX_PYTHON = 2,

		//! Select the C++ lexer.
		SCLEX_CPP = 3,

		//! Select the HTML lexer.
		SCLEX_HTML = 4,

		//! Select the XML lexer.
		SCLEX_XML = 5,

		//! Select the Perl lexer.
		SCLEX_PERL = 6,

		//! Select the SQL lexer.
		SCLEX_SQL = 7,

		//! Select the Visual Basic lexer.
		SCLEX_VB = 8,

		//! Select the lexer for properties style files.
		SCLEX_PROPERTIES = 9,

		//! Select the lexer for error list style files.
		SCLEX_ERRORLIST = 10,

		//! Select the Makefile lexer.
		SCLEX_MAKEFILE = 11,

		//! Select the Windows batch file lexer.
		SCLEX_BATCH = 12,

		//! Select the LaTex lexer.
		SCLEX_LATEX = 14,

		//! Select the Lua lexer.
		SCLEX_LUA = 15,

		//! Select the lexer for diff output.
		SCLEX_DIFF = 16,

		//! Select the lexer for Apache configuration files.
		SCLEX_CONF = 17,

		//! Select the Pascal lexer.
		SCLEX_PASCAL = 18,

		//! Select the Avenue lexer.
		SCLEX_AVE = 19,

		//! Select the Ada lexer.
		SCLEX_ADA = 20,

		//! Select the Lisp lexer.
		SCLEX_LISP = 21,

		//! Select the Ruby lexer.
		SCLEX_RUBY = 22,

		//! Select the Eiffel lexer.
		SCLEX_EIFFEL = 23,

		//! Select the Eiffel lexer folding at keywords.
		SCLEX_EIFFELKW = 24,

		//! Select the Tcl lexer.
		SCLEX_TCL = 25,

		//! Select the lexer for nnCron files.
		SCLEX_NNCRONTAB = 26,

		//! Select the Bullant lexer.
		SCLEX_BULLANT = 27,

		//! Select the VBScript lexer.
		SCLEX_VBSCRIPT = 28,

		//! Select the ASP lexer.
		SCLEX_ASP = SCLEX_HTML,

		//! Select the PHP lexer.
		SCLEX_PHP = SCLEX_HTML,

		//! Select the Baan lexer.
		SCLEX_BAAN = 31,

		//! Select the Matlab lexer.
		SCLEX_MATLAB = 32,

		//! Select the Scriptol lexer.
		SCLEX_SCRIPTOL = 33,

		//! Select the assembler lexer.
		SCLEX_ASM = 34,

		//! Select the C++ lexer with case insensitive keywords.
		SCLEX_CPPNOCASE = 35,

		//! Select the FORTRAN lexer.
		SCLEX_FORTRAN = 36,

		//! Select the FORTRAN77 lexer.
		SCLEX_F77 = 37,

		//! Select the CSS lexer.
		SCLEX_CSS = 38,

		//! Select the POV lexer.
		SCLEX_POV = 39,

		//! Select the Basser Lout typesetting language lexer.
		SCLEX_LOUT = 40,

		//! Select the EScript lexer.
		SCLEX_ESCRIPT = 41,

		//! Select the PostScript lexer.
		SCLEX_PS = 42,

		//! Select the NSIS lexer.
		SCLEX_NSIS = 43,

		//! Select the MMIX assembly language lexer.
		SCLEX_MMIXAL = 44,

		//! Select the Clarion lexer.
		SCLEX_CLW = 45,

		//! Select the Clarion lexer with case insensitive keywords.
		SCLEX_CLWNOCASE = 46,

		//! Select the MPT text log file lexer.
		SCLEX_LOT = 47,

		//! Select the YAML lexer.
		SCLEX_YAML = 48,

		//! Select the TeX lexer.
		SCLEX_TEX = 49,

		//! Select the Metapost lexer.
		SCLEX_METAPOST = 50,

		//! Select the PowerBASIC lexer.
		SCLEX_POWERBASIC = 51,

		//! Select the Forth lexer.
		SCLEX_FORTH = 52,

		//! Select the Erlang lexer.
		SCLEX_ERLANG = 53,

		//! Select the Octave lexer.
		SCLEX_OCTAVE = 54,

		//! Select the MS SQL lexer.
		SCLEX_MSSQL = 55,

		//! Select the Verilog lexer.
		SCLEX_VERILOG = 56,

		//! Select the KIX-Scripts lexer.
		SCLEX_KIX = 57,

		//! Select the Gui4Cli lexer.
		SCLEX_GUI4CLI = 58,

		//! Select the Specman E lexer.
		SCLEX_SPECMAN = 59,

		//! Select the AutoIt3 lexer.
		SCLEX_AU3 = 60,

		//! Select the APDL lexer.
		SCLEX_APDL = 61,

		//! Select the Bash lexer.
		SCLEX_BASH = 62,

		//! Select the ASN.1 lexer.
		SCLEX_ASN1 = 63,

		//! Select the VHDL lexer.
		SCLEX_VHDL = 64,

		//! Select the Caml lexer.
		SCLEX_CAML = 65,

		//! Select the BlitzBasic lexer.
		SCLEX_BLITZBASIC = 66,

		//! Select the PureBasic lexer.
		SCLEX_PUREBASIC = 67,

		//! Select the Haskell lexer.
		SCLEX_HASKELL = 68,

		//! Select the PHPScript lexer.
		SCLEX_PHPSCRIPT = 69,

		//! Select the TADS3 lexer.
		SCLEX_TADS3 = 70,

		//! Select the REBOL lexer.
		SCLEX_REBOL = 71,

		//! Select the Smalltalk lexer.
		SCLEX_SMALLTALK = 72,

		//! Select the FlagShip lexer.
		SCLEX_FLAGSHIP = 73,

		//! Select the Csound lexer.
		SCLEX_CSOUND = 74,
	};

	//! Construct an empty QextScintillaBase with parent \a parent, name
	//! \a name, and widget flags \a f.
	QextScintillaBase(QWidget *parent = 0,const char *name = 0,
			  WFlags f = 0);

	//! Destroys the QextScintillaBase instance.
	virtual ~QextScintillaBase();

	//! Returns a pointer to a QextScintillaBase instance, or 0 if there
	//! isn't one.  This can be used by the higher level API to send
	//! messages that aren't associated with a particular instance.
	static QextScintillaBase *pool();

	//! Send the Scintilla message \a msg with the optional parameters \a
	//! wParam and \a lParam.
	long SendScintilla(unsigned int msg,unsigned long wParam = 0,
			   long lParam = 0);

	//! \overload
	long SendScintilla(unsigned int msg,unsigned long wParam,
			   const char *lParam)
	{
		return SendScintilla(msg,wParam,reinterpret_cast<long>(lParam));
	}

	//! \overload
	long SendScintilla(unsigned int msg,const char *lParam)
	{
		return SendScintilla(msg,0UL,reinterpret_cast<long>(lParam));
	}

	//! \overload
	long SendScintilla(unsigned int msg,const char *wParam,
			   const char *lParam)
	{
		return SendScintilla(msg,reinterpret_cast<unsigned long>(wParam),reinterpret_cast<long>(lParam));
	}

	//! \overload
	long SendScintilla(unsigned int msg,long cpMin,long cpMax,
			   char *lpstrText);

	//! \overload
	long SendScintilla(unsigned int msg,unsigned long wParam,
			   const QColor &col);

	//! \overload
	long SendScintilla(unsigned int msg,const QColor &col);

	//! \overload
	long SendScintilla(unsigned int msg,unsigned long wParam,QPainter *hdc,
			   const QRect &rc,long cpMin,long cpMax);

	//! \overload
	long SendScintilla(unsigned int msg,unsigned long wParam,
			   const QPixmap *lParam)
	{
		return SendScintilla(msg,wParam,reinterpret_cast<long>(lParam));
	}

	//! Returns the recommended size of the widget.
	virtual QSize sizeHint() const;

	//! Returns the viewport widget.  This is the widget that actually
	//! contains the text.
	QWidget *viewport() const;

signals:
	//! This signal is emitted when text is selected or de-selected.
	//! \a yes is TRUE if text has been selected and FALSE if text has been
	//! deselected.
	void QSCN_SELCHANGED(bool yes);

	//! This signal is emitted when the user selects an item in an
	//! auto-completion list.  It is emitted before the selection is
	//! inserted.  The insertion can be cancelled by sending an
	//! SCI_AUTOCANCEL message from a connected slot.
	//! \a position is the start position of the word being completed.
	//! \a selection is the text of the selection.
	void SCN_AUTOCSELECTION(const char *selection,int position);

	//! This signal is emitted when the document has changed for any
	//! reason.
	void SCEN_CHANGE();

	//! This signal ir emitted when the user clicks on a calltip.
	//! \a position is 1 if the user clicked on the up arrow, 2 if the user
	//! clicked on the down arrow, and 0 if the user clicked elsewhere.
	void SCN_CALLTIPCLICK(int direction);

	//! This signal is emitted whenever the user enters an ordinary
	//! character into the text. \a charadded is the character. It can be
	//! used to decide to display a call tip or an auto-completion list.
	void SCN_CHARADDED(int charadded);

	//!
	void SCN_DOUBLECLICK();

	//!
	void SCN_DWELLEND(int,int,int);

	//!
	void SCN_DWELLSTART(int,int,int);

	//! This signal is emitted when the user clicks on text in a style
	//! with the hotspot attribute set.
	//! \a position is the position in the text where the click occured.
	//! \a modifiers is the logical or of the modifier keys that were
	//! pressed when the user clicked.
	void SCN_HOTSPOTCLICK(int position,int modifiers);

	//! This signal is emitted when the user double clicks on text in a
	//! style with the hotspot attribute set.
	//! \a position is the position in the text where the double click
	//! occured.
	//! \a modifiers is the logical or of the modifier keys that were
	//! pressed when the user double clicked.
	void SCN_HOTSPOTDOUBLECLICK(int position,int modifiers);

	//! This signal is emitted when a recordable editor command has been
	//! executed.
	void SCN_MACRORECORD(unsigned int,unsigned long,long);

	//! This signal is emitted when the user clicks on a sensitive margin.
	//! \a position is the position of the start of the line against which
	//! the user clicked.
	//! \a modifiers is the logical or of the modifier keys that were
	//! pressed when the user clicked.
	//! \a margin is the number of the margin the user clicked in: 0, 1 or
	//! 2.
	//! 
	//! \sa SCI_GETMARGINSENSITIVEN, SCI_SETMARGINSENSITIVEN
	void SCN_MARGINCLICK(int position,int modifiers,int margin);

	//!
	void SCN_MODIFIED(int,int,const char *,int,int,int,int,int);

	//! This signal is emitted when the user attempts to modify read-only
	//! text.
	void SCN_MODIFYATTEMPTRO();

	//!
	void SCN_NEEDSHOWN(int,int);

	//! This signal is emitted when painting has been completed.  It is
	//! useful to trigger some other change but to have the paint be done
	//! first to appear more reponsive to the user.
	void SCN_PAINTED();

	//! This signal is emitted when the current state of the text no longer
	//! corresponds to the state of the text at the save point.
	//! 
	//! \sa SCI_SETSAVEPOINT, SCN_SAVEPOINTREACHED()
	void SCN_SAVEPOINTLEFT();

	//! This signal is emitted when the current state of the text
	//! corresponds to the state of the text at the save point. This allows
	//! feedback to be given to the user as to whether the text has been
	//! modified since it was last saved.
	//! 
	//! \sa SCI_SETSAVEPOINT, SCN_SAVEPOINTLEFT()
	void SCN_SAVEPOINTREACHED();

	//! This signal is emitted when a range of text needs to be syntax
	//! styled. The range is from the value returned by the
	//! SCI_GETENDSTYLED message and \a position.  It is only emitted if
	//! the currently selected lexer is SCNLEX_CONTAINER.
	//!
	//! \sa SCI_COLOURISE, SCI_GETENDSTYLED
	void SCN_STYLENEEDED(int position);

	//!
	void SCN_UPDATEUI();

	//!
	void SCN_USERLISTSELECTION(const char *,int);

	//!
	void SCN_ZOOM();

protected:
	//! Re-implemented to filter certain events.
	bool eventFilter(QObject *o,QEvent *e);

	//! Re-implemented to handle the key presses for the widget.
	virtual void keyPressEvent(QKeyEvent *ke);

	//! Re-implemented to tell Scintilla it has the focus.
	virtual void focusInEvent(QFocusEvent *);

	//! Re-implemented to tell Scintilla it has lost the focus.
	virtual void focusOutEvent(QFocusEvent *);

	//! Re-implemented to allow tabs to be entered as text.
	virtual bool focusNextPrevChild(bool);

	//! Start a drag operation.
	virtual void startDrag();

private slots:
	void handleTimer();
	void handleVSb(int value);
	void handleHSb(int value);
	void handlePopUp(int cmd);
	void handleSelection();

private:
	friend class ScintillaQt;

	void mousePress(QMouseEvent *me);
	void mouseRelease(QMouseEvent *me);
	void mouseDoubleClick(QMouseEvent *me);
	void mouseMove(QMouseEvent *me);
#ifndef ZPATCH
	void mouseWheel(QWheelEvent *we);
	void contextMenu(QContextMenuEvent *cme);
#endif

	ScintillaQt *sci;
	QScrollBar *vsb;
	QScrollBar *hsb;
	QWidget *txtarea;

#if defined(Q_DISABLE_COPY)
	QextScintillaBase(const QextScintillaBase &);
	QextScintillaBase &operator=(const QextScintillaBase &);
#endif
};

#endif