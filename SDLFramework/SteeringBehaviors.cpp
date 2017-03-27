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
	Steering cohesion = calculateCohesion();
	Steering separation = calculateSeparation();

	std::cout << alignment.deltaX << " " << cohesion.deltaX << " " << separation.deltaX << std::endl;

	steering.deltaX = alignment.deltaX + cohesion.deltaX + separation.deltaX;
	steering.deltaY = alignment.deltaY + cohesion.deltaY + separation.deltaY;
	return steering;
}

Steering SteeringBehaviors::calculateAlignment() {
	Steering steering;
	int neighborCount = 0;

	for (unsigned i = 0; i < this->game->deadghosts.size(); ++i)
	{
		if (this->game->deadghosts.at(i) != this->deadghost)
		{
			if (this->deadghost->DistanceTo(this->game->deadghosts.at(i)) < 100)
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
	steering.normalize(alignmentWeight);
	steering.normalize(neighborCount);
	
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
				steering.deltaX += (this->game->deadghosts.at(i)->mX - this->deadghost->mX);
				steering.deltaY += (this->game->deadghosts.at(i)->mY - this->deadghost->mY);
				neighborCount++;
			}

		}
	}
	if (neighborCount == 0) {
		return steering;
	}
	steering.normalize(cohesionWeight);
	steering.normalize(neighborCount);
	
	return steering;
}

Steering SteeringBehaviors::calculateSeparation() {
	Steering steering;
	int neighborCount = 0;

	for (unsigned i = 0; i < this->game->deadghosts.size(); ++i)
	{
		if (this->game->deadghosts.at(i) != this->deadghost)
		{
			if (this->deadghost->DistanceTo(this->game->deadghosts.at(i)) < 50)
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
	// multiply by -1 to reverse the direction.
	steering.multiply(-1);
	steering.normalize(separationWeight);
	steering.normalize(neighborCount);
	
	return steering;
}
