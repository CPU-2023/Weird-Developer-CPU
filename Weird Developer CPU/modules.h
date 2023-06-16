#define _CRT_SECURE_NO_WARN
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <string.h>
#include <time.h>
#pragma comment(lib, "winmm.lib")
#pragma warning(disable:4996)



#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif



void print_auto_y(int* x, int* y, char* str);
void print_by_text(char* text, char* color, int x, int y);
void print_by_name(char* name);
void print_main_text(char* text, char* color, int x, int y);
void rectangle(int width, int height, int x, int y);
void gotoxy(int x, int y);
void gotoxy_2x(int x, int y);
int get_key(void);
void CursorView();
void move_arrow_key(
	char key,
	int* x,
	int* y,
	int size,
	int y_min,
	int y_max,
	int x_min,
	int x_max
);
void setBackColor(int forground, int background);
void setColor(int color);
int keyControl(int, int, int);