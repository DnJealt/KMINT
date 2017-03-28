#include "PillState.h"

PillState::PillState(Ghost* ghost) : GhostState(ghost, "pill") {}
PillState::~PillState() {}

void PillState::Move(int totalTime) {
	
	// If no path has been set yet, create a new path.
	if (this->shortestPath.empty() && !hasMoved) {
		Vertex* pillVertex1 = ghost->getGame()->r.pillSpawn1;
		Vertex* pillVertex2 = ghost->getGame()->r.pillSpawn2;
		Vertex* pillVertex3 = ghost->getGame()->r.pillSpawn3;
		Vertex* pillVertex4 = ghost->getGame()->r.pillSpawn4;

		std::vector<int> distances;
		distances.push_back(sqrt(pow((float)(ghost->getNode()->getX() - pillVertex1->getX()), 2) + pow((float)ghost->getNode()->getY() - pillVertex1->getY(), 2)) * 100);
		distances.push_back(sqrt(pow((float)(ghost->getNode()->getX() - pillVertex2->getX()), 2) + pow((float)ghost->getNode()->getY() - pillVertex2->getY(), 2)) * 100);
		distances.push_back(sqrt(pow((float)(ghost->getNode()->getX() - pillVertex3->getX()), 2) + pow((float)ghost->getNode()->getY() - pillVertex3->getY(), 2)) * 100);
		distances.push_back(sqrt(pow((float)(ghost->getNode()->getX() - pillVertex4->getX()), 2) + pow((float)ghost->getNode()->getY() - pillVertex4->getY(), 2)) * 100);

		int shortestDistance = 2147483647;
		int shortest = 0;
		for (unsigned i = 0; i < distances.size(); ++i) {
			if (distances.at(i) < shortestDistance) {
				shortestDistance = distances.at(i);
				shortest = i;
			}
		}

		Vertex* closestVertex;
		if (shortest == 0) { closestVertex = pillVertex1; }
		else if (shortest == 1) { closestVertex = pillVertex2; }
		else if (shortest == 2) { closestVertex = pillVertex3; }
		else if (shortest == 3) { closestVertex = pillVertex4; }
		else {
			closestVertex = nullptr;
		}

		this->shortestPath = AStar::find(ghost->getNode(), closestVertex, &ghost->getGame()->getMap());
		hasMoved = true;
	}
	else {
		if (ghost->DistanceTo(ghost->getNode()->getX(), ghost->getNode()->getY()) < ghost->getSpeed() * 3) {
			if (shortestPath.size() != pathCount) {
				ghost->setNode(shortestPath.at(pathCount));
				pathCount++;
			}
			else {
				ghost->setSpeed(ghost->getSpeed() * ghost->speedmultiplier);
				ghost->swapState(0);
			}
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
	}

	
	
	
	//if (totalTime > ghost->getWanderingTime()) {
	//	ghost->checkState();
	//}
}
