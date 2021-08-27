


void RunBhop(UserCmd* cmd, Entities* pLocal)
{
	static bool jumped_last_tick = false;
	static bool should_fake_jump = false;

	if (!jumped_last_tick && should_fake_jump)
	{
		should_fake_jump = false;
		cmd->buttons |= IN_JUMP;
	}
	else if (cmd->buttons & IN_JUMP)
	{
		if (pLocal->GetFlags() & FL_ONGROUND)
		{
			jumped_last_tick = true;
			should_fake_jump = true;
		}
		else
		{
			cmd->buttons &= ~IN_JUMP;
			jumped_last_tick = false;
		}
	}
	else
	{
		jumped_last_tick = false;
		should_fake_jump = false;
	}
}


void AutoPistols(UserCmd* pUserCmd,Entities* pLocal,Entities* weapon,float curtime)
{
	float fNextPrimary = weapon->GetNextPrimaryAttack();

	bool bCanFire = true;

	static bool bOldBullet;

	if ((fNextPrimary > curtime) || bOldBullet)
		bCanFire = false;

	if (!(fNextPrimary > curtime))
		bOldBullet = false;

	if ((pUserCmd->buttons & IN_ATTACK))
	{
		if (bCanFire)
			bOldBullet = true;
		else
		{
			pUserCmd->buttons &= ~IN_ATTACK;
		}
	}
}