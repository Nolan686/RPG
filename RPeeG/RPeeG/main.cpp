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

	int frameRight = 594;
	int frameLeft = 0;

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

		//Play music
		//sound.playMusic(sound.goneFishing);

		SDL_RenderClear(application.renderer);

		//Logic
		player.move();
		//skeleton.move();

		
		//Render world within the camera
		world.renderScreen(player.playerCam);
		//Render player 

		
		player.render(frameRight, frameLeft);
		skeleton.render(skeleton.getposX() - player.playerCam.x, skeleton.getposY() - player.playerCam.y);
		

		SDL_RenderPresent(application.renderer);

		
		//Sprite sheet frame setting. Resets after clip 27
		if ((frameRight / 27) >= playerSpriteSheet.WALKING_ANIMATION_FRAMES-1)
		{
			frameRight = 0;
		}
		//Increase or decrease speed of animation here
		if (player.getRight())
		{
			frameRight += 14;
		}
		//Set starting animation clip. divide by 27 to get current clip
		if (player.getRight() == false)
		{
			frameRight = 594;
		}
		//Same as above one but for running left
		if ((frameLeft / 27) >= playerSpriteSheet.WALKING_ANIMATION_FRAMES - 1)
		{
			frameLeft = 0;
		}

		if (player.getLeft())
		{
			frameLeft += 14;
		}
		if (player.getLeft() == false)
		{
			frameLeft = 0;
		}
		

	}


	application.close();

	return 0;
}