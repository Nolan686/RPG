
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
	void TextureManager::renderAnimation(int x, int y, SDL_Rect* clip);
	void render(int x, int y);

	void renderSpriteSheet(int x, int y, SDL_Rect* clip);

	int getWidth();
	int getHeight();

	static const int WALKING_ANIMATION_FRAMES = 27;

	SDL_Rect playerSpriteClips[27];
	SDL_Rect playerLeftSpriteClips[27];
	SDL_Rect playerStandStillRightClips[22];
	SDL_Rect playerStandStillLeftClips[22];


	void free();
};

extern TextureManager mapTexture;
extern TextureManager playerTextureLeft;
extern TextureManager playerTextureRight;
extern TextureManager skeletonTextureLeft;
extern TextureManager skeletonTextureRight;
extern TextureManager playerSpriteSheet;
extern TextureManager playerSpriteSheetLeft;
extern TextureManager playerStandStillRight;
extern TextureManager playerStandStillLeft;


#endif