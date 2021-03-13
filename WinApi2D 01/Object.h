#pragma once

#include <gmtl/gmtl.h>
#include <Windows.h>

using namespace gmtl;

class Object
{
public:
	Vec2d Position;
	Vec2d Velocity;
	Vec2d Force;

	double mass;

	double radius;
	uint32_t color;
	
	void Nullify();

public:
	Object();
	Object(Object& object);
	Object(Vec2d _Position, Vec2d _Velocity = Vec2d(0, 0));

	Vec2d getPos();
	double getRad();
	uint32_t getColor();
};

