//VSNETStructDef.h
#ifndef __VSNET_STRUCTDEF_H__
#define __VSNET_STRUCTDEF_H__

enum{
	VSNETALARMMSG_SERSTART = 1,	/* 服务器启动 */	
	VSNETALARMMSG_MOTION,		/* 移动侦测报警 */
	VSNETALARMMSG_VIDEOLOST,	/* 视频丢失报警 */
	VSNETALARMMSG_SENSOR,		/* 探头报警 */
	VSNETALARMMSG_DISKFULL,		/* 硬盘满报警 */
	VSNETALARMMSG_HIDEALARM,	/* 视频遮挡报警 */	
	VSNETALARMMSG_SERSTOP,		/* 服务器停止 */
};

/*转发用户权限*/
#define VSNET_USER_RIGHT_ADMIN		1	//管理员权限
#define VSNET_USER_RIGHT_HIOPER		2	//高级操作员
#define VSNET_USER_RIGHT_OPERIAL	3	//操作员

typedef struct
{
	char				m_username[20];		//用户名
	char				m_password[20];		//密码
}ONEUSER;

typedef struct
{
	ONEUSER				m_admin;			//管理员
	ONEUSER				hl_operator[10];	//高级操作员
	ONEUSER				m_operator[10];		//操作员
}WHOLE_USER;
typedef struct
{
	int					bUseDDNS;			//DDNS使能
	char				DDNSSerIp[40];		//DDNS服务器IP
	unsigned short		DDNSSerPort;		//DDNS服务器端口
	unsigned short		LocalMapPort;		//本地端口
}WHOLE_DDNS;
typedef struct
{
	char				pStrBSPVer[50];		//BSP版本
	char				pStrAPPVer[50];		//应用程序版本号
	char				pStrBSPBuildTime[50];
											//BSP编译时间
	char				pStrAPPBuildTime[50];
											//应用程序编译时间
}VERSIONINFO;
typedef struct{
	char				m_servername[24];	//服务器名称
	char				m_serverip[16];		//IP地址
	char				m_servermask[16];	//子网掩码
	char				m_gatewayAddr[16];	//网关
	char				m_dnsaddr[16];		//dns地址
	char				m_multiAddr[16];	//多播地址	
	unsigned short		m_serport;			//数据端口
	unsigned short		m_mulport;			//多播端口
	unsigned short		m_webport;			//网页端口
	unsigned char		m_isPAL;			//视频制式(PAL,NTSC)
	unsigned char		m_launage;			//语言
	unsigned char		m_phyAddr[6];		//物理地址
	unsigned short		m_reserved;         //保留
	unsigned char		m_serial[8];		//序列号
	WHOLE_DDNS			m_ddns;				//DDNS参数
	VERSIONINFO			m_version;			//版本
}WHOLEPARAM;

typedef struct{
	char				m_servername[60];	//服务器名称
	char				m_serverip[16];		//IP地址
	char				m_servermask[16];	//子网掩码
	char				m_gatewayAddr[16];	//网关
	char				m_dnsaddr[16];		//dns地址
	char				m_multiAddr[16];	//多播地址	
	unsigned short		m_serport;			//数据端口
	unsigned short		m_mulport;			//多播端口
	unsigned short		m_webport;			//网页端口
	unsigned char		m_isPAL;			//视频制式(PAL,NTSC)
	unsigned char		m_launage;			//语言
	unsigned char		m_phyAddr[6];		//物理地址
	unsigned short		m_reserved;         //保留
	unsigned char		m_serial[8];		//序列号
	WHOLE_DDNS			m_ddns;				//DDNS参数
	VERSIONINFO			m_version;			//版本
}WHOLEPARAMEX;

typedef struct
{
	unsigned char		m_starthour;		//开始小时
	unsigned char		m_startmin;			//开始分钟
	unsigned char		m_stophour;			//停止小时
	unsigned char		m_stopmin;			//停止分钟
	unsigned char		m_maskweek;			//周
	unsigned char		bReceive[3];		//保留
}TIMECHECK;

typedef struct
{
	TIMECHECK			pList[7];			//时间表
}TIMELIST;

typedef struct
{
	unsigned char		m_beanb;             //移动侦测启动
	unsigned char		m_alarmsenstive;     //移动侦测灵敏度
	unsigned char		m_brecord;           //联动到录像
	unsigned char		bReceive;            //保留
	unsigned char		m_outputmap[8];      //联动到输出 
	unsigned char		m_detect[18][22];    //侦测范围
	TIMELIST			m_timelist;          //侦测时间表 
}CHANNMOTION;

typedef struct
{
	unsigned char		m_beanb;             //移动侦测启动
	unsigned char		m_alarmsenstive;     //移动侦测灵敏度
	unsigned char		m_brecord;            //联动到录像
	unsigned char		m_capjpeg;           //联动到jpeg抓图
	unsigned char		m_singlehost;        //上传中心
	unsigned char		m_reseved1;          //保留
	unsigned char		m_reseved2;          //保留
	unsigned char		m_reseved3;          //保留
	unsigned char		m_outputmap[8];      //联动到输出 
	unsigned char		m_detect[18][22];    //侦测范围
	TIMELIST			m_timelist;          //侦测时间表 
}CHANNMOTIONEX;

typedef struct
{
	int					nFormat;			//显示格式
	unsigned short		x,y;				//显示坐标
}TIMEOSD;

typedef struct
{
	int					bShow;				//显示(1),不显示(0)
	unsigned short		x,y;				//显示坐标
}BITSINFOOSD;

typedef struct
{
	char				lpString[32];		//显示字符		
	unsigned short		x,y;				//坐标
}TITALOSD;

typedef struct
{
	TIMEOSD				m_time;				//时间
	TITALOSD			m_tital[4];			//标题
	BITSINFOOSD			m_bits;				//码率
}CHANNOSD;

typedef struct
{
	int					m_bmask;			//图像屏蔽使能
	unsigned short		m_x;				//x
	unsigned short		m_y;				//y
	unsigned short		m_width;			//width
	unsigned short		m_height;			//height
}CHANNVIDEOMASK;

typedef struct
{
	unsigned char		m_bri;				//图像亮度
	unsigned char		m_con;				//图像对比度
	unsigned char		m_sat;				//图像饱和度
	unsigned char		m_hue;				//图像色度
}CHANNVIPARAM;

typedef struct
{
	char				m_channelName[16];	//通道名称
   	int					m_streamType;		//码流类型:视频流、视音频流
   	int					m_encodeType;		//图像格式CIF,2CIF,4CIF
	int					m_Iinterval;		//关键帧间隔(10-200)
	int					m_videoFrameRate;	//帧率
	int					m_bitratetype;		//码率控制类型：CBR & VBR
	int					m_maxqueue;			//VBR 量化系数(2-31)
	int					m_minqueue;			//CBR 量化系数(2-31)
	int					m_maxbitrates;		//CBR 最大码率(64K-8000K)
	int					m_audiosample;		//音频采样频率
	int					m_audiobitrate;		//音频码率
	int					m_delay;			//报警延迟
	int					m_benrecord;		//定时录像使能
	TIMELIST			m_record;			//定时录像时间表
}CHANNELPARAM;

typedef struct
{
	char				m_channelName[60];	//通道名称
   	int					m_streamType;		//码流类型:视频流、视音频流
   	int					m_encodeType;		//图像格式CIF,2CIF,4CIF
	int					m_Iinterval;		//关键帧间隔(10-200)
	int					m_videoFrameRate;	//帧率
	int					m_bitratetype;		//码率控制类型：CBR & VBR
	int					m_maxqueue;			//VBR 量化系数(2-31)
	int					m_minqueue;			//CBR 量化系数(2-31)
	int					m_maxbitrates;		//CBR 最大码率(64K-8000K)
	int					m_audiosample;		//音频采样频率
	int					m_audiobitrate;		//音频码率
	int					m_delay;			//报警延迟
	int					m_benrecord;		//定时录像使能
	TIMELIST			m_record;			//定时录像时间表
}CHANNELPARAMEXNAME;

typedef struct
{
	char				m_channelName[16];	//通道名称
   	int					m_streamType;		//码流类型:视频流、视音频流
   	int					m_encodeType;		//图像格式CIF,2CIF,4CIF
	int					m_Iinterval;		//关键帧间隔(10-200)
	int					m_videoFrameRate;	//帧率
	int					m_bitratetype;		//码率控制类型：CBR & VBR
	int					m_maxqueue;			//VBR 量化系数(2-31)
	int					m_minqueue;			//CBR 量化系数(2-31)
	int					m_maxbitrates;		//CBR 最大码率(64K-8000K)
	int					m_audiosample;		//音频采样频率
	int					m_audiobitrate;		//音频码率
	int					m_delay;			//报警延迟
	int                 m_nPrerecordTime;   //预录时间(0为关闭,1-10秒时打开)
	int                 m_videofilebackup;  //视频文件备份(0,1,2分别表示不上传,上传报警文件,全部文件)
	int                 m_jpegfilebackup;	//Jpeg文件备份(0,1,2分别表示不上传,上传报警文件,全部文件)
	int					m_benrecord;		//定时录像使能
	TIMELIST			m_record;			//定时录像时间表
}CHANNELPARAMEX;

typedef struct{
	int					m_baudrate;			//波特率
	int					decoderModel;       //协议类型(不使用)
	unsigned char		m_databit;			//数据位
	unsigned char		m_stopbit;			//停止位
	unsigned char		m_checkbit;			//效验位
	unsigned char		m_flowcontrol;		//流控
	unsigned char		decoderAddress;		//解码器地址
	unsigned char		bReceive[3];		//保留
}SERIAL485_PARAM;

typedef struct{
	int					baudrate;			//波特率
	char				databit;			//数据位
	char				stopbit;            //停止位
	char				checkbit;			//校验位
	char				flowcontrol;        //流控
}VSSERIAL_INFO;

typedef struct
{
	int					m_year;				//年
	unsigned char		m_month;			//月
	unsigned char		m_dayofmonth;		//日
	unsigned char		m_dayofweek;        //星期
	unsigned char		m_hour;             //小时
	unsigned char		m_minute;			//分
	unsigned char		m_second;			//秒
	unsigned char		bReceive[2];		//保留
}TIME_PARAM;

typedef struct
{
	unsigned char		m_record[16];		//联动到录像
	unsigned char		m_out[8];			//联动到输出
	unsigned char		m_enpreno[16];		//联动到调用预置点
	unsigned char		m_preno[16];		//调用预置点号
	TIMELIST			m_timelist;			//检测时间表
}ALARMRECORD;

typedef struct
{
	int					m_alarmmode;		//报警模式0：常关,1：常开
	int					m_singlehost;		//报警信号上传中心标志
	unsigned char		m_record[16];		//联动到录像
	unsigned char		m_out[8];			//联动到输出
	unsigned char		m_enpreno[16];		//联动到调用预置点
	unsigned char		m_preno[16];		//调用预置点号
	unsigned char		m_capjpeg[16];		//联动到抓拍
	TIMELIST			m_timelist;			//检测时间表
}ALARMRECORDEX;

typedef struct
{
	int					m_benab;			//报警启动标志
	ALARMRECORD			m_alarmrec[8];		//报警联动参数
}ALARMPARAM;

typedef struct
{
	int					m_benab;            //报警启动标志
	ALARMRECORDEX		m_alarmrec[8];      //报警联动参数
}ALARMPARAMEX;

typedef struct{
	int					m_chanuser[16];		//通道
	unsigned char		m_chanIP[16][20][4];//连接的IP地址
}CONNECTIP;

typedef struct{
	unsigned long		m_videotag;         //视频tag
	short				m_width,m_height;   //视频尺寸
	int					m_bhaveaudio;       //有无音频   
	int					m_samplesize;       //音频采样频率
	unsigned short		m_audiotag;         //音频tag
	unsigned short		m_audiobitrate;		//音频码率
}VSTREAMINFO;

typedef struct{
	unsigned long		m_url;				//地址
	char				m_sername[24];		//服务器名称
	int					m_ch;				//通道
	int					trantype;			//传输类型 
	long				handle;				//句柄
}VSUSERINFO;

typedef struct
{
	int					m_benable;			//遮挡检测启动
	int					m_decval;			//检测灵敏度(1(最低)---3(最高))
	unsigned char		m_out[8];			//联动报警输出  
	TIMELIST			pTimeList;			//检测时间
}CHANNELHIDEALARM;

typedef struct
{
	int					m_benable;			//遮挡检测启动
	int					m_bsinglehost;		//报警信号上传中心标志
	int					m_decval;			//检测灵敏度(1(最低)---3(最高))
	unsigned char		m_out[8];			//联动报警输出  
	TIMELIST			pTimeList;			//检测时间
}CHANNELHIDEALARMEX;

typedef struct
{
	int					m_benbale;			//定时重启使能
	int					m_invalidtime;		//间隔时间(以小时为单位，10-240即:10小时至10天)
	int					m_rsthour;			//重启小时
	int					m_rstminute;		//重启分钟
}VSTIMERRESET;

typedef struct
{
	char				m_hostserverurl[40];   
	                                        //录像IP
	char				m_alarservermurl[40];    
	                                        //报警IP 
	unsigned short		m_hostserverport;   //录像端口
	unsigned short		m_alarserverport;   //报警端口
}VSREMOTEHOST;

typedef struct
{
	int					m_streamType;		//码流类型:视频流、视音频流
   	int					m_encodeType;		//图像格式CIF,2CIF,4CIF
	int					m_Iinterval;        //关键帧间隔(10-200)
	int					m_videoFrameRate;   //帧率
	int					m_bitratetype;      //码率控制类型：CBR & VBR
	int					m_maxqueue;         //VBR 量化系数(2-31)
	int					m_minqueue;         //CBR 量化系数(2-31)
	int					m_maxbitrates;      //CBR 最大码率(64K-8000K)
}VSSUBCHANPARAM;

typedef struct
{
	int					m_hds;			   //硬盘总数 
	int					m_hdtype[8];	   //硬盘类型
	int					m_hdstate[8];      //硬盘状态
	int					m_totalsize[8];	   //硬盘空间大小
	int					m_freesize[8];	   //硬盘剩余空间
}VSDISKSTATE;

typedef struct 
{
	unsigned int		m_channel;         //通道号
	unsigned short		m_detectall;       //所有报警和
	unsigned char		m_detect[18][22];  //报警块
}VSNETVIDEOMOVE_BLOCK;

typedef struct 
{
	int					m_busepppoe;		//使用PPPOE
	char				m_pppoename[64];	//PPPOE用户名
	char				m_pppoepswd[64];	//PPPOE密码
}VSNETPPPOEPARAM;

typedef struct 
{
	int					m_storecycle;		//硬盘是否循环使用(1:循环; 0:停止)
	int 				m_reservedsize;		//硬盘保留空间
	int 				m_reserved1;		//保留一
	int 				m_reserved2;		//保留二
}VSNETRECORDPARAM;

typedef struct 
{
	int					m_bsinglehost;		//上传中心标志
	unsigned char		m_out[8];			//对应的报警输出
	TIMELIST			m_timelist;			//检测时间
}VSNETVIDEOLOSTPARAM;

typedef struct
{
	unsigned char		m_caprate;			//抓拍帧率(1-5)
	unsigned char		m_encquant;			//抓拍质量(JPEG,1-100)
	unsigned char		m_encformat;		//抓拍格式(CIF,2CIF,4CIF)
	unsigned char		m_reserved;			//保留        
	int					m_capnums;			//抓拍帧数(-1为持续抓拍)
}VSNETJPEGCAPPARAM;					    

typedef struct
{
	char				m_serverIP[40];		//服务器IP
	unsigned int		m_port;				//服务器端口
	unsigned int		m_intervaltime;		//间隔时间
	char				m_senddata[512];	//发送数据
}VSNETHOSTNOTIFY;

typedef struct
{
	char				m_alarmname[32];	//报警探头名称
	int                 m_senseorinterval;  //探头报警间歇时间
}VSNETSENSORALARM;

typedef struct
{
	int  m_videolossinterval;	//视频丢失间歇时间
	int  m_videomoveinterval;	//视频移动间歇时间
	int  m_videohideinterval;	//探头遮挡间歇时间
	int  m_reserved;		    //保留
}VSNETALARMINTERVAL;            //报警间歇时间

typedef struct
{
	int m_audioinline;		//1:线性输入  0:Mic输入
	int m_audioinDBline;    //线性输入时发大比例(-34 - +12DB)范围(0-100)
	int m_audioinDBMic;     //Mic输入时发大比例(0,20DB)范围(0-1)
	int m_audiooutDB;       //输出时发大比例(-73 - +6DB)范围(0-100)
}VSNETAUDIOPARAM;	        //音频参数结构

typedef struct 
{
    int             m_usecdma;      //使用cdma
}VSNETCDMAPARAM;

typedef struct 
{
    int             m_usewifi;			//使用无线
    char	    	m_wifiipaddr[16];   //无线IP地址
    char	    	m_wifinetmask[16];  //无线MASK地址
    char	    	m_wifigateway[16];  //无线网关
    char            m_wifidns[16];      //无线DNS
    char            m_wifissid[40];     //无线ssid
    int             m_wifiencmode;      //加密方式 0,无加密 1,wep-60  2,wep-128
    char            m_wifipwd[64];      //密钥 wep-60(5个ASCII or 10个HEX) wep-128(13个ASCII or 26个HEX) 
}VSNETWIFIPARAM;

typedef struct
{
	char			m_deviceID[32];		//设备ID
	int				m_maxconnect;		//最大连接数，按每通道5路计算
	int				m_linktype;			//连接类型,1:LAN,2:ADSL,3:其他
	char			m_ftpuser[20];		//ftp用户名
	char			m_ftppass[20];		//ftp密码 
	char			m_devicemodel[32];  //设备型号
	int				m_sipport;          //sip信令端口
}VSNETLINKCONFIG;						//连接配置

typedef struct
{
	int				m_dnsprovider;     //ddns 提供者
	int             m_ddnsnotifytime;  //ddns 更新时间
	char			m_dnsusername[20]; //ddns 用户名
	char			m_dnspassword[20]; //ddns 密码
	char            m_dnsdomainname[50]; //dns域名名称
}VSNETDNSEXPARAM;

typedef struct
{
	int				m_comport;				//串口号
	int				m_protocol;				//串口协议
	int				m_addr;					//设备地址
	int				m_alarmchecktime;		//报警检测时间
	int				m_alarmintervaltime;	//报警间隔时间
}VSNETEXALARMPARAM;

typedef struct
{
	int				m_benablecheck;			//启动温度检测
	TIMELIST    	m_timeList;				//检测时间
	char            m_boutput[8];			//对应的报警输出,每一位对应相应的报警输出
	char			m_record[16];           //录像标志
	char			m_capture[16];          //抓图标志
	int             m_delay;				//报警延迟时间
	int             m_singlehost;			//上传中心
	float           m_tempmax;              //温度最大值
	float           m_tempmin;              //温度最小值
	float           m_hummax;               //湿度最大值
	float           m_hummin;               //湿度最小值
}VSNETHUMITUREPRAM;

typedef struct
{
	int             m_xoffset;              //水平偏移 0 - 8
}VSNETVIDEOOFFSET;

typedef struct
{
	unsigned short		m_x;				//x
	unsigned short		m_y;				//y
	unsigned short		m_width;			//width
	unsigned short		m_height;			//height
}VSNETVIDEOMASKAREA;

typedef struct
{
	int					m_bmask;			//图像屏蔽使能
    VSNETVIDEOMASKAREA  m_maskarea[4];      //图像屏蔽区域
}VSNETVIDEOMASK;

/***************** 远程检索、下载、播放 ****************/
typedef struct{
	int					m_year;				//年
	unsigned char		m_month;			//月
	unsigned char		m_day;				//日
	unsigned char		m_hour;				//时
	unsigned char		m_minute;			//分
	unsigned char		m_second;			//秒
	unsigned char		Received[3];		//保留
}VSNETPLAY_NETTIME;

typedef struct
{
	int					m_channel;			//通道号
	char				sFileName[100];		//文件名
	VSNETPLAY_NETTIME	struStartTime;		//文件的开始时间
	VSNETPLAY_NETTIME	struStopTime;		//文件的结束时间
	unsigned int		dwFileSize;			//文件的大小
}VSNETPLAY_FIND_DATA;

/*********************************************************/
#endif//__VSNET_STRUCTDEF_H__
