// camsearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "camsearch.h"
#include "camsearchDlg.h"
#include "CamSearchLib.h"
#include "DlgMotifyURL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
static CCamsearchDlg *s_CamSearDlg;

static void WINAPI s_searchnotify(int devtype,char *m_sername,char *m_url,BYTE m_mac[6],WORD m_webport,WORD m_localport,
					char *m_submask,char *m_getway,char *m_multiip,char *m_dns,WORD m_multiport,int channel = 0);
static void WINAPI localipnotify(char *localip)
{
	((CComboBox*)(s_CamSearDlg->GetDlgItem(IDC_COMBO_LOCALIP)))->AddString(localip);
}
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamsearchDlg dialog

CCamsearchDlg::CCamsearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCamsearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCamsearchDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	s_CamSearDlg = this;
}

void CCamsearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCamsearchDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCam);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCamsearchDlg, CDialog)
	//{{AFX_MSG_MAP(CCamsearchDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEARCH, OnBtnSearch)
	ON_WM_DESTROY()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_BTN_MODIFY, OnBtnModify)
	ON_BN_CLICKED(IDC_BTN_RESET, OnBtnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamsearchDlg message handlers

BOOL CCamsearchDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ListCam.InsertColumn(0, "server name" , LVCFMT_LEFT, 80);
	m_ListCam.InsertColumn(1, "Dev Type"    , LVCFMT_LEFT, 60);
	m_ListCam.InsertColumn(2, "IP"	        , LVCFMT_LEFT, 110);
	m_ListCam.InsertColumn(3, "MAC"		    , LVCFMT_LEFT, 120);
	m_ListCam.InsertColumn(4, "Web Port"    , LVCFMT_LEFT, 62);
	m_ListCam.InsertColumn(5, "Data Port"   , LVCFMT_LEFT, 66);
	m_ListCam.InsertColumn(6, "Channel"     , LVCFMT_LEFT, 60);
	m_ListCam.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	CAMSEAR_Startup();

	GetEthernetInfo(localipnotify);
	((CComboBox*)(GetDlgItem(IDC_COMBO_LOCALIP)))->SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCamsearchDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCamsearchDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCamsearchDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCamsearchDlg::OnBtnSearch() 
{
	CleanAllList();
	m_ListCam.UpdateWindow();
	if(((CComboBox*)(GetDlgItem(IDC_COMBO_LOCALIP)))->GetCurSel() != 0)
	{
		CString lpstr;
		char    lpstring[40];
		GetDlgItem(IDC_COMBO_LOCALIP)->GetWindowText(lpstr);
		sprintf(lpstring,"%s",lpstr);
		CAMSEAR_Searchcam(2000,s_searchnotify,lpstring);    //wait for 2 seconds
	}
	else
	{
		CAMSEAR_Searchcam(5000,s_searchnotify);     //wait for 5 seconds
	}
}
static void WINAPI s_searchnotify(int devtype,char *m_sername,char *m_url,BYTE m_mac[6],WORD m_webport,WORD m_localport,
					char *m_submask,char *m_getway,char *m_multiip,char *m_dns,WORD m_multiport,int channel)
{
	int nItem;
	char lpstr[100];
	nItem = s_CamSearDlg->m_ListCam.InsertItem(0,m_sername);
	if(devtype == 1)
		s_CamSearDlg->m_ListCam.SetItemText(nItem,1,"SERVER");
	else
		s_CamSearDlg->m_ListCam.SetItemText(nItem,1,"DECODER");
	s_CamSearDlg->m_ListCam.SetItemText(nItem,2, m_url);
	sprintf(lpstr,"%02X-%02X-%02X-%02X-%02X-%02X",
			m_mac[0],m_mac[1],m_mac[2],m_mac[3],m_mac[4],m_mac[5]);
	s_CamSearDlg->m_ListCam.SetItemText(nItem,3, lpstr);
	sprintf(lpstr,"%d",m_webport);
	s_CamSearDlg->m_ListCam.SetItemText(nItem,4, lpstr);
	sprintf(lpstr,"%d",m_localport);
	s_CamSearDlg->m_ListCam.SetItemText(nItem,5, lpstr);
	sprintf(lpstr,"%d",channel);
	s_CamSearDlg->m_ListCam.SetItemText(nItem,6, lpstr);

	CAMLIST_ITEM *listitem = new CAMLIST_ITEM;
	strcpy(listitem->m_getway,m_getway);
	listitem->m_localport = m_localport;
	memcpy(listitem->m_mac,m_mac,6);
	strcpy(listitem->m_multiip,m_multiip);
	listitem->m_multiport = m_multiport;
	strcpy(listitem->m_sername,m_sername);
	strcpy(listitem->m_submask,m_submask);
	strcpy(listitem->m_url,m_url);
	strcpy(listitem->m_dns,m_dns);
	listitem->m_webport = m_webport;
	s_CamSearDlg->m_ListCam.SetItemData(nItem,(DWORD)listitem);
	s_CamSearDlg->m_ListCam.UpdateWindow();
}

void CCamsearchDlg::OnDestroy()
{
	CleanAllList();
	CAMSEAR_Cleanup();
	CDialog::OnDestroy();	
}

void CCamsearchDlg::CleanAllList()
{
	int i;
	for(i=0;i<m_ListCam.GetItemCount();i++)
	{
		CAMLIST_ITEM *listitem = (CAMLIST_ITEM*)m_ListCam.GetItemData(i);
		delete listitem;
	}
	m_ListCam.DeleteAllItems();
}

void CCamsearchDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_ListCam.GetSelectedCount())
	{
		OnBtnModify();
	}
	*pResult = 0;
}

void CCamsearchDlg::OnBtnModify() 
{
	int nItem;
	CAMLIST_ITEM *listitem;
	BOOL iRet;
	if(m_ListCam.GetItemCount() < 1) return;

	if(m_ListCam.GetSelectedCount() == 0)
	{
		AfxMessageBox("Please select server which you want to revise!");
		m_ListCam.SetFocus();
		return;
	}
	CDlgMotifyURL dlg;
	nItem = m_ListCam.GetNextItem(-1, LVNI_SELECTED);
	listitem = (CAMLIST_ITEM*)m_ListCam.GetItemData(nItem);
	memcpy(&dlg.m_camitem,listitem,sizeof(CAMLIST_ITEM));
	if(dlg.DoModal() != IDOK)
	{
		return;
	}
	memcpy(listitem,&dlg.m_camitem,sizeof(CAMLIST_ITEM));

	if(((CComboBox*)(GetDlgItem(IDC_COMBO_LOCALIP)))->GetCurSel() != 0)
	{
		CString lpstr;
		char    lpstring[40];
		GetDlgItem(IDC_COMBO_LOCALIP)->GetWindowText(lpstr);
		sprintf(lpstring,"%s",lpstr);
	    iRet = CAMSEAR_SearchSeturl(listitem->m_mac,
			listitem->m_sername,listitem->m_url,listitem->m_submask,listitem->m_getway,listitem->m_multiip,listitem->m_dns,
			listitem->m_webport,listitem->m_localport,listitem->m_multiport,lpstring);
	}
	else
	{
	    iRet = CAMSEAR_SearchSeturl(listitem->m_mac,
			listitem->m_sername,listitem->m_url,listitem->m_submask,listitem->m_getway,listitem->m_multiip,listitem->m_dns,
			listitem->m_webport,listitem->m_localport,listitem->m_multiport);
	}
	if(iRet)
		AfxMessageBox("Revise Success!");
	else
		AfxMessageBox("Revise failed!");
	
}

void CCamsearchDlg::OnBtnReset() 
{
	int nItem;
	CAMLIST_ITEM *listitem;
	BOOL iRet;
	if(m_ListCam.GetItemCount() < 1) return;

	if(m_ListCam.GetSelectedCount() == 0)
	{
		AfxMessageBox("Please select server which you want to reset!");
		m_ListCam.SetFocus();
		return;
	}
	nItem = m_ListCam.GetNextItem(-1, LVNI_SELECTED);
	listitem = (CAMLIST_ITEM*)m_ListCam.GetItemData(nItem);
	if(AfxMessageBox("Are you sure to reset?",MB_ICONQUESTION|MB_OKCANCEL) != IDOK)
		return;

	if(((CComboBox*)(GetDlgItem(IDC_COMBO_LOCALIP)))->GetCurSel() != 0)
	{
		CString lpstr;
		char    lpstring[40];
		GetDlgItem(IDC_COMBO_LOCALIP)->GetWindowText(lpstr);
		sprintf(lpstring,"%s",lpstr);
		iRet = CAMSEAR_SearchReset(listitem->m_mac,lpstring);
	}
	else
		iRet = CAMSEAR_SearchReset(listitem->m_mac);

	if(iRet)
		AfxMessageBox("Reset Successful!");
	else
		AfxMessageBox("Reset failed!");
}
