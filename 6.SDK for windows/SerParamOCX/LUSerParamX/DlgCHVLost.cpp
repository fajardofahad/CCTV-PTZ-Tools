// DlgCHVLost.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgCHVLost.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCHVLost dialog


CDlgCHVLost::CDlgCHVLost(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCHVLost::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCHVLost)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgCHVLost::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCHVLost)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCHVLost, CDialog)
	//{{AFX_MSG_MAP(CDlgCHVLost)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCHVLost message handlers
LRESULT CDlgCHVLost::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgCHVLost::OnDlgFirst(WPARAM wParam,LPARAM lParam)
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

void CDlgCHVLost::OnBtnGet() 
{
	int i;
	int iRet1,iRet2;
	char lpnum[3];
	BOOL vilostenc;
	CString strmsg;
	memset(&m_vlost,0,sizeof(VSNETVIDEOLOSTPARAM));
	for(i=0;i<7;i++)
	{
		m_vlost.m_timelist.pList[i].m_maskweek = 10;
	}
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETVIDEOLOST,m_ch,&vilostenc,NULL,NULL);
	iRet2 = g_SerParam->ReadParam(MESSAGE_CMD_GETVIDEOLOSTPARAM,m_ch,&m_vlost,NULL,NULL);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);

	for(i=0;i<7;i++)
	{	
		((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->SetCurSel(m_vlost.m_timelist.pList[i].m_maskweek);
		GetDlgItem(IDC_COMBO_TIME1 + i)->EnableWindow(iRet2);

		sprintf(lpnum,"%02d",m_vlost.m_timelist.pList[i].m_starthour);
		GetDlgItem(IDC_STARTHOUR1 + i)->SetWindowText(lpnum);
		GetDlgItem(IDC_STARTHOUR1 + i)->EnableWindow(iRet2);

		sprintf(lpnum,"%02d",m_vlost.m_timelist.pList[i].m_startmin);
		GetDlgItem(IDC_STARTMINUTE1 + i)->SetWindowText(lpnum);
		GetDlgItem(IDC_STARTMINUTE1 + i)->EnableWindow(iRet2);

		sprintf(lpnum,"%02d",m_vlost.m_timelist.pList[i].m_stophour);
		GetDlgItem(IDC_STOPHOUR1 + i)->SetWindowText(lpnum);
		GetDlgItem(IDC_STOPHOUR1 + i)->EnableWindow(iRet2);

		sprintf(lpnum,"%02d",m_vlost.m_timelist.pList[i].m_stopmin);
		GetDlgItem(IDC_STOPMINUTE1 + i)->SetWindowText(lpnum);
		GetDlgItem(IDC_STOPMINUTE1 + i)->EnableWindow(iRet2);
	}
	((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->SetCheck(m_vlost.m_bsinglehost);
	GetDlgItem(IDC_CHECK_ALARMTOHOST)->EnableWindow(iRet2);

	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->SetCheck(m_vlost.m_out[i]);
		GetDlgItem(IDC_CHECK_ALARMOUT1 + i)->EnableWindow(iRet2);
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
	((CButton*)GetDlgItem(IDC_CHECK_EN))->SetCheck(vilostenc);
	UpdateData(FALSE);
}

BOOL CDlgCHVLost::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	int i;
	char lpnum[3];
	for(i=0;i<7;i++)
	{
		m_vlost.m_timelist.pList[i].m_maskweek = ((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->GetCurSel();
		GetDlgItem(IDC_STARTHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_vlost.m_timelist.pList[i].m_starthour = atoi(lpnum);
		
		GetDlgItem(IDC_STARTMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_vlost.m_timelist.pList[i].m_startmin = atoi(lpnum);
		
		GetDlgItem(IDC_STOPHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_vlost.m_timelist.pList[i].m_stophour = atoi(lpnum);
		
		GetDlgItem(IDC_STOPMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_vlost.m_timelist.pList[i].m_stopmin = atoi(lpnum);
	}
	m_vlost.m_bsinglehost = ((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->GetCheck();
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		m_vlost.m_out[i] = ((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->GetCheck();
	}
	return TRUE;
}

void CDlgCHVLost::OnBtnSet() 
{
	BOOL vilostenc;
	CString strmsg;
	if(!UpdateParam()) return;

	vilostenc = ((CButton*)GetDlgItem(IDC_CHECK_EN))->GetCheck();
	
	g_SerParam->ReadParam(MESSAGE_CMD_SETVIDEOLOST,m_ch,&vilostenc,NULL,NULL);
	g_SerParam->SaveParam(MESSAGE_CMD_SETVIDEOLOSTPARAM,m_ch,&m_vlost,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgCHVLost::OnBtnCopy1() 
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
