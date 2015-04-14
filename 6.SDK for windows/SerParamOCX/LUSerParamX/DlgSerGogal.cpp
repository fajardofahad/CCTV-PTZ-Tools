// DlgSerGogal.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgSerGogal.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSerGogal dialog


CDlgSerGogal::CDlgSerGogal(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSerGogal::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSerGogal)
	m_sername = _T("");
	m_autotime = 0;
	m_deviceID = _T("");
	m_ftppass = _T("");
	m_ftpuser = _T("");
	m_maxconnect = 1;
	m_devicemodel = _T("");
	m_sipport = 5000;
	//}}AFX_DATA_INIT
}


void CDlgSerGogal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSerGogal)
	DDX_Text(pDX, IDC_EDIT_NAME, m_sername);
	DDV_MaxChars(pDX, m_sername, 100);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_autotime);
	DDX_Text(pDX, IDC_EDIT_DEVICEID, m_deviceID);
	DDV_MaxChars(pDX, m_deviceID, 31);
	DDX_Text(pDX, IDC_EDIT_FTPPASS, m_ftppass);
	DDV_MaxChars(pDX, m_ftppass, 19);
	DDX_Text(pDX, IDC_EDIT_FTPUSER, m_ftpuser);
	DDV_MaxChars(pDX, m_ftpuser, 19);
	DDX_Text(pDX, IDC_EDIT_MAXCONNECT, m_maxconnect);
	DDV_MinMaxInt(pDX, m_maxconnect, 1, 20);
	DDX_Text(pDX, IDC_EDIT_DEVICEMODEL, m_devicemodel);
	DDV_MaxChars(pDX, m_devicemodel, 31);
	DDX_Text(pDX, IDC_EDIT_SIPPORT, m_sipport);
	DDV_MinMaxInt(pDX, m_sipport, 1, 65535);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgSerGogal, CDialog)
	//{{AFX_MSG_MAP(CDlgSerGogal)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSerGogal message handlers

BOOL CDlgSerGogal::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

LRESULT CDlgSerGogal::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	OnBtnGet();
	return 0;
}

void CDlgSerGogal::OnBtnGet() 
{
	CString strmsg;
	int iRet1,iRet2;
	char serialnumber[50];
	memset(serialnumber,'\0',sizeof(serialnumber));
	memset(&m_timerreset,0,sizeof(VSTIMERRESET));
	memset(&m_wholeparam,0,sizeof(WHOLEPARAM));
	memset(&m_linkconfig,0,sizeof(VSNETLINKCONFIG));

	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETSERIALNO,0,serialnumber,NULL,NULL);
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETTIMEDRESET,0,&m_timerreset,NULL,NULL);
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETGLOBALPARAM,0,&m_wholeparam,NULL,NULL);
	iRet2 = g_SerParam->ReadParam(MESSAGE_CMD_GETLINKCONFIG,0,&m_linkconfig,NULL,NULL);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);
	if(!iRet1)
	{
		strmsg.LoadString(IDS_STRING231);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		return;
	}
	else
	{
		strmsg.LoadString(IDS_STRING233);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	}
	m_sername = m_wholeparam.m_servername;
	GetDlgItem(IDC_EDIT_VERSION)->SetWindowText(m_wholeparam.m_version.pStrAPPVer);
	GetDlgItem(IDC_EDIT_VERTIME)->SetWindowText(m_wholeparam.m_version.pStrAPPBuildTime);
	((CComboBox*)GetDlgItem(IDC_COMBO_ISPAL))->SetCurSel(m_wholeparam.m_isPAL);
	((CComboBox*)GetDlgItem(IDC_COMBO_LAUNAGE))->SetCurSel(m_wholeparam.m_launage -1);
	GetDlgItem(IDC_EDIT_SERIALNO)->SetWindowText(serialnumber);
	((CButton*)GetDlgItem(IDC_CHECK_TIMERESET))->SetCheck(m_timerreset.m_benbale);
	m_autotime = CTime(2000,1,1,m_timerreset.m_rsthour,m_timerreset.m_rstminute,0,0);

	GetDlgItem(IDC_EDIT_DEVICEID)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_MAXCONNECT)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_FTPUSER)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_FTPPASS)->EnableWindow(iRet2);
	GetDlgItem(IDC_COMBO_LINKTYPE)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_DEVICEMODEL)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_SIPPORT)->EnableWindow(iRet2);
	if(iRet2)
	{
		m_deviceID = m_linkconfig.m_deviceID;
		m_maxconnect = m_linkconfig.m_maxconnect;
		m_ftppass = m_linkconfig.m_ftppass;
		m_ftpuser = m_linkconfig.m_ftpuser;
		m_sipport = m_linkconfig.m_sipport;
		m_devicemodel = m_linkconfig.m_devicemodel;
		if(m_linkconfig.m_linktype < 1 || m_linkconfig.m_linktype > 3)
		{
			((CComboBox*)GetDlgItem(IDC_COMBO_LINKTYPE))->SetCurSel(0);
		}
		else
		{
			((CComboBox*)GetDlgItem(IDC_COMBO_LINKTYPE))->SetCurSel(m_linkconfig.m_linktype - 1);
		}
	}
	UpdateData(FALSE);
}

void CDlgSerGogal::OnBtnSet() 
{
	CString strmsg;
	if(!UpdateData()) return;
	sprintf(m_wholeparam.m_servername,"%s",m_sername);
	m_wholeparam.m_isPAL = ((CComboBox*)GetDlgItem(IDC_COMBO_ISPAL))->GetCurSel();
	m_wholeparam.m_launage = ((CComboBox*)GetDlgItem(IDC_COMBO_LAUNAGE))->GetCurSel() + 1;
	m_timerreset.m_benbale = ((CButton*)GetDlgItem(IDC_CHECK_TIMERESET))->GetCheck();
	m_timerreset.m_rsthour = m_autotime.GetHour();
	m_timerreset.m_rstminute = m_autotime.GetMinute();

	sprintf(m_linkconfig.m_deviceID,"%s",m_deviceID);
	m_linkconfig.m_maxconnect = m_maxconnect;
	sprintf(m_linkconfig.m_ftppass,"%s",m_ftppass);
	sprintf(m_linkconfig.m_ftpuser,"%s",m_ftpuser);
	m_linkconfig.m_linktype = ((CComboBox*)GetDlgItem(IDC_COMBO_LINKTYPE))->GetCurSel() + 1;
	m_linkconfig.m_sipport = m_sipport;
	sprintf(m_linkconfig.m_devicemodel,"%s",m_devicemodel);

	g_SerParam->SaveParam(MESSAGE_CMD_SETTIMEDRESET,0,&m_timerreset,NULL,NULL);
	g_SerParam->SaveParam(MESSAGE_CMD_SETGLOBALPARAM,0,&m_wholeparam,NULL,NULL);
	g_SerParam->SaveParam(MESSAGE_CMD_SETLINKCONFIG,0,&m_linkconfig,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}
