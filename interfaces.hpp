

extern void InitialiseInterfaces();

inline void* pClientmode;
inline GlobalVars* pGlobalVars;
inline EngineClient* pEngine;
inline EntityList* pEntList;
inline MaterialSystem* pMaterialSystem;
inline CLient* pClient;
inline Enginetrace* pEngineTrace;
inline Panel* pPanel;
inline Surface* pSurface;
inline ModelRender* pModelRender;
inline IVRenderView* pRenderView;

struct InterfaceNode
{
	void* (*fnGet)();
	const char* szName;
	InterfaceNode* pNext;
};
