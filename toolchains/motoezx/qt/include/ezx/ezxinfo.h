/**************************************************************
*	
*	EZX系统的扩展函数列表,列表由程序整理，加上我个人的猜测，
*		有些返回值和参数我尚没有一一测试，带来不便请谅解,
*		如果有什么新的成果，请联系我。如果使用这个列表，
*		请开放源代码，期待你。
*
*	EZX system extern function list.
*				By SigarRon
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

#include <stdio.h>
#include <stdlib.h>

/************************************************************
 *
 *	以下是“取”状态函数，我只尝试过很小很小的一部分。
 *	返回值和参数,请自行完善。有什么新东西，请致电sigarron@163.com
 *	follows are some function "GET" ur phone status.
 *  i do not konw about the return value and arg.
 *	按照我的经验,所有get_some_status的函数都是int类型，并且都能准确
 *	的返回值.
 *
*************************************************************/

//libezxappbase-xscale-r
extern "C" int  UTIL_EncodingAutoDetectBuff();
extern "C" int  UTIL_GetAMApplicationStatus();
extern "C" int  UTIL_GetBatteryLevel();   			//监视电池电量
extern "C" int  UTIL_GetBatteryPercent();  			//取电池百分数
extern "C" int  UTIL_GetBatteryStatus();   			//取电池状态
extern "C" int  UTIL_GetBlendingPercentage(); 		//取透明百分数
extern "C" int  UTIL_GetBtConnCount();   			//取蓝牙连接数
extern "C" int  UTIL_GetBtHandfreeStatus();
extern "C" int  UTIL_GetBTHSStatus();
extern "C" int  UTIL_GetBtStatus();					//取蓝牙状态
extern "C" int  UTIL_GetChargeStatus();
extern "C" int  UTIL_GetCountryId();
extern "C" int  UTIL_GetCphsCspStatus();
extern "C" int  UTIL_GetCphsLineLockStatus();
extern "C" int  UTIL_GetCphsOperatorName();
extern "C" int  UTIL_GetCphsOpnShortformSatus();
extern "C" int  UTIL_GetCphsSimCardStatus();
extern "C" int  UTIL_GetCphsVMStatus();
extern "C" int  UTIL_GetDataCallStaus();
extern "C" int  UTIL_GetDataConnStatus();
extern "C" int  UTIL_GetDlgPriority();
extern "C" int  UTIL_GetEarpieceSafety();
extern "C" int  UTIL_GetEgprsServiceStatus();
extern "C" int  UTIL_GetEgprsTransStatus();
extern "C" int  UTIL_GetEMUBus_Acc_Status();
extern "C" int  UTIL_GetFlipStatus();
extern "C" int  UTIL_GetGprsActivatedStatus();
extern "C" int  UTIL_GetGprsAttachStatus();
extern "C" int  UTIL_GetGprsFeatureStatus();
extern "C" int  UTIL_GetGprsServiceStatus();
extern "C" int  UTIL_GetHeadsetStatus();
extern "C" int  UTIL_GetHKSoundInfo();
extern "C" int  UTIL_GetIncomingCallStatus();			//取呼入状态,无返回0，有返回1
extern "C" int  UTIL_GetIrdaBusyStatus();
extern "C" int  UTIL_GetNetworkId();
extern "C" int  UTIL_GetNotificationStatus();			//取未接信息提示状态,有1,无0
extern "C" int  UTIL_GetPhoneApplicationStatus();
extern "C" int  UTIL_GetPhoneAudioDeviceStatus();
extern "C" int  UTIL_GetPhoneAudioPath();
extern "C" int  UTIL_GetPhoneCallIconIndex();
extern "C" int  UTIL_GetPhoneInCall();					
extern "C" int  UTIL_GetPhoneLine();					//取话机线路
extern "C" int  UTIL_GetPhoneLockStatus();
extern "C" int  UTIL_GetPhoneSystemStatus();
extern "C" int  UTIL_GetPinStatus();
extern "C" int  UTIL_GetPowerOffStatus();
extern "C" int  UTIL_GetPowerOnMode();					//取开机模式
extern "C" int  UTIL_GetPowerOnProcess();				//取开机进度
extern "C" int  UTIL_GetRFMode();
extern "C" int  UTIL_GetRoamStatus();
extern "C" int  UTIL_GetServiceName(char *buf);			//取服务商名
extern "C" int  UTIL_GetSignalQuality();				//取信号强度
extern "C" int  UTIL_GetSimCardStatus();
extern "C" int  UTIL_GetSIMPinBatteryStatus();
extern "C" int  UTIL_GetSpnName(char *buf);				//取服务商名
extern "C" int  UTIL_GetTableAddress();
extern "C" int  UTIL_GetThemeInfo();
extern "C" int  UTIL_GetTimingPhoneLock();
extern "C" int  UTIL_GetTotalDataBytes();				//取总数据流量
extern "C" int  UTIL_GetTotalDuration();
extern "C" int  UTIL_GetTPSoundInfo();
extern "C" int  UTIL_GetTransparency();					
extern "C" int  UTIL_GetTTYDeviceStatus();
extern "C" int  UTIL_GetUSBChargingStatus();			//取充电状态
extern "C" int  UTIL_GetUSBConnectionStatus();			//USB连接状态
extern "C" int  UTIL_GetUSBDeviceType();				//取USB设备类型
extern "C" int  UTIL_GetUsbMassStorage();
extern "C" int  UTILITY_TAPI_Read_AppMsgHeader();		//这个是读取进程通信头的，显然不是int型
extern "C" void  UTIL_ResetDlgPriority();				//复位对话框？

/******************************************************************
 *
 *	以下部分是“置”状态函数，返回值和参数未知，请参考对应的“取”
 *	状态函数.
 *	follows are some function "set" ur phone status,
 *	i do not konw about the return value and arg.
 *
*******************************************************************/

extern "C" void  UTIL_SetAMApplicationStatus(int);
extern "C" void  UTIL_SetBatteryLevel(int);  				//置电池级别
extern "C" void  UTIL_SetBatteryPercent(int);				//置电池电量
extern "C" void  UTIL_SetBatteryStatus(int);				//置电池状态
extern "C" void  UTIL_SetBlendingPercentage(int);
extern "C" void  UTIL_SetBtConnCount(int);
extern "C" void  UTIL_SetBtHandfreeStatus(int);
extern "C" void  UTIL_SetBTHSStatus(int);					//置蓝牙耳机状态
extern "C" void  UTIL_SetBtStatus(int);
extern "C" void  UTIL_SetChargeStatus(int);
extern "C" void  UTIL_SetCountryId(int);
extern "C" void  UTIL_SetCphsInfo(int);
extern "C" void  UTIL_SetCphsLineLockStatus(int);
extern "C" void  UTIL_SetCphsOperatorName(int);
extern "C" void  UTIL_SetDataCallStatus(int);
extern "C" void  UTIL_SetDataConnStatus(int);
extern "C" void  UTIL_SetDlgPriority(int);
extern "C" void  UTIL_SetEarpieceSafety(int);
extern "C" void  UTIL_SetEgprsServiceStatus(int);
extern "C" void  UTIL_SetEgprsTransStatus(int);
extern "C" void  UTIL_SetEMUBus_Acc_Status(int);
extern "C" void  UTIL_SetFlipStatus(int);
extern "C" void  UTIL_SetGprsActivatedStatus(int);
extern "C" void  UTIL_SetGprsAttachStatus(int);
extern "C" void  UTIL_SetGprsFeatureStatus(int);
extern "C" void  UTIL_SetGprsServiceStatus(int);
extern "C" void  UTIL_SetHeadsetStatus(int);
extern "C" void  UTIL_SetHKSoundInfo(int);
extern "C" void  UTIL_SetIncomingCallStatus(int);
extern "C" void  UTIL_SetIrdaBusyStatus(int);
extern "C" void  UTIL_SetNetworkId(int);
extern "C" void  UTIL_SetNotificationStatus(int);
extern "C" void  UTIL_SetPhoneApplicationStatus(int);
extern "C" void  UTIL_SetPhoneAudioDeviceStatus(int);
extern "C" void  UTIL_SetPhoneAudioPath(int);
extern "C" void  UTIL_SetPhoneCallIconIndex(int);
extern "C" void  UTIL_SetPhoneInCall(int);
extern "C" void  UTIL_SetPhoneLine(int);						//置话机线路
extern "C" void  UTIL_SetPhoneLockStatus(int);
extern "C" void  UTIL_SetPinStatus(int);
extern "C" void  UTIL_SetPowerOffStatus(int);
extern "C" void  UTIL_SetPowerOnMode(int);
extern "C" void  UTIL_SetPowerOnProcess(int);
extern "C" void  UTIL_SetRFMode(int);
extern "C" void  UTIL_SetRoamStatus(int);
extern "C" void  UTIL_SetServiceName(char *name);
extern "C" void  UTIL_SetSignalQuality(int);
extern "C" void  UTIL_SetSimCardStatus(int);
extern "C" void  UTIL_SetSpnName(char *name);
extern "C" void  UTIL_SetThemeInfo(int);
extern "C" void  UTIL_SetTimingPhoneLock(int);
extern "C" void  UTIL_SetTotalDataBytes(int);
extern "C" void  UTIL_SetTotalDuration(int);
extern "C" void  UTIL_SetTPSoundInfo(int);
extern "C" void  UTIL_SetTransparency(int);
extern "C" void  UTIL_SetTTYDeviceStatus(int);
extern "C" void  UTIL_SetUSBChargingStatus(int);
extern "C" void  UTIL_SetUSBConnectionStatus(int);
extern "C" void  UTIL_SetUSBDeviceType(int);
extern "C" void  UTIL_SetUsbMassStorage(int);

