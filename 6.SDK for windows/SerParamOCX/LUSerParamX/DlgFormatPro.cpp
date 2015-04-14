// DlgFormatPro.cpp : implementation file
//

#include "stdafx.h"
#include "luserparamx.h"
#include "DlgSerParam.h"
#include "DlgFormatPro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgFormatPro dialog

CDlgFormatPro::CDlgFormatPro(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFormatPro::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgFormatPro)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_canexit = FALSE;
	m_timerid = 0;
}

void CDlgFormatPro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgFormatPro)
	DDX_Control(pDX, IDC_PROGRESS1, m_formatpro);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgFormatPro, CDialog)
	//{{AFX_MSG_MAP(CDlgFormatPro)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGFREEPARAM_MSG, OnFormtReturn)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgFormatPro message handlers

void CDlgFormatPro::OnOK() 
{
	// TODO: Add extra validation here
	if(!m_canexit) return;
	CDialog::OnOK();
}

void CDlgFormatPro::OnCancel() 
{	
	//CDialog::OnCancel();
}

UINT CALLBACK CDlgFormatPro::formatdiskthread(CDlgFormatPro *pDlgFormat)
{
	pDlgFormat->m_errno = VSNET_ClientMessageOpt(pDlgFormat->m_hParam,MESSAGE_CMD_FORMATDISK,0,&pDlgFormat->m_disksel,NULL,NULL);
	pDlgFormat->PostMessage(DLGFREEPARAM_MSG,0,0);
	return 0;
}

BOOL CDlgFormatPro::OnInitDialog() 
{
	CDialog::OnInitDialog();
	UINT ID;

	m_propos = 0;
	m_formatpro.SetRange(0,100);
	m_formatpro.SetPos(m_propos);
	m_hThread = (HANDLE)_beginthreadex(NULL,1024 * 10,
		(unsigned (__stdcall *) (void *))&formatdiskthread,
		this,0,&ID);
	m_timerid = SetTimer(10,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgFormatPro::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent == 10)
	{
		m_propos ++;
		m_propos = m_propos > 100 ? 0 : m_propos;
		m_formatpro.SetPos(m_propos);
	}
	CDialog::OnTimer(nIDEvent);
}

void CDlgFormatPro::OnDestroy() 
{
	if(m_timerid) KillTimer(m_timerid);
	m_timerid = 0;
	if(m_hThread)
	{
		WaitForSingleObject(m_hThread,-1);
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}
	CDialog::OnDestroy();
}

LRESULT CDlgFormatPro::OnFormtReturn(WPARAM wParam,LPARAM lParam)
{
	CDialog::OnOK();
	return 0;
}
