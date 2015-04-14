// DlgChanEnc.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgChanEnc.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChanEnc dialog


CDlgChanEnc::CDlgChanEnc(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChanEnc::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChanEnc)
	m_imageformat = 0;
	m_streamtype = 0;
	m_ikeyinterval = 100;
	m_samplerate = 0;
	m_audiobits = 0;
	m_framerate = 25;
	m_minqueue = 4;
	m_maxqueue = 31;
	m_maxbits = 512;
	m_bitstype = 0;
	m_subbitstype = 0;
	m_subframerate = 25;
	m_subikeyinterval = 100;
	m_subimagformat = 0;
	m_submaxqueue = 31;
	m_submaxrate = 512;
	m_subminqueue = 4;
	m_substreamtype = 0;
	m_alarmdelay = 30;
	m_prerecodetime = 0;
	m_videooffset = 0;
	//}}AFX_DATA_INIT
	m_ch = 0;
}


void CDlgChanEnc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChanEnc)
	DDX_CBIndex(pDX, IDC_IMAGEFORMAT, m_imageformat);
	DDX_CBIndex(pDX, IDC_STREAMTYPE, m_streamtype);
	DDX_Text(pDX, IDC_IKEYINTERVAL, m_ikeyinterval);
	DDV_MinMaxInt(pDX, m_ikeyinterval, 10, 200);
	DDX_CBIndex(pDX, IDC_SAMPLERATE, m_samplerate);
	DDX_CBIndex(pDX, IDC_AUBITS, m_audiobits);
	DDX_Text(pDX, IDC_FRAMERATE, m_framerate);
	DDV_MinMaxInt(pDX, m_framerate, 1, 30);
	DDX_Text(pDX, IDC_MINQUEUE, m_minqueue);
	DDV_MinMaxInt(pDX, m_minqueue, 2, 31);
	DDX_Text(pDX, IDC_MAXQUEUE, m_maxqueue);
	DDV_MinMaxInt(pDX, m_maxqueue, 2, 31);
	DDX_Text(pDX, IDC_MAXRATE, m_maxbits);
	DDV_MinMaxInt(pDX, m_maxbits, 32, 4000);
	DDX_CBIndex(pDX, IDC_BITRATETYPE, m_bitstype);
	DDX_CBIndex(pDX, IDC_SUBBITRATETYPE, m_subbitstype);
	DDX_Text(pDX, IDC_SUBFRAMERATE, m_subframerate);
	DDV_MinMaxInt(pDX, m_subframerate, 1, 30);
	DDX_Text(pDX, IDC_SUBIKEYINTERVAL, m_subikeyinterval);
	DDV_MinMaxInt(pDX, m_subikeyinterval, 10, 200);
	DDX_CBIndex(pDX, IDC_SUBIMAGEFORMAT, m_subimagformat);
	DDX_Text(pDX, IDC_SUBMAXQUEUE, m_submaxqueue);
	DDV_MinMaxInt(pDX, m_submaxqueue, 2, 31);
	DDX_Text(pDX, IDC_SUBMAXRATE, m_submaxrate);
	DDV_MinMaxInt(pDX, m_submaxrate, 32, 4000);
	DDX_Text(pDX, IDC_SUBMINQUEUE, m_subminqueue);
	DDV_MinMaxInt(pDX, m_subminqueue, 2, 31);
	DDX_CBIndex(pDX, IDC_SUBSTREAMTYPE, m_substreamtype);
	DDX_Text(pDX, IDC_DELAY, m_alarmdelay);
	DDV_MinMaxInt(pDX, m_alarmdelay, 5, 1800);
	DDX_Text(pDX, IDC_PRERECTIME, m_prerecodetime);
	DDV_MinMaxInt(pDX, m_prerecodetime, 0, 10);
	DDX_Text(pDX, IDC_VIDEOOFFSET, m_videooffset);
	DDV_MinMaxInt(pDX, m_videooffset, 0, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChanEnc, CDialog)
	//{{AFX_MSG_MAP(CDlgChanEnc)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_GET2, OnBtnGet2)
	ON_BN_CLICKED(IDC_BTN_SET2, OnBtnSet2)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	ON_BN_CLICKED(IDC_BTN_COPY2, OnBtnCopy2)
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChanEnc message handlers
LRESULT CDlgChanEnc::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	GetParam(0);
	return 0;
}

LRESULT CDlgChanEnc::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	GetDlgItem(IDC_COMBO_CHCOPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_COMBO_CHCOPY2)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY2)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY2)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	
	if(g_SerParam->m_chs > 1)
	{
		int i;
		CString strch,strtxt;

		strtxt.LoadString(IDS_STRING255);
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->AddString(strtxt);
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			strch.LoadString(IDS_STRING205);
			strtxt.Format(strch,i+1);
			((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->AddString(strtxt);
		}
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->SetCurSel(0);

		strtxt.LoadString(IDS_STRING255);
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->AddString(strtxt);
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			strch.LoadString(IDS_STRING205);
			strtxt.Format(strch,i+1);
			((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->AddString(strtxt);
		}
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->SetCurSel(0);
	}
	return 0;
}

void CDlgChanEnc::OnBtnGet() 
{
	GetParam(1);
}

BOOL CDlgChanEnc::UpdateMainParam()
{
	if(!UpdateData(TRUE)) return FALSE;

	m_chanparaex.m_bitratetype = m_bitstype;
	m_chanparaex.m_delay       = m_alarmdelay;
	m_chanparaex.m_videoFrameRate = m_framerate;
	m_chanparaex.m_Iinterval  = m_ikeyinterval;
	m_chanparaex.m_encodeType = m_imageformat + 1;
	m_chanparaex.m_maxqueue   = m_maxqueue;
	m_chanparaex.m_minqueue   = m_minqueue;
	m_chanparaex.m_maxbitrates = m_maxbits;
	m_chanparaex.m_streamType  = m_streamtype;
	m_chanparaex.m_audiosample = m_samplerate == 0 ? 16000 : 32000;
	if(m_audiobits == 0)      m_chanparaex.m_audiobitrate = 8;
	else if(m_audiobits == 1) m_chanparaex.m_audiobitrate = 16;
	else if(m_audiobits == 2) m_chanparaex.m_audiobitrate = 24;
	else if(m_audiobits == 3) m_chanparaex.m_audiobitrate = 32;
	else if(m_audiobits == 4) m_chanparaex.m_audiobitrate = 48;
	else if(m_audiobits == 5) m_chanparaex.m_audiobitrate = 64;
	else					  m_chanparaex.m_audiobitrate = 24;
	m_chanparaex.m_nPrerecordTime = m_prerecodetime;
	strcpy(m_chanpara.m_channelName,m_chanparaex.m_channelName);
	m_chanpara.m_streamType = m_chanparaex.m_streamType;
	m_chanpara.m_encodeType = m_chanparaex.m_encodeType;
	m_chanpara.m_Iinterval = m_chanparaex.m_Iinterval;
	m_chanpara.m_videoFrameRate = m_chanparaex.m_videoFrameRate;
	m_chanpara.m_bitratetype = m_chanparaex.m_bitratetype;
	m_chanpara.m_maxqueue = m_chanparaex.m_maxqueue;
	m_chanpara.m_minqueue = m_chanparaex.m_minqueue;
	m_chanpara.m_maxbitrates = m_chanparaex.m_maxbitrates;
	m_chanpara.m_audiosample = m_chanparaex.m_audiosample;
	m_chanpara.m_audiobitrate = m_chanparaex.m_audiobitrate;
	m_chanpara.m_delay = m_chanparaex.m_delay;
	m_chanpara.m_benrecord = m_chanparaex.m_benrecord;
	memcpy(&m_chanpara.m_record,&m_chanparaex.m_record,sizeof(TIMELIST));

	m_videooffsetparam.m_xoffset = m_videooffset;
	return TRUE;
}
BOOL CDlgChanEnc::UpdateSubParam()
{
	if(!UpdateData(TRUE)) return FALSE;

	m_subchparam.m_bitratetype = m_subbitstype;
	m_subchparam.m_videoFrameRate = m_subframerate;
	m_subchparam.m_Iinterval  = m_subikeyinterval;
	m_subchparam.m_encodeType = m_subimagformat + 1;
	m_subchparam.m_maxqueue   = m_submaxqueue;
	m_subchparam.m_minqueue   = m_subminqueue;
	m_subchparam.m_maxbitrates = m_submaxrate;
	m_subchparam.m_streamType  = m_substreamtype;

	return TRUE;
}

void CDlgChanEnc::OnBtnSet() 
{
	CString strmsg;
	if(!UpdateMainParam()) return;
	g_SerParam->SaveParam(MESSAGE_SETCHANNELPARAM,m_ch,&m_chanpara,&m_chanparaex,NULL);
	g_SerParam->SaveParam(MESSAGE_CMD_SETVIDEOOFFSET,m_ch,&m_videooffsetparam,NULL,NULL);

	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChanEnc::OnBtnGet2() 
{
	GetParam(2);
}

void CDlgChanEnc::OnBtnSet2() 
{
	CString strmsg;
	
	if(!UpdateSubParam()) return;

	g_SerParam->SaveParam(MESSAGE_CMD_SETSUBCHANNELPARAM,m_ch,&m_subchparam,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChanEnc::GetParam(int enctype)
{
	CString strmsg;
	int iRet1;
	if(enctype == 0 || enctype == 1)
	{
		memset(&m_chanpara,0,sizeof(CHANNELPARAM));
		memset(&m_chanparaex,0,sizeof(CHANNELPARAMEX));
		memset(&m_videooffsetparam,0,sizeof(VSNETVIDEOOFFSET));
	
		iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETVIDEOOFFSET,m_ch,&m_videooffsetparam,NULL,NULL);
		GetDlgItem(IDC_VIDEOOFFSET)->EnableWindow(iRet1);
		if(iRet1)
		{
			m_videooffset = m_videooffsetparam.m_xoffset;
		}

		iRet1 = g_SerParam->ReadParam(MESSAGE_GETCHANNELPARAM,m_ch,&m_chanpara,&m_chanparaex,&m_type);
		GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);
		if(!iRet1)
		{
			strmsg.LoadString(IDS_STRING231);
			g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		}
		else 
		{
			strmsg.LoadString(IDS_STRING233);
			g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
			if(!m_type)
			{
				memset(&m_chanparaex,0,sizeof(CHANNELPARAMEX));
				strcpy(m_chanparaex.m_channelName,m_chanpara.m_channelName);
				m_chanparaex.m_streamType = m_chanpara.m_streamType;
				m_chanparaex.m_encodeType = m_chanpara.m_encodeType;
				m_chanparaex.m_Iinterval = m_chanpara.m_Iinterval;
				m_chanparaex.m_videoFrameRate = m_chanpara.m_videoFrameRate;
				m_chanparaex.m_bitratetype = m_chanpara.m_bitratetype;
				m_chanparaex.m_maxqueue = m_chanpara.m_maxqueue;
				m_chanparaex.m_minqueue = m_chanpara.m_minqueue;
				m_chanparaex.m_maxbitrates = m_chanpara.m_maxbitrates;
				m_chanparaex.m_audiosample = m_chanpara.m_audiosample;
				m_chanparaex.m_audiobitrate = m_chanpara.m_audiobitrate;
				m_chanparaex.m_delay = m_chanpara.m_delay;
				m_chanparaex.m_benrecord = m_chanpara.m_benrecord;
				memcpy(&m_chanparaex.m_record,&m_chanpara.m_record,sizeof(TIMELIST));
			}
			GetDlgItem(IDC_PRERECTIME)->EnableWindow(m_type);
			m_bitstype   = m_chanparaex.m_bitratetype;
			m_framerate  = m_chanparaex.m_videoFrameRate;
			m_ikeyinterval = m_chanparaex.m_Iinterval;
			m_imageformat = m_chanparaex.m_encodeType - 1;
			m_maxqueue = m_chanparaex.m_maxqueue;
			m_minqueue = m_chanparaex.m_minqueue;
			m_maxbits  = m_chanparaex.m_maxbitrates;
			m_streamtype = m_chanparaex.m_streamType;
			m_samplerate = m_chanparaex.m_audiosample == 16000 ? 0 : 1;
			if(m_chanparaex.m_audiobitrate == 8)
				m_audiobits  = 0;
			else if(m_chanparaex.m_audiobitrate == 16)
				m_audiobits  = 1;
			else if(m_chanparaex.m_audiobitrate == 24)
				m_audiobits  = 2;
			else if(m_chanparaex.m_audiobitrate == 32)
				m_audiobits  = 3;
			else if(m_chanparaex.m_audiobitrate == 48)
				m_audiobits  = 4;
			else if(m_chanparaex.m_audiobitrate == 64)
				m_audiobits  = 5;
			else
				m_audiobits  = 2;
			m_alarmdelay = m_chanparaex.m_delay;
			m_prerecodetime = m_chanparaex.m_nPrerecordTime;
		}
	}

	if(enctype == 0 || enctype == 2) //sub channel
	{
		memset(&m_subchparam,0,sizeof(VSSUBCHANPARAM));
		iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETSUBCHANNELPARAM,m_ch,&m_subchparam,NULL,NULL);
		GetDlgItem(IDC_SUBIMAGEFORMAT)->EnableWindow(iRet1);
		GetDlgItem(IDC_SUBFRAMERATE)->EnableWindow(iRet1);
		GetDlgItem(IDC_SUBSTREAMTYPE)->EnableWindow(iRet1);
		GetDlgItem(IDC_SUBBITRATETYPE)->EnableWindow(iRet1);
		GetDlgItem(IDC_SUBIKEYINTERVAL)->EnableWindow(iRet1);
		GetDlgItem(IDC_SUBMINQUEUE)->EnableWindow(iRet1);
		GetDlgItem(IDC_SUBMAXRATE)->EnableWindow(iRet1);
		GetDlgItem(IDC_SUBMAXQUEUE)->EnableWindow(iRet1);
		GetDlgItem(IDC_COMBO_CHCOPY2)->EnableWindow(iRet1);
		GetDlgItem(IDC_BTN_COPY2)->EnableWindow(iRet1);
		GetDlgItem(IDC_BTN_GET2)->EnableWindow(iRet1);
		GetDlgItem(IDC_BTN_SET2)->EnableWindow(iRet1);
		if(!iRet1)
		{
			strmsg.LoadString(IDS_STRING256);
			g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		}
		else 
		{
			strmsg.LoadString(IDS_STRING233);
			g_SerParam->m_txtMsginfo.SetWindowText(strmsg);

			m_subbitstype = m_subchparam.m_bitratetype;
			m_subframerate = m_subchparam.m_videoFrameRate;
			m_subikeyinterval = m_subchparam.m_Iinterval;
			m_subimagformat = m_subchparam.m_encodeType - 1;
			m_submaxqueue = m_subchparam.m_maxqueue;
			m_subminqueue = m_subchparam.m_minqueue;
			m_submaxrate = m_subchparam.m_maxbitrates;
			m_substreamtype = m_subchparam.m_streamType;
		}
	}
	UpdateData(FALSE);
}

void CDlgChanEnc::OnBtnCopy1() 
{	
	int i,tmpch;
	CString strmsg;
	if(!UpdateMainParam()) return;
	int sel = ((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->GetCurSel();
	if(sel == -1) return;
	if(sel == (m_ch + 1)) return;
	tmpch = m_ch;
	if(sel == 0) //all channels
	{
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			m_ch = i;
			OnBtnSet();
		}
	}
	else
	{
		m_ch = sel - 1;
		OnBtnSet();
	}
	m_ch = tmpch;
	strmsg.LoadString(IDS_STRING257);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChanEnc::OnBtnCopy2()
{	
	int i,tmpch;
	CString strmsg;
	if(!UpdateSubParam()) return;
	int sel = ((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->GetCurSel();
	if(sel == -1) return;
	if(sel == (m_ch + 1)) return;
	tmpch = m_ch;
	if(sel == 0) //all channels
	{
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			m_ch = i;
			OnBtnSet2();
		}
	}
	else
	{
		m_ch = sel - 1;
		OnBtnSet2();
	}
	m_ch = tmpch;
	strmsg.LoadString(IDS_STRING257);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}
