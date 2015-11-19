#include "Cow.h"
#include <vector>
#include <limits>
#include <iostream>
#include <queue>

Cow::Cow()
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
}

void Cow::NextStep(Rabbit* r, std::vector<Node*> nodes, std::vector<Edge*>& edges)
{
	if (path.empty())
	{
		r->ChangePosition(nodes);
		ResetNodes(nodes, edges);
		CalculatePath(r->GetCurrentNode());
		return;
	}
	currentNode = path.at(0);
	path.erase(std::find(path.begin(), path.end(), currentNode));
	mX = currentNode->GetBoundingBox().x;
	mY = currentNode->GetBoundingBox().y;
}

void Cow::ResetNodes(std::vector<Node*>& nodes, std::vector<Edge*>& edges)
{
	for each (auto& Node in nodes)
	{
		Node->weight = 100000;
		Node->prevNode = nullptr;
	}
	for each (auto& Edge in edges)
	{
		Edge->Weight = 100000;
	}
}

struct lessThan {
	bool operator()(const Node* node1, const Node* node2) const
	{
		return node1->weight < node2->weight;
	}
};

void Cow::CalculatePath(Node* rabbitNode) 
{
	std::vector<Node*> ClosedSet;
	//std::vector<Node*> OpenSet;
	std::priority_queue<Node*, std::vector<Node*>, lessThan> OpenSet;
	std::vector<Node*> NodesInOpenSet;
	currentNode->weight = 0;
//	OpenSet.push_back(currentNode);
	OpenSet.push(currentNode);
	NodesInOpenSet.push_back(currentNode);

	while (!OpenSet.empty())
	{
	//	Node* cNode = GetCheapestNode(OpenSet);
	//	OpenSet.erase(std::find(OpenSet.begin(), OpenSet.end(), cNode));

		Node* cNode = OpenSet.top();
		OpenSet.pop();

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
			if (std::find(ClosedSet.begin(), ClosedSet.end(), weight.first) == ClosedSet.end() && std::find(NodesInOpenSet.begin(), NodesInOpenSet.end(), weight.first) == NodesInOpenSet.end())
			{
				//OpenSet.push_back(weight.first);
				OpenSet.push(weight.first);
				NodesInOpenSet.push_back(weight.first);
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
	e->Weight = weight;
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
