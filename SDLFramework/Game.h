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
	Game(FWApplication* application);
	~Game();
	std::vector<Ghost*> ghosts;
	std::vector<DeadGhost*> deadghosts;
	void addDeadGhost(int i);
	const Pacman* getPacman() const;
	
	Graph* getMap();

private:
	Rift r;
	Pocketknife pk;
	Pacman* pacman;
	const bool debug = true;
	FWApplication* application;
};