

struct playerinfo
{
	char m_name[128];
	int userid;
	int m_nUserID;
	char guid[32 + 1];
	unsigned int friendsid;
	char friendsname[32 + 96];
	bool fakeplayer;
	bool ishltv;
	unsigned int customfiles[4];
	unsigned char filesdownloaded;
};

struct EngineClient
{
	void GetScreenSize(int& width, int& height)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, int&, int&);
		return getvfunc<OriginalFn>(this, 5)(this, width, height);
	}

	bool GetPlayerInfo(int iIndex, playerinfo *pInfo)
	{
		typedef bool(__thiscall* OriginalFn)(PVOID, int, playerinfo*);
		return getvfunc<OriginalFn>(this, 8)(this, iIndex, pInfo);
	}

	int GetLocalPlayer()
	{
		typedef int(__thiscall* OriginalFn)(PVOID);
		return getvfunc<OriginalFn>(this, 12)(this);
	}

	void GetViewAngles(Vector& vAngles)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, Vector&);
		return getvfunc< OriginalFn >(this, 19)(this, vAngles);
	}

	void SetViewAngles(Vector& vAngles)
	{
		typedef void(__thiscall* oSetViewAngles)(PVOID, Vector&);
		return getvfunc< oSetViewAngles >(this, 20)(this, vAngles);
	}

	int GetMaxClients()
	{
		typedef bool(__thiscall* oGetMaxClients)(PVOID);
		return getvfunc< oGetMaxClients >(this, 21)(this);
	}

	const matrix3x4& WorldToScreenMatrix()
	{
		typedef const matrix3x4& (__thiscall* oWorldToScreenMatrix)(PVOID);
		return getvfunc< oWorldToScreenMatrix >(this, 36)(this);
	}
};

struct EntityList
{
	Entities* GetClientEntity(int entnum)
	{
		typedef Entities* (__thiscall* OriginalFn)(PVOID, int);
		return getvfunc<OriginalFn>(this, 3)(this, entnum);
	}
	Entities *GetClientEntityFromHandle(HANDLE hEnt)
	{
		typedef Entities* (__thiscall* OriginalFn)(PVOID, HANDLE);
		return getvfunc<OriginalFn>(this, 4)(this, hEnt);
	}
};

struct CLient
{
	ClientClass* GetAllClasses()
	{
		typedef ClientClass* (__thiscall* OriginalFn)(PVOID);
		return getvfunc<OriginalFn>(this, 8)(this);
	}
};
