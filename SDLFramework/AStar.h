#pragma once
#include <iostream>
#include <algorithm>

#include "Vertex.h"
#include "IGameObject.h"

class Map;

class AStar
{
public:
	AStar();
	~AStar();


	static std::vector<Vertex*> find(Vertex* from, Vertex* dest, Graph* graph) {
		std::vector<Vertex*> path;

		std::vector<Vertex*> open_list;
		std::vector<Vertex*> closed_list;

		// The 'Manhattan' heuristic uses Pythagoras to estimate the distance between the two points
		int heuristic = sqrt(pow((float)(from->getX() - dest->getX()), 2) + pow((float)from->getY() - dest->getY(), 2)) * 100;

		from->setCost(0);
		open_list.emplace_back(from);

		while (!open_list.empty()) {
			// Pop the first item from the openlist
			Vertex* current = open_list[0];
			open_list.erase(open_list.begin());

			// The early escape when we found the destination
			if (current == dest) {
				closed_list.emplace_back(current);
				break;
			}

			for (Vertex* neighbour : current->getConnections()) {
				int distanceToNeighbour = 0;

				// Find the length of the Edge from current to neighbour.
				for (auto e : current->getEdges()) {
					if (e->getOther(current) == neighbour) {
						distanceToNeighbour = e->getLength();
					}
				}

				float newCost = current->getCost() + distanceToNeighbour + heuristic;

				// Check if we've found a cheaper cost, then update it
				if (newCost < neighbour->getCost()) {
					neighbour->setPrevious(current);
					neighbour->setCost(newCost);
				}
				if (std::find(open_list.begin(), open_list.end(), neighbour) != open_list.end() || newCost > neighbour->getCost()) {
					continue;
				}
				else if (std::find(closed_list.begin(), closed_list.end(), neighbour) != closed_list.end() || newCost > neighbour->getCost()) {
					continue;
				}
				else {
					open_list.emplace_back(neighbour);
				}

				// Sort the open list, should be more efficient than a freakin' bubblesort.
				std::sort(open_list.begin(), open_list.end(), [](Vertex* a, Vertex* b) { return a->getCost() < b->getCost(); });
			}
			closed_list.emplace_back(current);
		}

		// Right now we should have found the path
		Vertex* current = dest;
		while (current->getPrevious() != nullptr) {
			// We're working from back to front, so put the elements at the front of the array
			path.emplace(path.begin(), current);
			current = current->getPrevious();
		}
		
		// Reset the costs of the Vertices back to max
		graph->resetGraph();

		return path;
	}


	//static void find(Vertex* from, Vertex* dest, Graph* graph) {
	//	std::vector<Vertex*> openlist;
	//	std::vector<Vertex*> closedlist;

	//	// Manhattan heuristic, aka pythagoras
	//	int heuristic = sqrt(pow((float)(from->getX() - dest->getX()), 2) + pow((float)from->getY() - dest->getY(), 2)) * 100;
	//	
	//	from->setCost(0);
	//	openlist.emplace_back(from);

	//	for (auto p : graph->vertices) {
	//		if (p->getX() == from->getX() && p->getY() == from->getY()) {
	//			p->setCost(0);
	//		}
	//		else {
	//			p->setCost(INT_MAX);
	//		}
	//	}

	//	// Start calculating costs
	//	while (!openlist.empty()) {

	//		// Pop the first item from the openlist
	//		Vertex* current = openlist[0];
	//		openlist.erase(openlist.begin());

	//		// The early escape
	//		if (current == dest) {
	//			break;
	//		}
	//		

	//		int totalCost = current->getCost();

	//		for (auto next : current->getConnections()) {
	//			int new_cost = current->getCost() + current->getDistance(next);

	//			if (new_cost > totalCost) {
	//				totalCost = new_cost;
	//				int priority = new_cost + heuristic;
	//				closedlist.emplace_back(current);
	//				next->setPrevious(current);
	//			}

	//			/*if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
	//				cost_so_far[next] = new_cost;
	//				int priority = new_cost + heuristic;
	//				frontier.put(next, priority);
	//				next->setPrevious(current);
	//			}*/
	//		}
	//	}

	//}

};
