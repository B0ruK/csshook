
#include "misc.hpp"

void DoStuff(UserCmd* pUserCmd)
{
	Entities* pLocal = pEntList->GetClientEntity(pEngine->GetLocalPlayer());

	if (!pLocal)
		return;

	if (!pLocal->IsAlive())
		return;

	if (gCvars.Bunnyhop)
	{
		RunBhop(pUserCmd, pLocal);
	}

	float fCurTime = pGlobalVars->pertick * (pLocal->GetTickBase() + 1);

	Entities* pWeapon = (Entities*)pEntList->GetClientEntityFromHandle(pLocal->GetActiveWeapon());

	if (!pWeapon || !pWeapon->HasAmmo())
		return;

	int weaponid = pWeapon->GetItemDefinitionIndex();

	if (!IsAimWep(weaponid) && !IsRecoilWep(weaponid))
		return;

	if (gCvars.trigenable)
	{
		if (GetAsyncKeyState(gCvars.triggerkey) & 1)
			gCvars.triglol = !gCvars.triglol;

		if (gCvars.triglol)
		{
			g_aimbot.triggerbot(pUserCmd, pLocal,weaponid);
		}
	}

	if (!gCvars.legitenable)
		return;

	if (gCvars.lagcomp)
	{
		backtrack::save_ticks(pLocal,pUserCmd);
		backtrack::set_backtrack_tick(pLocal,pUserCmd);
	}

	if (gCvars.autopistol)
	{
		AutoPistols(pUserCmd, pLocal, pWeapon,fCurTime);
	}

	if (!gCvars.RCSASSIST)
	{
		g_aimbot.Main(pUserCmd, pLocal);
	}

	if (gCvars.RCSASSIST)
	{
		if (IsRecoilWep(weaponid))
		{
			g_aimbot.Main_RCS(pUserCmd, pLocal);
		}

		if (IsAimWep(weaponid))
		{
			g_aimbot.Main(pUserCmd, pLocal);
		}
	}

	Math::ClampAngles(pUserCmd->viewangles);
}