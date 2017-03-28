#include "Pacman.h"
#include "Game.h"
#include <SDL_render.h>

Pacman::Pacman(Vertex* node, Game* game) {
	this->SetTexture(mApplication->LoadTexture("pacman.png"));
	this->SetSize(30, 30);
	this->hp = 100;
	this->node = node;
	this->speed = 11;
	this->mX = node->getX();
	this->mY = node->getY();
	this->startNode = node;
	this->startX = node->getX();
	this->startY = node->getY();
	this->game = game;
}

Pacman::~Pacman() {
	SDL_DestroyTexture(mTexture);
	mApplication->RemoveRenderable(this);
}

void Pacman::Update(float deltaTime) {	
	this->Move();
}

void Pacman::OnCollision(IGameObject* collidedObject) {
	if (collidedObject != nullptr && collidedObject->IsActive()) {
		std::string state = collidedObject->getState()->getStateName();
		if (state == "chase") {
			collidedObject->SetActive(false);
			this->hp--;
			this->speed = (this->hp / 10)+1;
			this->game->addDeadGhost(this->hp);
			if (collidedObject->getTotalTime() < this->game->averageTime) {
				this->game->increaseChance(collidedObject->getFirstState());
			}
		}
	}
}

void Pacman::reset() {
	this->mX = this->startX;
	this->mY = this->startY;
	this->setNode(this->startNode);
	this->hp = 100;
	this->speed = 11;
}
