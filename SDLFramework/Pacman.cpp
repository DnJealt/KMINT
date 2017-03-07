#include "Pacman.h"
#include <SDL_render.h>

Pacman::Pacman(Vertex* node, std::vector<DeadGhost*>* deadghosts) {
	texture = mApplication->LoadTexture("pacman.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
	this->hp = 100;
	this->node = node;
	this->speed = 11;
	this->mX = node->getX();
	this->mY = node->getY();
	this->deadghosts = deadghosts;
}

Pacman::~Pacman() {
	SDL_DestroyTexture(texture);
}

void Pacman::Update(float deltaTime) {
	this->Move();
}

void Pacman::OnCollision(IGameObject* collidedObject) {
	if (collidedObject != nullptr && collidedObject->IsActive()) {
		collidedObject->SetActive(false);
		this->hp--;
		this->speed = (this->hp / 10)+1;
		this->deadghosts->at(this->hp)->SetActive(true);
	}
}