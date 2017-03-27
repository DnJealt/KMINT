#pragma once
#include "DeadGhost.h"
#include "IGameObject.h"

class Pacman : public IGameObject {
public:
	Pacman(Vertex* node, std::vector<DeadGhost*>* deadghosts);
	~Pacman();
	void Update(float deltaTime);

	void OnCollision(IGameObject * collidedObject);
	std::vector<DeadGhost*>* deadghosts;
	int hp;
private:
	//SDL_Texture *texture;
};