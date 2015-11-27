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
	Rabbit* rabbit = dynamic_cast<Rabbit*>(owner);
	for (auto& edge : rabbit->GetCurrentNode()->GetEdges())
	{
		Node* node = edge->GetDifferentNodeFromEdge(rabbit->GetCurrentNode());
		if (node == FWApplication::GetInstance()->GetCow()->GetCurrentNode())
		{
			cow->ChangeState(StateFactory::Create(State::RESPAWNING, cow));
			owner->ChangeState(StateFactory::Create(State::WANDERING, owner));
		}
	}
}

std::string ShootState::ToString()
{
	return "Shooting cow";
}

ShootState::~ShootState()
{
}
