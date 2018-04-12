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
	Sleep(1000000);
	return 0;
}
