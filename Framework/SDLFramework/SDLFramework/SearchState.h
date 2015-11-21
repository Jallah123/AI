#pragma once
#include "GameState.h"

class Node;
class SearchState :
	public GameState
{
public:
	SearchState();
	virtual void Update(float dt);
	void Move(float dt);
	virtual void CheckState() = 0;
	~SearchState();
protected:
	void SetTarget(Node* _target) { target = _target; CalculatePath(target); };
	Node* target;
private:
	std::vector<Node*> path;
	Node* SearchState::GetCheapestNode(std::vector<Node*>& nodes);
	void SearchState::CalculatePath(Node* targetNode);
};

