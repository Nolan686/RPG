#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>


#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "CApplication.h"

class TextureManager
{
private:
	SDL_Texture *texture;

	int tWidth;
	int tHeight;
public:
	TextureManager();
	~TextureManager();

	SDL_Window *window;
	SDL_Renderer *renderer;

	bool loadFromFile(std::string path);
	void render(int x, int y);

	int getWidth();
	int getHeight();

	void free();
};

extern TextureManager somethingtexture;
extern TextureManager playerTexture;

#endif