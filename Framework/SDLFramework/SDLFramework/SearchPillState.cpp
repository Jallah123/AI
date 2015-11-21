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
}

void SearchPillState::CheckState()
{
	// If owner->node == pill->node
	if (owner->GetCurrentNode() == target)
	{
		std::cout << "New chase rabbit state" << std::endl;
		owner->ChangeState(StateFactory::Create(State::CHASE_RABBIT, owner));
	}
}

std::string SearchPillState::ToString()
{
	return "Searching pill";
}

SearchPillState::~SearchPillState()
{
}
