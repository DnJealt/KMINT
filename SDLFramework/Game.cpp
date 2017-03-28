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

const float Game::getAverageTime() const {
	return this->averageTime;
}

void Game::addAverage(float time) {
	// There is a new dead ghost, increase the number
	deadGhostCount++;

	// Calculate the new average time by deviding the newly added time
	float newAverage = (averageTime + time) / deadGhostCount;


}