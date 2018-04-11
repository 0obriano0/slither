#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "set_cursor.h"
#include "windows_Console.h"

using namespace std;

int main(int argc, char** argv) {
	set_cursor sc;
	windows_Console win_c;
	sc.gotoxy(0,80);
	win_c._SetConsoleTitle("¤¤¤å´ú¸Õwwwwwww");
	char a[100];
	win_c._GetConsoleTitle(a,16);
	cout << "a = " << a;
	//win_c.Clr();
	return 0;
}
