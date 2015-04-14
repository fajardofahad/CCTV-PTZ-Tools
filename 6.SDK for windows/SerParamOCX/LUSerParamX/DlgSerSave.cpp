// DlgSerSave.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgSerSave.h"
#include "DlgSerParam.h"
#include "DlgSerUpdate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSerSave dialog


CDlgSerSave::CDlgSerSave(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSerSave::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSerSave)
	m_syncdate = 0;
	m_synctime = 0;
	//}}AFX_DATA_INIT
	m_timerid = 0;
}


void CDlgSerSave::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSerSave)
	DDX_DateTimeCtrl(pDX, IDC_DATE_SYNCDATE, m_syncdate);
	DDX_DateTimeCtrl(pDX, IDC_DATE_SYNCTIME, m_synctime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSerSave, CDialog)
	//{{AFX_MSG_MAP(CDlgSerSave)
	ON_BN_CLICKED(IDC_BTN_SYNCTIME1, OnBtnSynctime1)
	ON_BN_CLICKED(IDC_BTN_SYNCTIME2, OnBtnSynctime2)
	ON_BN_CLICKED(IDC_BTN_SELFILE, OnBtnSelfile)
	ON_BN_CLICKED(IDC_BTN_UPDATE, OnBtnUpdate)
	ON_BN_CLICKED(IDC_BTN_SAVE, OnBtnSave)
	ON_BN_CLICKED(IDC_BTN_RESET, OnBtnReset)
	ON_BN_CLICKED(IDC_BTN_DEFAULT, OnBtnDefault)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGFREEPARAM_MSG,OnDlgFree)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSerSave message handlers
LRESULT CDlgSerSave::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	if(m_timerid) KillTimer(m_timerid);
	m_timerid = 0;
	m_timerid = SetTimer(1,1000,NULL);

	SYSTEMTIME dwTime = {0};
	GetLocalTime(&dwTime);
	m_syncdate = m_synctime = CTime(dwTime.wYear,dwTime.wMonth,dwTime.wDay,dwTime.wHour,dwTime.wMinute,dwTime.wSecond);
	UpdateData(FALSE);
	return 0;
}
LRESULT CDlgSerSave::OnDlgFree(WPARAM wParam,LPARAM lParam)
{
	if(m_timerid) KillTimer(m_timerid);
	m_timerid = 0;
	return 0;
}
void CDlgSerSave::OnBtnSynctime1() 
{
	int iRet;
	CString strmsg;
	UpdateData();
	TIME_PARAM ptimepara;
	ptimepara.m_year  = m_syncdate.GetYear();
	ptimepara.m_month = (BYTE)m_syncdate.GetMonth();
	ptimepara.m_dayofmonth = (BYTE)m_syncdate.GetDay();
	ptimepara.m_dayofweek  = (BYTE)m_syncdate.GetDayOfWeek() - 1;
	ptimepara.m_hour       = (BYTE)m_synctime.GetHour();
	ptimepara.m_minute     = (BYTE)m_synctime.GetMinute();
	ptimepara.m_second     = (BYTE)m_synctime.GetSecond();
	iRet = g_SerParam->SaveParam(MESSAGE_CMD_SETSYSTIME,0,&ptimepara,NULL,NULL);
	if(iRet)
	{
		strmsg.LoadString(IDS_STRING243);
	}
	else
	{
		strmsg.LoadString(IDS_STRING244);
	}
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgSerSave::OnBtnSynctime2() 
{
	int iRet;
	CString strmsg;
	SYSTEMTIME dwTime = {0};
	TIME_PARAM ptimepara;

	GetLocalTime(&dwTime);
	ptimepara.m_year  = dwTime.wYear;
	ptimepara.m_month = (BYTE)dwTime.wMonth;
	ptimepara.m_dayofmonth = (BYTE)dwTime.wDay;
	ptimepara.m_dayofweek  = (BYTE)dwTime.wDayOfWeek;
	ptimepara.m_hour       = (BYTE)dwTime.wHour;
	ptimepara.m_minute     = (BYTE)dwTime.wMinute;
	ptimepara.m_second     = (BYTE)dwTime.wSecond;
	iRet = g_SerParam->SaveParam(MESSAGE_CMD_SETSYSTIME,0,&ptimepara,NULL,NULL);
	if(iRet)
	{
		strmsg.LoadString(IDS_STRING243);
	}
	else
	{
		strmsg.LoadString(IDS_STRING244);
	}
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgSerSave::OnBtnSelfile() 
{
	CString info;
	info.LoadString(IDS_STRING237);
	CFileDialog dlg(TRUE,"*.*","",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		info);
	if(dlg.DoModal()==IDOK)
	{
		GetDlgItem(IDC_EDIT_FILE)->SetWindowText(dlg.GetPathName());
	}
}

void CDlgSerSave::OnBtnUpdate() 
{
	CString strmsg;
	CDlgSerUpdate dlg;
	HANDLE m_hEndEvent = NULL;
	LONG m_updatesock = -1;
	char filename[MAX_PATH];
	GetDlgItem(IDC_EDIT_FILE)->GetWindowText(filename,MAX_PATH);
	if(strlen(filename) < 1)
	{
		strmsg.LoadString(IDS_STRING265);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		return;
	}
	FILE *fpFile = fopen(filename,"rb");
	if(fpFile == NULL)
	{
		strmsg.LoadString(IDS_STRING238);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		goto err_exit;
	}
	fclose(fpFile);
	m_hEndEvent = CreateEvent(0,FALSE,FALSE,0);
	m_updatesock = VSNET_ClientUpdateStart(((char*)(const char*)g_SerParam->m_serurl),
		((char*)(const char*)g_SerParam->m_username),((char*)(const char*)g_SerParam->m_password),
		filename,m_hEndEvent,g_SerParam->m_serport,(char*)(const char*)g_SerParam->m_sername);
	if(m_updatesock == -1) 
	{
		strmsg.LoadString(IDS_STRING239);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		goto err_exit;
	}
	strmsg.LoadString(IDS_STRING240);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	
	dlg.m_updatesock = m_updatesock;
	dlg.m_hEndEvent  = m_hEndEvent;
	dlg.DoModal();
	m_updatesock = -1;

err_exit:
	if(m_updatesock != -1)
		VSNET_ClientUpdateStop(m_updatesock);
	m_updatesock = -1;
	if(m_hEndEvent)
		CloseHandle(m_hEndEvent);
	m_hEndEvent = NULL;
}

void CDlgSerSave::OnBtnSave() 
{
	int iRet;
	CString strmsg;
	iRet = g_SerParam->SaveParam(MESSAGE_CMD_SAVEPARA,0,NULL,NULL,NULL);
	if(iRet)
	{
		strmsg.LoadString(IDS_STRING245);
	}
	else
	{
		strmsg.LoadString(IDS_STRING246);
	}
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgSerSave::OnBtnReset() 
{
	int iRet;
	CString strmsg;
	if(AfxMessageBox(IDS_STRING247,MB_ICONQUESTION|MB_OKCANCEL) != IDOK)
		return;
	strmsg.LoadString(IDS_STRING248);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	iRet = VSNET_ClientMessageOpt(g_SerParam->m_hParam,MESSAGE_CMD_RESET,0,NULL,NULL,NULL);
	if(iRet)
	{
		strmsg.LoadString(IDS_STRING249);
	}
	else
	{
		AfxMessageBox(IDS_STRING250);
	}
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgSerSave::OnBtnDefault() 
{
	int iRet;
	CString strmsg;
	if(AfxMessageBox(IDS_STRING251,MB_ICONQUESTION|MB_OKCANCEL) != IDOK)
		return;
	strmsg.LoadString(IDS_STRING252);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	iRet = VSNET_ClientMessageOpt(g_SerParam->m_hParam,MESSAGE_CMD_PARAMDEFAULT,0,NULL,NULL,NULL);
	if(iRet)
	{
		strmsg.LoadString(IDS_STRING253);
	}
	else
	{
		AfxMessageBox(IDS_STRING254);
	}
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgSerSave::OnTimer(UINT nIDEvent) 
{	
	if(nIDEvent == 1)
	{
		SYSTEMTIME dwTime = {0};
		CString strtime;
		GetLocalTime(&dwTime);
		strtime.Format("%04d-%02d-%02d %02d:%02d:%02d",
			dwTime.wYear,dwTime.wMonth,dwTime.wDay,
			dwTime.wHour,dwTime.wMinute,dwTime.wSecond);
		GetDlgItem(IDC_STATIC_CURTIME)->SetWindowText(strtime);
	}
	CDialog::OnTimer(nIDEvent);
}
