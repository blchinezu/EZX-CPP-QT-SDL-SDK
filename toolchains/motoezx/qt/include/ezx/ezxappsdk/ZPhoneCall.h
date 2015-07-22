
//--------------------------------------------------------------------------------------------------
//
// Header Name: ZPhoneCall.h
//
// General Description: ZPhoneCall class
//
//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//-------------------------------------------------------------------------------------------------

#ifndef Z_PHONECALL_H
#define Z_PHONECALL_H

#include <qobject.h>

/**
 * Provide phone call function based on phone application.
 */

class ZPhoneCall : public QObject
{
    Q_OBJECT
        
public:
    
    ZPhoneCall( QObject * parent = 0, const char * name = 0 );
    virtual ~ZPhoneCall();

    /**
     * Dials the specified phone number.
     * Whether showing dial pad before dialing depends on phone's "Prepend" setup. 
     *
     * @param telenumber The phone number to be dialed
     *
     * @retval if success, return true, if failed, return false.
     */
    bool makeVoiceCall( const QString& telenumber );
};

#endif //Z_PHONECALL_H

