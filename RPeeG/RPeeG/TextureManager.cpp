#include "TextureManager.h"

TextureManager mapTexture;
TextureManager playerTextureLeft(90,120);
TextureManager playerTextureRight(90,120);
TextureManager skeletonTextureLeft(30,60);
TextureManager skeletonTextureRight(30,60);
TextureManager playerSpriteSheet(800,530);
TextureManager playerSpriteSheetLeft(800,530);
TextureManager playerStandStillRight(2138, 150);
TextureManager playerStandStillLeft;

TextureManager::TextureManager(int width, int height)
{
	texture = NULL;
	tWidth = width;
	tHeight = height;
}

TextureManager::TextureManager()
{
	texture = NULL;
	tWidth = 0;
	tHeight = 0;
}

TextureManager::~TextureManager()
{
	free();
}

bool TextureManager::loadFromFile(std::string path)
{
	free();

	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = NULL;
	std::cout << "old" << loadedSurface << std::endl;
	loadedSurface = IMG_Load(path.c_str());
	std::cout << "new" << loadedSurface << std::endl;
	if (loadedSurface == NULL)
	{
		std::cout << "wat" << loadedSurface << std::endl;
		std::cout << "Unable to load image " << path.c_str() << " SDL_image error " << IMG_GetError() << std::endl;
		getchar();
	}
	else
	{

		newTexture = SDL_CreateTextureFromSurface(application.renderer, loadedSurface);

		if (newTexture == NULL)
		{
			std::cout << "Unable to create texture from " << path.c_str() << std::endl;
			getchar();
		}
		else
		{
			tWidth = loadedSurface->w;
			tHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	texture = newTexture;
	return texture != NULL;
}


void TextureManager::render(int x, int y)
{
	SDL_Rect renderQuad = { x, y, tWidth, tHeight };

	SDL_RenderCopyEx(application.renderer, texture, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE);
	
}

void TextureManager::render(int x, int y, SDL_Rect clip)
{

	SDL_Rect renderQuad = { 0, 0, application.SCREEN_WIDTH, application.SCREEN_HEIGHT };
	std::cout << clip.x << std::endl;

	SDL_RenderCopyEx(application.renderer, texture, &clip, &renderQuad, NULL, NULL, SDL_FLIP_NONE);

}

void TextureManager::renderAnimation(int x, int y, SDL_Rect* clip)
{

	SDL_Rect renderQuad = { x, y, clip->w, clip->h };
	std::cout << clip->x << std::endl;

	SDL_RenderCopyEx(application.renderer, texture, clip, &renderQuad, NULL, NULL, SDL_FLIP_NONE);

}

void TextureManager::renderSpriteSheet(int x, int y, SDL_Rect* clip)
{

	SDL_Rect renderQuad = {x, y, tWidth, tHeight};

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(renderer, texture, clip, &renderQuad);

}

int TextureManager::getWidth()
{
	return tWidth;
}
int TextureManager::getHeight()
{
	return tHeight;
}

void TextureManager::free()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}