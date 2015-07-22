#ifndef __ZSTRUCTUREDATAPARSER_H__
#define __ZSTRUCTUREDATAPARSER_H__

#include "qlist.h"
#include "qstring.h"
#include "qstringlist.h"
/**
 * Call back function prototype
 *
 * @param origStr, the string replaced;
 * @param desStr,  the string used to replace.
 *
 * @return -1, error, 0, success, 1, no find the desStr, 2, isn't structure data, 
 * 3, find the desStr, but not replace.
 */

typedef int (* PPARSERCALLBACK)(const QString & origStr, QString & desStr);

#define STRUCTUREDATATYPE_PHONENUMBER  "text/x-phoneNumber"
#define STRUCTUREDATATYPE_EMAIL        "text/x-email"
#define STRUCTUREDATATYPE_URL          "text/x-url"
#define STRUCTUREDATATYPE_IM           "text/x-wv"
#define STRUCTUREDATATYPE_DATE_1       "text/x-date1"
#define STRUCTUREDATATYPE_DATE_2       "text/x-date2"
#define STRUCTUREDATATYPE_TIME         "text/x-time"

/**
 * The class ZStructureDataParser parses the structure data from a string.
 *
 * Currently, the parser only supports the 3 structure data type.
 *  1: "text/x-phoneNumber" : phone number
 *  2: "text/x-email" : email address
 *  3: "text/x-url" : url
 *  4: The type supports the combination of two or more type, the symbol of 
 *     combination is "|", For example, the type "text/x-phoneNumber|text/x-email|text/x-ur" 
 *     represents the parser parses the string with the three type.
 *  5: ZStructureDataParser supports filtering some structure date type.  
 */

class ZStruDataParserPrivate;

class Q_EXPORT ZStructureDataParser
{
public:

    /**
     * The structure describes the structure data info.
     *
     * @member strOrignal The orignal sub string in the Text that be parsed.
     * @member origBeginPos The begin pos of the strOrignal in the Text that be parsed.
     * @member origEndPos   The end pos of the strOrignal in the Text that be pared.
     * @member strDisplay The displaying sub string int the displaying Text(after parsing).
     * @member disBeginPos The begin pos of the strDisplay in the displaying Text.
     * @member disEndPos The end pos of strDisply in the displaying Text.
     * @member replacedFlag, -1, find replaced string fail, 0, success, 1, no find 
     *         replaced string, 3, find the desStr, but not replace.
     * @member strType The structure data type. 
     */ 
    typedef struct
    {
        QString strOrig;
        int origBeginPos;
        int origEndPos;
        QString strDisplay;
        int disBeginPos;
        int disEndPos;
        int replacedFlag;
        QString type;
    }STRUCTUREDATA, *LPSTRUCTUREDATA;
    
    /**
     * Constructor
     */ 
    ZStructureDataParser();

    /**
     * Constructor
     * @member strText The text will be parsed.
     * @type 
     */ 
    ZStructureDataParser(const QString & strText, const QString & type = "text/x-phoneNumber", 
                         PPARSERCALLBACK pParserCallback = 0);
    /**
     * Deconstructor
     */ 
    ~ZStructureDataParser();

    /**
     * Set type info.
     * 
     * @param strType, structure data type, if strType exists, modify the type info.
     * @param strTypeRule, some structure data type pattern expression, if strType exist && strTypeRule.isEmpty()
     * use default parsing rule, or modify parsing rule. if strType no exist && strTypeRule.isEmpty(), the structure
     * data type is invalid.
     * @pParserCallback, call back function pointer, if null, don't need process the orignal str.
     */ 
    void setTypeInfo(const QString & type, const QString & strTypeRule = QString::null,
                              PPARSERCALLBACK pParserCallback = 0);

    /**
     *  Set current structure data type, it can be the combination of several kind of type.
     *  For example, "text/x-phoneNumber|text/x-email"
     *
     *  @param type structure data type.
     */ 
    void setType(const QString & type);

    QString getType();

    /**
     *  Set current filter structure data type, it can be the combination of several kind of type.
     *  For example, "text/x-phoneNumber|text/x-email". The ZStructureDateParser will discard the 
     *  the data the data type is included in the filter.
     *
     *  @param type structure data type.
     */
    void setFilterType(const QString & type);
    
    /**
     * Set the text to be parsed.
     *
     * @param strText The text to be parsed.
     * @param nPos The beginning pos of parsing. The parser matches the text from the nPos.
     * For example, the text is "abcdefg1234", nPos = 3; the matching from char 'd'
     */ 
    void setText(const QString & strText, int nPos = 0, bool isAdd = false);

    /**
     * Parse the current text, using current type.
     */ 
    bool parse();
    
    /**
     *  Parse the string strText, using the type from nPos.
     *
     *  @param strText The text to be parsed
     *  @param nPos @see setText.
     *  @param type The type used to parse the text.
     */ 
    bool parse(const QString & strText, int nPos, const QString & type, bool isAdd = false);

    /**
     * Get the structure data based on the type.
     *
     * @param type, structure data type, it can be the combination of multi structure data type.
     *              if type.isEmpaty() is true, use the current type.
     */ 
    QList<STRUCTUREDATA> getStructureData(const QString & type = QString::null);

    /**
     * Get the number of structure data of some or multi structure data type.
     *
     * @param type, structure data type, it can be the combination of multi structure data type.
     *              if type.isEmpaty() is true, use the current type.
     */ 
    int getStructureDataCount(const QString & type = QString::null);

    /**
     * Get the structure data pointer at the index nIndex based on the type.
     *
     * @param nIndex The nIndex, it is the index in the structure data number of the type.
     *               if the nIndex > the structure data number of the type, return null.
     * @param type, structure data type, it can be the combination of multi structure data type.
     *              if type.isEmpaty() is true, use the current type.
     *
     * @return The pointer of the STRUCTUREDATA.
     */ 
    const LPSTRUCTUREDATA getStructureData(int nIndex, const QString & type = QString::null);

     /**
      * Get the displaying text. The text is the text after proccessed by parser.
      *
      * @return the displaying text.
      */ 
    QString getDisplayText();

    /**
     * Delete the structure data at the index based on the type.
     * 
     * @param nIndex The nIndex, it is the index in the structure data number of the type.
     * @param type, structure data type, it can be the combination of multi structure data type.
     *              if type.isEmpaty() is true, use the current type.
     */
    void deleteStructureData(int nIndex, const QString & type = QString::null);			
private:
    void inital();
    QString getCurrentRule(QStringList typeList);
    void setCallBack(const QString & type, PPARSERCALLBACK pParserCallback);
    QStringList getCurrentTypeList(const QString & type);
    int getCapturedParaNumber(const QString & strTypeRule);
    bool realParse();
    int getStruDataTypeInfo(QString & strMatch);
    int addNewStruDataTypeInfo(const QString & strMatch, const QString & strTypeName, 
                        PPARSERCALLBACK pParserCallback, int nPos, int nIndex);
    
    int findStructureDataByPos(int nPos);
    int getDisplayTextPos(int norigPos, int nIndex);
    int getEmailHeader(const QString & strSour, QString & strHead, int curPos);
    int getContainedSD(int nPos, int nFirstIndex, int nLastIndex);
    bool isFilterData(const QString & strType);

    /**
     * The structure data type info.
     *
     * @member strTypeName The type name, like "text/x-phoneNumber" etc.
     * @member strTypeRule The pattern expression of the structure data type.
     * @member nCapNumber  The captured parentheses number of the rule.
     * @member pParserCallback The call back function pointer. if the caller need process the structure data,
     *                         the caller must set the call back function. if the pointer is null, represent the 
     *                         caller needn't process the structure data.
     */
    typedef struct
    {
        QString strTypeName;
        QString strTypeRule;
        int nCapNumber;
        PPARSERCALLBACK pParserCallback;
    }TYPEINFO, *LPTYPEINFO;

    /**
     * The list saved the type info.
     */ 
    QList<TYPEINFO> mlistTypeInfo;
    QList<STRUCTUREDATA> mlistStruData;

    ZStruDataParserPrivate * d;

    QStringList mCurDataType;
    QString mText;
    QString mCurRule;
    int mPos;
    bool mIsAdd;
    //int mCurDTIndex;
    //PPARSERCALLBACK mpParserCallback;    
};

#endif  //__ZSTRUCTUREDATAPARSER_H__
