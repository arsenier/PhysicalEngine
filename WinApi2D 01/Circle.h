#pragma once
#include "Object.h"
#include "Renderer.h"
#include "CircleCollider.h"
#include "PlaneCollider.h"
class Circle :
    virtual public Object
{
protected:
public:
    int r;
    Circle(Vec2d _Position, Vec2d _Velocity, double _mass, int _r, COLORREF _color) : Object(_Position, _Velocity, _mass, _color)
    {
        this->r = _r;
    }
    Circle() {}

    void draw(Renderer& renderer)
    {
        setcolor(color);
        Vec2d temp = renderer.T(Position);
        if (renderer.T(r) > 1) putarc(temp[0], temp[1], renderer.T(r), 0, Math::TWO_PI);
        else putpixel(temp[0], temp[1], color);
    }
};

