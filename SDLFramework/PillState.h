#pragma once

#include "GhostState.h"

class PillState : public GhostState {
public:
	PillState(Ghost* ghost);
	~PillState();

	void Move(int totalTime) override;
};
