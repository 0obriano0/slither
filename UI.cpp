#include "UI.h"
#include "set_cursor.h"
#include "windows_Console.h"
#include <stdio.h> 
#include <iostream>

//�]�p�]�w�C�⪺�禡 
void UI::SetColor(unsigned short ForeColor,unsigned short BackGroundColor){
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));
}

void UI::base(){
	//�]�w�����j�p(�u���ƭ�) 
	int w = 112,h = 30,spaceh = 1;
	form_width = w;
	form_height = h;
	form_top = spaceh+1;
	form_left = 5;
	
	//�[�W �W���(���) 
	set_cursor sc;
	sc.gotoxy(3,spaceh);
	for(int loopNum1 = 0; loopNum1 <= w/2; loopNum1++){
		printf("�X");
	}
	
	//�[�W ���k���(���) 
	for(int loopNum2 = spaceh+1; loopNum2 < spaceh+h; loopNum2++){
		sc.gotoxy(3,loopNum2);
		printf("||");
		sc.gotoxy(3+w,loopNum2);
		printf("||");
	}
	
	//�[�W �U���(���) 
	sc.gotoxy(3,spaceh+h);
	for(int loopNum3 = 0; loopNum3 <= w/2; loopNum3++){
		printf("�X");
	}
	
	//�]�w�ج[�j�p 
	windows_Console win;
	windows_width = w+6;
	windows_height = h+spaceh+2;
	win.SetConsoleSize(w+8,h+spaceh+2);
}

void UI::GameMenu(){
	//��r�w�q�� 
	char mode1[]="### �}�l�C�� ###";
	char mode2[]="### ���հϰ�j�p ###";
	int num1 = 6;		 
	char st1[6][55]={ "   ____                      __  __                  ",
				      "  / ___| __ _ _ __ ___   ___|  \\/  | ___ _ __  _   _ ",
				      " | |  _ / _` | '_ ` _ \\ / _ \\ |\\/| |/ _ \\ '_ \\| | | |",
				      " | |_| | (_| | | | | | |  __/ |  | |  __/ | | | |_| |",
				      "  \\____|\\__,_|_| |_| |_|\\___|_|  |_|\\___|_| |_|\\__,_|",
					  "                                                     "};
	int num2 = 7;
	char st2[7][79]={	"       ###     ##    ##    ###                                              #",
				  		" ####   ##           ##     ##                    ###                       #",
				  		"##  #   ##    ###   #####   ####   ###  ## ###   ## ##  ###   #####   ###   #",
                  		"####    ##     ##    ##     ## ## ## ##  ### #   ##    ## ##   ##### ## ##  #",
                  		"  ###   ##     ##    ##     ## ## #####  ##      #####  ####   # # # #####  #",
                  		"#  ##   ##     ##    ## ##  ## ## ##     ##      ## ## ## ##   # # # ##      ",
                  		"####  ###### ######   ###   ## ##  #### ####      #### ######  # # #  ####  #"};
	set_cursor sc;
	
	//�����p���r���j�p 
	int w=windows_width-6; //�]�w�̹��e��
	int h=windows_height-2; //�]�w�̹�����
	int L= strlen(st1[0]); //���o��r����
	int L2= strlen(st2[0]); //���o��r����
	int mode_L1 = strlen(mode1);
	int mode_L2 = strlen(mode2);
	SetColor(1,7);
	
	//�}�l��X��r 
	for(int loopnum1 = 0; loopnum1 < num1 ; loopnum1++){
		sc.gotoxy(5+((w-L)/2),2+(h-1-num1-2)/2+loopnum1); //��X��r��l ���� �]�ù�����-�r����ס^/2 
		std::cout << st1[loopnum1]; //��X��r 
	}
	
	SetColor(7,0);
	for(int loopnum1 = 0; loopnum1 < num2 ; loopnum1++){
		sc.gotoxy(5+((w-L2)/2),2+(h-1-num1-2)/2+loopnum1-num2-1); //��X��r��l ���� �]�ù�����-�r����ס^/2 
		std::cout << st2[loopnum1]; //��X��r 
	}
	
	SetColor(1,7);
	mode1_left = 5+((w-mode_L1)/2);
	mode1_height = 2+(h-1-num1-3)/2+num1+2;
	sc.gotoxy(mode1_left-3,mode1_height); //��X��r��l ���� �]�ù�����-�r����ס^/2
	SetColor(7,0);
	std::cout << ">> ";
	SetColor(4,7);
	std::cout << mode1; //��X��r
	
	mode2_left = 5+((w-mode_L2)/2);
	mode2_height = 2+(h-1-num1-3)/2+num1+4;
	sc.gotoxy(mode2_left,mode2_height); //��X��r��l ���� �]�ù�����-�r����ס^/2 
	std::cout << mode2; //��X��r
	
	SetColor(7,0);
}
