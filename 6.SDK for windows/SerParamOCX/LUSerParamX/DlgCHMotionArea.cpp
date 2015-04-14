// DlgCHMotionArea.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgCHMotionArea.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCHMotionArea dialog

CDlgCHMotionArea::CDlgCHMotionArea(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCHMotionArea::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCHMotionArea)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CDlgCHMotionArea::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCHMotionArea)
	DDX_Control(pDX, IDC_SLIDER_MOTIONAREA, m_MotionVal);
	DDX_Control(pDX, IDC_STATIC_WND, m_videownd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgCHMotionArea, CDialog)
	//{{AFX_MSG_MAP(CDlgCHMotionArea)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_ALL, OnBtnAll)
	ON_BN_CLICKED(IDC_BTN_CLEAN, OnBtnClean)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
	ON_MESSAGE(DLGFREEPARAM_MSG,OnDlgFree)
	ON_MESSAGE(DLGWND_VIDEOMSG, OnDlgVideoMsg)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCHMotionArea message handlers
void CDlgCHMotionArea::OnOK() 
{
	//CDialog::OnOK();
}

void CDlgCHMotionArea::OnCancel() 
{	
	//CDialog::OnCancel();
}

BOOL CDlgCHMotionArea::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	memcpy(m_channmotion.m_detect,m_channmotionex.m_detect,18*22);
	m_channmotion.m_alarmsenstive = m_channmotionex.m_alarmsenstive = m_MotionVal.GetPos();
	return TRUE;
}

LRESULT CDlgCHMotionArea::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	if(m_hchann != -1)
	{
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
	}
	if(!ConnectVideo())
	{
		AfxMessageBox(IDS_STRING258,MB_ICONWARNING);
	}
	
	OnBtnGet();

	RECT rect;
	m_videownd.m_ImageWidth  = 704;
	m_videownd.m_ImageHeight = 576;
	m_videownd.m_HCount = m_videownd.m_ImageWidth / 32;
	m_videownd.m_VCount = m_videownd.m_ImageHeight / 32;
	m_videownd.m_curmouse_x = m_videownd.m_curmouse_y = 0;
	m_videownd.GetClientRect(&rect);
	m_videownd.m_wblock = (rect.right  - rect.left)/(m_videownd.m_ImageWidth/32);
	m_videownd.m_hblock = (rect.bottom - rect.top)/(m_videownd.m_VCount);

	m_videownd.m_pmotion= &m_channmotionex;
	//m_videownd.m_hchann = m_hchann;
	m_videownd.m_bIsArea= TRUE;
	m_videownd.m_bLinkOk= TRUE;
	return 0;
}

LRESULT CDlgCHMotionArea::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	m_MotionVal.SetLineSize(1);
	m_MotionVal.SetPageSize(1);
	m_MotionVal.SetRange(1,99);

	GetDlgItem(IDC_COMBO_CHCOPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
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
	}
	return 0;
}

LRESULT CDlgCHMotionArea::OnDlgFree(WPARAM wParam,LPARAM lParam)
{
	CString strmsg;
	KILLTIMER(m_timerid);
	if(m_hchann != -1)
	{
		strmsg.LoadString(IDS_STRING259);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
		g_SerParam->m_txtMsginfo.SetWindowText("");
	}
	return 0;
}

void CDlgCHMotionArea::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if(pScrollBar == (CScrollBar*)GetDlgItem(IDC_SLIDER_MOTIONAREA))
	{
		if(    (nSBCode == SB_LEFT)
			|| (nSBCode == SB_LINELEFT)
			|| (nSBCode == SB_LINERIGHT)
			|| (nSBCode == SB_PAGELEFT)
			|| (nSBCode == SB_PAGERIGHT)
			|| (nSBCode == SB_RIGHT)
			|| (nSBCode == SB_THUMBPOSITION)
			|| (nSBCode == SB_THUMBTRACK) )
		{
			char lpnum[10];
			sprintf(lpnum,"%d",m_MotionVal.GetPos());
			GetDlgItem(IDC_STATIC_VAL)->SetWindowText(lpnum);
		}
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDlgCHMotionArea::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	char lpnum[10];

	memset(&m_channmotion,0,sizeof(CHANNMOTION));
	memset(&m_channmotionex,0,sizeof(CHANNMOTIONEX));
	
	m_type = 0;
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETMOTIONPARAM,m_ch,&m_channmotion,&m_channmotionex,&m_type);
	if(!m_type)
	{
		memset(&m_channmotionex,0,sizeof(CHANNMOTIONEX));
		m_channmotionex.m_beanb = m_channmotion.m_beanb; 
		m_channmotionex.m_alarmsenstive = m_channmotion.m_alarmsenstive; 
		m_channmotionex.m_brecord = m_channmotion.m_brecord;
		memcpy(m_channmotionex.m_outputmap,m_channmotion.m_outputmap,sizeof(m_channmotionex.m_outputmap));
		memcpy(m_channmotionex.m_detect,m_channmotion.m_detect,18*22); 
		memcpy(&m_channmotionex.m_timelist,&m_channmotion.m_timelist,sizeof(TIMELIST));
	}
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
	}
	
	m_MotionVal.SetPos(m_channmotionex.m_alarmsenstive);
	sprintf(lpnum,"%d",m_channmotionex.m_alarmsenstive);
	GetDlgItem(IDC_STATIC_VAL)->SetWindowText(lpnum);
}

void CDlgCHMotionArea::OnBtnSet() 
{
	BOOL nRet;
	CString strmsg;
	if(!UpdateParam()) return;
	nRet = g_SerParam->SaveParam(MESSAGE_CMD_SETMOTIONPARAM,m_ch,&m_channmotion,&m_channmotionex,NULL);
	TRACE("set motion para ret : %d\n",nRet);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgCHMotionArea::OnBtnAll() 
{
	memset(m_channmotionex.m_detect,1,18*22);
	m_videownd.Invalidate();
}

void CDlgCHMotionArea::OnBtnClean() 
{
	memset(m_channmotionex.m_detect,0,18*22);
	m_videownd.Invalidate();
}

void CDlgCHMotionArea::OnBtnCopy1() 
{
	if(!UpdateParam()) return;

	int i,tmpch;
	CString strmsg;
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

LRESULT CDlgCHMotionArea::OnDlgVideoMsg(WPARAM wParam,LPARAM lParam)
{
	if(wParam != LAUMSG_LINKMSG) return 0;
	
	if(lParam == 0)
	{
		return 0;
	}

	KILLTIMER(m_timerid);
	if(m_hchann != -1)
	{
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
	}
	switch(lParam)
	{
	case 1:		
		break;
	case 2:		
		break;
	case 3:		
	case 4:		
	case 5:	
	case -102:
	case -103:	
	case -105:
	case -106:	
	case -112:
	default:
		m_timerid = SetTimer(10,10 * 1000,NULL);
		break;
	}
	return 0;
}

BOOL CDlgCHMotionArea::ConnectVideo()
{
	KILLTIMER(m_timerid);
	if(m_hchann != -1)
	{
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
	}
	CHANNEL_CLIENTINFO m_chinfo;
	memset(&m_chinfo,0,sizeof(CHANNEL_CLIENTINFO));
	m_chinfo.m_buffnum    = 50;
	m_chinfo.m_ch         = m_ch;
	m_chinfo.m_hChMsgWnd  = m_hWnd;
	m_chinfo.m_nChmsgid   = DLGWND_VIDEOMSG;
	m_chinfo.m_hVideohWnd = GetDlgItem(IDC_STATIC_WND)->m_hWnd;
	m_chinfo.m_password   = (char*)(const char*)(g_SerParam->m_password);
	m_chinfo.m_playstart  = TRUE;
	m_chinfo.m_sername    = (char*)(const char*)(g_SerParam->m_sername);
	m_chinfo.m_tranType   = 3;
	m_chinfo.m_useoverlay = FALSE;
	m_chinfo.m_username   = (char*)(const char*)(g_SerParam->m_username);
	m_chinfo.nColorKey    = RGB(255,0,255);
	m_hchann = VSNET_ClientStart((char*)(const char*)g_SerParam->m_serurl,&m_chinfo,g_SerParam->m_serport);
	if(m_hchann == -1)
	{
		return FALSE;
	}
	else
	{
		VSNET_ClientSetDelayTime(m_hchann,5);
	}
	return TRUE;
}

void CDlgCHMotionArea::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent == 10)
	{
		KILLTIMER(m_timerid);
		ConnectVideo();
	}
	CDialog::OnTimer(nIDEvent);
}

void CDlgCHMotionArea::OnDestroy() 
{
	KILLTIMER(m_timerid);
	if(m_hchann != -1)
	{
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
	}
	CDialog::OnDestroy();	
}
