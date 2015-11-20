#pragma once
#include <map>
#include <string>
#include "GameState.h"

enum State
{
	WANDERING,
	SEARCH_PILL,
	SEARCH_WEAPON,
	CHASE_RABBIT
};

class StateFactory
{
public:
	static GameState* Create(State state);
private:
	static std::map<State, std::function<GameState*(void)>> StateMap;
};

