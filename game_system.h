class game_system
{
private:
	int game_form_width;				//�C�������e�� 
	int game_form_height;				//�C���������� 
	int game_form_top;					//�C�����������_�l��m 
	int game_form_left;					//�C�������V���}�l�⪺�_�l��m 
	bool game_start;					//�����C���ϧ_�}�l(���b�B��) 
	bool game_test;						//�����O�_�b���ժ��A 
	bool game_over;						//�C���������������� 
	bool setting_snake_control;			//�O�_�����o���s����� 
	bool windows_snake_body[150][50];	
	int snake_data[3080][2];
	int snake_lenght;
	int snake_control;
	int snake_set_top;
	int snake_set_left;
	int snake_speed;
	int cookie[2][2];
	
	void game_create_cookie();
	void game_eat_cookie();
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
