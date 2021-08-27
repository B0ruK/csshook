#include "include.hpp"

void CfgSystem::LoadCfg(bool left, bool right)
{
	static char path[MAX_PATH];
	std::string folder, file;

	if (left)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insolegit\\config.ini");

			folder = std::string(path) + "\\insolegit\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	if (right)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insorage\\config.ini");

			folder = std::string(path) + "\\insorage\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	CIniWriter writer(file.c_str());

	gCvars.Smoothnessyaw = writer.ReadFloat("Smoothnessyaw");
	gCvars.Smoothnesspitch = writer.ReadFloat("Smoothnesspitch");
	gCvars.legitenable = writer.ReadFloat("legitenable");
	gCvars.RCSASSIST = writer.ReadFloat("RCSASSIST");
	gCvars.AimTeam = writer.ReadFloat("AimTeam");
	gCvars.AimFOV = writer.ReadFloat("AimFOV");
	gCvars.AimSpot = writer.ReadFloat("AimSpot");
	gCvars.Bunnyhop = writer.ReadFloat("Bunnyhop");
	gCvars.inattack = writer.ReadFloat("inattack");
	gCvars.radar = writer.ReadFloat("radar");
	gCvars.velocity = writer.ReadFloat("velocity");
	gCvars.watermark = writer.ReadFloat("watermark");
	gCvars.triggerkey = writer.ReadFloat("triggerkey");
	gCvars.skinchanger = writer.ReadFloat("skinchanger");
	gCvars.skinselection = writer.ReadFloat("skinselection");
	gCvars.trigenable = writer.ReadFloat("trigenable");
	gCvars.trighead = writer.ReadFloat("trighead");
	gCvars.triggerbody = writer.ReadFloat("triggerbody");
	gCvars.trigerdelay = writer.ReadFloat("trigerdelay");
	gCvars.trigteam = writer.ReadFloat("trigteam");
	gCvars.autopistol = writer.ReadFloat("autopistol");
	gCvars.espbox = writer.ReadFloat("espbox");
	gCvars.healthbar = writer.ReadFloat("healthbar");
	gCvars.chams = writer.ReadFloat("chams");
	gCvars.XQZ = writer.ReadFloat("XQZ");
	gCvars.espteam = writer.ReadFloat("espteam");
	gCvars.radarsize = writer.ReadFloat("radarsize");
	gCvars.radarrange = writer.ReadFloat("radarrange");
	gCvars.radarteam = writer.ReadFloat("radarteam");
	gCvars.radarnames = writer.ReadFloat("radarnames");
	gCvars.RCSFOV = writer.ReadFloat("RCSFOV");
	gCvars.RCSSMOOTH = writer.ReadFloat("RCSSMOOTH");
	gCvars.lagcomp = writer.ReadFloat("lagcomp");
	gCvars.flRadarPos_x = writer.ReadFloat("flRadarPos_x");
	gCvars.flRadarPos_y = writer.ReadFloat("flRadarPos_y");
	gCvars.colorsredone = writer.ReadFloat("colorsredone");
	gCvars.colorsgreenone = writer.ReadFloat("colorsgreenone");
	gCvars.colorsblueone = writer.ReadFloat("colorsblueone");
	gCvars.colorsredtwo = writer.ReadFloat("colorsredtwo");
	gCvars.colorsgreentwo = writer.ReadFloat("colorsgreentwo");
	gCvars.colorsbluetwo = writer.ReadFloat("colorsbluetwo");
	gCvars.colorsredTHREE = writer.ReadFloat("colorsredTHREE");
	gCvars.colorsgreenTHREE = writer.ReadFloat("colorsgreenTHREE");
	gCvars.colorsblueTHREE = writer.ReadFloat("colorsblueTHREE");
	gCvars.colorsredFOUR = writer.ReadFloat("colorsredFOUR");
	gCvars.colorsgreenFOUR = writer.ReadFloat("colorsgreenFOUR");
	gCvars.colorsblueFOUR = writer.ReadFloat("colorsblueFOUR");
	gCvars.colorsredFIVE = writer.ReadFloat("colorsredFIVE");
	gCvars.colorsgreenFIVE = writer.ReadFloat("colorsgreenFIVE");
	gCvars.colorsblueFIVE = writer.ReadFloat("colorsblueFIVE");
	gCvars.esprenderdist = writer.ReadFloat("esprenderdist");
	gCvars.recoilxhair = writer.ReadFloat("recoilxhair");
	gCvars.drawmonitor = writer.ReadFloat("drawmonitor");
	gCvars.f1monitorpos_x = writer.ReadFloat("f1monitorpos_x");
	gCvars.f1monitorpos_y = writer.ReadFloat("f1monitorpos_y");
	gCvars.espname = writer.ReadFloat("espname");
	gCvars.espteam = writer.ReadFloat("espteam");
	gCvars.CHAMTEAM = writer.ReadFloat("CHAMTEAM");
}



void CfgSystem::SaveCFG(bool left, bool right)
{
	static char path[MAX_PATH];
	std::string folder, file;

	if (left)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insolegit\\config.ini");

			folder = std::string(path) + "\\insolegit\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	if (right)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insorage\\config.ini");

			folder = std::string(path) + "\\insorage\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	CIniWriter writer(file.c_str());

	writer.WriteFloat("Smoothnessyaw", gCvars.Smoothnessyaw);
	writer.WriteFloat("Smoothnesspitch", gCvars.Smoothnesspitch);
	writer.WriteFloat("legitenable", gCvars.legitenable);
	writer.WriteFloat("RCSASSIST", gCvars.RCSASSIST);
	writer.WriteFloat("AimTeam", gCvars.AimTeam);
	writer.WriteFloat("AimFOV", gCvars.AimFOV);
	writer.WriteFloat("AimSpot", gCvars.AimSpot);
	writer.WriteFloat("Bunnyhop", gCvars.Bunnyhop);
	writer.WriteFloat("inattack", gCvars.inattack);
	writer.WriteFloat("radar", gCvars.radar);
	writer.WriteFloat("velocity", gCvars.velocity);
	writer.WriteFloat("watermark", gCvars.watermark);
	writer.WriteFloat("triggerkey", gCvars.triggerkey);
	writer.WriteFloat("skinchanger", gCvars.skinchanger);
	writer.WriteFloat("skinselection", gCvars.skinselection);
	writer.WriteFloat("trigenable", gCvars.trigenable);
	writer.WriteFloat("trighead", gCvars.trighead);
	writer.WriteFloat("triggerbody", gCvars.triggerbody);
	writer.WriteFloat("trigerdelay", gCvars.trigerdelay);
	writer.WriteFloat("trigteam", gCvars.trigteam);
	writer.WriteFloat("autopistol", gCvars.autopistol);
	writer.WriteFloat("espbox", gCvars.espbox);
	writer.WriteFloat("healthbar", gCvars.healthbar);
	writer.WriteFloat("chams", gCvars.chams);\
	writer.WriteFloat("XQZ", gCvars.XQZ);
	writer.WriteFloat("espteam", gCvars.espteam);
	writer.WriteFloat("radarsize", gCvars.radarsize);
	writer.WriteFloat("radarrange", gCvars.radarrange);
	writer.WriteFloat("radarteam", gCvars.radarteam);
	writer.WriteFloat("radarnames", gCvars.radarnames);
	writer.WriteFloat("RCSFOV", gCvars.RCSFOV);
	writer.WriteFloat("RCSSMOOTH", gCvars.RCSSMOOTH);
	writer.WriteFloat("lagcomp", gCvars.lagcomp);
	writer.WriteFloat("flRadarPos_x", gCvars.flRadarPos_x);
	writer.WriteFloat("flRadarPos_y", gCvars.flRadarPos_y);
	writer.WriteFloat("colorsredone", gCvars.colorsredone);
	writer.WriteFloat("colorsgreenone", gCvars.colorsgreenone);
	writer.WriteFloat("colorsblueone", gCvars.colorsblueone);
	writer.WriteFloat("colorsredtwo", gCvars.colorsredtwo);
	writer.WriteFloat("colorsgreentwo", gCvars.colorsgreentwo);
	writer.WriteFloat("colorsbluetwo", gCvars.colorsbluetwo);
	writer.WriteFloat("colorsredTHREE", gCvars.colorsredTHREE);
	writer.WriteFloat("colorsgreenTHREE", gCvars.colorsgreenTHREE);
	writer.WriteFloat("colorsblueTHREE", gCvars.colorsblueTHREE);
	writer.WriteFloat("colorsredFOUR", gCvars.colorsredFOUR);
	writer.WriteFloat("colorsgreenFOUR", gCvars.colorsgreenFOUR);
	writer.WriteFloat("colorsblueFOUR", gCvars.colorsblueFOUR);
	writer.WriteFloat("colorsredFIVE", gCvars.colorsredFIVE);
	writer.WriteFloat("colorsgreenFIVE", gCvars.colorsgreenFIVE);
	writer.WriteFloat("colorsblueFIVE", gCvars.colorsblueFIVE);
	writer.WriteFloat("esprenderdist", gCvars.esprenderdist);
	writer.WriteFloat("recoilxhair", gCvars.recoilxhair);
	writer.WriteFloat("drawmonitor", gCvars.drawmonitor);
	writer.WriteFloat("f1monitorpos_x", gCvars.f1monitorpos_x);
	writer.WriteFloat("f1monitorpos_y", gCvars.f1monitorpos_y);
	writer.WriteFloat("espname", gCvars.espname);
	writer.WriteFloat("espteam", gCvars.espteam);
	writer.WriteFloat("CHAMTEAM", gCvars.CHAMTEAM);
}
