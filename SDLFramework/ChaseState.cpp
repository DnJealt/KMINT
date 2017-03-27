#include "ChaseState.h"
#include "Ghost.h"
#include "Game.h"
#include "AStar.h"

ChaseState::ChaseState(Ghost* ghost) : GhostState(ghost) {}
ChaseState::~ChaseState() {}

void ChaseState::Move(int totalTime) {
	Vertex* pacmanVertex = ghost->getGame()->getPacman()->getNode();

	if (pacmanVertex != ghost->getNode()) {
		if (ghost->DistanceTo(ghost->getNode()->getX(), ghost->getNode()->getY()) < ghost->getSpeed() * 2) {
			std::vector<Vertex*> path = AStar::find(ghost->getNode(), pacmanVertex, &ghost->getGame()->getMap());

			ghost->setNode(path[0]);
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
	}

}
