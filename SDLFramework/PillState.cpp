#include "PillState.h"
#include "Ghost.h"

PillState::PillState(Ghost* ghost) : GhostState(ghost) {}
PillState::~PillState() {}

void PillState::Move(int totalTime) {
	if (totalTime > ghost->getWanderingTime()) {
		ghost->checkState();
	}
}
