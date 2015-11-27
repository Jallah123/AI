#pragma once
#include "AliveGameObject.h"

class Rabbit :
	public AliveGameObject
{
public:
	Rabbit(Node* _currentNode);
	bool HasPill = false;
	~Rabbit();
};