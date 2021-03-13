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

void PhysicsWorld::Step(double dt)
{
	for (Object* obj : m_objects)
	{
		obj->Force += obj->mass * m_gravity;

		obj->Velocity += obj->Force / obj->mass * dt;
		obj->Position += obj->Velocity * dt;

		obj->Force = Vec2d(0, 0);
	}
}