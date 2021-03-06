#if !defined(AFX_LUSERPARAMX_H__DDDC96A4_0767_471E_B03D_43A46BC24188__INCLUDED_)
#define AFX_LUSERPARAMX_H__DDDC96A4_0767_471E_B03D_43A46BC24188__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamX wrapper class

class CLUSerParamX : public CWnd
{
protected:
	DECLARE_DYNCREATE(CLUSerParamX)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x3bb373e3, 0x11c7, 0x4173, { 0x96, 0x3, 0x32, 0x1d, 0x46, 0xf3, 0xf8, 0xf4 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	long ShowParamPage(LPCTSTR sername, LPCTSTR serurl, short serport, LPCTSTR username, LPCTSTR password);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUSERPARAMX_H__DDDC96A4_0767_471E_B03D_43A46BC24188__INCLUDED_)
