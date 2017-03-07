#pragma once
#include <string>
#include <sstream>
#include <vector>

class Pocketknife {
private:
	void split(const std::string &s, char delim, std::vector<std::string> &elems);
public:
	Pocketknife();
	~Pocketknife();
	int GetRandomNumber(int from, int to);
	std::vector<std::string> splitString(const std::string &s, char delim);
};