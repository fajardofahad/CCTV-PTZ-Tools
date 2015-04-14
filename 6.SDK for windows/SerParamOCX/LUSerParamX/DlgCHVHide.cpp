// DlgCHVHide.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgCHVHide.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCHVHide dialog


CDlgCHVHide::CDlgCHVHide(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCHVHide::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCHVHide)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgCHVHide::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCHVHide)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCHVHide, CDialog)
	//{{AFX_MSG_MAP(CDlgCHVHide)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCHVHide message handlers
LRESULT CDlgCHVHide::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgCHVHide::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	int i;
	GetDlgItem(IDC_COMBO_CHCOPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);

	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		GetDlgItem(IDC_CHECK_ALARMOUT1 + i)->ShowWindow(SW_SHOW);
	}

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

void CDlgCHVHide::OnBtnGet() 
{
	int i;
	int iRet1;
	char lpnum[3];
	CString strmsg;
	memset(&m_chanhide,0,sizeof(CHANNELHIDEALARM));
	memset(&m_chanhideex,0,sizeof(CHANNELHIDEALARMEX));
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETHIDEALARM,m_ch,&m_chanhide,&m_chanhideex,&m_type);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);
	if(!m_type)
	{
		memset(&m_chanhideex,0,sizeof(CHANNELHIDEALARMEX));
		m_chanhideex.m_benable = m_chanhide.m_benable; 
		m_chanhideex.m_decval = m_chanhide.m_decval; 
		memcpy((char*)m_chanhideex.m_out,(char*)m_chanhide.m_out,sizeof(m_chanhideex.m_out)); 
		memcpy(&m_chanhideex.pTimeList,&m_chanhide.pTimeList,sizeof(TIMELIST)); 
	}
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

	for(i=0;i<7;i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->SetCurSel(m_chanhideex.pTimeList.pList[i].m_maskweek);

		sprintf(lpnum,"%02d",m_chanhideex.pTimeList.pList[i].m_starthour);
		GetDlgItem(IDC_STARTHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_chanhideex.pTimeList.pList[i].m_startmin);
		GetDlgItem(IDC_STARTMINUTE1 + i)->SetWindowText(lpnum);

		sprintf(lpnum,"%02d",m_chanhideex.pTimeList.pList[i].m_stophour);
		GetDlgItem(IDC_STOPHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_chanhideex.pTimeList.pList[i].m_stopmin);
		GetDlgItem(IDC_STOPMINUTE1 + i)->SetWindowText(lpnum);
	}
	((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->SetCheck(m_chanhideex.m_bsinglehost);
	GetDlgItem(IDC_CHECK_ALARMTOHOST)->EnableWindow(m_type);

	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->SetCheck(m_chanhideex.m_out[i]);
	}
	((CButton*)GetDlgItem(IDC_CHECK_EN))->SetCheck(m_chanhideex.m_benable);
	UpdateData(FALSE);
}

BOOL CDlgCHVHide::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	int i;
	char lpnum[3];
	for(i=0;i<7;i++)
	{
		m_chanhideex.pTimeList.pList[i].m_maskweek = ((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->GetCurSel();
		GetDlgItem(IDC_STARTHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanhideex.pTimeList.pList[i].m_starthour = atoi(lpnum);
		
		GetDlgItem(IDC_STARTMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanhideex.pTimeList.pList[i].m_startmin = atoi(lpnum);
		
		GetDlgItem(IDC_STOPHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanhideex.pTimeList.pList[i].m_stophour = atoi(lpnum);
		
		GetDlgItem(IDC_STOPMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanhideex.pTimeList.pList[i].m_stopmin = atoi(lpnum);
	}
	m_chanhideex.m_benable = ((CButton*)GetDlgItem(IDC_CHECK_EN))->GetCheck();
	m_chanhideex.m_bsinglehost = ((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->GetCheck();
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		m_chanhideex.m_out[i] = ((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->GetCheck();
	}
	m_chanhide.m_benable = m_chanhideex.m_benable; 
	m_chanhide.m_decval = m_chanhideex.m_decval; 
	memcpy((char*)m_chanhide.m_out,(char*)m_chanhideex.m_out,sizeof(m_chanhide.m_out)); 
	memcpy(&m_chanhide.pTimeList,&m_chanhideex.pTimeList,sizeof(TIMELIST)); 
	return TRUE;
}

void CDlgCHVHide::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETHIDEALARM,m_ch,&m_chanhide,&m_chanhideex,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgCHVHide::OnBtnCopy1() 
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
