#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ATLExeCOMServer_i.h"
#include "xdlldata.h"

using namespace ATL;

class CATLExeCOMServerModule : public ATL::CAtlExeModuleT< CATLExeCOMServerModule >
{
public:
	DECLARE_LIBID(LIBID_ATLExeCOMServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLEXECOMSERVER, "{295c82a5-f2d9-43ef-8d93-cf3f4fb74375}")
};

CATLExeCOMServerModule _AtlModule;

extern "C" int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}
