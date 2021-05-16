#include "Object.h"

void Object::Nullify()
{
	this->transform->Position = Vec2d(0, 0);
	this->transform->Velocity = Vec2d(0, 0);
	Force = Vec2d(0, 0);
	mass = 1;
	color = 0xFFFFFF;
}

Object::Object(){
	this->transform = new Transform;
}

Object::Object(Object& object)
{
	this->transform = new Transform;
	this->transform->Position = object.transform->Position;
	this->transform->Velocity = object.transform->Velocity;
	this->Force = object.Force;
	this->mass = object.mass;
	this->invMass = object.invMass;
	this->color = object.color;
	
}

Object::Object(Vec2d _Position, Vec2d _Velocity, double _mass, COLORREF _color)
{
	this->transform = new Transform;
	this->transform->Position = _Position;
	this->transform->Velocity = _Velocity;
	this->Force = Vec2d(0, 0);
	this->mass = _mass;
	this->color = _color;
	if (mass == 0) {
		invMass = 0;
	}
	else {
		invMass = 1 / mass;
	}
}

void Object::move(Vec2d offset)
{
	this->transform->Position += offset;
}

Object::~Object() {
	delete this->transform;
}