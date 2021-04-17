#pragma once
#include <gmtl/gmtl.h>

class Object;

using namespace gmtl;

struct CollisionPoints {
	Vec2d A; // Furthest point of A into B
	Vec2d B; // Furthest point of B into A
	Vec2d Normal; // B – A normalized
	double Depth;    // Length of B – A
	bool HasCollision;
};

struct Transform { // Describes an objects location
	Vec2d Position;
	Vec2d Scale;
	//TODO roatation
};

struct Collision {
	Object* ObjA;
	Object* ObjB;
	CollisionPoints Points;
};