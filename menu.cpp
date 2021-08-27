#include "include.hpp"


bool bSliderFix[50];

int iSliderIndex = -1;
int iCurrSlider;

DWORD dwWait;

#define COLOR1 60, 60, 60, 255
#define COLOR2 85, 85, 85, 255
#define COLOR3 0, 0, 0, 255
#define COLOR4 35, 35, 35, 255
#define COLOR5 50, 50, 50, 255
#define COLOR6 100, 100, 100, 255
#define COLOR7 73, 73, 73, 255
#define COLOR8 65, 65, 65, 255
#define COLOR10 255, 255, 255, 255

#define COLOR9 (gCvars.colorsredone), (gCvars.colorsgreenone), (gCvars.colorsblueone), 255
#define COLOR69 (gCvars.colorsredone), (gCvars.colorsgreenone), (gCvars.colorsblueone), 110

#define ELEMENT_HEIGHT 15
#define ELEMENT_SEPERATION 20
#define CHECKBOX_SEPERATION_FROM_TEXT 95
#define CHECKBOX_SIZE 13

#define DEFAULT_X_TO_ADD (CHECKBOX_SEPERATION_FROM_TEXT + CHECKBOX_SIZE + 40)

#define DROPDOWN_WIDTH 56
#define DROPDOWN_HEIGHT 15

#define ADDER_SIZEX 12
#define ADDER_SIZEY 13

#define ADDER_SEPERATE_FROM_BOXES 44 

cMenu::cMenu(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

int iRowTwo = DEFAULT_X_TO_ADD;
int iRowThree = ((DEFAULT_X_TO_ADD) * 2) - 10;

void cMenu::InitMenuElements()
{
	static cMenuSection mslegitbot;
	static cMenuSection mslegitbotSliders;
	static cMenuSection msEsp;
	static cMenuSection msRemovals;
	static cMenuSection hoodrich;
	static cMenuSection colortabslide;
	static cMenuSection colortabshow;
	static cMenuSection nightmodesliders;

	int iUsualX = m_x + 10;

	iCurrSlider = 0;

	switch (GetTabIndex())
	{
	case LEGITAB:

		mslegitbot.ClearSection();
		mslegitbotSliders.ClearSection();

		mslegitbot.Draw(iUsualX, m_y + 13, m_w - 22, 80);

		mslegitbot.AddElement(ONOFF, 0, 0, "AIMBOT", &gCvars.legitenable);
		mslegitbot.AddElement(ONOFF, 0, 0, "BACKTRACK", &gCvars.lagcomp);
		mslegitbot.AddElement(ADDER, 0, 0, "AIM BONE", &gCvars.AimSpot, 0, 14);

		mslegitbot.RestartSection();

		mslegitbot.AddElement(ONOFF, iRowTwo, 0, "AIM ONFIRE", &gCvars.inattack);
		mslegitbot.AddElement(ONOFF, iRowTwo, 0, "AIM TEAM", &gCvars.AimTeam);
		mslegitbot.AddElement(ONOFF, iRowTwo, 0, "AUTOPISTOL", &gCvars.autopistol);

		mslegitbot.RestartSection();

		mslegitbot.AddElement(ONOFF, iRowThree, 0, "RCS ASSIST", &gCvars.RCSASSIST);
		mslegitbot.AddElement(ADDER, iRowThree, 0, "RCS FOV", &gCvars.RCSFOV, 0, 20);
		mslegitbot.AddElement(ADDER, iRowThree, 0, "RCS SMOOTH", &gCvars.RCSSMOOTH, 0, 50);


		mslegitbotSliders.Draw(iUsualX, m_y + 99, m_w - 22, 124);

		mslegitbotSliders.SetSlider(iCurrSlider, true);
		mslegitbotSliders.AddElement(SLIDER, 0, 0, "TARGET SELECTION FOV", &gCvars.AimFOV, 0, 20);
		mslegitbotSliders.SetSlider(iCurrSlider, true);
		mslegitbotSliders.AddElement(SLIDER, 0, 0, "SMOOTHNESS PITCH", &gCvars.Smoothnesspitch, 0, 50);
		mslegitbotSliders.SetSlider(iCurrSlider, true);
		mslegitbotSliders.AddElement(SLIDER, 0, 0, "SMOOTHNESS YAW", &gCvars.Smoothnessyaw, 0, 50);

		break;

	case ESPTAB:
		msEsp.ClearSection();
		nightmodesliders.ClearSection();

		msEsp.Draw(iUsualX, m_y + 13, m_w - 22, 114);

		msEsp.AddElement(ONOFF, 0, -4, "BOX ESP", &gCvars.espbox);
		msEsp.AddElement(ONOFF, 0, -4, "HEALTH ESP", &gCvars.healthbar);
		msEsp.AddElement(ONOFF, 0, -4, "NAME ESP", &gCvars.espname);
		msEsp.AddElement(ONOFF, 0, -4, "ESP TEAM", &gCvars.espteam);
		msEsp.RestartSection();
		msEsp.AddElement(ONOFF, iRowTwo, -4, "CHAMS", &gCvars.chams);
		msEsp.AddElement(ONOFF, iRowTwo, -4, "CHAMS XQZ", &gCvars.XQZ);
		msEsp.AddElement(ONOFF, iRowTwo, -4, "CHAM TEAM", &gCvars.CHAMTEAM);

		msEsp.RestartSection();

		msEsp.AddElement(ONOFF, iRowThree, -4, "RADAR", &gCvars.radar);
		msEsp.AddElement(ONOFF, iRowThree, -4, "RADAR TEAM", &gCvars.radarteam);
		msEsp.AddElement(ADDER, iRowThree, -4, "RADAR SIZE", &gCvars.radarsize, 1, 150);
		msEsp.AddElement(ONOFF, iRowThree, -4, "RADAR NAME", &gCvars.radarnames);

		nightmodesliders.Draw(iUsualX, m_y + 133, m_w - 22, 90);

		nightmodesliders.SetSlider(iCurrSlider, true);
		nightmodesliders.AddElement(SLIDER, 0, 0, "ESP RENDER RANGE", &gCvars.esprenderdist, 0, 8000);
		nightmodesliders.SetSlider(iCurrSlider, true);
		nightmodesliders.AddElement(SLIDER, 0, 0, "RADAR RENDER DIST", &gCvars.radarrange, 0, 200);

		break;

	case MISCTAB:
		msRemovals.ClearSection();
		hoodrich.ClearSection();

		hoodrich.Draw(iUsualX, m_y + 13, m_w - 22, 64);
		hoodrich.AddElement(ONOFF, 0, 0, "TRIGGERBOT", &gCvars.trigenable);
		hoodrich.AddElement(ONOFF, 0, 0, "TRIG TEAM", &gCvars.trigteam);
		hoodrich.RestartSection();
		hoodrich.AddElement(ONOFF, iRowTwo, 0, "TRIG HEAD", &gCvars.trighead);
		hoodrich.AddElement(KEYBIND, iRowTwo, 0, "KEY BIND", &gCvars.triggerkey);
		hoodrich.RestartSection();
		hoodrich.AddElement(ONOFF, iRowThree, 0, " TRIG BODY", &gCvars.triggerbody);
		hoodrich.AddElement(ADDER, iRowThree, 0, " DELAY", &gCvars.trigerdelay, 10, 200);

		msRemovals.Draw(iUsualX, m_y + 83, m_w - 22, 140);
		msRemovals.AddElement(ONOFF, 0, 0, "BUNNYHOP", &gCvars.Bunnyhop);
		msRemovals.AddElement(ONOFF, 0, 0, "WATERMARK", &gCvars.watermark);
		msRemovals.AddElement(ONOFF, 0, 0, "MONITOR", &gCvars.drawmonitor);
		msRemovals.RestartSection();
		msRemovals.AddElement(ONOFF, iRowTwo, 0, "VELOCITY", &gCvars.velocity);
		msRemovals.AddElement(ONOFF, iRowTwo, 0, "RCS XHAIR", &gCvars.recoilxhair);

		hoodrich.PostSection();
		break;
	case COLTAB:
		colortabslide.ClearSection();

		ListItemArray.ClearList();

		ListItemArray.AddItem("menu colors");
		ListItemArray.AddItem("visuals colors");
		ListItemArray.AddItem("radar colors");
		ListItemArray.AddItem("chams colors");
		ListItemArray.AddItem("xqz chams colors");
		ListItemArray.Draw(iUsualX, m_y + 16, m_w - 22, 80, false);

		if (ListItemArray.IsSelected(0))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredone, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenone, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueone, 0, 255);
		}

		if (ListItemArray.IsSelected(1))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredtwo, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreentwo, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsbluetwo, 0, 255);
		}

		if (ListItemArray.IsSelected(2))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredTHREE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenTHREE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueTHREE, 0, 255);
		}

		if (ListItemArray.IsSelected(3))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredFOUR, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenFOUR, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueFOUR, 0, 255);
		}

		if (ListItemArray.IsSelected(4))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredFIVE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenFIVE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueFIVE, 0, 255);
		}

		break;
	}
}

void cListItem::Draw(int x, int y, int w, int h, bool scrolls)
{
	int iNumOfItems = GetNumberOfItems();

	int slackerx = x + w - 8;

	if (iNumOfItems == 0)
	{
		Draw::FillRGBA(slackerx, y, 8, h, COLOR2);

		Draw::OutlinedRectangle(slackerx, y, 8, h, COLOR6);

		Draw::OutlinedRectangle(x, y, w, h, COLOR2);

		return;
	}

	if (iSelectedIndex >= iNumOfItems)
		iSelectedIndex = (iNumOfItems - 1);

	if (iTopIndex >= iNumOfItems)
		iTopIndex = 0;

	DisplayPerPage(((h / ELEMENT_HEIGHT) - 1));

	int iDisplayed = 0;

	for (int i = iTopIndex; i < iNumOfItems; i++)
	{
		if (iDisplayed > iDisplayPerPage)
			break;

		ListItem_t liItem = GetItemFromIndex(i);

		int iDrawIndex = i - iTopIndex;

		if ((iDrawIndex & 2) == 1)
		{
			Draw::FillRGBA(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT, 255, 255, 255, 255);
		}

		if (g_Mouse.IsOver(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT + 1))
		{
			Draw::FillRGBA(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT, 255, 255, 255, 4);

			if (g_Mouse.HasMouseOneJustBeenReleased())
			{
				this->Select(i);
			}
		}

		if (iSelectedIndex == i)
		{
			Draw::GradientVertical(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT, gCvars.colorsredone * 0.35, gCvars.colorsgreenone * 0.35, gCvars.colorsblueone * 0.35, 255, gCvars.colorsredone, gCvars.colorsgreenone, gCvars.colorsblueone);
		}

		Draw::RenderText(x + 5, y + iDrawIndex * ELEMENT_HEIGHT + 1, COLOR10, false, Fonts::m_WatermarkFont, liItem.szName);

		iDisplayed++;
	}

	if (g_Mouse.IsOver(x, y, w, h))
	{
		if (!IsFocused())
			SetFocus(true);
	}
	else
	{
		if (IsFocused())
			SetFocus(false);
	}

	if (scrolls)
	{
		int iHowMany = iNumOfItems - iDisplayPerPage;
		int iScrollBar = (iHowMany * 3.5);
		int iWhen = 0;

		if (iScrollBar > (h - 20))
		{
			iScrollBar = h - 20;

			for (int nab = 0; ; nab++)
			{
				int iNew = (nab * 3.5);

				if (iNew > (h - 20))
				{
					iWhen = nab;
					break;
				}
			}
		}

		int iDiff = 0;

		if (iWhen > 0)
			iDiff = abs(iHowMany - iWhen) * 3.5;

		int iScrollBarHai = h + 3.5 - iScrollBar;
		int iScrollYAdd = iTopIndex * 3.5 * ((iWhen > 0) ? ((3.5 / iDiff) * 10 + 0.15) : 1);
		int iScrollYPos = y + iScrollYAdd;
		int iSavedScrollYPos = iScrollYPos;
		int iDummy;

		g_Mouse.Drag(g_Mouse.bDragged[1], true, g_Mouse.LeftClick(slackerx, y, 8, h), iDummy, iScrollYPos, g_Mouse.iDiffX[1], g_Mouse.iDiffY[1]);

		if (g_Mouse.bDragged[1] && !g_Menu.IsHandlingItem())
			g_Menu.AddMenuFlag(FL_DISABLEDRAG);

		if (iScrollYPos != iSavedScrollYPos)
		{
			int iNewTopIndex = (iScrollYPos - y);
			iNewTopIndex /= 3.5;
			iNewTopIndex /= ((iWhen > 0) ? ((3.5 / iDiff) * 10 + 0.15) : 1);

			if (iNewTopIndex < 0)
				iNewTopIndex = 0;

			int iLastPossibleTopIndex = abs(iNumOfItems - iDisplayPerPage) - 1;

			if (iNewTopIndex > iLastPossibleTopIndex)
				iNewTopIndex = iLastPossibleTopIndex;

			iScrollYPos = y + (iNewTopIndex * 3.5 * ((iWhen > 0) ? ((3.5 / iDiff) * 10 + 0.15) : 1));

			iTopIndex = iNewTopIndex;
		}

		Draw::FillRGBA(slackerx, iScrollYPos - 2, 8, iScrollBarHai, COLOR1);
		Draw::OutlinedRectangle(slackerx, iScrollYPos - 2, 8, iScrollBarHai, COLOR6);
	}

	Draw::OutlinedRectangle(x, y - 3, w, h, COLOR2);
}

int iNubLoop[] = { 22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };

void cMenu::DrawTab(int index, int &setindex, int x, int y, const char *pszTitle)
{
	static int iWidth = 100;
	static int iHeight = 22;

	bool bOverTri = false;

	bool bOverBack = g_Mouse.IsOver(x + iHeight, y - iHeight, iWidth + 1 - iHeight, iHeight + 1);

	bool bSame = setindex == index;

	for (int ax = 0; ax <= iHeight; ax++)
	{
		if (g_Mouse.IsOver(x + ax, y - ax, 2, ax) || g_Mouse.IsOver(x + iWidth + ax, y - iHeight, 2, iNubLoop[ax]))
		{
			bOverTri = true;
			break;
		}
	}

	for (int i = 0; i <= iHeight; i++)
	{
		if (bSame)
		{
			pSurface->DrawSetColor(COLOR7);
			pSurface->DrawLine(x + i, y, x + iHeight + i, y - iHeight);
			pSurface->DrawLine(x + iWidth + iHeight - i, y - iHeight, x + iWidth - i, y);

			if (i == iHeight)
				Draw::FillRGBA(x + iHeight, y - iHeight, iWidth - iHeight, iHeight + 1, COLOR7);
		}
		else
		{
			if (bOverBack || bOverTri)
				pSurface->DrawSetColor(COLOR8);
			else
				pSurface->DrawSetColor(COLOR1);

			pSurface->DrawLine(x + i, y, x + iHeight + i, y - iHeight);
			pSurface->DrawLine(x + iWidth + iHeight - i, y - iHeight, x + iWidth - i, y);

			if (g_Mouse.HasMouseOneJustBeenReleased() && (bOverBack || bOverTri))
				setindex = index;

			if (i == iHeight)
			{
				if (bOverBack || bOverTri)
					Draw::FillRGBA(x + iHeight, y - iHeight, iWidth - iHeight, iHeight + 1, COLOR8);
				else
					Draw::FillRGBA(x + iHeight, y - iHeight, iWidth - iHeight, iHeight + 1, COLOR1);
			}
		}
	}

	pSurface->DrawSetColor(COLOR2);

	pSurface->DrawLine(x, y, x + iHeight, y - iHeight);
	pSurface->DrawLine(x + iHeight, y - iHeight, x + iWidth + iHeight + 1, y - iHeight);
	pSurface->DrawLine(x + iWidth, y, x + iWidth + iHeight, y - iHeight);
	pSurface->DrawLine(x, y, x + iWidth, y);

	Draw::RenderText(x + (iWidth + iHeight) * 0.5, y + 3 - iHeight, COLOR9, true, Fonts::m_WatermarkFont, pszTitle);
}

void cMenu::DrawMenu()
{
	Draw::FillRGBA(m_x + 22, m_y - 22, 80 * 5 + 20, 23, COLOR4);

	DrawTab(LEGITAB, iTabIndex, m_x, m_y, "AIMBOT");
	DrawTab(ESPTAB, iTabIndex, m_x + 125, m_y, "VISUAL");
	DrawTab(MISCTAB, iTabIndex, m_x + 245, m_y, "MISC");
	DrawTab(COLTAB, iTabIndex, m_x + 365, m_y, "COLOR");

	Draw::FillRGBA(m_x, m_y + 1, m_w, m_h, COLOR3);
	Draw::FillRGBA(m_x + 1, m_y + 2, m_w - 2, m_h - 2, COLOR4);
	Draw::FillRGBA(m_x + 6, m_y + 7, m_w - 12, m_h - 12, COLOR3);
	Draw::FillRGBA(m_x + 7, m_y + 8, m_w - 14, m_h - 14, COLOR5);

	Draw::FillRGBA(m_x - 15, m_y + 50, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x - 14, m_y + 51, 14, 53))
	{
		CfgSystem::SaveCFG(true, false);
	}

	if (g_Mouse.LeftClick(m_x - 14, m_y + 51, 14, 53))
		Draw::FillRGBA(m_x - 15, m_y + 50, 15, 55, COLOR9);

	Draw::FillRGBA(m_x - 14, m_y + 51, 14, 53, COLOR6);

	Draw::RenderText(m_x - 10, m_y + 51,COLOR9, false, Fonts::m_WatermarkFont,"S");
	Draw::RenderText(m_x - 10, m_y + 63,COLOR9, false, Fonts::m_WatermarkFont,"A");
	Draw::RenderText(m_x - 10, m_y + 75,COLOR9, false, Fonts::m_WatermarkFont,"V");
	Draw::RenderText(m_x - 10, m_y + 87,COLOR9, false, Fonts::m_WatermarkFont,"E");

	Draw::FillRGBA(m_x - 15, m_y + 140, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x - 14, m_y + 141, 14, 53))
	{
		CfgSystem::LoadCfg(true, false);
	}

	if (g_Mouse.LeftClick(m_x - 14, m_y + 141, 14, 53))
		Draw::FillRGBA(m_x - 15, m_y + 140, 15, 55, COLOR9);

	Draw::FillRGBA(m_x - 14, m_y + 141, 14, 53, COLOR6);

	Draw::RenderText(m_x - 10, m_y + 140,  COLOR9, false, Fonts::m_WatermarkFont,  "L");
	Draw::RenderText(m_x - 10, m_y + 152,  COLOR9, false, Fonts::m_WatermarkFont, "O");
	Draw::RenderText(m_x - 10, m_y + 164,  COLOR9, false, Fonts::m_WatermarkFont, "A");
	Draw::RenderText(m_x - 10, m_y + 176,  COLOR9, false, Fonts::m_WatermarkFont,  "D");

	Draw::FillRGBA(m_x + m_w, m_y + 50, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x + m_w, m_y + 51, 14, 53))
	{
		CfgSystem::SaveCFG(false, true);
	}

	if (g_Mouse.LeftClick(m_x + m_w, m_y + 51, 15, 55))
		Draw::FillRGBA(m_x + m_w, m_y + 50, 15, 55, COLOR9);

	Draw::FillRGBA(m_x + m_w, m_y + 51, 14, 53, COLOR6);

	Draw::RenderText(m_x + m_w + 3, m_y + 51,  COLOR9, false, Fonts::m_WatermarkFont, "S");
	Draw::RenderText(m_x + m_w + 3, m_y + 63,  COLOR9, false, Fonts::m_WatermarkFont, "A");
	Draw::RenderText(m_x + m_w + 3, m_y + 75,  COLOR9, false, Fonts::m_WatermarkFont, "V");
	Draw::RenderText(m_x + m_w + 3, m_y + 87,  COLOR9, false, Fonts::m_WatermarkFont, "E");

	Draw::FillRGBA(m_x + m_w, m_y + 140, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x + m_w, m_y + 141, 14, 53))
	{
		CfgSystem::LoadCfg(false, true);
	}

	if (g_Mouse.LeftClick(m_x + m_w, m_y + 141, 15, 55))
		Draw::FillRGBA(m_x + m_w, m_y + 140, 15, 55, COLOR9);

	Draw::FillRGBA(m_x + m_w, m_y + 141, 14, 53, COLOR6);

	Draw::RenderText(m_x + m_w + 3, m_y + 140, COLOR9, false, Fonts::m_WatermarkFont, "L");
	Draw::RenderText(m_x + m_w + 3, m_y + 152, COLOR9, false, Fonts::m_WatermarkFont, "O");
	Draw::RenderText(m_x + m_w + 3, m_y + 164, COLOR9, false, Fonts::m_WatermarkFont, "A");
	Draw::RenderText(m_x + m_w + 3, m_y + 176, COLOR9, false, Fonts::m_WatermarkFont, "D");

	InitMenuElements();
}

void cMenuSection::Draw(int x, int y, int w, int h)
{
	Draw::OutlinedRectangle(x,y,w,h,COLOR2);

	SetSectionPos(x,y);
}

void cMenuSection::DrawAllDropDowns()
{
	int iNumOfDropDowns = vecDropDowns.size();

	int iWhich = -1;

	for (int i2 = (iNumOfDropDowns - 1); i2 >= 0; i2--)
	{
		bool bIsActive = bActiveDropDown[i2];

		if (bIsActive)
		{
			iWhich = i2;

			dwWait = GetTickCount() + 700;
			break;
		}
	}

	for (int i = (iNumOfDropDowns - 1); i >= 0; i--)
	{
		int e_x = vecDropDowns[i].x;
		int e_y = vecDropDowns[i].y;
		int iCount = vecDropDowns[i].iCount;

		bool bIsActive = bActiveDropDown[i];

		char **ppszNames = vecDropDowns[i].ppszNames;
		float *fValues = vecDropDowns[i].fValues;
		float *cvar = vecDropDowns[i].cvar;

		int gayfag = e_x - 1;

		if (bIsActive)
		{
			int string_x = gayfag + (DROPDOWN_WIDTH * 0.5);

			for (int ax = 0; ax < iCount; ax++)
			{
				if (g_Mouse.IsOver(gayfag, e_y + (ax * DROPDOWN_HEIGHT), DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
				{
					if (!g_Menu.IsHandlingItem())
						g_Menu.AddMenuFlag(FL_DISABLEDRAG);

					Draw::FillRGBA(gayfag + 1, e_y + 1 + (ax * DROPDOWN_HEIGHT), DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - (ax == (iCount - 1) ? 1 : 0), COLOR5);

					if (g_Mouse.HasMouseOneJustBeenReleased())
					{
						*cvar = fValues[ax];

						bActiveDropDown[i] = false;
					}
				}
				else
				{
					Draw::FillRGBA(gayfag + 1, e_y + 1 + (ax * DROPDOWN_HEIGHT), DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - (ax == (iCount - 1) ? 1 : 0), COLOR4);

					if (g_Mouse.HasMouseOneJustBeenReleased())
					{
						bActiveDropDown[i] = false;
					}
				}

				if (ax == (iCount - 1))
					Draw::OutlinedRectangle(gayfag, e_y, DROPDOWN_WIDTH, (ax + 1) * DROPDOWN_HEIGHT, COLOR3);

				if (*cvar == fValues[ax])
				{
					Draw::RenderText(string_x, e_y + (ax * DROPDOWN_HEIGHT), COLOR9, true, Fonts::m_ListItemFont, ppszNames[ax]);
				}
				else
				{
					Draw::RenderText(string_x, e_y + (ax * DROPDOWN_HEIGHT), COLOR10, true, Fonts::m_ListItemFont, ppszNames[ax]);
				}
			}
		}
		else
		{
			if (g_Mouse.IsOver(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
			{
				if (!g_Menu.IsHandlingItem())
					g_Menu.AddMenuFlag(FL_DISABLEDRAG);

				Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR5);

				if (g_Mouse.HasMouseOneJustBeenReleased() && (dwWait < GetTickCount() || iWhich == -1))
				{
					bActiveDropDown[i] = true;
				}
			}
			else
				Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR4);

			Draw::OutlinedRectangle(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT, COLOR3);

			int string_x = gayfag + (DROPDOWN_WIDTH * 0.5);
			int string_y = e_y;

			for (int ax = 0; ax < iCount; ax++)
			{
				if (*cvar == fValues[ax])
				{
					Draw::RenderText(string_x, string_y, COLOR10, true, Fonts::m_ListItemFont, ppszNames[ax]);
					break;
				}
			}
		}
	}

	ClearAllElementSpecifics();
}

int GetPressedKey()
{
	for (int i = 1; i < 256; i++)
	{
		if (GetAsyncKeyState(i) & 0x8000)
			return i;
	}
	return -1;
}

const char* ExplainKey(int vk)
{
	static char explaination[16] = { 0 };

    #define	DenyVK(_key) if (vk == _key) return explaination

	DenyVK(VK_INSERT);

	if (char exp = MapVirtualKey(vk, MAPVK_VK_TO_CHAR) & 255)
	{
		if (exp == 32)
			return "Space";
		else if (exp == '\t')
			return "Tab";
		else if (exp == '\b')
			return "Backspace";
		else if (exp == '\n' || exp == '\r')
			return "Enter";
		else
			sprintf(explaination, "%c", exp);
	}
	else
	{
		switch (vk)
		{
		case VK_LBUTTON:	return "LMB";
		case VK_RBUTTON:	return "RMB";
		case VK_MBUTTON:	return "Wheel";
		case VK_XBUTTON1:	return "X1";
		case VK_XBUTTON2:	return "X2";
		case VK_INSERT:		return "Ins";
		case VK_DELETE:		return "Del";
		case VK_LSHIFT:		return "L Shift";
		case VK_RSHIFT:		return "R Shift";
		case VK_LMENU:		return "L Alt";
		case VK_RMENU:		return "R Alt";
		case VK_LCONTROL:	return "L Ctrl";
		case VK_RCONTROL:	return "R Ctrl";
		}
	}

	return explaination;
}

void cMenuSection::AddElement(int iType, int add_to_x, int add_to_y, const char *pszElementName, float *cvar, float min, float max, float step)
{
	int e_x = s_x + 10 + add_to_x;
	int e_y = s_y + 15 + (iSection * ELEMENT_SEPERATION) + add_to_y;

	bool bDropDownActive = false;

	for (int i2 = 0; i2 < 50; i2++)
	{
		bDropDownActive = bActiveDropDown[i2];

		if (bDropDownActive)
			break;
	}

	int notgay;

	if (add_to_x = iRowThree)
	{
		notgay = +3;
	}
	
	if (iType == ONOFF)
	{
		Draw::RenderText(e_x - notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_x += CHECKBOX_SEPERATION_FROM_TEXT;

		if (g_Mouse.OneLeftClick(e_x - 3, e_y - 3, CHECKBOX_SIZE + 5, CHECKBOX_SIZE + 5) && !bDropDownActive)
			*cvar = !*cvar;

		e_y += 1;

		Draw::GradientVertical(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, 15, 15, 15, 140, 35, 35, 35);

		if (*cvar)
		{
			Draw::GradientVertical(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, 35, 35, 35, 220, gCvars.colorsredone, gCvars.colorsgreenone, gCvars.colorsblueone);
		}

		if (g_Mouse.IsOver(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE))
		{
			Draw::OutlinedRectangle(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, COLOR9);

			if (!g_Menu.IsHandlingItem())
				g_Menu.AddMenuFlag(FL_DISABLEDRAG);
		}
		else
			Draw::OutlinedRectangle(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, 25,25,25,255);
	}
	else if (iType == DROPDOWN)
	{
		Draw::RenderText(e_x-notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_y += 1;

		DropDown_t ddNew;

		ddNew.x = e_x + CHECKBOX_SEPERATION_FROM_TEXT - 20;
		ddNew.y = e_y - 2;
		ddNew.fValues = fValueList;
		ddNew.cvar = cvar;
		ddNew.ppszNames = ppszValueNames;
		ddNew.iCount = iValueCount;

		AddDropDownToDrawList(ddNew);
	}
	else if (iType == SLIDER)
	{
		static int sliderlenght = 420;

		float Scale = max / 418;

		bool bOver = false;

		Draw::RenderText(e_x, e_y - 7, COLOR10, false, Fonts::m_WatermarkFont, "%s %2.2f", pszElementName, *cvar);

		e_y += 8;

		Draw::FillRGBA(e_x + 3, e_y + 6, sliderlenght, 2, 115, 120, 123, 185);

		int mouse_x, mouse_y;
		g_Mouse.GetMousePosition(mouse_x, mouse_y);

		if (mouse_x >= (e_x - 3) && mouse_x <= (e_x + sliderlenght + 3) && mouse_y >= (e_y) && mouse_y <= (e_y + 10) && GetAsyncKeyState(VK_LBUTTON) && (iSliderIndex == -1) && dwWait < GetTickCount() && !bSliderFix[iCurrSlider])
		{
			iSliderIndex = iCurrSlider;
			bSliderFix[iCurrSlider] = true;

			if (!g_Menu.IsHandlingItem())
				g_Menu.AddMenuFlag(FL_DISABLEDRAG);
		}

		if (mouse_x >= (e_x - 1000) && mouse_x <= (e_x + sliderlenght + 1000) && mouse_y >= (e_y - 1000) && mouse_y <= (e_y + 1000) && GetAsyncKeyState(VK_LBUTTON) && !bDropDownActive)
		{
			if (bSliderFix[iCurrSlider])
			{
				*cvar = min + (mouse_x - e_x) * Scale;

				bOver = true;

				if (!g_Menu.IsHandlingItem())
					g_Menu.AddMenuFlag(FL_DISABLEDRAG);
			}
		}
		else if (bSliderFix[iCurrSlider])
		{
			iSliderIndex = -1;
			bSliderFix[iCurrSlider] = false;
		}

		if (*cvar > max)
			*cvar = max;

		if (*cvar < min)
			*cvar = min;

		static int iSizeOf = 6;

		for (int nu = 0; nu <= iSizeOf; nu++)
		{
			Draw::FillRGBA(e_x + (*cvar / Scale) - iSizeOf + nu, e_y + iSizeOf - nu, (iSizeOf + 1) - nu, 1, COLOR4);
			Draw::FillRGBA(e_x + (*cvar / Scale) - iSizeOf + nu, e_y + iSizeOf + nu, (iSizeOf + 1) - nu, 1, COLOR4);
			Draw::FillRGBA(e_x + (*cvar / Scale), e_y + iSizeOf - nu, (iSizeOf + 1) - nu, 1, COLOR4);
			Draw::FillRGBA(e_x + (*cvar / Scale), e_y + iSizeOf + nu, (iSizeOf + 1) - nu, 1, COLOR4);
		}

		if (g_Mouse.IsOver(e_x + (*cvar / Scale) - iSizeOf, e_y - 1, 10, 14) || bOver)
		{
			Draw::RenderLine(e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y - 1, COLOR9);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y - 1, e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, COLOR9);
			Draw::RenderLine(e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), COLOR9);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, COLOR9);
		}
		else
		{
			Draw::RenderLine(e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y - 1, COLOR6);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y - 1, e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, COLOR6);
			Draw::RenderLine(e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), COLOR6);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, COLOR6);
		}
	}
	else if (iType == ADDER)
	{
		int gayfag = e_x - 1;

		Draw::RenderText(e_x-notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_y += 1;

		gayfag += (CHECKBOX_SEPERATION_FROM_TEXT - 20);

		Draw::FillRGBA(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR7);

		if (g_Mouse.IsOver(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY))
		{
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR9);

			if (g_Mouse.HasMouseOneJustBeenReleased() && !bDropDownActive)
				*cvar -= step;

			if (g_Mouse.IsMouseTwoBeingHeld() && !bDropDownActive)
				*cvar -= 1;
		}
		else
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR4);

		Draw::RenderText(gayfag + ADDER_SIZEX * 0.5, e_y - 1, COLOR9, true, Fonts::m_ListItemFont, "<");

		Draw::RenderText(gayfag - 7 + ADDER_SIZEX + ADDER_SEPERATE_FROM_BOXES * 0.5, e_y - 2, COLOR10, true, Fonts::m_WatermarkFont, "%2.0f", *cvar);

		gayfag += ADDER_SEPERATE_FROM_BOXES;

		Draw::FillRGBA(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR7);

		if (g_Mouse.IsOver(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY))
		{
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR9);

			if (g_Mouse.HasMouseOneJustBeenReleased() && !bDropDownActive)
				*cvar += step;

			if (g_Mouse.IsMouseTwoBeingHeld() && !bDropDownActive)
				*cvar += 1;
		}
		else
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR4);

		Draw::RenderText(gayfag + ADDER_SIZEX * 0.5, e_y - 1, COLOR9, true, Fonts::m_ListItemFont, ">");


		if (*cvar < min)
			*cvar = max;

		if (*cvar > max)
			*cvar = min;
	}
	else if (iType == KEYBIND)
	{
		Draw::RenderText(e_x-notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_y - 2;

		int gayfag = e_x + CHECKBOX_SEPERATION_FROM_TEXT - 21;

		int PressedKey = GetPressedKey();

		if (g_Mouse.IsOver(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
		{
			if (PressedKey > 0 && PressedKey != 0x57 && PressedKey != 0x53 && PressedKey != 0x44 && PressedKey != 0x41 && PressedKey != 0x20 && PressedKey != 0x10 && PressedKey != 0xA0 && PressedKey != 0xA1 && PressedKey != 0x11 && PressedKey != 0xA2 && PressedKey != 0xA3 && PressedKey != VK_INSERT)
				*cvar = PressedKey;
		}

		if (g_Mouse.IsOver(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
		{
			if (!g_Menu.IsHandlingItem())
				g_Menu.AddMenuFlag(FL_DISABLEDRAG);

			Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR5);
		}
		else
			Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR4);

		Draw::SoftOutlinedRectangle(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT, COLOR3);

		int string_x = gayfag + (DROPDOWN_WIDTH * 0.5);
		int string_y = e_y;

		Draw::RenderText(string_x, string_y, COLOR10, true, Fonts::m_WatermarkFont, ExplainKey(*cvar));
	}

	PostElement((iType == SLIDER ? 2 : 1));
}