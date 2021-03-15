#include "Renderer.h"

Vec2d Renderer::T(Vec2d vec)
{
	return Vec2d(Width/2, Height/2) + (Vec2d(vec[0], -vec[1]) - Vec2d(camera[0], -camera[1])) * scale;
}

double Renderer::T(double scalar)
{
	return scalar * scale;
}

Renderer::Renderer()
{
	camera = Vec2d(0, 0);
	scale = 1;
	mul = 10;
}

void Renderer::move(Vec2d offset)
{
	camera += offset;
}

void Renderer::setPosition(Vec2d pos)
{
	camera = pos;
}

void Renderer::zoom(double zoom)
{
	scale *= zoom;
}

void Renderer::setScale(double _scale)
{
	scale = _scale;
}

double Renderer::getScale()
{
	return scale;
}

double Renderer::getMovRate()
{
	return mul/scale;
}

void Renderer::DrawGrid(int resolution)
{
	resolution *= scale;
	
	while (resolution < 4) resolution *= 10;

	setcolor(0x606060);

	Vec2d origin(0,0);
	Vec2d Torigin = T(origin);

	for (int x = (int)Torigin[0] % resolution; x <= Height; x += resolution)
	{
		putline(x, 0, x, Height);
	}
	for (int y = (int)Torigin[1] % resolution; y <= Height; y += resolution)
	{
		putline(0, y, Width, y);
	}
	resolution *= 5;
	setcolor(0xA0A0A0);
	for (int x = (int)Torigin[0] % resolution; x <= Height; x += resolution)
	{
		putline(x, 0, x, Height);
	}
	for (int y = (int)Torigin[1] % resolution; y <= Height; y += resolution)
	{
		putline(0, y, Width, y);
	}
	setcolor(0xFFFFFF);
	putline(Torigin[0], 0, Torigin[0], Height);
	putline(0, Torigin[1], Width, Torigin[1]);
}

void Renderer::AddObject(Object* object)
{
	m_objects.push_back(object);
}

void Renderer::RemoveObject(Object* object)
{
	if (!object) return;
	auto itr = std::find(m_objects.begin(), m_objects.end(), object);
	if (itr == m_objects.end()) return;
	m_objects.erase(itr);
}

void Renderer::drawAll()
{
	for (Object* obj : m_objects)
	{
		obj->draw(*this);
	}
}