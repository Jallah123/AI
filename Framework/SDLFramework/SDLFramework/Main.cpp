#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include <vector>
#include <algorithm>
#include "Edge.h"
#include "Node.h"
#include "Cow.h"
#include "Rabbit.h"

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
					// c->NextStep(r, nodes, edges);
					application->c->Update(1.0);
					application->r->Update(1.0);
					application->c->Move(1.0);
					application->r->Move(1.0);
				default:
					break;
				}
			}
		}

		// application->UpdateGameObjects();
		application->RenderGameObjects();
		for each (auto& edge in application->edges)
		{
			int xmidpoint = (edge->n1->GetBoundingBox().x + edge->n2->GetBoundingBox().x) / 2;
			int ymidpoint = (edge->n1->GetBoundingBox().y + edge->n2->GetBoundingBox().y) / 2;
			application->DrawLine(edge->n1, edge->n2);
		}
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}