#if !defined(AFX_DLGCHAUDIOPARAM_H__F9F642FE_282C_4C74_9BC7_4F2C174DAD24__INCLUDED_)
#define AFX_DLGCHAUDIOPARAM_H__F9F642FE_282C_4C74_9BC7_4F2C174DAD24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCHAudioParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCHAudioParam dialog

class CDlgCHAudioParam : public CDialog
{
// Construction
public:
	CDlgCHAudioParam(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCHAudioParam)
	enum { IDD = IDD_DLG_AUDIOPARAM };
	int		m_linein;
	int		m_audioout;
	int		m_micboost;
	int		m_audiotype;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCHAudioParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	VSNETAUDIOPARAM   m_audioparam;

	// Generated message map functions
	//{{AFX_MSG(CDlgCHAudioParam)
	afx_msg void OnBtnCopy1();
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL UpdateParam();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHAUDIOPARAM_H__F9F642FE_282C_4C74_9BC7_4F2C174DAD24__INCLUDED_)
