#pragma once
#include "IGameObject.h"
#include <limits>
#include <vector>
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
	std::vector<Edge*> edges;
	Node* prevNode{ nullptr };
	~Node();
};

