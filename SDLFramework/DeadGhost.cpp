#include "DeadGhost.h"
#include <SDL_render.h>
#include "Steering.h"

DeadGhost::DeadGhost() {
	texture = mApplication->LoadTexture("ghost_angel.png");
	this->SetTexture(texture);
	this->SetSize(60, 60);
	this->speed = 5;
	this->maxSpeed = 10;
	this->mX = 900;
	this->mY = 300;
	this->mIsActive = false;
	this->angle = 0;
	this->behavior = new SteeringBehaviors();
}

DeadGhost::~DeadGhost() {
	SDL_DestroyTexture(texture);
}

void DeadGhost::Update(float deltaTime) {
	Steering steering = this->behavior->calculate(this->mX, this->mY);

	this->angle += steering.deltaAngle;
	this->speed += steering.deltaSpeed;

	// Validation
	if (this->mX < 600) this->mX = 1200;
	if (this->mX > 1200) this->mX = 600;
	if (this->mY < 10) this->mY = 590;
	if (this->mY > 590) this->mY = 10;
	if (this->angle > 359) this->angle = 0;
	if (this->angle < 0) this->angle = 359;
	if (this->speed < 1) speed = 1;
	if (this->speed > this->maxSpeed) speed = this->maxSpeed;

	this->mX += speed * sin(angle);
	this->mY += speed * cos(angle);
	
	this->SetOffset(this->mX, this->mY);
}