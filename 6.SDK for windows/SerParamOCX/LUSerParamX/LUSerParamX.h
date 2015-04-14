#if !defined(AFX_LUSERPARAMX_H__94A9228B_8529_45F6_B7FF_2BDEEC5977F2__INCLUDED_)
#define AFX_LUSERPARAMX_H__94A9228B_8529_45F6_B7FF_2BDEEC5977F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// LUSerParamX.h : main header file for LUSERPARAMX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXApp : See LUSerParamX.cpp for implementation.

class CLUSerParamXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUSERPARAMX_H__94A9228B_8529_45F6_B7FF_2BDEEC5977F2__INCLUDED)
