#include "Ghost.h"
#include <SDL_render.h>

Ghost::Ghost(Vertex* start) {
	texture = mApplication->LoadTexture("ghost_idle.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
	this->node = start;
	this->speed = 5;
	this->mX = node->getX();
	this->mY = node->getY();
}

Ghost::~Ghost() {
	SDL_DestroyTexture(texture);
}

void Ghost::Update(float deltaTime) {
	totalTime += deltaTime;
	this->Move();	
	checkState();	
}

void Ghost::swapState(const int state) {
	if (state == 0) {
		this->SetTexture(mApplication->LoadTexture("ghost_chase_pacman.png"));
	}
	else if (state == 1) {
		this->SetTexture(mApplication->LoadTexture("ghost_idle.png"));
	}
	else if (state == 2) {		
		this->SetTexture(mApplication->LoadTexture("ghost_chase_powerpill.png"));
	}
}

void Ghost::checkState() {
	if (totalTime > wanderingTime) {
		totalTime = 0;
		swapState(pk.GetRandomNumber(0, 3));
	}
}