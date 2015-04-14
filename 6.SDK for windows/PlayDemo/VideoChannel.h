// VideoChannel.h: interface for the CVideoChannel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOCHANNEL_H__D1736789_C3E0_4E20_88A2_304B89946F22__INCLUDED_)
#define AFX_VIDEOCHANNEL_H__D1736789_C3E0_4E20_88A2_304B89946F22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVideoChannel  
{
public:
	CVideoChannel();
	virtual ~CVideoChannel();
public:
	LONG        m_hchann;      //connect handle
	BOOL        m_starttimer;  //relink timer start
	int         m_timernum;    //relink timer count
	CAM_DECITEM m_camitem;     //link paramerters 

public:
	void        LoadCamera(LPCSTR url,int channel,LPCSTR sername,WORD port,LPCSTR username,LPCSTR password,
							   int transtype,HWND videownd);
	int         StartPlay();
	void        StopPlay();
	void        AlarmProcess(int wParam,int lParam);
	void        RelinkTimer();
	void        LinkProcess(int lParam);
protected:
	int         aviopenfile();
	void        aviclosefile();
public:
	PAVIFILE   m_pavifile;
	PAVISTREAM m_paviaudio;
	PAVISTREAM m_pavivideo;
	int        m_audionum,m_videonum;
};

#endif // !defined(AFX_VIDEOCHANNEL_H__D1736789_C3E0_4E20_88A2_304B89946F22__INCLUDED_)
