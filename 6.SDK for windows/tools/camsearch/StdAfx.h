// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__3EAD2461_7E79_46F3_A1A4_C827CF8BFFFE__INCLUDED_)
#define AFX_STDAFX_H__3EAD2461_7E79_46F3_A1A4_C827CF8BFFFE__INCLUDED_

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


typedef struct
{
	unsigned char m_mac[6];
	char m_sername[40];
	char m_url[20];
	char m_submask[20];
	char m_getway[20];
	char m_multiip[20];
	char m_dns[20];
	WORD m_localport;
	WORD m_webport;
	WORD m_multiport;
}CAMLIST_ITEM;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__3EAD2461_7E79_46F3_A1A4_C827CF8BFFFE__INCLUDED_)
