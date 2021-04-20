#pragma once

struct CollisionPoints;
struct CircleCollider;
struct Transform;
struct PlaneCollider;


namespace algo {
	CollisionPoints FindSphereSphereCollisionPoints(
		const CircleCollider* a, const Transform* ta,
		const CircleCollider* b, const Transform* tb);

	CollisionPoints FindSpherePlaneCollisionPoints(
		const CircleCollider* a, const Transform* ta,
		const PlaneCollider* b, const Transform* tb);
}