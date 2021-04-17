#include "Circle.h"

Circle::Circle(Vec2d _Position, Vec2d _Velocity, double _mass, int _r, COLORREF _color) : Object(_Position, _Velocity, _mass, _color)
{
    this->circleCollider = new CircleCollider;
    this->collider = this->circleCollider;
    this->r = _r;
}

Circle::Circle() {}

Circle::~Circle()
{
    delete this->circleCollider;
}