#include "Edge.h"

Edge::Edge(Vertex* from, Vertex* to, const int weight) 
	: from{ from }, to{ to }, weight{ weight } {
	this->from->addEdge(this);
	this->to->addEdge(this);
}



Edge::~Edge() {
	delete from, to;
}

const int Edge::getWeight() const {
	return this->weight;
}
