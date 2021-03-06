
enum  WeaponIndx
{
	WEAPON_NULL,
	WEAPON_P228,
	WEAPON_GLOCK,
	WEAPON_SCOUT,
	WEAPON_HE_GRENADE,
	WEAPON_XM1014,
	WEAPON_C4,
	WEAPON_MAC10,
	WEAPON_AUG,
	WEAPON_SMOKE_GRENADE,
	WEAPON_ELITES,
	WEAPON_FIVESEVEN,
	WEAPON_UMP,
	WEAPON_SG550,
	WEAPON_GALIL,
	WEAPON_FAMAS,
	WEAPON_USP,
	WEAPON_AWP,
	WEAPON_MP5,
	WEAPON_M249,
	WEAPON_M3,
	WEAPON_M4A1,
	WEAPON_TMP,
	WEAPON_G3SG1,
	WEAPON_FLASHBANG,
	WEAPON_DEAGLE,
	WEAPON_SG552,
	WEAPON_AK47,
	WEAPON_KNIFE,
	WEAPON_P90
};

inline bool IsRecoilWep(int iWpnID)
{
	return (iWpnID == WEAPON_MAC10
		|| iWpnID == WEAPON_AUG
		|| iWpnID == WEAPON_ELITES
		|| iWpnID == WEAPON_SG550
		|| iWpnID == WEAPON_GALIL
		|| iWpnID == WEAPON_FAMAS
		|| iWpnID == WEAPON_MP5
		|| iWpnID == WEAPON_M249
		|| iWpnID == WEAPON_M4A1
		|| iWpnID == WEAPON_TMP
		|| iWpnID == WEAPON_SG552
		|| iWpnID == WEAPON_AK47
		|| iWpnID == WEAPON_P90
		|| iWpnID == WEAPON_UMP);
}

inline bool IsAimWep(int iWpnID)
{
	return (iWpnID == WEAPON_P228
		|| iWpnID == WEAPON_GLOCK
		|| iWpnID == WEAPON_SCOUT
		|| iWpnID == WEAPON_USP
		|| iWpnID == WEAPON_G3SG1
		|| iWpnID == WEAPON_DEAGLE
		|| iWpnID == WEAPON_AWP
		|| iWpnID == WEAPON_M3
		|| iWpnID == WEAPON_XM1014
		|| iWpnID == WEAPON_FIVESEVEN);
}