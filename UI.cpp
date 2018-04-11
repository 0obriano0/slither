#include "UI.h"
#include "set_cursor.h"
#include "windows_Console.h"
void UI::base(){
	int w = 114,h = 30;
	set_cursor sc;
	sc.gotoxy(3,3);
	for(int loopNum1 = 0; loopNum1 <= w/2; loopNum1++){
		printf("¡X");
	}
	for(int loopNum2 = 4; loopNum2 < 3+h; loopNum2++){
		sc.gotoxy(3,loopNum2);
		printf("||");
		sc.gotoxy(3+w,loopNum2);
		printf("||");
	}
	sc.gotoxy(3,3+h);
	for(int loopNum3 = 0; loopNum3 <= w/2; loopNum3++){
		printf("¡X");
	}
	windows_Console win;
	win.SetConsoleSize(w+6,h+5);
}
