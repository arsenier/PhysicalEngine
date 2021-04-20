#pragma once
#include "CollisionPointsAndTransform.h"

struct CircleCollider;
struct PlaneCollider;

struct Collider {
	virtual CollisionPoints TestCollision(
		const Transform* transform,
		const Collider* collider,
		const Transform* colliderTransform) const = 0;

	virtual CollisionPoints TestCollision(
		const Transform* transform,
		const CircleCollider* sphere,
		const Transform* sphereTransform) const = 0;

	virtual CollisionPoints TestCollision(
		const Transform* transform,
		const PlaneCollider* plane,
		const Transform* planeTransform) const = 0;
};