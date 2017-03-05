#include "Graph.h"

Graph::Graph() {}
Graph::~Graph() {}

const void Graph::addEdge(Edge* edge) {
	this->edges.emplace_back(edge);
}

const void Graph::addVertex(Vertex* vertex) {
	this->vertices.emplace_back(vertex);
}