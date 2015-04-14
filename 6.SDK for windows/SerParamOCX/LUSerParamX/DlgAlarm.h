#if !defined(AFX_DLGALARM_H__F9DF63E5_C4A3_4156_BF06_0048C7043F2D__INCLUDED_)
#define AFX_DLGALARM_H__F9DF63E5_C4A3_4156_BF06_0048C7043F2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAlarm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAlarm dialog

class CDlgAlarm : public CDialog
{
// Construction
public:
	CDlgAlarm(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAlarm)
	enum { IDD = IDD_DLG_ALARM };
	int		m_alarminterval;
	CString	m_senname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAlarm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	int m_curptzno;
	int m_type;
	ALARMPARAM		m_alarmpara;
	ALARMPARAMEX	m_alarmparaex;
	VSNETSENSORALARM m_alarmname;
	// Generated message map functions
	//{{AFX_MSG(CDlgAlarm)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnCopy1();
	afx_msg void OnSelchangeComboPtzchsel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL UpdateParam();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGALARM_H__F9DF63E5_C4A3_4156_BF06_0048C7043F2D__INCLUDED_)
