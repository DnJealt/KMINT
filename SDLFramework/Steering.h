#pragma once

class Steering
{
public:
	Steering() {};
	float deltaX = 0;
	float deltaY = 0;
	void normalize(int count) {
		deltaX /= count;
		deltaY /= count;
	}
	void multiply(float count) {
		deltaX *= count;
		deltaY *= count;
	}
	void add(Steering count) {
		deltaX += count.deltaX;
		deltaY += count.deltaY;
	}
};

