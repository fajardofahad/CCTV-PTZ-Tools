// DlgSerUser.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgSerUser.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSerUser dialog


CDlgSerUser::CDlgSerUser(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSerUser::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSerUser)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgSerUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSerUser)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSerUser, CDialog)
	//{{AFX_MSG_MAP(CDlgSerUser)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSerUser message handlers

BOOL CDlgSerUser::OnInitDialog()
{
	CDialog::OnInitDialog();
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

LRESULT CDlgSerUser::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	OnBtnGet();
	return 0;
}

void CDlgSerUser::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	memset(&m_wholeusr,0,sizeof(WHOLE_USER));

	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETSYSUSER,0,&m_wholeusr,NULL,NULL);
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

	int i;
	GetDlgItem(IDC_EDIT_ADMINUSR)->SetWindowText(m_wholeusr.m_admin.m_username);
	GetDlgItem(IDC_EDIT_ADMINPASS)->SetWindowText(m_wholeusr.m_admin.m_password);
	for(i=0;i<10;i++)
	{
		GetDlgItem(IDC_EDIT_HIOPUSR1 + i)->SetWindowText(m_wholeusr.hl_operator[i].m_username);
		GetDlgItem(IDC_EDIT_HIOPPASS1+ i)->SetWindowText(m_wholeusr.hl_operator[i].m_password);
		GetDlgItem(IDC_EDIT_OPUSR1 + i)->SetWindowText(m_wholeusr.m_operator[i].m_username);
		GetDlgItem(IDC_EDIT_OPPASS1+ i)->SetWindowText(m_wholeusr.m_operator[i].m_password);
	}
}

void CDlgSerUser::OnBtnSet() 
{
	int i;
	CString strpp;
	GetDlgItem(IDC_EDIT_ADMINUSR)->GetWindowText(strpp);
	if(strpp.GetLength() >= 20)
	{
		AfxMessageBox(IDS_STRING235);
		GetDlgItem(IDC_EDIT_ADMINUSR)->SetFocus();
		return;
	}
	sprintf(m_wholeusr.m_admin.m_username,"%s",strpp);

	GetDlgItem(IDC_EDIT_ADMINPASS)->GetWindowText(strpp);
	if(strpp.GetLength() >= 20)
	{
		AfxMessageBox(IDS_STRING236);
		GetDlgItem(IDC_EDIT_ADMINPASS)->SetFocus();
		return;
	}
	sprintf(m_wholeusr.m_admin.m_password,"%s",strpp);

	for(i=0;i<10;i++)
	{
		GetDlgItem(IDC_EDIT_HIOPUSR1 + i)->GetWindowText(strpp);
		if(strpp.GetLength() >= 20)
		{
			AfxMessageBox("IDS_STRING235");
			GetDlgItem(IDC_EDIT_HIOPUSR1 + i)->SetFocus();
			return;
		}
		sprintf(m_wholeusr.hl_operator[i].m_username,"%s",strpp);

		GetDlgItem(IDC_EDIT_HIOPPASS1+ i)->GetWindowText(strpp);
		if(strpp.GetLength() >= 20)
		{
			AfxMessageBox(IDS_STRING236);
			GetDlgItem(IDC_EDIT_HIOPPASS1+ i)->SetFocus();
			return;
		}
		sprintf(m_wholeusr.hl_operator[i].m_password,"%s",strpp);

		GetDlgItem(IDC_EDIT_OPUSR1 + i)->GetWindowText(strpp);
		if(strpp.GetLength() >= 20)
		{
			AfxMessageBox(IDS_STRING235);
			GetDlgItem(IDC_EDIT_OPUSR1 + i)->SetFocus();
			return;
		}
		sprintf(m_wholeusr.m_operator[i].m_username,"%s",strpp);

		GetDlgItem(IDC_EDIT_OPPASS1+ i)->GetWindowText(strpp);
		if(strpp.GetLength() >= 20)
		{
			AfxMessageBox(IDS_STRING236);
			GetDlgItem(IDC_EDIT_OPPASS1+ i)->SetFocus();
			return;
		}
		sprintf(m_wholeusr.m_operator[i].m_password,"%s",strpp);
	}

	g_SerParam->SaveParam(MESSAGE_CMD_SETSYSUSER,0,&m_wholeusr,NULL,NULL);

	strpp.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strpp);
}
