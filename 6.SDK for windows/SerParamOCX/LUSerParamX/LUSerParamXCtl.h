#if !defined(AFX_LUSERPARAMXCTL_H__3D018BD1_4BBA_42B8_8F88_E37904452A97__INCLUDED_)
#define AFX_LUSERPARAMXCTL_H__3D018BD1_4BBA_42B8_8F88_E37904452A97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// LUSerParamXCtl.h : Declaration of the CLUSerParamXCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl : See LUSerParamXCtl.cpp for implementation.
#ifdef L_IMPL_OBJECTSAFETY
#include <objsafe.h>
#endif // L_IMPL_OBJECTSAFETY

class CLUSerParamXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLUSerParamXCtrl)

// Constructor
public:
	CLUSerParamXCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLUSerParamXCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

#ifdef L_IMPL_OBJECTSAFETY 
	BEGIN_INTERFACE_PART(ObjectSafety, IObjectSafety) 
		STDMETHOD(GetInterfaceSafetyOptions)(REFIID riid, DWORD __RPC_FAR *pdwSupportedOptions, DWORD __RPC_FAR *pdwEnabledOptions); 
		STDMETHOD(SetInterfaceSafetyOptions)(REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions); 
	END_INTERFACE_PART(ObjectSafety) 

	DECLARE_INTERFACE_MAP(); 
#endif // L_IMPL_OBJECTSAFET

// Implementation
protected:
	~CLUSerParamXCtrl();

	DECLARE_OLECREATE_EX(CLUSerParamXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CLUSerParamXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLUSerParamXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CLUSerParamXCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CLUSerParamXCtrl)
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CLUSerParamXCtrl)
	afx_msg long ShowParamPage(LPCTSTR sername, LPCTSTR serurl, short serport, LPCTSTR username, LPCTSTR password);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CLUSerParamXCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CLUSerParamXCtrl)
	dispidShowParamPage = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUSERPARAMXCTL_H__3D018BD1_4BBA_42B8_8F88_E37904452A97__INCLUDED)
