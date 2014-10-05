#include "CApplication.h"
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

CApplication application;

CApplication::CApplication()
{

}

void CApplication::run()
{

	if (!init())
	{
		std::cout << "INIT DUN FUCKLED" << std::endl;
	}

	if (!loadMedia())
	{
		std::cout << "Can't load media" << std::endl; 
	}

}


bool CApplication::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize" << std::endl;
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: linear texture filtering not enabled!" << std::endl;
			getchar();
		}

		window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "Window could not be created!" << std::endl;
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created" << std::endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL Image could not initialize!" << std::endl;
					success = false;
				}
			}
		}
	}
	return success;
}

bool CApplication::loadMedia()
{
	bool success = true;

	
	if (!(playerTextureLeft.loadFromFile("playerleft.png")))
	{
		std::cout << "Failed to load player Texture!" << std::endl;
		success = false;
	}

	if (!(mapTexture.loadFromFile("world.png")))
	{
		std::cout << "Failed to load world texture!" << std::endl;
		success = false;
	}
	if (!(playerTextureRight.loadFromFile("playerright.png")))
	{
		std::cout << "Failed to load world texture!" << std::endl;
		success = false;
	}
	if (!(skeletonTextureRight.loadFromFile("skeletonRight.png")))
	{
		std::cout << "Failed to load world texture!" << std::endl;
		success = false;
	}

	if (!(playerSpriteSheet.loadFromFile("playerSpriteSheet.png")))
	{
		std::cout << "Failed to load player Sprite Sheet" << std::endl;
		success = false;
	}
	else
	{
		playerSpriteSheet.playerSpriteClips[0].x = 0;
		playerSpriteSheet.playerSpriteClips[0].y = 0;
		playerSpriteSheet.playerSpriteClips[0].w = 150;
		playerSpriteSheet.playerSpriteClips[0].h = 150;

		playerSpriteSheet.playerSpriteClips[1].x = 150;
		playerSpriteSheet.playerSpriteClips[1].y = 0;
		playerSpriteSheet.playerSpriteClips[1].w = 150;
		playerSpriteSheet.playerSpriteClips[1].h = 150;

		playerSpriteSheet.playerSpriteClips[2].x = 300;
		playerSpriteSheet.playerSpriteClips[2].y = 0;
		playerSpriteSheet.playerSpriteClips[2].w = 150;
		playerSpriteSheet.playerSpriteClips[2].h = 150;

		playerSpriteSheet.playerSpriteClips[3].x = 450;
		playerSpriteSheet.playerSpriteClips[3].y = 0;
		playerSpriteSheet.playerSpriteClips[3].w = 150;
		playerSpriteSheet.playerSpriteClips[3].h = 150;

		playerSpriteSheet.playerSpriteClips[4].x = 600;
		playerSpriteSheet.playerSpriteClips[4].y = 0;
		playerSpriteSheet.playerSpriteClips[4].w = 150;
		playerSpriteSheet.playerSpriteClips[4].h = 150;

		playerSpriteSheet.playerSpriteClips[5].x = 750;
		playerSpriteSheet.playerSpriteClips[5].y = 0;
		playerSpriteSheet.playerSpriteClips[5].w = 150;
		playerSpriteSheet.playerSpriteClips[5].h = 150;

		playerSpriteSheet.playerSpriteClips[6].x = 0;
		playerSpriteSheet.playerSpriteClips[6].y = 150;
		playerSpriteSheet.playerSpriteClips[6].w = 150;
		playerSpriteSheet.playerSpriteClips[6].h = 150;

		playerSpriteSheet.playerSpriteClips[7].x = 150;
		playerSpriteSheet.playerSpriteClips[7].y = 150;
		playerSpriteSheet.playerSpriteClips[7].w = 150;
		playerSpriteSheet.playerSpriteClips[7].h = 150;

		playerSpriteSheet.playerSpriteClips[8].x = 300;
		playerSpriteSheet.playerSpriteClips[8].y = 150;
		playerSpriteSheet.playerSpriteClips[8].w = 150;
		playerSpriteSheet.playerSpriteClips[8].h = 150;

		playerSpriteSheet.playerSpriteClips[9].x = 450;
		playerSpriteSheet.playerSpriteClips[9].y = 150;
		playerSpriteSheet.playerSpriteClips[9].w = 150;
		playerSpriteSheet.playerSpriteClips[9].h = 150;

		playerSpriteSheet.playerSpriteClips[10].x = 600;
		playerSpriteSheet.playerSpriteClips[10].y = 150;
		playerSpriteSheet.playerSpriteClips[10].w = 150;
		playerSpriteSheet.playerSpriteClips[10].h = 150;

		playerSpriteSheet.playerSpriteClips[11].x = 750;
		playerSpriteSheet.playerSpriteClips[11].y = 150;
		playerSpriteSheet.playerSpriteClips[11].w = 150;
		playerSpriteSheet.playerSpriteClips[11].h = 150;

		playerSpriteSheet.playerSpriteClips[12].x = 0;
		playerSpriteSheet.playerSpriteClips[12].y = 300;
		playerSpriteSheet.playerSpriteClips[12].w = 150;
		playerSpriteSheet.playerSpriteClips[12].h = 150;

		playerSpriteSheet.playerSpriteClips[13].x = 150;
		playerSpriteSheet.playerSpriteClips[13].y = 300;
		playerSpriteSheet.playerSpriteClips[13].w = 150;
		playerSpriteSheet.playerSpriteClips[13].h = 150;

		playerSpriteSheet.playerSpriteClips[14].x = 300;
		playerSpriteSheet.playerSpriteClips[14].y = 300;
		playerSpriteSheet.playerSpriteClips[14].w = 150;
		playerSpriteSheet.playerSpriteClips[14].h = 150;

		playerSpriteSheet.playerSpriteClips[15].x = 450;
		playerSpriteSheet.playerSpriteClips[15].y = 300;
		playerSpriteSheet.playerSpriteClips[15].w = 150;
		playerSpriteSheet.playerSpriteClips[15].h = 150;

		playerSpriteSheet.playerSpriteClips[16].x = 600;
		playerSpriteSheet.playerSpriteClips[16].y = 300;
		playerSpriteSheet.playerSpriteClips[16].w = 150;
		playerSpriteSheet.playerSpriteClips[16].h = 150;

		playerSpriteSheet.playerSpriteClips[17].x = 750;
		playerSpriteSheet.playerSpriteClips[17].y = 300;
		playerSpriteSheet.playerSpriteClips[17].w = 150;
		playerSpriteSheet.playerSpriteClips[17].h = 150;

		playerSpriteSheet.playerSpriteClips[18].x = 0;
		playerSpriteSheet.playerSpriteClips[18].y = 450;
		playerSpriteSheet.playerSpriteClips[18].w = 150;
		playerSpriteSheet.playerSpriteClips[18].h = 150;

		playerSpriteSheet.playerSpriteClips[19].x = 150;
		playerSpriteSheet.playerSpriteClips[19].y = 450;
		playerSpriteSheet.playerSpriteClips[19].w = 150;
		playerSpriteSheet.playerSpriteClips[19].h = 150;

		playerSpriteSheet.playerSpriteClips[20].x = 300;
		playerSpriteSheet.playerSpriteClips[20].y = 450;
		playerSpriteSheet.playerSpriteClips[20].w = 150;
		playerSpriteSheet.playerSpriteClips[20].h = 150;

		playerSpriteSheet.playerSpriteClips[21].x = 450;
		playerSpriteSheet.playerSpriteClips[21].y = 450;
		playerSpriteSheet.playerSpriteClips[21].w = 150;
		playerSpriteSheet.playerSpriteClips[21].h = 150;

		playerSpriteSheet.playerSpriteClips[22].x = 600;
		playerSpriteSheet.playerSpriteClips[22].y = 450;
		playerSpriteSheet.playerSpriteClips[22].w = 150;
		playerSpriteSheet.playerSpriteClips[22].h = 150;

		playerSpriteSheet.playerSpriteClips[23].x = 750;
		playerSpriteSheet.playerSpriteClips[23].y = 450;
		playerSpriteSheet.playerSpriteClips[23].w = 150;
		playerSpriteSheet.playerSpriteClips[23].h = 150;

	}
	

	return success;
}



void CApplication::close()
{
	playerTextureLeft.free();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}