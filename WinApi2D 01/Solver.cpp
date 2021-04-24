#include "Solver.h"

void Solver::ResolveCollision(Collision& collision, double dtms)
{	
	Vec2d rv = collision.ObjB->Velocity - collision.ObjA->Velocity;
	double velAlongNormal = gmtl::dot(rv, collision.Points.Normal);
	
	if (velAlongNormal > 0) return;	//если скорости противоположны
	
	double e = 0.7; //упругость материала (Можно потом прикрутить к объекту)

	double j = -(1 + e) * velAlongNormal;
	j /= 1 / collision.ObjA->mass + 1 / collision.ObjB->mass;

	Vec2d impulse = j * collision.Points.Normal;
	collision.ObjA->Velocity -= 1 / collision.ObjA->mass * impulse;
	collision.ObjB->Velocity += 1 / collision.ObjB->mass * impulse;

}	

void Solver::Solve(std::vector<Collision>& collisions, double dtms)
{
	for (auto it = collisions.begin(); it != collisions.end(); ++it)
	{
		ResolveCollision(*it, dtms);
		//collisions.pop_back();
	}
}