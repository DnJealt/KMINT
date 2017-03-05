#pragma once
#include <vector>
#include "Edge.h"
#include "Vertex.h"

class Graph {
public:
	Graph();
	~Graph();

	std::vector<Edge*> edges;
	std::vector<Vertex*> vertices;

	const void addEdge(Edge* edge);
	const void addVertex(Vertex* vertex);
};