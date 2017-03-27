#pragma once
#include "IGameObject.h"

class Game;

class Pacman : public IGameObject {
public:
	Pacman(Vertex* node, Game* game);
	~Pacman();
	void Update(float deltaTime);

	void OnCollision(IGameObject * collidedObject);
	Game* game;
	int hp;
private:
	SDL_Texture *texture;
};