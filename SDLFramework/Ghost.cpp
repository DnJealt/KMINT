#include "Ghost.h"
#include <SDL_render.h>

Ghost::Ghost(Vertex* start) {
	texture = mApplication->LoadTexture("ghost_idle.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
	this->node = start;
	this->speed = 2;
	this->mX = node->getX();
	this->mY = node->getY();
}

Ghost::~Ghost() {
	SDL_DestroyTexture(texture);
}

void Ghost::Update(float deltaTime) {
	this->Move();
}