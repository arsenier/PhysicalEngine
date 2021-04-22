#pragma once

#include <gmtl/gmtl.h>
#include <vector>
#include "Object.h"
#include "Collision.h"
#include "Solver.h"

class PhysicsWorld
{
private:
	
	Solver solver;
	std::vector<Object*> m_objects;
	Vec2d m_gravity = Vec2d(0, -9.81f);
	double G = 6.67e+3;

public:
	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void ResolveCollision(double dtms);

	void Step(double dtms);
};

