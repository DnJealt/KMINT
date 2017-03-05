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
	Vertex* previous;

public:

	Vertex();
	Vertex(int xPos, int yPos);
	~Vertex();

	void setPrevious(Vertex* v);
	Vertex* getPrevious() const;

	void setCost(int cost);
	int getCost() const;

	double getPriority() const;
	void setPriority(double d);

	void reset();
};