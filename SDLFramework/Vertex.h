#pragma once
#include <vector>


class Edge;


class Vertex {
private:
	int number;

	int xPos;
	int yPos;

	double priority;
	int cost;

	std::vector<Edge*> edges;
	std::vector<Vertex*> connections;

	Vertex* previous{ nullptr };

public:

	Vertex();
	Vertex(int xPos, int yPos);
	~Vertex();

	int getX() const;
	int getY() const;

	const int getNumber() const;
	void setNumber(const int number);

	void addEdge(Edge* edge);
	const std::vector<Edge*> getEdges() const;

	void addConnection(Vertex* vertex);
	const std::vector<Vertex*> getConnections() const;

	const int getDistance(Vertex* to);

	void setPrevious(Vertex* v);
	Vertex* getPrevious() const;

	void setCost(int cost);
	int getCost() const;

	double getPriority() const;
	void setPriority(double d);

	void reset();
};