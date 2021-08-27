#include "include.hpp"

PVOID GetInterface(LPCWSTR szModule, PCCH szObject)
{
	if (const auto Module = GetModuleHandleW(szModule))
	{
		const auto dwCreateInterface = reinterpret_cast<DWORD>(GetProcAddress(Module, "CreateInterface"));
		const auto dwShortJmp = dwCreateInterface + 0x5;
		const auto dwJmp = (dwShortJmp + *reinterpret_cast<DWORD *>(dwShortJmp)) + 0x4;

		auto pList = **reinterpret_cast<InterfaceNode ***>(dwJmp + 0x6);

		while (pList)
		{
			if ((strstr(pList->szName, szObject) && (strlen(pList->szName) - strlen(szObject)) < 5))
				return pList->fnGet();

			pList = pList->pNext;
		}
	}

	return nullptr;
}

void InitialiseInterfaces()
{
	pRenderView = (IVRenderView*)(GetInterface(L"engine.dll", "VEngineRenderView"));
	pModelRender = (ModelRender*)(GetInterface(L"engine.dll", "VEngineModel"));
	pPanel = (Panel*)(GetInterface(L"vgui2.dll", "VGUI_Panel"));
	pSurface = (Surface*)(GetInterface(L"vguimatsurface.dll", "VGUI_Surface"));
	pClient = (CLient*)(GetInterface(L"client.dll", "VClient"));
	pEngine = (EngineClient*)(GetInterface(L"engine.dll", "VEngineClient"));
	pEntList = (EntityList*)(GetInterface(L"client.dll", "VClientEntityList"));
	pMaterialSystem = (MaterialSystem*)(GetInterface(L"materialsystem.dll", "VMaterialSystem"));
	pEngineTrace = (Enginetrace*)(GetInterface(L"engine.dll", "EngineTraceClient"));
	pGlobalVars = **reinterpret_cast<GlobalVars***>((*reinterpret_cast<uintptr_t**>(pClient))[0] + 0x34);
	pClientmode = **(void***)((*(DWORD**)pClient)[10] + 0x5);
}



