#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "set_cursor.h"
#include "windows_Console.h"
#include "UI.h"

using namespace std;

int main(int argc, char** argv) {
	
	set_cursor sc;
	windows_Console win_c;
	UI UI;
	UI.base();
	UI.GameMenu();
	sc.SetCursorVisible(false,1); 
	win_c._SetConsoleTitle(" ( ¡E£s¡E`)"); 
	
	int key1,key2;
	while(1){
		if (!kbhit())
			key1= getch();
			
		if (key1 == 0 || key1==224){
			key2 = getch();
			switch(key2){
				case 72:
					sc.gotoxy(UI.mode1_left-3,UI.mode1_height);
					std::cout << ">> ";
					sc.gotoxy(UI.mode2_left-3,UI.mode2_height);
					std::cout << "   ";
				break;
				case 80:
					sc.gotoxy(UI.mode1_left-3,UI.mode1_height);
					std::cout << "   ";
					sc.gotoxy(UI.mode2_left-3,UI.mode2_height);
					std::cout << ">> ";
				break;
			}
		}else{
		}
	}
	
	Sleep(1000000);
	return 0;
}
