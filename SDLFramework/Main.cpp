#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include <vector>

#include "Ghost.h"
#include "Pacman.h"
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
	auto pacman = new Pacman(r.pacmanStart);
	application->AddRenderable(pacman);

	std::vector<Ghost>* ghosts;
	for (unsigned i = 0; i < 100; ++i) {
		Ghost* temp;
		if (i < 25) {
			temp = new Ghost(r.ghostStart1);
		}
		else if (i < 50) {
			temp = new Ghost(r.ghostStart2);
		}
		else if (i < 75) {
			temp = new Ghost(r.ghostStart3);
		}
		else {
			temp = new Ghost(r.ghostStart4);
		}
		application->AddRenderable(temp);
	}

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

		// DRAW FUNCTIONS

		application->SetColor(Color(255, 255, 255, 255));
		application->DrawTexture(background, 0, 0);

		application->DrawGraph(r.getGraph());

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
		
	}
		
	return EXIT_SUCCESS;
}
