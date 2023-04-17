#include "modules.h"

#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77



//커서 숨기기
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


// move the cursor funtion (chohadam 21-03-11)
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy_2x(int x, int y)
{
	COORD Pos;
	Pos.X = x * 2;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 텍스트 색상
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void setBackColor(int forground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//콘솔 핸들 가져오기
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

int keyControl(int x, int y, int num)
{
	int input;
	int key = y;

	while (1) {
		input = _getch();
		switch (input) {
		case UP: {
			if (y > key) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, --y);
				printf("♥");
			}
			break;
		}
		case DOWN: {
			if (y < key + num) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, ++y);
				printf("♥");
			}
			break;
		}
		case ENTER: {
			return y - key;
		}
		case ESC: {
			return 1;
		}
		}
	}
	return 0;
}
void print_auto_y(int* x, int* y, char* str) {
	gotoxy(*x, *y);
	printf(str);
	*y += 1;
}

void print_by_text(char* text, char* color, int x, int y) {
	// set color : RED
	setColor(color);

	gotoxy(x, y);
	printf("TEAM [ %s ] KILL", text);

	setColor(white);
}

void rectangle(int width, int height, int x, int y) {
	// ┌――――┐
	for (int i = 1; i < width / 2; i++) {
		gotoxy((x + width) / 2 - i, y);
		printf("─");

		gotoxy((x + width) / 2 + i, y);
		printf("─");
		Sleep(1);
	}
	gotoxy(x, y);
	printf("┌");
	gotoxy(x + width, y);
	printf("┐");

	// ｜      ｜
	for (int i = 1; i < height; i++) {
		gotoxy(x, y + i);
		// ｜      ｜
		printf("│");

		for (int j = 1; j < width - 1; j++) {
			printf(" ");
		}
		printf(" ");

		printf("│");
		Sleep(1);
	}

	// └――――┘
	gotoxy(x, y + height);
	printf("└");
	gotoxy(x + width, y + height);
	printf("┘");
	for (int i = 1; i < width / 2; i++) {
		gotoxy(x + i, y + height);
		printf("─");

		gotoxy((x + width) - i, y + height);
		printf("─");
		Sleep(1);
	}
}