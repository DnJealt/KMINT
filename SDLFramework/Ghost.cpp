#include "Ghost.h"
#include <SDL_render.h>

Ghost::Ghost() {
	texture = mApplication->LoadTexture("ghost_idle.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
}

Ghost::~Ghost() {
	SDL_DestroyTexture(texture);
}

void Ghost::Update(float deltaTime) {
	
}