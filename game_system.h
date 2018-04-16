class game_system
{
private:
	int game_form_width;
	int game_form_height;
	int game_form_top;
	int game_form_left;
	bool game_start;
	bool game_test;
protected:
	
public:
	bool getgame_start();
	void setgame_test(bool game_test);
	bool getgame_test();
	void game_system_seting(int game_form_width, int game_form_height, int game_form_top, int game_form_left);
	void test();
};
