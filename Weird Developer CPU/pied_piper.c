#include "modules.h"
#include "pied_piper.h"
// _getch() value of ESC key


char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��", "��", "��", "��" };


int PkeyControl() {
	char temp;
	while (1) {
		if (_kbhit()) {
			temp = _getch();
			if (temp == -32) {
				temp = _getch();
				switch (temp) {
				case UP:
					return UP;
					break;
				case DOWN:
					return DOWN;
					break;
				}
			}
			else if (temp == 13) {
				return ENTER;
			}
			else if (temp == 27) {
				return ESC;
			}
		}
		return 0;
	}
}


int PmenuDraw() {
	PlaySound(TEXT("guess_note.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");



	int x = 23;
	int y = 4;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	print_auto_y(&x, &y, " _______  ___   _______  ______     _______  ___   _______  _______  ______   ");
	print_auto_y(&x, &y, "|       ||   | |       ||      |   |       ||   | |       ||       ||    _ |  ");
	print_auto_y(&x, &y, "|    _  ||   | |    ___||  _    |  |    _  ||   | |    _  ||    ___||   | ||  ");
	print_auto_y(&x, &y, "|   |_| ||   | |   |___ | | |   |  |   |_| ||   | |   |_| ||   |___ |   |_||_ ");
	print_auto_y(&x, &y, "|    ___||   | |    ___|| |_|   |  |    ___||   | |    ___||    ___||    __  |");
	print_auto_y(&x, &y, "|   |    |   | |   |___ |       |  |   |    |   | |   |    |   |___ |   |  | |");
	print_auto_y(&x, &y, "|___|    |___| |_______||______|   |___|    |___| |___|    |_______||___|  |_|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);



	gotoxy(41, 15);
	printf("�鸮�� ���� ��� �˸��� ���� ������~!");
	gotoxy(35, 17);
	printf("!���� ���� �� �ѱ۷� �����Ǿ� �ִ��� Ȯ�����ּ���!");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	x = 50;
	y = 21;

	gotoxy(x - 2, y); // -2�� ������ >�� ����ϱ� ���ؼ�
	printf(">     �� �� �� �� \n");
	gotoxy(x, y + 2);
	printf("    �� �� �� �� \n");
	print_by_name("������");



	while (1) {
		int n = PkeyControl();
		switch (n) {
		case UP: {
			if (y > 21) { //y�� 12~14������ �̵�
				gotoxy(x - 2, y); // x-2�ϴ� ������ >�� �� ĭ ������ ����ϱ� ���ؼ�
				printf(" ");

				gotoxy(x - 2, y -= 2); //���� �̵��� ��ġ�� �̵��Ͽ�
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf(">"); //�ٽ� �׸���
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			break;
		}
		case DOWN: {
			if (y < 23) { //�ִ� 20
				gotoxy(x - 2, y);
				printf(" ");

				gotoxy(x - 2, y += 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf(">");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			break;
		}
		case ENTER: {
			return y - 21;
			break;
		}
		}
	}
	return 0;
}


void print_piano() {
	gotoxy(34, 11);
	puts("����� �������� ��� �������� �����");
	gotoxy(34, 12);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 13);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 14);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 15);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 16);
	puts("��  ��� ���  ��  ��� ��� ���  ��  ��� ���  �� ");
	gotoxy(34, 17);
	puts("��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��");
	gotoxy(34, 18);
	puts("��   ��   ��   ��   ��   ��   ��   ��   ��   ��   ��");
	gotoxy(34, 19);
	puts("���������������������������");
}



int pr_str_array(char** dp, int n) {
	while (1) {
		double frequency[] = { 523, 587, 659, 699, 784, 880, 988, 1047, 1175, 1319 };
		const int note_len = 600;

		srand((unsigned int)time(NULL));
		int random = (rand() % 7);

		for (int i = 0; i < 7; i++) {
			if (random == i + 1) {
				Sleep(200);
			}
		}
		Beep(frequency[random], note_len);


		system("cls");

		char answer[10];

		print_piano();

		gotoxy(34, 9);
		printf("���� ���ϱ��?: ");
		scanf_s("%s", answer);

		if (!strcmp(answer, *(dp + random))) {
			gotoxy(76, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | (0 << 4));
			printf("�����Դϴ�!\n");
		}
		else {
			gotoxy(67, 9);
			printf("��! ������ %s�Դϴ�.\n", *(dp + random));
			gotoxy(82, 28);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | (0 << 4));
			for (int n = 3; n > 0; --n) {
				gotoxy(82, 29);
				printf("%d�� �Ŀ� ����ȭ������ ���ư��ϴ�...\n", n);
				Sleep(1000);
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | (0 << 4));
			break;
		}
	}
	return 0;
}

int playGame() {
	char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
	while (1) {
		int n = PkeyControl();
		switch (n) {
		case SUBMIT: {
			return pr_str_array(p, SIZE);
		}
		}
	}
	return 0;
}
void rule() {
	system("cls");
	gotoxy(26, 14);
	printf("���� ���� �� �ѱ۷� �����Ǿ� �ִ��� Ȯ�����ּ���.");
	gotoxy(75, 29);
	printf("������ �����Ϸ��� �����̽��ٸ� ��������...");
	playGame();
}

void pied_piper_main(void) {
	system("cls");

	char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
	int x = 100, y = 20;
	char key;


	while (1) {\
		int menuCode = PmenuDraw();
		system("cls");
		if (menuCode == 0) {
			pr_str_array(p, SIZE);
		}
		else if (menuCode == 2) {
			break;
		}
	}

	return 0;
}
