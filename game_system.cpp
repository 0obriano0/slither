#include "game_system.h"
#include "windows_Console.h"
#include "set_cursor.h"
#include "UI.h"
#include <stdio.h>

int game_system::getsnake_control(){
	return snake_control;
}

void game_system::setsnake_control(int snake_control){
	this->snake_control = snake_control;
	snake_set_top = 0;
	snake_set_left = 0;
	switch(snake_control){
		case 1:
			snake_set_top = -1;
			break;
		case 2:
			snake_set_top = 1;
			break;
		case 3:
			snake_set_left = -1;
			break;
		case 4:
			snake_set_left = 1;
			break;
	}
}

bool game_system::getgame_start(){
	return game_start;
}

void game_system::setgame_test(bool game_test){
	this->game_test = game_test;
}

bool game_system::getgame_test(){
	return game_test;
}

bool game_system::getsetting_snake_control(){
	return setting_snake_control;
}

void game_system::game_system_seting(int game_form_width, int game_form_height, int game_form_top, int game_form_left){
	this->game_form_width = game_form_width;
	this->game_form_height = game_form_height;
	this->game_form_top = game_form_top;
	this->game_form_left = game_form_left;
	game_start = false;
	game_test = false;
	setting_snake_control = false;
}

void game_system::test(){
	game_test = true;
	set_cursor sc;
	for(int loopnum1 = 0; loopnum1 < game_form_height; loopnum1++){
		sc.gotoxy(game_form_left,game_form_top+loopnum1);
		for(int loopnum2 = 0; loopnum2 < game_form_width; loopnum2++){
			printf(">");
		}
	}
	char str[] = "    請按 \"esc\" 來回上頁    ";
	int L = strlen(str);
	sc.gotoxy(game_form_left+(game_form_width-L)/2,game_form_top+(game_form_height-1)/2); //算出文字位子 等於 （螢幕長度-字串長度）/2
	printf("%s",str); 
}

void game_system::game_start_function(){
	//遊戲設定 
	game_start = true;
	windows_Console win_c;
	win_c.Clr();
	UI UI;
	UI.base();
	set_cursor sc;
	char snake[] = "          ";
	snake_lenght = strlen(snake);
	sc.gotoxy(game_form_left+(game_form_width-snake_lenght)/2,game_form_top+(game_form_height-1)/2); //算出文字位子 等於 （螢幕長度-字串長度）/2
	UI.SetColor(7,7);
	printf("%s",snake);
	UI.SetColor(7,0);
	for(int loopnum1 = 0; loopnum1 < snake_lenght; loopnum1++){
		snake_data[loopnum1][0] = game_form_left+(game_form_width-snake_lenght)/2+loopnum1;
		snake_data[loopnum1][1] = game_form_top+(game_form_height-1)/2;
	}
	
	//開始遊戲區域 
	while(1){
		sc.gotoxy(snake_data[snake_lenght-1][0]-1,snake_data[snake_lenght-1][1]);
		printf("  ");
		for(int loopnum2 = snake_lenght-1; loopnum2 >= 2;loopnum2--){
			snake_data[loopnum2][0] = snake_data[loopnum2-2][0];
			snake_data[loopnum2][1] = snake_data[loopnum2-2][1];
		}
		
		sc.gotoxy(snake_data[2][0]+2*snake_set_left,snake_data[2][1]+snake_set_top);
		UI.SetColor(7,7);
		printf("  ");
		UI.SetColor(7,0);
		setting_snake_control = true;
		for(int loopnum3 = 0; loopnum3 < 2;loopnum3++){
			snake_data[loopnum3][0] = snake_data[2][0]+((snake_set_left == 1)?2+loopnum3:2-loopnum3)*snake_set_left+abs(snake_set_top)*loopnum3;
			snake_data[loopnum3][1] = snake_data[2][1]+snake_set_top;
		}
		setting_snake_control = false;
		Sleep(500);
	}
	game_start = false;
}
