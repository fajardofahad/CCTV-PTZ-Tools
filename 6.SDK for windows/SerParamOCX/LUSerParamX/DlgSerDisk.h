#if !defined(AFX_DLGSERDISK_H__7D7ECA5D_91E9_4BEC_B16D_F0817AFDC69A__INCLUDED_)
#define AFX_DLGSERDISK_H__7D7ECA5D_91E9_4BEC_B16D_F0817AFDC69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSerDisk.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSerDisk dialog

class CDlgSerDisk : public CDialog
{
// Construction
public:
	CDlgSerDisk(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSerDisk)
	enum { IDD = IDD_DLG_SERDISK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSerDisk)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	VSDISKSTATE m_diskstate;
	// Generated message map functions
	//{{AFX_MSG(CDlgSerDisk)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnFormat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
	void ConvertDiskSize(int size, CString &strret);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERDISK_H__7D7ECA5D_91E9_4BEC_B16D_F0817AFDC69A__INCLUDED_)
