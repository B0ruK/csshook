
struct GlobalVars
{
	float realtime;
	int framecount;
	float absoluteframetime;
	float curtime;
	float frametime;
	int maxclients;
	int tickcount;
	float pertick;
};

struct UserCmd
{
	BYTE      Pad[4];
	int command_number;
	int tick_count;
	Vector viewangles;
	float forwardmove;
	float sidemove;
	float upmove;
	int	buttons;
};