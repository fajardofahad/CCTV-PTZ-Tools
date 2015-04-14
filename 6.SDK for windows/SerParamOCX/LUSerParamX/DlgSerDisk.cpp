// DlgSerDisk.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgSerDisk.h"
#include "DlgSerParam.h"
#include "DlgFormatPro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSerDisk dialog


CDlgSerDisk::CDlgSerDisk(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSerDisk::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSerDisk)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgSerDisk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSerDisk)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSerDisk, CDialog)
	//{{AFX_MSG_MAP(CDlgSerDisk)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_FORMAT, OnBtnFormat)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSerDisk message handlers
LRESULT CDlgSerDisk::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	OnBtnGet();
	return 0;
}

LRESULT CDlgSerDisk::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	return 0;
}

void CDlgSerDisk::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	int i;
	CString strinfo;

	memset(&m_diskstate,0,sizeof(VSDISKSTATE));
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETDISKSTATE,0,&m_diskstate,NULL,NULL);
	if(!iRet1)
	{
		strmsg.LoadString(IDS_STRING266);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		GetDlgItem(IDC_BTN_FORMAT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DISK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_DISK)->ShowWindow(SW_HIDE);
		return;
	}
	else
	{
		strmsg.LoadString(IDS_STRING233);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	}

	while(((CComboBox*)GetDlgItem(IDC_COMBO_DISK))->GetCount())
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_DISK))->DeleteString(0);
	}
	
	strmsg.LoadString(IDS_STRING267);
	((CComboBox*)GetDlgItem(IDC_COMBO_DISK))->AddString(strmsg);
	for(i=0;i<m_diskstate.m_hds;i++)
	{
		if(m_diskstate.m_hdtype[i] == 0) //IDE
			strinfo.LoadString(IDS_STRING271);
		else
			strinfo.LoadString(IDS_STRING272);
		GetDlgItem(IDC_STATIC_TYPE1 + i)->SetWindowText(strinfo);

		ConvertDiskSize(m_diskstate.m_totalsize[i],strinfo);
		GetDlgItem(IDC_STATIC_TOTALSIZE1 + i)->SetWindowText(strinfo);
		
		ConvertDiskSize(m_diskstate.m_freesize[i],strinfo);
		GetDlgItem(IDC_STATIC_FREESIZE1 + i)->SetWindowText(strinfo);

		if(m_diskstate.m_hdstate[i] == 0)
			strinfo.LoadString(IDS_STRING268);
		else
			strinfo.LoadString(IDS_STRING269);
		GetDlgItem(IDC_STATIC_STAT1 + i)->SetWindowText(strinfo);

		strinfo.LoadString(IDS_STRING270);
		strmsg.Format(strinfo,i+1);
		((CComboBox*)GetDlgItem(IDC_COMBO_DISK))->AddString(strmsg);
	}
	((CComboBox*)GetDlgItem(IDC_COMBO_DISK))->SetCurSel(0);
	GetDlgItem(IDC_BTN_FORMAT)->ShowWindow(m_diskstate.m_hds > 0 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_DISK)->ShowWindow(m_diskstate.m_hds > 0 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_COMBO_DISK)->ShowWindow(m_diskstate.m_hds > 0 ? SW_SHOW : SW_HIDE);
}

void CDlgSerDisk::ConvertDiskSize(int size, CString &strret)
{
	if(size >= 1000)
	{
		float recc;
		recc = (float)size / (float)1000.0;
		strret.Format("%.2fG",recc);
	}
	else
	{
		strret.Format("%dM",size);
	}
}

void CDlgSerDisk::OnBtnFormat() 
{	

	CDlgFormatPro dlg;
	CString strmsg;
	int sel = ((CComboBox*)GetDlgItem(IDC_COMBO_DISK))->GetCurSel();
	if(sel == -1)
	{
		AfxMessageBox(IDS_STRING273);
		return;
	}
	if(sel == 0) //all disk
	{
		strmsg.LoadString(IDS_STRING274);
		if(AfxMessageBox(IDS_STRING274,MB_YESNO|MB_ICONQUESTION) != IDYES)
			return;
	}
	else
	{
		CString strinfo;
		strmsg.LoadString(IDS_STRING275);
		strinfo.Format(strmsg,sel);
		if(AfxMessageBox(strinfo,MB_YESNO|MB_ICONQUESTION) != IDYES)
			return;
	}
	if(sel == 0) 
		sel = 0XFF;
	else
		sel --;
	strmsg.LoadString(IDS_STRING276);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	dlg.m_disksel = sel;
	dlg.m_hParam  = g_SerParam->m_hParam;
	dlg.DoModal();
	//iRet = VSNET_ClientMessageOpt(g_SerParam->m_hParam,MESSAGE_CMD_FORMATDISK,0,&sel,NULL,NULL);
	strmsg.LoadString(dlg.m_errno ? IDS_STRING277 : IDS_STRING278);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}
