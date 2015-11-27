#include "ChaseRabbitState.h"
#include "FWApplication.h"
#include <iostream>
#include "Rabbit.h"
#include "Cow.h"
#include "StateFactory.h"

ChaseRabbitState::ChaseRabbitState()
{
}

void ChaseRabbitState::Update(float dt)
{
	SetTarget(FWApplication::GetInstance()->GetRabbit()->GetCurrentNode());
	CheckState();
}

void ChaseRabbitState::Move(float dt)
{
	SearchState::Move(dt);
}

void ChaseRabbitState::CheckState()
{
	if (owner->GetCurrentNode() == target)
	{
		Rabbit* rabbit = FWApplication::GetInstance()->GetRabbit();
		if (rabbit->HasPill)
		{
			owner->ChangeState(StateFactory::Create(State::SLEEP, owner));
			rabbit->HasPill = false;
		}
		else 
		{
			rabbit->ChangeState(StateFactory::Create(State::RESPAWNING, rabbit));
		}
	}
}

std::string ChaseRabbitState::ToString()
{
	return "Chasing rabbit";
}

ChaseRabbitState::~ChaseRabbitState()
{

}