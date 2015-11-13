#pragma once
#include "IGameObject.h"
#include "Node.h"
#include <vector>

class Rabbit :
	public IGameObject
{
public:
	Rabbit();
	void Update(float dt) {};
	Node* GetCurrentNode() { return currentNode; };
	void ChangePosition(std::vector<Node*> nodes);
	void SetCurrentNode(Node* newNode);
	~Rabbit();
private:
	Node* currentNode{ nullptr };
};

