#pragma once
#include "Object.h"
#include "Renderer.h"
#include "RectCollider.h"

class Rect :
    public Object
{
protected:
public:
    RectCollider* rectCollider;
    Rect(Vec2d _Position, double _width, double _height, Vec2d _Velocity, double _mass, COLORREF _color) :
        Object(_Position, _Velocity, _mass, _color)
    {
        this->rectCollider = new RectCollider;
        this->collider = this->rectCollider;
        //this->r = _r;
        this->rectCollider->width = _width;
        this->rectCollider->height = _height;
    }
    Rect() {
        this->rectCollider = new RectCollider;
        this->collider = this->rectCollider;
    }

    ~Rect() {
        delete this->rectCollider;
    }

    void draw(Renderer& renderer)
    {
        setcolor(color);
        /*double tempWidth = renderer.T(this->rectCollider->width);
        double tempHeight = renderer.T(this->rectCollider->height);
        Vec2d tempPos = renderer.T(this->transform->Position);
        
        if (tempWidth > 1 && tempHeight > 1) {
            putline(tempPos.mData[0], tempPos.mData[1], tempPos.mData[0] + tempWidth, tempPos.mData[1]);
            putline(tempPos.mData[0] + tempWidth, tempPos.mData[1], tempPos.mData[0] + tempWidth, tempPos.mData[1]+tempHeight);
            putline(tempPos.mData[0] + tempWidth, tempPos.mData[1] + tempHeight, tempPos.mData[0], tempPos.mData[1] + tempHeight);
            putline(tempPos.mData[0], tempPos.mData[1] + tempHeight, tempPos.mData[0], tempPos.mData[1]);
            
        }
        else if (tempWidth < 1 && tempHeight < 1) {
            putpixel(tempPos.mData[0], tempPos.mData[1], color);
        }
        else if (tempWidth < 1) {
            putline(tempPos.mData[0], tempPos.mData[1] + tempHeight, tempPos.mData[0], tempPos.mData[1]);
        }
        else if (Height < 1) {
            putline(tempPos.mData[0], tempPos.mData[1], tempPos.mData[0] + tempWidth, tempPos.mData[1]);
        }*/


        //Try 4 ======================================

        Vec2d tempLT = renderer.T(Vec2d(this->transform->Position.mData[0], this->transform->Position.mData[1]));
        Vec2d tempRB = renderer.T(Vec2d(this->transform->Position.mData[0] + this->rectCollider->width, this->transform->Position.mData[1] - this->rectCollider->height));
        double tempWidth = fabs(tempLT.mData[0] - tempRB[0]);
        double tempHeight = fabs(tempLT.mData[1] - tempRB[1]);
        if (tempWidth > 1 && tempHeight > 1) {
            putline(tempLT.mData[0], tempLT.mData[1], tempRB.mData[0], tempLT.mData[1]);
            putline(tempRB.mData[0], tempLT.mData[1], tempRB.mData[0], tempRB.mData[1]);
            putline(tempLT.mData[0], tempRB.mData[1], tempRB.mData[0], tempRB.mData[1]);
            putline(tempLT.mData[0], tempRB.mData[1], tempLT.mData[0], tempLT.mData[1]);

        }
        else if (tempWidth < 1 && tempHeight < 1) {
            putpixel(tempLT.mData[0], tempLT.mData[1], color);
        }
        else if (tempWidth < 1) {
            putline(tempLT.mData[0], tempLT.mData[1], tempLT.mData[0], tempRB.mData[1]);
        }
        else if (Height < 1) {
            putline(tempLT.mData[0], tempLT.mData[1], tempRB.mData[0], tempLT.mData[1]);
        }


        //Done ==========================================

        
    }
};

