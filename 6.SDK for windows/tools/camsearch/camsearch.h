// camsearch.h : main header file for the CAMSEARCH application
//

#if !defined(AFX_CAMSEARCH_H__09376AA7_3836_4359_99B8_28F9BE8FECAD__INCLUDED_)
#define AFX_CAMSEARCH_H__09376AA7_3836_4359_99B8_28F9BE8FECAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCamsearchApp:
// See camsearch.cpp for the implementation of this class
//

class CCamsearchApp : public CWinApp
{
public:
	CCamsearchApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamsearchApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCamsearchApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMSEARCH_H__09376AA7_3836_4359_99B8_28F9BE8FECAD__INCLUDED_)
