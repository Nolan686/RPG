#include "CWorld.h"
#include "TextureManager.h"
#include <SDL.h>
#include <SDL_image.h>


CWorld world;

CWorld::CWorld()
{
	mapGrid();
	setStartValues();
}

void CWorld::mapGrid()
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < 1360; i++)
	{
		gridRect[i].w = GRID_WIDTH;
		gridRect[i].h = GRID_HEIGHT;
		y = 0;
		if (i <= 85)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 85)
		{
			x = 0;
		}
		y = 30;
		if (i > 85 && i <= 170)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 170)
		{
			x = 0;
		}
		y = 60;
		if (i > 170 && i <= 255)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 255)
		{
			x = 0;
		}
		y = 90;
		if (i > 255 && i <= 340)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 340)
		{
			x = 0;
		}
		y = 120;
		if (i > 340 && i <= 425)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 425)
		{
			x = 0;
		}
		y = 150;
		if (i > 425 && i <= 510)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 510)
		{
			x = 0;
		}
		y = 180;
		if (i > 510 && i <= 595)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 595)
		{
			x = 0;
		}
		y = 210;
		if (i > 595 && i <= 680)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 680)
		{
			x = 0;
		}
		y = 240;
		if (i > 680 && i <= 765)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 765)
		{
			x = 0;
		}
		y = 270;
		if (i > 765 && i <= 850)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 850)
		{
			x = 0;
		}
		y = 300;
		if (i > 850 && i <= 935)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 935)
		{
			x = 0;
		}
		y = 330;
		if (i > 935 && i <= 1020)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 1020)
		{
			x = 0;
		}
		y = 360;
		if (i > 1020 && i <= 1105)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 1105)
		{
			x = 0;
		}
		y = 390;
		if (i > 1105 && i <= 1190)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 1190)
		{
			x = 0;
		}
		y = 420;
		if (i > 1190 && i <= 1275)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
		if (i == 1275)
		{
			x = 0;
		}
		y = 450;
		if (i > 1275 && i <= 1360)
		{
			gridRect[i].x = x;
			gridRect[i].y = y;
			x += 30;
		}
	}
}

void CWorld::setStartValues()
{
	for (int i = 1020; i < 1360; i++)
	{
		gridValue[i] = impassable;
	}

	gridValue[989] = impassable;
}

void CWorld::renderScreen(SDL_Rect screen)
{

	mapTexture.render(0, 0, screen);

}
