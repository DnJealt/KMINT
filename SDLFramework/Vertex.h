#pragma once
#include <vector>


class Edge;


class Vertex {
private:
	int xPos;
	int yPos;

	double priority;
	int cost;

	std::vector<Edge*> edges;
	Vertex* previous{ nullptr };

public:

	Vertex();
	Vertex(int xPos, int yPos);
	~Vertex();

	int getX() const;
	int getY() const;

	void addEdge(Edge* edge);
	const std::vector<Edge*> getEdges() const;

	void setPrevious(Vertex* v);
	Vertex* getPrevious() const;

	void setCost(int cost);
	int getCost() const;

	double getPriority() const;
	void setPriority(double d);

	void reset();
};