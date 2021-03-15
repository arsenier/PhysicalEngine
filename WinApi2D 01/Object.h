#pragma once

#include <gmtl/gmtl.h>
#include <Windows.h>
#include "draw.h"
//#include "Renderer.h"

class Renderer;

using namespace gmtl;

class Object
{
public:
	Vec2d Position;
	Vec2d Velocity;
	Vec2d Force;

	double mass;

	COLORREF color;
	
	void Nullify();

public:
	Object();
	Object(Object& object);
	Object(Vec2d _Position, Vec2d _Velocity = Vec2d(0, 0), double mass = 1, COLORREF color = 0xFFFFFF);

	void move(Vec2d);

	virtual ~Object() {}

	virtual void draw(Renderer& renderer) = 0;
};

