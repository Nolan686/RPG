#include "Player.h"


Player::Player(int x, int y)
{
	posX = x;
	posY = y;

	velX = 0;
	velY = 15 ;

	playerCam = { 0, 0, application.SCREEN_WIDTH, application.SCREEN_HEIGHT };
}



void Player::inputHandler(SDL_Event event)
{
	double mouseX = 0;
	double mouseY = 0;
	

	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			velX -= PLAYER_VELOCITY;
			left = true;
			right = false;
			break;

		case SDLK_d:
			velX += PLAYER_VELOCITY;
			right = true;
			left = false;
			break;

		case SDLK_SPACE:
			if (isJumping == false || CanDoSecondJump == true)
			{
				
				velY = -velY;
				isJumping = true;
				if (jumping == 1)
				{
					CanDoSecondJump == true;
				}
			}
			break;
		}
	}
	if (event.type == SDL_KEYUP && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			velX += PLAYER_VELOCITY;
			
			break;
		case SDLK_d:
			velX -= PLAYER_VELOCITY;
			right = false;
			
			break;
		case SDLK_SPACE: 
			jumping++;
			break;
		}
	}




}



void Player::move()
{


	posX += velX;

	std::cout << velX << ", " << velY << std::endl;
	

	if (posX < 0)
	{
		posX = 0;
	}

	if (posX > application.LEVEL_WIDTH - PLAYER_WIDTH)
	{
		posX = application.LEVEL_WIDTH - PLAYER_WIDTH;
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

	if (posY > 360 - PLAYER_HEIGHT)
	{
		posY = 360 - PLAYER_HEIGHT;
	}

	playerCam.x = (getposX() + PLAYER_WIDTH / 2) - (application.SCREEN_WIDTH / 2);
	playerCam.y = (getposY() + PLAYER_HEIGHT / 2) - (application.SCREEN_HEIGHT / 2);

	if (playerCam.x < 0)
	{
		playerCam.x = 0;
	}

	if (playerCam.y < 0)
	{
		playerCam.y = 0;
	}

	if (playerCam.x > application.LEVEL_WIDTH - playerCam.w)
	{
		playerCam.x = application.LEVEL_WIDTH - playerCam.w;
	}

	if (playerCam.y > application.LEVEL_HEIGHT - playerCam.h)
	{
		playerCam.y = application.LEVEL_HEIGHT - playerCam.h;
	}

	//Camera moving

}


double Player::getvelY(double distanceInit, double distanceFinal, double initVelY)
{
	double finalVelY;
	//Need the pixel position when the jump starts and the pixel position for the distance wanting to calculate velY for


	finalVelY = sqrt((pow(initVelY, 2)) + ((2)*(gravity * (distanceFinal - distanceInit))));


	return finalVelY;

}


void Player::render(int frame)
{
	//Render player in relation to the camera (in the middle of the camera always, except right now because the screen is so small and the world is poop)
	SDL_Rect* currentClip = &playerSpriteSheet.playerSpriteClips[frame/24];

	
	if (right)
	{
		playerSpriteSheet.renderShit(getposX() - playerCam.x, getposY() - playerCam.y, currentClip);
	}
	
	
	
}

double Player::getposX()
{
	return posX;
}

double Player::getposY()
{
	return posY;
}