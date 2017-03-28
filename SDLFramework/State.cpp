#include "State.h"

State::State(IGameObject* obj, std::string stateName) : stateName{ stateName } {}
State::~State() {}

const std::string State::getStateName() const {
	return this->stateName;
}