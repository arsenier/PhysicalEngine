#pragma once
#include "CircleCollider.h"
#include "Object.h"
#include "Renderer.h"

class Circle :
    virtual public Object
{
protected:
public:
    int r;
    CircleCollider* circleCollider;

    Circle(Vec2d _Position, Vec2d _Velocity, double _mass, int _r, COLORREF _color);
    Circle();
    virtual ~Circle();

    void draw(Renderer& renderer)
    {
        setcolor(color);
        Vec2d temp = renderer.T(transform->Position);
        if (renderer.T(r) > 1) putarc(temp[0], temp[1], renderer.T(r), 0, Math::TWO_PI);
        else putpixel(temp[0], temp[1], color);
    }
};

