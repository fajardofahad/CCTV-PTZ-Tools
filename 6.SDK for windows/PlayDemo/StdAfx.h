// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__43610153_4EDE_435F_A027_E2FECB25B11E__INCLUDED_)
#define AFX_STDAFX_H__43610153_4EDE_435F_A027_E2FECB25B11E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <Vfw.h>
#include "launet.h"

#define VIDEOWND_MSG (WM_USER + 300)
#define VIEWNUM      4

typedef struct
{
	char m_sername[24];
	char m_url[40];
	char m_ch;
	char m_trantype;
	WORD m_port;
	char m_username[20];
	char m_password[20];
	HWND m_videownd;
}CAM_DECITEM;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__43610153_4EDE_435F_A027_E2FECB25B11E__INCLUDED_)
