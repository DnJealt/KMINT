#pragma once

#include "GhostState.h"
#include <vector>
#include "AStar.h"
#include "Game.h"
#include "Ghost.h"

class PillState : public GhostState {
public:
	PillState(Ghost* ghost);
	~PillState();

	void Move(int totalTime) override;

	std::vector<Vertex*> shortestPath;
	int pathCount = 0;
private:
	bool hasMoved = false;
};
