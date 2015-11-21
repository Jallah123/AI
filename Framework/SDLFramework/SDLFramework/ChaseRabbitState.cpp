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
	CheckState();
	SetTarget(FWApplication::GetInstance()->GetRabbit()->GetCurrentNode());
}

void ChaseRabbitState::Move(float dt)
{
	SearchState::Move(dt);
	// auto* newNode = owner->GetCurrentNode()->GetEdges().at(NumberUtility::GenerateRandomNumber(0, owner->GetCurrentNode()->GetEdges().size() - 1));



	// owner->SetCurrentNode(newNode->GetDifferentNodeFromEdge(owner->GetCurrentNode()));
}

void ChaseRabbitState::CheckState()
{
	// If owner->node == pill->node
	//if (owner->GetCurrentNode() == target)
	//{
		//owner->ChangeState(StateFactory::Create(State::WANDERING, owner));
	//}
}

ChaseRabbitState::~ChaseRabbitState()
{
}
