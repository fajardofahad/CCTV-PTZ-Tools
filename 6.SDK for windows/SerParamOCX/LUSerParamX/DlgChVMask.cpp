// DlgChVMask.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgChVMask.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChVMask dialog


CDlgChVMask::CDlgChVMask(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChVMask::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChVMask)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hchann = -1;
}


void CDlgChVMask::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChVMask)
	DDX_Control(pDX, IDC_STATIC_WND, m_videownd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChVMask, CDialog)
	//{{AFX_MSG_MAP(CDlgChVMask)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RADIO_AREA1, OnRadioArea1)
	ON_BN_CLICKED(IDC_RADIO_AREA2, OnRadioArea2)
	ON_BN_CLICKED(IDC_RADIO_AREA3, OnRadioArea3)
	ON_BN_CLICKED(IDC_RADIO_AREA4, OnRadioArea4)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
	ON_MESSAGE(DLGFREEPARAM_MSG,OnDlgFree)
	ON_MESSAGE(DLGWND_VIDEOMSG, OnDlgVideoMsg)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChVMask message handlers

BOOL CDlgChVMask::UpdateParam()
{
	if(!UpdateData()) return FALSE;
	return TRUE;
}

LRESULT CDlgChVMask::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	if(!ConnectVideo())
	{
		AfxMessageBox(IDS_STRING258,MB_ICONWARNING);
	}
	OnBtnGet();
	return 0;
}

LRESULT CDlgChVMask::OnDlgFirst(WPARAM wParam,LPARAM lParam)
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

LRESULT CDlgChVMask::OnDlgFree(WPARAM wParam,LPARAM lParam)
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

void CDlgChVMask::OnBtnGet() 
{
	CString strmsg;
	int iRet1;

	memset(&m_maskarea,0,sizeof(VSNETVIDEOMASK));
	memset(&m_channvmask,0,sizeof(CHANNVIDEOMASK));
	memset(&m_vmask,0,sizeof(m_vmask));
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETVIDEOMASKAREA,m_ch,&m_maskarea,NULL,NULL);
	GetDlgItem(IDC_RADIO_AREA1)->EnableWindow(iRet1);
	GetDlgItem(IDC_RADIO_AREA2)->EnableWindow(iRet1);
	GetDlgItem(IDC_RADIO_AREA3)->EnableWindow(iRet1);
	GetDlgItem(IDC_RADIO_AREA4)->EnableWindow(iRet1);
	if(iRet1)
	{
		strmsg.LoadString(IDS_STRING233);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		GetDlgItem(IDC_BTN_SET)->EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_CHECK_EN))->SetCheck(m_maskarea.m_bmask);
		memcpy(m_vmask,m_maskarea.m_maskarea,sizeof(m_vmask));
	}
	else
	{
		iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETVIDEOMASK,m_ch,&m_channvmask,NULL,NULL);
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
			m_vmask[0].m_x = m_channvmask.m_x;
			m_vmask[0].m_y = m_channvmask.m_y;
			m_vmask[0].m_width = m_channvmask.m_width;
			m_vmask[0].m_height = m_channvmask.m_height;
		}
		((CButton*)GetDlgItem(IDC_CHECK_EN))->SetCheck(m_channvmask.m_bmask);
	}
	RECT rect;
	m_videownd.m_ImageWidth  = 704;
	m_videownd.m_ImageHeight = 576;
	m_videownd.m_HCount = m_videownd.m_ImageWidth / 32;
	m_videownd.m_VCount = m_videownd.m_ImageHeight / 32;
	m_videownd.m_curmouse_x = m_videownd.m_curmouse_y = 0;
	m_videownd.GetClientRect(&rect);
	m_videownd.m_wblock = (rect.right  - rect.left)/(m_videownd.m_ImageWidth/32);
	m_videownd.m_hblock = (rect.bottom - rect.top)/(m_videownd.m_VCount);

	float w_off,h_off;
	w_off = (float)(rect.right  - rect.left) / (float)704;
	h_off = (float)(rect.bottom - rect.top)  / (float)576;
	m_videownd.m_maskmax_w  = (int)((float)352  * w_off);
	m_videownd.m_maskmax_h  = (int)((float)288 * h_off);

	m_videownd.pvmask[0]   = &m_vmask[0];
	m_videownd.pvmask[1]   = &m_vmask[1];
	m_videownd.pvmask[2]   = &m_vmask[2];
	m_videownd.pvmask[3]   = &m_vmask[3];
	m_videownd.m_bIsArea = FALSE;
	m_videownd.m_bLinkOk = TRUE;
	m_videownd.m_curmaskarea = 0;
	m_videownd.Reinit(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_AREA4))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO_AREA3))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO_AREA2))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO_AREA1))->SetCheck(TRUE);
}

void CDlgChVMask::OnBtnSet() 
{
	int i;
	CString strmsg;
	float w_off,h_off;
	RECT rect;
	m_videownd.GetClientRect(&rect);
	w_off = (float)(rect.right  - rect.left) / (float)704;
	h_off = (float)(rect.bottom - rect.top)  / (float)576;
	for(i=0;i<4;i++)
	{
		if(m_vmask[i].m_width < 0)
		{
			m_vmask[i].m_x = m_vmask[i].m_x + m_vmask[i].m_width;
			m_vmask[i].m_width = - m_vmask[i].m_width;
		}
		if(m_vmask[i].m_height < 0)
		{
			m_vmask[i].m_y = m_vmask[i].m_y + m_vmask[i].m_height;
			m_vmask[i].m_height = - m_vmask[i].m_height;
		}
		
		m_vmask[i].m_x = m_vmask[i].m_x < 0 ? - m_vmask[i].m_x : m_vmask[i].m_x;
		m_vmask[i].m_y = m_vmask[i].m_y < 0 ? - m_vmask[i].m_y : m_vmask[i].m_y;
		
		TRACE("x:%d,y:%d,width:%d,height:%d\n",
			m_vmask[i].m_x,m_vmask[i].m_y,
			m_vmask[i].m_width,m_vmask[i].m_height);
		
		if((m_vmask[i].m_x + m_vmask[i].m_width) > rect.right)
		{
			m_vmask[i].m_width = rect.right - m_vmask[i].m_x;
		}
		if((m_vmask[i].m_y + m_vmask[i].m_height) > rect.bottom)
		{
			m_vmask[i].m_height = rect.bottom - m_vmask[i].m_y;
		}
	}
	
	m_maskarea.m_bmask = m_channvmask.m_bmask = ((CButton*)GetDlgItem(IDC_CHECK_EN))->GetCheck();
	for(i=0;i<4;i++)
	{
		m_maskarea.m_maskarea[i].m_x = (short)((float)m_vmask[i].m_x / w_off);
		m_maskarea.m_maskarea[i].m_y = (short)((float)m_vmask[i].m_y / h_off);
		if(m_vmask[i].m_width < 10 && m_vmask[i].m_height < 10)
		{
			m_maskarea.m_maskarea[i].m_width = 0;
			m_maskarea.m_maskarea[i].m_height = 0;
		}
		else
		{
			m_maskarea.m_maskarea[i].m_width  = (short)((float)m_vmask[i].m_width / w_off);
			m_maskarea.m_maskarea[i].m_height = (short)((float)m_vmask[i].m_height / h_off);
		}
	}
	i = g_SerParam->ReadParam(MESSAGE_CMD_SETVIDEOMASKAREA,m_ch,&m_maskarea,NULL,NULL);
	if(!i)
	{
		m_channvmask.m_x = (short)((float)m_vmask[0].m_x / w_off);
		m_channvmask.m_y = (short)((float)m_vmask[0].m_y / h_off);
		if(m_vmask[0].m_width < 10 && m_vmask[0].m_height < 10)
		{
			m_channvmask.m_width = 0;
			m_channvmask.m_height = 0;
		}
		else
		{
			m_channvmask.m_width  = (short)((float)m_vmask[0].m_width / w_off);
			m_channvmask.m_height = (short)((float)m_vmask[0].m_height / h_off);	
		}
		g_SerParam->ReadParam(MESSAGE_CMD_SETVIDEOMASK,m_ch,&m_channvmask,NULL,NULL);
	}
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChVMask::OnBtnCopy1() 
{
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
LRESULT CDlgChVMask::OnDlgVideoMsg(WPARAM wParam,LPARAM lParam)
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

BOOL CDlgChVMask::ConnectVideo()
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

void CDlgChVMask::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent == 10)
	{
		KILLTIMER(m_timerid);
		ConnectVideo();
	}
	CDialog::OnTimer(nIDEvent);
}

void CDlgChVMask::OnDestroy() 
{
	OnDlgFree(0,0);
	CDialog::OnDestroy();
}

void CDlgChVMask::OnRadioArea1() 
{
	m_videownd.m_curmaskarea = 0;
	m_videownd.Reinit();
}

void CDlgChVMask::OnRadioArea2() 
{
	m_videownd.m_curmaskarea = 1;
	m_videownd.Reinit();
}

void CDlgChVMask::OnRadioArea3() 
{
	m_videownd.m_curmaskarea = 2;
	m_videownd.Reinit();
}

void CDlgChVMask::OnRadioArea4() 
{
	m_videownd.m_curmaskarea = 3;
	m_videownd.Reinit();
}

