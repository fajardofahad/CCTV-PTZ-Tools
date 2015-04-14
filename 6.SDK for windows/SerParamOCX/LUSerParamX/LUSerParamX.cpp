// LUSerParamX.cpp : Implementation of CLUSerParamXApp and DLL registration.

#include "stdafx.h"
#include "LUSerParamX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CLUSerParamXApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x1a12460, 0x909d, 0x4847, { 0x81, 0x93, 0xa, 0xf7, 0x9f, 0x4e, 0xec, 0x5f } };
const WORD _wVerMajor = 2;
const WORD _wVerMinor = 3;


////////////////////////////////////////////////////////////////////////////
// CLUSerParamXApp::InitInstance - DLL initialization

BOOL CLUSerParamXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}
	return bInit;
}


////////////////////////////////////////////////////////////////////////////
// CLUSerParamXApp::ExitInstance - DLL termination

int CLUSerParamXApp::ExitInstance()
{
	// TODO: Add your own module termination code here.
	return COleControlModule::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
