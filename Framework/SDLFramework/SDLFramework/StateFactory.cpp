#include "StateFactory.h"
#include "WanderingState.h"
#include "SearchPillState.h"
#include "AliveGameObject.h"
#include "ChaseRabbitState.h"
#include "SearchWeaponState.h"

std::map<State, std::function<GameState*(void)>> fillMap()
{
	std::map<State, std::function<GameState*(void)>> map;
	map[State::WANDERING] = [](void) -> GameState * { return new WanderingState; };
	map[State::SEARCH_PILL] = [](void) -> GameState * { return new SearchPillState; };
	map[State::CHASE_RABBIT] = [](void) -> GameState * { return new ChaseRabbitState; };
	map[State::SEARCH_WEAPON] = [](void) -> GameState * { return new SearchWeaponState; };
	return map;
}

std::map<State, std::function<GameState*(void)>> StateFactory::StateMap = fillMap();

GameState* StateFactory::Create(State state, AliveGameObject* owner)
{
	GameState* gameState = nullptr;
	auto it = StateMap.find(state);
	if (it != StateMap.end())
	{
		gameState = it->second();
		gameState->SetOwner(owner);
	}
	return gameState;
}