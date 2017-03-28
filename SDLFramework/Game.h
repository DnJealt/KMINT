#pragma once
#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include <vector>

#include "Ghost.h"
#include "DeadGhost.h"
#include "Pacman.h"
#include "Rift.h"
#include "AStar.h"
#include "Pocketknife.h"

class Game {
public:
	Game(FWApplication* application, bool debug = false);
	~Game();
	std::vector<Ghost*> ghosts;
	std::vector<DeadGhost*> deadghosts;
	void addDeadGhost(int i);
	const Pacman* getPacman() const;
	Rift r;
	Graph getMap();
	float averageTime;

	void increaseChance(int state);

	float idleChance = 100 / 3;
	float chaseChance = 100 / 3;
	float pillChance = 100 / 3;

private:
	void nextGeneration();
	const float getAverageTime() const;

	Pocketknife pk;
	Pacman* pacman;
	FWApplication* application;
};