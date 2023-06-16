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

//키보드값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define ESC 5


//함수 정의 
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

	//일반 재생
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
	gotoxy(x, y++); printf("\t        $$$$$$$ \t                                |▶                                ");
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
	
	gotoxy(x-2, ++y); printf("> 게임시작");
	gotoxy(x, y+1); printf("게임정보");

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
	gotoxy(x, y++); printf("\t\t\t                    ♣작전명! 공주를 구하여라!♣                   ");
	gotoxy(x, y++); printf("\t\t\t===================================================================");
	gotoxy(x, y++); printf("\t\t\t                                                                   ");
	gotoxy(x, y++); printf("\t\t\t\t\t          [게임 방법 ☆]                                   ");
	gotoxy(x, y++);
	gotoxy(x, y++); printf("\t\t\t- 화면에 나타나는 적들을 물리치고, 폭탄을 피하자!                  ");
	gotoxy(x, y++); printf("\t\t\t- 플레이어는 ↑ ↓ ← → 키를 사용하여 움직일 수 있습니다.         "); ;
	gotoxy(x, y++); printf("\t\t\t- 스페이스 바를 사용하여 총알을 발사할 수 있습니다.                ");
	gotoxy(x, y++); printf("\t\t\t- 적에 공격을 받으면 즉시 미션에 실패합니다.                       ");
	gotoxy(x, y++); printf("\t\t\t- 플레이어의 목숨은 1개입니다.                                     ");
	gotoxy(x, y++); printf("\t\t\t- 적을 죽일때 마다 점수는 5점씩 올라갑니다.                        ");
	gotoxy(x, y++); printf("\t\t\t- 점수가 50점이 되면 미션을 성공하게 됩니다.  ");
	gotoxy(x, y++);
	gotoxy(x, y++); printf("\t\t\t\t\t          [☆ 조작법 ☆]");
	gotoxy(x, y++); printf("\t\t\t- ←: 왼쪽으로 이동                                       ^ _ ^ ");
	gotoxy(x, y++); printf("\t\t\t- →: 오른쪽으로 이동                                    ( o.o )");
	gotoxy(x, y++); printf("\t\t\t- 스페이스 바: 총알 발사                                  > ^ < ");
	gotoxy(x, y++); printf("\t\t\t                                                        *-|   |-*");
	gotoxy(x, y++); printf("\t\t\t===================================================================");


	textcolor(7);
	x = 55;
	y = 26;

	char input;
	input = _getch();

}