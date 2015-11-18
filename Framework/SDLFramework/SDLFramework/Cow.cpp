#include "Cow.h"
#include <vector>
#include <iostream>
#include <queue>
#include <set>

Cow::Cow()
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
}

void Cow::NextStep(Rabbit* r, std::vector<Node*> nodes)
{
	if (path.empty())
	{
		r->ChangePosition(nodes);
		ResetNodes(nodes);
		CalculatePath(r->GetCurrentNode());
		return;
	}
	currentNode = path.at(0);
	path.erase(std::find(path.begin(), path.end(), currentNode));
	mX = currentNode->GetBoundingBox().x;
	mY = currentNode->GetBoundingBox().y;
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

void Cow::CalculatePath(Node* rabbitNode) 
{
	std::vector<Node*> ClosedSet;
	std::set<Node*> OpenSet;
	std::priority_queue<Node*, std::vector<Node*>, Comparetor> NodeQueue;
	currentNode->weight = 0;
	NodeQueue.push(currentNode);
	OpenSet.insert(currentNode);

	while (!NodeQueue.empty())
	{
		// Node* cNode = GetCheapestNode(OpenSet);
		// OpenSet.erase(std::find(OpenSet.begin(), OpenSet.end(), cNode));

		Node* cNode = NodeQueue.top();
		// OpenSet2.pop();
		NodeQueue.pop();
		OpenSet.erase(cNode);

		if (cNode == rabbitNode)
		{
			ClosedSet.push_back(rabbitNode);
			std::vector<Node*> correctPath;
			while (cNode != this->currentNode)
			{
				correctPath.push_back(cNode);
				cNode = cNode->prevNode;
			}
			std::reverse(correctPath.begin(), correctPath.end());
			path = correctPath;
			return;
		}

		for each (auto Edge in cNode->edges)
		{
			std::pair<Node*, int> weight = GetWeight(cNode, rabbitNode, Edge);
			if (weight.second < weight.first->weight)
			{
				weight.first->weight = weight.second;
				weight.first->prevNode = cNode;
			}
			if (std::find(ClosedSet.begin(), ClosedSet.end(), weight.first) == ClosedSet.end() && find(OpenSet.begin(), OpenSet.end(), weight.first) == OpenSet.end())
			{
				NodeQueue.push(weight.first);
				OpenSet.insert(weight.first);
			}
		}
		ClosedSet.push_back(cNode);
	}
}

std::pair<Node*, int> Cow::GetWeight(Node* n, Node* rabbitNode, Edge* e)
{
	int weight = e->Weight;
	std::pair<Node*, int> pair;

	if (e->n1 == n) {
		weight += e->n2->DistanceTo(rabbitNode) + e->n2->weight;
		pair = std::make_pair(e->n2, weight);
	}
	else {
		weight += e->n1->DistanceTo(rabbitNode) + e->n1->weight;
		pair = std::make_pair(e->n1, weight);
	}
	return pair;
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

void Cow::SetCurrentNode(Node* newNode)
{
	currentNode = newNode;
	mX = newNode->GetBoundingBox().x;
	mY = newNode->GetBoundingBox().y;
	mWidth = 30;
	mHeight = 30;
}

void Cow::Update(float dt)
{
}


Cow::~Cow()
{
}
