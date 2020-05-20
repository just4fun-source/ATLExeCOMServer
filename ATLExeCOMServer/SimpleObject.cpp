#include "pch.h"
#include "SimpleObject.h"

STDMETHODIMP CSimpleObject::SayHello(BSTR* pRet)
{
	*pRet = ::SysAllocString(L"Hello World!");
	if (pRet == NULL) return E_OUTOFMEMORY;
	return S_OK;
}

STDMETHODIMP CSimpleObject::GetProcessID(LONG* pProcessId)
{
	*pProcessId = GetCurrentProcessId();
	return S_OK;
}

STDMETHODIMP CSimpleObject::GetThreadID(LONG* pThreadId)
{
	*pThreadId = GetCurrentThreadId();
	return S_OK;
}
