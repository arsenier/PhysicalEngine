#pragma once
//#include "CircleCollider.h"
struct CollisionPoints;
struct CircleCollider;
struct PlaneCollider;
struct Transform;

CollisionPoints FindCircleCircleCollisionPoints(
		const CircleCollider* a, const Transform* ta,
		const CircleCollider* b, const Transform* tb);


CollisionPoints FindSpherePlaneCollisionPoints(
		const CircleCollider* a, const Transform* ta,
		const PlaneCollider* b, const Transform* tb);