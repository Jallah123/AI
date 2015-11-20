#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Node.h"
#include "Edge.h"
#include <vector>
#include <algorithm>
#include "Cow.h"
#include "Rabbit.h"

Edge* createEdge(Node* n1, Node* n2)
{
	Edge* e = new Edge(n1, n2);
	n1->AddEdge(e); 
	n2->AddEdge(e);
	return e;
}

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}


	application->SetTargetFPS(60);

	std::vector<Node*> nodes;
	// Fill nodes
	{
		nodes.push_back(new Node{ 10, 10 });
		nodes.push_back(new Node{ 75, 90 });
		nodes.push_back(new Node{ 50, 150 });
		nodes.push_back(new Node{ 250, 470 });
		nodes.push_back(new Node{ 387, 500 });
		nodes.push_back(new Node{ 500, 570 });
		nodes.push_back(new Node{ 480, 470 });
		nodes.push_back(new Node{ 40, 340 });
		nodes.push_back(new Node{ 250, 10 });
		nodes.push_back(new Node{ 400, 75 });
		nodes.push_back(new Node{ 300, 200 });
		nodes.push_back(new Node{ 400, 300 });
	}


	std::vector<Edge*> edges;
	// Fill edges
	{
		edges.push_back(createEdge(nodes.at(0), nodes.at(1)));
		edges.push_back(createEdge(nodes.at(1), nodes.at(2)));
		edges.push_back(createEdge(nodes.at(3), nodes.at(4)));
		edges.push_back(createEdge(nodes.at(4), nodes.at(5)));
		edges.push_back(createEdge(nodes.at(5), nodes.at(6)));
		edges.push_back(createEdge(nodes.at(6), nodes.at(7)));
		edges.push_back(createEdge(nodes.at(2), nodes.at(7)));
		edges.push_back(createEdge(nodes.at(8), nodes.at(9)));
		edges.push_back(createEdge(nodes.at(9), nodes.at(10)));
		edges.push_back(createEdge(nodes.at(10), nodes.at(11)));
		edges.push_back(createEdge(nodes.at(6), nodes.at(11)));
		edges.push_back(createEdge(nodes.at(1), nodes.at(8)));
		edges.push_back(createEdge(nodes.at(2), nodes.at(11)));
		edges.push_back(createEdge(nodes.at(1), nodes.at(10)));
		edges.push_back(createEdge(nodes.at(3), nodes.at(7)));
		edges.push_back(createEdge(nodes.at(11), nodes.at(7)));

		/*
		edges.push_back(new Edge{ nodes.at(1), nodes.at(8) });
		nodes.at(3)->AddEdge(edges.at(3));
		nodes.at(8)->AddEdge(edges.at(3));
		edges.push_back(new Edge{ nodes.at(4), nodes.at(8) });
		nodes.at(4)->AddEdge(edges.at(5));
		nodes.at(8)->AddEdge(edges.at(5));
		edges.push_back(new Edge{ nodes.at(7), nodes.at(11) });
		nodes.at(7)->AddEdge(edges.at(9));
		nodes.at(11)->AddEdge(edges.at(9));
		*/
	}


	Cow* c = new Cow;
	c->SetCurrentNode(nodes.at(2));

	Rabbit* r = new Rabbit;
	r->SetCurrentNode(nodes.at(6));

	c->CalculatePath(r->GetCurrentNode());

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case ' ':
					c->NextStep(r, nodes, edges);
				default:
					break;
				}
			}
		}

		application->UpdateGameObjects();
		application->RenderGameObjects();
		for each (auto& edge in edges)
		{
			int xmidpoint = (edge->n1->GetBoundingBox().x + edge->n2->GetBoundingBox().x) / 2;
			int ymidpoint = (edge->n1->GetBoundingBox().y + edge->n2->GetBoundingBox().y) / 2;
			application->DrawText(std::to_string(edge->Weight), xmidpoint, ymidpoint);
			application->DrawLine(edge->n1, edge->n2);
		}
		for each (auto& node in c->path)
		{
			application->DrawRect(node->GetBoundingBox().x, node->GetBoundingBox().y, 10, 10, true);
		}
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}