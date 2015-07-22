//
// ZLanguage : hacking by eakrin
// 2008 March 4
// 2008 March 15 : change from ZLanguage class to namespace.
// Version 0.1
// 2010 Jan 27 : add MMC

#ifndef  ZLANGUAGE_H
#define ZLANGUAGE_H

#include <qstring.h>

namespace ZLanguage
{

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

	LanguageId getSystemLanguageId();   //nukin change the return type //no static in namespace 
	//int getSystemLanguageId( void );
	QString getSystemLanguageCode( void );
	QString getSystemLanguageString( void );
	QString getLanguageStringByLanguageCode( QString const& );
	
//private:
    //static const MCC mccMapTable[];
};
typedef ZLanguage::LanguageId ZLanguageId;
typedef ZLanguageId ZKbLanguageId;

#endif // ZLANGUAGE_H
