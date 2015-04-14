#if !defined(AFX_DLGSERUPDATE_H__5775472B_147D_4499_8DBF_FA74B99713D5__INCLUDED_)
#define AFX_DLGSERUPDATE_H__5775472B_147D_4499_8DBF_FA74B99713D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSerUpdate.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSerUpdate dialog

class CDlgSerUpdate : public CDialog
{
// Construction
public:
	LONG   m_updatesock;
	HANDLE m_hEndEvent;
	CDlgSerUpdate(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSerUpdate)
	enum { IDD = IDD_DLG_SERUPDATE };
	CProgressCtrl	m_progress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSerUpdate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bCanExit;
	UINT m_timerid;
	// Generated message map functions
	//{{AFX_MSG(CDlgSerUpdate)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERUPDATE_H__5775472B_147D_4499_8DBF_FA74B99713D5__INCLUDED_)
