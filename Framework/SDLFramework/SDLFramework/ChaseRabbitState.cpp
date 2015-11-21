#include "ChaseRabbitState.h"
#include "FWApplication.h"
#include <iostream>
#include "Rabbit.h"
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
	// If owner->node == pill->node
	if (owner->GetCurrentNode() == target)
	{
		owner->ChangeState(StateFactory::Create(State::WANDERING, owner));
		Rabbit* rabbit = FWApplication::GetInstance()->GetRabbit();
		rabbit->ChangeState(StateFactory::Create(State::RESPAWNING, rabbit));
	}
}

std::string ChaseRabbitState::ToString() 
{
	return "Chasing rabbit";
}

ChaseRabbitState::~ChaseRabbitState()
{

}