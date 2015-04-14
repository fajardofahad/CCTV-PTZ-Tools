#if !defined(AFX_DLGEXALARMPARAM_H__BC51FE74_9A84_496A_B0D8_F01EFA3FF844__INCLUDED_)
#define AFX_DLGEXALARMPARAM_H__BC51FE74_9A84_496A_B0D8_F01EFA3FF844__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgExAlarmParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgExAlarmParam dialog

class CDlgExAlarmParam : public CDialog
{
// Construction
public:
	CDlgExAlarmParam(CWnd* pParent = NULL);   // standard constructor
	VSNETEXALARMPARAM m_exalarmparam;
// Dialog Data
	//{{AFX_DATA(CDlgExAlarmParam)
	enum { IDD = IDD_DLG_EXALARMPARAM };
	int		m_comport;
	int		m_protocol;
	int		m_addr;
	int		m_alarmtime;
	int		m_checktime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgExAlarmParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgExAlarmParam)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	BOOL    UpdateParam();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEXALARMPARAM_H__BC51FE74_9A84_496A_B0D8_F01EFA3FF844__INCLUDED_)
