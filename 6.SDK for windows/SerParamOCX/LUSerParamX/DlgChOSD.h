#if !defined(AFX_DLGCHOSD_H__553B4502_E6C2_447C_8B36_06DB63D66191__INCLUDED_)
#define AFX_DLGCHOSD_H__553B4502_E6C2_447C_8B36_06DB63D66191__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChOSD.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChOSD dialog

class CDlgChOSD : public CDialog
{
// Construction
public:
	CDlgChOSD(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChOSD)
	enum { IDD = IDD_DLG_CHOSD };
	int		m_timeosd;
	CString	m_titalosd1;
	CString	m_titalosd2;
	CString	m_titalosd3;
	CString	m_titalosd4;
	BOOL	m_bitsosd;
	int		m_bitosd_x;
	int		m_bitosd_y;
	int		m_timeosd_x;
	int		m_timeosd_y;
	int		m_titalosd1_x;
	int		m_titalosd1_y;
	int		m_titalosd2_x;
	int		m_titalosd2_y;
	int		m_titalosd3_x;
	int		m_titalosd3_y;
	int		m_titalosd4_x;
	int		m_titalosd4_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChOSD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	CHANNOSD m_channosd;
	// Generated message map functions
	//{{AFX_MSG(CDlgChOSD)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnCopy1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL UpdateParam();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHOSD_H__553B4502_E6C2_447C_8B36_06DB63D66191__INCLUDED_)
