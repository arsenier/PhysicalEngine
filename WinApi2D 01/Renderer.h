#pragma once

#include <Windows.h>
#include <gmtl/gmtl.h>
//#include "Object.h"
class Object;

using namespace gmtl;

class Renderer
{
private:
	Vec2d camera;
	Vec2d FOV;

public:
	Renderer();

	Vec2d T(Vec2d);

	void DrawGrid(HDC, int = 10);
	void Draw(HDC, Object*);
};