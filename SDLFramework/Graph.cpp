#include "Graph.h"

Graph::Graph() {}
Graph::~Graph() {} // Do not destroy the edges here or the application will crash.

const void Graph::addEdge(Edge* edge) {
	this->edges.emplace_back(edge);
}

const void Graph::addVertex(Vertex* vertex) {
	// Give the vertex a number to make it identify-able;
	vertex->setNumber(vertexCount++);
	this->vertices.emplace_back(vertex);
}

const void Graph::addVertexConnections() {
	for (auto v : this->vertices) {
		for (auto e : v->getEdges()) {
			v->addConnection(e->getOther(v));
		}
	}
}