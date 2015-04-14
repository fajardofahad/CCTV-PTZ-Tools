// DlgChVParam.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgChVParam.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChVParam dialog


CDlgChVParam::CDlgChVParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChVParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChVParam)
	m_bri = 0;
	m_con = 0;
	m_hue = 0;
	m_sat = 0;
	//}}AFX_DATA_INIT
	m_ch = 0;
	m_hchann = -1;
	m_timerid= 0;
}


void CDlgChVParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChVParam)
	DDX_Text(pDX, IDC_EDIT_BRI, m_bri);
	DDV_MinMaxInt(pDX, m_bri, 0, 255);
	DDX_Text(pDX, IDC_EDIT_CON, m_con);
	DDV_MinMaxInt(pDX, m_con, 0, 255);
	DDX_Text(pDX, IDC_EDIT_HUE, m_hue);
	DDV_MinMaxInt(pDX, m_hue, 0, 255);
	DDX_Text(pDX, IDC_EDIT_SAT, m_sat);
	DDV_MinMaxInt(pDX, m_sat, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChVParam, CDialog)
	//{{AFX_MSG_MAP(CDlgChVParam)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	ON_BN_CLICKED(IDC_BTN_DEFAULT, OnBtnDefault)
	ON_WM_DESTROY()
	ON_WM_VSCROLL()
	ON_WM_TIMER()
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
	ON_MESSAGE(DLGFREEPARAM_MSG,OnDlgFree)
	ON_MESSAGE(DLGWND_VIDEOMSG, OnDlgVideoMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChVParam message handlers
BOOL CDlgChVParam::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BRI))->SetLineSize(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BRI))->SetPageSize(5);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BRI))->SetRange(0,255);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_CON))->SetLineSize(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_CON))->SetPageSize(5);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_CON))->SetRange(0,255);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SAT))->SetLineSize(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SAT))->SetPageSize(5);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SAT))->SetRange(0,255);

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HUE))->SetLineSize(1);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HUE))->SetPageSize(5);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HUE))->SetRange(0,255);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgChVParam::OnOK() 
{
	//CDialog::OnOK();
}

void CDlgChVParam::OnCancel() 
{	
	//CDialog::OnCancel();
}

LRESULT CDlgChVParam::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	if(!ConnectVideo())
	{
		AfxMessageBox(IDS_STRING258,MB_ICONWARNING);
	}
	OnBtnGet();
	return 0;
}

LRESULT CDlgChVParam::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
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

LRESULT CDlgChVParam::OnDlgFree(WPARAM wParam,LPARAM lParam)
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


void CDlgChVParam::OnBtnGet() 
{
	int iRet1;
	CString strmsg;
	memset(&m_viparam,0,sizeof(CHANNVIPARAM));
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETVIPARAM,m_ch,&m_viparam,NULL,NULL);
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

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BRI))->SetPos(m_viparam.m_bri);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_CON))->SetPos(m_viparam.m_con);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SAT))->SetPos(m_viparam.m_sat);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HUE))->SetPos(m_viparam.m_hue);
	m_bri = m_viparam.m_bri;
	m_con = m_viparam.m_con;
	m_sat = m_viparam.m_sat;
	m_hue = m_viparam.m_hue;
	UpdateData(FALSE);
}

BOOL CDlgChVParam::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	m_viparam.m_bri = m_bri;
	m_viparam.m_con = m_con;
	m_viparam.m_sat = m_sat;
	m_viparam.m_hue = m_hue;
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BRI))->SetPos(m_viparam.m_bri);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_CON))->SetPos(m_viparam.m_con);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SAT))->SetPos(m_viparam.m_sat);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HUE))->SetPos(m_viparam.m_hue);
	return TRUE;
}

void CDlgChVParam::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETVIPARAM,m_ch,&m_viparam,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChVParam::OnBtnCopy1()
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

void CDlgChVParam::OnBtnDefault() 
{
	m_bri = 110;
	m_con = 80;
	m_sat = 80;
	m_hue = 0;
	m_viparam.m_bri = m_bri;
	m_viparam.m_con = m_con;
	m_viparam.m_sat = m_sat;
	m_viparam.m_hue = m_hue;
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BRI))->SetPos(m_viparam.m_bri);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_CON))->SetPos(m_viparam.m_con);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SAT))->SetPos(m_viparam.m_sat);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HUE))->SetPos(m_viparam.m_hue);
	UpdateData(FALSE);
	OnBtnSet();
}


void CDlgChVParam::OnDestroy() 
{
	OnDlgFree(0,0);
	CDialog::OnDestroy();
}

void CDlgChVParam::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if(((CScrollBar*)GetDlgItem(IDC_SLIDER_BRI)) == pScrollBar)
	{
		m_bri = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BRI))->GetPos();
	}
	else if(((CScrollBar*)GetDlgItem(IDC_SLIDER_CON)) == pScrollBar)
	{
		m_con = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_CON))->GetPos();
	}
	else if(((CScrollBar*)GetDlgItem(IDC_SLIDER_SAT)) == pScrollBar)
	{
		m_sat = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SAT))->GetPos();
	}
	else if(((CScrollBar*)GetDlgItem(IDC_SLIDER_HUE)) == pScrollBar)
	{
		m_hue = ((CSliderCtrl*)GetDlgItem(IDC_SLIDER_HUE))->GetPos();
	}
	UpdateData(FALSE);
	if(m_hchann != -1)
	{
		m_viparam.m_bri = m_bri;
		m_viparam.m_con = m_con;
		m_viparam.m_sat = m_sat;
		m_viparam.m_hue = m_hue;
		VSNET_ClientMessageOpt(g_SerParam->m_hParam,MESSAGE_CMD_SETVIPARAM,m_ch,&m_viparam,NULL,NULL);
		
		//VSNET_ClientViAdjust(m_hchann,m_viparam.m_bri,m_viparam.m_con,m_viparam.m_sat,m_viparam.m_hue);
	}	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

LRESULT CDlgChVParam::OnDlgVideoMsg(WPARAM wParam,LPARAM lParam)
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

BOOL CDlgChVParam::ConnectVideo()
{
	KILLTIMER(m_timerid);
	if(m_hchann != -1)
	{
		VSNET_ClientStop(m_hchann);
		m_hchann = -1;
	}
	CHANNEL_CLIENTINFO m_chinfo;
	memset(&m_chinfo,0,sizeof(CHANNEL_CLIENTINFO));
	m_chinfo.m_buffnum    = 5;
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

void CDlgChVParam::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent == 10)
	{
		KILLTIMER(m_timerid);
		ConnectVideo();
	}
	CDialog::OnTimer(nIDEvent);
}
