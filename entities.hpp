
template <typename t>
t getvfunc(void* class_pointer, size_t index)
{
	return (*(t**)class_pointer)[index];
}

struct Entities
{
	void* GetNetworkable()
	{
		typedef void* (__thiscall* GetNetworkableFn)(void*);
		return getvfunc< GetNetworkableFn >(this, 4)(this);
	}

	void* GetRenderable()
	{
		typedef void* (__thiscall* GetRenderableFn)(void*);
		return getvfunc< GetRenderableFn >(this, 5)(this);
	}

	bool IsDormant()
	{
		auto pNet = GetNetworkable();
		typedef bool(__thiscall* IsDormantFn)(void*);
		return getvfunc< IsDormantFn >(pNet, 8)(pNet);
	}

	bool SetupBones(matrix3x4* pOut)
	{
		auto pRen = GetRenderable();
		typedef bool(__thiscall* SetupBonesFn)(void*, matrix3x4*, int, int, float);
		return getvfunc< SetupBonesFn >(pRen, 16)(pRen, pOut, 128, 0x100, 0);
	}

	const Vector& GetAbsOrigin()
	{
		typedef const Vector& (__thiscall *GetAbsOrg_t)(PVOID);
		return getvfunc<GetAbsOrg_t>(this, 9)(this);
	}

	int GetItemDefinitionIndex()
	{
		return getvfunc<int(__thiscall*)(void*)>(this, 365)(this);
	}

	bool IsPlayer()
	{
		return getvfunc<bool(__thiscall*)(Entities*)>(this, 131)(this);
	}

	Vector GetOrigin()
	{
		return *(Vector*)((uintptr_t)this + offsets.DT_BaseEntity.m_vecOrigin);
	}

	int GetHealth()
	{
		return *(int*)((uintptr_t)this + offsets.DT_BasePlayer.m_iHealth);
	}

	unsigned char GetLifeState()
	{
		return *(unsigned char*)((uintptr_t)this + offsets.DT_BasePlayer.m_lifeState);
	}

	int GetTeamNum()
	{
		return *(int*)((uintptr_t)this + offsets.DT_BaseEntity.m_iTeamNum);
	}

	Vector GetAimPunchAngle()
	{
		return *(Vector*)((uintptr_t)this + offsets.DT_CSPlayer.m_vecPunchAngle);
	}

	int GetFlags()
	{
		return *(int*)((uintptr_t)this + offsets.DT_BasePlayer.m_fFlags);
	}

	Vector GetVecViewOffset()
	{
		return *(Vector*)((uintptr_t)this + offsets.DT_BasePlayer.m_vecViewOffset);
	}

	Vector GetEyePosition()
	{
		return GetAbsOrigin() + GetVecViewOffset();
	}

	Vector GetVelocity()
	{
		return *(Vector*)((uintptr_t)this + offsets.DT_BasePlayer.m_vecVelocity);
	}

	int GetShotsFired()
	{
		return *(int*)((uintptr_t)this + offsets.DT_CSPlayer.m_iShotsFired);
	}

	HANDLE GetActiveWeapon()
	{
		return *(HANDLE*)((uintptr_t)this + offsets.DT_BaseCombatCharacter.m_hActiveWeapon);
	}

	int GetTickBase()
	{
		return *(unsigned int*)((uintptr_t)this + offsets.DT_BasePlayer.m_nTickBase);
	}

	bool IsAlive()
	{
		return (GetLifeState() == 0 && GetHealth() > 0);
	}

	float GetNextPrimaryAttack()
	{
		return *(float*)((uintptr_t)this + offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack);
	}

	bool HasAmmo()
	{
		return ((*(PINT)((DWORD)this + offsets.DT_BaseCombatWeapon.m_iClip1)) > 0);
	}

	Vector GetBonePos(int boneIndex)
	{
		matrix3x4 BoneMatrix[128];

		if (!this->SetupBones(BoneMatrix))
		{
			return this->GetOrigin();
		}

		matrix3x4 hitbox = BoneMatrix[boneIndex];

		return Vector(hitbox[0][3], hitbox[1][3], hitbox[2][3]);
	}
};
