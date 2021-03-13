#include "draw.h"
#include <math.h>

HWND hWndMain;
HDC hdcMain;
HBITMAP hbmMain;
enum
{
	physTimer = 1
};

void setcolor(COLORREF color)
{
	HPEN hpen;
	hpen = CreatePen(PS_SOLID, 0, color);
	hpen = (HPEN)SelectObject(hdcMain, hpen);
	if (hpen != NULL)
	{
		DeleteObject(hpen);
	}
}

void putline(int x1, int y1, int x2, int y2)
{
	MoveToEx(hdcMain, x1, y1, NULL);
	LineTo(hdcMain, x2, y2);
}

void putarc(int x, int y, int radius, float StartAngle, float SweepAngle)
{
	if (SweepAngle > 2 * 3.141592654 - 0.00001) {
		Arc(hdcMain, x - radius, y - radius, x + radius, y + radius, 1, 0, 1, 0);
	}
	else {
		Arc(hdcMain, x - radius, y - radius, x + radius, y + radius, (int)(50000.0 * cos(StartAngle)), -(int)(50000.0 * sin(StartAngle)), (int)(50000.0 * cos(StartAngle + SweepAngle)), -(int)(50000.0 * sin(StartAngle + SweepAngle)));
	}
}

void clrscr(COLORREF color = 0x222222)
{
	HBRUSH brush = CreateSolidBrush(color);
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = Width;
	rect.bottom = Height;
	FillRect(hdcMain, &rect, brush);
	RedrawWindow(hWndMain, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
}

void GFlush(void)
{
	RedrawWindow(hWndMain, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	switch (msg)
	{
	case WM_TIMER:
	{
		setcolor(0x0000FF);
		putline(20, 30, 50, 60);
		putline(205, 300, 50, 60);
		//SetPixel(hdcMain, 60, 60, 0xFFFFFF);
		GFlush();
		break;
	}
	case WM_CREATE:
	{
		SetTimer(hWnd, physTimer, timeStepMilliseconds, NULL);
		clrscr();
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		BitBlt(hdc, 0, 0, Width, Height, hdcMain, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		break;
	}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	static TCHAR winName[] = TEXT("PhysEngine");

	WNDCLASS wc;
	MSG msg;
	HDC hdc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = winName;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Не могу зарегистрировать класс окна!"), TEXT("Ошибка"), MB_OK);
		return 0;
	}

	int x = 200;
	int y = 200;
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + Width;
	rect.bottom = y + Height;

	UINT style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;

	AdjustWindowRectEx(&rect, style, 0, 0);

	hWndMain = CreateWindow(
		winName,
		winName,
		style,
		rect.left, rect.top, rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!hWndMain)
	{
		MessageBox(NULL, TEXT("Не удается создать главное окно!"), TEXT("Ошибка"), MB_OK);
		return 0;
	}

	hdc = GetDC(hWndMain);
	hdcMain = CreateCompatibleDC(hdc);
	hbmMain = CreateCompatibleBitmap(hdc, Width, Height);
	SelectObject(hdcMain, hbmMain);
	ReleaseDC(hWndMain, hdc);

	ShowWindow(hWndMain, nCmdShow);
	UpdateWindow(hWndMain);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}