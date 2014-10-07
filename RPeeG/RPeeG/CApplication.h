

#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include "Sound.h"
#include "AnimationClips.h"

class CApplication
{
private:

public:
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	int LEVEL_WIDTH = 2048;
	int LEVEL_HEIGHT = 1200;
	

	SDL_Window *window = NULL;
	SDL_Renderer* renderer = NULL;

	CApplication();

	bool init();
	bool loadMedia();
	bool loadMusic();
	SDL_Texture* loadTexture(std::string path);
	void close();
	void run();
};

extern CApplication application;
#endif