#pragma once

#include "IGameObject.h"

class Pacman : public IGameObject {
public:
	Pacman(Vertex* node);
	~Pacman();
	void Update(float deltaTime);

	void OnCollision(IGameObject * collidedObject);

	int hp;
private:
	SDL_Texture *texture;
};