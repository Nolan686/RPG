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

	Player player(320,240);

	SDL_Rect playerCam = { 0, 0, 640, 480 };

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

		playerCam.x = (player.getposX() + player.PLAYER_WIDTH / 2) - (application.SCREEN_WIDTH / 2);
		playerCam.y = (player.getposY() + player.PLAYER_HEIGHT / 2) - (application.SCREEN_HEIGHT / 2);

		if (playerCam.x < 0)
		{
			playerCam.x = 0;
		}

		if (playerCam.y < 0)
		{
			playerCam.y = 0;
		}

		if (playerCam.x > application.LEVEL_WIDTH - playerCam.w)
		{
			playerCam.x = application.LEVEL_WIDTH - playerCam.w;
		}

		if (playerCam.y > application.LEVEL_HEIGHT - playerCam.h)
		{
			playerCam.y = application.LEVEL_HEIGHT - playerCam.h;
		}

		world.renderScreen(playerCam);

		playerTexture.render(player.getposX() - playerCam.x, player.getposY() - playerCam.y);
		

		SDL_RenderPresent(application.renderer);


	}


	application.close();

	return 0;
}