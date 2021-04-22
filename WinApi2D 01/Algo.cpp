#include "Algo.h"
#include "CircleCollider.h"

CollisionPoints FindCircleCircleCollisionPoints(
	const CircleCollider* a, const Transform* ta,
	const CircleCollider* b, const Transform* tb) {

	double r = a->Radius + b->Radius;
	r *= r;
	CollisionPoints result;
	auto xa = ta->Position.mData[0];
	auto ya = ta->Position.mData[1];
	auto xb = tb->Position.mData[0];
	auto yb = tb->Position.mData[1];
	result.HasCollision = r > (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
	if (result.HasCollision) {
		Vec2d Normal = ta->Position - tb->Position;
		result.Normal = Normal;
		normalize(result.Normal);
	}
	return result;
}