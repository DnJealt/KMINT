#pragma once
#include "State.h"

class Ghost;

class GhostState : public State{
private:

protected:
	Ghost* ghost;

public:
	GhostState(Ghost* ghost, const std::string stateName);
	~GhostState();

	virtual void Move(int totalTime) = 0;
};
