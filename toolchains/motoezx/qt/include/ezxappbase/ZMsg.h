//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
// Revision History:
//                   Modification    Tracking
// Author (core ID)         Date      Number  Description of Changes
// -----------------  ----------  ----------  ---------------------------------
// Developer Name/ID  MM/DD/YYYY  LIBXXXXXXX  BRIEF description of changes made
// 
//-------------------------------------------------------------------------------------------------

/**
 * @file ZMsg.h
 * @brief Class for encapsulating and sending messages over a QCopChannel
 */
#ifndef ZMSG_H
#define ZMSG_H

#include <qcopchannel_qws.h>
#include <qdatastream.h>
#define APP_CHANNEL_PREF "EZX/Application/" //add

/**
 * The ZMsg class encapsulates the message and sends it over a QCopChannel. 
 *
 * This is a helper class to make communication between applications easier.
 * The peer application only needs to connect to the QCopChannel and receive it. 
 *
 * send the message with one parameter
 * @code
 * ZMsg msg(CHANNEL_NAME,"MESSAGENAME(int)");
 * msg << winId;
 * msg.send;  
 * @endcode
 *
 * receive the message above
 * @code
 * {
 *     ...
 *     const QCString CHANNEL_NAME = "MyChannel";
 *     QCopChannel* channel = new QCopChannel( CHANNEL_NAME, this );
 *     connect( channel, SIGNAL(received(const QCString&, const QByteArray&)), 
 *         this, SLOT(receive(const QCString&, const QByteArray&)) );
 *     ...
 * }
 *
 * void receive( const QCString& msg, const QByteArray& data )
 * {
 *    QDataStream stream( data, IO_ReadOnly );
 *
 *    if (msg == "MESSAGENAME(int)")
 *    {
 *        int winId;
 *        stream >> winId;
 *        ...
 *     }
 * } 
 * @endcode
 */

class ZMsg : public QDataStream
{

  public:
    
    /**
     * Constructor of ZMsg
     *
     * @param channel the name of the channel over which the message will be sent
     * @param message the message will be sent over the channel
     * @param local if true, the send() method will send the message via QCopChannel::sendLocally() 
     */
    ZMsg( const QCString& channel, const QCString& message, bool local = false );
    
    /**
     * Destructor of ZMsg. 
     */
    ~ZMsg();

    /**
     * Send the message to the destination channel.
     */
    void send();

  private:
  
    QCString ch;
    QCString msg;
    bool localMsg;
};


#endif

