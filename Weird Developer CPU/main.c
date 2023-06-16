#include "modules.h"
#include "pengsoo.h"
#include "pied_piper.h"
#include "whale.h"
#include "save_the_princess.h"
#include "blue_night_in_jeju.h"

void set_console(void);
void set_cursor(int flag, int size);

void draw_main(void);
int select_game(void);

int main(void) {
	PlaySound(TEXT("./sound/main_music.wav"), NULL, SND_ASYNC | SND_LOOP);
	set_console();
	int select;
	while (select = select_game()) {
		//PlaySound(NULL, 0, 0);

		switch (select)
		{
		case 1:
			//rectangle(114, 29, 2, 1);
			//flowing_dress_main();
			break;

		case 2:
			//rectangle(114, 29, 2, 1);
			pengsoo_main();
			break;

		case 3:
			//rectangle(114, 29, 2, 1);
			//pied_piper_main();
			break;

		case 4:
			//rectangle(114, 29, 2, 1);
			whale_main();
			break;

		case 5:
			//rectangle(114, 29, 2, 1);
			save_the_princess_main();
			break;

		case 6:
			//rectangle(114, 29, 2, 1);
			blue_night_in_jeju_main();
			break;

		default:
			break;
		}
	}
	return 0;
}

void set_console(void)
{
	// set the console size
	system("mode con:cols=120 lines=30");
	// hide cursor
	set_cursor(0, 1);
	// set title
	system("title Weird Developer CPU");
	// clear console
	system("cls");
}

void set_cursor(int flag, int size) {
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = flag;
	cursor.dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void draw_main(void)
{
	system("cls");

	setColor(yellow);
	int x = 42;
	gotoxy(x, 4); printf("weird developer CPU");
	/*
	gotoxy(x, 4); printf(" _____ ____  __    __ _____ _____   ");
	gotoxy(x, 5); printf("/ ____/ __ ＼| |  | ||_   _|  __ ＼ ");
	gotoxy(x, 6); printf("| |   | |  | | |  | |  | | | |  | |");
	gotoxy(x, 7); printf("| |   | |  | | |  | |  | | | |  | | ");
	gotoxy(x, 8); printf("| |___| |__| | |__| | _| |_| |__| | ");
	gotoxy(x, 9); printf("＼____＼___＼＼____/ |_____|_____/  ");

	gotoxy(x, 10); printf("   _____          __    __ ______ ");
	gotoxy(x, 11); printf("  / ____|   /＼   |  ＼/  |  ____|");
	gotoxy(x, 12); printf(" | |  __   /  ＼  | ＼  / | |__ ");
	gotoxy(x, 13); printf(" | | |_ | / /＼＼ | |＼/| |  __|");
	gotoxy(x, 14); printf(" | |__| |/ ____ ＼| |   | | |____ ");
	gotoxy(x, 15); printf("  ＼____/_/   ＼_＼_|   |_|______|");
	*/



	setColor(white);

	gotoxy(52, 18); printf("게임 선택후 엔터");
	/*
	gotoxy(86, 5); printf("■■■■■");
	gotoxy(86, 6); printf("■      ■");
	gotoxy(86, 7); printf("■      ■");
	gotoxy(86, 8); printf("■■■■■");

	setColor(white);
	gotoxy(21, 5); printf("  ●●●");
	gotoxy(21, 6); printf("●      ●");
	gotoxy(21, 7); printf("●      ●");
	gotoxy(21, 8); printf("  ●●●");

	*/
	setColor(white);
	gotoxy(30, 22); printf("① 드레스\n");
	gotoxy(54, 22);  printf("② 펭수");
	gotoxy(78, 22);  printf("③ 피리");

	gotoxy(30, 26);  printf("④ 고래");
	gotoxy(54, 26);  printf("⑤ 후추양");
	gotoxy(78, 26);  printf("⑥ 제주도");
}

int select_game(void)
{
	draw_main();

	int select_x[3] = { 26, 50, 74 };
	int select_y[2] = { 20, 24 };

	// default menu 1
	int select = 1;

	int i, j, x, y;

	int key = 0;
	while (key != ENTER) {
		// 1, 4 | 2, 5 | 3, 6 | 
		i = (select - 1) % 3;
		x = select_x[i];
		// 1, 2, 3| 5, 6, 7
		j = select <= 3 ? 0 : 1;
		y = select_y[j];

		// print rectangle
		print_auto_y(&x, &y, "┌─────────────────┐");
		print_auto_y(&x, &y, "│");
		gotoxy(x + 18, y - 1);			printf("│");
		print_auto_y(&x, &y, "│");
		gotoxy(x + 18, y - 1);			printf("│");
		print_auto_y(&x, &y, "│");
		gotoxy(x + 18, y - 1);			printf("│");
		print_auto_y(&x, &y, "└─────────────────┘");

		// ↑, ↓, ←, →
		key = _getch();

		switch (key) {
		case RIGHT:
			select = select == 6 ? 6 : select + 1;
			break;

		case LEFT:
			select = select == 1 ? 1 : select - 1;
			break;

		case UP:
			if (select > 3) {
				select -= 3;
			}
			break;

		case DOWN:
			if (select <= 3) {
				select += 3;
			}
			break;
		}

		// remove rectangle
		y -= 5;
		print_auto_y(&x, &y, "                    ");
		print_auto_y(&x, &y, "  ");
		gotoxy(x + 18, y - 1);			printf("  ");
		print_auto_y(&x, &y, "  ");
		gotoxy(x + 18, y - 1);			printf("  ");
		print_auto_y(&x, &y, "  ");
		gotoxy(x + 18, y - 1);			printf("  ");
		print_auto_y(&x, &y, "                    ");
	}

	return select;
}
