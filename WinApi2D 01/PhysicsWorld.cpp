#include "PhysicsWorld.h"

void PhysicsWorld::AddObject(Object* object)
{
	m_objects.push_back(object);
}

void PhysicsWorld::RemoveObject(Object* object)
{
	if (!object) return;
	auto itr = std::find(m_objects.begin(), m_objects.end(), object);
	if (itr == m_objects.end()) return;
	m_objects.erase(itr);
}

void PhysicsWorld::ResolveCollision(double dtms) {
	std::vector<Collision> collisions;
	for (Object* a : m_objects) {
		for (Object* b : m_objects) {
			if (a == b) break;

			if (!a->collider
				|| !b->collider)
			{
				continue;
			}

			CollisionPoints points = a->collider->TestCollision(
				a->transform,
				b->collider,
				b->transform);

			if (points.HasCollision) {
				collisions.emplace_back(Collision(a, b, points));
			}
		}
	}
}

void PhysicsWorld::Step(double dtms)
{
	dtms /= 5000;
	Vec2d r;
	double distsqr;
	std::vector<Collision> collisions; //Temp потом удалим. Для быстрой отладки
	for (Object* obj : m_objects)
	{

		for (Object* _obj : m_objects)
		{
			if (obj == _obj) continue;

			r = _obj->transform->Position - obj->transform->Position;
			distsqr = lengthSquared(r);

			normalize(r);

			obj->Force += G * obj->mass * _obj->mass / distsqr * r;
			
			auto test = obj->collider->TestCollision(obj->transform, _obj->collider, _obj->transform);
			if (test.HasCollision) {
				collisions.emplace_back(Collision(obj, _obj, test));
			}
		}
		//obj->Force += obj->mass * m_gravity - obj->Position;
		if (obj->mass != 0){
			obj->transform->Velocity += obj->Force * obj->invMass * dtms;
			obj->transform->Position += obj->transform->Velocity * dtms;

			obj->Force = Vec2d(0, 0);
		}
	}
	solver.Solve(collisions, dtms);
}

std::vector<Object*> PhysicsWorld::getObjects() {
	return m_objects;
}