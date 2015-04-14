#if !defined(AFX_DLGCHPTZ_H__68E78EDC_F8C7_439D_ABBD_BBDC9D0C5CBD__INCLUDED_)
#define AFX_DLGCHPTZ_H__68E78EDC_F8C7_439D_ABBD_BBDC9D0C5CBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChPtz.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChPtz dialog

class CDlgChPtz : public CDialog
{
// Construction
public:
	CDlgChPtz(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChPtz)
	enum { IDD = IDD_DLG_CHPTZ };
	int		m_addr;
	int		m_bitrate;
	int		m_checkbit;
	int		m_databit;
	int		m_stopbit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChPtz)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	char m_lpptzcmdname[40];
	SERIAL485_PARAM m_param485;
	// Generated message map functions
	//{{AFX_MSG(CDlgChPtz)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnCopy1();
	afx_msg void OnBtnFile();
	afx_msg void OnBtnPtzfileset();
	afx_msg void OnBtnCopy2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL UpdateParam();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHPTZ_H__68E78EDC_F8C7_439D_ABBD_BBDC9D0C5CBD__INCLUDED_)
