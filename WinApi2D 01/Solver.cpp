#include "Solver.h"
#include <algorithm>

double absOfVec2d(const Vec2d& v1) {
	return sqrt(v1.mData[0]* v1.mData[0] + v1.mData[1]* v1.mData[1]);
}

void Solver::ResolveCollision(Collision& collision, double dtms)
{	
	if (collision.Points.Normal.mData[0] == 0 && collision.Points.Normal.mData[1] == 0) return;
	Vec2d rv = collision.ObjB->transform->Velocity - collision.ObjA->transform->Velocity;
	double velAlongNormal = gmtl::dot(rv, collision.Points.Normal);
	//if (velAlongNormal > 0) return;
	if (collision.ObjA->mass && collision.ObjB->mass) {
		if (velAlongNormal > 0) return;	//если скорости противоположны
	}
	else {
		
		if (collision.ObjA->mass) {
			collision.ObjA->transform->Velocity = collision.Points.Normal * absOfVec2d(collision.ObjA->transform->Velocity);
			return;
		}
		else {
			collision.ObjB->transform->Velocity = collision.Points.Normal * absOfVec2d(collision.ObjB->transform->Velocity);
			return;
		}
	}
	double e = 1; //упругость материала (Можно потом прикрутить к объекту)

	double j = -(1 + e) * velAlongNormal;
	j /= collision.ObjA->invMass + collision.ObjB->invMass;

	Vec2d impulse = j * collision.Points.Normal;
	collision.ObjA->transform->Velocity -= collision.ObjA->invMass * impulse;
	collision.ObjB->transform->Velocity += collision.ObjB->invMass * impulse;
}	


void Solver::Solve(std::vector<Collision>& collisions, double dtms)
{
	for (auto it = collisions.begin(); it != collisions.end(); ++it)
	{
		ResolveCollision(*it, dtms);
		//collisions.pop_back();
	}
}