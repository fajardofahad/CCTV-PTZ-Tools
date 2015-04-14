#if !defined(AFX_DLGCHVPARAM_H__55A45ED5_C661_4FDA_9909_600ED09C61EA__INCLUDED_)
#define AFX_DLGCHVPARAM_H__55A45ED5_C661_4FDA_9909_600ED09C61EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChVParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChVParam dialog

class CDlgChVParam : public CDialog
{
// Construction
public:
	CDlgChVParam(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChVParam)
	enum { IDD = IDD_DLG_CHVPARAM };
	int		m_bri;
	int		m_con;
	int		m_hue;
	int		m_sat;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChVParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	LONG m_hchann;
	UINT m_timerid;
	CHANNVIPARAM m_viparam;
	// Generated message map functions
	//{{AFX_MSG(CDlgChVParam)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnCopy1();
	afx_msg void OnBtnDefault();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL ConnectVideo();
	BOOL UpdateParam();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFree(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgVideoMsg(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHVPARAM_H__55A45ED5_C661_4FDA_9909_600ED09C61EA__INCLUDED_)
