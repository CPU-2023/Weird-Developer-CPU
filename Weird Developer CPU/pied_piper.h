#include <windows.h>
#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>

#include <conio.h>
#include "modules.h"

#define SIZE 10

#define ESC 27
#define UP 72
#define DOWN 80
#define SUBMIT 4
#define ENTER 13

/* 함수 선언 */
int keyControl();
int PmenuDraw();
int PkeyControl();
void print_piano();
int MakeRandNote(int random);
int playGame(char** dp, int n);
void rule();
void guess_note(void);
void pied_piper_main(void);

#ifdef __cplusplus
extern "C" {
#endif

	void guess_note(void);

#ifdef __cplusplus
}
#endif

