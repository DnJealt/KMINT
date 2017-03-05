#include "Edge.h"

Edge::Edge(Vertex* from, Vertex* to, const int weight) 
	: from{ from }, to{ to }, weight{ weight } {}


Edge::~Edge() {
	delete from, to;
}
