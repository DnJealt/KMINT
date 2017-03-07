#include "Vertex.h"

Vertex::Vertex() {
	this->xPos = 0;
	this->yPos = 0;
}

Vertex::Vertex(int xPos, int yPos) :
	xPos{ xPos }, yPos{ yPos } {}

Vertex::~Vertex() {
	edges.clear();
}

int Vertex::getX() const {
	return this->xPos;
}
int Vertex::getY() const {
	return this->yPos;
}

void Vertex::addEdge(Edge* edge)
{
	this->edges.emplace_back(edge);
}

Vertex* Vertex::getPrevious() const
{
	return this->previous;
}

void Vertex::setPrevious(Vertex* v)
{
	this->previous = v;
}

int Vertex::getCost() const
{
	return this->cost;
}

void Vertex::setCost(int cost)
{
	this->cost = cost;
}

void Vertex::setPriority(double d)
{
	this->priority = d;
}

double Vertex::getPriority() const
{
	return this->priority;
}

void Vertex::reset()
{
	setCost(2147483647);
	setPrevious(nullptr);
	setPriority(0);
}
