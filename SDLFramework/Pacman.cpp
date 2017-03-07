#include "Pacman.h"
#include <SDL_render.h>

Pacman::Pacman() {
	texture = mApplication->LoadTexture("pacman.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}

Pacman::~Pacman() {
	SDL_DestroyTexture(texture);
}

void Pacman::Update(float deltaTime) {
	const int x = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 400);
	SetOffset(x, 250);
}