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

Rabbit::~Rabbit()
{
}
