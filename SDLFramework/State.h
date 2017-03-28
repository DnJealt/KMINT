#pragma once
#include <string>

class IGameObject;

class State {

protected:
	const std::string stateName;

public:
	State(IGameObject* obj, const std::string stateName);
	~State();

	const std::string getStateName() const;

};