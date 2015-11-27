#pragma once
#include "IGameObject.h"
#include "Node.h"
#include "NumberUtility.h"

class Pill :
	public IGameObject
{
public:
	Pill(Node* n);
	void Update(float dt) {};
	Node* GetNode() { return currentNode; };	
	void Respawn() {
		std::vector<Node*> nodes = FWApplication::GetInstance()->nodes;
		currentNode = nodes.at(NumberUtility::GenerateRandomNumber(0, nodes.size()-1));
		mX = currentNode->GetBoundingBox().x;
		mY = currentNode->GetBoundingBox().y;
	};
	~Pill();
private:
	Node* currentNode{ nullptr };
};

