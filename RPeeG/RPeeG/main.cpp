#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "CApplication.h"
#include "TextureManager.h"
#include "CWorld.h"

SDL_Event event;
int main(int argc, char *argv[])
{
	bool quit = false;

	Player player(10,330);

	application.run();

	while (quit == false)
	{

		while (SDL_PollEvent(&event))
		{

			player.inputHandler(event);


			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}

		SDL_RenderClear(application.renderer);

		player.move();

		if (player.getposX() < 640)
		{
			std::cout << "Why you do dis" << std::endl;
			world.renderScreen(0);
		}

		if (player.getposX() >= 640)
		{
			world.renderScreen(1);
		}

		if (player.getposX() >= 1280)
		{
			world.renderScreen(2);
		}

		if (player.getposX() > 1920)
		{
			world.renderScreen(3);
		}


		player.render();
		

		SDL_RenderPresent(application.renderer);


	}


	application.close();

	return 0;
}