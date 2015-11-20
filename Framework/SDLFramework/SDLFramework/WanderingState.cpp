#include "WanderingState.h"
#include "NumberUtility.h"

void WanderingState::Update(float dt)
{
	// chance to change state to search_pill
	CheckState();
}

void WanderingState::Move(float dt)
{
	auto* newNode = owner->GetCurrentNode()->GetEdges().at(NumberUtility::GenerateRandomNumber(0, owner->GetCurrentNode()->GetEdges().size() - 1));

	owner->SetCurrentNode(newNode->GetDifferentNodeFromEdge(owner->GetCurrentNode()));
}

void WanderingState::CheckState()
{
	if (NumberUtility::GenerateRandomNumber(0, 10) == 5)
	{
		// owner->ChangeState(new GetPillState());
	}
}

WanderingState::~WanderingState()
{
}
