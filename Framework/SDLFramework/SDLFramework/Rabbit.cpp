#include "Rabbit.h"
#include "NumberUtility.h"

Rabbit::Rabbit()
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	mApplication->AddRenderable(this);
}

void Rabbit::ChangePosition(std::vector<Node*> nodes)
{
	Node* prevNode = currentNode;
	Node* newNode = nodes.at(NumberUtility::GenerateRandomNumber(0, nodes.size() - 1));
	while (prevNode == newNode)
	{
		newNode = nodes.at(NumberUtility::GenerateRandomNumber(0, nodes.size() - 1));
	}
	SetCurrentNode(newNode);
	
}

void Rabbit::SetCurrentNode(Node* newNode)
{
	currentNode = newNode;
	mX = newNode->GetBoundingBox().x;
	mY = newNode->GetBoundingBox().y;
	mWidth = 30;
	mHeight = 30;
}


Rabbit::~Rabbit()
{
}
