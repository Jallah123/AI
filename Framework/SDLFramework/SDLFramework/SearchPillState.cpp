#include "SearchPillState.h"
#include "Pill.h"
#include <iostream>
#include "StateFactory.h"
#include "Rabbit.h"

SearchPillState::SearchPillState()
{
	SetTarget(FWApplication::GetInstance()->GetPill()->GetNode());
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
	if (owner->GetCurrentNode() == target)
	{
		std::cout << "Pill found now wandering" << std::endl;
		if (Rabbit* r = dynamic_cast<Rabbit*>(owner)) 
		{
			r->ChangeState(StateFactory::Create(State::WANDERING, owner));
			r->HasPill = true;
			FWApplication::GetInstance()->GetPill()->Respawn();
		}
	}
}

std::string SearchPillState::ToString()
{
	return "Searching pill";
}

SearchPillState::~SearchPillState()
{
}
