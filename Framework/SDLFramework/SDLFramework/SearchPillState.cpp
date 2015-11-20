#include "SearchPillState.h"


SearchPillState::SearchPillState()
{
}

void SearchPillState::Update(float dt)
{
	CheckState();
}

void SearchPillState::Move(float dt)
{
	// auto* newNode = owner->GetCurrentNode()->GetEdges().at(NumberUtility::GenerateRandomNumber(0, owner->GetCurrentNode()->GetEdges().size() - 1));

	

	// owner->SetCurrentNode(newNode->GetDifferentNodeFromEdge(owner->GetCurrentNode()));
}

void SearchPillState::CheckState()
{
	// Chance state if bunny found
}

SearchPillState::~SearchPillState()
{
}
