#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include <vector>
#include "Game.h"

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

	Game* game = new Game(application);
	
		
	return EXIT_SUCCESS;
}
