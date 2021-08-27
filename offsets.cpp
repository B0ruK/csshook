#include "include.hpp"

void Offsets::GetOffsets()
{
	std::vector<RecvTable *> tables = NetVarManager::GetTables();

	offsets.DT_BasePlayer.m_vecViewOffset = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_vecViewOffset[0]");
	offsets.DT_BasePlayer.m_nTickBase = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_nTickBase");
	offsets.DT_BasePlayer.m_vecVelocity = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_vecVelocity[0]");
	offsets.DT_BasePlayer.m_iHealth = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_iHealth");
	offsets.DT_BasePlayer.m_lifeState = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_lifeState");
	offsets.DT_BasePlayer.m_fFlags = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_fFlags");
	offsets.DT_BaseEntity.m_iTeamNum = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_iTeamNum");
	offsets.DT_BaseCombatCharacter.m_hActiveWeapon = NetVarManager::GetOffset(tables, "DT_BaseCombatCharacter", "m_hActiveWeapon");
	offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack = NetVarManager::GetOffset(tables, "DT_BaseCombatWeapon", "m_flNextPrimaryAttack");
	offsets.DT_BaseCombatWeapon.m_iClip1 = NetVarManager::GetOffset(tables, "DT_BaseCombatWeapon", "m_iClip1");
	offsets.DT_BaseEntity.m_vecOrigin = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_vecOrigin");
	offsets.DT_CSPlayer.m_iShotsFired = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_iShotsFired");
	offsets.DT_CSPlayer.m_vecPunchAngle = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_vecPunchAngle");
	offsets.DT_BaseAnimating.m_nForceBone = NetVarManager::GetOffset(tables, "DT_BaseAnimating", "m_nForceBone");
}
