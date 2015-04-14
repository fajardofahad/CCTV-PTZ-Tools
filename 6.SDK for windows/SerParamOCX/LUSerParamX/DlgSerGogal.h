#if !defined(AFX_DLGSERGOGAL_H__A7A366D9_CC71_4237_9559_E5A85198A7E8__INCLUDED_)
#define AFX_DLGSERGOGAL_H__A7A366D9_CC71_4237_9559_E5A85198A7E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSerGogal.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSerGogal dialog

class CDlgSerGogal : public CDialog
{
// Construction
public:
	CDlgSerGogal(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSerGogal)
	enum { IDD = IDD_DLG_SERGOBAL };
	CString	m_sername;
	CTime	m_autotime;
	CString	m_deviceID;
	CString	m_ftppass;
	CString	m_ftpuser;
	int		m_maxconnect;
	CString	m_devicemodel;
	int		m_sipport;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSerGogal)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	WHOLEPARAM   m_wholeparam;
	VSTIMERRESET m_timerreset;
	VSNETLINKCONFIG m_linkconfig;
	// Generated message map functions
	//{{AFX_MSG(CDlgSerGogal)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERGOGAL_H__A7A366D9_CC71_4237_9559_E5A85198A7E8__INCLUDED_)
