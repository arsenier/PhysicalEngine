#pragma once
#include <gmtl/gmtl.h>
//#include "CircleCollider.h"
struct CollisionPoints;
struct CircleCollider;
struct PlaneCollider;
struct RectCollider;
struct Transform;


CollisionPoints FindCircleCircleCollisionPoints(
		const CircleCollider* a, const Transform* ta,
		const CircleCollider* b, const Transform* tb);


//CollisionPoints FindCirclePlaneCollisionPoints(
//		const CircleCollider* a, const Transform* ta,
//		const Vec2d& A, const Vec2d& B);

CollisionPoints FindCircleRectCollisionPoints(
	const CircleCollider* a, const Transform* ta,
	const RectCollider* b, const Transform* tb);