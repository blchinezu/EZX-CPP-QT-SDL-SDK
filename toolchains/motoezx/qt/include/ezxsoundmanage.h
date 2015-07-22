/**************************************************************
*	
*	EZX系统的Sound Manage扩展函数列表,列表由程序整理，这些函数是
*	严重没有完全的列表,期待大家都努力.
*
*	EZX system Sound Manage extern function list.
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

//libezxsound-xscale-r
/*
*
*	振动控制的函数
*/
extern "C" int SOUNDM_VBBLM_VibeOpenDev(void);
extern "C" int SOUNDM_VBBLM_VibeCloseDev(int hdev);
extern "C" int SOUNDM_VBBLM_VibeDevON(int hdev,int zero,int arg);