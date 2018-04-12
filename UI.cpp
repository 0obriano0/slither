#include "UI.h"
#include "set_cursor.h"
#include "windows_Console.h"

int windows_width;
int windows_height;

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
	char st[]="遊戲選擇目錄";
	set_cursor sc;
	
	int w=windows_width-6; //設定屏幕寬度
	int h=windows_height-2; //設定屏幕長度
	int L= strlen(st); //取得文字長度
	SetColor(1,7);
	sc.gotoxy(5+((w-L)/2),2+(h-1)/2); //算出文字位子 等於 （螢幕長度-字串長度）/2 
	printf("%s",st); //輸出文字 
	SetColor(7,0);
}
