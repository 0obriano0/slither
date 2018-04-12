#include <iostream>
#include "UI.h"
#include "set_cursor.h"
#include "windows_Console.h"

int windows_width;
int windows_height;
int mode1_left;
int mode1_height;
int mode2_left;
int mode2_height;

void UI::SetColor(unsigned short ForeColor,unsigned short BackGroundColor){
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));
}

void UI::base(){
	int w = 114,h = 30,spaceh = 1;
	
	set_cursor sc;
	sc.gotoxy(3,spaceh);
	for(int loopNum1 = 0; loopNum1 <= w/2; loopNum1++){
		printf("—");
	}
	for(int loopNum2 = spaceh+1; loopNum2 < spaceh+h; loopNum2++){
		sc.gotoxy(3,loopNum2);
		printf("||");
		sc.gotoxy(3+w,loopNum2);
		printf("||");
	}
	sc.gotoxy(3,spaceh+h);
	for(int loopNum3 = 0; loopNum3 <= w/2; loopNum3++){
		printf("—");
	}
	
	windows_Console win;
	windows_width = w+6;
	windows_height = h+spaceh+2;
	win.SetConsoleSize(w+6,h+spaceh+2);
}

void UI::GameMenu(){
	char mode1[]="### 模式 一 ###";
	char mode2[]="### 模式 二 ###";
	int num1 = 6;		 
	char st1[6][55]={ "   ____                      __  __                  ",
				      "  / ___| __ _ _ __ ___   ___|  \\/  | ___ _ __  _   _ ",
				      " | |  _ / _` | '_ ` _ \\ / _ \\ |\\/| |/ _ \\ '_ \\| | | |",
				      " | |_| | (_| | | | | | |  __/ |  | |  __/ | | | |_| |",
				      "  \\____|\\__,_|_| |_| |_|\\___|_|  |_|\\___|_| |_|\\__,_|",
					  "                                                     "};
				  
	set_cursor sc;
	
	int w=windows_width-6; //設定屏幕寬度
	int h=windows_height-2; //設定屏幕長度
	int L= strlen(st1[0]); //取得文字長度
	int mode_L1 = strlen(mode1);
	int mode_L2 = strlen(mode2);
	SetColor(1,7);
	for(int loopnum1 = 0; loopnum1 < num1 ; loopnum1++){
		sc.gotoxy(5+((w-L)/2),2+(h-1-num1-2)/2+loopnum1); //算出文字位子 等於 （螢幕長度-字串長度）/2 
		std::cout << st1[loopnum1]; //輸出文字 
	}
	
	
	mode1_left = 5+((w-mode_L1)/2);
	mode1_height = 2+(h-1-num1-3)/2+num1+2;
	sc.gotoxy(mode1_left-3,mode1_height); //算出文字位子 等於 （螢幕長度-字串長度）/2
	SetColor(7,0);
	std::cout << ">> ";
	SetColor(4,7);
	std::cout << mode1; //輸出文字
	
	mode2_left = 5+((w-mode_L2)/2);
	mode2_height = 2+(h-1-num1-3)/2+num1+4;
	sc.gotoxy(mode2_left,mode2_height); //算出文字位子 等於 （螢幕長度-字串長度）/2 
	std::cout << mode2; //輸出文字
	
	SetColor(7,0);
}
