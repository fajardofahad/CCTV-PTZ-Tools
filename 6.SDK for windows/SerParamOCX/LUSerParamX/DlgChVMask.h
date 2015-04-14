#if !defined(AFX_DLGCHVMASK_H__85D7C48A_87E0_4D03_8321_F02B97BF1AC8__INCLUDED_)
#define AFX_DLGCHVMASK_H__85D7C48A_87E0_4D03_8321_F02B97BF1AC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChVMask.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChVMask dialog
#include "MotionArea.h"
class CDlgChVMask : public CDialog
{
// Construction
public:
	CDlgChVMask(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChVMask)
	enum { IDD = IDD_DLG_CHVMASK };
	CMotionArea	m_videownd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChVMask)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	LONG m_hchann;
	UINT m_timerid;
	VSNETVIDEOMASKAREA m_vmask[4];
	CHANNVIDEOMASK m_channvmask;
	VSNETVIDEOMASK m_maskarea;
	// Generated message map functions
	//{{AFX_MSG(CDlgChVMask)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnCopy1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnRadioArea1();
	afx_msg void OnRadioArea2();
	afx_msg void OnRadioArea3();
	afx_msg void OnRadioArea4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL UpdateParam();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFree(WPARAM wParam,LPARAM lParam);
	BOOL ConnectVideo();
	LRESULT OnDlgVideoMsg(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHVMASK_H__85D7C48A_87E0_4D03_8321_F02B97BF1AC8__INCLUDED_)
