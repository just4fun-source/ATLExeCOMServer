#pragma once
#include "resource.h"
#include "ATLExeCOMServer_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Singlethread-COM-Objekte werden auf der Windows CE-Plattform nicht vollständig unterstützt. Windows Mobile-Plattformen bieten beispielsweise keine vollständige DCOM-Unterstützung. Definieren Sie _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, um ATL zu zwingen, die Erstellung von Singlethread-COM-Objekten zu unterstützen und die Verwendung eigener Singlethread-COM-Objektimplementierungen zu erlauben. Das Threadmodell in der RGS-Datei wurde auf 'Free' festgelegt, da dies das einzige Threadmodell ist, das auf Windows CE-Plattformen ohne DCOM unterstützt wird."
#endif

using namespace ATL;

class ATL_NO_VTABLE CSimpleObject :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSimpleObject, &CLSID_SimpleObject>,
	public IDispatchImpl<ISimpleObject, &IID_ISimpleObject, &LIBID_ATLExeCOMServerLib, 1, 0>
{
public:
	CSimpleObject()
	{
	}

	DECLARE_REGISTRY_RESOURCEID(106)

	BEGIN_COM_MAP(CSimpleObject)
		COM_INTERFACE_ENTRY(ISimpleObject)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(SayHello)(BSTR* pRet);
	STDMETHOD(GetProcessID)(LONG* pProcessId);
	STDMETHOD(GetThreadID)(LONG* pThreadId);
};

OBJECT_ENTRY_AUTO(__uuidof(SimpleObject), CSimpleObject)
