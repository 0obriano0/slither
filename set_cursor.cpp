#include "set_cursor.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

void set_cursor::gotoxy(int x, int y) /* Thanks to 
http://stackoverflow.com/questions/7955145/which-header-file-i-need-to-include-to-use-gotoxy-function
*/
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y }; // I am getting a little warning here :

/*
narrowing conversion of 'y' from 'int' to 'SHORT {aka short int}' 
inside { } [-Wnarrowing]  Report Card.cpp /Working    line 13 C/C++ Problem
*/
  SetConsoleCursorPosition(h,c);
}
