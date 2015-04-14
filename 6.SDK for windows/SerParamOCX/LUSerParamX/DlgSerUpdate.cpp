// DlgSerUpdate.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgSerUpdate.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSerUpdate dialog


CDlgSerUpdate::CDlgSerUpdate(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSerUpdate::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSerUpdate)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bCanExit = FALSE;
	m_updatesock  = -1;
	m_hEndEvent   = NULL;
	m_timerid  = 0;
}


void CDlgSerUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSerUpdate)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSerUpdate, CDialog)
	//{{AFX_MSG_MAP(CDlgSerUpdate)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSerUpdate message handlers

BOOL CDlgSerUpdate::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_timerid = SetTimer(1,1000,NULL);
	m_progress.SetRange(0,100);
	m_progress.SetPos(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSerUpdate::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1)
	{
		if(WaitForSingleObject(m_hEndEvent,0) == WAIT_OBJECT_0)
		{
			int ret;
			CString strmsg;
			KillTimer(m_timerid);
			ret = VSNET_ClientUpdateStop(m_updatesock);
			m_updatesock = -1;
			if(ret == 0)
			{
				strmsg.LoadString(IDS_STRING241);
				g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
			}
			else
			{
				CString tt;
				tt.LoadString(IDS_STRING242);
				strmsg.Format(tt,ret);
				g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
			}
			m_bCanExit = TRUE;
			CDialog::OnOK();
		}
		else
		{
			int pos = m_progress.GetPos();
			pos++;
			pos = pos > 100 ? 0 : pos;
			m_progress.SetPos(pos);
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CDlgSerUpdate::OnOK() 
{
	if(!m_bCanExit) return;
	CDialog::OnOK();
}

void CDlgSerUpdate::OnCancel() 
{	
	if(!m_bCanExit) return;
	CDialog::OnCancel();
}
