#if !defined(AFX_DLGCHVLOST_H__5906ACC8_CAC9_4D01_8FC7_95078127ED4D__INCLUDED_)
#define AFX_DLGCHVLOST_H__5906ACC8_CAC9_4D01_8FC7_95078127ED4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCHVLost.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCHVLost dialog

class CDlgCHVLost : public CDialog
{
// Construction
public:
	CDlgCHVLost(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCHVLost)
	enum { IDD = IDD_DLG_CHVLOST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCHVLost)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	VSNETVIDEOLOSTPARAM m_vlost;
	// Generated message map functions
	//{{AFX_MSG(CDlgCHVLost)
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

#endif // !defined(AFX_DLGCHVLOST_H__5906ACC8_CAC9_4D01_8FC7_95078127ED4D__INCLUDED_)
