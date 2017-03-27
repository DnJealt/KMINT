#include "ChaseState.h"
#include "Ghost.h"

ChaseState::ChaseState(Ghost* ghost) : GhostState(ghost) {}
ChaseState::~ChaseState() {}

void ChaseState::Move(int totalTime)
{}
