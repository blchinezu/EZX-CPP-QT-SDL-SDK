/**************************************************************
*	
*	EZXϵͳ��TAPI��չ�����б�,�б��ɳ������������Ҹ��˵Ĳ²⣬
*		��Щ����ֵ�Ͳ�������û��һһ���ԣ������������½�,
*		�����ʲô�µĳɹ�������ϵ�ҡ����ʹ������б�
*		�뿪��Դ���룬�ڴ��㡣
*
*	EZX system TAPI extern function list.
*			copyfrom psysun's code	By SigarRon
*
* 	This program is free software; you can redistribute it and/or
* 	modify it under the terms of the GNU General Public License as
* 	published by the Free Software Foundation; either version 2.1 of
* 	the License, or (at your option) any later version.
*			
*
* 	Unofficial EZX Native Software Development Kit
* 	Copyright (C) 2007 SigarRon.China. <sigarron@163.com>
*
**************************************************************/

//libezxtapi-xscalr-r
extern "C" int TAPI_VOICE_MakeCall(char *n1,int *size);
extern "C" int TAPI_VOICE_CancelCall(int *i);
extern "C" int TAPI_CLIENT_Init(int * pi,int j);
extern "C" void TAPI_CLIENT_Fini(void);
extern "C" int TAPI_CLIENT_GetSyncSocketFd(void);
extern "C" int TAPI_CLIENT_ReadAndMallocMsg(int i,char * pmsg8byte);//return 0 when successed;
//extern "C" int TAPI_VOICE_DropCurrentCall(int tapihandle);
extern "C" int TAPI_VOICE_DropAllCall();
extern "C" int TAPI_CALL_GetAllCallSessions(char * buf);
extern "C" int TAPI_CSD_GetCurrentConnectedDuration(char * buf);
extern "C" int TAPI_FIXDIALING_GetStatus(int tapihandle,char * buf);