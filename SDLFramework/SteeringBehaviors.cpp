#include "SteeringBehaviors.h"
#include "Pocketknife.h"
#include "Game.h"

SteeringBehaviors::SteeringBehaviors(Game* game, DeadGhost* deadghost)
{
	this->game = game;
	this->deadghost = deadghost;
}


SteeringBehaviors::~SteeringBehaviors()
{
}

Steering SteeringBehaviors::calculate() {
	Steering steering;
	
	Steering alignment = calculateAlignment();
	alignment.multiply(alignmentWeight);
	Steering cohesion = calculateCohesion();
	cohesion.multiply(cohesionWeight);
	Steering separation = calculateSeparation();
	separation.normalize(separationWeight);

	std::cout << alignment.deltaX << " " << cohesion.deltaX << " " << separation.deltaX << std::endl;

	steering.deltaX = separation.deltaX;
	steering.deltaY = separation.deltaY;

	return steering;
}

Steering SteeringBehaviors::calculateAlignment() {
	Steering steering;
	int neighborCount = 0;

	for (unsigned i = 0; i < this->game->deadghosts.size(); ++i)
	{
		if (this->game->deadghosts.at(i) != this->deadghost)
		{
			if (this->deadghost->DistanceTo(this->game->deadghosts.at(i)) < 300)
			{
				steering.deltaX += this->game->deadghosts.at(i)->velocity.deltaX;
				steering.deltaY += this->game->deadghosts.at(i)->velocity.deltaY;
				neighborCount++;
			}

		}
	}
	if (neighborCount == 0) {
		return steering;
	}
	steering.deltaX /= neighborCount;
	steering.deltaY /= neighborCount;
	//steering.normalize(1);
	return steering;
}

Steering SteeringBehaviors::calculateCohesion() {
	Steering steering;
	int neighborCount = 0;

	for (unsigned i = 0; i < this->game->deadghosts.size(); ++i)
	{
		if (this->game->deadghosts.at(i) != this->deadghost)
		{
			if (this->deadghost->DistanceTo(this->game->deadghosts.at(i)) < 200)
			{
				steering.deltaX += this->game->deadghosts.at(i)->mX;
				steering.deltaY += this->game->deadghosts.at(i)->mY;
				neighborCount++;
			}

		}
	}
	if (neighborCount == 0) {
		return steering;
	}
	steering.deltaX /= neighborCount;
	steering.deltaY /= neighborCount;
	//steering->normalize(1);
	Steering velocity;
	velocity.deltaX = steering.deltaX - deadghost->mX;
	velocity.deltaY = steering.deltaY - deadghost->mY;
	return velocity;
}

Steering SteeringBehaviors::calculateSeparation() {
	Steering steering;
	int neighborCount = 0;

	for (unsigned i = 0; i < this->game->deadghosts.size(); ++i)
	{
		if (this->game->deadghosts.at(i) != this->deadghost)
		{
			if (this->deadghost->DistanceTo(this->game->deadghosts.at(i)) < 100)
			{
				steering.deltaX += (this->game->deadghosts.at(i)->mX - this->deadghost->mX);
				steering.deltaY += (this->game->deadghosts.at(i)->mY - this->deadghost->mY);
				neighborCount++;
			}

		}
	}
	if (neighborCount == 0) {
		return steering;
	}
	steering.multiply(-1);
	steering.normalize(neighborCount);
	steering.normalize(50);
	return steering;
}
