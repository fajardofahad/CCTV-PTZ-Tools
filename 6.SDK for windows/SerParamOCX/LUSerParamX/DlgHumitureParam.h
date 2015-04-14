#if !defined(AFX_DLGHUMITUREPARAM_H__9018C6A7_1D5F_4CE3_B404_9756A0620936__INCLUDED_)
#define AFX_DLGHUMITUREPARAM_H__9018C6A7_1D5F_4CE3_B404_9756A0620936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgHumitureParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgHumitureParam dialog

class CDlgHumitureParam : public CDialog
{
// Construction
public:
	CDlgHumitureParam(CWnd* pParent = NULL);   // standard constructor
	VSNETHUMITUREPRAM	m_humitureparam;
// Dialog Data
	//{{AFX_DATA(CDlgHumitureParam)
	enum { IDD = IDD_DLG_HUMITUREPRAM };
	CString	m_hummax;
	CString	m_hummin;
	CString	m_tempmax;
	CString	m_tempmin;
	int		m_delaytime;
	BOOL	m_singlehost;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgHumitureParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgHumitureParam)
	afx_msg void OnBtnSet();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
	BOOL    UpdateParam();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGHUMITUREPARAM_H__9018C6A7_1D5F_4CE3_B404_9756A0620936__INCLUDED_)
