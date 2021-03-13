#include "Renderer.h"

Vec2d Renderer::T(Vec2d vec)
{
	return FOV * 0.5 + Vec2d(vec[0], -vec[1]) - Vec2d(camera[0], -camera[1]);
}

Renderer::Renderer()
{
	camera = Vec2d(0, 0);
	FOV = Vec2d(600, 600);
}

void Renderer::Draw(HDC hdc, Object* object)
{
}

void Renderer::DrawGrid(HDC hdc, int resolution)
{
	HPEN hNPen = CreatePen(PS_SOLID, 1, 0x777777);
	HPEN hOPen = (HPEN)SelectObject(hdc, hNPen);
	HBRUSH hOldBrush;
	HBRUSH hNewBrush;
	hNewBrush = CreateSolidBrush(0x777777);
	hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);

	Vec2d left(1000, 1000), origin(0, 0);

	left = T(left);
	origin = T(origin);

	MoveToEx(hdc, origin[0] - left[0], origin[1], NULL);
	LineTo(hdc, origin[0] + left[0], origin[1]);

	MoveToEx(hdc, origin[0], origin[1] - left[1], NULL);
	LineTo(hdc, origin[0], origin[1] + left[1]);

	DeleteObject(SelectObject(hdc, hOPen));
	DeleteObject(SelectObject(hdc, hOldBrush));
}