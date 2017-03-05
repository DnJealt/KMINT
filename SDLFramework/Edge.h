#pragma once
#include "Vertex.h"

class Edge {
private:
	Vertex* from;
	Vertex* to;
	const int weight;

public:

	Edge(Vertex* from, Vertex* to, const int weight);
	~Edge();
};
