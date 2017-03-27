#pragma once
#include <string>

#include "IGameObject.h"

class Ghost : public IGameObject {
public:
	Ghost(Vertex* start);
	~Ghost();
	void Update(float deltaTime);

	

private:
	float totalTime = 0;
	SDL_Texture *texture;

	int wanderingTime = pk.GetRandomNumber(2, 11);

	void swapState(const int state);
	void checkState();
};