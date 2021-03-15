#pragma once

#include <Windows.h>

const int Height = 800;
const int Width = 800;

//int timeStepMilliseconds = 10;

void putline(int x1, int y1, int x2, int y2);
void putarc(int x, int y, int radius, float StartAngle, float SweepAngle);
void setcolor(COLORREF, COLORREF = 0x000000);
void clrscr(COLORREF);

void GFlush(void);

void drawTest();
