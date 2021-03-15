#pragma once

#include <Windows.h>

const int Height = 800;
const int Width = 800;

//int timeStepMilliseconds = 10;

void putline(int x1, int y1, int x2, int y2);
void putarc(int x, int y, int radius, float StartAngle, float SweepAngle);
void putpixel(int x, int y, COLORREF);
void setcolor(COLORREF, COLORREF = 0x000000);
void clrscr(COLORREF = 0x222222);

void GFlush(void);

void OnKeyPress(const WPARAM& wParam);
void OnCharPress(const HWND& hWnd, const WPARAM& wParam);
void drawTest();
void OnTimer(const WPARAM& wParam);
void OnDraw();
void OnCreate(const HWND& hWnd);
