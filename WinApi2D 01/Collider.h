#pragma once

#include "CollisionPAndTransform.h"

class CircleCollider;
class PlaneCollider;

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

namespace algo {
	CollisionPoints FindSphereSphereCollisionPoints(
		const CircleCollider* a, const Transform* ta,
		const CircleCollider* b, const Transform* tb);


	CollisionPoints FindSpherePlaneCollisionPoints(
		const CircleCollider* a, const Transform* ta,
		const PlaneCollider* b, const Transform* tb);
}