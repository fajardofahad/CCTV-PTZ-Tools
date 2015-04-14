// testDlg.h : header file
//
//{{AFX_INCLUDES()
#include "luserparamx.h"
//}}AFX_INCLUDES

#if !defined(AFX_TESTDLG_H__2851AEED_AC13_414D_B6B6_82EE08C7251F__INCLUDED_)
#define AFX_TESTDLG_H__2851AEED_AC13_414D_B6B6_82EE08C7251F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CLUSerParamX	m_serparam;
	CString	m_devname;
	int		m_devport;
	CString	m_devurl;
	CString	m_devuid;
	CString	m_devpsw;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__2851AEED_AC13_414D_B6B6_82EE08C7251F__INCLUDED_)
