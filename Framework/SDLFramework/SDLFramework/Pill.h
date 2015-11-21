#pragma once
#include "IGameObject.h"
#include "Node.h"

class Pill :
	public IGameObject
{
public:
	Pill(Node* n);
	void Update(float dt) {};
	Node* GetNode() { return currentNode; };
	~Pill();
private:
	Node* currentNode{ nullptr };
};

