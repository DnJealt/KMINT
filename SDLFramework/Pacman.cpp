#include "Pacman.h"
#include <SDL_render.h>

Pacman::Pacman(Vertex* node) {
	texture = mApplication->LoadTexture("pacman.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
	this->hp = 100;
	this->node = node;
	this->speed = 2;
	this->mX = node->getX();
	this->mY = node->getY();
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
	}
}