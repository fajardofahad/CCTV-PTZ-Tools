// DlgChMotionTime.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgChMotionTime.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChMotionTime dialog

CDlgChMotionTime::CDlgChMotionTime(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChMotionTime::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChMotionTime)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_ch = 0;
}

void CDlgChMotionTime::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChMotionTime)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgChMotionTime, CDialog)
	//{{AFX_MSG_MAP(CDlgChMotionTime)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChMotionTime message handlers
LRESULT CDlgChMotionTime::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgChMotionTime::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	int i;
	CString strch,strtxt;

	GetDlgItem(IDC_COMBO_CHCOPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		GetDlgItem(IDC_CHECK_ALARMOUT1 + i)->ShowWindow(SW_SHOW);
	}
	if(g_SerParam->m_chs > 1)
	{
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

void CDlgChMotionTime::OnBtnGet()
{
	CString strmsg;
	int i,iRet1;
	char lpnum[3];

	memset(&m_channmotion,0,sizeof(CHANNMOTION));
	memset(&m_channmotionex,0,sizeof(CHANNMOTIONEX));
	for(i=0;i<7;i++)
	{
		m_channmotionex.m_timelist.pList[i].m_maskweek = 10;
	}

	m_type = 0;
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETMOTIONPARAM,m_ch,&m_channmotion,&m_channmotionex,&m_type);
	if(!m_type)
	{
		memset(&m_channmotionex,0,sizeof(CHANNMOTIONEX));
		m_channmotionex.m_beanb = m_channmotion.m_beanb; 
		m_channmotionex.m_alarmsenstive = m_channmotion.m_alarmsenstive; 
		m_channmotionex.m_brecord = m_channmotion.m_brecord; 
		memcpy((char*)m_channmotionex.m_outputmap,(char*)m_channmotion.m_outputmap,sizeof(m_channmotionex.m_outputmap)); 
		memcpy((char*)m_channmotionex.m_detect,(char*)m_channmotion.m_detect,sizeof(m_channmotionex.m_detect)); 
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

	for(i=0;i<7;i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->SetCurSel(m_channmotionex.m_timelist.pList[i].m_maskweek);

		sprintf(lpnum,"%02d",m_channmotionex.m_timelist.pList[i].m_starthour);
		GetDlgItem(IDC_STARTHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_channmotionex.m_timelist.pList[i].m_startmin);
		GetDlgItem(IDC_STARTMINUTE1 + i)->SetWindowText(lpnum);

		sprintf(lpnum,"%02d",m_channmotionex.m_timelist.pList[i].m_stophour);
		GetDlgItem(IDC_STOPHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_channmotionex.m_timelist.pList[i].m_stopmin);
		GetDlgItem(IDC_STOPMINUTE1 + i)->SetWindowText(lpnum);
	}
	
	((CButton*)GetDlgItem(IDC_CHECK_RECV1))->SetCheck(m_channmotionex.m_brecord);
	((CButton*)GetDlgItem(IDC_CHECK_CAPJPEG1))->SetCheck(m_channmotionex.m_capjpeg);
	GetDlgItem(IDC_CHECK_CAPJPEG1)->EnableWindow(m_type);
	((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->SetCheck(m_channmotionex.m_singlehost);
	GetDlgItem(IDC_CHECK_ALARMTOHOST)->EnableWindow(m_type);
	((CButton*)GetDlgItem(IDC_CHECK_EN))->SetCheck(m_channmotionex.m_beanb);

	
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->SetCheck(m_channmotionex.m_outputmap[i]);
	}

	UpdateData(FALSE);
}

BOOL CDlgChMotionTime::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	int i;
	char lpnum[3];
	for(i=0;i<7;i++)
	{
		m_channmotionex.m_timelist.pList[i].m_maskweek = ((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->GetCurSel();
		GetDlgItem(IDC_STARTHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_channmotionex.m_timelist.pList[i].m_starthour = atoi(lpnum);
		
		GetDlgItem(IDC_STARTMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_channmotionex.m_timelist.pList[i].m_startmin = atoi(lpnum);
		
		GetDlgItem(IDC_STOPHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_channmotionex.m_timelist.pList[i].m_stophour = atoi(lpnum);
		
		GetDlgItem(IDC_STOPMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_channmotionex.m_timelist.pList[i].m_stopmin = atoi(lpnum);
	}
	m_channmotionex.m_beanb      = ((CButton*)GetDlgItem(IDC_CHECK_EN))->GetCheck();
	m_channmotionex.m_brecord    = ((CButton*)GetDlgItem(IDC_CHECK_RECV1))->GetCheck();
	m_channmotionex.m_capjpeg    = ((CButton*)GetDlgItem(IDC_CHECK_CAPJPEG1))->GetCheck();
	m_channmotionex.m_singlehost = ((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->GetCheck();
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		m_channmotionex.m_outputmap[i] = ((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->GetCheck();
	}

	m_channmotion.m_beanb = m_channmotionex.m_beanb; 
	m_channmotion.m_alarmsenstive = m_channmotionex.m_alarmsenstive; 
	m_channmotion.m_brecord = m_channmotionex.m_brecord; 
	memcpy((char*)m_channmotion.m_outputmap,(char*)m_channmotionex.m_outputmap,sizeof(m_channmotion.m_outputmap)); 
	memcpy((char*)m_channmotion.m_detect,(char*)m_channmotionex.m_detect,sizeof(m_channmotion.m_detect)); 
	memcpy(&m_channmotion.m_timelist,&m_channmotionex.m_timelist,sizeof(TIMELIST)); 

	return TRUE;
}

void CDlgChMotionTime::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETMOTIONPARAM,m_ch,&m_channmotion,&m_channmotionex,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChMotionTime::OnBtnCopy1()
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
