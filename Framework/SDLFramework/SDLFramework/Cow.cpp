#include "Cow.h"
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include "Edge.h"
#include "Node.h"
#include "Rabbit.h"

Cow::Cow(Node* currentNode) : AliveGameObject(currentNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
}

Cow::~Cow()
{
}
