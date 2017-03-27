#pragma once
#include <vector>
#include "Edge.h"
#include "Vertex.h"

class Graph {
private:
	int vertexCount = 0;
public:
	Graph();
	~Graph();

	std::vector<Edge*> edges;
	std::vector<Vertex*> vertices;

	const void addEdge(Edge* edge);
	const void addVertex(Vertex* vertex);

	const void resetGraph();

	const void addVertexConnections();
};