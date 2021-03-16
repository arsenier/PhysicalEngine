#pragma once
#include "Collider.h"
#include "PlaneCollider.h"


struct CircleCollider
	: Collider
{
	Vec2d Center;
	float Radius;

	CollisionPoints TestCollision(
		const Transform* transform,
		const Collider* collider,
		const Transform* colliderTransform) const override
	{
		return collider->TestCollision(colliderTransform, this, transform);
	}

	CollisionPoints TestCollision(
		const Transform* transform,
		const CircleCollider* sphere,
		const Transform* sphereTransform) const override
	{
		return algo::FindSphereSphereCollisionPoints(
			this, transform, sphere, sphereTransform);
	}

	CollisionPoints TestCollision(
		const Transform* transform,
		const PlaneCollider* plane,
		const Transform* planeTransform) const override
	{
		return algo::FindSpherePlaneCollisionPoints(
			this, transform, plane, planeTransform);
	}
};