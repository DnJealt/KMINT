#pragma once
#include "Vertex.h"

class Edge {
private:
	const int weight;

public:

	Vertex* from;
	Vertex* to;

	const int getWeight() const;

	Edge(Vertex* from, Vertex* to, const int weight);
	~Edge();
};
