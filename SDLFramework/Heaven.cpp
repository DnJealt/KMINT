#include "Heaven.h"

Heaven::Heaven(std::vector<DeadGhost*> ghosts) {
	this->ghosts = ghosts;
}

std::vector<DeadGhost*>* Heaven::getGhosts()
{
	return &this->ghosts;
}

Heaven::~Heaven() {
	for (unsigned i = 0; i < ghosts.size(); ++i) {
		delete ghosts.at(i);
	}
}

