#include "DeadGhost.h"
#include <SDL_render.h>

DeadGhost::DeadGhost() {
	texture = mApplication->LoadTexture("ghost_angel.png");
	this->SetTexture(texture);
	this->SetSize(60, 60);
	this->speed = 5;
	this->mX = 900;
	this->mY = 300;
	this->mIsActive = false;
	this->angle = 0;
}

DeadGhost::~DeadGhost() {
	SDL_DestroyTexture(texture);
}

void DeadGhost::Update(float deltaTime) {
	if (this->mX < 600) this->mX = 1200;
	if (this->mX > 1200) this->mX = 600;
	if (this->mY < 10) this->mY = 590;
	if (this->mY > 590) this->mY = 10;
	if (this->angle > 99) this->angle = 0;
	if (this->angle < 0) this->angle = 99;
	this->mX += speed * sin(angle);
	this->mY += speed * cos(angle);
	if (pk.GetRandomNumber(0, 2) == 1) {
		this->angle += 0.1;
	}
	else {
		this->angle -= 0.1;
	}
	this->SetOffset(this->mX, this->mY);
}