#include "Rabbit.h"
#include "StateFactory.h"

Rabbit::Rabbit(Node* currentNode) : AliveGameObject(currentNode)
{
	currentState = StateFactory::Create(State::WANDERING, this);
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	mApplication->AddRenderable(this);
}

Rabbit::~Rabbit()
{
}
