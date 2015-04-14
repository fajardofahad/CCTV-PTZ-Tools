#if !defined(AFX_STDAFX_H__BF103541_6E19_45F6_B957_102E2FAB746B__INCLUDED_)
#define AFX_STDAFX_H__BF103541_6E19_45F6_B957_102E2FAB746B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxctl.h>         // MFC support for ActiveX Controls
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Comon Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// Delete the two includes below if you do not wish to use the MFC
//  database classes
#include <afxdb.h>			// MFC database classes
#include <afxdao.h>			// MFC DAO database classes

#include <process.h>

#include "launet.h"

#define DLGLOADPARAM_MSG	(WM_USER + 10)
#define DLGFREEPARAM_MSG	(WM_USER + 11)
#define DLGPARM_LOGINMSG	(WM_USER + 12)	//µÇÂ¼ÏûÏ¢
#define DLGPRAM_INITMSG		(WM_USER + 13)
#define DLGWND_VIDEOMSG		(WM_USER + 14)

#define KILLTIMER(id) if(id) {KillTimer(id); id = 0;}

enum{LOGIN_OK	  = 0,
	 LOGIN_FAILED,
	 LOGIN_USERERRNO,
	 LOGIN_USEROK,
};

class CDlgSerParam;
extern CDlgSerParam *g_SerParam;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__BF103541_6E19_45F6_B957_102E2FAB746B__INCLUDED_)
