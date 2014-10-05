#include "Skeleton.h"



Skeleton::Skeleton(int x, int y)
{
	posX = x;
	posY = y;

	velX = 1;
	velY = 15;
}

void Skeleton::move()
{

	posX += velX;

	if (posX < 0)
	{
		posX = 0;
	}

	if (posX > application.LEVEL_WIDTH - SKELETON_WIDTH)
	{
		posX = application.LEVEL_WIDTH - SKELETON_WIDTH;
	}



	if (velY >= 14.60 && velY < 15.39)
	{
		isJumping = false;
		velY = 15;

	}
	//Terminal velocity. Velocity can only get up to 15
	if (velY > 15)
	{
		velY = 15;
	}

	posY += velY;
	if (isJumping)
	{
		velY = velY - gravity;
	}


	if (posY < 0)
	{
		posY = 0;
	}

	if (posY > 360 - SKELETON_HEIGHT)
	{
		posY = 360 - SKELETON_HEIGHT;
	}



	jump();

}


void Skeleton::jump()
{
	if (isJumping == true)
	{

		velY = -velY;

	}


}

double Skeleton::getposX()
{
	return posX;
}

double Skeleton::getposY()
{
	return posY;
}


void Skeleton::render(double x, double y)
{

	skeletonTextureRight.render(x, y);

}