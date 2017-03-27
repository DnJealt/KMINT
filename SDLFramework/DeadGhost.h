#pragma once

#include "IGameObject.h"
#include "SteeringBehaviors.h"

class DeadGhost : public IGameObject {
public:
	DeadGhost();
	~DeadGhost();
	void Update(float deltaTime);
	float angle;
	float maxSpeed;
private:
	SDL_Texture *texture;
	SteeringBehaviors *behavior;
};