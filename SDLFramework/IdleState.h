#pragma once

#include "GhostState.h"
#include "Pocketknife.h"

class IdleState : public GhostState {
private:
	Pocketknife pk;
public:
	IdleState(Ghost* ghost);
	~IdleState();

	void Move(int totalTime) override;
};