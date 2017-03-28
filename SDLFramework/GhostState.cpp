#include "GhostState.h"
#include "Ghost.h"

GhostState::GhostState(Ghost* ghost, const std::string stateName) 
	: State(ghost, stateName), ghost{ ghost } {}

GhostState::~GhostState() {}