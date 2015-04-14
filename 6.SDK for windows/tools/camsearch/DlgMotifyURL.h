#if !defined(AFX_DLGMOTIFYURL_H__2A16448D_2DA6_44C6_8530_4EB001C21350__INCLUDED_)
#define AFX_DLGMOTIFYURL_H__2A16448D_2DA6_44C6_8530_4EB001C21350__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMotifyURL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMotifyURL dialog

class CDlgMotifyURL : public CDialog
{
// Construction
public:
	CAMLIST_ITEM m_camitem;
	CDlgMotifyURL(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgMotifyURL)
	enum { IDD = IDD_DLG_MODIFYURL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMotifyURL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMotifyURL)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMOTIFYURL_H__2A16448D_2DA6_44C6_8530_4EB001C21350__INCLUDED_)
