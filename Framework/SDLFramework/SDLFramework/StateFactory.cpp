#include "StateFactory.h"
#include "WanderingState.h"

std::map<State, std::function<GameState*(void)>> fillMap()
{
	std::map<State, std::function<GameState*(void)>> map;
	map[State::WANDERING] = [](void) -> GameState * { return new WanderingState; };
	return map;
}

std::map<State, std::function<GameState*(void)>> StateFactory::StateMap = fillMap();

GameState* StateFactory::Create(State state)
{
	GameState* gameState = nullptr;
	auto it = StateMap.find(state);
	if (it != StateMap.end())
	{
		gameState = it->second();
	}
	return gameState;
}