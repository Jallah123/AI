#pragma once
#include "IGameObject.h"
#include "Node.h"

class Weapon :
	public IGameObject
{
public:
	Weapon(Node* n);
	void Update(float dt) {};
	Node* GetNode() { return currentNode; };
	~Weapon();
private:
	Node* currentNode{ nullptr };
};

