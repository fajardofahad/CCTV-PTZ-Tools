//VSNETStructDef.h
#ifndef __VSNET_STRUCTDEF_H__
#define __VSNET_STRUCTDEF_H__

enum{
	VSNETALARMMSG_SERSTART = 1,	/* ���������� */	
	VSNETALARMMSG_MOTION,		/* �ƶ���ⱨ�� */
	VSNETALARMMSG_VIDEOLOST,	/* ��Ƶ��ʧ���� */
	VSNETALARMMSG_SENSOR,		/* ̽ͷ���� */
	VSNETALARMMSG_DISKFULL,		/* Ӳ�������� */
	VSNETALARMMSG_HIDEALARM,	/* ��Ƶ�ڵ����� */	
	VSNETALARMMSG_SERSTOP,		/* ������ֹͣ */
};

/*ת���û�Ȩ��*/
#define VSNET_USER_RIGHT_ADMIN		1	//����ԱȨ��
#define VSNET_USER_RIGHT_HIOPER		2	//�߼�����Ա
#define VSNET_USER_RIGHT_OPERIAL	3	//����Ա

typedef struct
{
	char				m_username[20];		//�û���
	char				m_password[20];		//����
}ONEUSER;

typedef struct
{
	ONEUSER				m_admin;			//����Ա
	ONEUSER				hl_operator[10];	//�߼�����Ա
	ONEUSER				m_operator[10];		//����Ա
}WHOLE_USER;
typedef struct
{
	int					bUseDDNS;			//DDNSʹ��
	char				DDNSSerIp[40];		//DDNS������IP
	unsigned short		DDNSSerPort;		//DDNS�������˿�
	unsigned short		LocalMapPort;		//���ض˿�
}WHOLE_DDNS;
typedef struct
{
	char				pStrBSPVer[50];		//BSP�汾
	char				pStrAPPVer[50];		//Ӧ�ó���汾��
	char				pStrBSPBuildTime[50];
											//BSP����ʱ��
	char				pStrAPPBuildTime[50];
											//Ӧ�ó������ʱ��
}VERSIONINFO;
typedef struct{
	char				m_servername[24];	//����������
	char				m_serverip[16];		//IP��ַ
	char				m_servermask[16];	//��������
	char				m_gatewayAddr[16];	//����
	char				m_dnsaddr[16];		//dns��ַ
	char				m_multiAddr[16];	//�ಥ��ַ	
	unsigned short		m_serport;			//���ݶ˿�
	unsigned short		m_mulport;			//�ಥ�˿�
	unsigned short		m_webport;			//��ҳ�˿�
	unsigned char		m_isPAL;			//��Ƶ��ʽ(PAL,NTSC)
	unsigned char		m_launage;			//����
	unsigned char		m_phyAddr[6];		//�����ַ
	unsigned short		m_reserved;         //����
	unsigned char		m_serial[8];		//���к�
	WHOLE_DDNS			m_ddns;				//DDNS����
	VERSIONINFO			m_version;			//�汾
}WHOLEPARAM;

typedef struct{
	char				m_servername[60];	//����������
	char				m_serverip[16];		//IP��ַ
	char				m_servermask[16];	//��������
	char				m_gatewayAddr[16];	//����
	char				m_dnsaddr[16];		//dns��ַ
	char				m_multiAddr[16];	//�ಥ��ַ	
	unsigned short		m_serport;			//���ݶ˿�
	unsigned short		m_mulport;			//�ಥ�˿�
	unsigned short		m_webport;			//��ҳ�˿�
	unsigned char		m_isPAL;			//��Ƶ��ʽ(PAL,NTSC)
	unsigned char		m_launage;			//����
	unsigned char		m_phyAddr[6];		//�����ַ
	unsigned short		m_reserved;         //����
	unsigned char		m_serial[8];		//���к�
	WHOLE_DDNS			m_ddns;				//DDNS����
	VERSIONINFO			m_version;			//�汾
}WHOLEPARAMEX;

typedef struct
{
	unsigned char		m_starthour;		//��ʼСʱ
	unsigned char		m_startmin;			//��ʼ����
	unsigned char		m_stophour;			//ֹͣСʱ
	unsigned char		m_stopmin;			//ֹͣ����
	unsigned char		m_maskweek;			//��
	unsigned char		bReceive[3];		//����
}TIMECHECK;

typedef struct
{
	TIMECHECK			pList[7];			//ʱ���
}TIMELIST;

typedef struct
{
	unsigned char		m_beanb;             //�ƶ��������
	unsigned char		m_alarmsenstive;     //�ƶ����������
	unsigned char		m_brecord;           //������¼��
	unsigned char		bReceive;            //����
	unsigned char		m_outputmap[8];      //��������� 
	unsigned char		m_detect[18][22];    //��ⷶΧ
	TIMELIST			m_timelist;          //���ʱ��� 
}CHANNMOTION;

typedef struct
{
	unsigned char		m_beanb;             //�ƶ��������
	unsigned char		m_alarmsenstive;     //�ƶ����������
	unsigned char		m_brecord;            //������¼��
	unsigned char		m_capjpeg;           //������jpegץͼ
	unsigned char		m_singlehost;        //�ϴ�����
	unsigned char		m_reseved1;          //����
	unsigned char		m_reseved2;          //����
	unsigned char		m_reseved3;          //����
	unsigned char		m_outputmap[8];      //��������� 
	unsigned char		m_detect[18][22];    //��ⷶΧ
	TIMELIST			m_timelist;          //���ʱ��� 
}CHANNMOTIONEX;

typedef struct
{
	int					nFormat;			//��ʾ��ʽ
	unsigned short		x,y;				//��ʾ����
}TIMEOSD;

typedef struct
{
	int					bShow;				//��ʾ(1),����ʾ(0)
	unsigned short		x,y;				//��ʾ����
}BITSINFOOSD;

typedef struct
{
	char				lpString[32];		//��ʾ�ַ�		
	unsigned short		x,y;				//����
}TITALOSD;

typedef struct
{
	TIMEOSD				m_time;				//ʱ��
	TITALOSD			m_tital[4];			//����
	BITSINFOOSD			m_bits;				//����
}CHANNOSD;

typedef struct
{
	int					m_bmask;			//ͼ������ʹ��
	unsigned short		m_x;				//x
	unsigned short		m_y;				//y
	unsigned short		m_width;			//width
	unsigned short		m_height;			//height
}CHANNVIDEOMASK;

typedef struct
{
	unsigned char		m_bri;				//ͼ������
	unsigned char		m_con;				//ͼ��Աȶ�
	unsigned char		m_sat;				//ͼ�񱥺Ͷ�
	unsigned char		m_hue;				//ͼ��ɫ��
}CHANNVIPARAM;

typedef struct
{
	char				m_channelName[16];	//ͨ������
   	int					m_streamType;		//��������:��Ƶ��������Ƶ��
   	int					m_encodeType;		//ͼ���ʽCIF,2CIF,4CIF
	int					m_Iinterval;		//�ؼ�֡���(10-200)
	int					m_videoFrameRate;	//֡��
	int					m_bitratetype;		//���ʿ������ͣ�CBR & VBR
	int					m_maxqueue;			//VBR ����ϵ��(2-31)
	int					m_minqueue;			//CBR ����ϵ��(2-31)
	int					m_maxbitrates;		//CBR �������(64K-8000K)
	int					m_audiosample;		//��Ƶ����Ƶ��
	int					m_audiobitrate;		//��Ƶ����
	int					m_delay;			//�����ӳ�
	int					m_benrecord;		//��ʱ¼��ʹ��
	TIMELIST			m_record;			//��ʱ¼��ʱ���
}CHANNELPARAM;

typedef struct
{
	char				m_channelName[60];	//ͨ������
   	int					m_streamType;		//��������:��Ƶ��������Ƶ��
   	int					m_encodeType;		//ͼ���ʽCIF,2CIF,4CIF
	int					m_Iinterval;		//�ؼ�֡���(10-200)
	int					m_videoFrameRate;	//֡��
	int					m_bitratetype;		//���ʿ������ͣ�CBR & VBR
	int					m_maxqueue;			//VBR ����ϵ��(2-31)
	int					m_minqueue;			//CBR ����ϵ��(2-31)
	int					m_maxbitrates;		//CBR �������(64K-8000K)
	int					m_audiosample;		//��Ƶ����Ƶ��
	int					m_audiobitrate;		//��Ƶ����
	int					m_delay;			//�����ӳ�
	int					m_benrecord;		//��ʱ¼��ʹ��
	TIMELIST			m_record;			//��ʱ¼��ʱ���
}CHANNELPARAMEXNAME;

typedef struct
{
	char				m_channelName[16];	//ͨ������
   	int					m_streamType;		//��������:��Ƶ��������Ƶ��
   	int					m_encodeType;		//ͼ���ʽCIF,2CIF,4CIF
	int					m_Iinterval;		//�ؼ�֡���(10-200)
	int					m_videoFrameRate;	//֡��
	int					m_bitratetype;		//���ʿ������ͣ�CBR & VBR
	int					m_maxqueue;			//VBR ����ϵ��(2-31)
	int					m_minqueue;			//CBR ����ϵ��(2-31)
	int					m_maxbitrates;		//CBR �������(64K-8000K)
	int					m_audiosample;		//��Ƶ����Ƶ��
	int					m_audiobitrate;		//��Ƶ����
	int					m_delay;			//�����ӳ�
	int                 m_nPrerecordTime;   //Ԥ¼ʱ��(0Ϊ�ر�,1-10��ʱ��)
	int                 m_videofilebackup;  //��Ƶ�ļ�����(0,1,2�ֱ��ʾ���ϴ�,�ϴ������ļ�,ȫ���ļ�)
	int                 m_jpegfilebackup;	//Jpeg�ļ�����(0,1,2�ֱ��ʾ���ϴ�,�ϴ������ļ�,ȫ���ļ�)
	int					m_benrecord;		//��ʱ¼��ʹ��
	TIMELIST			m_record;			//��ʱ¼��ʱ���
}CHANNELPARAMEX;

typedef struct{
	int					m_baudrate;			//������
	int					decoderModel;       //Э������(��ʹ��)
	unsigned char		m_databit;			//����λ
	unsigned char		m_stopbit;			//ֹͣλ
	unsigned char		m_checkbit;			//Ч��λ
	unsigned char		m_flowcontrol;		//����
	unsigned char		decoderAddress;		//��������ַ
	unsigned char		bReceive[3];		//����
}SERIAL485_PARAM;

typedef struct{
	int					baudrate;			//������
	char				databit;			//����λ
	char				stopbit;            //ֹͣλ
	char				checkbit;			//У��λ
	char				flowcontrol;        //����
}VSSERIAL_INFO;

typedef struct
{
	int					m_year;				//��
	unsigned char		m_month;			//��
	unsigned char		m_dayofmonth;		//��
	unsigned char		m_dayofweek;        //����
	unsigned char		m_hour;             //Сʱ
	unsigned char		m_minute;			//��
	unsigned char		m_second;			//��
	unsigned char		bReceive[2];		//����
}TIME_PARAM;

typedef struct
{
	unsigned char		m_record[16];		//������¼��
	unsigned char		m_out[8];			//���������
	unsigned char		m_enpreno[16];		//����������Ԥ�õ�
	unsigned char		m_preno[16];		//����Ԥ�õ��
	TIMELIST			m_timelist;			//���ʱ���
}ALARMRECORD;

typedef struct
{
	int					m_alarmmode;		//����ģʽ0������,1������
	int					m_singlehost;		//�����ź��ϴ����ı�־
	unsigned char		m_record[16];		//������¼��
	unsigned char		m_out[8];			//���������
	unsigned char		m_enpreno[16];		//����������Ԥ�õ�
	unsigned char		m_preno[16];		//����Ԥ�õ��
	unsigned char		m_capjpeg[16];		//������ץ��
	TIMELIST			m_timelist;			//���ʱ���
}ALARMRECORDEX;

typedef struct
{
	int					m_benab;			//����������־
	ALARMRECORD			m_alarmrec[8];		//������������
}ALARMPARAM;

typedef struct
{
	int					m_benab;            //����������־
	ALARMRECORDEX		m_alarmrec[8];      //������������
}ALARMPARAMEX;

typedef struct{
	int					m_chanuser[16];		//ͨ��
	unsigned char		m_chanIP[16][20][4];//���ӵ�IP��ַ
}CONNECTIP;

typedef struct{
	unsigned long		m_videotag;         //��Ƶtag
	short				m_width,m_height;   //��Ƶ�ߴ�
	int					m_bhaveaudio;       //������Ƶ   
	int					m_samplesize;       //��Ƶ����Ƶ��
	unsigned short		m_audiotag;         //��Ƶtag
	unsigned short		m_audiobitrate;		//��Ƶ����
}VSTREAMINFO;

typedef struct{
	unsigned long		m_url;				//��ַ
	char				m_sername[24];		//����������
	int					m_ch;				//ͨ��
	int					trantype;			//�������� 
	long				handle;				//���
}VSUSERINFO;

typedef struct
{
	int					m_benable;			//�ڵ��������
	int					m_decval;			//���������(1(���)---3(���))
	unsigned char		m_out[8];			//�����������  
	TIMELIST			pTimeList;			//���ʱ��
}CHANNELHIDEALARM;

typedef struct
{
	int					m_benable;			//�ڵ��������
	int					m_bsinglehost;		//�����ź��ϴ����ı�־
	int					m_decval;			//���������(1(���)---3(���))
	unsigned char		m_out[8];			//�����������  
	TIMELIST			pTimeList;			//���ʱ��
}CHANNELHIDEALARMEX;

typedef struct
{
	int					m_benbale;			//��ʱ����ʹ��
	int					m_invalidtime;		//���ʱ��(��СʱΪ��λ��10-240��:10Сʱ��10��)
	int					m_rsthour;			//����Сʱ
	int					m_rstminute;		//��������
}VSTIMERRESET;

typedef struct
{
	char				m_hostserverurl[40];   
	                                        //¼��IP
	char				m_alarservermurl[40];    
	                                        //����IP 
	unsigned short		m_hostserverport;   //¼��˿�
	unsigned short		m_alarserverport;   //�����˿�
}VSREMOTEHOST;

typedef struct
{
	int					m_streamType;		//��������:��Ƶ��������Ƶ��
   	int					m_encodeType;		//ͼ���ʽCIF,2CIF,4CIF
	int					m_Iinterval;        //�ؼ�֡���(10-200)
	int					m_videoFrameRate;   //֡��
	int					m_bitratetype;      //���ʿ������ͣ�CBR & VBR
	int					m_maxqueue;         //VBR ����ϵ��(2-31)
	int					m_minqueue;         //CBR ����ϵ��(2-31)
	int					m_maxbitrates;      //CBR �������(64K-8000K)
}VSSUBCHANPARAM;

typedef struct
{
	int					m_hds;			   //Ӳ������ 
	int					m_hdtype[8];	   //Ӳ������
	int					m_hdstate[8];      //Ӳ��״̬
	int					m_totalsize[8];	   //Ӳ�̿ռ��С
	int					m_freesize[8];	   //Ӳ��ʣ��ռ�
}VSDISKSTATE;

typedef struct 
{
	unsigned int		m_channel;         //ͨ����
	unsigned short		m_detectall;       //���б�����
	unsigned char		m_detect[18][22];  //������
}VSNETVIDEOMOVE_BLOCK;

typedef struct 
{
	int					m_busepppoe;		//ʹ��PPPOE
	char				m_pppoename[64];	//PPPOE�û���
	char				m_pppoepswd[64];	//PPPOE����
}VSNETPPPOEPARAM;

typedef struct 
{
	int					m_storecycle;		//Ӳ���Ƿ�ѭ��ʹ��(1:ѭ��; 0:ֹͣ)
	int 				m_reservedsize;		//Ӳ�̱����ռ�
	int 				m_reserved1;		//����һ
	int 				m_reserved2;		//������
}VSNETRECORDPARAM;

typedef struct 
{
	int					m_bsinglehost;		//�ϴ����ı�־
	unsigned char		m_out[8];			//��Ӧ�ı������
	TIMELIST			m_timelist;			//���ʱ��
}VSNETVIDEOLOSTPARAM;

typedef struct
{
	unsigned char		m_caprate;			//ץ��֡��(1-5)
	unsigned char		m_encquant;			//ץ������(JPEG,1-100)
	unsigned char		m_encformat;		//ץ�ĸ�ʽ(CIF,2CIF,4CIF)
	unsigned char		m_reserved;			//����        
	int					m_capnums;			//ץ��֡��(-1Ϊ����ץ��)
}VSNETJPEGCAPPARAM;					    

typedef struct
{
	char				m_serverIP[40];		//������IP
	unsigned int		m_port;				//�������˿�
	unsigned int		m_intervaltime;		//���ʱ��
	char				m_senddata[512];	//��������
}VSNETHOSTNOTIFY;

typedef struct
{
	char				m_alarmname[32];	//����̽ͷ����
	int                 m_senseorinterval;  //̽ͷ������Ъʱ��
}VSNETSENSORALARM;

typedef struct
{
	int  m_videolossinterval;	//��Ƶ��ʧ��Ъʱ��
	int  m_videomoveinterval;	//��Ƶ�ƶ���Ъʱ��
	int  m_videohideinterval;	//̽ͷ�ڵ���Ъʱ��
	int  m_reserved;		    //����
}VSNETALARMINTERVAL;            //������Ъʱ��

typedef struct
{
	int m_audioinline;		//1:��������  0:Mic����
	int m_audioinDBline;    //��������ʱ�������(-34 - +12DB)��Χ(0-100)
	int m_audioinDBMic;     //Mic����ʱ�������(0,20DB)��Χ(0-1)
	int m_audiooutDB;       //���ʱ�������(-73 - +6DB)��Χ(0-100)
}VSNETAUDIOPARAM;	        //��Ƶ�����ṹ

typedef struct 
{
    int             m_usecdma;      //ʹ��cdma
}VSNETCDMAPARAM;

typedef struct 
{
    int             m_usewifi;			//ʹ������
    char	    	m_wifiipaddr[16];   //����IP��ַ
    char	    	m_wifinetmask[16];  //����MASK��ַ
    char	    	m_wifigateway[16];  //��������
    char            m_wifidns[16];      //����DNS
    char            m_wifissid[40];     //����ssid
    int             m_wifiencmode;      //���ܷ�ʽ 0,�޼��� 1,wep-60  2,wep-128
    char            m_wifipwd[64];      //��Կ wep-60(5��ASCII or 10��HEX) wep-128(13��ASCII or 26��HEX) 
}VSNETWIFIPARAM;

typedef struct
{
	char			m_deviceID[32];		//�豸ID
	int				m_maxconnect;		//�������������ÿͨ��5·����
	int				m_linktype;			//��������,1:LAN,2:ADSL,3:����
	char			m_ftpuser[20];		//ftp�û���
	char			m_ftppass[20];		//ftp���� 
	char			m_devicemodel[32];  //�豸�ͺ�
	int				m_sipport;          //sip����˿�
}VSNETLINKCONFIG;						//��������

typedef struct
{
	int				m_dnsprovider;     //ddns �ṩ��
	int             m_ddnsnotifytime;  //ddns ����ʱ��
	char			m_dnsusername[20]; //ddns �û���
	char			m_dnspassword[20]; //ddns ����
	char            m_dnsdomainname[50]; //dns��������
}VSNETDNSEXPARAM;

typedef struct
{
	int				m_comport;				//���ں�
	int				m_protocol;				//����Э��
	int				m_addr;					//�豸��ַ
	int				m_alarmchecktime;		//�������ʱ��
	int				m_alarmintervaltime;	//�������ʱ��
}VSNETEXALARMPARAM;

typedef struct
{
	int				m_benablecheck;			//�����¶ȼ��
	TIMELIST    	m_timeList;				//���ʱ��
	char            m_boutput[8];			//��Ӧ�ı������,ÿһλ��Ӧ��Ӧ�ı������
	char			m_record[16];           //¼���־
	char			m_capture[16];          //ץͼ��־
	int             m_delay;				//�����ӳ�ʱ��
	int             m_singlehost;			//�ϴ�����
	float           m_tempmax;              //�¶����ֵ
	float           m_tempmin;              //�¶���Сֵ
	float           m_hummax;               //ʪ�����ֵ
	float           m_hummin;               //ʪ����Сֵ
}VSNETHUMITUREPRAM;

typedef struct
{
	int             m_xoffset;              //ˮƽƫ�� 0 - 8
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
	int					m_bmask;			//ͼ������ʹ��
    VSNETVIDEOMASKAREA  m_maskarea[4];      //ͼ����������
}VSNETVIDEOMASK;

/***************** Զ�̼��������ء����� ****************/
typedef struct{
	int					m_year;				//��
	unsigned char		m_month;			//��
	unsigned char		m_day;				//��
	unsigned char		m_hour;				//ʱ
	unsigned char		m_minute;			//��
	unsigned char		m_second;			//��
	unsigned char		Received[3];		//����
}VSNETPLAY_NETTIME;

typedef struct
{
	int					m_channel;			//ͨ����
	char				sFileName[100];		//�ļ���
	VSNETPLAY_NETTIME	struStartTime;		//�ļ��Ŀ�ʼʱ��
	VSNETPLAY_NETTIME	struStopTime;		//�ļ��Ľ���ʱ��
	unsigned int		dwFileSize;			//�ļ��Ĵ�С
}VSNETPLAY_FIND_DATA;

/*********************************************************/
#endif//__VSNET_STRUCTDEF_H__
