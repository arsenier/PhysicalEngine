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

std::vector<Circle> circles(10);
Circle circle(Vec2d(10, 0), Vec2d(-1, 0), 150, 15, 0xFFFFFF);
Circle circle2(Vec2d(0, 50), Vec2d(1, 0)*10.0, 100, 10, 0x0000FF);
Rect rect(Vec2d(-30, -30), 25, 25, Vec2d(0, 0), 100, 0xFFFFFF);


void OnCreate(const HWND& hWnd)
{
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i].transform->Position = Vec2d(rand()%100, rand()%100);
		circles[i].Velocity = Vec2d(rand() % 10, rand() % 10);
		circles[i].mass = 1;
		circles[i].cirlceCollider->Radius = 1;
		circles[i].color = 0xFFFFFF;

		world.AddObject(&circles[i]);
		renderer.AddObject(&circles[i]);
	}

	world.AddObject(&circle);
	renderer.AddObject(&circle);
	world.AddObject(&circle2);
	renderer.AddObject(&circle2);
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