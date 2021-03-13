#pragma once
#include "Object.h"
class Circle :
    virtual public Object
{
protected:
    int r;
public:
    Circle(Vec2d _Position, Vec2d _Velocity, double _mass, int _r, COLORREF _color) : Object(_Position, _Velocity, _mass, _color)
    {
        this->r = _r;
    }

    void draw()
    {
        putarc(Position[0], Position[1], r, 0, Math::TWO_PI);
    }
};

