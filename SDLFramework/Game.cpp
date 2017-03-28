#include "Game.h"

Game::Game(FWApplication* application, bool debug) {
	this->application = application;
	this->application->SetTargetFPS(60);
	this->application->SetColor(Color(255, 10, 40, 255));

	auto background = this->application->LoadTexture("background.png");

	this->pacman = new Pacman(r.pacmanStart, this);
	this->application->AddRenderable(pacman);

	if (!debug) {
		for (unsigned i = 0; i < 100; ++i) {
			Ghost* temp;
			if (i < 25) {
				temp = new Ghost(r.ghostStart1, this);
			}
			else if (i < 50) {
				temp = new Ghost(r.ghostStart2, this);
			}
			else if (i < 75) {
				temp = new Ghost(r.ghostStart3, this);
			}
			else {
				temp = new Ghost(r.ghostStart4, this);
			}
			ghosts.push_back(temp);
			this->application->AddRenderable(temp);
		}
	}
	else {
		for (unsigned i = 0; i < 4; ++i) {
			Ghost* temp;
			if (i == 0) {
				temp = new Ghost(r.ghostStart1, this);
			}
			else if (i == 1) {
				temp = new Ghost(r.ghostStart2, this);
			}
			else if (i == 2) {
				temp = new Ghost(r.ghostStart3, this);
			}
			else {
				temp = new Ghost(r.ghostStart4, this);
			}
			ghosts.push_back(temp);
			this->application->AddRenderable(temp);
		}
	}

	for (unsigned i = 0; i < 100; ++i) {
		DeadGhost* temp;
		temp = new DeadGhost(this);
		deadghosts.push_back(temp);
		application->AddRenderable(temp);
	}

	while (this->application->IsRunning())
	{
		this->application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				this->application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_g: // Letter G
					std::cout << "keypressed! \n";
					this->application->EndTick();
					for (int i = 0; i < 10; ++i) {
						this->application->StartTick();
						this->application->UpdateGameObjects(true);
					}
						/*this->application->RenderGameObjects();
						this->application->EndTick();*/
					break;
				default:
					break;
				}
			}
		}

		// DRAW FUNCTIONS
		this->application->SetColor(Color(255, 255, 255, 255));
		this->application->DrawTexture(background, 0, 0);

		this->application->DrawGraph(r.getGraph(), debug);

		this->application->UpdateGameObjects();
		this->application->RenderGameObjects();

		this->application->SetColor(Color(0, 0, 0, 255));
		this->application->DrawRect(575, 0, 25, 600, true);
		this->application->SetColor(Color(255, 255, 255, 255));
		this->application->DrawText(std::to_string(pacman->hp), 290, 285);
		if (pacman->hp <= 0) {
			this->nextGeneration();
		}
		this->application->EndTick();

	}
}

void Game::addDeadGhost(int i) {
	// Set the ghost at the designated hp spot of pacman active.
	deadghosts.at(i)->SetActive(true);
}

const Pacman* Game::getPacman() const {
	return this->pacman;
}

Graph Game::getMap() {
	return r.getGraph();
}

void Game::nextGeneration() {
	if (averageTime == 0) {
		std::cout << "There was no average time to begin with, so the chances are all 33.3." << std::endl;
	}
	float totalGhostTime = 0;
	for (unsigned i = 0; i < ghosts.size(); ++i) {
		totalGhostTime += ghosts.at(i)->getTotalTime();
	}
	this->averageTime = totalGhostTime / 100;

	if (averageTime != 0) {
		std::cout << "--- NEXT GENERATION ---" << std::endl;
		std::cout << "--- Chase: " << this->chaseChance << " ---" << std::endl;
		std::cout << "--- Idle: " << this->idleChance << " ---" << std::endl;
		std::cout << "--- Pill: " << this->pillChance << " ---" << std::endl;
		std::cout << "-----------------------" << std::endl;
	}

	this->pacman->reset();
	
	for (unsigned i = 0; i < ghosts.size(); ++i) {
		ghosts.at(i)->reset();
	}
	for (unsigned i = 0; i < deadghosts.size(); ++i) {
		deadghosts.at(i)->reset();
	}
}

void Game::increaseChance(int state) {
	// Set boundaries for given chances
	if (idleChance > 10 && pillChance > 10) {
		if (chaseChance < 90) {
			if (state == 0) {
				this->chaseChance += 0.4;
				this->idleChance -= 0.2;
				this->pillChance -= 0.2;
			}
		}
	}
	if (chaseChance > 10 && pillChance > 10) {
		if (idleChance < 90) {
			if (state == 1) {
				this->idleChance += 0.4;
				this->chaseChance -= 0.2;
				this->pillChance -= 0.2;
			}
		}
	}
	if (idleChance > 10 && chaseChance > 10) {
		if (pillChance < 90) {
			if (state == 2) {
				this->pillChance += 0.4;
				this->chaseChance -= 0.2;
				this->idleChance -= 0.2;
			}
		}
	}
}

const float Game::getAverageTime() const {
	return this->averageTime;
}
