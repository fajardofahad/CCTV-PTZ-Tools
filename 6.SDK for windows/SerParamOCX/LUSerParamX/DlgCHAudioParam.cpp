// DlgCHAudioParam.cpp : implementation file
//

#include "stdafx.h"
#include "luserparamx.h"
#include "DlgCHAudioParam.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCHAudioParam dialog


CDlgCHAudioParam::CDlgCHAudioParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCHAudioParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCHAudioParam)
	m_linein = 0;
	m_audioout = 0;
	m_micboost = 0;
	m_audiotype = 0;
	//}}AFX_DATA_INIT
}


void CDlgCHAudioParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCHAudioParam)
	DDX_Text(pDX, IDC_EDIT_LINEIN, m_linein);
	DDV_MinMaxInt(pDX, m_linein, 0, 100);
	DDX_Text(pDX, IDC_EDIT_AUDIOOUT, m_audioout);
	DDV_MinMaxInt(pDX, m_audioout, 0, 100);
	DDX_CBIndex(pDX, IDC_COMBO_MIC, m_micboost);
	DDX_CBIndex(pDX, IDC_COMBO_TYPE, m_audiotype);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCHAudioParam, CDialog)
	//{{AFX_MSG_MAP(CDlgCHAudioParam)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCHAudioParam message handlers
LRESULT CDlgCHAudioParam::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgCHAudioParam::OnDlgFirst(WPARAM wParam,LPARAM lParam)
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

void CDlgCHAudioParam::OnBtnCopy1() 
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

void CDlgCHAudioParam::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	memset(&m_audioparam,0,sizeof(VSNETAUDIOPARAM));
	
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETAUDIOPARAM,m_ch,&m_audioparam,NULL,NULL);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);
	if(!iRet1)
	{
		strmsg.LoadString(IDS_STRING279);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	}
	else
	{
		strmsg.LoadString(IDS_STRING233);
		g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
	}
	GetDlgItem(IDC_COMBO_TYPE)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_LINEIN)->EnableWindow(iRet1);
	GetDlgItem(IDC_COMBO_MIC)->EnableWindow(iRet1);
	GetDlgItem(IDC_EDIT_AUDIOOUT)->EnableWindow(iRet1);
	GetDlgItem(IDC_COMBO_CHCOPY1)->EnableWindow(iRet1);
	GetDlgItem(IDC_BTN_COPY1)->EnableWindow(iRet1);
	GetDlgItem(IDC_BTN_GET)->EnableWindow(iRet1);
	GetDlgItem(IDC_BTN_SET)->EnableWindow(iRet1);

	m_linein = m_audioparam.m_audioinDBline;
	m_audioout = m_audioparam.m_audiooutDB;
	m_micboost = m_audioparam.m_audioinDBMic;
	m_audiotype = m_audioparam.m_audioinline;

	UpdateData(FALSE);	
}

void CDlgCHAudioParam::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETAUDIOPARAM,m_ch,&m_audioparam,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);	
}

BOOL CDlgCHAudioParam::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	m_audioparam.m_audioinDBline = m_linein; 
	m_audioparam.m_audiooutDB = m_audioout; 
	m_audioparam.m_audioinDBMic= m_micboost; 
	m_audioparam.m_audioinline = m_audiotype; 
	return TRUE;
}
