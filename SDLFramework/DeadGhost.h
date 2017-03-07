#pragma once

#include "IGameObject.h"

class DeadGhost : public IGameObject {
public:
	DeadGhost();
	~DeadGhost();
	void Update(float deltaTime);
	float angle;
private:
	SDL_Texture *texture;
};