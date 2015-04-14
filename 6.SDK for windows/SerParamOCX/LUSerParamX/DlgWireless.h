#if !defined(AFX_DLGWIRELESS_H__3908F2BD_D854_4C64_B73E_8676B095C9AD__INCLUDED_)
#define AFX_DLGWIRELESS_H__3908F2BD_D854_4C64_B73E_8676B095C9AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgWireless.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgWireless dialog

class CDlgWireless : public CDialog
{
// Construction
public:
	CDlgWireless(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgWireless)
	enum { IDD = IDD_DLG_WIRELESS };
	BOOL	m_usecdma;
	BOOL	m_usewifi;
	int		m_weptype;
	CString	m_wiredns;
	CString	m_wiregateway;
	CString	m_wireip;
	CString	m_password;
	CString	m_ssid;
	CString	m_wiresubmask;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgWireless)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	VSNETCDMAPARAM m_cdmaparam;
	VSNETWIFIPARAM m_wifiparam;
	// Generated message map functions
	//{{AFX_MSG(CDlgWireless)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWIRELESS_H__3908F2BD_D854_4C64_B73E_8676B095C9AD__INCLUDED_)
