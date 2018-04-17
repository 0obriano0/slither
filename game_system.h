class game_system
{
private:
	int game_form_width;
	int game_form_height;
	int game_form_top;
	int game_form_left;
	bool game_start;
	bool game_test;
	bool game_over;
	bool setting_snake_control;
	int snake_data[100][2];
	int snake_lenght;
	int snake_control;
	int snake_set_top;
	int snake_set_left;
protected:
	
public:
	void setsnake_control(int snake_control);
	int getsnake_control();
	bool getgame_start();
	void setgame_over(bool game_over);
	bool getgame_over();
	void setgame_test(bool game_test);
	bool getgame_test();
	bool getsetting_snake_control();
	void game_system_seting(int game_form_width, int game_form_height, int game_form_top, int game_form_left);
	void test();
	void game_start_function();
};
