#pragma once
#include "AliveGameObject.h"


class Rabbit :
	public AliveGameObject
{
public:
	Rabbit(Node* _currentNode);
	void ChangePosition(std::vector<Node*> nodes);
	~Rabbit();
protected:
	Node* currentNode{ nullptr };
};