//#include <windows.h>
//#include <gmtl/gmtl.h>
//#include "draw.h"
//#include "PhysicsWorld.h"
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//char szClassName[] = "CG_WAPI_Template";
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	HWND hWnd;
//	MSG lpMsg;
//	WNDCLASS wc;
//
//	// Заполняем структуру класса окна
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = NULL;
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = (LPCWSTR)szClassName;
//
//	// Регистрируем класс окна
//	if (!RegisterClass(&wc))
//	{
//		MessageBox(NULL, (LPCWSTR)"Не могу зарегистрировать класс окна!", (LPCWSTR)"Ошибка", MB_OK);
//		return 0;
//	}
//
//	int x = 200;
//	int y = 200;
//	int w = 600;
//	int h = 600;
//
//	RECT rect;
//	rect.left = x;
//	rect.top = y;
//	rect.right = x + w;
//	rect.bottom = y + h;
//
//	UINT style = WS_OVERLAPPEDWINDOW;
//
//	AdjustWindowRectEx(&rect, style, 0, 0);
//
//	// Создаем основное окно приложения
//	hWnd = CreateWindow(
//		(LPCWSTR)szClassName, // Имя класса 
//		L"Шаблон WinAPI приложения", // Текст заголовка
//		style, // Стиль окна 
//		rect.left, rect.top, rect.right - rect.left,
//		rect.bottom - rect.top,
//		(HWND)NULL, // Указатель на родительское окно NULL 
//		(HMENU)NULL, // Используется меню класса окна 
//		(HINSTANCE)hInstance, // Указатель на текущее приложение
//		NULL); // Передается в качестве lParam в событие WM_CREATE
//
//	if (!hWnd)
//	{
//		MessageBox(NULL, (LPCWSTR)"Не удается создать главное окно!", (LPCWSTR)"Ошибка", MB_OK);
//		return 0;
//	}
//
//	// Показываем наше окно
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	// Выполняем цикл обработки сообщений до закрытия приложения
//	while (GetMessage(&lpMsg, NULL, 0, 0))
//	{
//		TranslateMessage(&lpMsg);
//		DispatchMessage(&lpMsg);
//	}
//	return (lpMsg.wParam);
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	RECT Rect;
//	HDC hdc, hCmpDC;
//	HBITMAP hBmp;
//
//	switch (messg)
//	{
//	case WM_TIMER:
//	{
//		break;
//	}
//	case WM_CREATE:
//	{
//		break;
//	}
//	case WM_KEYDOWN:
//	{
//		int KeyPressed;
//		KeyPressed = (int)wParam;
//		switch (KeyPressed)
//		{
//		default:
//			break;
//		}
//		InvalidateRect(hWnd, NULL, FALSE);
//		break;
//	}
//	case WM_ERASEBKGND:
//	{
//		return 1;
//		break;
//	}
//	case WM_PAINT:
//	{
//		GetClientRect(hWnd, &Rect);
//		hdc = BeginPaint(hWnd, &ps);
//
//		// Создание теневого контекста для двойной буферизации
//		hCmpDC = CreateCompatibleDC(hdc);
//		hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
//			Rect.bottom - Rect.top);
//		SelectObject(hCmpDC, hBmp);
//
//		// Закраска фоновым цветом
//		LOGBRUSH br;
//		br.lbStyle = BS_SOLID;
//		br.lbColor = 0x222222;
//		HBRUSH brush;
//		brush = CreateBrushIndirect(&br);
//		FillRect(hCmpDC, &Rect, brush);
//		DeleteObject(brush);
//
//		// Здесь рисуем на контексте hCmpDC
//
//		// Копируем изображение из теневого контекста на экран
//		SetStretchBltMode(hdc, COLORONCOLOR);
//		BitBlt(hdc, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top,
//			hCmpDC, 0, 0, SRCCOPY);
//
//		// Удаляем ненужные системные объекты
//		DeleteDC(hCmpDC);
//		DeleteObject(hBmp);
//		hCmpDC = NULL;
//
//		EndPaint(hWnd, &ps);
//		break;
//	}
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	default:
//		return (DefWindowProc(hWnd, messg, wParam, lParam));
//	}
//	return (0);
//}