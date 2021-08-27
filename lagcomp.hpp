


struct saved_ticks 
{
	saved_ticks(int tick_number, Vector head_positon) {
		this->tick_number = tick_number;
		this->head_position = head_positon;
	}

	int tick_number = -1;
	Vector head_position = { 0, 0, 0 };
};

namespace backtrack 
{
	void save_ticks(Entities* local_player, UserCmd* cmd);

	void set_backtrack_tick(Entities* local_player, UserCmd* cmd);

	extern std::vector<saved_ticks> player_ticks[64];
}