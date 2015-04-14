#if !defined(AFX_DLGSERSAVE_H__202217EC_B3BE_4D58_B29A_BDF5F1A04993__INCLUDED_)
#define AFX_DLGSERSAVE_H__202217EC_B3BE_4D58_B29A_BDF5F1A04993__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSerSave.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSerSave dialog

class CDlgSerSave : public CDialog
{
// Construction
public:
	CDlgSerSave(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSerSave)
	enum { IDD = IDD_DLG_SERSAVE };
	CTime	m_syncdate;
	CTime	m_synctime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSerSave)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UINT m_timerid;
	// Generated message map functions
	//{{AFX_MSG(CDlgSerSave)
	afx_msg void OnBtnSynctime1();
	afx_msg void OnBtnSynctime2();
	afx_msg void OnBtnSelfile();
	afx_msg void OnBtnUpdate();
	afx_msg void OnBtnSave();
	afx_msg void OnBtnReset();
	afx_msg void OnBtnDefault();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFree(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERSAVE_H__202217EC_B3BE_4D58_B29A_BDF5F1A04993__INCLUDED_)
