#include "Ghost.h"
#include <SDL_render.h>

Ghost::Ghost(Vertex* start, Game* game) : game { game } {
	this->SetTexture(mApplication->LoadTexture("ghost_idle.png"));
	this->SetSize(30, 30);
	this->node = start;
	this->speed = 5;
	this->mX = node->getX();
	this->mY = node->getY();
	this->state = new IdleState(this);
}

Ghost::~Ghost() {
	SDL_DestroyTexture(mTexture);
}

void Ghost::Update(float deltaTime) {
	totalTime += deltaTime;
	if (IsActive()) {
		this->state->Move(totalTime);
	}
}

void Ghost::swapState(const int state) {
	if (state == 0) {
		this->SetTexture(mApplication->LoadTexture("ghost_chase_pacman.png"));
		updateState(new ChaseState(this));
	}
	else if (state == 1) {
		this->SetTexture(mApplication->LoadTexture("ghost_idle.png"));
		updateState(new IdleState(this));
	}
	else if (state == 2) {		
		this->SetTexture(mApplication->LoadTexture("ghost_chase_powerpill.png"));
		updateState(new PillState(this));
	}
}

void Ghost::checkState() {
	if (totalTime > wanderingTime) {
		totalTime = 0;
		swapState(pk.GetRandomNumber(0, 3));
	}
}

void Ghost::updateState(GhostState* state) {
	delete this->state;
	this->state = state;
}

const int Ghost::getWanderingTime() const {
	return this->wanderingTime;
}

Game* Ghost::getGame() const {
	return this->game;
}

State* Ghost::getState() {
	return this->state;
}