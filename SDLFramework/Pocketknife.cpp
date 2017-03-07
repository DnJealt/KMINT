#include "Pocketknife.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


Pocketknife::Pocketknife()
{

}

Pocketknife::~Pocketknife()
{
}

int Pocketknife::GetRandomNumber(int from, int to) {
	return from + (rand() % to);
}

void Pocketknife::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

// A magic spell to split a string with any delimiter.
std::vector<std::string> Pocketknife::splitString(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}