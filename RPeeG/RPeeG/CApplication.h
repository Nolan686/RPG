

#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

class CApplication
{
private:

public:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	int LEVEL_WIDTH = 2560;
	int LEVEL_HEIGHT = 480;
	

	SDL_Window *window = NULL;
	SDL_Renderer* renderer = NULL;

	CApplication();

	bool init();
	bool loadMedia();
	SDL_Texture* loadTexture(std::string path);
	void close();
	void run();
};

extern CApplication application;
#endif