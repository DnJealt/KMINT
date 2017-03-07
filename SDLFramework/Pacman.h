#pragma once

#include "IGameObject.h"

class Pacman : public IGameObject {
public:
	Pacman();
	~Pacman();
	void Update(float deltaTime);

private:
	SDL_Texture *texture;
};