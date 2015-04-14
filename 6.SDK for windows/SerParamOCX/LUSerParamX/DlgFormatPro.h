#if !defined(AFX_DLGFORMATPRO_H__C8E690C9_DD87_4566_8AAE_1955473F4200__INCLUDED_)
#define AFX_DLGFORMATPRO_H__C8E690C9_DD87_4566_8AAE_1955473F4200__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFormatPro.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFormatPro dialog

class CDlgFormatPro : public CDialog
{
// Construction
public:
	LONG m_hParam;
	int  m_disksel;
	int  m_errno;
	CDlgFormatPro(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgFormatPro)
	enum { IDD = IDD_DLG_FORMATDISK };
	CProgressCtrl	m_formatpro;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFormatPro)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HANDLE m_hThread;
	int m_propos;
	BOOL m_canexit;
	UINT m_timerid;
	// Generated message map functions
	//{{AFX_MSG(CDlgFormatPro)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnFormtReturn(WPARAM wParam,LPARAM lParam);
	static UINT CALLBACK formatdiskthread(CDlgFormatPro *pDlgFormat);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFORMATPRO_H__C8E690C9_DD87_4566_8AAE_1955473F4200__INCLUDED_)
