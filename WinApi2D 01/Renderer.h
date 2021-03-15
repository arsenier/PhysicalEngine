#pragma once

#include <Windows.h>
#include <gmtl/gmtl.h>
#include "Object.h"

//class Object;

using namespace gmtl;

class Renderer
{
private:
	std::vector<Object*> m_objects;
	Vec2d camera;
	double scale;

public:
	Renderer();

	Vec2d T(Vec2d);
	double T(double);

	void move(Vec2d);
	void setPosition(Vec2d pos);

	void DrawGrid(HDC, int = 10);
	void AddObject(Object* object);
	void RemoveObject(Object* object);
	void drawAll();
};