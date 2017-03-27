#include "Game.h"

Game::Game(FWApplication* application) {
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
				temp = new Ghost(r.ghostStart1);
			}
			else if (i < 50) {
				temp = new Ghost(r.ghostStart2);
			}
			else if (i < 75) {
				temp = new Ghost(r.ghostStart3);
			}
			else {
				temp = new Ghost(r.ghostStart4);
			}
			ghosts.push_back(temp);
			this->application->AddRenderable(temp);
		}
	}
	else {
		for (unsigned i = 0; i < 4; ++i) {
			Ghost* temp;
			if (i == 0) {
				temp = new Ghost(r.ghostStart1);
			}
			else if (i == 1) {
				temp = new Ghost(r.ghostStart2);
			}
			else if (i == 2) {
				temp = new Ghost(r.ghostStart3);
			}
			else {
				temp = new Ghost(r.ghostStart4);
			}
			ghosts.push_back(temp);
			this->application->AddRenderable(temp);
		}
	}

	for (unsigned i = 0; i < 10; ++i) {
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
		this->application->DrawText(std::to_string(pacman->hp), 290, 285);
		this->application->EndTick();

	}
}

void Game::addDeadGhost(int i) {
	deadghosts.at(i)->SetActive(true);
}