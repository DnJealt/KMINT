#pragma once
#include "Steering.h"
#include <vector>

class DeadGhost;

class SteeringBehaviors
{

private:
	enum State 
	{ 
		Wandering = 1,
		Following,
		Arriving,
		Fleeing 
	};

	State currentState;

public:
	SteeringBehaviors();
	~SteeringBehaviors();

	Steering calculate(int x, int y);
	Steering calcWandering(int x, int y);
	Steering calcFollowing(int x, int y);
	Steering calcArriving(int x, int y);
	Steering calcFleeing(int x, int y);





};

