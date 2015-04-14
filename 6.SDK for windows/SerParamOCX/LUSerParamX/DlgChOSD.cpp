// DlgChOSD.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgChOSD.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChOSD dialog


CDlgChOSD::CDlgChOSD(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChOSD::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChOSD)
	m_timeosd = -1;
	m_titalosd1 = _T("");
	m_titalosd2 = _T("");
	m_titalosd3 = _T("");
	m_titalosd4 = _T("");
	m_bitsosd = FALSE;
	m_bitosd_x = 0;
	m_bitosd_y = 0;
	m_timeosd_x = 0;
	m_timeosd_y = 0;
	m_titalosd1_x = 0;
	m_titalosd1_y = 0;
	m_titalosd2_x = 0;
	m_titalosd2_y = 0;
	m_titalosd3_x = 0;
	m_titalosd3_y = 0;
	m_titalosd4_x = 0;
	m_titalosd4_y = 0;
	//}}AFX_DATA_INIT
}


void CDlgChOSD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChOSD)
	DDX_CBIndex(pDX, IDC_TIMEOSD, m_timeosd);
	DDX_Text(pDX, IDC_TITALOSD1, m_titalosd1);
	DDV_MaxChars(pDX, m_titalosd1, 24);
	DDX_Text(pDX, IDC_TITALOSD2, m_titalosd2);
	DDV_MaxChars(pDX, m_titalosd2, 24);
	DDX_Text(pDX, IDC_TITALOSD3, m_titalosd3);
	DDV_MaxChars(pDX, m_titalosd3, 24);
	DDX_Text(pDX, IDC_TITALOSD4, m_titalosd4);
	DDV_MaxChars(pDX, m_titalosd4, 24);
	DDX_Check(pDX, IDC_CHECK_BITSOSD, m_bitsosd);
	DDX_Text(pDX, IDC_BITOSD_X, m_bitosd_x);
	DDV_MinMaxInt(pDX, m_bitosd_x, 0, 704);
	DDX_Text(pDX, IDC_BITOSD_Y, m_bitosd_y);
	DDV_MinMaxInt(pDX, m_bitosd_y, 0, 704);
	DDX_Text(pDX, IDC_TIMEOSD_X, m_timeosd_x);
	DDV_MinMaxInt(pDX, m_timeosd_x, 0, 704);
	DDX_Text(pDX, IDC_TIMEOSD_Y, m_timeosd_y);
	DDV_MinMaxInt(pDX, m_timeosd_y, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD1_X, m_titalosd1_x);
	DDV_MinMaxInt(pDX, m_titalosd1_x, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD1_Y, m_titalosd1_y);
	DDV_MinMaxInt(pDX, m_titalosd1_y, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD2_X, m_titalosd2_x);
	DDV_MinMaxInt(pDX, m_titalosd2_x, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD2_Y, m_titalosd2_y);
	DDV_MinMaxInt(pDX, m_titalosd2_y, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD3_X, m_titalosd3_x);
	DDV_MinMaxInt(pDX, m_titalosd3_x, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD3_Y, m_titalosd3_y);
	DDV_MinMaxInt(pDX, m_titalosd3_y, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD4_X, m_titalosd4_x);
	DDV_MinMaxInt(pDX, m_titalosd4_x, 0, 704);
	DDX_Text(pDX, IDC_TITALOSD4_Y, m_titalosd4_y);
	DDV_MinMaxInt(pDX, m_titalosd4_y, 0, 704);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChOSD, CDialog)
	//{{AFX_MSG_MAP(CDlgChOSD)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChOSD message handlers
LRESULT CDlgChOSD::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgChOSD::OnDlgFirst(WPARAM wParam,LPARAM lParam)
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

void CDlgChOSD::OnBtnGet() 
{
	CString strmsg;
	int iRet1;
	memset(&m_channosd,0,sizeof(CHANNOSD));
	
	iRet1 = g_SerParam->ReadParam(MESSAGE_CMD_GETCHANNELOSD,m_ch,&m_channosd,NULL,NULL);
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

	m_timeosd    = m_channosd.m_time.nFormat;
	m_titalosd1   = m_channosd.m_tital[0].lpString;
	m_titalosd2   = m_channosd.m_tital[1].lpString;
	m_titalosd3   = m_channosd.m_tital[2].lpString;
	m_titalosd4   = m_channosd.m_tital[3].lpString;
	m_bitsosd  = m_channosd.m_bits.bShow;
	m_bitosd_x = m_channosd.m_bits.x;
	m_bitosd_y = m_channosd.m_bits.y;
	m_timeosd_x = m_channosd.m_time.x;
	m_timeosd_y = m_channosd.m_time.y;
	m_titalosd1_x = m_channosd.m_tital[0].x;
	m_titalosd1_y = m_channosd.m_tital[0].y;
	m_titalosd2_x = m_channosd.m_tital[1].x;
	m_titalosd2_y = m_channosd.m_tital[1].y;
	m_titalosd3_x = m_channosd.m_tital[2].x;
	m_titalosd3_y = m_channosd.m_tital[2].y;
	m_titalosd4_x = m_channosd.m_tital[3].x;
	m_titalosd4_y = m_channosd.m_tital[3].y;
	UpdateData(FALSE);
}

void CDlgChOSD::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_CMD_SETCHANNELOSD,m_ch,&m_channosd,NULL,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);

}

BOOL CDlgChOSD::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	m_channosd.m_time.nFormat = m_timeosd;
	m_channosd.m_bits.bShow  = m_bitsosd;
	sprintf(m_channosd.m_tital[0].lpString,"%s",m_titalosd1);
	sprintf(m_channosd.m_tital[1].lpString,"%s",m_titalosd2);
	sprintf(m_channosd.m_tital[2].lpString,"%s",m_titalosd3);
	sprintf(m_channosd.m_tital[3].lpString,"%s",m_titalosd4);
	m_channosd.m_bits.x = m_bitosd_x;
	m_channosd.m_bits.y = m_bitosd_y;
	m_channosd.m_time.x = m_timeosd_x;
	m_channosd.m_time.y = m_timeosd_y;
	m_channosd.m_tital[0].x = m_titalosd1_x;
	m_channosd.m_tital[0].y = m_titalosd1_y;
	m_channosd.m_tital[1].x = m_titalosd2_x;
	m_channosd.m_tital[1].y = m_titalosd2_y;
	m_channosd.m_tital[2].x = m_titalosd3_x;
	m_channosd.m_tital[2].y = m_titalosd3_y;
	m_channosd.m_tital[3].x = m_titalosd4_x;
	m_channosd.m_tital[3].y = m_titalosd4_y;

	return TRUE;
}

void CDlgChOSD::OnBtnCopy1() 
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
