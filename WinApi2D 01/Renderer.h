#pragma once

#include <Windows.h>
#include "Object.h"

class Renderer
{
private:
	Vec2d camera;
	Vec2d FOV;

	Vec2d T(Vec2d);

public:
	Renderer();

	void DrawGrid(HDC, int = 10);
	void Draw(HDC, Object*);
};