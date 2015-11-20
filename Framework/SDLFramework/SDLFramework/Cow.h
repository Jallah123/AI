#pragma once
#include "AliveGameObject.h"
#include "Node.h"
#include <vector>
#include "Rabbit.h"

class Cow :
	public AliveGameObject
{
public:
	Cow();
	void Update(float dt);
	void CalculatePath(Node* targetNode);
	void NextStep(Rabbit* r, std::vector<Node*> nodes, std::vector<Edge*> edges);
	void Cow::ResetNodes(std::vector<Node*>& nodes);
	void Cow::ResetEdges(std::vector<Edge*> edges);
	std::pair<Node*, int> GetWeight(Node* n, Node* rabbitNode, Edge* e);
	Node* GetCheapestNode(std::vector<Node*>& nodes);
	std::vector<Node*> path;
	~Cow();
};

