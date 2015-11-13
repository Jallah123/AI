#include "Node.h"
#include "NumberUtility.h"


Node::Node()
{
	mTexture = mApplication->LoadTexture("Node.png");
	mX = NumberUtility::GenerateRandomNumber(0, 770);
	mY = NumberUtility::GenerateRandomNumber(0, 570);

	mApplication->AddRenderable(this);
}

Node::Node(int x, int y)
{
	mTexture = mApplication->LoadTexture("Node.png");
	mX = x;
	mY = y;
	mApplication->AddRenderable(this);
}


void Node::Update(float dt) 
{
	
}


Node::~Node()
{
}
