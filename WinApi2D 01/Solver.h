#pragma once
#include <vector>
#include "Collision.h"

class Solver {
private:
	void ResolveCollision(Collision& collision, double dtms);
public:
	virtual void Solve(std::vector<Collision>& collisions, double dtms);
};