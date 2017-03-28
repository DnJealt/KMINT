#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include <vector>
#include "Game.h"


const bool debug = true;

int main(int args[])
{
	// Seed the RNG
	srand(time(NULL));

	auto application = new FWApplication(50,50,1200,600);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	Game* game = new Game(application, debug);
	
		
	return EXIT_SUCCESS;
}
