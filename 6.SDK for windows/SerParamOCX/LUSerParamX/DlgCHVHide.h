#if !defined(AFX_DLGCHVHIDE_H__C3D1AFF1_CEF5_44CD_9FB6_F71FFB2652F4__INCLUDED_)
#define AFX_DLGCHVHIDE_H__C3D1AFF1_CEF5_44CD_9FB6_F71FFB2652F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCHVHide.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCHVHide dialog

class CDlgCHVHide : public CDialog
{
// Construction
public:
	CDlgCHVHide(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCHVHide)
	enum { IDD = IDD_DLG_CHVHIDE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCHVHide)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	int m_type;
	CHANNELHIDEALARM	m_chanhide;
	CHANNELHIDEALARMEX	m_chanhideex;
	// Generated message map functions
	//{{AFX_MSG(CDlgCHVHide)
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

#endif // !defined(AFX_DLGCHVHIDE_H__C3D1AFF1_CEF5_44CD_9FB6_F71FFB2652F4__INCLUDED_)
