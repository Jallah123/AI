#include "Node.h"
#include "NumberUtility.h"
#include <string>

int Node::next_id = 0;

Node::Node(int x, int y)
{
	mTexture = mApplication->LoadTexture("Node.png");
	mX = x;
	mY = y;

	id = next_id;
	next_id++;
	mApplication->AddRenderable(this);
}

void Node::Draw()
{
	IGameObject::Draw();
//	mApplication->DrawText(std::to_string(id), mX + 10, mY + 0);
//	mApplication->DrawText(std::to_string(weight), mX + 5, mY + 5);
}


void Node::Update(float dt) 
{
	
}


Node::~Node()
{
}
