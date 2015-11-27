#include "FleeState.h"
#include "Rabbit.h"
#include "FWApplication.h"
#include "Edge.h"
#include "Cow.h"
#include "NumberUtility.h"

FleeState::FleeState()
{
}


FleeState::~FleeState()
{
}

void FleeState::Update(float dt)
{
	CheckState();
}

void FleeState::Move(float dt)
{
	if (Rabbit* r = dynamic_cast<Rabbit*>(owner))
	{
		std::vector<Node*> CowFreeNodes;
		for (auto& edge : r->GetCurrentNode()->GetEdges())
		{
			Node* node = edge->GetDifferentNodeFromEdge(r->GetCurrentNode());
			if (node != FWApplication::GetInstance()->GetCow()->GetCurrentNode())
			{
				CowFreeNodes.push_back(node);
			}
		}
		if(CowFreeNodes.size() == 0)
		{
			r->SetCurrentNode(r->GetCurrentNode()->edges.at(0)->GetDifferentNodeFromEdge(r->GetCurrentNode()));
		}
		else
		{
			r->SetCurrentNode(CowFreeNodes.at(NumberUtility::GenerateRandomNumber(0, CowFreeNodes.size() - 1)));
		}
	}
}

std::string FleeState::ToString()
{
	return "Fleeing";
}

void FleeState::CheckState()
{

}