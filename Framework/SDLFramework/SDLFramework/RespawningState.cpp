#include "RespawningState.h"
#include "NumberUtility.h"
#include "StateFactory.h"
#include "Cow.h"

void RespawningState::Update(float dt)
{
	CheckState();
}

void RespawningState::Move(float dt)
{
	owner->SetCurrentNode(FWApplication::GetInstance()->nodes.at(NumberUtility::GenerateRandomNumber(0, FWApplication::GetInstance()->nodes.size()-1)));
}

void RespawningState::CheckState()
{
	if (Cow* c = dynamic_cast<Cow*>(owner)) 
	{
		owner->ChangeState(StateFactory::Create(State::CHASE_RABBIT, owner));
	}
	else 
	{
		owner->ChangeState(StateFactory::Create(State::WANDERING, owner));
	}
}

std::string RespawningState::ToString()
{
	return "Respawning";
}

RespawningState::~RespawningState()
{
}
