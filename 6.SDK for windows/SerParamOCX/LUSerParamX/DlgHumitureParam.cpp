// DlgHumitureParam.cpp : implementation file
//

#include "stdafx.h"
#include  <math.h>
#include "luserparamx.h"
#include "DlgSerParam.h"
#include "DlgHumitureParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgHumitureParam dialog


CDlgHumitureParam::CDlgHumitureParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHumitureParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgHumitureParam)
	m_hummax = _T("");
	m_hummin = _T("");
	m_tempmax = _T("");
	m_tempmin = _T("");
	m_delaytime = 0;
	m_singlehost = FALSE;
	//}}AFX_DATA_INIT
	memset(&m_humitureparam,0,sizeof(VSNETHUMITUREPRAM));
}


void CDlgHumitureParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgHumitureParam)
	DDX_Text(pDX, IDC_EDIT_HUMMAX, m_hummax);
	DDV_MaxChars(pDX, m_hummax, 6);
	DDX_Text(pDX, IDC_EDIT_HUMMIN, m_hummin);
	DDV_MaxChars(pDX, m_hummin, 6);
	DDX_Text(pDX, IDC_EDIT_TEMPMAX, m_tempmax);
	DDV_MaxChars(pDX, m_tempmax, 7);
	DDX_Text(pDX, IDC_EDIT_TEMPMIN, m_tempmin);
	DDV_MaxChars(pDX, m_tempmin, 7);
	DDX_Text(pDX, IDC_EDIT_DELAYTIME, m_delaytime);
	DDV_MinMaxInt(pDX, m_delaytime, 5, 3600);
	DDX_Check(pDX, IDC_CHECK_ALARMTOHOST, m_singlehost);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgHumitureParam, CDialog)
	//{{AFX_MSG_MAP(CDlgHumitureParam)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgHumitureParam message handlers
void CDlgHumitureParam::OnOK() 
{
	//CDialog::OnOK();
}

void CDlgHumitureParam::OnCancel() 
{	
	//CDialog::OnCancel();
}

void CDlgHumitureParam::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETHUMITUREPRAM,0,&m_humitureparam,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);	
}
LRESULT CDlgHumitureParam::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	OnBtnGet();
	return 0;
}

LRESULT CDlgHumitureParam::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	int i;
	for(i=0;i<g_SerParam->m_chs;i++)
	{
		GetDlgItem(IDC_CHECK_RECV1 + i)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECK_CAPJPEG1 + i)->ShowWindow(SW_SHOW);
	}

	for(i=0;i<g_SerParam->m_alarmouts;i++)
		GetDlgItem(IDC_CHECK_ALARMOUT1 + i)->ShowWindow(SW_SHOW);
	return 0;
}

void CDlgHumitureParam::OnBtnGet() 
{
	int i;
	CString strmsg;
	int iRet1;
	memset(&m_humitureparam,0,sizeof(VSNETHUMITUREPRAM));
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETHUMITUREPRAM,0,&m_humitureparam,NULL,NULL);
	GetDlgItem(IDC_CHECK_ON)->EnableWindow(iRet1);
	GetDlgItem(IDC_CHECK_ALARMTOHOST)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_DELAYTIME)->EnableWindow(iRet1);
	for(i=0;i<7;i++)
	{
		GetDlgItem(IDC_COMBO_TIME1 + i)->EnableWindow(iRet1);
		GetDlgItem(IDC_STARTHOUR1 + i)->EnableWindow(iRet1);
		GetDlgItem(IDC_STARTMINUTE1 + i)->EnableWindow(iRet1);
		GetDlgItem(IDC_STOPHOUR1 + i)->EnableWindow(iRet1);
		GetDlgItem(IDC_STOPMINUTE1 + i)->EnableWindow(iRet1);
	}
	for(i=0;i<4;i++)
	{
		GetDlgItem(IDC_CHECK_RECV1 + i)->EnableWindow(iRet1);
		GetDlgItem(IDC_CHECK_CAPJPEG1 + i)->EnableWindow(iRet1);
		GetDlgItem(IDC_CHECK_ALARMOUT1 + i)->EnableWindow(iRet1);
	}
	GetDlgItem(IDC_EDIT_TEMPMAX)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_TEMPMIN)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_HUMMAX)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_HUMMIN)->EnableWindow(iRet1);
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
	char lpnum[3];
	((CButton*)GetDlgItem(IDC_CHECK_ON))->SetCheck(m_humitureparam.m_benablecheck);
	for(i=0;i<7;i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->SetCurSel(m_humitureparam.m_timeList.pList[i].m_maskweek);

		sprintf(lpnum,"%02d",m_humitureparam.m_timeList.pList[i].m_starthour);
		GetDlgItem(IDC_STARTHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_humitureparam.m_timeList.pList[i].m_startmin);
		GetDlgItem(IDC_STARTMINUTE1 + i)->SetWindowText(lpnum);

		sprintf(lpnum,"%02d",m_humitureparam.m_timeList.pList[i].m_stophour);
		GetDlgItem(IDC_STOPHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_humitureparam.m_timeList.pList[i].m_stopmin);
		GetDlgItem(IDC_STOPMINUTE1 + i)->SetWindowText(lpnum);
	}
	for(i=0;i<g_SerParam->m_chs;i++)
	{
		((CButton*)GetDlgItem(IDC_CHECK_RECV1 + i))->SetCheck(m_humitureparam.m_record[i]);
		((CButton*)GetDlgItem(IDC_CHECK_CAPJPEG1 + i))->SetCheck(m_humitureparam.m_capture[i]);
	}
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->SetCheck(m_humitureparam.m_boutput[i]);
	}
	m_delaytime = m_humitureparam.m_delay;
	m_singlehost = m_humitureparam.m_singlehost;
	m_tempmax.Format("%3.2f",m_humitureparam.m_tempmax);
	m_tempmin.Format("%3.2f",m_humitureparam.m_tempmin);
	m_hummax.Format("%3.2f",m_humitureparam.m_hummax);
	m_hummin.Format("%3.2f",m_humitureparam.m_hummin);
	UpdateData(FALSE);
}

BOOL CDlgHumitureParam::UpdateParam()
{
	if(!UpdateData()) return FALSE;
	if(atof(m_tempmin) > atof(m_tempmax))
	{
		AfxMessageBox(IDS_STRING286);
		return FALSE;
	}
	m_tempmin.Format("%3.2f",atof(m_tempmin));
	m_tempmax.Format("%3.2f",atof(m_tempmax));
	m_hummin.Format("%3.2f",fabs(atof(m_hummin)));
	m_hummax.Format("%3.2f",fabs(atof(m_hummax)));
	UpdateData(FALSE);
	if(atof(m_hummin) > atof(m_hummax))
	{
		AfxMessageBox(IDS_STRING287);
		return FALSE;
	}

	int i;
	char lpnum[3];

	for(i=0;i<7;i++)
	{
		m_humitureparam.m_timeList.pList[i].m_maskweek = ((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->GetCurSel();
		GetDlgItem(IDC_STARTHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_humitureparam.m_timeList.pList[i].m_starthour = atoi(lpnum);
		
		GetDlgItem(IDC_STARTMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_humitureparam.m_timeList.pList[i].m_startmin = atoi(lpnum);
		
		GetDlgItem(IDC_STOPHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_humitureparam.m_timeList.pList[i].m_stophour = atoi(lpnum);
		
		GetDlgItem(IDC_STOPMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_humitureparam.m_timeList.pList[i].m_stopmin = atoi(lpnum);
	}
	for(i=0;i<g_SerParam->m_chs;i++)
	{
		m_humitureparam.m_record[i] = ((CButton*)GetDlgItem(IDC_CHECK_RECV1 + i))->GetCheck();
		m_humitureparam.m_capture[i] = ((CButton*)GetDlgItem(IDC_CHECK_CAPJPEG1 + i))->GetCheck();
	}
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		m_humitureparam.m_boutput[i] = ((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->GetCheck();
	}
	m_humitureparam.m_benablecheck = ((CButton*)GetDlgItem(IDC_CHECK_ON))->GetCheck();
	m_humitureparam.m_delay = m_delaytime;
	m_humitureparam.m_singlehost = m_singlehost;
	m_humitureparam.m_tempmin = (float)atof(m_tempmin);
	m_humitureparam.m_tempmax = (float)atof(m_tempmax);
	m_humitureparam.m_hummax = (float)atof(m_hummax);
	m_humitureparam.m_hummin = (float)atof(m_hummin);
	return TRUE;
}

