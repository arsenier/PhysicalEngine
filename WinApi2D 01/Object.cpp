#include "Object.h"

void Object::Nullify()
{
	Position = Vec2d(0, 0);
	Velocity = Vec2d(0, 0);
	Force = Vec2d(0, 0);
	mass = 1;
	color = 0xFFFFFF;
}

Object::Object()
{
	Nullify();
}

Object::Object(Object& object)
{
	this->Position = object.Position;
	this->Velocity = object.Velocity;
	this->Force = object.Force;
	this->mass = object.mass;
	this->color = object.color;
}

Object::Object(Vec2d _Position, Vec2d _Velocity)
{
	Nullify();
	this->Position = _Position;
	this->Velocity = _Velocity;
}