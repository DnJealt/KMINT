#include "IdleState.h"
#include "Ghost.h"

IdleState::IdleState(Ghost* ghost) : GhostState(ghost) {}
IdleState::~IdleState() {}

void IdleState::Move(int totalTime) {
	// IdleState: Move around randomly

	if (ghost->DistanceTo(ghost->getNode()->getX(), ghost->getNode()->getY()) < ghost->getSpeed() * 2) {
		std::vector<Edge*> edges = ghost->getNode()->getEdges();
		auto selection = pk.GetRandomNumber(0, edges.size());
		ghost->setNode(edges[selection]->getOther(ghost->getNode()));
	}
	else {
		if (ghost->getX() < ghost->getNode()->getX()) {
			ghost->setX(ghost->getX() + ghost->getSpeed());
		}
		if (ghost->getX() > ghost->getNode()->getX()) {
			ghost->setX(ghost->getX() - ghost->getSpeed());
		}
		if (ghost->getY() > ghost->getNode()->getY()) {
			ghost->setY(ghost->getY() - ghost->getSpeed());
		}
		if (ghost->getY() < ghost->getNode()->getY()) {
			ghost->setY(ghost->getY() + ghost->getSpeed());
		}
	}
	// Move the ghost to its new position
	ghost->SetOffset(ghost->getX(), ghost->getY());

	if (totalTime > ghost->getWanderingTime()) {
		ghost->checkState();
	}
}
