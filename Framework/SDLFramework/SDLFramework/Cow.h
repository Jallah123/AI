#pragma once
#include "AliveGameObject.h"
#include "Node.h"
#include <vector>

class Rabbit;
class Cow :
	public AliveGameObject
{
public:
	Cow(Node* _currentNode);
	std::vector<Node*> path;
	~Cow();
};