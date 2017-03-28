#include "Pacman.h"
#include "Game.h"
#include <SDL_render.h>

Pacman::Pacman(Vertex* node, Game* game) {
	this->SetTexture(mApplication->LoadTexture("pacman.png"));
	this->SetSize(30, 30);
	this->hp = 4;
	this->node = node;
	this->speed = 11;
	this->mX = node->getX();
	this->mY = node->getY();
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
		}
	}
}