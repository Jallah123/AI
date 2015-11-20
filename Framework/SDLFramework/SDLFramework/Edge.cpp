#include "Edge.h"

Node* Edge::GetDifferentNodeFromEdge(Node* n)
{
	if (n1 == n)
	{
		return n2;
	}
	return n1;
}

Edge::~Edge()
{
	n1 = nullptr;
	n2 = nullptr;
}
