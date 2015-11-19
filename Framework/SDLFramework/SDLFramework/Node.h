#pragma once
#include "IGameObject.h"
#include <vector>
#include <limits>
#include "Edge.h"

class Node :
	public IGameObject
{
public:
	Node();
	Node(int x, int y);
	void Update(float dt);
	int weight = std::numeric_limits<int>::max();
	void AddEdge(Edge* edge) { edges.push_back(edge); };
	bool operator<(const Node& otherNode) {
		return weight < otherNode.weight;
	}
	std::vector<Edge*> edges;
	Node* prevNode{ nullptr };
	~Node();
};

