#pragma once
#include <iostream>

#include "Vertex.h"
#include "IGameObject.h"

class Map;

class AStar
{
public:
	AStar();
	~AStar();

	static void find(IGameObject* subject, Vertex* dest, Graph* graph) {
		std::vector<Vertex*> openlist;
		std::vector<Vertex*> closedlist;

		// Manhattan heuristic, aka pythagoras
		auto node = subject->getNode();
		int heuristic = sqrt(pow((float)(node->getX() - dest->getX()), 2) + pow((float)node->getY() - dest->getY(), 2)) * 100;
		
		node->setCost(0);
		openlist.emplace_back(node);

		for (auto p : graph->vertices) {
			if (p->getX() == subject->getNode()->getX() && p->getY() == subject->getNode()->getY()) {
				p->setCost(0);
			}
			else {
				p->setCost(INT_MAX);
			}
		}

		// Start calculating costs
		while (!openlist.empty()) {
			Vertex* current = openlist[0];
			openlist.erase(openlist.begin());

			// The early escape
			if (current == dest) {
				break;
			}

			int totalCost = current->getCost();

			for (auto next : current->getConnections()) {
				int new_cost = current->getCost() + current->getDistance(next);

				if (new_cost < totalCost) {
					totalCost = new_cost;
					int priority = new_cost + heuristic;
					closedlist.emplace_back(current);
					next->setPrevious(current);
				}

				/*if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
					cost_so_far[next] = new_cost;
					int priority = new_cost + heuristic;
					frontier.put(next, priority);
					next->setPrevious(current);
				}*/
			}
		}

	}

};
