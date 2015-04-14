// VideoChannel.cpp: implementation of the CVideoChannel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VideoChannel.h"
#include "PlayDemo.h"
#include "PlayDemoDlg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern CPlayDemoDlg *m_maindlg;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
static void WINAPI s_messagecallback(LONG hHandle,int wParam,int lParam,void *context)
{
	CVideoChannel *pchannel = (CVideoChannel*)context;
	if(wParam != LAUMSG_LINKMSG)
	{
		pchannel->AlarmProcess(wParam,lParam);
		return;    //alarm message
	}
	PostMessage(m_maindlg->m_hWnd,VIDEOWND_MSG,DWORD(context),lParam);
}

/*Note:In video and audio callback function,you must return as soon as possible.
otherwise,you will lost frames or connection broken. */
/*
pbuff:       MPEG4 video data;have vol header,just send this data to decoder or save to disk.
size:        MPEG4 video data length;
timetick:    MPEG4 time tick(ms)
biskeyframe: TRUE: key frame(I frame), FALSE : other
*/
static void WINAPI m_nomalvideo(char *pbuff,int size,int timetick,int biskeyframe,void *context)
{
	CVideoChannel *pParent = (CVideoChannel*)context;
	//TRACE("get video data size:%d,timetick:%d,wnd:%d\n",size,timetick,pParent);

	if(pParent->m_pavivideo && (pParent->m_videonum > 0 || biskeyframe)) //first to write key frame
	{
		if(!AVIStreamWrite(pParent->m_pavivideo,pParent->m_videonum, 1, pbuff, size, biskeyframe ? AVIIF_KEYFRAME : 0, NULL, NULL))
		{
			pParent->m_videonum ++;
		}
	}
}
/*
pbuff:       MP3 audio data;just send this data to decoder or save to disk.
size:        MP3 audio data length;
timetick:    MP3 time tick(ms)
biskeyframe: Not used.
*/
static void WINAPI m_nomalaudio(char *pbuff,int size,int timetick,int biskeyframe,void *context)
{
	CVideoChannel *pParent = (CVideoChannel*)context;
	//TRACE("get audio data size:%d,timetick:%d,wnd:%d\n",size,timetick,pParent);
	if(pParent->m_paviaudio && pParent->m_videonum > 0)  //write after video
	{
		if(!AVIStreamWrite(pParent->m_paviaudio, pParent->m_audionum, 1, pbuff, size, 0, NULL, NULL))
		{
			pParent->m_audionum ++;
		}
	}
}


CVideoChannel::CVideoChannel()
{
	m_hchann = -1;
	m_audionum = m_videonum = 0;
	m_pavifile = NULL;
	m_pavivideo = NULL;
	m_paviaudio = NULL;
	memset(&m_camitem,0,sizeof(CAM_DECITEM));

	m_timernum = 0;           //set to relink
	m_starttimer = FALSE;
}

CVideoChannel::~CVideoChannel()
{
	StopPlay();
}

void CVideoChannel::LoadCamera(LPCSTR url,int channel,LPCSTR sername,WORD port,LPCSTR username,LPCSTR password,
							   int transtype,HWND videownd)
{
	strcpy(m_camitem.m_sername,sername);
	strcpy(m_camitem.m_url,url);
	m_camitem.m_ch = channel;
	m_camitem.m_trantype = transtype;
	m_camitem.m_port = port;
	strcpy(m_camitem.m_username,username);
	strcpy(m_camitem.m_password,password);
	m_camitem.m_videownd = videownd;
}

int CVideoChannel::StartPlay()
{
	if(m_hchann != -1)
	{
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
	}
	aviclosefile();
	m_timernum = 0;           //set to relink
	m_starttimer = FALSE;


	CHANNEL_CLIENTINFO m_chinfo;

	m_chinfo.m_buffnum    = 50;
	m_chinfo.m_ch         = m_camitem.m_ch;
	m_chinfo.m_hChMsgWnd  = NULL;
	m_chinfo.m_hVideohWnd = m_camitem.m_videownd;
	m_chinfo.m_nChmsgid   = NULL;
	m_chinfo.m_password   = m_camitem.m_password;
	m_chinfo.m_playstart  = TRUE;
	m_chinfo.m_sername    = m_camitem.m_sername;
	m_chinfo.m_tranType   = m_camitem.m_trantype;
	m_chinfo.m_useoverlay = FALSE;
	m_chinfo.m_username   = m_camitem.m_username;
	m_chinfo.nColorKey    = RGB(255,0,255);
	m_chinfo.context      = this;
	m_chinfo.m_messagecallback = s_messagecallback;
	m_hchann = VSNET_ClientStart(m_camitem.m_url,&m_chinfo,m_camitem.m_port);
	if(m_hchann == -1)
	{
		return -1;
	}
	return 0;
}

void CVideoChannel::StopPlay()
{
	if(m_hchann != -1)
	{
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
	}
	aviclosefile();
	m_timernum = 0;           //set to relink
	m_starttimer = FALSE;
}

void CVideoChannel::RelinkTimer()
{
	m_timernum = 0; 
	m_starttimer = FALSE;
	StartPlay();
}

void CVideoChannel::AlarmProcess(int wParam,int lParam)
{
	if(wParam == LAUMSG_VIDEOMOTION)
	{
		//video move alarm
	}
	else if(wParam == LAUMSG_ALARM)
	{
		//sensor alarm
	}
	else if(wParam == LAUMSG_VIDEOLOST)
	{
		//video lost alarm
	}
	else if(wParam == LAUMSG_OUTPUTSTATUS)
	{
		//output status changed
	}
	else if(wParam == LAUMSG_CURSWITCHCHAN)
	{
		//channel switch
	}
}
void CVideoChannel::LinkProcess(int lParam)
{
	if(lParam == 0)
	{
		TRACE("Connect successful\n");
		aviopenfile();
		VSNET_ClientStartNomalCap(m_hchann,m_nomalvideo,this,m_nomalaudio,this); //get raw data
	}
	else
	{
		TRACE("Connect failed\n");
		StopPlay();

		m_timernum = 0;           //set to relink
		m_starttimer = TRUE;
	}
}
/*******************open avi file*****************************
note: this avi file property: video format:MPEG4,audio format:Mp3
8000 and 9000 serials support this format,but 6000 serials audio format is G722
and 5000 serials video format is H264,audio format is G722.
you should call VSNET_ClientGetStreamInfo to get this format.

BOOL VSNET_ClientGetStreamInfo(LONG hHandle,VSTREAMINFO *m_pStreamInfo)
Explanation: Get stream information
Parameters Explanation:
hHandle:         Channel connect handle, return value of VSNET_ClientStart;
m_pStreamInfo:   Pointer to VSTREAMINFO;
Return Value: TURE(1) if the operation is successful, otherwise, it is FALSE(0);

VSTREAMINFO structure:
typedef struct
{
DWORD m_videotag;
short m_width,m_height;
BOOL  m_bhaveaudio;
int   m_samplesize;
WORD  m_audiotag;
WORD  m_audiobitrate;
}VSTREAMINFO;
Explanation:
m_videotag:       Video CODEC tag£»0X34363248:H264(lc5000) ; 0X58564944 : DIVX(lc8000,lc9000,lc6000)
m_width,m_height: Video image size;
m_bhaveaudio:     Have audio flag, TRUE: Have audio data, FALSE: No audio data;
m_samplesize:     Sample size of audio;
m_audiotag:       Audio CODEC tag; 0xFE:G722(lc5000,lc6000); 0x55: mp3(lc8000,lc9000)
m_audiobitrate:   Audio bit rate;
aduio channel:    Always 1.
*************************************************************/
int CVideoChannel::aviopenfile()
{
	int iRet;
	AVISTREAMINFO strhdr;
	HRESULT hr;
	VSTREAMINFO streaminfo;
	char filename[MAX_PATH];

	m_audionum = m_videonum = 0;
	sprintf(filename,"c:\\avitest_%d.avi",this);
	iRet = AVIFileOpen(&m_pavifile,filename, OF_WRITE | OF_CREATE, NULL);
	if (iRet != AVIERR_OK)
	{
		goto err_exit;
	}

	if(VSNET_ClientGetStreamInfo(m_hchann,&streaminfo)) //get stream info
	{
		if(streaminfo.m_bhaveaudio && m_paviaudio == NULL)
		{
			MPEGLAYER3WAVEFORMAT mp3format;
			mp3format.wfx.cbSize = MPEGLAYER3_WFX_EXTRA_BYTES;
			mp3format.wfx.wFormatTag = WAVE_FORMAT_MPEGLAYER3;
			mp3format.wfx.nChannels = 1; //always one channel
			mp3format.wfx.nAvgBytesPerSec = streaminfo.m_audiobitrate * 1000 /8;  
			mp3format.wfx.wBitsPerSample = 0;	// MUST BE ZERO
			mp3format.wfx.nBlockAlign = 1;      // MUST BE ONE
			mp3format.wfx.nSamplesPerSec = streaminfo.m_samplesize;   
			mp3format.fdwFlags = MPEGLAYER3_FLAG_PADDING_OFF;
			mp3format.nBlockSize = streaminfo.m_audiobitrate * 1000 * 144 / streaminfo.m_samplesize;                        // voodoo value #1
			mp3format.nFramesPerBlock = 1;                     // MUST BE ONE
			mp3format.nCodecDelay = 1393;                      // voodoo value #2
			mp3format.wID = MPEGLAYER3_ID_MPEG;

			memset(&strhdr, 0, sizeof(strhdr));
			strhdr.fccType = streamtypeAUDIO;
			strhdr.dwScale = mp3format.wfx.nBlockAlign;
			strhdr.dwRate = mp3format.wfx.nAvgBytesPerSec; 
			strhdr.dwSampleSize= mp3format.wfx.nBlockAlign;
			strhdr.dwQuality=(DWORD)-1;
			hr = AVIFileCreateStream(m_pavifile, &m_paviaudio, &strhdr);
			if (hr!=AVIERR_OK) 
			{
				goto err_exit;
			}
		    hr = AVIStreamSetFormat(m_paviaudio,0,&mp3format,sizeof(MPEGLAYER3WAVEFORMAT));
			if (hr!=AVIERR_OK) 
			{
				goto err_exit;
			}
		}
		if(m_pavivideo == NULL)
		{
			BITMAPINFOHEADER myBitmapInfoHeader;
			memset(&myBitmapInfoHeader, 0, sizeof(BITMAPINFOHEADER));
			myBitmapInfoHeader.biHeight = streaminfo.m_height;
			myBitmapInfoHeader.biWidth = streaminfo.m_width;
			myBitmapInfoHeader.biPlanes = 1;
			myBitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
			myBitmapInfoHeader.biCompression =  mmioFOURCC('X','V','I','D');
			myBitmapInfoHeader.biBitCount = 24;
			myBitmapInfoHeader.biSizeImage = 6* streaminfo.m_width * streaminfo.m_height;

			memset(&strhdr, 0, sizeof(strhdr));
			strhdr.fccType = streamtypeVIDEO;
			strhdr.fccHandler = mmioFOURCC('X','V','I','D');
			strhdr.dwScale = 1;
			strhdr.dwRate = 25; //25 frame (PAL) default
			strhdr.dwSuggestedBufferSize = 0;
			strhdr.dwQuality = (DWORD)-1;
			SetRect(&strhdr.rcFrame, 0, 0, streaminfo.m_width, streaminfo.m_height);

			hr = AVIFileCreateStream(m_pavifile,&m_pavivideo,&strhdr); 
			if (hr!=AVIERR_OK) 
			{
				goto err_exit;
			}		
			hr = AVIStreamSetFormat(m_pavivideo, 0, &myBitmapInfoHeader, sizeof(BITMAPINFOHEADER)); 
			if (hr!=AVIERR_OK) 
			{
				goto err_exit;
			}
		}
		return 0;
	}	
err_exit:
	if(m_paviaudio) AVIStreamRelease(m_paviaudio); m_paviaudio = NULL;
	if(m_pavivideo) AVIStreamRelease(m_pavivideo); m_pavivideo = NULL;
	if(m_pavifile) AVIFileRelease(m_pavifile);	m_pavifile = NULL;
	return -1;
}

/*******************close avi file*****************************/
void CVideoChannel::aviclosefile()
{
	if(m_paviaudio) AVIStreamRelease(m_paviaudio); m_paviaudio = NULL;
	if(m_pavivideo) AVIStreamClose(m_pavivideo); m_pavivideo = NULL;
	if(m_pavifile) AVIFileRelease(m_pavifile);	m_pavifile = NULL;
}
