// LUSerParamXCtl.cpp : Implementation of the CLUSerParamXCtrl ActiveX Control class.

#include "stdafx.h"
#include "LUSerParamX.h"
#include "LUSerParamXCtl.h"
#include "LUSerParamXPpg.h"
#include "DlgSerParam.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLUSerParamXCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLUSerParamXCtrl, COleControl)
	//{{AFX_MSG_MAP(CLUSerParamXCtrl)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CLUSerParamXCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CLUSerParamXCtrl)
	DISP_FUNCTION(CLUSerParamXCtrl, "ShowParamPage", ShowParamPage, VT_I4, VTS_BSTR VTS_BSTR VTS_I2 VTS_BSTR VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

#ifdef L_IMPL_OBJECTSAFETY 

BEGIN_INTERFACE_MAP(CLUSerParamXCtrl, COleControl) 
	INTERFACE_PART(CLUSerParamXCtrl, IID_IObjectSafety, ObjectSafety) 
END_INTERFACE_MAP() 

#endif // L_IMPL_OBJECTSAFETY

/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CLUSerParamXCtrl, COleControl)
	//{{AFX_EVENT_MAP(CLUSerParamXCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CLUSerParamXCtrl, 1)
	PROPPAGEID(CLUSerParamXPropPage::guid)
END_PROPPAGEIDS(CLUSerParamXCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLUSerParamXCtrl, "LUSERPARAMX.LUSerParamXCtrl.1",
	0x3bb373e3, 0x11c7, 0x4173, 0x96, 0x3, 0x32, 0x1d, 0x46, 0xf3, 0xf8, 0xf4)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CLUSerParamXCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DLUSerParamX =
		{ 0x9a8b902a, 0x9eef, 0x4be6, { 0x81, 0x83, 0x31, 0xee, 0x66, 0x8a, 0x69, 0xdf } };
const IID BASED_CODE IID_DLUSerParamXEvents =
		{ 0x4c83f36a, 0x9739, 0x4a26, { 0x98, 0xe1, 0x14, 0x5, 0xb9, 0xe, 0xb, 0x62 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwLUSerParamXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLUSerParamXCtrl, IDS_LUSERPARAMX, _dwLUSerParamXOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl::CLUSerParamXCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CLUSerParamXCtrl

BOOL CLUSerParamXCtrl::CLUSerParamXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_LUSERPARAMX,
			IDB_LUSERPARAMX,
			afxRegApartmentThreading,
			_dwLUSerParamXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl::CLUSerParamXCtrl - Constructor

CLUSerParamXCtrl::CLUSerParamXCtrl()
{
	InitializeIIDs(&IID_DLUSerParamX, &IID_DLUSerParamXEvents);

	// TODO: Initialize your control's instance data here.
}

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl::~CLUSerParamXCtrl - Destructor

CLUSerParamXCtrl::~CLUSerParamXCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl::OnDraw - Drawing function

void CLUSerParamXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl::DoPropExchange - Persistence support

void CLUSerParamXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
	// TODO: Call PX_ functions for each persistent custom property.
}

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl::OnResetState - Reset control to default state

void CLUSerParamXCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}

/////////////////////////////////////////////////////////////////////////////
// CLUSerParamXCtrl message handlers

long CLUSerParamXCtrl::ShowParamPage(LPCTSTR sername, LPCTSTR serurl, short serport, LPCTSTR username, LPCTSTR password) 
{
	if(sername == NULL || serurl == NULL || username == NULL || password == NULL) return FALSE;

	CDlgSerParam dlg;
	dlg.m_sername = sername;
	dlg.m_serurl  = serurl;
	dlg.m_serport = serport;
	dlg.m_username= username;
	dlg.m_password= password;
	dlg.DoModal();
	
	return TRUE;
}

void CLUSerParamXCtrl::OnDestroy() 
{
	VSNET_ClientCleanup();
	COleControl::OnDestroy();
}

int CLUSerParamXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	VSNET_ClientStartup(0,NULL,NULL,NULL);
	VSNET_ClientWaitTime(10,4);
	return 0;
}

#ifdef L_IMPL_OBJECTSAFETY 
// Implementation of IObjectSafety 
STDMETHODIMP CLUSerParamXCtrl::XObjectSafety::GetInterfaceSafetyOptions(REFIID riid,
																	 DWORD __RPC_FAR *pdwSupportedOptions,
																	 DWORD __RPC_FAR *pdwEnabledOptions) 
{ 
	METHOD_PROLOGUE_EX(CLUSerParamXCtrl, ObjectSafety)
	if (!pdwSupportedOptions || !pdwEnabledOptions) 
	{ 
		return E_POINTER; 
	} 
	*pdwSupportedOptions = INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA; 
	*pdwEnabledOptions = 0; 
	
	if (NULL == pThis->GetInterface(&riid)) 
	{ 
		TRACE("Requested interface is not supported.\n"); 
		return E_NOINTERFACE; 
	} 
	
	// What interface is being checked out anyhow? 
	OLECHAR szGUID[39]; 
	int i = StringFromGUID2(riid, szGUID, 39); 
	
	if (riid == IID_IDispatch) 
	{ 
		// Client wants to know if object is safe for scripting 
		*pdwEnabledOptions = INTERFACESAFE_FOR_UNTRUSTED_CALLER; 
		return S_OK; 
	} 
	else if(riid == IID_IPersistPropertyBag
		|| riid == IID_IPersistStreamInit
		|| riid == IID_IPersistStorage
		|| riid == IID_IPersistMemory) 
	{ 
		// Those are the persistence interfaces COleControl derived controls support 
		// as indicated in AFXCTL.H 
		// Client wants to know if object is safe for initializing from persistent data 
		*pdwEnabledOptions = INTERFACESAFE_FOR_UNTRUSTED_DATA; 
		return S_OK; 
	} 
	else 
	{ 
		// Find out what interface this is, and decide what options to enable 
		TRACE("We didn¡¯t account for the safety of this interface, and it¡¯s one we support...\n"); 
		return E_NOINTERFACE; 
	}
} 

STDMETHODIMP CLUSerParamXCtrl::XObjectSafety::SetInterfaceSafetyOptions(REFIID riid,
																		DWORD dwOptionSetMask,
																		DWORD dwEnabledOptions) 
{ 
	METHOD_PROLOGUE_EX(CLUSerParamXCtrl, ObjectSafety) 

	OLECHAR szGUID[39]; 
	// What is this interface anyway? 
	// We can do a quick lookup in the registry under HKEY_CLASSES_ROOT\Interface 
	int i = StringFromGUID2(riid, szGUID, 39); 
	if (0 == dwOptionSetMask && 0 == dwEnabledOptions) 
	{ 
		// the control certainly supports NO requests through the specified interface 
		// so it¡¯s safe to return S_OK even if the interface isn¡¯t supported. 
		return S_OK; 
	} 
	
	// Do we support the specified interface? 
	if (NULL == pThis->GetInterface(&riid)) 
	{
		TRACE1("%s is not support.\n", szGUID); 
		return E_FAIL; 
	} 
	
	
	if (riid == IID_IDispatch) 
	{ 
		TRACE("Client asking if it¡¯s safe to call through IDispatch.\n"); 
		TRACE("In other words, is the control safe for scripting?\n"); 
		if (INTERFACESAFE_FOR_UNTRUSTED_CALLER == dwOptionSetMask && INTERFACESAFE_FOR_UNTRUSTED_CALLER == dwEnabledOptions) 
		{ 
			return S_OK; 
		}
		else 
		{ 
			return E_FAIL; 
		} 
	} 
	else if( riid == IID_IPersistPropertyBag
		|| riid == IID_IPersistStreamInit
		|| riid == IID_IPersistStorage
		|| riid == IID_IPersistMemory) 
	{
		TRACE("Client asking if it¡¯s safe to call through IPersist*.\n"); 
		TRACE("In other words, is the control safe for initializing from persistent data?\n"); 
		
		if (INTERFACESAFE_FOR_UNTRUSTED_DATA == dwOptionSetMask && INTERFACESAFE_FOR_UNTRUSTED_DATA == dwEnabledOptions) 
		{ 
			return NOERROR; 
		} 
		else 
		{ 
			return E_FAIL; 
		} 
	} 
	else 
	{ 
		TRACE1("We didn¡¯t account for the safety of %s, and it¡¯s one we support...\n", szGUID); 
		return E_FAIL; 
	} 
} 

STDMETHODIMP_(ULONG) CLUSerParamXCtrl::XObjectSafety::AddRef()
{
	METHOD_PROLOGUE_EX_(CLUSerParamXCtrl, ObjectSafety) 
	return (ULONG)pThis->ExternalAddRef(); 
} 

STDMETHODIMP_(ULONG) CLUSerParamXCtrl::XObjectSafety::Release()
{
	METHOD_PROLOGUE_EX_(CLUSerParamXCtrl, ObjectSafety) 
	return (ULONG)pThis->ExternalRelease(); 
} 

STDMETHODIMP CLUSerParamXCtrl::XObjectSafety::QueryInterface(REFIID iid, LPVOID* ppvObj) 
{ 
	METHOD_PROLOGUE_EX_(CLUSerParamXCtrl, ObjectSafety) 
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj); 
} 

#endif // L_IMPL_OBJECTSAFETY 
