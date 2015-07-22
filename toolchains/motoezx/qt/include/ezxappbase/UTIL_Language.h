#ifndef __UTIL_LANGUAGE_H__
#define __UTIL_LANGUAGE_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//--------------------------------------------------------------------------------------------------
//
//   Header Name: UTIL_Language.h
//
//   General Description: system language api
//
//--------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                   Template ID and version: IL93-TMP-01-0107  Version 1.10
//                    (c) Copyright Motorola 2002-2003, All Rights Reserved
//
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Wang Mingju/w20128            03/20/2003     LIBbb88079  Created
//
//
//
//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------

#include <unistd.h>
#include <qstring.h>
#include <qstringlist.h>
#include <ZLanguage.h>

class UTIL_Language
{
public:
/*LANG_PACK_TYPE size: 4LanguageId size:4
LanPack: 1
LangCode: en-gb LanId: 0
LangCode: zh-cn LanId: 20
LangCode: zh-hk LanId: 22
LangId: 0 en-us LanIndex: 1
LangId: 1 de LanIndex: 0
LangId: 2 da LanIndex: 4
LangId: 3 fr-ca LanIndex: 3
LangId: 4 it LanIndex: 5
LangId: 5 es-co LanIndex: 7
LangId: 6 sv LanIndex: 6
LangId: 7 nl LanIndex: 2
LangId: 8 pt-br LanIndex: 8
LangId: 9 fi LanIndex: 9
LangId: 10 no LanIndex: 10
LangId: 11 cl LanIndex: 11
LangId: 12 hu LanIndex: 13
LangId: 13 tr LanIndex: 12
LangId: 14 pl LanIndex: 14
LangId: 15 th LanIndex: 240
LangId: 16 vi LanIndex: 39
LangId: 17 ms LanIndex: 20
LangId: 18 in LanIndex: 39
LangId: 19 en-us LanIndex: 39
LangId: 20 zh-cn LanIndex: 39
LangId: 21 cs LanIndex: 39
LangId: 22 zh-hk LanIndex: 39
LangId: 23 bg LanIndex: 39
LangId: 24 hr LanIndex: 39
LangId: 25 et LanIndex: 39
LangId: 26 lv LanIndex: 39
LangId: 27 lt LanIndex: 39
LangId: 28 ro LanIndex: 39
LangId: 29 ru LanIndex: 39
LangId: 30 sr LanIndex: 39
LangId: 31 sk LanIndex: 39
LangId: 32 sl LanIndex: 21
LangId: 33 uk LanIndex: 39
LangId: 34 he LanIndex: 39
LangId: 35 ar LanIndex: 39
LangId: 36 fa LanIndex: 39
LangId: 37 hi LanIndex: 39
LangId: 38 ur LanIndex: 39
LangId: 240 auto-lang
LangId: 254 en-us
The encoding of the file is not recognized! (not Unicode , GB2312 or BIG5 encoding)
*/

    // language id define value
    typedef enum LanguageId
    {
	TD_LNGID_ENGLISH = 0,    // English
	TD_LNGID_GERMAN,         // German
	TD_LNGID_DANISH,         // Danish
	TD_LNGID_FRENCH,         // French
	TD_LNGID_ITALIAN,        // Italian
	TD_LNGID_SPANISH,        // Spanish
	TD_LNGID_SWEDISH,        // Swedish
	TD_LNGID_DUTCH,          // Dutch
	TD_LNGID_PORTUGUESE,     // Portuguese
	TD_LNGID_FINNISH,        // Finnish
	TD_LNGID_NORWEGIAN,      // Norwegian
	TD_LNGID_GREEK,          // Greek
	TD_LNGID_HUNGARIAN,      // Hungarian
	TD_LNGID_TURKISH,        // Turkish
	TD_LNGID_POLISH,         // Polish
	TD_LNGID_THAI,           // Thai
	TD_LNGID_VIETNAMESE,     // Vietnamese
	TD_LNGID_MALAY,          // Malay
	TD_LNGID_INDONESIAN,     // Indonesian
	TD_LNGID_TAGALOG,        // Tagalog
	TD_LNGID_CHINESE,        // Simplified Chinese
	TD_LNGID_CZECH,          // Czech
	TD_LNGID_TRAD_CHINESE,   // Traditional Chinese
	TD_LNGID_BULGARIAN,      // Bulgarian
	TD_LNGID_CROATIAN,       // Croatian
	TD_LNGID_ESTONIAN,       // Estonian
	TD_LNGID_LATVIAN,        // Latvian
	TD_LNGID_LITHUANIAN,     // Lithuanian
	TD_LNGID_ROMANIAN,       // Romanian
	TD_LNGID_RUSSIAN,        // Russian
	TD_LNGID_SERBIAN,        // Serbian
	TD_LNGID_SLOVAK,         // Slovak
	TD_LNGID_SLOVENIAN,      // Slovenian
	TD_LNGID_UKRAINIAN,      // Ukrainian
	TD_LNGID_HEBREW,         // Hebrew
	TD_LNGID_ARABIC,         // Arabic

	// Add new language ID values above this line
	TD_LNGID_NUM_OF_LANGUAGES, // number of languages with HSC language ID values
	TD_LNGID_INVALID = TD_LNGID_NUM_OF_LANGUAGES,  // invalid language id value

	TD_LNGID_AUTOMATIC = 0xF0,    // reserved for automatic language selection setting

	TD_LNGID_CURRENT_LANG = 0xFE  // equivalent to 'current language'
    };

    typedef struct
    {
	int		mccNumber;
	QString		mccText;
	QString 	languageCode;
	LanguageId	languageId;
    } MCC;

   // static LanguageId getSystemLanguageId();
    //static QString  getSystemLanguageCode();
    //static QString  getSystemLanguageString();

    //static LanguageId getLanguageIdByMcc( int mcc );
    //static QString  getLanguageCodeByMcc(int mcc);
    
    //LANG_PACK_TYPE not known yet
    typedef enum LANG_PACK_TYPE
    {
    LANG1,LANG2,LANG3,LANG4,LANG5,LANG6,LANG7,LANG8,LANG9,LANG10,LANG11,LANG12,
    LANG13,LANG14,LANG15,LANG16,LANG17,LANG18,LANG19,LANG20,LANG21,LANG22,
    LANG23,LANG24,LANG25,LANG26,LANG27,LANG28,LANG29,LANG30
    
    };
    
    
    static QString decodingTextBuff(uchar *,uint,UTIL_Language::LANG_PACK_TYPE);  //return the text or NULL. The encoding of the file is not recognized! (not Unicode , GB2312 or BIG5 encoding)
    static QString getISO639LangCode(QString);
    static int getLanPackType(void);
    static QStringList getLangCodeList(void);
	static QString getLanguageCodeByDialCode(int);
	static QString getLanguageCodeByEFlp(int,uchar *);
	static QString getLanguageCodeByISO639(ushort);
	static QString getLanguageCodeByLanId(int);
	static QString getLanguageCodeByLangId(ZLanguage::LanguageId);
	static QString getLanguageCodeByMcc(int);  //always return en-us
	static LanguageId getLanguageIdByDialCode(int);
	static LanguageId getLanguageIdByLanCode(QString);
	static LanguageId getLanguageIdByLanIndex(int);
	static LanguageId getLanguageIdByLangCode(QString);
	static LanguageId getLanguageIdByMcc(int);
	static LanguageId getLanguageIndexByLanId(int);
	static QString guessChineseCodec(uchar *,uint);
	bool isRtlLanguage(QString  const&);
	bool isSupportedLanguage(QString);
	
	enum lanMapTable { };
	enum Id_TypeMapTable {};

protected:

private:
    static const MCC mccMapTable[];
    LanguageId langid;
    bool rtlang, supportedlang;
    QString langcode;
    char unknow[2048];

};

#endif // __UTIL_Language_H__

