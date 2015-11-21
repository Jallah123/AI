#pragma once
#include "IGameObject.h"
#include <vector>

class Edge;
class Node :
	public IGameObject
{
public:
	Node(int x, int y);
	void Draw();
	void Update(float dt);
	int weight = 100000;
	void AddEdge(Edge* edge) { edges.push_back(edge); };
	bool operator<(const Node& otherNode) {
		return weight < otherNode.weight;
	}
	static int next_id;
	int id = 0;
	std::vector<Edge*> edges;
	std::vector<Edge*> GetEdges() { return edges; };
	Node* prevNode{ nullptr };
	~Node();
};

