// DlgChRecvTime.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgChRecvTime.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChRecvTime dialog


CDlgChRecvTime::CDlgChRecvTime(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChRecvTime::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChRecvTime)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgChRecvTime::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChRecvTime)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChRecvTime, CDialog)
	//{{AFX_MSG_MAP(CDlgChRecvTime)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_COPY1, OnBtnCopy1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPRAM_INITMSG, OnDlgFirst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChRecvTime message handlers
LRESULT CDlgChRecvTime::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	m_ch = lParam;
	OnBtnGet();
	return 0;
}

LRESULT CDlgChRecvTime::OnDlgFirst(WPARAM wParam,LPARAM lParam)
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

void CDlgChRecvTime::OnBtnGet() 
{
	int i;
	CString strmsg;
	int iRet1;
	char lpnum[3];
	memset(&m_chanpara,0,sizeof(CHANNELPARAM));
	memset(&m_chanparaex,0,sizeof(CHANNELPARAMEX));
	for(i=0;i<7;i++)
	{
		m_chanparaex.m_record.pList[i].m_maskweek = 10;
	}
	
	iRet1 = g_SerParam->ReadParam(MESSAGE_GETCHANNELPARAM,m_ch,&m_chanpara,&m_chanparaex,&m_type);
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
	if(!m_type)
	{
		memset(&m_chanparaex,0,sizeof(CHANNELPARAMEX));
		strcpy(m_chanparaex.m_channelName,m_chanpara.m_channelName);
		m_chanparaex.m_streamType = m_chanpara.m_streamType;
		m_chanparaex.m_encodeType = m_chanpara.m_encodeType;
		m_chanparaex.m_Iinterval = m_chanpara.m_Iinterval;
		m_chanparaex.m_videoFrameRate = m_chanpara.m_videoFrameRate;
		m_chanparaex.m_bitratetype = m_chanpara.m_bitratetype;
		m_chanparaex.m_maxqueue = m_chanpara.m_maxqueue;
		m_chanparaex.m_minqueue = m_chanpara.m_minqueue;
		m_chanparaex.m_maxbitrates = m_chanpara.m_maxbitrates;
		m_chanparaex.m_audiosample = m_chanpara.m_audiosample;
		m_chanparaex.m_audiobitrate = m_chanpara.m_audiobitrate;
		m_chanparaex.m_delay = m_chanpara.m_delay;
		m_chanparaex.m_benrecord = m_chanpara.m_benrecord;
		memcpy(&m_chanparaex.m_record,&m_chanpara.m_record,sizeof(TIMELIST));
	}
	
	for(i=0;i<7;i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->SetCurSel(m_chanparaex.m_record.pList[i].m_maskweek);

		sprintf(lpnum,"%02d",m_chanparaex.m_record.pList[i].m_starthour);
		GetDlgItem(IDC_STARTHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_chanparaex.m_record.pList[i].m_startmin);
		GetDlgItem(IDC_STARTMINUTE1 + i)->SetWindowText(lpnum);

		sprintf(lpnum,"%02d",m_chanparaex.m_record.pList[i].m_stophour);
		GetDlgItem(IDC_STOPHOUR1 + i)->SetWindowText(lpnum);
		sprintf(lpnum,"%02d",m_chanparaex.m_record.pList[i].m_stopmin);
		GetDlgItem(IDC_STOPMINUTE1 + i)->SetWindowText(lpnum);
	}
	((CButton*)GetDlgItem(IDC_CHECK_AUTOTREC))->SetCheck(m_chanparaex.m_benrecord);
	UpdateData(FALSE);
}

void CDlgChRecvTime::OnBtnSet() 
{
	if(!UpdateParam()) return;

	CString strmsg;
	g_SerParam->SaveParam(MESSAGE_SETCHANNELPARAM,m_ch,&m_chanpara,&m_chanparaex,NULL);
	strmsg.LoadString(IDS_STRING232);
	g_SerParam->m_txtMsginfo.SetWindowText(strmsg);
}

void CDlgChRecvTime::OnBtnCopy1() 
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

BOOL CDlgChRecvTime::UpdateParam()
{
	if(!UpdateData()) return FALSE;

	int i;
	char lpnum[3];
	for(i=0;i<7;i++)
	{
		m_chanparaex.m_record.pList[i].m_maskweek = ((CComboBox*)GetDlgItem(IDC_COMBO_TIME1 + i))->GetCurSel();
		GetDlgItem(IDC_STARTHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanparaex.m_record.pList[i].m_starthour = atoi(lpnum);
		
		GetDlgItem(IDC_STARTMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanparaex.m_record.pList[i].m_startmin = atoi(lpnum);
		
		GetDlgItem(IDC_STOPHOUR1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanparaex.m_record.pList[i].m_stophour = atoi(lpnum);
		
		GetDlgItem(IDC_STOPMINUTE1 + i)->GetWindowText(lpnum,sizeof(lpnum));
		m_chanparaex.m_record.pList[i].m_stopmin = atoi(lpnum);
	}
	m_chanparaex.m_benrecord = ((CButton*)GetDlgItem(IDC_CHECK_AUTOTREC))->GetCheck();

	strcpy(m_chanpara.m_channelName,m_chanparaex.m_channelName);
	m_chanpara.m_streamType = m_chanparaex.m_streamType;
	m_chanpara.m_encodeType = m_chanparaex.m_encodeType;
	m_chanpara.m_Iinterval = m_chanparaex.m_Iinterval;
	m_chanpara.m_videoFrameRate = m_chanparaex.m_videoFrameRate;
	m_chanpara.m_bitratetype = m_chanparaex.m_bitratetype;
	m_chanpara.m_maxqueue = m_chanparaex.m_maxqueue;
	m_chanpara.m_minqueue = m_chanparaex.m_minqueue;
	m_chanpara.m_maxbitrates = m_chanparaex.m_maxbitrates;
	m_chanpara.m_audiosample = m_chanparaex.m_audiosample;
	m_chanpara.m_audiobitrate = m_chanparaex.m_audiobitrate;
	m_chanpara.m_delay = m_chanparaex.m_delay;
	m_chanpara.m_benrecord = m_chanparaex.m_benrecord;
	memcpy(&m_chanpara.m_record,&m_chanparaex.m_record,sizeof(TIMELIST));

	return TRUE;
}
