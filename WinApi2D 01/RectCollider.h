#pragma once
#include "Collider.h"
#include "Algo.h"

struct RectCollider
	: Collider
{
	double width;
	double height;

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
		//return FindCircleCircleCollisionPoints(this, transform, sphere, sphereTransform);
		return FindCircleRectCollisionPoints(sphere, sphereTransform, this, transform);
	}

	CollisionPoints TestCollision(
		const Transform* transform,
		const RectCollider* rect,
		const Transform* planeTransform) const override
	{
		/*return algo::FindSpherePlaneCollisionPoints(
			this, transform, plane, planeTransform);*/
		return {};
	}
};