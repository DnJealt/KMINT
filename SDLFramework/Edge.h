#pragma once
#include "Vertex.h"

class Edge {
private:
	float length;

	const float calculateLength(Vertex* from, Vertex* to);

public:

	Vertex* from;
	Vertex* to;

	const float getLength() const;

	Edge(Vertex* from, Vertex* to);
	~Edge();
};
