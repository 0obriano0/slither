#include <windows.h>
#include <conio.h>
#include <stdio.h>

class set_cursor
{
private:
	
protected:
	
public:
	void gotoxy(int x, int y);
	void getxy(int &x, int &y);
	void SetCursorVisible(BOOL Visible, DWORD Size);
};
