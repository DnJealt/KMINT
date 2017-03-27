#pragma once

#include "GhostState.h"

class ChaseState : public GhostState {
public:
	ChaseState(Ghost* ghost);
	~ChaseState();

	void Move(int totalTime) override;
};
