#if !defined(AFX_DLGSERUSER_H__EBFB63E0_CB6E_4E88_AA29_3921D5A77F3B__INCLUDED_)
#define AFX_DLGSERUSER_H__EBFB63E0_CB6E_4E88_AA29_3921D5A77F3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSerUser.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSerUser dialog

class CDlgSerUser : public CDialog
{
// Construction
public:
	CDlgSerUser(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSerUser)
	enum { IDD = IDD_DLG_SERUSER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSerUser)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	WHOLE_USER   m_wholeusr;
	// Generated message map functions
	//{{AFX_MSG(CDlgSerUser)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERUSER_H__EBFB63E0_CB6E_4E88_AA29_3921D5A77F3B__INCLUDED_)
