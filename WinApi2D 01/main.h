#pragma once
#include "Renderer.h"
#include "PhysicsWorld.h"
#include "Circle.h"
#include "Rect.h"
#include <vector>

int count = -1;

enum
{
	physTimer = 1,
	graphTimer
};

Renderer renderer;
PhysicsWorld world;

std::vector<Circle> circles(7);
//Circle circle(Vec2d(10, 0), Vec2d(-1, 0), 150, 15, 0xFFFFFF);
//Circle circle2(Vec2d(0, 50), Vec2d(1, 0)*10.0, 100, 10, 0x0000FF);
Rect rect(Vec2d(-30, -30), 40, 40, Vec2d(0, 0), 0, 0xFFFFFF);
Circle circle3(Vec2d(-18, -43), Vec2d(1, 0.5) * 30.0, 10, 1, 0x0060B3);
Circle circle4(Vec2d(-25, -43), Vec2d(2, 0.5) * 30.0, 10, 1, 0x0000B3);
Circle circle5(Vec2d(-25, -56), Vec2d(-1, 3) * 30.0, 10, 1, 0x000011);
Circle circle6(Vec2d(-17, -68), Vec2d(5, -4) * 30.0, 10, 1, 0x001589);
Circle circle7(Vec2d(-26, -53), Vec2d(5, -4) * 30.0, 10, 1, 0x001589);
Circle circle8(Vec2d(-26, -40), Vec2d(5, -4) * 30.0, 10, 1, 0x001589);

void OnCreate(const HWND& hWnd)
{
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i].transform->Position = Vec2d(rand()%100, rand()%100);
		circles[i].transform->Velocity = Vec2d(rand() % 10, rand() % 10);
		circles[i].mass = 1;
		circles[i].invMass = 1;
		circles[i].cirlceCollider->Radius = 1;
		circles[i].color = 0xFFFFFF;

		world.AddObject(&circles[i]);
		renderer.AddObject(&circles[i]);
	}

	/*world.AddObject(&circle);
	renderer.AddObject(&circle);
	world.AddObject(&circle2);
	renderer.AddObject(&circle2);*/
	world.AddObject(&circle3);
	world.AddObject(&circle4);
	world.AddObject(&circle5);
	world.AddObject(&circle6);
	world.AddObject(&circle7);
	world.AddObject(&circle8);
	renderer.AddObject(&circle3);
	renderer.AddObject(&circle4);
	renderer.AddObject(&circle5);
	renderer.AddObject(&circle6);
	renderer.AddObject(&circle7);
	renderer.AddObject(&circle8);
	world.AddObject(&rect);
	renderer.AddObject(&rect);
	renderer.setScale(4);
	SetTimer(hWnd, graphTimer, 1, NULL);
	clrscr();
}

void OnTimer(const WPARAM& wParam)
{
	switch (wParam)
	{
	case physTimer:
	{
		for (int i = 0; i < 10; i++)	world.Step(1);
		break;
	}
	case graphTimer:
	{
		GFlush();
		break;
	}
	}
}

void OnKeyPress(const WPARAM& wParam)
{
	switch (wParam)
	{
	case VK_UP:
		renderer.move(Vec2d(0, renderer.getMovRate()));
		break;
	case VK_DOWN:
		renderer.move(Vec2d(0, -renderer.getMovRate()));
		break;
	case VK_LEFT:
		renderer.move(Vec2d(-renderer.getMovRate(), 0));
		break;
	case VK_RIGHT:
		renderer.move(Vec2d(renderer.getMovRate(), 0));
		break;
	case VK_SPACE:
		world.Step(10);
		break;
	case 0x4E://Press 'N' - Next
		if (++count == world.getObjects().size()) count = -1;
		break;
	}
}

void OnCharPress(const HWND& hWnd, const WPARAM& wParam)
{
	switch (wParam)
	{
	case '=':
		renderer.zoom(1.1);
		break;
	case '-':
		renderer.zoom(0.90909090909);
		break;
	case '1':
		SetTimer(hWnd, physTimer, 10, NULL);
		break;
	case '0':
		KillTimer(hWnd, physTimer);
		break;
	}
}

void OnDraw()
{
	clrscr();
	renderer.DrawGrid();
	renderer.drawAll();
	if (count == -1);
	else {
		auto temp = world.getObjects()[count]->transform->Position;
		renderer.setPosition(temp);
	}
}