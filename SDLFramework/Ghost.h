#pragma once

#include "IGameObject.h"

class Ghost : public IGameObject {
public:
	Ghost(Vertex* start);
	~Ghost();
	void Update(float deltaTime);

private:
	SDL_Texture *texture;
};