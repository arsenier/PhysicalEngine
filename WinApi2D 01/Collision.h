#pragma once
#include "CollisionPointsAndTransform.h"
#include "Object.h"

struct Collision {
	Object* ObjA;
	Object* ObjB;
	CollisionPoints Points;
	
	Collision(Object* a, Object* b, CollisionPoints p):
		ObjA(a), ObjB(b), Points(p){}
};