#pragma once
#include "AliveGameObject.h"


class Rabbit :
	public AliveGameObject
{
public:
	Rabbit();
	void ChangePosition(std::vector<Node*> nodes);
	~Rabbit();
};