#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

#ifndef CWORLD_H
#define CWORLD_H

#include "TextureManager.h"

class CWorld
{
private:
	const int GRID_WIDTH = 30;
	const int GRID_HEIGHT = 30;
public:
	CWorld();

	int gridValue[1360];

	SDL_Rect gridRect[1360];

	const int passable = 0;
	const int impassable = 1;

	void mapGrid();
	void setStartValues();
	void renderScreen(int mapSection);
};

extern CWorld world;

#endif