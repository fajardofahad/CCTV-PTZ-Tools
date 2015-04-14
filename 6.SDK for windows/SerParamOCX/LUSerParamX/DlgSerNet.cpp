// DlgSerNet.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgSerNet.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSerNet dialog


CDlgSerNet::CDlgSerNet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSerNet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSerNet)
	m_bpppoe = -1;
	m_buseddns = -1;
	m_alarmhostport = 0;
	m_alarmhosturl = _T("");
	m_strddnsurl = _T("");
	m_ddnsmaport = 0;
	m_ddnsport = 0;
	m_strdns = _T("");
	m_strgateway = _T("");
	m_strip = _T("");
	m_strmac = _T("");
	m_strmultiip = _T("");
	m_multiport = 0;
	m_strpppowpsw = _T("");
	m_strpppoeuid = _T("");
	m_hostport = 0;
	m_hosturl = _T("");
	m_serport = 0;
	m_strsubmask = _T("");
	m_webport = 0;
	m_ddnsprovider = 0;
	m_ddnspass = _T("");
	m_ddnsusername = _T("");
	m_ddnstime = 10;
	m_ddnsname = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSerNet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSerNet)
	DDX_CBIndex(pDX, IDC_COMBO_PPPOE, m_bpppoe);
	DDX_CBIndex(pDX, IDC_COMBO_USEDDNS, m_buseddns);
	DDX_Text(pDX, IDC_EDIT_ALARMPORT, m_alarmhostport);
	DDX_Text(pDX, IDC_EDIT_ALARMURL, m_alarmhosturl);
	DDV_MaxChars(pDX, m_alarmhosturl, 40);
	DDX_Text(pDX, IDC_EDIT_DDNSIP, m_strddnsurl);
	DDX_Text(pDX, IDC_EDIT_DDNSMAPPORT, m_ddnsmaport);
	DDX_Text(pDX, IDC_EDIT_DDNSPORT, m_ddnsport);
	DDX_Text(pDX, IDC_EDIT_DNS, m_strdns);
	DDV_MaxChars(pDX, m_strdns, 15);
	DDX_Text(pDX, IDC_EDIT_GETWAY, m_strgateway);
	DDV_MaxChars(pDX, m_strgateway, 15);
	DDX_Text(pDX, IDC_EDIT_IP, m_strip);
	DDV_MaxChars(pDX, m_strip, 15);
	DDX_Text(pDX, IDC_EDIT_MAC, m_strmac);
	DDX_Text(pDX, IDC_EDIT_MULTIIP, m_strmultiip);
	DDV_MaxChars(pDX, m_strmultiip, 15);
	DDX_Text(pDX, IDC_EDIT_MULTIPORT, m_multiport);
	DDX_Text(pDX, IDC_EDIT_PPPOEPASS, m_strpppowpsw);
	DDV_MaxChars(pDX, m_strpppowpsw, 60);
	DDX_Text(pDX, IDC_EDIT_PPPOEUSER, m_strpppoeuid);
	DDV_MaxChars(pDX, m_strpppoeuid, 60);
	DDX_Text(pDX, IDC_EDIT_REHOSTPORT, m_hostport);
	DDX_Text(pDX, IDC_EDIT_REHOSTURL, m_hosturl);
	DDV_MaxChars(pDX, m_hosturl, 40);
	DDX_Text(pDX, IDC_EDIT_SERPORT, m_serport);
	DDX_Text(pDX, IDC_EDIT_SUBMASK, m_strsubmask);
	DDX_Text(pDX, IDC_EDIT_WEBPORT, m_webport);
	DDX_CBIndex(pDX, IDC_COMBO_DDNSPROVIDER, m_ddnsprovider);
	DDX_Text(pDX, IDC_EDIT_DDNSPASS, m_ddnspass);
	DDV_MaxChars(pDX, m_ddnspass, 19);
	DDX_Text(pDX, IDC_EDIT_DDNSUSERNAME, m_ddnsusername);
	DDV_MaxChars(pDX, m_ddnsusername, 19);
	DDX_Text(pDX, IDC_EDIT_DDNSTIME, m_ddnstime);
	DDV_MinMaxInt(pDX, m_ddnstime, 10, 65535);
	DDX_Text(pDX, IDC_EDIT_DDNSNAME, m_ddnsname);
	DDV_MaxChars(pDX, m_ddnsname, 48);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSerNet, CDialog)
	//{{AFX_MSG_MAP(CDlgSerNet)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSerNet message handlers

LRESULT CDlgSerNet::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	OnBtnGet();
	return 0;
}

void CDlgSerNet::OnBtnGet() 
{
	CString strmsg;
	int iRet1,iRet2;
	memset(&m_remotehost,0,sizeof(VSREMOTEHOST));
	memset(&m_wholeparam,0,sizeof(WHOLEPARAM));
	memset(&m_pppoeparam,0,sizeof(VSNETPPPOEPARAM));
	memset(&m_ddnsexparam,0,sizeof(VSNETDNSEXPARAM));

	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETREMOTEHOST,0,&m_remotehost,NULL,NULL);
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETPPPOEPARAM,0,&m_pppoeparam,NULL,NULL);
	GetDlgItem(IDC_COMBO_PPPOE)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_PPPOEUSER)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_PPPOEPASS)->EnableWindow(iRet1);
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETGLOBALPARAM,0,&m_wholeparam,NULL,NULL);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);

	iRet2 = g_SerParam->ReadParam(MESSAGE_CMD_GETDDNSEXPARAM,0,&m_ddnsexparam,NULL,NULL);
	GetDlgItem(IDC_COMBO_DDNSPROVIDER)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_DDNSUSERNAME)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_DDNSPASS)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_DDNSTIME)->EnableWindow(iRet2);
	GetDlgItem(IDC_EDIT_DDNSNAME)->EnableWindow(iRet2);

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
	
	m_strip     = m_wholeparam.m_serverip;
	m_strsubmask = m_wholeparam.m_servermask;
	m_strdns     = m_wholeparam.m_dnsaddr;
	m_strgateway  = m_wholeparam.m_gatewayAddr;
	m_strmultiip = m_wholeparam.m_multiAddr;
	m_serport = m_wholeparam.m_serport;
	m_multiport = m_wholeparam.m_mulport;
	m_webport = m_wholeparam.m_webport;
	m_strmac.Format("%02X-%02X-%02X-%02X-%02X-%02X",
		m_wholeparam.m_phyAddr[0],m_wholeparam.m_phyAddr[1],m_wholeparam.m_phyAddr[2],
		m_wholeparam.m_phyAddr[3],m_wholeparam.m_phyAddr[4],m_wholeparam.m_phyAddr[5]);

	m_buseddns   = m_wholeparam.m_ddns.bUseDDNS;
	m_strddnsurl = m_wholeparam.m_ddns.DDNSSerIp;
	m_ddnsport   = m_wholeparam.m_ddns.DDNSSerPort;
	m_ddnsmaport = m_wholeparam.m_ddns.LocalMapPort;

	m_bpppoe       = m_pppoeparam.m_busepppoe;
	m_strpppoeuid  = m_pppoeparam.m_pppoename;
	m_strpppowpsw  = m_pppoeparam.m_pppoepswd;

	m_hosturl       = m_remotehost.m_hostserverurl;
	m_alarmhosturl  = m_remotehost.m_alarservermurl;
	m_hostport      = m_remotehost.m_hostserverport;
	m_alarmhostport = m_remotehost.m_alarserverport;

	if(iRet2)
	{
		m_ddnsprovider  = m_ddnsexparam.m_dnsprovider;
		m_ddnsusername  = m_ddnsexparam.m_dnsusername;
		m_ddnspass      = m_ddnsexparam.m_dnspassword;
		m_ddnstime      = m_ddnsexparam.m_ddnsnotifytime;
		m_ddnsname      = m_ddnsexparam.m_dnsdomainname;
	}
	UpdateData(FALSE);
}

void CDlgSerNet::OnBtnSet() 
{
	CString strmsg;
	UpdateData();

	if(m_buseddns)
	{
		if(m_strddnsurl.IsEmpty())
		{
			GetDlgItem(IDC_EDIT_DDNSIP);
			AfxMessageBox(IDS_STRING234);
			return;
		}
	}
	sprintf(m_wholeparam.m_serverip,"%s",m_strip);
	sprintf(m_wholeparam.m_servermask,"%s",m_strsubmask);
	sprintf(m_wholeparam.m_dnsaddr,"%s",m_strdns);
	sprintf(m_wholeparam.m_gatewayAddr,"%s",m_strgateway);
	sprintf(m_wholeparam.m_multiAddr,"%s",m_strmultiip);
	m_wholeparam.m_serport = m_serport;
	m_wholeparam.m_mulport = m_multiport;
	m_wholeparam.m_webport = m_webport;
	m_wholeparam.m_ddns.bUseDDNS = m_buseddns;
	sprintf(m_wholeparam.m_ddns.DDNSSerIp,"%s",m_strddnsurl);
	m_wholeparam.m_ddns.DDNSSerPort = m_ddnsport;
	m_wholeparam.m_ddns.LocalMapPort  = m_ddnsmaport;
	g_SerParam->SaveParam(MESSAGE_CMD_SETGLOBALPARAM,0,&m_wholeparam,NULL,NULL);
	m_pppoeparam.m_busepppoe = m_bpppoe;
	sprintf(m_pppoeparam.m_pppoename,"%s",m_strpppoeuid);
	sprintf(m_pppoeparam.m_pppoepswd,"%s",m_strpppowpsw);
	g_SerParam->SaveParam(MESSAGE_CMD_SETPPPOEPARAM,0,&m_pppoeparam,NULL,NULL);

	sprintf(m_remotehost.m_hostserverurl,"%s",m_hosturl);
	sprintf(m_remotehost.m_alarservermurl,"%s",m_alarmhosturl);
	m_remotehost.m_hostserverport = m_hostport;
	m_remotehost.m_alarserverport = m_alarmhostport;
	g_SerParam->SaveParam(MESSAGE_CMD_SETREMOTEHOST,0,&m_remotehost,NULL,NULL);

	sprintf(m_ddnsexparam.m_dnspassword,"%s",m_ddnspass);
	sprintf(m_ddnsexparam.m_dnsusername,"%s",m_ddnsusername);
	sprintf(m_ddnsexparam.m_dnsdomainname,"%s",m_ddnsname);

	m_ddnsexparam.m_dnsprovider = m_ddnsprovider;
	m_ddnsexparam.m_ddnsnotifytime = m_ddnstime;
	g_SerParam->SaveParam(MESSAGE_CMD_SETDDNSEXPARAM,0,&m_ddnsexparam,NULL,NULL);

	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}
