#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "CApplication.h"
#include "TextureManager.h"
#include "CWorld.h"
#include "Skeleton.h"

SDL_Event event;
int main(int argc, char *argv[])
{
	bool quit = false;

	Player player(320,240);
	Skeleton skeleton(520, 270);


	application.run();

	int frame = 0;

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

		//Logic
		player.move();
		//skeleton.move();

		
		//Render world within the camera
		world.renderScreen(player.playerCam);
		//Render player 

		
		player.render(frame);
		skeleton.render(skeleton.getposX() - player.playerCam.x, skeleton.getposY());
		

		SDL_RenderPresent(application.renderer);

		++frame;

		if ((frame / 24) >= playerSpriteSheet.WALKING_ANIMATION_FRAMES)
		{
			frame = 0;
		}


	}


	application.close();

	return 0;
}