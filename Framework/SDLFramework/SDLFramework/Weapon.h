#pragma once
#include "IGameObject.h"
#include "Node.h"
#include "NumberUtility.h"

class Weapon :
	public IGameObject
{
public:
	Weapon(Node* n);
	void Update(float dt) {};
	Node* GetNode() { return currentNode; };
	void Respawn() { 
		std::vector<Node*> nodes = FWApplication::GetInstance()->nodes;
		currentNode = nodes.at(NumberUtility::GenerateRandomNumber(0, nodes.size()-1)); 
		mX = currentNode->GetBoundingBox().x;
		mY = currentNode->GetBoundingBox().y;
	};
	~Weapon();
private:
	Node* currentNode{ nullptr };
};

