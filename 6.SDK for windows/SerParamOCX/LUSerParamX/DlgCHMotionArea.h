#if !defined(AFX_DLGCHMOTIONAREA_H__F1BAAC94_A4B5_4C1C_9ACD_532F6832AC3E__INCLUDED_)
#define AFX_DLGCHMOTIONAREA_H__F1BAAC94_A4B5_4C1C_9ACD_532F6832AC3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCHMotionArea.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCHMotionArea dialog
#include "MotionArea.h"
class CDlgCHMotionArea : public CDialog
{
// Construction
public:
	CDlgCHMotionArea(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCHMotionArea)
	enum { IDD = IDD_DLG_CHMOTIONAREA };
	CSliderCtrl	m_MotionVal;
	CMotionArea	m_videownd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCHMotionArea)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	LONG m_hchann;
	UINT m_timerid;
	int m_type;
	CHANNMOTION			m_channmotion;
	CHANNMOTIONEX		m_channmotionex;
	// Generated message map functions
	//{{AFX_MSG(CDlgCHMotionArea)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnAll();
	afx_msg void OnBtnClean();
	afx_msg void OnBtnCopy1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
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

#endif // !defined(AFX_DLGCHMOTIONAREA_H__F1BAAC94_A4B5_4C1C_9ACD_532F6832AC3E__INCLUDED_)
