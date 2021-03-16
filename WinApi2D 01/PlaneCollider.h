#pragma once
#include "Collider.h"
#include "CircleCollider.h"

struct PlaneCollider
	: Collider
{
	Vec2d Plane;
	float Distance;

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
		const Transform* sphereTransform) const //по непонятной мне причине override выдает здесь ошибку
	{
		 //reuse sphere code
		CollisionPoints points = sphere->TestCollision(sphereTransform, this, transform);
		CollisionPoints points;
		Vec2d T = points.A; // You could have an algo Plane v Sphere to do the swap
		points.A = points.B;
		points.B = T;

		points.Normal = -points.Normal;

		return points;
	}

	CollisionPoints TestCollision(
		const Transform* transform,
		const PlaneCollider* plane,
		const Transform* planeTransform) const override
	{
		return {}; // No plane v plane
	}
};