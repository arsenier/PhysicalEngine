#pragma once

#include <gmtl/gmtl.h>
#include <vector>
#include "Object.h"

class PhysicsWorld
{
private:
	std::vector<Object*> m_objects;
	Vec2d m_gravity = Vec2d(0, -9.81f);

public:
	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void Step(double dtms);
};

