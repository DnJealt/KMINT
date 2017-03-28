#include "DeadGhost.h"
#include <SDL_render.h>
#include "Steering.h"
#include "Game.h"

DeadGhost::DeadGhost(Game* game) {
	Pocketknife pk;
	texture = mApplication->LoadTexture("ghost_angel.png");
	this->game = game;
	this->SetTexture(texture);
	this->SetSize(60, 60);
	this->speed = 5;
	this->mX = pk.GetRandomNumber(650, 1150);
	this->mY = pk.GetRandomNumber(50, 550);
	this->mIsActive = false;
	this->behavior = new SteeringBehaviors(game, this);
}

DeadGhost::~DeadGhost() {
	SDL_DestroyTexture(texture);
	mApplication->RemoveRenderable(this);
}

void DeadGhost::Update(float deltaTime) {
	this->velocity.add(this->behavior->calculate());
	if (this->velocity.deltaX > this->speed) this->velocity.deltaX = this->speed;
	if (this->velocity.deltaY > this->speed) this->velocity.deltaY = this->speed;
	if (this->velocity.deltaX < (this->speed*-1)) this->velocity.deltaX = (this->speed*-1);
	if (this->velocity.deltaY < (this->speed*-1)) this->velocity.deltaY = (this->speed*-1);

	float angle = atan2(this->velocity.deltaY, this->velocity.deltaX);
	angle = angle * 180 / 3.14159265359;
	this->mAngle = angle;

	this->mX += this->velocity.deltaX;
	this->mY += this->velocity.deltaY;

	// Validation
	if (this->mX < 600) this->mX = 1200;
	if (this->mX > 1200) this->mX = 600;
	if (this->mY < 10) this->mY = 590;
	if (this->mY > 590) this->mY = 10;
	
	this->SetOffset(this->mX, this->mY);
}