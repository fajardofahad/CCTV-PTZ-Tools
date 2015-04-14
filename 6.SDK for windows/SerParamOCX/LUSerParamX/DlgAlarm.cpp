// DlgAlarm.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgAlarm.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAlarm dialog


CDlgAlarm::CDlgAlarm(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAlarm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAlarm)
	m_alarminterval = 0;
	m_senname = _T("");
	//}}AFX_DATA_INIT
	m_curptzno = -1;
}


void CDlgAlarm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAlarm)
	DDX_Text(pDX, IDC_EDIT_INTERTIME, m_alarminterval);
	DDX_Text(pDX, IDC_EDIT_SENNAME, m_senname);
	DDV_MaxChars(pDX, m_senname, 32);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAlarm, CDialog)
	//{{AFX_MSG_MAP(CDlgAlarm)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	ON_CBN_SELCHANGE(IDC_COMBO_PTZCHSEL, OnSelchangeComboPtzchsel)
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAlarm message handlers
void CDlgAlarm::OnOK() 
{
	//CDialog::OnOK();
}

void CDlgAlarm::OnCancel() 
{	
	//CDialog::OnCancel();
}

LRESULT CDlgAlarm::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgAlarm::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	GetDlgItem(IDC_STATIC_CALLCH)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_COMBO_PTZCHSEL)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);

	GetDlgItem(IDC_COMBO_CHCOPY1)->ShowWindow(g_SerParam->m_alarmins > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY1)->ShowWindow(g_SerParam->m_alarmins > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_alarmins > 1 ? SW_SHOW : SW_HIDE);

	int i;
	CString strch,tt;
	for(i=0;i<g_SerParam->m_chs;i++)
	{
		tt.LoadString(IDS_STRING205);
		strch.Format(tt,i+1);
		((CComboBox*)GetDlgItem(IDC_COMBO_PTZCHSEL))->AddString(strch);
	}
	for(i=0;i<g_SerParam->m_chs;i++)
	{
		GetDlgItem(IDC_CHECK_RECV1 + i)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECK_CAPJPEG1 + i)->ShowWindow(SW_SHOW);
	}

	for(i=0;i<g_SerParam->m_alarmouts;i++)
		GetDlgItem(IDC_CHECK_ALARMOUT1 + i)->ShowWindow(SW_SHOW);

	if(g_SerParam->m_alarmins > 1)
	{
		int i;
		CString strch,strtxt;

		strtxt.LoadString(IDS_STRING264);
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->AddString(strtxt);
		for(i=0;i<g_SerParam->m_alarmins;i++)
		{
			strch.LoadString(IDS_STRING219);
			strtxt.Format(strch,i+1);
			((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->AddString(strtxt);
		}
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->SetCurSel(0);
	}
	return 0;
}

void CDlgAlarm::OnBtnGet()
{
	int i;
	CString strmsg;
	int iRet1;
	memset(&m_alarmname,0,sizeof(VSNETSENSORALARM));
	memset(&m_alarmpara,0,sizeof(ALARMPARAM));
	memset(&m_alarmparaex,0,sizeof(ALARMPARAMEX));
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETSENSORALARM,m_ch,&m_alarmname,NULL,NULL);
	GetDlgItem(IDC_EDIT_SENNAME)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_INTERTIME)->EnableWindow(iRet1);
	iRet1 = g_SerParam->ReadParam(MESSAGE_GETALARMPARAM,0,&m_alarmpara,&m_alarmparaex,&m_type);
	if(!m_type)
	{
		memset(&m_alarmparaex,0,sizeof(ALARMPARAMEX));
		m_alarmparaex.m_benab = m_alarmpara.m_benab;
		for(i=0;i<8;i++)
		{
			memcpy((char*)m_alarmparaex.m_alarmrec[i].m_record,(char*)m_alarmpara.m_alarmrec[i].m_record,sizeof(m_alarmparaex.m_alarmrec[i].m_record));
			memcpy((char*)m_alarmparaex.m_alarmrec[i].m_out,(char*)m_alarmpara.m_alarmrec[i].m_out,sizeof(m_alarmparaex.m_alarmrec[i].m_out));
			memcpy((char*)m_alarmparaex.m_alarmrec[i].m_enpreno,(char*)m_alarmpara.m_alarmrec[i].m_enpreno,sizeof(m_alarmparaex.m_alarmrec[i].m_enpreno));
			memcpy((char*)m_alarmparaex.m_alarmrec[i].m_preno,(char*)m_alarmpara.m_alarmrec[i].m_preno,sizeof(m_alarmparaex.m_alarmrec[i].m_preno));
			memcpy(&m_alarmparaex.m_alarmrec[i].m_timelist,&m_alarmpara.m_alarmrec[i].m_timelist,sizeof(TIMELIST));
		}		
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
	char lpnum[3];
	((CButton*)GetDlgItem(IDC_CHECK_ON))->SetCheck(m_alarmparaex.m_benab);
	for(i=0;i<7;i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->SetCurSel(m_alarmparaex.m_alarmrec[m_ch].m_timelist.pList[i].m_maskweek);

		sprintf(lpnum,"%02d",m_alarmparaex.m_alarmrec[m_ch].m_timelist.pList[i].m_starthour);
		GetDlgItem(IDC_STARTHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_alarmparaex.m_alarmrec[m_ch].m_timelist.pList[i].m_startmin);
		GetDlgItem(IDC_STARTMINUTE1 + i)->SetWindowText(lpnum);

		sprintf(lpnum,"%02d",m_alarmparaex.m_alarmrec[m_ch].m_timelist.pList[i].m_stophour);
		GetDlgItem(IDC_STOPHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_alarmparaex.m_alarmrec[m_ch].m_timelist.pList[i].m_stopmin);
		GetDlgItem(IDC_STOPMINUTE1 + i)->SetWindowText(lpnum);
	}
	for(i=0;i<g_SerParam->m_chs;i++)
	{
		((CButton*)GetDlgItem(IDC_CHECK_RECV1 + i))->SetCheck(m_alarmparaex.m_alarmrec[m_ch].m_record[i]);
		((CButton*)GetDlgItem(IDC_CHECK_CAPJPEG1 + i))->SetCheck(m_alarmparaex.m_alarmrec[m_ch].m_capjpeg[i]);
		GetDlgItem(IDC_CHECK_CAPJPEG1 + i)->EnableWindow(m_type);
	}
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->SetCheck(m_alarmparaex.m_alarmrec[m_ch].m_out[i]);
	}
	((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->SetCheck(m_alarmparaex.m_alarmrec[m_ch].m_singlehost);
	GetDlgItem(IDC_CHECK_ALARMTOHOST)->EnableWindow(m_type);
	((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->SetCurSel(m_alarmparaex.m_alarmrec[m_ch].m_alarmmode);
	GetDlgItem(IDC_COMBO_MODE)->EnableWindow(m_type);
	((CComboBox*)GetDlgItem(IDC_COMBO_PTZCHSEL))->SetCurSel(0);
	m_curptzno = -1;
	m_alarminterval = m_alarmname.m_senseorinterval;
	m_senname       = m_alarmname.m_alarmname;
	UpdateData(FALSE);
	OnSelchangeComboPtzchsel();
}

BOOL CDlgAlarm::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	int i;
	char lpnum[3];
	int ch = m_ch;

	for(i=0;i<7;i++)
	{
		m_alarmparaex.m_alarmrec[ch].m_timelist.pList[i].m_maskweek = ((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->GetCurSel();
		GetDlgItem(IDC_STARTHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_alarmparaex.m_alarmrec[ch].m_timelist.pList[i].m_starthour = atoi(lpnum);
		
		GetDlgItem(IDC_STARTMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_alarmparaex.m_alarmrec[ch].m_timelist.pList[i].m_startmin = atoi(lpnum);
		
		GetDlgItem(IDC_STOPHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_alarmparaex.m_alarmrec[ch].m_timelist.pList[i].m_stophour = atoi(lpnum);
		
		GetDlgItem(IDC_STOPMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_alarmparaex.m_alarmrec[ch].m_timelist.pList[i].m_stopmin = atoi(lpnum);
	}
	for(i=0;i<g_SerParam->m_chs;i++)
	{
		m_alarmparaex.m_alarmrec[ch].m_record[i] = ((CButton*)GetDlgItem(IDC_CHECK_RECV1 + i))->GetCheck();
		m_alarmparaex.m_alarmrec[ch].m_capjpeg[i] = ((CButton*)GetDlgItem(IDC_CHECK_CAPJPEG1 + i))->GetCheck();
	}
	for(i=0;i<g_SerParam->m_alarmouts;i++)
	{
		m_alarmparaex.m_alarmrec[ch].m_out[i] = ((CButton*)GetDlgItem(IDC_CHECK_ALARMOUT1 + i))->GetCheck();
	}
	if(m_curptzno != -1)
	{
		m_alarmparaex.m_alarmrec[ch].m_enpreno[m_curptzno] = ((CButton*)GetDlgItem(IDC_CHECK_PTZCALL))->GetCheck();
		GetDlgItem(IDC_EDIT_PTZNO)->GetWindowText(lpnum,sizeof(lpnum));
		m_alarmparaex.m_alarmrec[ch].m_preno[m_curptzno] = atoi(lpnum);
	}
	m_alarmparaex.m_alarmrec[m_ch].m_alarmmode = ((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->GetCurSel();
	m_alarmparaex.m_alarmrec[ch].m_singlehost = ((CButton*)GetDlgItem(IDC_CHECK_ALARMTOHOST))->GetCheck();
	m_alarmparaex.m_benab = ((CButton*)GetDlgItem(IDC_CHECK_ON))->GetCheck();

	memset(&m_alarmpara,0,sizeof(ALARMPARAM));
	m_alarmpara.m_benab = m_alarmparaex.m_benab;
	for(i=0;i<8;i++)
	{
		memcpy((char*)m_alarmpara.m_alarmrec[i].m_record,(char*)m_alarmparaex.m_alarmrec[i].m_record,sizeof(m_alarmpara.m_alarmrec[i].m_record));
		memcpy((char*)m_alarmpara.m_alarmrec[i].m_out,(char*)m_alarmparaex.m_alarmrec[i].m_out,sizeof(m_alarmpara.m_alarmrec[i].m_out));
		memcpy((char*)m_alarmpara.m_alarmrec[i].m_enpreno,(char*)m_alarmparaex.m_alarmrec[i].m_enpreno,sizeof(m_alarmpara.m_alarmrec[i].m_enpreno));
		memcpy((char*)m_alarmpara.m_alarmrec[i].m_preno,(char*)m_alarmparaex.m_alarmrec[i].m_preno,sizeof(m_alarmpara.m_alarmrec[i].m_preno));
		memcpy(&m_alarmpara.m_alarmrec[i].m_timelist,&m_alarmparaex.m_alarmrec[i].m_timelist,sizeof(TIMELIST));
	}

	m_alarmname.m_senseorinterval = m_alarminterval;
	sprintf(m_alarmname.m_alarmname,"%s",m_senname);
	UpdateData(FALSE);
	return TRUE;
}

void CDlgAlarm::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_SETALARMPARAM,0,&m_alarmpara,&m_alarmparaex,NULL);
	g_SerParam->SaveParam(MESSAGE_CMD_SETSENSORALARM,m_ch,&m_alarmname,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgAlarm::OnBtnCopy1() 
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
		for(i=0;i<g_SerParam->m_alarmins;i++)
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

void CDlgAlarm::OnSelchangeComboPtzchsel() 
{	
	char str[10];
	int chno  = ((CComboBox*)GetDlgItem(IDC_COMBO_PTZCHSEL))->GetCurSel();
	if(m_curptzno != -1)
	{
		m_alarmparaex.m_alarmrec[m_ch].m_enpreno[m_curptzno] = ((CButton*)GetDlgItem(IDC_CHECK_PTZCALL))->GetCheck();
		GetDlgItem(IDC_EDIT_PTZNO)->GetWindowText(str,sizeof(str));
		m_alarmparaex.m_alarmrec[m_ch].m_preno[m_curptzno] = atoi(str);
	}
	m_curptzno = chno;
	((CButton*)GetDlgItem(IDC_CHECK_PTZCALL))->SetCheck(m_alarmparaex.m_alarmrec[m_ch].m_enpreno[m_curptzno]);
	sprintf(str,"%d",m_alarmparaex.m_alarmrec[m_ch].m_preno[m_curptzno]);
	GetDlgItem(IDC_EDIT_PTZNO)->SetWindowText(str);
}
