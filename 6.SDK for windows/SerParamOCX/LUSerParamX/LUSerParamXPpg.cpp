// LUSerParamXPpg.cpp : Implementation of the CLUSerParamXPropPage property page class.

#include "stdafx.h"
#include "LUSerParamX.h"
#include "LUSerParamXPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLUSerParamXPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLUSerParamXPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CLUSerParamXPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLUSerParamXPropPage, "LUSERPARAMX.LUSerParamXPropPage.1",
	0x43138286, 0xd8ca, 0x44ae, 0xb8, 0x84, 0xfd, 0x27, 0x11, 0x70, 0x1a, 0xc8)


/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXPropPage::CLUSerParamXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CLUSerParamXPropPage

BOOL CLUSerParamXPropPage::CLUSerParamXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LUSERPARAMX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXPropPage::CLUSerParamXPropPage - Constructor

CLUSerParamXPropPage::CLUSerParamXPropPage() :
	COlePropertyPage(IDD, IDS_LUSERPARAMX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CLUSerParamXPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXPropPage::DoDataExchange - Moves data between page and properties

void CLUSerParamXPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CLUSerParamXPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXPropPage message handlers
