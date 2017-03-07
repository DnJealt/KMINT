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

	static void find(IGameObject* subject, Vertex* dest) {
		std::vector<Vertex*> openlist;
		std::vector<Vertex*> closedlist;

		// Manhattan heuristic, aka pythagoras
		//int heuristic = subject->

	}

};
