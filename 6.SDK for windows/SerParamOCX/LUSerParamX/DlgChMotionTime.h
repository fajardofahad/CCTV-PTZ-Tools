#if !defined(AFX_DLGCHMOTIONTIME_H__5C34B886_882A_46E9_B8F5_3431200A6D4E__INCLUDED_)
#define AFX_DLGCHMOTIONTIME_H__5C34B886_882A_46E9_B8F5_3431200A6D4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChMotionTime.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChMotionTime dialog

class CDlgChMotionTime : public CDialog
{
// Construction
public:
	CDlgChMotionTime(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChMotionTime)
	enum { IDD = IDD_DLG_CHMOTIONTIME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChMotionTime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	int m_type;
	CHANNMOTION			m_channmotion;
	CHANNMOTIONEX		m_channmotionex;
	// Generated message map functions
	//{{AFX_MSG(CDlgChMotionTime)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnCopy1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
	BOOL UpdateParam();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHMOTIONTIME_H__5C34B886_882A_46E9_B8F5_3431200A6D4E__INCLUDED_)
