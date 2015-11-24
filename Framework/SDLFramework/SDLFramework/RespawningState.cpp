#include "RespawningState.h"
#include "NumberUtility.h"
#include "StateFactory.h"

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
	owner->ChangeState(StateFactory::Create(State::WANDERING, owner));
}

std::string RespawningState::ToString()
{
	return "Respawning";
}

RespawningState::~RespawningState()
{
}
