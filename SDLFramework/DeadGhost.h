#pragma once

#include "IGameObject.h"
#include "SteeringBehaviors.h"
#include "Steering.h"

class Game;

class DeadGhost : public IGameObject {
public:
	DeadGhost(Game* game);
	~DeadGhost();
	void Update(float deltaTime);
	Steering velocity;
private:
	SDL_Texture *texture;
	SteeringBehaviors *behavior;
	Game* game;
};