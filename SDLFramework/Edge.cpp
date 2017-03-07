#include "Edge.h"

Edge::Edge(Vertex* from, Vertex* to) 
	: from{ from }, to{ to }{
	this->from->addEdge(this);
	this->to->addEdge(this);

	//Pythagoras to calculate the length of the edge
	length = calculateLength(from, to);
}

const float Edge::calculateLength(Vertex* from, Vertex* to) {
	return sqrt(pow((float)(from->getX() - to->getX()), 2) + pow((float)from->getY() - to->getY(), 2));
}


Edge::~Edge() {
	delete from, to;
}

const float Edge::getLength() const {
	return this->length;
}
