#include "game_system.h"
#include "windows_Console.h"
#include "set_cursor.h"
#include "UI.h"
#include <stdio.h>
#include <time.h>
#include <math.h> 

int game_system::getsnake_control(){
	return snake_control;
}

void game_system::setsnake_control(int snake_control){
	setting_snake_control = true;
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

void game_system::setgame_over(bool game_over){
	this->game_over = game_over;
}

bool game_system::getgame_over(){
	return game_over;
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
	for(int loopnum1 = 0; loopnum1 < 150; loopnum1++)
		for(int loopnum2 = 0; loopnum2 < 150; loopnum2++)
			windows_snake_body[loopnum1][loopnum2] = false;
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
	//紀錄蛇的身體位置 
	for(int loopnum1 = 0; loopnum1 < 150; loopnum1++)
		for(int loopnum2 = 0; loopnum2 < 150; loopnum2++)
			windows_snake_body[loopnum1][loopnum2] = false;
	snake_speed = 200;
	game_start = true;
	windows_Console win_c;
	win_c.Clr();
	UI UI;
	UI.base();
	set_cursor sc;
	char snake[] = "          ";//蛇的初始身體長度，以兩個空白為一個單位 
	snake_lenght = strlen(snake);
	sc.gotoxy(game_form_left+(game_form_width-snake_lenght)/2,game_form_top+(game_form_height-1)/2); //算出文字位子 等於 （螢幕長度-字串長度）/2
	UI.SetColor(8,8);
	printf("%s",snake);
	UI.SetColor(7,0);
	for(int loopnum1 = 0; loopnum1 < snake_lenght; loopnum1++){
		snake_data[loopnum1][0] = game_form_left+(game_form_width-snake_lenght)/2+loopnum1;
		snake_data[loopnum1][1] = game_form_top+(game_form_height-1)/2;
		windows_snake_body[snake_data[loopnum1][0]][snake_data[loopnum1][1]] = true;
	}
	
	game_create_cookie();
	
	//開始遊戲區域 
	while(1){
		setting_snake_control = true;
		
		if(snake_control == 1){
			if(snake_data[0][1] == game_form_top || windows_snake_body[snake_data[0][0]][snake_data[0][1]-1])
				break;
			else if(snake_data[0][1]-1 == cookie[0][1] && snake_data[0][0] == cookie[0][0])
				game_eat_cookie(); 
		}else if(snake_control == 2){
			if(snake_data[0][1] == game_form_top+game_form_height-1 || windows_snake_body[snake_data[0][0]][snake_data[0][1]+1])
				break;
			else if(snake_data[0][1]+1 == cookie[0][1] && snake_data[0][0] == cookie[0][0])
				game_eat_cookie();
		}else if(snake_control == 3){
			if(snake_data[0][0] == game_form_left || windows_snake_body[snake_data[0][0]-1][snake_data[0][1]])
				break;
			else if(snake_data[0][0]-1 == cookie[1][0] && snake_data[0][1] == cookie[0][1])
				game_eat_cookie();
		}else if(snake_control == 4){
			if(snake_data[1][0] == game_form_left+game_form_width-1 || windows_snake_body[snake_data[1][0]+1][snake_data[1][1]])
				break;
			else if(snake_data[1][0]+1 == cookie[0][0] && snake_data[0][1] == cookie[0][1])
				game_eat_cookie();
		}
	
		sc.gotoxy(snake_data[snake_lenght-2][0],snake_data[snake_lenght-2][1]);
		windows_snake_body[snake_data[snake_lenght-1][0]][snake_data[snake_lenght-1][1]] = false;
		windows_snake_body[snake_data[snake_lenght-2][0]][snake_data[snake_lenght-2][1]] = false;
		printf("  ");
		for(int loopnum2 = snake_lenght-1; loopnum2 >= 2;loopnum2--){
			snake_data[loopnum2][0] = snake_data[loopnum2-2][0];
			snake_data[loopnum2][1] = snake_data[loopnum2-2][1];
		}
		
		sc.gotoxy(snake_data[2][0]+2*snake_set_left,snake_data[2][1]+snake_set_top);
		UI.SetColor(15,15);
		printf("  ");
		UI.SetColor(8,8);
		sc.gotoxy(snake_data[2][0],snake_data[2][1]);
		printf("  ");
		UI.SetColor(7,0);
		
		for(int loopnum3 = 0; loopnum3 < 2;loopnum3++){
			snake_data[loopnum3][0] = snake_data[2][0]+((snake_set_left == 1)?2+loopnum3:2-loopnum3)*snake_set_left+abs(snake_set_top)*loopnum3;
			snake_data[loopnum3][1] = snake_data[2][1]+snake_set_top;
			windows_snake_body[snake_data[loopnum3][0]][snake_data[loopnum3][1]] = true;
		}
		
		setting_snake_control = false;
		Sleep(log(snake_speed)+snake_speed);
	}
	
	
	//當遊戲結束時做的動作 
	char str1[] = "    GAME OVER!!    ";
	char str2[] = "    請按 任意鍵 來首頁    ";
	int L1 = strlen(str1);
	int L2 = strlen(str2);
	sc.gotoxy(game_form_left+(game_form_width-L1)/2,game_form_top+(game_form_height-1+2)/2); //算出文字位子 等於 （螢幕長度-字串長度）/2
	printf("%s",str1);
	sc.gotoxy(game_form_left+(game_form_width-L2)/2,game_form_top+(game_form_height-1+2)/2+1); //算出文字位子 等於 （螢幕長度-字串長度）/2
	printf("%s",str2); 
	
	game_over = true;
	while(game_over){
		Sleep(20);
	}
	
	win_c.Clr();
	UI.base();
	UI.GameMenu();
	
	game_start = false;
}

//產生餅乾 
void game_system::game_create_cookie(){
	do{
		srand((unsigned)time(NULL));
	    cookie[0][0] = game_form_left+rand()%(game_form_width-1);
	    if(cookie[0][0] % 2 == 0)
	    	cookie[0][0]-=1;	
	    cookie[0][1] = game_form_top+rand()%(game_form_height-1);
	}while(windows_snake_body[cookie[0][0]][cookie[0][1]]);
	cookie[1][0] = cookie[0][0] + 1;
	cookie[1][1] = cookie[0][1];
	
	set_cursor sc;
	sc.gotoxy(cookie[0][0],cookie[0][1]);
	printf("◎");
}

//吃到餅乾後的動作 
void game_system::game_eat_cookie(){
	for(int loopnum1 = 0; loopnum1 < 2;loopnum1++){
		snake_data[snake_lenght+loopnum1][0] = snake_data[snake_lenght-2+loopnum1][0];
		snake_data[snake_lenght+loopnum1][1] = snake_data[snake_lenght-2+loopnum1][1];
		windows_snake_body[cookie[loopnum1][0]][cookie[loopnum1][1]] = true;
	}
	snake_lenght+=2;
	if(snake_speed >=30)
		snake_speed-=10;
	game_create_cookie();
} 
