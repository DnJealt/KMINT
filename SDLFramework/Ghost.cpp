#include "Ghost.h"
#include <SDL_render.h>

Ghost::Ghost() {
	texture = mApplication->LoadTexture("ghost_idle.png");
	this->SetTexture(texture);
	this->SetSize(50, 50);
}

Ghost::~Ghost() {
	SDL_DestroyTexture(texture);
}

void Ghost::Update(float deltaTime) {
	const int x = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 400);
	SetOffset(x, 250);
}