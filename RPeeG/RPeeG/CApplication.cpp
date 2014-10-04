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
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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

	
	if (!(playerTexture.loadFromFile("player.bmp")))
	{
		std::cout << "Failed to load player Texture!" << std::endl;
		success = false;
	}

	return success;
}



void CApplication::close()
{
	//sometexture.free();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}