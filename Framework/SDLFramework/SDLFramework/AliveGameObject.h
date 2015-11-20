#pragma once
#include "IGameObject.h"
#include "Node.h"
#include <vector>

class GameState;
class AliveGameObject :
	public IGameObject
{
public:
	AliveGameObject();
	void Update(float dt);
	void Move(float dt);
	void ChangeState(GameState* newState) { currentState = nullptr; currentState = newState; };
	Node* GetCurrentNode() { return currentNode; };
	void SetCurrentNode(Node* newNode);
	virtual ~AliveGameObject() {};
protected:
	Node* currentNode{ nullptr };
	GameState* currentState{ nullptr };
};

