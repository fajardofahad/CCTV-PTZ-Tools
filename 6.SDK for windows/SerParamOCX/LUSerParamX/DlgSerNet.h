#if !defined(AFX_DLGSERNET_H__55AA83F1_7CFB_4DC3_9547_49DC47CB9A6A__INCLUDED_)
#define AFX_DLGSERNET_H__55AA83F1_7CFB_4DC3_9547_49DC47CB9A6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSerNet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSerNet dialog

class CDlgSerNet : public CDialog
{
// Construction
public:
	CDlgSerNet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSerNet)
	enum { IDD = IDD_DLG_SERNET };
	int		m_bpppoe;
	int		m_buseddns;
	int		m_alarmhostport;
	CString	m_alarmhosturl;
	CString	m_strddnsurl;
	int		m_ddnsmaport;
	int		m_ddnsport;
	CString	m_strdns;
	CString	m_strgateway;
	CString	m_strip;
	CString	m_strmac;
	CString	m_strmultiip;
	int		m_multiport;
	CString	m_strpppowpsw;
	CString	m_strpppoeuid;
	int		m_hostport;
	CString	m_hosturl;
	int		m_serport;
	CString	m_strsubmask;
	int		m_webport;
	int		m_ddnsprovider;
	CString	m_ddnspass;
	CString	m_ddnsusername;
	int		m_ddnstime;
	CString	m_ddnsname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSerNet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	WHOLEPARAM   m_wholeparam;
	VSREMOTEHOST m_remotehost;
	VSNETPPPOEPARAM m_pppoeparam;
	VSNETDNSEXPARAM m_ddnsexparam;
	// Generated message map functions
	//{{AFX_MSG(CDlgSerNet)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERNET_H__55AA83F1_7CFB_4DC3_9547_49DC47CB9A6A__INCLUDED_)
