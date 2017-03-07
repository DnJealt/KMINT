#pragma once

#include "IGameObject.h"

class Ghost : public IGameObject {
public:
	Ghost();
	~Ghost();
	void Update(float deltaTime);

private:
	SDL_Texture *texture;
};