#pragma once
#include "CollisionPointsAndTransform.h"

struct CircleCollider;
struct PlaneCollider;
struct RectCollider;

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
		const RectCollider* rect,
		const Transform* planeTransform) const = 0;
};