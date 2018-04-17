#include <windows.h>
class UI
{
private:
	int windows_width;
	int windows_height;
protected:
	
public:
	void SetColor(unsigned short ForeColor,unsigned short BackGroundColor);
	int form_width;
	int form_height;
	int form_top;
	int form_left;
	int mode1_left;
	int mode1_height;
	int mode2_left;
	int mode2_height;
	void base();
	void GameMenu();
};
