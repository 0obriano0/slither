#include <windows.h>
class windows_Console
{
private:
	
protected:
	
public:
	void _SetConsoleTitle(const char* title);
	void _GetConsoleTitle(char* title, DWORD nSize);
	void Clr();
	BOOL SetConsoleSize(int W, int H);
	void ConsoleFullScreen();
	BOOL IsConsoleFullScreen();
	void GetConsoleWindowSize(DWORD &W, DWORD &H);
	void _GetLargestConsoleWindowSize(DWORD &W, DWORD &H);
};
