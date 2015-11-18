#pragma once
#include "IGameObject.h"
#include <vector>
#include "Edge.h"

class Node :
	public IGameObject
{
public:
	Node();
	Node(int x, int y);
	void Update(float dt);
	int weight = 100000;
	void AddEdge(Edge* edge) { edges.push_back(edge); };
	bool operator<(const Node& otherNode) {
		return weight < otherNode.weight;
	}
	std::vector<Edge*> edges;
	Node* prevNode{ nullptr };
	~Node();
};

