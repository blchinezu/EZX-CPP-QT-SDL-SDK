/*
 * Motorola Linux Mobile EZX Sound Manager SDK
 *
 * Copyright (C) 2008 OopsWare <oopsware@163.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Further, this software is distributed without any warranty that it is
 * free of the rightful claim of any third person regarding infringement
 * or the like.  Any license provided herein, whether implied or
 * otherwise, applies only to this software file.  Patent licenses, if
 * any, provided herein do not apply to combinations of this program with
 * other software, or any other product whatsoever.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
 
#if !defined(__EZX_SOUND_DM__)
#define __EZX_SOUND_DM__

#include <stdlib.h>  //uint

enum SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T {
	NORMAL_DEVICE		= 0xC000,
	NORMAL_DEVICE_1		= 0xC001,
	NORMAL_DEVICE_2		= 0xC002,
	NORMAL_DEVICE_3		= 0xC003,
	
	UNKNOWN_DEVICE		= 0xCC00,
  
};

enum SOUNDM_AUDIO_HARDWARE_TYPE {
	AUDIO_HARDWARE_DEFAULT	= 0x1,		// media play 
	
	AUDIO_HARDWARE_RADIO	= 0x4,		// FM radio
	
};

struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T {
	int active;							// 0x00		init with #1
	int deviceType;						// 0x04		init with #1
	int unknown_0x08;					// 0x08		init with #1 renderSoundDevice ? lock ?? pthread mutex ??? 
	int isStereo;						// 0x0c		????
	int unknown_0x10;					// 0x10		SoundPath ??? 0 for auto select ???
	int frequency;						// 0x14
	int channels;						// 0x18
	unsigned short bytesPerSample;		// 0x1c
	unsigned short bufferSize;			// 0x1e		init with #0	??????
	int unknown_x20;					//			init with #0
	int unknown_x24;					// 0x24		init with #5
	int leftVolume;						// 0x28		init with #7
	int rightVolume;					// 0x2c		init with #7
	int unknown_x30;
	unsigned char isMuted;				// 0x34
	unsigned char canRead;				//			init with #0, canRead ???
	unsigned char canWrite;				// 0x36		0:can write, 1: can't write
	unsigned char unknown_0x37;
	int unknown_0x38;
	int bytesWritten;					// 0x3c
	int unknown_0x40;
	int unknown_0x44;
	int unknown_0x48;					// 0x48		load to reg before call __Znwj ??? 
	short unknown_0x4c;					//			isMuted will set this to 1 while canFlush ???
	unsigned char unknown_0x4e;			//			Low 8 bit of NormalDevType
	unsigned char unknown_0x4f;			//			0x11 ???
	int unknown_0x50;
	int unknown_0x54;					// 0x54		hardware type ???
	int pid;							// 0x58		init with getpid() 
	int clientThreadSocketID;			// 0x5C
	int unknown_0x60;
	void *virTrack;						// 0x64
	int virTrackNumber;					// 0x68
};

struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T {
	int unknown_0x00;
	int unknown_0x04;
	int unknown_0x08;
	int unknown_0x0c;
	int SystemChannel;					// 0x10		SocketID ???
	unsigned char unknown_0x14;
	unsigned char unknown_0x15;
	unsigned char InputVolume;			// 0x16
	unsigned char Volume;				// 0x17
	unsigned char isMute;				// 0x18
	unsigned char unknown_0x19;
	unsigned char unknown_0x1a;
	unsigned char unknown_0x1b;
	int unknown_0x1c;					// 0x1C		set to isMute while set mute ???
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * return Const 0x6C the size of SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T 
 */
int SOUNDM_GetVirStructSize();	

/*
 * alloc 0x6c of memory and fill with zero
 */
struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T * SOUNDM_GetVirtualStructure();
int SOUNDM_FreeVirtualStructure(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);

/*
 * flag:
 *	0xC000 ~ 0xC004: Normal Sound Device with low 4 bits Priority ??
 *  0xCC00: ???
 *	0xC0FA: [0x4f] = 0x11, frequency = 8000, 
 *	0xC0FB: 
 * 	0xC0FC:
 *
 * frequency:
 *	8000 16000 22050 44100 48000 ...
 * channels can be 1 or 2
 * bytespersample MUST be 2, Support AFMT_S16_LE Only
 * bufferlen ?? default is 0x8000 .
 */
int SOUNDM_OpenOutputDevice(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, int flags, int frequency, int channels, int bytespersample);
int SOUNDM_CloseOutputDevice(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);

/*
 * return bufferlen * 2
 */
int SOUNDM_BufferSize_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_BytesPerSample_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_BytesRendered_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_BytesWritten_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
/*
 * check canWrite and then loop check SOUNDM_AudioOperate_CanWrite SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T
 */
int SOUNDM_CanWrite_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_Channels_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_Flush_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_Frequency_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_VirTrackFlush_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, void *track);
int SOUNDM_VirTrackWrite_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, void *track, int ,int );
int SOUNDM_Write_OD(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, void *, int len);

/*
 * unfinished , virtrack is a struct
 */
int SOUNDM_CloseDevVirTrack(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, void * virtrack );
int SOUNDM_GetVirTrackNumber(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_OpenDevVirTrack(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);

/*
 * Vibe and Backlight Manager
 */
int SOUNDM_VBBLM_BackLightOpenDev();
int SOUNDM_VBBLM_BackLightCloseDev(int );
int SOUNDM_VBBLM_BackLightDevON(int);
int SOUNDM_VBBLM_BackLightDevOFF(int);

int SOUNDM_VBBLM_VibeOpenDev();
int SOUNDM_VBBLM_VibeCloseDev();
int SOUNDM_VBBLM_VibeDevIfExist(int );
int SOUNDM_VBBLM_VibeDevON(int, int, int);
int SOUNDM_VBBLM_VibeDevOFF(int);

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus

/* SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T */

int SOUNDM_AudioOperate_OpenAudioDevice(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_CloseAudioDevice(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);

int SOUNDM_AudioOperateSetAudioDevice(unsigned int, unsigned int, unsigned int, struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_setAudioDevice(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_SetRenderSoundDevice(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, int);

int SOUNDM_AudioOperate_Flush(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_ReFresh(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_CanRead(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_CanWrite(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_BytesRendered(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);

int SOUNDM_AudioOperate_RenderSound(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, unsigned int, short *);
int SOUNDM_AudioOperate_ReadSound(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, short *, unsigned int);
int SOUNDM_AudioOperate_MA3_ioctrl(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, int, unsigned int, void *);
int SOUNDM_AudioOperate_RenderMA3Sound(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, unsigned int, char *);
int SOUNDM_AudioOperate_SetDevInputVol(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);
int SOUNDM_AudioOperate_StereoBT_Flush(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *);

/* SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T */

int SOUNDM_AudioOperate_OpenSystemChannel(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_CloseSystemChannel(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);

int SOUNDM_AudioOperate_OpenLogicalPhone(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_CloseLogicalPhone(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);

int SOUNDM_AudioOperate_GetVolumeControlAPP(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);

int SOUNDM_AudioOperate_GetVolume(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_SetVolume(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_GetInputVolume(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_SetInputVolume(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);

int SOUNDM_AudioOperate_isMute(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_SetMute(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_SetPath(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *, int);	/* Path less then #5 */

int SOUNDM_AudioOperate_HandsFreeOn(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_HandsFreeOff(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_ConnectPhone(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperate_HangUpPhone(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperatePhoneSetVolume(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);

int SOUNDM_AudioOperateBluetoothON(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperateBluetoothOFF(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);

int SOUNDM_AudioOperateStereoBluetoothON(char, char, struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);
int SOUNDM_AudioOperateStereoBluetoothOFF(struct SOUNDM_AUDIO_VIRTUALCOMMANDINFO_T *);

/* 
 * MISCs
 *
 * Command: SetChargingState
 *	0xA0: SetMute
 *	0xC9: SetChargingState(?, ture);
 *	0xCB: SetChargingState(?, false);
 *	0xCD: SetDuringVoiceCall(?, ture);
 *	0xCF: SetDuringVoiceCall(?, false);
 */

struct SOUNDM_AUDIO_SOUND_COMMAND {
	int Command;
	int Param1;
	int Param2;
};

int SOUNDM_SM_OpenAudioDevice(struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T *, unsigned int /*dev type*/, unsigned int /*frequency*/, unsigned int /*channels*/, unsigned int /*bytespersample*/);
int SOUNDM_SM_GetAudioManageIPCKey(int *);
int SOUNDM_SM_ReleaseAudioManagerIPCKey(int);
char * SOUNDM_SM_GetAUD_TN_LST(unsigned int /* 0x2A */);	/* "/usr/language/babt.wav" */

int SOUNDM_Audio_MySocketRead(int, void *, int);				/* socketID, pBuffer, BufferSize */
int SOUNDM_Audio_ReadCommand(int);								/* socketID */
int SOUNDM_Audio_WriteCommand(int, struct SOUNDM_AUDIO_SOUND_COMMAND *);
int SOUNDM_Audio_WaitDataComing(int, int);
int SOUNDM_AUDIOOPERATE_WaitDataComing(int *, int, int);
int SOUNDM_SetChargingState(int, bool);							/* socketID, ???? */
int SOUNDM_SetDuringVoiceCall(int, bool);
int SOUNDM_AUDIO_CLEARMySocketBeforeWrite(int);

/* VBBLM */

int SOUNDM_VBBLM_OpenHaptic();
int SOUNDM_VBBLM_CloseHaptic(int);
int SOUNDM_VBBLM_IfHapticsAlive(int);
int SOUNDM_VBBLM_PlayHaptic();
int SOUNDM_VBBLM_StopHaptic(int);

/*
 * ZAudioNormalDev
 */

class ZAudioNormalDev {
public:
	
	ZAudioNormalDev(enum SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T, uint /*frequency*/, uint /*channels*/, uint /*bytespersample*/);//, enum SOUNDM_AUDIO_HARDWARE_TYPE, int);
	
	int setAudioDevice(uint /*frequency*/, uint /*channels*/, uint /*bytespersample*/);
	int setRenderSoundDevice(int);

	int checkDevState();
	
	int open();				/* try open if not active  with 44100Hz Stereo */
	int close();
	int lock();
	int unlock();
	int refresh();
	int flush();
	
	int read(short *, uint);		/* MIC FM_Radeo ??? */
	
	int write(short*, uint);		/* play audio buffer 16Bit-LE */
	//int write(char *, unsigned int);		/* play MA3 stream */
	
	int leftVolume();
	int rightVolume();
	int setVolume(uint);						/* Volumn from 0x00 to 0x0f */
	int setVolume(uint, uint, bool);	/* leftVolume, rightVolume, Mute ?? */
	//int getVolume(uint *, uint *, bool *);  //E6 does not have this
	int setVolume1(uint);  //E6
	int increaseVolume();
	int decreaseVolume();
	int isMuted();
	int volumeChanged(bool);

	struct SOUNDM_AUDIO_VIRTUALPRIVATEINFO_T * getVirPrivateInfo();  //E6 does not have this
	int getPID();  //E6 does not have this
	int getAudiodeviceType();  //E6 does not have this
	int getHardwareType();  //E6 does not have this
	int getClientThreadSocketID();  //E6 does not have this
	int ioctl();  //E6 does not have this
	int getDeviceType();
	
//these are added by wangbin
	int openRetryDev(enum SOUNDM_AUDIO_NORMALDEV_TYPE_ENUM_T,uint /*frequency*/, uint /*channels*/, uint /*bytespersample*/);
	int recordStartTime(struct timeval&);
	virtual ~ZAudioNormalDev();
//protected:
	/* 
	 * protected ???? 
	 */
	int canWrite();
	int canRead();
	int channels();
	int frequency();
	int bytesPerSample();
	int bufferSize();
	int bytesWritten();
	int bytesRendered();
};

/*
 * SOUNDM_Audio_SystemCommand
 */

class SOUNDM_Audio_SystemCommand {
public:
	SOUNDM_Audio_SystemCommand();
	int OpenRetryDev();
	int GetVolumeControlAPP();
	int CheckDevState();
	int isMute();
	int SetMute(bool);
	int GetVolume();
	int SetVolume(int);
	int GetOutputVolume();
	int SetOutputVolume(int);
	int GetInputVolume();
	int SetInputVolume(int);
};

/*
 * SOUNDM_Audio_PhoneCommand
 */
 
class SOUNDM_Audio_PhoneCommand {
public:
	SOUNDM_Audio_PhoneCommand();
	int PhoneClose();
	int PhoneConnect();
	int openRetryDev();
	int checkDevState();
	int PhoneHandsFree();
	int SetPhoneVolume(int);
	int SetSpeakerPath(int);
	int CheckPhoneState();
	int SetChargingState(bool);
	int SetDuringVoiceCall(bool);
	int CheckHandsFreeState();
	int SetBluetoothHeadset(bool);
	int SetStereoBluetoothHeadset(char, char);
};


#endif

#endif // __EZX_SOUND_DM__
