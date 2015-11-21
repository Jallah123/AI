#include "SearchState.h"
#include "Node.h"
#include "Edge.h"
#include <set>
#include <iostream>
#include "FWApplication.h"

SearchState::SearchState()
{
}

void SearchState::Move(float dt)
{
	if (path.empty())
	{
		// r->ChangePosition(nodes);
		FWApplication::GetInstance()->ResetNodes();
		FWApplication::GetInstance()->ResetEdges();
		if (target != nullptr)
		{
			CalculatePath(target);
		}
		return;
	}
	std::cout << "Moving to target" << std::endl;
	std::cout << path.at(0)->GetBoundingBox().x << ":" << path.at(0)->GetBoundingBox().y << std::endl;
	owner->SetCurrentNode(path.at(0));
	path.erase(std::find(path.begin(), path.end(), owner->GetCurrentNode()));
}

void SearchState::CalculatePath(Node* targetNode)
{
	FWApplication::GetInstance()->ResetNodes();
	FWApplication::GetInstance()->ResetEdges();
	std::cout << "Recalculating path" << std::endl;
	std::vector<Node*> ClosedSet;
	std::set<Node*> OpenSet;
	// std::priority_queue<Node*, std::vector<Node*>, Comparetor> NodeQueue;
	std::vector<Node*> NodeQueue;
	Node* currentNode = owner->GetCurrentNode();
	currentNode->weight = 0;
	NodeQueue.push_back(currentNode);
	OpenSet.insert(currentNode);

	while (!NodeQueue.empty())
	{
		Node* cNode = GetCheapestNode(NodeQueue);
		NodeQueue.erase(find(NodeQueue.begin(), NodeQueue.end(), cNode));
		OpenSet.erase(cNode);

		if (cNode == targetNode)
		{
			std::vector<Node*> correctPath;
			while (cNode != currentNode)
			{
				correctPath.push_back(cNode);
				cNode = cNode->prevNode;
			}
			std::reverse(correctPath.begin(), correctPath.end());
			path = correctPath;
			return;
		}
		ClosedSet.push_back(cNode);

		for each (auto& edge in cNode->edges)
		{
			// weight = cNode->weight + anderenode->distanceTo(rabbitNode) + anderenode->distanceTo(cNode)
			Node* differentNode = edge->GetDifferentNodeFromEdge(cNode);
			if (find(ClosedSet.begin(), ClosedSet.end(), differentNode) != ClosedSet.end())
			{
				continue;
			}
			int weight = cNode->weight + (differentNode->DistanceTo(targetNode) / 10) + differentNode->DistanceTo(cNode);

			edge->Weight = differentNode->DistanceTo(cNode);

			if (weight < differentNode->weight) {
				differentNode->weight = weight;
				differentNode->prevNode = cNode;
			}

			// if already in open/closed set
			if (find(OpenSet.begin(), OpenSet.end(), differentNode) == OpenSet.end())
			{
				NodeQueue.push_back(differentNode);
				OpenSet.insert(differentNode);
			}
		}

	}
}

Node* SearchState::GetCheapestNode(std::vector<Node*>& nodes)
{
	Node* cheapest = nodes.at(0);
	for each (auto& Node in nodes)
	{
		if (Node->weight < cheapest->weight)
		{
			cheapest = Node;
		}
	}
	return cheapest;
}

SearchState::~SearchState()
{
}
