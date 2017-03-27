#pragma once
#include "Steering.h"
#include <vector>

class Game;
class DeadGhost;

class SteeringBehaviors
{

private:
	Game* game;
	DeadGhost* deadghost;
	const float alignmentWeight = 500;
	const float cohesionWeight = 150;
	const float separationWeight = 1000;

public:
	SteeringBehaviors(Game* game, DeadGhost* deadghost);
	~SteeringBehaviors();

	Steering calculate();
	Steering calculateAlignment();
	Steering calculateCohesion();
	Steering calculateSeparation();




};

