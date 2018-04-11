#include "set_cursor.h"
#include <conio.h>
#include <stdio.h>

// =============================================
// 函式： gotoxy
// 說明： 移動游標至指定位置
// ============================================
void set_cursor::gotoxy(int x, int  y)
{
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// =============================================
// 函式： getxy
// 說明： 取得目前游標位置
// ============================================
void set_cursor::getxy(int &x, int &y)
{
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
}

// ============================================
// 函式： SetCursorVisible, 設定游標顯示比例
// 說明： 其實就是設定游標多肥大,百分比 1~100
// ===========================================
void set_cursor::SetCursorVisible(BOOL Visible, DWORD Size)
{
        CONSOLE_CURSOR_INFO cci;
        cci.bVisible = Visible; // 是否可視
        cci.dwSize = Size; // 設定大小,1~100
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
