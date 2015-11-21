#include "Cow.h"
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include "Edge.h"
#include "Node.h"
#include "Rabbit.h"

Cow::Cow(Node* currentNode) : AliveGameObject(currentNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
}

void Cow::NextStep(Rabbit* r, std::vector<Node*> nodes, std::vector<Edge*> edges)
{
	if (path.empty())
	{
		r->ChangePosition(nodes);
		ResetNodes(nodes);
		ResetEdges(edges);
		CalculatePath(r->GetCurrentNode());
		return;
	}
	currentNode = path.at(0);
	path.erase(std::find(path.begin(), path.end(), currentNode));
	mX = currentNode->GetBoundingBox().x;
	mY = currentNode->GetBoundingBox().y;
}

void Cow::ResetEdges(std::vector<Edge*> edges) 
{
	for each (auto& edge in edges)
	{
		edge->Weight = 0;
	}
}

void Cow::ResetNodes(std::vector<Node*>& nodes)
{
	for each (auto& Node in nodes)
	{
		Node->weight = 100000;
		Node->prevNode = nullptr;
	}
}

struct Comparetor {
	bool operator()(const Node* node1, const Node* node2) {
		return node1->weight < node2->weight;
	}
};

void Cow::CalculatePath(Node* targetNode)
{
	std::vector<Node*> ClosedSet;
	std::set<Node*> OpenSet;
	// std::priority_queue<Node*, std::vector<Node*>, Comparetor> NodeQueue;
	std::vector<Node*> NodeQueue;
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
			while (cNode != this->currentNode)
			{
				correctPath.push_back(cNode);
				cNode = cNode->prevNode;
			}
			std::reverse(correctPath.begin(), correctPath.end());
			path =  correctPath;
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

Node* Cow::GetCheapestNode(std::vector<Node*>& nodes)
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


Cow::~Cow()
{
}
