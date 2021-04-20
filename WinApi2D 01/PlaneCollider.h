#pragma once
#include "Collider.h"
//#include "CircleCollider.h"

struct CircleCollider;

struct PlaneCollider
	: Collider
{
	Vec2d Plane;
	double Distance;

	CollisionPoints TestCollision(
		const Transform* transform,
		const Collider* collider,
		const Transform* colliderTransform) const override
	{
		return collider->TestCollision(colliderTransform, this, transform);
	}

	virtual CollisionPoints TestCollision(
		const Transform* transform,
		const CircleCollider* sphere,
		const Transform* sphereTransform) const override {
		return {};
	}

	CollisionPoints TestCollision(
		const Transform* transform,
		const PlaneCollider* plane,
		const Transform* planeTransform) const override
	{
		return {}; // No plane v plane
	}
};