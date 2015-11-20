#pragma once
#include "IGameObject.h"
#include "Node.h"
#include <vector>
#include "Rabbit.h"

class Cow :
	public IGameObject
{
public:
	Cow();
	void Update(float dt);
	void SetCurrentNode(Node* newNode);
	void CalculatePath(Node* rabbitNode);
	void NextStep(Rabbit* r, std::vector<Node*> nodes, std::vector<Edge*> edges);
	void Cow::ResetNodes(std::vector<Node*>& nodes);
	void Cow::ResetEdges(std::vector<Edge*> edges);
	Node* Cow::GetDifferentNodeFromEdge(Edge* e, Node* n);
	std::pair<Node*, int> GetWeight(Node* n, Node* rabbitNode, Edge* e);
	Node* GetCheapestNode(std::vector<Node*>& nodes);
	std::vector<Node*> path;
	~Cow();
private:
	Node* currentNode{ nullptr };
};

