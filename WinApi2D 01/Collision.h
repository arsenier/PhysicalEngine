#pragma once
#include "CollisionPointsAndTransform.h"

class Object;

struct Collision {
	Object* ObjA;
	Object* ObjB;
	CollisionPoints Points;
};