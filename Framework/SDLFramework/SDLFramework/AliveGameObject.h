#pragma once
#include "IGameObject.h"
#include "Node.h"
#include <vector>

class GameState;
class AliveGameObject :
	public IGameObject
{
public:
	AliveGameObject(Node* n);
	void Update(float dt);
	void Move(float dt);
	void ChangeState(GameState* newState);
	Node* GetCurrentNode() { return currentNode; };
	void SetCurrentNode(Node* newNode);
	virtual ~AliveGameObject() {};
	GameState* GetCurrentState() { return currentState; };
protected:
	Node* currentNode{ nullptr };
	GameState* currentState{ nullptr };
};

