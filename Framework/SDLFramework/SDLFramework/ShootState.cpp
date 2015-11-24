#include "ShootState.h"
#include "NumberUtility.h"
#include "StateFactory.h"
#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Cow.h"
#include "Rabbit.h"

void ShootState::Update(float dt)
{
	CheckState();
}

void ShootState::Move(float dt)
{

}

void ShootState::CheckState()
{
	Cow* cow = FWApplication::GetInstance()->GetCow();
	if (cow->GetCurrentNode() == owner->GetCurrentNode()) 
	{
		cow->ChangeState(StateFactory::Create(State::RESPAWNING, cow));
		owner->ChangeState(StateFactory::Create(State::WANDERING, owner));
	}
}

std::string ShootState::ToString()
{
	return "Shooting cow";
}

ShootState::~ShootState()
{
}
