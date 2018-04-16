#include "game_system.h"
#include "set_cursor.h"
#include <stdio.h>

bool game_start = false;

bool game_system::getgame_start(){
	return game_start;
}

void game_system::setgame_test(bool game_test){
	this->game_test = game_test;
}

bool game_system::getgame_test(){
	return game_test;
}

void game_system::game_system_seting(int game_form_width, int game_form_height, int game_form_top, int game_form_left){
	this->game_form_width = game_form_width;
	this->game_form_height = game_form_height;
	this->game_form_top = game_form_top;
	this->game_form_left = game_form_left;
	game_start = false;
	game_test = false;
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
