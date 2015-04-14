// DlgCHJpegParam.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgCHJpegParam.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCHJpegParam dialog


CDlgCHJpegParam::CDlgCHJpegParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCHJpegParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCHJpegParam)
	m_format = -1;
	m_quant = 0;
	m_rate = 0;
	m_total = 0;
	//}}AFX_DATA_INIT
}


void CDlgCHJpegParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCHJpegParam)
	DDX_CBIndex(pDX, IDC_COMBO_FORMAT, m_format);
	DDX_Text(pDX, IDC_EDIT_QUANT, m_quant);
	DDV_MinMaxInt(pDX, m_quant, 1, 100);
	DDX_Text(pDX, IDC_EDIT_RATE, m_rate);
	DDV_MinMaxInt(pDX, m_rate, 1, 5);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_total);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCHJpegParam, CDialog)
	//{{AFX_MSG_MAP(CDlgCHJpegParam)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCHJpegParam message handlers
LRESULT CDlgCHJpegParam::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgCHJpegParam::OnDlgFirst(WPARAM wParam,LPARAM lParam)
{
	GetDlgItem(IDC_COMBO_CHCOPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_BTN_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);
	GetDlgItem(IDC_STATIC_COPY1)->ShowWindow(g_SerParam->m_chs > 1 ? SW_SHOW : SW_HIDE);	
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
	}
	return 0;
}

void CDlgCHJpegParam::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	memset(&m_jpegparam,0,sizeof(VSNETJPEGCAPPARAM));
	
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETJPEGCAPPARAM,m_ch,&m_jpegparam,NULL,NULL);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);
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

	m_total  = m_jpegparam.m_capnums; 
	m_rate   = m_jpegparam.m_caprate; 
	m_quant  = m_jpegparam.m_encquant; 
	m_format = m_jpegparam.m_encformat - 1; 
	UpdateData(FALSE);
}

BOOL CDlgCHJpegParam::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	m_jpegparam.m_capnums = m_total; 
	m_jpegparam.m_caprate = m_rate; 
	m_jpegparam.m_encquant= m_quant; 
	m_jpegparam.m_encformat = m_format + 1; 
	return TRUE;
}
void CDlgCHJpegParam::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETJPEGCAPPARAM,m_ch,&m_jpegparam,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);

}

void CDlgCHJpegParam::OnBtnCopy1() 
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
