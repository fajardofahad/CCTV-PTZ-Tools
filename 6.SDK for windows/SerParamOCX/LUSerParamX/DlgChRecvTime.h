#if !defined(AFX_DLGCHRECVTIME_H__DEC1EA77_B399_4507_8B51_2124251168A6__INCLUDED_)
#define AFX_DLGCHRECVTIME_H__DEC1EA77_B399_4507_8B51_2124251168A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChRecvTime.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChRecvTime dialog

class CDlgChRecvTime : public CDialog
{
// Construction
public:
	CDlgChRecvTime(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChRecvTime)
	enum { IDD = IDD_DLG_CHRECVTIME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChRecvTime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	int m_type;
	CHANNELPARAM   m_chanpara;
	CHANNELPARAMEX m_chanparaex;
	// Generated message map functions
	//{{AFX_MSG(CDlgChRecvTime)
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

#endif // !defined(AFX_DLGCHRECVTIME_H__DEC1EA77_B399_4507_8B51_2124251168A6__INCLUDED_)
