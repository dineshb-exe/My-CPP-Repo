#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()

{

	system("cls");
	system("color 60");
	gotoxy(99,3);

	cout<<"HELLO WORLD";
	getch();
	system("color 50");
	gotoxy(60,10);

	cout<<"HELLO WORLD";
	getch();
	gotoxy(35,20);

	cout<<"HELLO WORLD";

	getch();

	return 0;

}

