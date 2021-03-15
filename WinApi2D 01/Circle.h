#pragma once
#include "Object.h"
#include "Renderer.h"
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

    void draw(Renderer& renderer)
    {
        setcolor(color);
        Vec2d temp = renderer.T(Position);
        putarc(temp[0], temp[1], renderer.T(r), 0, Math::TWO_PI);
    }
};

