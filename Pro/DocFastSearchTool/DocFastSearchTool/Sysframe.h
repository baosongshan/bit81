#pragma once
#include"Common.h"


/*
void SetCurPos(int x, int y); //x row   y col

void DrawRow(int x, int y);
void DrawCol(int x, int y);

void DrawFrame(char *title);
void DrawMenu();

*/

void SetCurPos(int x, int y);
void HideCursor();
void DrawCol(int x, int y);
void DrawRow(int x, int y);

void DrawFrame(char *title);
void DrawMenu();
void SystemEnd();