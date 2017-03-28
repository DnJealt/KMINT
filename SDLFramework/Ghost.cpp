#include "Ghost.h"
#include <SDL_render.h>

Ghost::Ghost(Vertex* start, Game* game) : game { game } {
	this->SetTexture(mApplication->LoadTexture("ghost_idle.png"));
	this->SetSize(30, 30);
	this->node = start;
	this->speed = 3;
	this->isFirstState = true;
	this->mX = node->getX();
	this->mY = node->getY();
	this->startNode = node;
	this->startX = node->getX();
	this->startY = node->getY();
	this->state = new IdleState(this);
}

Ghost::~Ghost() {
	SDL_DestroyTexture(mTexture);
	mApplication->RemoveRenderable(this);
}

void Ghost::Update(float deltaTime) {
	totalTime += deltaTime;
	if (IsActive()) {
		this->state->Move(totalTime);
	}
}

void Ghost::swapState(const int state) {
	if (isFirstState) {
		this->setFirstState(state);
		isFirstState = false;
	}
	
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
		int draw = pk.GetRandomNumber(0, 100);
		if (draw < this->game->chaseChance) {
			swapState(0);
			//std::cout << "Ghost drew " << draw << " and switched to chase!" << std::endl;
		}
		else if (draw < this->game->idleChance + this->game->chaseChance) {
			swapState(1);
			//std::cout << "Ghost drew " << draw << " and stayed in idle!" << std::endl;
		}
		else {
			swapState(2);
			//std::cout << "Ghost drew " << draw << " and switched to pill!" << std::endl;
		}
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

void Ghost::reset() {
	this->SetActive(true);
	this->SetTexture(mApplication->LoadTexture("ghost_idle.png"));
	this->state = new IdleState(this);
	this->isFirstState = true;
	this->mX = this->startX;
	this->mY = this->startY;
	this->setNode(this->startNode);
	this->speed = 3;
	this->totalTime = 0;
}
