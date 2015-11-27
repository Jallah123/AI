#include "Cow.h"
#include "StateFactory.h"

Cow::Cow(Node* currentNode) : AliveGameObject(currentNode)
{
	currentState = StateFactory::Create(State::CHASE_RABBIT, this);
	mTexture = mApplication->LoadTexture("cow-1.png");
	mApplication->AddRenderable(this);
}

Cow::~Cow()
{
}
