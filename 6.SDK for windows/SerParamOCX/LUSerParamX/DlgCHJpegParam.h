#if !defined(AFX_DLGCHJPEGPARAM_H__59AEA080_6C07_4484_A40D_FA4B4056F227__INCLUDED_)
#define AFX_DLGCHJPEGPARAM_H__59AEA080_6C07_4484_A40D_FA4B4056F227__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCHJpegParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCHJpegParam dialog

class CDlgCHJpegParam : public CDialog
{
// Construction
public:
	CDlgCHJpegParam(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCHJpegParam)
	enum { IDD = IDD_DLG_CHJPEGPARA };
	int		m_format;
	int		m_quant;
	int		m_rate;
	int		m_total;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCHJpegParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	VSNETJPEGCAPPARAM   m_jpegparam;
	// Generated message map functions
	//{{AFX_MSG(CDlgCHJpegParam)
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

#endif // !defined(AFX_DLGCHJPEGPARAM_H__59AEA080_6C07_4484_A40D_FA4B4056F227__INCLUDED_)
