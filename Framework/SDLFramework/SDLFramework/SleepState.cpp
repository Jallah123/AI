#include "SleepState.h"
#include "StateFactory.h"


SleepState::SleepState()
{
}


SleepState::~SleepState()
{
}

void SleepState::Update(float dt)
{
	CheckState();
	sleep--;
}

void SleepState::Move(float dt)
{

}

std::string SleepState::ToString()
{
	return "Sleeping";
}

void SleepState::CheckState()
{
	if (sleep == 0) 
	{
		owner->ChangeState(StateFactory::Create(State::CHASE_RABBIT, owner));
		sleep = 5;
	}
}