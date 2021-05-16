#pragma once
#include <gmtl/gmtl.h>

using namespace gmtl;

struct CollisionPoints {
	Vec2d A; // Furthest point of A into B
	Vec2d B; // Furthest point of B into A
	Vec2d Normal; // B – A normalized
	float Depth;    // Length of B – A
	bool HasCollision;
};

struct Transform { // Describes an objects location
	Vec2d Position;
	Vec2d Scale;
	Vec2d Velocity;
	//quaternion Rotation;
};