
#include "cmove.hpp"

template<typename T> inline T get_BP()
{
	__asm mov eax, ebp
}

template<typename T> inline T get_SI()
{
	__asm mov eax, esi
}


using SetViewAngleFn = void(__stdcall*)(Vector &);
SetViewAngleFn org_SetViewAngles = nullptr;

void __stdcall hooked_SetViewAngles(Vector &angles)
{
	UserCmd* cmd = get_SI<UserCmd*>();
	unsigned* sequence_number = (*get_BP<unsigned**>() + 2);

	org_SetViewAngles(angles);

	if (cmd && cmd->command_number == *sequence_number)
	{
		DoStuff(cmd);

		*sequence_number = cmd->command_number;
	}
}
