#pragma once

#include <gmtl/gmtl.h>
#include <vector>
#include "Object.h"
#include "Collider.h"

class PhysicsWorld
{
private:
	std::vector<Object*> m_objects;
	Vec2d m_gravity = Vec2d(0, -9.81f);
	double G = 6.67e+3;

public:
	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void Step(double dtms);
	void ResolveCollisions(float);
};

