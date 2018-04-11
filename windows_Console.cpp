#include <windows.h>
#include "windows_Console.h"

// ============================================
// 函式： ConsoleTitle
// 說明： 設定 Consle 名稱
// ===========================================
void windows_Console::_SetConsoleTitle(const char* title){
        SetConsoleTitle(title);
        
}

// ============================================
// 函式： GetConsoleTitle
// 說明： 取得 Consle 名稱
// ===========================================
void windows_Console::_GetConsoleTitle(char* title, DWORD nSize){
        GetConsoleTitle(title, nSize);
}

// ============================================
// 函式： Clr, 清除螢幕
// 說明： 解決使用 system("cls") 會有閃爍問題
//        事實上這只是把每個點都填上空白而已
// 轉載： CodeGurn
// ===========================================
void windows_Console::Clr(){
        COORD coordScreen = { 0, 0 }; 
        DWORD cCharsWritten; 
        CONSOLE_SCREEN_BUFFER_INFO csbi; 
        DWORD dwConSize; 
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
        FillConsoleOutputCharacter(hConsole, TEXT(' '),
                dwConSize, 
                coordScreen,
                &cCharsWritten); 
        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        FillConsoleOutputAttribute(hConsole,
                csbi.wAttributes,
                dwConSize,
                coordScreen,
                &cCharsWritten); 
        SetConsoleCursorPosition(hConsole, coordScreen);

}
