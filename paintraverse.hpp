#pragma once


using paint_traverse_t = void(__thiscall *)(void*, unsigned int, bool, bool);
paint_traverse_t painttraverse_original = nullptr;

void __fastcall hkPaintTraverse(void* pPanels, int edx, unsigned int vguiPanel, bool forceRepaint, bool allowForce)
{
	painttraverse_original(pPanels, vguiPanel, forceRepaint, allowForce);

	static unsigned int FocusOverlayPanel = 0;

	static bool FoundPanel = false;

	if (!FoundPanel)
	{
		PCHAR szPanelName = (PCHAR)pPanel->GetName(vguiPanel);

		if (strstr(szPanelName, "FocusOverlayPanel"))
		{
			FocusOverlayPanel = vguiPanel;
			FoundPanel = true;
		}
	}
	else if (FocusOverlayPanel == vguiPanel)
	{
		pEngine->GetScreenSize(iScreenWidth, iScreenHeight);

		if (iScreenWidth == 0 || iScreenHeight == 0)
			return;

		DrawVisuals();
		DrawMenu(vguiPanel);
	}
}
