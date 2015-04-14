// DlgExAlarmParam.cpp : implementation file
//

#include "stdafx.h"
#include "luserparamx.h"
#include "DlgExAlarmParam.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgExAlarmParam dialog


CDlgExAlarmParam::CDlgExAlarmParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExAlarmParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExAlarmParam)
	m_comport = -1;
	m_protocol = -1;
	m_addr = 0;
	m_alarmtime = 0;
	m_checktime = 0;
	//}}AFX_DATA_INIT
	memset(&m_exalarmparam,0,sizeof(VSNETEXALARMPARAM));
}


void CDlgExAlarmParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExAlarmParam)
	DDX_CBIndex(pDX, IDC_COMBO_COMPORT, m_comport);
	DDX_CBIndex(pDX, IDC_COMBO_PROTOCOL, m_protocol);
	DDX_Text(pDX, IDC_EDIT_ADDR, m_addr);
	DDV_MinMaxInt(pDX, m_addr, 0, 255);
	DDX_Text(pDX, IDC_EDIT_ALARMTIME, m_alarmtime);
	DDV_MinMaxInt(pDX, m_alarmtime, 5, 3600);
	DDX_Text(pDX, IDC_EDIT_CHECKTIME, m_checktime);
	DDV_MinMaxInt(pDX, m_checktime, 2, 3600);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgExAlarmParam, CDialog)
	//{{AFX_MSG_MAP(CDlgExAlarmParam)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgExAlarmParam message handlers

void CDlgExAlarmParam::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	memset(&m_exalarmparam,0,sizeof(VSNETEXALARMPARAM));
	
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETEXALARMPARAM,0,&m_exalarmparam,NULL,NULL);
	GetDlgItem(IDC_COMBO_PROTOCOL)->EnableWindow(iRet1);
	GetDlgItem(IDC_COMBO_COMPORT)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_ADDR)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_CHECKTIME)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_ALARMTIME)->EnableWindow(iRet1);
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

	m_comport  = m_exalarmparam.m_comport; 
	m_protocol = m_exalarmparam.m_protocol; 
	m_addr     = m_exalarmparam.m_addr; 
	m_alarmtime = m_exalarmparam.m_alarmintervaltime; 
	m_checktime = m_exalarmparam.m_alarmchecktime; 
	UpdateData(FALSE);	
}

void CDlgExAlarmParam::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETEXALARMPARAM,0,&m_exalarmparam,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);		
}

LRESULT CDlgExAlarmParam::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	OnBtnGet();
	return 0;
}

BOOL CDlgExAlarmParam::UpdateParam()
{
	if(!UpdateData()) return FALSE;
	m_exalarmparam.m_comport = m_comport; 
	m_exalarmparam.m_protocol = m_protocol; 
	m_exalarmparam.m_addr = m_addr; 
	m_exalarmparam.m_alarmintervaltime = m_alarmtime; 
	m_exalarmparam.m_alarmchecktime = m_checktime; 
	return TRUE;
}