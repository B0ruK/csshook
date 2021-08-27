

namespace CfgSystem
{
	void LoadCfg(bool,bool);
	void SaveCFG(bool,bool);
}

class CGlobalVariables
{
public:
	bool bMenu = false;
	bool triglol = false;
	float Smoothnessyaw;
	float Smoothnesspitch;
	float legitenable;
	float RCSASSIST;
	float AimTeam;
	float AimFOV;
	float AimSpot;
	float Bunnyhop;
	float inattack;
	float radar;
	float velocity;
	float watermark;
	float triggerkey;
	float skinchanger;
	float skinselection;
	float trigenable;
	float trighead;
	float triggerbody;
	float trigerdelay;
	float trigteam;
	float autopistol;
	float espbox;
	float healthbar;
	float chams;
	float XQZ;
	float radarsize;
	float radarrange = 40;
	float radarteam;
	float radarnames;
	float flRadarPos_x = 120;
	float flRadarPos_y = 120;
	float RCSFOV;
	float RCSSMOOTH;
	float lagcomp;
	float colorsredone = 254;
	float colorsgreenone = 254;
	float colorsblueone = 0;
	float colorsredtwo = 168;
	float colorsgreentwo = 216;
	float colorsbluetwo = 236;
	float colorsredTHREE = 254;
	float colorsgreenTHREE = 254;
	float colorsblueTHREE = 254;
	float colorsredFOUR = 168;
	float colorsgreenFOUR = 216;
	float colorsblueFOUR = 236;
	float colorsredFIVE = 251;
	float colorsgreenFIVE = 219;
	float colorsblueFIVE = 73;
	float esprenderdist;
	float recoilxhair;
	float drawmonitor;
	float f1monitorpos_x = 400;
	float f1monitorpos_y = 400;
	float espname;
	float espteam;
	float CHAMTEAM;
};

inline  CGlobalVariables gCvars;
