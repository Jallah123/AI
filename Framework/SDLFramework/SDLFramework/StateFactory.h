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
	static GameState* StateFactory::Create(State state, AliveGameObject* owner);
private:
	static std::map<State, std::function<GameState*(void)>> StateMap;
};

