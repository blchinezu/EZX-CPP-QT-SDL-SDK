//--------------------------------------------------------------------------------------------------
//
//   Header Name: ZKbGlobal.h
//
//   General Description: In this class, we defined some general enumeration and structure
//
//
//--------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//                     Template ID and version: TMP_LFC_50115 Version 1.1
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Developer Name/ID            MM/DD/YYYY     LIBXXXXXXX   BRIEF description of changes made
// Li Jun/a18547                     1/16/2005                           Initial version
// Zhang Yueting/e7366c         04/07/2006     LIBii68353   Modified for writing system
//
//--------------------------------------------------------------------------------------------------
#ifndef ZKB_GLOBAL_H
#define ZKB_GLOBAL_H
//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------


#include "qstring.h" 
#include "qrect.h"
#include "qevent.h"
#include "qmap.h"
#include "ZIMethod.h"
#include "ZLanguage.h"
#include "ZKbWritingSystem.h"

#if 1
typedef QChar		ZChar; 
typedef QFont		ZFont;
typedef QFontMetrics	ZFontMetrics;
typedef QObject     ZObject;

typedef QString     ZString; 
typedef QPoint      ZPoint; 
typedef QColorGroup ZColorGroup; 
typedef QRect 	    ZRect; 
typedef QEvent      ZEvent;
#endif

namespace ZKbGlobal
{

    enum 
    {
        //
        // shift and autoshift-behavior
        //
        /** Shift behavior constant- no autoshift, but manual shifting available, (value = 401)   */
        FIELD_CAPS_NONE = 401,

        /** Shift behavior constant- no shifting available --> all in lowercase, (value = 402)   */
        FIELD_CAPS_LOWER = 402,

        /** Shift behavior constant- no shifting available --> all in uppercase, (value = 403)   */
        FIELD_CAPS_UPPER = 403,

        /** Shift behavior constant- 1st letter of each word capitalized, (value = 404)   */
        FIELD_CAPS_WORD = 404,

        /** Shift behavior constant- 1st letter of each sentence capitalized, (value = 405)   */
        FIELD_CAPS_SENTENCE = 405,

        /** Shift behavior constant- set shift status in function of surrounding text, (value = 451)   */
        FIELD_SHIFT_FREE = 451,

        /** Shift behavior constant-  set shift status to lowercase, (value = 452)   */
        FIELD_SHIFT_LOWER = 452,

        /** Shift behavior constant- set shift status to uppercase, (value = 453)   */
        FIELD_SHIFT_UPPER = 453,

        /** Shift behavior constant- set shift status to all caps, (value = 454)   */
        FIELD_SHIFT_CAPS = 454,
    }; 

    //what's the meaming???
    enum
    {
        ZKB_CURSOR_NONE,

        ZKB_CURSOR_BLOCK,

        ZKB_CURSOR_BAR, 
    };

    enum
    {
        ZKB_CF_NONE,

        ZKB_CF_L2R,

        ZKB_CF_R2L,         
    };
    
    enum
    {
        /* right-to-left text cursor rendering */
        /** RTL Cusror status -  left-to-right cursor , (value = 0)   */
        ZKB_L2R_CURSOR       = 0, 

        /** RTL cusror status - right-to-left cursor, (value = 1&lt;&lt;14)   */
        ZKB_R2L_CURSOR       = 1<<14, 
    }; 


    enum
    {
        ZKB_INPUT_DEVICE_TS,
        ZKB_INPUT_DEVICE_KEYPAD, 
    }; 


    enum EVENT_TYPE
    {
        KB_EVENT_USER = QEvent::User + 234,
        KB_EVENT_MODIFIED,
        KB_EVENT_CURSOR_MOVED,
        KB_EVENT_TEXT_CONFIMED,
        KB_EVENT_START_EDITTING,
        KB_EVENT_INDICATOR_CHANGEING,
        KB_EVENT_END_COMPOSITION
    };

    enum
    {
        ZKB_SOUND_DIGIT_KEY,
        ZKB_SOUND_ZERO_KEY,
        ZKB_SOUND_SPACE_KEY,
        ZKB_SOUND_MODE_KEY,
        ZKB_SOUND_GENERIC_KEY,
        ZKB_SOUND_END_LIST,
        ZKB_SOUND_PAGEUP,
        ZKB_SOUND_PAGEDOWN,
        ZKB_SOUND_BEEP
    };
    
    /**
     * @enum ZKB_ITEM_INDEX
     * @all the indicators of input method .
    */
    typedef enum  
    {
         ZKB_MODES_INDICATOR= 0,
         ZKB_LANGUAGE_INDICATOR,
         ZKB_SHIFT_INDICATOR,
         ZKB_COMPLETION_INDICATOR,
         ZKB_UAD_INDICATOR,
         ZKB_NEW_WORD
    }ZKB_ITEM_INDEX;
     
     /**
     * @enum ZKB_ACT_INDEX
     * @the actions of indicatior change.
    */ 
    typedef enum 
    {
         ZKB_ACT_ADD = 0,
         ZKB_ACT_REMOVE
    }ZKB_ACT_INDEX;
    

    class ZKbModifiedEvent : public QCustomEvent
    {
     public:
        ZKbModifiedEvent(QPoint cursorPos)
            :QCustomEvent(KB_EVENT_MODIFIED)
            , _cursorPos(cursorPos)
        {

        }

        virtual ~ZKbModifiedEvent()
        {
        }

        QPoint getCursorPos()
        {
            return _cursorPos; 
        }
     private:
        QPoint _cursorPos; 
    };

    class ZKbCursorMoveEvent : public QCustomEvent
    {
    public:
        ZKbCursorMoveEvent(QPoint cursorPos)
            :QCustomEvent(KB_EVENT_CURSOR_MOVED)
            , _cursorPos(cursorPos)
        {

        }

        virtual ~ZKbCursorMoveEvent()
        {

        }

        QPoint getCursorPos()
        {
            return _cursorPos; 
        }
    private:
        QPoint _cursorPos; 
    };

    class ZKbTextConfirmEvent : public QCustomEvent
    {
    public:
        ZKbTextConfirmEvent(const QString& txt)
            :QCustomEvent(KB_EVENT_TEXT_CONFIMED)
            , _txt(txt)
        {

        }

        virtual ~ZKbTextConfirmEvent()
        {

        }

        QString getText()
        {
            return _txt; 
        }
    private:
        QString _txt; 
    };

    class ZKbStartEdittingEvent : public QCustomEvent
    {
    public:
        ZKbStartEdittingEvent()
            :QCustomEvent(KB_EVENT_START_EDITTING)
        {

        }

        virtual ~ZKbStartEdittingEvent()
        {

        }
    };
    
    class ZIMIndicatorChangeEvent : public QCustomEvent
    {
    public:
        ZIMIndicatorChangeEvent(ZKB_ITEM_INDEX itemIndex, QString resId,ZKB_ACT_INDEX action)
            :QCustomEvent(KB_EVENT_INDICATOR_CHANGEING),_index(itemIndex), _id(resId),_actions(action)
        {
        }

        ZKB_ITEM_INDEX getItemIndex() const
        {
        	return _index;
        }
         
        QString getID() const 
        {
        	return _id;
        }
        
        ZKB_ACT_INDEX getActions() const
        {
        	return _actions;
        }
        
        virtual ~ZIMIndicatorChangeEvent()
        {
        }

      private:
           ZKB_ITEM_INDEX _index;
           QString _id;
           ZKB_ACT_INDEX _actions;
    };
    

    class ZKbEndCompositionEvent : public QCustomEvent
    {
    public:
        ZKbEndCompositionEvent()
            :QCustomEvent(KB_EVENT_END_COMPOSITION)
        {

        }

        virtual ~ZKbEndCompositionEvent()
        {

        }
    };
    
    struct ZKbEditBehavior 
    {
        bool capital:1;
        bool space:1;
        bool nocheck:1;
        bool ltr:1; //left to right
        bool langMapTo1Key:1;//language is mapped to the 1 key. e.g Thai
        bool progressive:1;  //language force to use progressive completion, e.g. Thai.
        bool new_word_query:1;  //language need to query new word status when spinning out of dictionary.
        int  :1; //reserved
    };

    struct ZKbLangContext
    {
        union{
            ZLanguageId langId; 
            ZWritingSystemId writingId;
        };
        QMap<ushort, QString> mappingTable;
        ZKbEditBehavior editBehavior;
    };

    struct InputMode
    {
        union{
            ZLanguageId langId;
            ZWritingSystemId writingId;
        };
        QUuid modeId;
        int langContextIndex;
    };

    struct ZKbNumbers
    {
        ZKbLanguageId langId;
        QString number;
    };

    enum
    {
        ZKB_ALTNATE_MODE_CANDIDATE_LIST_CHOOSER,
        ZKB_ALTNATE_MODE_CANDIDATE_MATRIX_CHOOSER,
        ZKB_ALTNATE_MODE_SYMBOL_CHOOSER,
    }; 

    enum
    {
        ZKB_ALTNATE_ACTION_HIDEUI,
        ZKB_ALTNATE_ACTION_KEEPUI,
    }; 
    class ZKbKey
    {
    public:
        ZKbKey(int keycode, bool repeat, bool pressed=true, bool sound=false):keyCode(keycode),repeat(repeat),press(pressed),soundFlag(sound){};
        int key () const{return keyCode;};
        bool isAutoRepeat () const {return repeat;};
        void setSound(bool hasSounded=true){soundFlag = hasSounded;};
        bool isSound() const {return soundFlag;};
        bool isPress() const { return press;};
        bool isRelease() const { return !press;};
    private:
        int keyCode;
        bool repeat;
        bool press;
        bool soundFlag;
    };
}; 


#endif
