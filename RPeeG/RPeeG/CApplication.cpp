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

		window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
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

	if (!(playerSpriteSheet.loadFromFile("playerSpriteSheetRight.png")))
	{
		std::cout << "Failed to load player Sprite Sheet" << std::endl;
		success = false;
	}
	else
	{
		//Would like a function that can get the value of the image's dimensions so I don't have to manually input each valueeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
		playerSpriteSheet.playerSpriteClips[0].x = 0;
		playerSpriteSheet.playerSpriteClips[0].y = 0;
		playerSpriteSheet.playerSpriteClips[0].w = 114;
		playerSpriteSheet.playerSpriteClips[0].h = 125;

		playerSpriteSheet.playerSpriteClips[1].x = 114;
		playerSpriteSheet.playerSpriteClips[1].y = 0;
		playerSpriteSheet.playerSpriteClips[1].w = 114;
		playerSpriteSheet.playerSpriteClips[1].h = 125;

		playerSpriteSheet.playerSpriteClips[2].x = 228;
		playerSpriteSheet.playerSpriteClips[2].y = 0;
		playerSpriteSheet.playerSpriteClips[2].w = 114;
		playerSpriteSheet.playerSpriteClips[2].h = 125;

		playerSpriteSheet.playerSpriteClips[3].x = 342;
		playerSpriteSheet.playerSpriteClips[3].y = 0;
		playerSpriteSheet.playerSpriteClips[3].w = 114;
		playerSpriteSheet.playerSpriteClips[3].h = 125;

		playerSpriteSheet.playerSpriteClips[4].x = 456;
		playerSpriteSheet.playerSpriteClips[4].y = 0;
		playerSpriteSheet.playerSpriteClips[4].w = 114;
		playerSpriteSheet.playerSpriteClips[4].h = 125;

		playerSpriteSheet.playerSpriteClips[5].x = 570;
		playerSpriteSheet.playerSpriteClips[5].y = 0;
		playerSpriteSheet.playerSpriteClips[5].w = 114;
		playerSpriteSheet.playerSpriteClips[5].h = 125;

		playerSpriteSheet.playerSpriteClips[6].x = 684;
		playerSpriteSheet.playerSpriteClips[6].y = 0;
		playerSpriteSheet.playerSpriteClips[6].w = 114;
		playerSpriteSheet.playerSpriteClips[6].h = 125;

		playerSpriteSheet.playerSpriteClips[7].x = 0;
		playerSpriteSheet.playerSpriteClips[7].y = 132;
		playerSpriteSheet.playerSpriteClips[7].w = 114;
		playerSpriteSheet.playerSpriteClips[7].h = 125;

		playerSpriteSheet.playerSpriteClips[8].x = 114;
		playerSpriteSheet.playerSpriteClips[8].y = 132;
		playerSpriteSheet.playerSpriteClips[8].w = 114;
		playerSpriteSheet.playerSpriteClips[8].h = 125;

		playerSpriteSheet.playerSpriteClips[9].x = 228;
		playerSpriteSheet.playerSpriteClips[9].y = 132;
		playerSpriteSheet.playerSpriteClips[9].w = 114;
		playerSpriteSheet.playerSpriteClips[9].h = 125;

		playerSpriteSheet.playerSpriteClips[10].x = 342;
		playerSpriteSheet.playerSpriteClips[10].y = 132;
		playerSpriteSheet.playerSpriteClips[10].w = 114;
		playerSpriteSheet.playerSpriteClips[10].h = 125;

		playerSpriteSheet.playerSpriteClips[11].x = 456;
		playerSpriteSheet.playerSpriteClips[11].y = 132;
		playerSpriteSheet.playerSpriteClips[11].w = 114;
		playerSpriteSheet.playerSpriteClips[11].h = 125;

		playerSpriteSheet.playerSpriteClips[12].x = 570;
		playerSpriteSheet.playerSpriteClips[12].y = 132;
		playerSpriteSheet.playerSpriteClips[12].w = 114;
		playerSpriteSheet.playerSpriteClips[12].h = 125;

		playerSpriteSheet.playerSpriteClips[13].x = 684;
		playerSpriteSheet.playerSpriteClips[13].y = 132;
		playerSpriteSheet.playerSpriteClips[13].w = 114;
		playerSpriteSheet.playerSpriteClips[13].h = 125;

		playerSpriteSheet.playerSpriteClips[14].x = 0;
		playerSpriteSheet.playerSpriteClips[14].y = 264;
		playerSpriteSheet.playerSpriteClips[14].w = 114;
		playerSpriteSheet.playerSpriteClips[14].h = 125;

		playerSpriteSheet.playerSpriteClips[15].x = 114;
		playerSpriteSheet.playerSpriteClips[15].y = 264;
		playerSpriteSheet.playerSpriteClips[15].w = 114;
		playerSpriteSheet.playerSpriteClips[15].h = 125;

		playerSpriteSheet.playerSpriteClips[16].x = 228;
		playerSpriteSheet.playerSpriteClips[16].y = 264;
		playerSpriteSheet.playerSpriteClips[16].w = 114;
		playerSpriteSheet.playerSpriteClips[16].h = 125;

		playerSpriteSheet.playerSpriteClips[17].x = 342;
		playerSpriteSheet.playerSpriteClips[17].y = 264;
		playerSpriteSheet.playerSpriteClips[17].w = 114;
		playerSpriteSheet.playerSpriteClips[17].h = 125;

		playerSpriteSheet.playerSpriteClips[18].x = 456;
		playerSpriteSheet.playerSpriteClips[18].y = 264;
		playerSpriteSheet.playerSpriteClips[18].w = 114;
		playerSpriteSheet.playerSpriteClips[18].h = 125;

		playerSpriteSheet.playerSpriteClips[19].x = 570;
		playerSpriteSheet.playerSpriteClips[19].y = 264;
		playerSpriteSheet.playerSpriteClips[19].w = 114;
		playerSpriteSheet.playerSpriteClips[19].h = 125;

		playerSpriteSheet.playerSpriteClips[20].x = 684;
		playerSpriteSheet.playerSpriteClips[20].y = 264;
		playerSpriteSheet.playerSpriteClips[20].w = 114;
		playerSpriteSheet.playerSpriteClips[20].h = 125;

		playerSpriteSheet.playerSpriteClips[21].x = 0;
		playerSpriteSheet.playerSpriteClips[21].y = 396;
		playerSpriteSheet.playerSpriteClips[21].w = 114;
		playerSpriteSheet.playerSpriteClips[21].h = 125;

		playerSpriteSheet.playerSpriteClips[22].x = 114;
		playerSpriteSheet.playerSpriteClips[22].y = 396;
		playerSpriteSheet.playerSpriteClips[22].w = 114;
		playerSpriteSheet.playerSpriteClips[22].h = 125;

		playerSpriteSheet.playerSpriteClips[23].x = 228;
		playerSpriteSheet.playerSpriteClips[23].y = 396;
		playerSpriteSheet.playerSpriteClips[23].w = 114;
		playerSpriteSheet.playerSpriteClips[23].h = 125;

		playerSpriteSheet.playerSpriteClips[24].x = 342;
		playerSpriteSheet.playerSpriteClips[24].y = 396;
		playerSpriteSheet.playerSpriteClips[24].w = 114;
		playerSpriteSheet.playerSpriteClips[24].h = 125;

		playerSpriteSheet.playerSpriteClips[25].x = 456;
		playerSpriteSheet.playerSpriteClips[25].y = 396;
		playerSpriteSheet.playerSpriteClips[25].w = 114;
		playerSpriteSheet.playerSpriteClips[25].h = 125;

		playerSpriteSheet.playerSpriteClips[26].x = 570;
		playerSpriteSheet.playerSpriteClips[26].y = 396;
		playerSpriteSheet.playerSpriteClips[26].w = 114;
		playerSpriteSheet.playerSpriteClips[26].h = 125;

		


	}
	
	if (!(playerSpriteSheetLeft.loadFromFile("playerSpriteSheetLeft.png")))
	{
		std::cout << "Failed to load player Sprite Sheet" << std::endl;
		success = false;
	}
	else
	{



		playerSpriteSheetLeft.playerLeftSpriteClips[0].x = 684;
		playerSpriteSheetLeft.playerLeftSpriteClips[0].y = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[0].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[0].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[1].x = 570;
		playerSpriteSheetLeft.playerLeftSpriteClips[1].y = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[1].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[1].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[2].x = 456;
		playerSpriteSheetLeft.playerLeftSpriteClips[2].y = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[2].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[2].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[3].x = 342;
		playerSpriteSheetLeft.playerLeftSpriteClips[3].y = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[3].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[3].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[4].x = 228;
		playerSpriteSheetLeft.playerLeftSpriteClips[4].y = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[4].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[4].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[5].x = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[5].y = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[5].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[5].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[6].x = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[6].y = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[6].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[6].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[7].x = 684;
		playerSpriteSheetLeft.playerLeftSpriteClips[7].y = 132;
		playerSpriteSheetLeft.playerLeftSpriteClips[7].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[7].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[8].x = 570;
		playerSpriteSheetLeft.playerLeftSpriteClips[8].y = 132;
		playerSpriteSheetLeft.playerLeftSpriteClips[8].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[8].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[9].x = 456;
		playerSpriteSheetLeft.playerLeftSpriteClips[9].y = 132;
		playerSpriteSheetLeft.playerLeftSpriteClips[9].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[9].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[10].x = 342;
		playerSpriteSheetLeft.playerLeftSpriteClips[10].y = 132;
		playerSpriteSheetLeft.playerLeftSpriteClips[10].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[10].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[11].x = 228;
		playerSpriteSheetLeft.playerLeftSpriteClips[11].y = 132;
		playerSpriteSheetLeft.playerLeftSpriteClips[11].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[11].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[12].x = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[12].y = 132;
		playerSpriteSheetLeft.playerLeftSpriteClips[12].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[12].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[13].x = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[13].y = 132;
		playerSpriteSheetLeft.playerLeftSpriteClips[13].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[13].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[14].x = 684;
		playerSpriteSheetLeft.playerLeftSpriteClips[14].y = 264;
		playerSpriteSheetLeft.playerLeftSpriteClips[14].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[14].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[15].x = 570;
		playerSpriteSheetLeft.playerLeftSpriteClips[15].y = 264;
		playerSpriteSheetLeft.playerLeftSpriteClips[15].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[15].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[16].x = 456;
		playerSpriteSheetLeft.playerLeftSpriteClips[16].y = 264;
		playerSpriteSheetLeft.playerLeftSpriteClips[16].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[16].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[17].x = 342;
		playerSpriteSheetLeft.playerLeftSpriteClips[17].y = 264;
		playerSpriteSheetLeft.playerLeftSpriteClips[17].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[17].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[18].x = 228;
		playerSpriteSheetLeft.playerLeftSpriteClips[18].y = 264;
		playerSpriteSheetLeft.playerLeftSpriteClips[18].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[18].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[19].x = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[19].y = 264;
		playerSpriteSheetLeft.playerLeftSpriteClips[19].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[19].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[20].x = 0;
		playerSpriteSheetLeft.playerLeftSpriteClips[20].y = 264;
		playerSpriteSheetLeft.playerLeftSpriteClips[20].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[20].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[21].x = 684;
		playerSpriteSheetLeft.playerLeftSpriteClips[21].y = 396;
		playerSpriteSheetLeft.playerLeftSpriteClips[21].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[21].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[22].x = 570;
		playerSpriteSheetLeft.playerLeftSpriteClips[22].y = 396;
		playerSpriteSheetLeft.playerLeftSpriteClips[22].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[22].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[23].x = 456;
		playerSpriteSheetLeft.playerLeftSpriteClips[23].y = 396;
		playerSpriteSheetLeft.playerLeftSpriteClips[23].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[23].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[24].x = 342;
		playerSpriteSheetLeft.playerLeftSpriteClips[24].y = 396;
		playerSpriteSheetLeft.playerLeftSpriteClips[24].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[24].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[25].x = 228;
		playerSpriteSheetLeft.playerLeftSpriteClips[25].y = 396;
		playerSpriteSheetLeft.playerLeftSpriteClips[25].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[25].h = 125;

		playerSpriteSheetLeft.playerLeftSpriteClips[26].x = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[26].y = 396;
		playerSpriteSheetLeft.playerLeftSpriteClips[26].w = 114;
		playerSpriteSheetLeft.playerLeftSpriteClips[26].h = 125;

		


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