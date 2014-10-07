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

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					std::cout << "SDL_mixer could not initialize! SDL_mixer Error" << std::endl;
					success = false;
				}
			}
		}
	}
	return success;
}

bool CApplication::loadMusic()
{
	bool MusicLoaded = true;

	sound.goneFishing = Mix_LoadMUS("gonefishing.mp3");
	if (sound.goneFishing == NULL)
	{
		printf("Failed to load the Gone Fishing song! SDL_mixer Error: %s\n", Mix_GetError());
		MusicLoaded = false;
	}



	return MusicLoaded;
}

bool CApplication::loadMedia()
{
	bool success = true;

	loadMusic();
	
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
		std::cout << "Failed to load player Right texture!" << std::endl;
		success = false;
	}

	if (!(playerTextureLeft.loadFromFile("playerleft.png")))
	{
		std::cout << "Failed to load player Left texture!" << std::endl;
	}

	if (!(skeletonTextureRight.loadFromFile("skeletonRight.png")))
	{
		std::cout << "Failed to load world texture!" << std::endl;
		success = false;
	}


	if (!(playerStandStillRight.loadFromFile("playerStandingRight.png")))
	{
		std::cout << "Failed to load player standing still right sheet" << std::endl;
		success = false;
	}
	else
	{
		animationClips.playerStandStillRightClips();
	}


	if (!(playerSpriteSheet.loadFromFile("playerSpriteSheetRight.png")))
	{
		std::cout << "Failed to load player Sprite Sheet" << std::endl;
		success = false;
	}
	else
	{
		//Would like a function that can get the value of the image's dimensions so I don't have to manually input each valueeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
		animationClips.playerRightRunningClips();
	}
	
	if (!(playerSpriteSheetLeft.loadFromFile("playerSpriteSheetLeft.png")))
	{
		std::cout << "Failed to load player Sprite Sheet" << std::endl;
		success = false;
	}
	else
	{
		
		animationClips.playerLeftRunningClips();

	}

	return success;
}



void CApplication::close()
{
	playerTextureLeft.free();
	playerTextureRight.free();
	playerSpriteSheet.free();
	playerSpriteSheetLeft.free();
	skeletonTextureLeft.free();
	skeletonTextureRight.free();

	sound.goneFishing = NULL;
	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}