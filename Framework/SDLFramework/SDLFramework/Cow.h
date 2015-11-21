#pragma once
#include "AliveGameObject.h"
#include "Node.h"
#include <vector>

class Rabbit;
class Cow :
	public AliveGameObject
{
public:
	Cow(Node* _currentNode);
	void CalculatePath(Node* targetNode);
	void NextStep(Rabbit* r, std::vector<Node*> nodes, std::vector<Edge*> edges);
	void Cow::ResetNodes(std::vector<Node*>& nodes);
	void Cow::ResetEdges(std::vector<Edge*> edges);
	Node* GetCheapestNode(std::vector<Node*>& nodes);
	std::vector<Node*> path;
	~Cow();
};

