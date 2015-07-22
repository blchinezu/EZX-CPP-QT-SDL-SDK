//--------------------------------------------------------------------------------------------------
//
//   Header Name: KbMultiLineInputField.h
//
//   General Description: Declaraion of the Multiline field
//
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
// Li Jun/a18547                     1/17/2005                           Initial version
//
//
//--------------------------------------------------------------------------------------------------
#ifndef KB_MULTILINE_INPUTFIELD_H
#define KB_MULTILINE_INPUTFIELD_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------

#include <ZKbGlobal.h> 
#include <ZInputField.h>

#define MAX_UNDERLINE_LINE 12
#define MAX_REVERSE_LINE 12

class ZMultiLineEdit;

class KbMultiLineInputField : public ZInputField
{
Q_OBJECT

  public: 
    KbMultiLineInputField(ZMultiLineEdit * edit); 
    virtual ~KbMultiLineInputField();

#if 0 //check with Dong Feng whether we need these functions
    void updateUnderline();
    void updateReverse();
    void clearBoth();
#endif
    
public:

    virtual int editType()
    {
        return  ZKB_SUPPORTED_EDIT; 
    }

    
    /**
     * A field's text.
     * @param pos position where to get the text , invalid position (-1,-1) means the whole text
     * @param forward the direction to get the text
     * @return text
     */
    virtual ZString getText(ZPoint pos , bool forward);

   
    /**
     * A cursor position in the field's text.
     * @return cursor position
     */
    virtual ZPoint getCursorPos(); 

    /**
     * A command to set a field's text. A Field can ignore it and process only 
     * <code>delete</code> and <code>insert</code> commands.
     * @param text field's text
     */
    virtual void setText(ZString text);
    
    
    /**
     * A command to set the cursor position in the text.
     * @param pos start cursor position
     * @param len the moving length from the start pos, nagtive to left, positive to right
     * @retval return the current cursor position 
     */
    virtual ZPoint setCursorPos(ZPoint pos, int len, bool update = true);

    /**
     * The possible values for the <code>flag</code> are: ZKB_CF_NONE, ZKB_CF_L2R, ZKB_CUF_R2L. 
     * @param flag cursor flag
     */
    virtual void setCursorFlag(int flag);

    /**
     * The possible values for the <code>direction</code> are: ZKB_L2R_CURSOR, ZKB_R2L_CURSOR
     * @param direction cursor direction
     */
    virtual void setCursorDirection(int direction);

    /**
     * A command to show a hint for a suggested completition in reverse video.
     * @param pos starting position of the reverse video (completion)
     * @param len length of reverse video  
     */
    virtual void setReverse(ZPoint pos, int len, bool update);
    
    /**
     * A command to remove the current reverse state without removing string 
     */
    virtual void clearReverse(bool update);

    /**
     * A command to show a hint for a text part subject for disambiquation when in 
     * predictive mode.   
     * @param pos starting position of the underlined part
     * @param len length of the underlined part
     * @param alternateAvailable to show a hint for availability of alternates when in predictive mode.   
     */
    virtual void setUnderline(ZPoint pos, int len, bool alternateAvailable, bool update);

    /**
     * A command to remove the current underline state without removing string 
     */
    virtual void clearUnderline(bool update);

    
    /**
     * A command to delete a part of the text. Usually it will be pared with the <code>insert</code> command
     * @param pos position to start deleting the text
     * @param len number of characters to delete 
     * @param autoUpdate if immediate update is needed 
     */
    virtual void deleteString(ZPoint pos, int len , bool autoUpdate);

    /**
     * A command to insert a text at the given positioni. Usually it will be pared with the <code>delete</code> command
     * @param pos position to start inserting the text 
     * @param text text to insert 
     */
    virtual void insertString(ZPoint pos, ZString text, bool update);
    
    /*
     * @param cursorPos: the cursor position in the inserted string.
     */
    virtual void insertString(ZPoint start_pos , ZString text , int reverse_start , int reverse_len , int underline_start , int underline_len , bool alternateAvailable,int cursorPos);

    /**
     * A callback method that <code>InputEngine</code> will call when time comes
     * to learn the field's text. The parameter is an unformatted string, The return value 
     * is the formatted String.    
     */
    virtual ZString format(ZString text);

    /**
     * A callback method that <code>InputEngine</code> will call when time comes to
     * to compute position of the UI popup with alternatives and helper tooltips.
     * @return boundindg rectangle of the field on the screen 
     */
    virtual ZRect getFieldBounds();
    
    /**
     * A callback method that <code>InputEngine</code> will call when time comes to
     * to compute position of the UI popup with alternatives and helper tooltips.
     * 
     * @param pos of a character in the field's text
     * @return boundindg rectangle of the character in the field's recctangle 
     */
    virtual ZRect getCharBounds(ZPoint pos);

    virtual ZRect getUnderlineBounds(ZPoint pos);

    /**
     * A function to get max length of input field.
     * If there's no limit, then return -1
     */
    virtual int maxLength(); 

    /**
     * A  method that <code>InputEngine</code> will call before insert a char 
     * or string in the editor. If there is a validator, the engine should call 
     * canInsertString to confirm the string can insert or not.
     * @return  true if the editor has a valid and not empty validator
     */
    virtual bool  hasValidator(void) ;
    /**
     * A  method that <code>InputEngine</code> will call before insert a char 
     * or string in the editor. If there is a validator, this methods should be called 
     * to confirm the char can insert or not.
     * @param the QString that engine want to insert.
     * @return  true if all the char of the string can be inserted.
     */
    virtual bool  canInsertString(const QString& string);

public slots:
    void slotTextChanged();
    void slotCursorChanged( int cursorX , int cursorY );

protected:
    /**
    * Disable update, return the old update setting
    */
    bool enableUpdate(bool enable);

    /**
    * Enable update
    */
    void restoreUpdateEnabled(bool );
    
public:
    bool underline;
    short underlineStart[MAX_UNDERLINE_LINE];
    short underlineSize[MAX_UNDERLINE_LINE];
    short underlineLine[MAX_UNDERLINE_LINE];
    bool underlineAlter[MAX_UNDERLINE_LINE];

    bool reverse;
    short reverseStart[MAX_REVERSE_LINE];
    short reverseSize[MAX_REVERSE_LINE];
    short reverseLine[MAX_REVERSE_LINE];

private:
    ZMultiLineEdit * multi_editor;
};

#endif
