#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "ExampleGameObject.h"
#include "Rift.h"


int main(int args[])
{
	// Seed the RNG
	srand(time(NULL));
	Rift r;

	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication(50,50,1200,600);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));

	auto background = application->LoadTexture("background.png");

	//// Dancing cow
	//ExampleGameObject *example = new ExampleGameObject();
	//application->AddRenderable(example);

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

				default:
					break;
				}
			}
		}
		
		// For the background

		application->SetColor(Color(255, 255, 255, 255));
		application->DrawTexture(background, 0, 0);

		application->DrawGraph(r.getGraph());

		//// Text drawing
		//application->SetColor(Color(0, 0, 0, 255));
		//application->DrawText("Welcome to KMint", 400, 300);
		//
		//// Graph drawing
		//application->SetColor(Color(0, 0, 0, 255));
		//application->DrawLine(400, 350, 350, 400);
		//application->DrawLine(350, 400, 450, 400);
		//application->DrawLine(450, 400, 400, 350);

		//application->SetColor(Color(0, 0, 255, 255));
		//application->DrawCircle(400, 350, 10, true);
		//application->DrawCircle(350, 400, 10, true);
		//application->DrawCircle(450, 400, 10, true);

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}
