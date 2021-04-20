#pragma once
#include "Object.h"
#include "Renderer.h"
#include "CircleCollider.h"

class Circle :
    public Object
{
protected:
public:
    CircleCollider* cirlceCollider;
    Circle(Vec2d _Position, Vec2d _Velocity, double _mass, int _r, COLORREF _color) : 
        Object(_Position, _Velocity, _mass, _color)
    {
        this->cirlceCollider = new CircleCollider;
        this->collider = this->cirlceCollider;
        //this->r = _r;
        this->cirlceCollider->Radius = _r;
    }
    Circle() {
        this->cirlceCollider = new CircleCollider;
        this->collider = this->cirlceCollider;
    }

    ~Circle() {
        delete this->cirlceCollider;
    }

    void draw(Renderer& renderer)
    {
        setcolor(color);
        Vec2d temp = renderer.T(this->transform->Position);
        if (renderer.T(this->cirlceCollider->Radius) > 1) putarc(temp[0], temp[1], renderer.T(this->cirlceCollider->Radius), 0, Math::TWO_PI);
        else putpixel(temp[0], temp[1], color);
    }
};

