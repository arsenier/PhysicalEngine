#include "Algo.h"
#include "CircleCollider.h"
#include "RectCollider.h"

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


CollisionPoints FindCirclePlaneCollisionPoints(
	const CircleCollider* a, const Transform* ta,
	const Vec2d& A, const Vec2d& B) {

	Vec2d v01 = A - ta->Position;
	Vec2d v02 = B - ta->Position;

	Vec2d d = v02 - v01;

	double na = d.mData[0] * d.mData[0] + d.mData[1] * d.mData[1];
	double b = 2.0f * (v01.mData[0] * d.mData[0] + v01.mData[1] * d.mData[1]);
	double c = v01.mData[0] * v01.mData[0] + v01.mData[1] * v01.mData[1] - a->Radius * a->Radius;

	bool flagCollision = false;

	if (-b < 0) flagCollision = c < 0;
	else if (-b < (2.0f * na)) flagCollision = (4.0f * na * c - b * b) < 0;
	else flagCollision = na + b + c < 0;

	CollisionPoints result;

	result.HasCollision = flagCollision;

	if (flagCollision) {
		if (A.mData[0] == B.mData[0]) {

			if (ta->Position.mData[0] <= A.mData[0]) {
				if (ta->Velocity.mData[0] > 0) { result.Normal = Vec2d(-ta->Velocity.mData[0], ta->Velocity.mData[1]); normalize(result.Normal);}
				else result.Normal = Vec2d(0, 0);
			}
			else {
				if (ta->Velocity.mData[0] < 0) { result.Normal = Vec2d(-ta->Velocity.mData[0], ta->Velocity.mData[1]); normalize(result.Normal);}
				else result.Normal = Vec2d(0, 0);
			}
		}
		else if (A.mData[1] == B.mData[1]) {
			if (ta->Position.mData[1] <= A.mData[1]) {
				if (ta->Velocity.mData[1] > 0) { result.Normal = Vec2d(ta->Velocity.mData[0], -ta->Velocity.mData[1]); normalize(result.Normal);}
				else result.Normal = Vec2d(0, 0);
			}
			else {
				if (ta->Velocity.mData[1] < 0) { result.Normal = Vec2d(ta->Velocity.mData[0], -ta->Velocity.mData[1]); normalize(result.Normal);}
				else result.Normal = Vec2d(0, 0);
			}
		}
	}

	return result;

}

CollisionPoints FindCircleRectCollisionPoints(
	const CircleCollider* a, const Transform* ta,
	const RectCollider* b, const Transform* tb) {

	CollisionPoints result;
	result = FindCirclePlaneCollisionPoints(a, ta, Vec2d(tb->Position.mData[0], tb->Position.mData[1]), Vec2d(tb->Position.mData[0] + b->width, tb->Position.mData[1]));
	if (result.HasCollision) return result;
	result = FindCirclePlaneCollisionPoints(a, ta, Vec2d(tb->Position.mData[0] + b->width, tb->Position.mData[1]), Vec2d(tb->Position.mData[0] + b->width, tb->Position.mData[1] - b->height));
	if (result.HasCollision) return result;
	result = FindCirclePlaneCollisionPoints(a, ta, Vec2d(tb->Position.mData[0], tb->Position.mData[1] - b->height), Vec2d(tb->Position.mData[0] + b->width, tb->Position.mData[1] - b->height));
	if (result.HasCollision) return result;
	result = FindCirclePlaneCollisionPoints(a, ta, Vec2d(tb->Position.mData[0], tb->Position.mData[1] - b->height), Vec2d(tb->Position.mData[0], tb->Position.mData[1]));
	if (result.HasCollision) return result;
	return result;

}