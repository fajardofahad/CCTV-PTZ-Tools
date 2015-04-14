// PlayDemoDlg.h : header file
//

#if !defined(AFX_PLAYDEMODLG_H__EDD97C18_3F57_4B27_86A9_DCCA8B796D47__INCLUDED_)
#define AFX_PLAYDEMODLG_H__EDD97C18_3F57_4B27_86A9_DCCA8B796D47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlayDemoDlg dialog

class CVideoChannel;

class CPlayDemoDlg : public CDialog
{
// Construction
public:
	CPlayDemoDlg(CWnd* pParent = NULL);	// standard constructor
	int  m_curch;
	CVideoChannel *m_video[VIEWNUM];
	UINT  m_relinktimer;
// Dialog Data
	//{{AFX_DATA(CPlayDemoDlg)
	enum { IDD = IDD_PLAYDEMO_DIALOG };
	CStatic	m_videownd1;
	CStatic	m_videownd2;
	CStatic	m_videownd3;
	CStatic	m_videownd4;
	int		m_channel;
	int		m_transtype;
	CString	m_ipaddr;
	CString	m_password;
	int		m_port;
	CString	m_username;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlayDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnConnect();
	afx_msg void OnDestroy();
	afx_msg LRESULT OnVideoWndMsg(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBtnDisconnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticVideo1();
	afx_msg void OnStnClickedStaticVideo2();
	afx_msg void OnStnClickedStaticVideo3();
	afx_msg void OnStnClickedStaticVideo4();
	afx_msg void OnTimer(UINT nIDEvent);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYDEMODLG_H__EDD97C18_3F57_4B27_86A9_DCCA8B796D47__INCLUDED_)
