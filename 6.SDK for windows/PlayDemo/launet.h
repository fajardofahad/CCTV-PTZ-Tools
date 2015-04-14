//launet.h
#ifndef __LAUNET_H__
#define __LAUNET_H__

#include "VSNETStructDef.h"

#define CNET_APIIMPORT  extern "C"__declspec(dllexport)

#define LAUMSG_LINKMSG			1		//连接服务器错误
#define LAUMSG_VIDEOMOTION		2		//视频移动报警
#define LAUMSG_VIDEOLOST		3		//视频丢失报警
#define LAUMSG_ALARM			4		//探头报警
#define LAUMSG_OUTPUTSTATUS		5		//报警输出状态
#define LAUMSG_CURSWITCHCHAN	6		//当前切换通道
#define LAUMSG_HIDEALARM		7		//图像遮挡报警
#define LAUMSG_CHRECORD         8       //开始，停止录像
#define LAUMSG_EACHVIDEOMOTION  9       //分块视频移动
#define LAUMSG_INTERNAL         10      //内部消息
#define LAUMSG_SERVERRECORD     11      //服务器录像消息

/********************后处理标志**************/
#define CYN_PP_DEBLOCK_Y	0X00000001
#define CYN_PP_DEBLOCK_UV	0X00000002
#define CYN_PP_FILMEFFECT   0X00000004
#define CYN_PP_DERING_UV	0X00000008
#define CYN_PP_DERING_Y  	0X00000010
/********************后处理标志**************/

typedef struct{
	char *m_sername;                    //服务器名称
	char *m_username;                   //用户名
	char *m_password;                   //密码
	WORD m_tranType;                    //传输类型   
	WORD m_playstart;                   //是否启动预览
	BYTE m_ch;                          //通道号 
	HWND m_hVideohWnd;                  //视频窗口句柄
	HWND m_hChMsgWnd;                   //消息窗口句柄
	UINT m_nChmsgid;                    //通道号  
	int  m_buffnum;                     //音视频buff数量
	int  m_useoverlay;                  //是否使用overlay
	COLORREF nColorKey;                 //color key(保留)
	char url[40];                       //连接的url
	void (WINAPI *m_messagecallback)(LONG hHandle,int wParam,int lParam,void *context);
	                                    //消息回调函数 
	void *context;                      //回调函数上下文
}CHANNEL_CLIENTINFO;

typedef struct
{
	char m_multiip[16];                 //多播地址
	WORD m_wMultiPort;                  //多播端口
	WORD m_wLocaport;                   //本地端口
	int  m_videobuff;                   //音频buff数量
	int  m_audiobuff;                   //视频buff数量
	int  m_channuser;                   //通道用户数
	int  m_totaluser;                   //系统用户数
	int  (WINAPI *m_UserCheckcallback)(char *m_url,char *username,char *password);
	                                    //转发连接时用户验证
	int  (WINAPI *m_UserConnectcallback)(char *m_sername,int channel,BOOL bStart,char *m_userurl,char *username,char *password,int transtype,long handle);
                                        //转发用户连接或断开回调函数
}VSNET_REDIRECTORINFO;

/*ptz conctrl code*/
enum{
	PTZ_LEFT         =  0,
	PTZ_RIGHT	     =	1,
	PTZ_UP		     =	2,
	PTZ_DOWN	     =	3,
	PTZ_IRISADD	     =	4,
	PTZ_IRISDEC	     =  5,
	PTZ_FOCUSADD     =  6,
	PTZ_FOCUSDEC     =	7,
	PTZ_ZOOMADD	     =	8,
	PTZ_ZOOMDEC	     =	9,
	PTZ_GOTOPOINT    =	10,
	PTZ_SETPOINT	 =	11,
	PTZ_AUTO		 =	12,
	PTZ_STOP		 =	13,
	PTZ_LEFTSTOP	 =	14,
	PTZ_RIGHTSTOP	 =	15,
	PTZ_UPSTOP	     =	16,
	PTZ_DOWNSTOP     =	17,
	PTZ_IRISADDSTOP	 =	18,
	PTZ_IRISDECSTOP	 =	19,
	PTZ_FOCUSADDSTOP =	20,
	PTZ_FOCUSDECSTOP =	21,
	PTZ_ZOOMADDSTOP	 =  22,
	PTZ_ZOOMDECSTOP	 =  23,
	PTZ_LIGHT		 =	24,
	PTZ_LIGHTSTOP	 =	25,
	PTZ_RAIN		 =	26,
	PTZ_RAINSTOP	 =	27,
	PTZ_TRACK		 =	28,
	PTZ_TRACKSTOP	 =	29,
	PTZ_DEVOPEN		 =	30,
	PTZ_DECCLOSE	 =	31,
	PTZ_AUTOSTOP	 =	32,
	PTZ_CLEARPOINT	 =	33
};

enum{
	MESSAGE_SERVERCHS = 1,
	MESSAGE_CLEANALARM,
	MESSAGE_CONNECTIP,
	MESSAGE_CMD_RESET,
	MESSAGE_CMD_SHUTDOWN,
	MESSAGE_CMD_GETGLOBALPARAM,
	MESSAGE_CMD_SETGLOBALPARAM,
	MESSAGE_GETCHANNELPARAM,
	MESSAGE_SETCHANNELPARAM,
	MESSAGE_GETALARMPARAM,
	MESSAGE_SETALARMPARAM,
	MESSAGE_CMD_GETMOTIONPARAM,
	MESSAGE_CMD_SETMOTIONPARAM,
	MESSAGE_CMD_MOTIONTEST,
	MESSAGE_CMD_GETVIDEOMASK,
	MESSAGE_CMD_SETVIDEOMASK,
	MESSAGE_CMD_GETCHANNELOSD,
	MESSAGE_CMD_SETCHANNELOSD,
	MESSAGE_CMD_SAVEPARA,
	MESSAGE_CMD_PARAMDEFAULT,	
	MESSAGE_CMD_GETVIPARAM,
	MESSAGE_CMD_SETVIPARAM,
	MESSAGE_CMD_GETSERIAL,
	MESSAGE_CMD_SETSERIAL,
	MESSAGE_CMD_GETSYSTIME,
	MESSAGE_CMD_SETSYSTIME,
	MESSAGE_CMD_GETSERIALNO,
	MESSAGE_CMD_AFFIRMUSER,
	MESSAGE_CMD_GETSYSUSER,
	MESSAGE_CMD_SETSYSUSER,
	MESSAGE_CMD_OUTPUTCTRL,
	MESSAGE_CMD_TRANUART,
	MESSAGE_CMD_OUTPUTSTATUS,
	MESSAGE_CMD_EXDEVICESTATUS,
	MESSAGE_CMD_PTZCMDFILE,
	MESSAGE_CMD_PTZCMDNAME,
	MESSAGE_CMD_CURSWITCHCHAN,
	MESSAGE_CMD_SETVIDEOLOST,
	MESSAGE_CMD_GETVIDEOLOST,
	MESSAGE_CMD_UDPPORT,
	MESSAGE_CMD_SETTIMEDRESET,
	MESSAGE_CMD_GETTIMEDRESET,
	MESSAGE_CMD_SETHIDEALARM,
	MESSAGE_CMD_GETHIDEALARM,
	MESSAGE_CMD_GETREMOTEHOST,
	MESSAGE_CMD_SETREMOTEHOST,
	MESSAGE_CMD_GETSUBCHANNELPARAM,
	MESSAGE_CMD_SETSUBCHANNELPARAM,
	MESSAGE_CMD_STARTRECORDFILE,
	MESSAGE_CMD_STOPRECORDFILE,
	MESSAGE_CMD_CAPTUREJPEG,
	MESSAGE_CMD_GETDISKSTATE,
	MESSAGE_CMD_FORMATDISK,
	MESSAGE_CMD_ENCKEYFRAME,
	MESSAGE_CMD_GETPPPOEPARAM,
	MESSAGE_CMD_SETPPPOEPARAM,
	MESSAGE_CMD_GETRECORDPARAM,
	MESSAGE_CMD_SETRECORDPARAM,
	MESSAGE_CMD_GETVIDEOLOSTPARAM,
	MESSAGE_CMD_SETVIDEOLOSTPARAM,
	MESSAGE_CMD_GETJPEGCAPPARAM,
	MESSAGE_CMD_SETJPEGCAPPARAM,
	MESSAGE_CMD_GETRECORDSTATUS,
	MESSAGE_CMD_GETSENSORALARM,
	MESSAGE_CMD_SETSENSORALARM,
	MESSAGE_CMD_GETGLOBALPARAMEX,
	MESSAGE_CMD_SETGLOBALPARAMEX,
	MESSAGE_GETCHANNELPARAMEXNAME,
	MESSAGE_SETCHANNELPARAMEXNAME,
	MESSAGE_CMD_GETAUDIOPARAM,
	MESSAGE_CMD_SETAUDIOPARAM,
	MESSAGE_CMD_GETCDMAPARAM,
	MESSAGE_CMD_SETCDMAPARAM,
	MESSAGE_CMD_GETWIFIPARAM,
	MESSAGE_CMD_SETWIFIPARAM,
	MESSAGE_CMD_GETLINKCONFIG,
	MESSAGE_CMD_SETLINKCONFIG,
	MESSAGE_CMD_GETDDNSEXPARAM,
	MESSAGE_CMD_SETDDNSEXPARAM,
	MESSAGE_CMD_GETEXALARMPARAM,
	MESSAGE_CMD_SETEXALARMPARAM,
	MESSAGE_CMD_GETHUMITUREPRAM,
	MESSAGE_CMD_SETHUMITUREPRAM,
	MESSAGE_CMD_GETVIDEOOFFSET,
	MESSAGE_CMD_SETVIDEOOFFSET,
	MESSAGE_CMD_GETVIDEOMASKAREA,
	MESSAGE_CMD_SETVIDEOMASKAREA,
};

//SDK初始化函数
CNET_APIIMPORT void  __stdcall VSNET_ClientSetDebugFile(char *filename);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStartup(UINT m_nMessage,HWND m_hWnd,void (WINAPI *m_messagecallback)(LONG hHandle,int wParam,int lParam,void *context) = NULL,void *context = NULL);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientReadMessage(char *m_sername,char *m_url,WORD *m_port,int *m_ch,DWORD *wParam,DWORD *lParam);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientWaitTime(int m_waitnum = 6,int m_trynum = 3);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientCleanup();

//SDK连接,录像函数
CNET_APIIMPORT LONG  __stdcall VSNET_ClientStart(char *m_url,CHANNEL_CLIENTINFO *m_pChaninfo,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStop(LONG hHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStartView(LONG hHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStopView(LONG hHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetWnd(LONG hHandle,HWND hWnd);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientRefrenshWnd(LONG hHandle,RECT *rect = NULL);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientShowcallback(LONG hHandle,void(WINAPI *ShowCallBack)(BYTE *m_y,BYTE *m_u,BYTE *m_v,int stridey,int strideuv,int width,int height,void *context),void *context);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientVideoQuality(LONG hHandle,int m_quality);
CNET_APIIMPORT LONG  __stdcall VSNET_ClientGetState(LONG hHandle);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStartASFFileCap(LONG hHandle,LPTSTR m_FileName,BOOL m_bbroad = FALSE);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStopCapture(LONG hHandle);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientPlayAudio(LONG hHandle);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStopAudio(LONG hHandle);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientGetVideoSize(LONG hHandle,DWORD *m_pWidth,DWORD *m_pHeight);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientCapturePicture(LONG hHandle,LPTSTR m_filename);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientPTZCtrl(LONG hHandle,int type,int value);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSetPTZAddr(LONG hHandle,BYTE m_ptzaddr);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientPTZDev(LONG hHandle,char m_devch,BOOL bOn);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientOutPut(LONG hHandle,char m_devch,BOOL bOn);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientViAdjust(LONG hHandle,BYTE m_bri,BYTE m_con,BYTE m_sta,BYTE m_hue);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSwitchChannel(LONG hHandle,char m_curch);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientPrerecord(LONG hHandle,BOOL m_benable,int m_buffsize,int m_framecount);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSerialSend(LONG hHandle,int m_serialport,BYTE *pData,int size);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientClearAlarmOutHandle(LONG hHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStartViewEx(LONG hHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStopViewEx(LONG hHandle);
CNET_APIIMPORT int   __stdcall VSNET_ClientGetSwitchChannels(LONG hHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetStreamInfo(LONG hHandle,VSTREAMINFO *m_pStreamInfo);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStartNomalCap(LONG hHandle,
					   void(WINAPI *m_nomalvideo)(char *pbuff,int size,int timetick,int biskeyframe,void *context),void *pvideocontext,
					   void(WINAPI *m_nomalaudio)(char *pbuff,int size,int timetick,int biskeyframe,void *context),void *paudiocontext);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStopNomalCap(LONG hHandle);
CNET_APIIMPORT LONG  __stdcall VSNET_InfoClientStart(char *m_infourl,CHANNEL_CLIENTINFO *m_pChaninfo,WORD winfoport = 8080);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientInfoGetIPHandle(LONG hHandle,char* m_pgetip,WORD *m_wgetport);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStartMp4Capture(LONG hHandle, LPTSTR m_FileName);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStopMp4Capture(LONG hHandle);
CNET_APIIMPORT BOOL	 __stdcall VSNET_CleanVideoDisplayBuffer(LONG hHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientMediaData(LONG hHandle,BOOL bStart);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientAudioVolume(LONG hHandle,WORD m_Volume);
CNET_APIIMPORT int   __stdcall VSNET_ClientGetFrameRate(LONG hHandle);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientCapturePictureEx(LONG hHandle,char *pbuff,int stride,int size);

//服务器对讲函数(自动采集本地音频)
CNET_APIIMPORT LONG  __stdcall VSNET_ClientTalkExchangeStart(char *m_url,char *m_username,char *m_password,WORD wserport = 3000,void(WINAPI *TalkCallBack)(char *pbuff,int size) = NULL,char *m_servername = NULL);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientTalkExchangeStop(LONG hAudioHandle);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientTalkBroadcastStart();
CNET_APIIMPORT int   __stdcall VSNET_ClientTalkAddnew(char *m_url,char *m_username,char *m_password,WORD wserport = 3000,char *m_servername = NULL);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientTalkDel(char *m_url,WORD wserport = 3000,char *m_servername = NULL);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientTalkBroadcastStop();

//服务器对讲函数(用户采集音频输入)
CNET_APIIMPORT int   __stdcall VSNET_ClientTalkStart(char *m_url,char *m_username,char *m_password,int m_tranType,LONG *handle,WORD wserport=3000,char *m_servername = NULL);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientTalkStop(LONG hAudioHandle);
CNET_APIIMPORT int	 __stdcall VSNET_ClientTalkSendData(LONG hAudioHandle,char *pBuf,int buflen);
CNET_APIIMPORT void  __stdcall VSNET_ClientTalkFreeAll();

//服务器升级函数
CNET_APIIMPORT LONG  __stdcall VSNET_ClientUpdateStart(char *m_url,char *m_username,char *m_password,char *m_filename,HANDLE m_hEndEvent,WORD wserport = 3000,char *m_sername = NULL);
CNET_APIIMPORT int   __stdcall VSNET_ClientUpdateStop(LONG hHandle);

//服务器参数函数
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientClearAlarmOut(char *m_sername,char *m_url,char *m_username,char *m_password,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetChannelAmount(char *m_sername,char *m_url,DWORD *m_channs,DWORD *m_alarmins,DWORD *m_alarmouts,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetConnectIP(char *m_sername,char *m_url,char *m_username,char *m_password,CONNECTIP *m_pConnecIP,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientResetServer(char *m_sername,char *m_url,char *m_username,char *m_password,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientShutDownServer(char *m_sername,char *m_url,char *m_username,char *m_password,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetWholePara(char *m_sername,char *m_url,char *m_username,char *m_password,WHOLEPARAM *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetWholePara(char *m_sername,char *m_url,char *m_username,char *m_password,WHOLEPARAM *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetChannelPara(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNELPARAM *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetChannelPara(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNELPARAM *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetAlarmRecord(char *m_sername,char *m_url,char *m_username,char *m_password,ALARMPARAM *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetAlarmRecord(char *m_sername,char *m_url,char *m_username,char *m_password,ALARMPARAM *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetMotionPara(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNMOTION *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetMotionPara(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNMOTION *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientMotionTest(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,BOOL m_bOn,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetVideoMask(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNVIDEOMASK *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetVideoMask(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNVIDEOMASK *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetChanOSD(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNOSD *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetChanOSD(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNOSD *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSaveServerPara(char *m_sername,char *m_url,char *m_username,char *m_password,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientDefaultPara(char *m_sername,char *m_url,char *m_username,char *m_password,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetViparam(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNVIPARAM *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetViparam(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNVIPARAM *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetSerial485Param(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,SERIAL485_PARAM *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetSerial485Param(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,SERIAL485_PARAM *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetSystime(char *m_sername,char *m_url,char *m_username,char *m_password,TIME_PARAM *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetSystime(char *m_sername,char *m_url,char *m_username,char *m_password,TIME_PARAM *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetSerialNo(char *m_sername,char *m_url,char *m_username,char *m_password,BYTE m_serial[50],WORD wserport = 3000);
CNET_APIIMPORT int   __stdcall VSNET_ClientAffirmUser(char *m_sername,char *m_url,char *m_username,char *m_password,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetUser(char *m_sername,char *m_url,char *m_username,char *m_password,WHOLE_USER *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetUser(char *m_sername,char *m_url,char *m_username,char *m_password,WHOLE_USER *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientOutPutServer(char *m_sername,char *m_url,char *m_username,char *m_password,char m_devch,BOOL bOn,WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSerialSendToServer(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,int m_serialport,BYTE *pData,int size,WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientGetOutputStatus(char *m_sername,char *m_url,char *m_username,char *m_password,BYTE m_outputstatus[8],WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientGetExDeviceStatus(char *m_sername,char *m_url,char *m_username,char *m_password,BYTE m_outputstatus[16],WORD wserport = 3000);
CNET_APIIMPORT int 	 __stdcall VSNET_ClientSetPTZCommandFile(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,char *m_filename,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetPTZCommandName(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,char *m_ptzname,WORD wserport = 3000);
CNET_APIIMPORT int 	 __stdcall VSNET_ClientGetCurSwitchChannel(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetVideoLost(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,BOOL bEnabled,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetVideoLost(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,BOOL *pbEnabled,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetTimerReset(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,VSTIMERRESET *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetTimerReset(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,VSTIMERRESET *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetHideAlarm(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNELHIDEALARM *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetHideAlarm(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,CHANNELHIDEALARM *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientEncKeyFrame(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,WORD wserport=3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetUdpPort(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,unsigned short *videoport,unsigned short *audioport,WORD wserport=3000);
CNET_APIIMPORT int   __stdcall VSNET_ClientServerTalk(ULONG m_nurl,char *m_username,char *m_password,int m_tranType,BOOL isStart,unsigned int *sock,DWORD wserport = 3000,char *m_servername = NULL);
CNET_APIIMPORT int 	 __stdcall VSNET_ClientSetLicenseFile(char *m_sername,char *m_url,char *m_username,char *m_password,char *pbuff,int size,WORD wserport = 3000);
CNET_APIIMPORT int 	 __stdcall VSNET_ClientGetLicenseFile(char *m_sername,char *m_url,char *m_username,char *m_password,void(WINAPI *licdatacallback)(char *pbuff,int size,void *userdata),void *userdata = NULL,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetHostNotify(char *m_sername,char *m_url,char *m_username,char *m_password,VSNETHOSTNOTIFY *m_pSetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetHostNotify(char *m_sername,char *m_url,char *m_username,char *m_password,VSNETHOSTNOTIFY *m_pGetPara,WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSetSerialNumData(char *m_sername,char *m_url,char *m_username,char *m_password,char *pSetbuff,WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientGetSerialNumData(char *m_sername,char *m_url,char *m_username,char *m_password,char *pGetbuff,WORD wserport = 3000);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSetSerialNumPass(char *m_sername,char *m_url,char *m_username,char *m_password,char *pSetbuff,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetTempData(char *m_sername,char *m_url,char *m_username,char *m_password,char *pbuff,int size,WORD wserport = 3000);
CNET_APIIMPORT int   __stdcall VSNET_ClientGetTempData(char *m_sername,char *m_url,char *m_username,char *m_password,char *pbuff,WORD wserport = 3000);
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetPTZText(char *m_sername,char *m_url,char *m_username,char *m_password,char *pbuff,int size,WORD wserport = 3000);

//远程报警录像接口,9000系列只支持报警
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetRemoteHost(char *m_sername,char *m_url,char *m_username,char *m_password,VSREMOTEHOST *m_pGetPara,WORD wserport );
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetRemoteHost(char *m_sername,char *m_url,char *m_username,char *m_password,VSREMOTEHOST *m_pSetPara,WORD wserport );

//8000系列子通道视频参数
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetSubChanPara(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,VSSUBCHANPARAM *m_pGetPara,WORD wserport );
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientSetSubChanPara(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,VSSUBCHANPARAM *m_pSetPara,WORD wserport );

//8000系列硬盘录像
CNET_APIIMPORT BOOL	 __stdcall VSNET_StartServerRecord(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,int lRecordType,WORD wserport );
CNET_APIIMPORT BOOL	 __stdcall VSNET_StopServerRecord(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,WORD wserport );
CNET_APIIMPORT BOOL  __stdcall VSNET_ClientGetRecordStatus(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,WORD wserport);

//8000系列硬盘抓图
CNET_APIIMPORT BOOL	 __stdcall VSNET_ServerCapJPEG(char *m_sername,char *m_url,char m_ch,char *m_username,char *m_password,int m_quality,WORD wserport );

//8000系列硬盘操作
CNET_APIIMPORT BOOL	 __stdcall VSNET_GetDiskState(char *m_sername,char *m_url,char *m_username,char *m_password,VSDISKSTATE *m_pDiskState,WORD wserport );
CNET_APIIMPORT int 	 __stdcall VSNET_FormatDisk(char *m_sername,char *m_url,char *m_username,char *m_password,int m_diskno,WORD wserport );
//参数读取统一接口
CNET_APIIMPORT LONG	 __stdcall VSNET_ClientMessageOpen(char *sername,char *url,char *username,char *password,WORD serport = 3000);
CNET_APIIMPORT int	 __stdcall VSNET_ClientMessageOpt(LONG hHandle,int opt,int ch = 0,void *param1 = NULL,void *param2 = NULL,void *param3 = NULL);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientMessageClose(LONG hHandle);
//转发服务器接口
CNET_APIIMPORT BOOL	 __stdcall VSNET_SetRedirectorInfo(VSNET_REDIRECTORINFO *m_pRedirect);
CNET_APIIMPORT int	 __stdcall VSNET_StartListenClient(char *m_localAddrIP = NULL);
CNET_APIIMPORT BOOL	 __stdcall VSNET_StopListenClient();
CNET_APIIMPORT int   __stdcall VSNET_RedirectorGetNormalUser(VSUSERINFO *userinfo,int index);
CNET_APIIMPORT int   __stdcall VSNET_RedirectorGetMultiUser(VSUSERINFO *userinfo,int index);
CNET_APIIMPORT BOOL  __stdcall VSNET_RedirectorDelUser(VSUSERINFO *userinfo);

//DDNS服务器IP获取函数
CNET_APIIMPORT int 	 __stdcall VSNET_ClientInfoGetServerIP(char* m_infourl,WORD m_wInfoport,char *m_sername,char* m_pgetip,WORD *m_wgetport);

//透明串口接口
CNET_APIIMPORT LONG	 __stdcall VSNET_ClientSerialStart(char *m_sername,char *m_url,char *m_username,char *m_password,int iSerialPort,
												 VSSERIAL_INFO *pSerialInfo,
												 void(WINAPI *fSerialDataCallBack)(LONG hSerial,char *pRecvDataBuff,int BuffSize,void *context),
												 void *context,WORD wserport);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSerialStop(LONG hSerial);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSerialSendNew(LONG hSerial,char *pSendBuff,DWORD BuffSize);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSerialRecvPause(LONG hSerial);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSerialRecvRestart(LONG hSerial);
CNET_APIIMPORT LONG	 __stdcall VSNET_ClientJpegCapStart(char *m_sername,char *m_url,char *m_username,char *m_password,WORD wserport,
											void(WINAPI *jpegdatacallback)(LONG hHandle,int m_ch,char *pBuffer,int size,void *userdata),void *userdata);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientJpegCapSingle(LONG hHandle,int m_ch,int m_quality);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientJpegCapStop(LONG hHandle);
//新增加的函数
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSetDelayTime(LONG hHandle,int delaytime);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientFlipVideo(LONG hHandle);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientGetVideoMove(LONG hHandle,VSNETVIDEOMOVE_BLOCK *block);

CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStartMp4StreamCapture(LONG hHandle,WORD port);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientStopMp4StreamCapture(LONG hHandle);

CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSetRedirectDelayTime(LONG hHandle,int delaytime);
CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientSetImageShow(LONG hHandle,BOOL bShow);

#endif//__LAUNET_H__
