
struct COffsets
{
	struct
	{
		std::ptrdiff_t m_vecViewOffset;
		std::ptrdiff_t m_nTickBase;
		std::ptrdiff_t m_vecVelocity;
		std::ptrdiff_t m_iHealth;
		std::ptrdiff_t m_lifeState;
		std::ptrdiff_t m_fFlags;
	} DT_BasePlayer;

	struct
	{
		std::ptrdiff_t m_iTeamNum;
		std::ptrdiff_t m_vecOrigin;
	} DT_BaseEntity;

	struct
	{
		std::ptrdiff_t m_hActiveWeapon;
	} DT_BaseCombatCharacter;

	struct
	{
		std::ptrdiff_t m_iShotsFired;
		std::ptrdiff_t m_vecPunchAngle;
	} DT_CSPlayer;

	struct
	{
		std::ptrdiff_t m_flNextPrimaryAttack;
		std::ptrdiff_t m_iClip1;
	} DT_BaseCombatWeapon;

	struct
	{
		std::ptrdiff_t m_nForceBone;
	} DT_BaseAnimating;
};

namespace Offsets
{
	void GetOffsets();
}

inline COffsets offsets;
