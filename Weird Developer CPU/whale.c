#include "modules.h"
#include "whale.h"

// _getch() value of ESC key
#define MAGIC_KEY 224
#define ESC 27
#define A 65
#define a 97
#define L 76
#define l 108
#define ENTER 13

void game_fun(void);
void start_game(void);

char key;
char t_name1[20];
char t_name2[20];
int x = 40;
int y = 11;
int win = 0;
int win_lose = 0;
int input = 0;

enum MENU
{
	GAMESTART = 0,
	EXIT
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

// 게임 시작 메인 함수
void whale_main() {
	system("cls");
	//PlaySound(TEXT("push.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (1) {
		if (game() == GAMESTART) {
			x = 40;
			start_game();
		}
		else {
			//PlaySound(NULL, 0, 0);
			break;
		}
	}
	return 0;
}

// 게임 메인화면 함수
void main_show() {
	system("cls");
	int x, y = 0;
	x = 23;
	y = 4;
	gotoxy(x, y);
	print_main_text("           hh              lll                                              ", cyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("ww      ww hh        aa aa lll   eee      gggggg   aa aa mm mm mmmm    eee  ", cyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("ww      ww hhhhhh   aa aaa lll ee   e    gg   gg  aa aaa mmm  mm  mm ee   e ", cyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" ww ww ww  hh   hh aa  aaa lll eeeee     ggggggg aa  aaa mmm  mm  mm eeeee  ", cyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("  ww  ww   hh   hh  aaa aa lll  eeeee         gg  aaa aa mmm  mm  mm  eeeee ", cyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("                                          ggggg                             ", cyan, &x, &y);

	x = 29, y = 13;
	gotoxy(x, y);
	print_main_text("O  ---(.______)--||-------||----||------||-------||-----", lightgray, &x, &y);
	gotoxy(x, ++y);
	print_main_text("|                                                      |", lightgray, &x, &y);
	gotoxy(x, ++y);
	print_main_text("|       이번 게임은 [내가 고래 였다면] 입니다.         |", lightgray, &x, &y);
	gotoxy(x, ++y);
	print_main_text("|                                                      |", lightgray, &x, &y);
	gotoxy(x, ++y);
	print_main_text("|        줄다리기에 이겨, 고래로 변신해보세요.         |", lightgray, &x, &y);
	gotoxy(x, ++y);
	print_main_text("|                                                      |", lightgray, &x, &y);
	gotoxy(x, ++y);
	print_main_text("O  -----||-------||----||------||-----||----(______.)---", lightgray, &x, &y);
	gotoxy(x, ++y);




	x = 0;
	y = 11;
	gotoxy(x, y);
	print_main_text("             $$$$$$", lightcyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("          $$$$$$$$$$$", lightcyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("$$  $$   $$$$$$$$$$$$$", lightcyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" $$$$$   $$$$$$$$$$$$$", lightcyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("  $$$$$$$$$$$$$$$$$$$$", lightcyan, &x, &y);
	gotoxy(x, ++y);
	print_main_text("   $$$$$$$$$$$$$$$$$$$", lightcyan, &x, &y);
	gotoxy(x, ++y);

	x = 10;
	y = 19;
	gotoxy(x, y);
	print_main_text("    #   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("   ##   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("  ####   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #####         *", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("######         **", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("######        ***", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" ######        ****", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #######        ***", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #######        **** ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("########      ****** ", lightgreen, &x, &y);

	x = 3;
	y = 19;
	gotoxy(x, y);
	print_main_text("O", lightblue, &x, &y);

	x = 17;
	y = 4;
	gotoxy(x, y);
	print_main_text("*", lightblue, &x, &y);

	x = 87;
	y = 17;
	gotoxy(x, y);
	print_main_text("*", lightblue, &x, &y);

	x = 100;
	y = 4;
	gotoxy(x, y);
	print_main_text("O", lightblue, &x, &y);

	x = 90;
	y = 16;
	gotoxy(x, y);
	print_main_text("            O  O        ", white, &x, &y);
	gotoxy(x, ++y);
	print_main_text("   VV     #########     VV", lightred, &x, &y);
	gotoxy(x, ++y);
	print_main_text("    #   ###       ###   #   ", lightred, &x, &y);
	gotoxy(x, ++y);
	print_main_text("      # ###  VVV  ### #     ", lightred, &x, &y);
	gotoxy(x, ++y);
	print_main_text("         ###     ###      ", lightred, &x, &y);
	gotoxy(x, ++y);
	print_main_text("          ########      ", lightred, &x, &y);






	gotoxy(56, 22);
	printf("게임 시작");

	gotoxy(56, 24);
	printf("게임 종료");

	print_by_name("이혜령 황채민");
}

// 메뉴 선택 커서 함수
enum MENU game() {
	int y = 0;
	while (1) {
		main_show();

		if (y <= 0)
		{
			y = 0;
		}
		else if (y >= 4)
		{
			y = 2;
		}

		gotoxy(53, 22 + y);
		printf(">");

		input = _getch();

		if (input == MAGIC_KEY)
		{
			switch (_getch())
			{
			case UP:
				gotoxy(53, 18 + y);
				printf("  ");
				y = y - 2;
				break;
			case DOWN:
				gotoxy(53, 18 + y);
				printf("  ");
				y = y + 2;
				break;
			}
		}
		else if (input == 13)
		{
			switch (y)
			{
			case 0:
				return GAMESTART;
			case 2:
				return EXIT;
			}
		}
	}
}


// 줄다리기 그려주는 함수
void line(int x, int y)
{

	system("cls");
	int i, line[21] = { 0 };
	line[10] = 1;
	line[2] = 2;
	line[18] = 2;
	gotoxy(31, 13);
	for (i = 0; i < 78; i++)
		printf(" ");

	gotoxy(28, 8);
	printf("%s", t_name1);
	gotoxy(86, 8);
	printf("%s", t_name2);

	int peple = 0;
	gotoxy(x - 16, 10);
	printf("           #######        ");
	gotoxy(x - 16, 11);
	printf("          #########       ");
	gotoxy(x - 15, 12);
	printf("   ## ## ###########      ");
	gotoxy(x - 16, 13);
	printf("   #################      ");

	gotoxy(x + 37, 10);
	printf("   #######        ");
	gotoxy(x + 34, 11);
	printf("   #########       ");
	gotoxy(x + 37, 12);
	printf("  ########### ## ##");
	gotoxy(x + 37, 13);
	printf("  #################");

	gotoxy(0, 14);
	printf("■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(77, 14);
	printf("■■■■■■■■■■■■■■■■■■■■■");

	// x,y함수로 line그려줌 x =40, y = 11
	gotoxy(x, 11);
	for (i = 0; i < 21; i++)
		if (line[i] == 0)
			printf("□");
		else if (line[i] == 1)
			printf("■");
		else
			printf("◆");

	//공중 줄 그리기
	for (int i = 0; i <= 9; i++) {
		gotoxy(58, i);
		printf("  |  ");
	}
	gotoxy(60, 10);
	printf("▼");
	gotoxy(60, 12);
	printf("▲");
	gotoxy(44, 2);
	printf("움직이지 않는다면 한영키를 바꾸십시오.");


	gotoxy(45, 27);
	printf("메뉴로 돌아가려면 ESC를 눌러주세요\n");

	char end = _getch();
	if (end == ESC) {
		whale_main();
	}
}

void start_game() {
	system("cls");
	int x, y = 0;
	x = 8;
	y = 19;
	gotoxy(x, y);
	print_main_text("    #   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("   ##   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("  ####   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #####         *", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("######         **", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("######        ***", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" ######        ****", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #######        ***", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #######        **** ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("########      ****** ", lightgreen, &x, &y);

	x = 90;
	y = 19;
	gotoxy(x, y);
	print_main_text("    #   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("   ##   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("  ####   ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #####         *", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("######         **", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("######        ***", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" ######        ****", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #######        ***", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text(" #######        **** ", lightgreen, &x, &y);
	gotoxy(x, ++y);
	print_main_text("########      ****** ", lightgreen, &x, &y);

	gotoxy(62, 12);
	printf("VS");
	gotoxy(45, 9);
	printf("게임을 진행할 팀 등록을 진행하십시오\n");
	gotoxy(25, 12);
	printf("첫번째 팀 이름입력 후 엔터> ");
	scanf_s("%s", &t_name1, 20);
	gotoxy(68, 12);
	printf("두번째 팀 이름입력 후 엔터> ");
	scanf_s("%s", &t_name2, 20);


	// 이름 입력 후 화면 지우기
	system("cls");
	//line 그려줌
	line(x, y);
	//게임함수 실행
	game_fun();
}

void game_fun() {
	while (1) {
		char click = _getch();

		switch (click) {
		case A: case a: // A
			x -= 2;
			line(x, y);
			Sleep(100);
			if (x <= 25) {
				gotoxy(78, 14);
				printf("                                         ");
				Sleep(500);
				system("color 40");
				Sleep(1000);
				system("color 0C");
				system("cls");
				print_by_text(t_name1, "red", 55, 15);
				gotoxy(48, 17);
				printf("2초 뒤 메인화면으로 돌아갑니다.");
				Sleep(2000);
				whale_main();
			}
			break;

		case L: case l: // L
			x += 2;
			line(x, y);
			Sleep(100);
			if (x >= 55) {
				gotoxy(0, 14);
				printf("                                              ");
				Sleep(500);
				system("color 40");
				Sleep(1000);
				system("color 0C");
				system("cls");
				print_by_text(t_name1, "red", 55, 15);
				gotoxy(48, 17);
				printf("2초 뒤 메인화면으로 돌아갑니다.");
				Sleep(2000);
				whale_main();
			}
			break;
		case ESC:
			break;
		}
	}
}
