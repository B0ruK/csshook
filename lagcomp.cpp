#include "include.hpp"


namespace backtrack 
{
	std::vector<saved_ticks> player_ticks[64];

	void save_ticks(Entities* local_player, UserCmd* cmd) 
	{
		for (int i = 1; i <= pEngine->GetMaxClients(); i++) 
		{
			auto entity = pEntList->GetClientEntity(i);

			if (!entity || !entity->GetHealth() || entity->GetTeamNum() == local_player->GetTeamNum()) 
			{
				continue;
			}

			player_ticks[i].insert(player_ticks[i].begin(), { cmd->tick_count, entity->GetBonePos(gCvars.AimSpot) });

			if (player_ticks[i].size() > 12) 
			{
				player_ticks[i].pop_back();
			}
		}
	}

	void set_backtrack_tick(Entities* local_player, UserCmd* cmd) 
	{
		auto max_delta = FLT_MAX;
		auto best_index = -1;
		for (int i = 1; i <= pEngine->GetMaxClients(); i++) 
		{
			auto entity = pEntList->GetClientEntity(i);

			if (!entity || !entity->GetHealth() || entity->GetTeamNum() == local_player->GetTeamNum())
			{
				continue;
			}

			float delta = (Math::MakeVector(local_player->GetEyePosition(), entity->GetEyePosition()) - cmd->viewangles).Length();

			if (delta < max_delta) 
			{
				best_index = i;
				max_delta = delta;
			}
		}

		if (best_index == -1) {
			return;
		}

		int best_tick = -1;
		max_delta = FLT_MAX;
		for (int i = 0; i < player_ticks[best_index].size(); i++) 
		{
			float delta = (Math::MakeVector(local_player->GetEyePosition(), player_ticks[best_index].at(i).head_position) - cmd->viewangles).Length();
			if (delta < max_delta) {
				max_delta = delta;
				best_tick = i;
			}
		}

		if (best_tick != -1 && cmd->buttons & IN_ATTACK) {
			cmd->tick_count = player_ticks[best_index].at(best_tick).tick_number;
		}
	}
}