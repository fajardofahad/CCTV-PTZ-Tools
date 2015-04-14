// DlgChPtz.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgChPtz.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChPtz dialog


CDlgChPtz::CDlgChPtz(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChPtz::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChPtz)
	m_addr = 0;
	m_bitrate = -1;
	m_checkbit = -1;
	m_databit = -1;
	m_stopbit = -1;
	//}}AFX_DATA_INIT
}


void CDlgChPtz::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChPtz)
	DDX_Text(pDX, IDC_ADDR, m_addr);
	DDV_MinMaxInt(pDX, m_addr, 0, 254);
	DDX_CBIndex(pDX, IDC_BITRATE, m_bitrate);
	DDX_CBIndex(pDX, IDC_CHECKBIT, m_checkbit);
	DDX_CBIndex(pDX, IDC_DATABIT, m_databit);
	DDX_CBIndex(pDX, IDC_STOPBIT, m_stopbit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChPtz, CDialog)
	//{{AFX_MSG_MAP(CDlgChPtz)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	ON_BN_CLICKED(IDC_BTN_FILE, OnBtnFile)
	ON_BN_CLICKED(IDC_BTN_PTZFILESET, OnBtnPtzfileset)
	ON_BN_CLICKED(IDC_BTN_COPY2, OnBtnCopy2)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChPtz message handlers
LRESULT CDlgChPtz::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgChPtz::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	GetDlgItem(IDC_COMBO_CHCOPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY2)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_COMBO_CHCOPY2)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);

	if(g_SerParam->m_chs > 1)
	{
		int i;
		CString strch,strtxt;

		strtxt.LoadString(IDS_STRING255);
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->AddString(strtxt);
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			strch.LoadString(IDS_STRING205);
			strtxt.Format(strch,i+1);
			((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->AddString(strtxt);
		}
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->SetCurSel(0);

		strtxt.LoadString(IDS_STRING255);
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->AddString(strtxt);
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			strch.LoadString(IDS_STRING205);
			strtxt.Format(strch,i+1);
			((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->AddString(strtxt);
		}
		((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->SetCurSel(0);
	}
	return 0;
}

void CDlgChPtz::OnBtnGet()
{
	CString strmsg;
	int iRet1;
	memset(&m_param485,0,sizeof(SERIAL485_PARAM));
	
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETSERIAL,m_ch,&m_param485,NULL,NULL);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_PTZCMDNAME,m_ch,m_lpptzcmdname,NULL,NULL);
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

	m_addr = m_param485.decoderAddress;

	if(m_param485.m_baudrate == 300) m_bitrate = 0;
	else if(m_param485.m_baudrate == 600)	m_bitrate = 1;
	else if(m_param485.m_baudrate == 1200)	m_bitrate = 2;
	else if(m_param485.m_baudrate == 2400)	m_bitrate = 3;
	else if(m_param485.m_baudrate == 4800)	m_bitrate = 4;
	else if(m_param485.m_baudrate == 9600)	m_bitrate = 5;
	else if(m_param485.m_baudrate == 19200) m_bitrate = 6;
	else if(m_param485.m_baudrate == 38400) m_bitrate = 7;
	else if(m_param485.m_baudrate == 57600) m_bitrate = 8;
	else if(m_param485.m_baudrate == 115200) m_bitrate = 9;
	else								    m_bitrate = 4;
	m_checkbit = m_param485.m_checkbit;
	if(m_param485.m_databit == 5) m_databit = 0;
	else if(m_param485.m_databit == 6) m_databit = 1;
	else if(m_param485.m_databit == 7) m_databit = 2;
	else if(m_param485.m_databit == 8) m_databit = 3;
	else									  m_databit = 3;

	if(m_param485.m_stopbit == 1) m_stopbit = 0;
	else							     m_stopbit = 1;

	GetDlgItem(IDC_EDIT_PTZNAME)->SetWindowText(m_lpptzcmdname);
	UpdateData(FALSE);
}

BOOL CDlgChPtz::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	m_param485.decoderAddress = m_addr;
	if(m_bitrate == 0) m_param485.m_baudrate = 300;
	else if(m_bitrate == 1) m_param485.m_baudrate = 600;
	else if(m_bitrate == 2) m_param485.m_baudrate = 1200;
	else if(m_bitrate == 3) m_param485.m_baudrate = 2400;
	else if(m_bitrate == 4) m_param485.m_baudrate = 4800;
	else if(m_bitrate == 5) m_param485.m_baudrate = 9600;
	else if(m_bitrate == 6) m_param485.m_baudrate = 19200;
	else if(m_bitrate == 7) m_param485.m_baudrate = 38400;
	else if(m_bitrate == 8) m_param485.m_baudrate = 57600;
	else if(m_bitrate == 9) m_param485.m_baudrate = 115200;
	m_param485.m_checkbit = m_checkbit;
	if(m_databit == 0) m_param485.m_databit = 5;
	else if(m_databit == 1) m_param485.m_databit = 6;
	else if(m_databit == 2) m_param485.m_databit = 7;
	else if(m_databit == 3) m_param485.m_databit = 8;

	if(m_stopbit == 0) m_param485.m_stopbit = 1;
	else			   m_param485.m_stopbit = 2;

	return TRUE;
}

void CDlgChPtz::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETSERIAL,m_ch,&m_param485,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChPtz::OnBtnCopy1() 
{
	if(!UpdateParam()) return;

	int i,tmpch;
	CString strmsg;
	int sel = ((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY1))->GetCurSel();
	if(sel == -1) return;
	if(sel == (m_ch + 1)) return;
	tmpch = m_ch;
	if(sel == 0) //all channels
	{
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			m_ch = i;
			OnBtnSet();
		}
	}
	else
	{
		m_ch = sel - 1;
		OnBtnSet();
	}
	m_ch = tmpch;
	strmsg.LoadString(IDS_STRING257);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChPtz::OnBtnFile() 
{
	CFileDialog dlgFile(
		TRUE, 
		_T("open PTZ Cmmmand File"),
		"",
		OFN_HIDEREADONLY,
		"ptz Files(*.ptz)|*.ptz||",
		NULL);
	char lpszTitle[]={""};
	dlgFile.m_ofn.lpstrTitle = lpszTitle;
	
	if (dlgFile.DoModal() != IDOK)
	{
		return;
	}
	CString lpfile = dlgFile.GetPathName();
	GetDlgItem(IDC_EDIT_PTZFILE)->SetWindowText(lpfile);
	GetDlgItem(IDC_BTN_PTZFILESET)->EnableWindow(TRUE);
}

void CDlgChPtz::OnBtnPtzfileset() 
{
	int iRet1;
	CString lpfile;
	CString strmsg;
	char lppztfile[MAX_PATH];
	GetDlgItem(IDC_EDIT_PTZFILE)->GetWindowText(lpfile);
	if(lpfile.IsEmpty())
	{
		strmsg.LoadString(IDS_STRING260);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		GetDlgItem(IDC_BTN_FILE)->SetFocus();
		return;
	}
	sprintf(lppztfile,"%s",lpfile);
	strmsg.LoadString(IDS_STRING261);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	iRet1 = VSNET_ClientMessageOpt(g_SerParam->m_hParam,MESSAGE_CMD_PTZCMDFILE,m_ch,lppztfile,NULL,NULL);
	if(iRet1 == 0)
	{
		VSNET_ClientMessageOpt(g_SerParam->m_hParam,MESSAGE_CMD_PTZCMDNAME,m_ch,m_lpptzcmdname,NULL,NULL);
		GetDlgItem(IDC_EDIT_PTZNAME)->SetWindowText(m_lpptzcmdname);
		strmsg.LoadString(IDS_STRING262);
	}
	else
	{
		strmsg.LoadString(IDS_STRING263);
	}
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChPtz::OnBtnCopy2()
{
	int i,tmpch;
	CString strmsg;
	int sel = ((CComboBox*)GetDlgItem(IDC_COMBO_CHCOPY2))->GetCurSel();
	if(sel == -1) return;
	if(sel == (m_ch + 1)) return;
	GetDlgItem(IDC_EDIT_PTZFILE)->GetWindowText(strmsg);
	if(strmsg.IsEmpty())
	{
		strmsg.LoadString(IDS_STRING260);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
		GetDlgItem(IDC_BTN_FILE)->SetFocus();
		return;
	}
	tmpch = m_ch;
	if(sel == 0) //all channels
	{
		for(i=0;i<g_SerParam->m_chs;i++)
		{
			m_ch = i;
			OnBtnPtzfileset();
		}
	}
	else
	{
		m_ch = sel - 1;
		OnBtnPtzfileset();
	}
	m_ch = tmpch;
	strmsg.LoadString(IDS_STRING257);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}
