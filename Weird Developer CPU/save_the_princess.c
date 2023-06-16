#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include "console.h"
#include <mmsystem.h>
#include "modules.h"
#pragma comment(lib, "winmm.lib")

//Ű���尪
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define ESC 5


//�Լ� ���� 
void TitleDraw();
void init();
int menuDraw();
int SkeyControl();
void ruleDraw();



int save_the_princess_main() {
	PlaySound(TEXT("./sound/SaveThePrincess/Waterfall.wav"), NULL, SND_ASYNC | SND_LOOP);

	int select;
	while (1)
	{
		system("cls");
		init();
		TitleDraw();
		select = menuDraw();
		if (select == 0) {
			Function();
		}
		else if (select == 1) {
			ruleDraw();
		}
		else if(select == -1){
			break;
		}
		
	}

	//�Ϲ� ���
	return 0;
}


void init() {
	system("mode con:cols=120 lines=30 | title Save the Princess");
}

void TitleDraw()
{
	int x = 5, y = 3;
	textcolor(14);

	gotoxy(x, y++); printf("\t    _______  _______  __   __  _______      _______  ______    ___   __    _  _______  _______  _______ ");
	gotoxy(x, y++); printf("\t   |       ||   _   ||  | |  ||       |    |       ||    _ |  |   | |  |  | ||       ||       ||       |");
	gotoxy(x, y++); printf("\t   |  _____||  |_|  ||  |_|  ||    ___|    |    _  ||   | ||  |   | |   |_| ||       ||    ___||  _____|");
	gotoxy(x, y++); printf("\t   | |_____ |       ||       ||   |___     |   |_| ||   |_||_ |   | |       ||       ||   |___ | |_____ ");
	gotoxy(x, y++); printf("\t   |_____  ||       ||       ||    ___|    |    ___||    __  ||   | |  _    ||      _||    ___||_____  |");
	gotoxy(x, y++); printf("\t    _____| ||   _   | |     | |   |___     |   |    |   |  | ||   | | | |   ||     |_ |   |___  _____| |");
	gotoxy(x, y++); printf("\t   |_______||__| |__|  |___|  |_______|    |___|    |___|  |_||___| |_|  |__||_______||_______||_______|");
	gotoxy(x, y++);
	gotoxy(x, y++);
	gotoxy(x, y++);
	gotoxy(x, y++); printf("\t        $$$$$$$ \t                                |��                                ");
	gotoxy(x, y++); printf("\t       $$ $$$$$$\t   $$                           |                                  ");
	gotoxy(x, y++); printf("\t       $$$$$$$$$\t  $$$$         -----------------------------------                 ");
	gotoxy(x, y++); printf("\t$      $$$      \t   $$          |     ___       ___       ___     |                 ");
	gotoxy(x, y++); printf("\t$$     $$$$$$$  \t               |    |   |     |   |     |   |    |                $$");
	gotoxy(x, y++); printf("\t$$$   $$$$$     \t               |   |     |   |     |   |     |   |               $$$$");
	gotoxy(x, y++); printf("\t $$  $$$$$$$$$$ \t               -----------------------------------                $$");
	gotoxy(x, y++); printf("\t $$$$$$$$$$$    \t   |-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|    ");
	gotoxy(x, y++); printf("\t  $$$$$$$$$$    \t   |     ____       ____       ____     ____       ____      |    ");
	gotoxy(x, y++); printf("\t    $$$$$$$$    \t   |    |    |     |    |     |    |   |    |     |    |     |    ");
	gotoxy(x, y++); printf("\t     $$$$$$     \t   |   |      |   |      |   |      | |      |   |      |    |    ");
	gotoxy(x, y++); printf("\t\t                   -----------------------------------------------------------    ");
}

int menuDraw() {
	textcolor(7);
	int x = 55;
	int y = 26;
	
	gotoxy(x-2, ++y); printf("> ���ӽ���");
	gotoxy(x, y+1); printf("��������");

	return keyControl(x, y, 1);

}


int SkeyControl() {
	int temp = _getch();

	if (temp == 0xE0 || temp == 0)
	{
		temp = _getch();
	}

	switch (temp) {
	case 72: // VK_UP
		return UP;
	case 80: // VK_DOWN
		return DOWN;
	case 75: // VK_LEFT
		return LEFT;
	case 77: // VK_RIGHT
		return RIGHT;
	case 13: // Space
		return SUBMIT;
	case 27:
		return ESC;
	default:
		return 0;
	}
}

void ruleDraw() {


	int x = 5, y = 5;
	gotoxy(x, y++); printf("\t\t\t===================================================================");
	gotoxy(x, y++); printf("\t\t\t                    ��������! ���ָ� ���Ͽ���!��                   ");
	gotoxy(x, y++); printf("\t\t\t===================================================================");
	gotoxy(x, y++); printf("\t\t\t                                                                   ");
	gotoxy(x, y++); printf("\t\t\t\t\t          [���� ��� ��]                                   ");
	gotoxy(x, y++);
	gotoxy(x, y++); printf("\t\t\t- ȭ�鿡 ��Ÿ���� ������ ����ġ��, ��ź�� ������!                  ");
	gotoxy(x, y++); printf("\t\t\t- �÷��̾�� �� �� �� �� Ű�� ����Ͽ� ������ �� �ֽ��ϴ�.         "); ;
	gotoxy(x, y++); printf("\t\t\t- �����̽� �ٸ� ����Ͽ� �Ѿ��� �߻��� �� �ֽ��ϴ�.                ");
	gotoxy(x, y++); printf("\t\t\t- ���� ������ ������ ��� �̼ǿ� �����մϴ�.                       ");
	gotoxy(x, y++); printf("\t\t\t- �÷��̾��� ����� 1���Դϴ�.                                     ");
	gotoxy(x, y++); printf("\t\t\t- ���� ���϶� ���� ������ 5���� �ö󰩴ϴ�.                        ");
	gotoxy(x, y++); printf("\t\t\t- ������ 50���� �Ǹ� �̼��� �����ϰ� �˴ϴ�.  ");
	gotoxy(x, y++);
	gotoxy(x, y++); printf("\t\t\t\t\t          [�� ���۹� ��]");
	gotoxy(x, y++); printf("\t\t\t- ��: �������� �̵�                                       ^ _ ^ ");
	gotoxy(x, y++); printf("\t\t\t- ��: ���������� �̵�                                    ( o.o )");
	gotoxy(x, y++); printf("\t\t\t- �����̽� ��: �Ѿ� �߻�                                  > ^ < ");
	gotoxy(x, y++); printf("\t\t\t                                                        *-|   |-*");
	gotoxy(x, y++); printf("\t\t\t===================================================================");


	textcolor(7);
	x = 55;
	y = 26;

	char input;
	input = _getch();

}