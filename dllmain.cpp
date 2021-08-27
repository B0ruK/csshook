
#include "include.hpp"

vmt_hook* drawmodels;
vmt_hook* panels;
vmt_hook* engine;

#include "drawmodel.hpp"
#include "clientmode.hpp"
#include "paintraverse.hpp"

int __stdcall DllMain(void*, int r, void*)
{
	if (r == 1)
	{
		InitialiseInterfaces();
		Offsets::GetOffsets();

		drawmodels = new vmt_hook(pModelRender);
		draw_model_original = drawmodels->hook<DrawModelExecuteFn>(19, hkDrawModelExecute);

		panels = new vmt_hook(pPanel);
		painttraverse_original = panels->hook<paint_traverse_t>(41, hkPaintTraverse);

		engine = new vmt_hook(pEngine);
		org_SetViewAngles = engine->hook<SetViewAngleFn>(20, hooked_SetViewAngles);

		Draw::InitFonts();
	}

	return 1;
}
