#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "CApplication.h"
#include "TextureManager.h"

SDL_Event event;
int main(int argc, char *argv[])
{
	bool quit = false;

	Player player(0,0);

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

		player.move();

		SDL_RenderClear(application.renderer);

		player.render();

		SDL_RenderPresent(application.renderer);


	}


	application.close();

	return 0;
}