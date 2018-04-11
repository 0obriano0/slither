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

// ============================================
// 函式： SetConsoleSize
// 說明： 設定 Console 視窗大小
//        // x 不好用.
// ===========================================
BOOL windows_Console::SetConsoleSize(int W, int H)
{
        BOOL ret;
        SMALL_RECT SR;
        SR.Top = 0;
        SR.Left = 0;
        SR.Bottom = H-1;
        SR.Right = W-1;
        	ret = SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE, &SR);
        if(!ret) return ret;

        COORD Sz;
        Sz.X = W;
        Sz.Y = H;
        
        return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),Sz);
}

// ============================================
// 函式： ConsoleFullScreen
// 說明： Console設為全螢幕
//        VK_MENU -> ALT, VK_RETURN -> Enter
//        其實就是 alt + Enter 
// 轉載： CodeGurn
// ===========================================

void windows_Console::ConsoleFullScreen()
{
        keybd_event(VK_MENU,0x38,0,0); 
        keybd_event(VK_RETURN,0x1c,0,0); 
        keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0);
        keybd_event(VK_RETURN,0x9c,KEYEVENTF_KEYUP,0);

        /* 原版是寫下面這樣,但根據 scan code 送出之訊息, 較不好
        keybd_event(VK_MENU,0x38,0,0); 
        keybd_event(VK_RETURN,0x1c,0,0); 
        keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); 
        keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
        */

}

// ============================================
// 函式： IsConsoleFullScreen()
// 說明： 判斷是否為全螢幕
// ===========================================
BOOL windows_Console::IsConsoleFullScreen()
{
        // CONSOLE_FULLSCREEN(1), CONSOLE_FULLSCREEN_HARDWARE(2)
        DWORD mode;
        GetConsoleDisplayMode(&mode);
        if( (mode&CONSOLE_FULLSCREEN) == CONSOLE_FULLSCREEN) return TRUE;
        return FALSE;
}


// ============================================
// 函式： GetConsoleWindowSize
// 說明： 取得目前視窗大小
// ===========================================


void windows_Console::GetConsoleWindowSize(DWORD &W, DWORD &H)
{
        CONSOLE_FONT_INFO cfi;
        GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
        W = cfi.dwFontSize.X;
        H = cfi.dwFontSize.Y;
}

// ============================================
// 函式： _GetLargestConsoleWindowSize
// 說明： 取得最大視窗大小
// ===========================================

void windows_Console::_GetLargestConsoleWindowSize(DWORD &W, DWORD &H)
{
        COORD c = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
        W = c.X;
        H = c.Y;
}
