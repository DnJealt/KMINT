#pragma once
#include <string>

#include "IGameObject.h"

#include "IdleState.h"
#include "ChaseState.h"
#include "PillState.h"

class Game;

class Ghost : public IGameObject {
public:
	Ghost(Vertex* start, Game* game);
	~Ghost();
	void Update(float deltaTime);

	void checkState();
	int speedmultiplier = pk.GetRandomNumber(1, 3);
	const int getWanderingTime() const;
	Game* getGame() const;
	void swapState(const int state);
	void setSpeed(int speed);
private:
	float totalTime = 0;
	GhostState* state;
	Game* game;

	// Ghost may wander around for 2 to 10 seconds
	int wanderingTime = pk.GetRandomNumber(2, 11);
	void updateState(GhostState* state);
	
	
};