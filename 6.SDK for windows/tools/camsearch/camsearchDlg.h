// camsearchDlg.h : header file
//

#if !defined(AFX_CAMSEARCHDLG_H__D360C8BF_A797_4746_9CE9_F25017EE1E10__INCLUDED_)
#define AFX_CAMSEARCHDLG_H__D360C8BF_A797_4746_9CE9_F25017EE1E10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCamsearchDlg dialog

class CCamsearchDlg : public CDialog
{
// Construction
public:
	void CleanAllList();
	CCamsearchDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCamsearchDlg)
	enum { IDD = IDD_CAMSEARCH_DIALOG };
	CListCtrl	m_ListCam;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamsearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCamsearchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSearch();
	afx_msg void OnDestroy();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnModify();
	afx_msg void OnBtnReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMSEARCHDLG_H__D360C8BF_A797_4746_9CE9_F25017EE1E10__INCLUDED_)
