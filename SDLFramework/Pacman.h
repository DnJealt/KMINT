#pragma once

#include "IGameObject.h"

class Pacman : public IGameObject {
public:
	Pacman(Vertex* node);
	~Pacman();
	void Update(float deltaTime);

	int hp;
private:
	SDL_Texture *texture;
};