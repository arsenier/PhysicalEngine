#pragma once

#include <gmtl/gmtl.h>
#include <Windows.h>
#include "Renderer.h"

class Renderer;

using namespace gmtl;

class Object
{
public:
	Vec2d Position;
	Vec2d Velocity;
	Vec2d Force;

	double mass;

	uint32_t color;
	
	void Nullify();

public:
	Object();
	Object(Object& object);
	Object(Vec2d _Position, Vec2d _Velocity = Vec2d(0, 0));

	virtual void draw(HDC, Renderer*) = 0;
};

