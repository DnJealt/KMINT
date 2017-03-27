#pragma once

class Ghost;


class GhostState {
private:

protected:
	Ghost* ghost;

public:
	GhostState(Ghost* ghost);
	~GhostState();

	virtual void Move(int totalTime) = 0;
};
