/**********************************************************************
** Copyright (C) 2001 Trolltech AS.  All rights reserved.
**
** This file is part of the Qtopia Environment.
**
** Licensees holding valid Qtopia Developer license may use this
** file in accordance with the Qtopia Developer License Agreement
** provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
** THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
** PURPOSE.
**
** email sales@trolltech.com for information about Qtopia License
** Agreements.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/
#ifndef SOUND_H
#define SOUND_H

class QString;
class SoundData;

class Sound {
public:
    Sound(const QString& name);
    ~Sound();

    void play();
    void playLoop();
    void stop();

    static void soundAlarm();
    //static void soundClick();
    //static void soundTap();
    
private:
    SoundData* d;
};

#endif
