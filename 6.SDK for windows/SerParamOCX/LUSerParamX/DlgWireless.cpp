// DlgWireless.cpp : implementation file
//

#include "stdafx.h"
#include "luserparamx.h"
#include "DlgWireless.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgWireless dialog


CDlgWireless::CDlgWireless(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgWireless::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgWireless)
	m_usecdma = FALSE;
	m_usewifi = FALSE;
	m_weptype = 0;
	m_wiredns = _T("");
	m_wiregateway = _T("");
	m_wireip = _T("");
	m_password = _T("");
	m_ssid = _T("");
	m_wiresubmask = _T("");
	//}}AFX_DATA_INIT
	memset(&m_cdmaparam,0,sizeof(VSNETCDMAPARAM));
	memset(&m_wifiparam,0,sizeof(VSNETWIFIPARAM));
}


void CDlgWireless::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgWireless)
	DDX_Check(pDX, IDC_CHECK_USECDMA, m_usecdma);
	DDX_Check(pDX, IDC_CHECK_USEWIFI, m_usewifi);
	DDX_CBIndex(pDX, IDC_COMBO_WEP, m_weptype);
	DDX_Text(pDX, IDC_EDIT_DNS, m_wiredns);
	DDV_MaxChars(pDX, m_wiredns, 15);
	DDX_Text(pDX, IDC_EDIT_GETWAY, m_wiregateway);
	DDV_MaxChars(pDX, m_wiregateway, 15);
	DDX_Text(pDX, IDC_EDIT_IP, m_wireip);
	DDV_MaxChars(pDX, m_wireip, 15);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 60);
	DDX_Text(pDX, IDC_EDIT_SSID, m_ssid);
	DDV_MaxChars(pDX, m_ssid, 39);
	DDX_Text(pDX, IDC_EDIT_SUBMASK, m_wiresubmask);
	DDV_MaxChars(pDX, m_wiresubmask, 15);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgWireless, CDialog)
	//{{AFX_MSG_MAP(CDlgWireless)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgWireless message handlers

LRESULT CDlgWireless::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	OnBtnGet();
	return 0;
}

void CDlgWireless::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	memset(&m_cdmaparam,0,sizeof(VSNETCDMAPARAM));
	memset(&m_wifiparam,0,sizeof(VSNETWIFIPARAM));

	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETCDMAPARAM,0,&m_cdmaparam,NULL,NULL);
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETWIFIPARAM,0,&m_wifiparam,NULL,NULL);
	GetDlgItem(IDC_CHECK_USECDMA)->EnableWindow(iRet1);
	GetDlgItem(IDC_CHECK_USEWIFI)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_SSID)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_IP)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_SUBMASK)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_GETWAY)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_DNS)->EnableWindow(iRet1);
	GetDlgItem(IDC_COMBO_WEP)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(iRet1);
	GetDlgItem(IDC_BTN_GET)->EnableWindow(iRet1);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);

	if(!iRet1)
	{
		strmsg.LoadString(IDS_STRING281);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		return;
	}
	else
	{
		strmsg.LoadString(IDS_STRING282);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	}

	m_usecdma = m_cdmaparam.m_usecdma;
	m_usewifi = m_wifiparam.m_usewifi;
	m_wireip  = m_wifiparam.m_wifiipaddr;
	m_wiresubmask = m_wifiparam.m_wifinetmask;
	m_wiregateway = m_wifiparam.m_wifigateway;
	m_wiredns = m_wifiparam.m_wifidns;
	m_ssid = m_wifiparam.m_wifissid;
	m_weptype = m_wifiparam.m_wifiencmode;
	m_password = m_wifiparam.m_wifipwd;
	UpdateData(FALSE);
}

void CDlgWireless::OnBtnSet() 
{
	int i;
	CString strmsg;
	if(!UpdateData()) return;

	if(m_weptype == 1)
	{
		if(m_password.GetLength() != 5 && m_password.GetLength() != 10)
		{
			AfxMessageBox(IDS_STRING283);
			return;
		}
		if(m_password.GetLength() == 10)
		{
			for(i=0;i<m_password.GetLength();i++)
			{
				if(!isxdigit(m_password.GetAt(i)))
				{
					AfxMessageBox(IDS_STRING283);
					return;
				}
			}
		}
	}
	else if(m_weptype == 2)
	{
		if(m_password.GetLength() != 13 && m_password.GetLength() != 26)
		{
			AfxMessageBox(IDS_STRING284);
			return;
		}
		if(m_password.GetLength() == 26)
		{
			for(i=0;i<m_password.GetLength();i++)
			{
				if(!isxdigit(m_password.GetAt(i)))
				{
					AfxMessageBox(IDS_STRING284);
					return;
				}
			}
		}
	}
	m_cdmaparam.m_usecdma = m_usecdma;
	m_wifiparam.m_usewifi = m_usewifi;
	sprintf(m_wifiparam.m_wifiipaddr,"%s",m_wireip);
	sprintf(m_wifiparam.m_wifinetmask,"%s",m_wiresubmask);
	sprintf(m_wifiparam.m_wifigateway,"%s",m_wiregateway);
	sprintf(m_wifiparam.m_wifidns,"%s",m_wiredns);
	sprintf(m_wifiparam.m_wifissid,"%s",m_ssid);
	sprintf(m_wifiparam.m_wifipwd,"%s",m_password);
	m_wifiparam.m_wifiencmode = m_weptype;
	g_SerParam->SaveParam(MESSAGE_CMD_SETCDMAPARAM,0,&m_cdmaparam,NULL,NULL);
	g_SerParam->SaveParam(MESSAGE_CMD_SETWIFIPARAM,0,&m_wifiparam,NULL,NULL);

	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}
