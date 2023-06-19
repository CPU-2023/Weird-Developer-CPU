#include <conio.h>
#include <iostream>
#include "pied_piper.h" 
using namespace std;

// _getch() value of ESC key
#define ESC 27

extern "C" void guess_note(void) {
	system("cls");

	cout << "guess note\n";

	int x = 100, y = 20;
	char key = 0;

	do {
		gotoxy(x, y);
		printf("njk");
		key = _getch();
	} while (key != ESC);
}