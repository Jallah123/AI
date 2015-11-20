#pragma once

class Node;
class Edge
{
public:
	Edge(Node* _n1, Node* _n2) { n1 = _n1; n2 = _n2; };
	Node* n1;
	Node* n2;
	Node* Edge::GetDifferentNodeFromEdge(Node* n);
	int Weight = 0;
	~Edge();
};

