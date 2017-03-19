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

const int Vertex::getNumber() const {
	return this->number;
}

void Vertex::setNumber(const int number) {
	this->number = number;
}

void Vertex::addEdge(Edge* edge)
{
	this->edges.emplace_back(edge);
}

const std::vector<Edge*> Vertex::getEdges() const {
	return this->edges;
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

void Vertex::addConnection(Vertex* vertex) {
	this->connections.emplace_back(vertex);
}

const std::vector<Vertex*> Vertex::getConnections() const {
	return connections;
}

const int Vertex::getDistance(Vertex* to) {
		float diffX = xPos - to->getX();
		float diffY = yPos - to->getY();
		return sqrt((diffY * diffY) + (diffX * diffX));	
}
