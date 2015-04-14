#if !defined(AFX_LUSERPARAMXPPG_H__B4CDDB3D_1688_44CD_B30A_0F14EE43C101__INCLUDED_)
#define AFX_LUSERPARAMXPPG_H__B4CDDB3D_1688_44CD_B30A_0F14EE43C101__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// LUSerParamXPpg.h : Declaration of the CLUSerParamXPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CLUSerParamXPropPage : See LUSerParamXPpg.cpp.cpp for implementation.

class CLUSerParamXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLUSerParamXPropPage)
	DECLARE_OLECREATE_EX(CLUSerParamXPropPage)

// Constructor
public:
	CLUSerParamXPropPage();

// Dialog Data
	//{{AFX_DATA(CLUSerParamXPropPage)
	enum { IDD = IDD_PROPPAGE_LUSERPARAMX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CLUSerParamXPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUSERPARAMXPPG_H__B4CDDB3D_1688_44CD_B30A_0F14EE43C101__INCLUDED)
