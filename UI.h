#include <windows.h>
class UI
{
private:
	int windows_width;
	int windows_height;
	void SetColor(unsigned short ForeColor,unsigned short BackGroundColor);
protected:
	
public:
	int mode1_left;
	int mode1_height;
	int mode2_left;
	int mode2_height;
	void base();
	void GameMenu();
};
