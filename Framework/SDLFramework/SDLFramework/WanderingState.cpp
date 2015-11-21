#include "WanderingState.h"
#include "NumberUtility.h"
#include "StateFactory.h"
#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Cow.h"

void WanderingState::Update(float dt)
{
	// chance to change state to search_pill
	CheckState();
}

void WanderingState::Move(float dt)
{
	auto* newNode = owner->GetCurrentNode()->GetEdges().at(NumberUtility::GenerateRandomNumber(0, owner->GetCurrentNode()->GetEdges().size() - 1));

	owner->SetCurrentNode(newNode->GetDifferentNodeFromEdge(owner->GetCurrentNode()));
}

void WanderingState::CheckState()
{
	if (Cow* c = dynamic_cast<Cow*>(owner))
	{
		int number = NumberUtility::GenerateRandomNumber(0, 10);
		if (number > 1)
		{
			std::cout << "new pill search state" << std::endl;
			owner->ChangeState(StateFactory::Create(State::SEARCH_PILL, owner));
		}
	}
}

WanderingState::~WanderingState()
{
}
