#include "SearchPillState.h"
#include "Pill.h"
#include <iostream>
#include "StateFactory.h"

SearchPillState::SearchPillState()
{
}

void SearchPillState::Update(float dt)
{
	CheckState();
	if (target == nullptr)
	{
		SetTarget(FWApplication::GetInstance()->GetPill()->GetNode());
	}
}

void SearchPillState::Move(float dt)
{
	SearchState::Move(dt);
	// auto* newNode = owner->GetCurrentNode()->GetEdges().at(NumberUtility::GenerateRandomNumber(0, owner->GetCurrentNode()->GetEdges().size() - 1));

	

	// owner->SetCurrentNode(newNode->GetDifferentNodeFromEdge(owner->GetCurrentNode()));
}

void SearchPillState::CheckState()
{
	// If owner->node == pill->node
	if (owner->GetCurrentNode() == target)
	{
		owner->ChangeState(StateFactory::Create(State::CHASE_RABBIT, owner));
	}
}

SearchPillState::~SearchPillState()
{
}
