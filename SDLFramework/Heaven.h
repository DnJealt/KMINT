#pragma once
#include <vector>
#include "DeadGhost.h"

class Heaven {
private:
	std::vector<DeadGhost*> ghosts;
public:
	std::vector<DeadGhost*>* getGhosts();

	Heaven(std::vector<DeadGhost*> ghosts);
	~Heaven();
};
