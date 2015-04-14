// DlgMotifyURL.cpp : implementation file
//

#include "stdafx.h"
#include "camsearch.h"
#include "DlgMotifyURL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMotifyURL dialog


CDlgMotifyURL::CDlgMotifyURL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMotifyURL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMotifyURL)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgMotifyURL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMotifyURL)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMotifyURL, CDialog)
	//{{AFX_MSG_MAP(CDlgMotifyURL)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMotifyURL message handlers

BOOL CDlgMotifyURL::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString strinfo;
	// TODO: Add extra initialization here
	GetDlgItem(IDC_EDIT_NAME)->SetWindowText(m_camitem.m_sername);
	GetDlgItem(IDC_EDIT_URL)->SetWindowText(m_camitem.m_url);
	GetDlgItem(IDC_EDIT_SUBMASK)->SetWindowText(m_camitem.m_submask);
	GetDlgItem(IDC_EDIT_GETWAY)->SetWindowText(m_camitem.m_getway);
	GetDlgItem(IDC_EDIT_MULTIIP)->SetWindowText(m_camitem.m_multiip);
	GetDlgItem(IDC_EDIT_DNS)->SetWindowText(m_camitem.m_dns);
	strinfo.Format("%d",m_camitem.m_webport);
	GetDlgItem(IDC_EDIT_WEBPORT)->SetWindowText(strinfo);
	strinfo.Format("%d",m_camitem.m_localport);
	GetDlgItem(IDC_EDIT_LOCALPORT)->SetWindowText(strinfo);
	strinfo.Format("%d",m_camitem.m_multiport);
	GetDlgItem(IDC_EDIT_MULTIPORT)->SetWindowText(strinfo);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMotifyURL::OnOK() 
{
	char strport[6];
	// TODO: Add extra initialization here
	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(m_camitem.m_sername,40);
	GetDlgItem(IDC_EDIT_URL)->GetWindowText(m_camitem.m_url,16);
	GetDlgItem(IDC_EDIT_SUBMASK)->GetWindowText(m_camitem.m_submask,16);
	GetDlgItem(IDC_EDIT_GETWAY)->GetWindowText(m_camitem.m_getway,16);
	GetDlgItem(IDC_EDIT_MULTIIP)->GetWindowText(m_camitem.m_multiip,16);
	GetDlgItem(IDC_EDIT_DNS)->GetWindowText(m_camitem.m_dns,16);
	
	GetDlgItem(IDC_EDIT_WEBPORT)->GetWindowText(strport,sizeof(strport));
	m_camitem.m_webport = atoi(strport);
	
	GetDlgItem(IDC_EDIT_LOCALPORT)->GetWindowText(strport,sizeof(strport));
	m_camitem.m_localport = atoi(strport);

	GetDlgItem(IDC_EDIT_MULTIPORT)->GetWindowText(strport,sizeof(strport));
	m_camitem.m_multiport = atoi(strport);

	CDialog::OnOK();
}
