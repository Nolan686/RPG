
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

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
	void render(int x, int y, SDL_Rect clip);
	void TextureManager::renderShit(int x, int y, SDL_Rect* clip);
	void render(int x, int y);

	void renderSpriteSheet(int x, int y, SDL_Rect* clip);

	int getWidth();
	int getHeight();

	static const int WALKING_ANIMATION_FRAMES = 24;

	SDL_Rect playerSpriteClips[24];


	void free();
};

extern TextureManager mapTexture;
extern TextureManager playerTextureLeft;
extern TextureManager playerTextureRight;
extern TextureManager skeletonTextureLeft;
extern TextureManager skeletonTextureRight;
extern TextureManager playerSpriteSheet;

#endif