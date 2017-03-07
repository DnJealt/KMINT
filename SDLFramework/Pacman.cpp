#include "Pacman.h"
#include <SDL_render.h>

Pacman::Pacman(Vertex* node) {
	texture = mApplication->LoadTexture("pacman.png");
	this->SetTexture(texture);
	this->SetSize(30, 30);
	this->hp = 100;
	this->node = node;
}

Pacman::~Pacman() {
	SDL_DestroyTexture(texture);
}

void Pacman::Update(float deltaTime) {
	this->SetOffset(this->node->getX(), this->node->getY());
}