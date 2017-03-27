#include "SteeringBehaviors.h"
#include "Pocketknife.h"

SteeringBehaviors::SteeringBehaviors()
{
	currentState = SteeringBehaviors::Wandering;
}


SteeringBehaviors::~SteeringBehaviors()
{
}

Steering SteeringBehaviors::calculate(int x, int y) {
	if (currentState == SteeringBehaviors::Wandering)
		return calcWandering(x, y);

	if (currentState == SteeringBehaviors::Following)
		return calcFollowing(x, y);

	if (currentState == SteeringBehaviors::Arriving)
		return calcArriving(x, y);

	if (currentState == SteeringBehaviors::Fleeing)
		return calcFleeing(x, y);
}

Steering SteeringBehaviors::calcWandering(int x, int y) {
	Steering steering;
	Pocketknife pk;

	if (pk.GetRandomNumber(0, 2) == 1) {
		steering.deltaAngle = 0.1;
	}
	else {
		steering.deltaAngle = -0.1;
	}
	if (pk.GetRandomNumber(0, 2) == 1) {
		steering.deltaSpeed = 0.1;
	}
	else {
		steering.deltaSpeed = -0.1;
	}

	return steering;
}

Steering SteeringBehaviors::calcFollowing(int x, int y) {
	Steering steering;
	Pocketknife pk;



	return steering;
}

Steering SteeringBehaviors::calcArriving(int x, int y) {
	Steering steering;
	Pocketknife pk;



	return steering;
}

Steering SteeringBehaviors::calcFleeing(int x, int y) {
	Steering steering;
	Pocketknife pk;



	return steering;
}