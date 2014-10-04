#include "Player.h"


Player::Player(int x, int y)
{
	posX = x;
	posY = y;

	velX = 0;
	velY = 14;

}

bool Player::checkPlayerCollision(SDL_Rect player, SDL_Rect object)
{


	return true;
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
			break;

		case SDLK_d:
			velX += PLAYER_VELOCITY;
			break;

		case SDLK_SPACE:
			if (isJumping == false)
			{
				velY = -velY;
				isJumping = true;
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
			
			break;
		case SDLK_SPACE: 
			
			break;
		}
	}




}

void Player::render()
{

	if (posX < 640)
	{
		playerTexture.render(posX, posY);
	}

	if (posX > 640)
	{
		playerTexture.render(posX - 640, posY);
	}

	if (posX > 1280)
	{
		playerTexture.render(posX - 1280, posY);
	}

	if (posX > 1920)
	{
		playerTexture.render(posX - 1920, posY);
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


	
	if (velY >= 13.60 && velY < 14.39) 
	{
		isJumping = false;
		velY = 14;
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

	if (posY > 480 - PLAYER_HEIGHT)
	{
		posY = 480 - PLAYER_HEIGHT;
	}

}

double Player::getposX()
{
	return posX;
}