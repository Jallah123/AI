#include "WanderingState.h"
#include "NumberUtility.h"
#include "StateFactory.h"
#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Cow.h"

void WanderingState::Update(float dt)
{
	CheckState();
}

void WanderingState::Move(float dt)
{
	auto* newNode = owner->GetCurrentNode()->GetEdges().at(NumberUtility::GenerateRandomNumber(0, owner->GetCurrentNode()->GetEdges().size() - 1));

	owner->SetCurrentNode(newNode->GetDifferentNodeFromEdge(owner->GetCurrentNode()));
}

void WanderingState::CheckState()
{
	if (Rabbit* r = dynamic_cast<Rabbit*>(owner))
	{
		for (auto& edge : r->GetCurrentNode()->GetEdges())
		{
			if (edge->GetDifferentNodeFromEdge(r->GetCurrentNode()) == FWApplication::GetInstance()->GetCow()->GetCurrentNode())
			{
				ChangeState(r);
			}
		}
	}
}

void WanderingState::ChangeState(Rabbit* r)
{
	int number = NumberUtility::GenerateRandomNumber(0, 10);
	GameState* newState;
	if (number < 1)
	{
		newState = StateFactory::Create(State::FLEE, r);
	}
	else if (number < 6) 
	{
		newState = StateFactory::Create(State::SEARCH_PILL, r);
	}
	else 
	{
		newState = StateFactory::Create(State::SEARCH_WEAPON, r);
	}
	r->ChangeState(newState);
}

std::string WanderingState::ToString()
{
	return "Wandering";
}

WanderingState::~WanderingState()
{

}
