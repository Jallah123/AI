#include "AliveGameObject.h"
#include "NumberUtility.h"
#include "StateFactory.h"
#include "GameState.h"

AliveGameObject::AliveGameObject()
{
	currentState = StateFactory::Create(State::WANDERING);
	currentState->SetOwner(this);
	mWidth = 30;
	mHeight = 30;
}

void AliveGameObject::Move(float dt)
{
	currentState->Move(dt);
}

void AliveGameObject::Update(float dt)
{
	currentState->Update(dt);
}

void AliveGameObject::SetCurrentNode(Node* newNode)
{
	currentNode = newNode;
	mX = newNode->GetBoundingBox().x;
	mY = newNode->GetBoundingBox().y;
}