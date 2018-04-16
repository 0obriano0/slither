 // 參考網站 http://www.cplusplus.com/forum/beginner/106119/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) /* Thanks to 
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

int main()
{
char NAME[20];
int i;
float science  ;
float maths  ;
float sst  ;
float english  ;
float total ;
float percent;

gotoxy(20,5); cout<<"Please enter your name. eg. Prakul Sharma"
<<endl<<endl;
gotoxy(20,6); gets(NAME);

gotoxy(20,7);  cout<<"Please enter marks for Maths subject. e.g. 98 or 75.5"
<<endl<< endl;
gotoxy(20,8);  cin>>maths;

gotoxy(20,9);  cout<<"Please enter marks for Science Subject"
<<endl<<endl;
gotoxy(20,10); cin>> science;

gotoxy(20,11); cout<<"Please enter marks for SST Subject"
<<endl<<endl;
gotoxy(20,12); cin>> sst;

gotoxy(20,13); cout<<"Please enter marks for English Subject"
<<endl<<endl;
gotoxy(20,14); cin>> english;

    //a clrscr(); was supposed to be here but Eclipse doesn't resolve it.

for(i=1; i<=25; i++){ //25 is the hieght of the box
gotoxy(20,10+i); cout<<"?"<<endl; //keeping x cordinate constant for 1st border
gotoxy(65,10+i); cout<<"?"<<endl; //keeping x cordinate constant for 2nd border
};

for(i=1; i<=46; i++){ //46 is the breadth of the box
gotoxy(19+i,10); cout<<"?"<<endl; //keeping y cordinate constant. 10 is the top border. 31-12 = 19
gotoxy(19+i,35);cout<<"?"<<endl;
}

gotoxy(35,12); cout<<"Report Card";
gotoxy(35,13); cout<<"-------------";

gotoxy(33,15); cout<<"Name           : "<<NAME;
gotoxy(33,17); cout<<"Mathematics    : "<<maths;
gotoxy(33,19); cout<<"Science        : "<<science;
gotoxy(33,21); cout<<"Social Science : "<<sst;
gotoxy(33,23); cout<<"English        : "<<english;

total= maths + science + sst + english;
percent= (total/400)*100;
gotoxy(25,26); cout<<"Total marks out of 400 = " << total;
gotoxy(30,28); cout<<"Percentage = "<<percent<<"%" <<endl<<endl;

if(percent >= 90){
    gotoxy(35,31); cout<<"Keep it up!. \n";
}else if(80>=percent && percent<90){
    gotoxy(35,31); cout<<"Good. \n";
}else if(70>=percent && percent<80){
    gotoxy(35,31); cout<<"You can do BETTER. \n";
}else if(60>=percent && percent<70){
    gotoxy(35,31); cout<<"You need to work hard. \n";
}else if(40>= percent){
    gotoxy(35,32); cout<<"You have Failed. \n";
};

system("pause>nul");
return 0;
}
