#include "Player.h"


Player::Player(int x, int y)
{




}

bool Player::checkPlayerCollision(SDL_Rect player, SDL_Rect object)
{


	return true;
}

void Player::inputHandler(SDL_Event event)
{
	double mouseX = 0;
	double mouseY = 0;

	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_a)
		{
			velX -= PLAYER_VELOCITY;
		}

		if (event.key.keysym.sym == SDLK_d)
		{
			velX += PLAYER_VELOCITY;
		}

		if (event.key.keysym.sym == SDLK_SPACE)
		{
			velY = -velY;
			
		}

		//Whatever the attack class/function whateverthefuck is gonna be
		if (event.button.button == SDL_BUTTON_LEFT)
		{

			//Attack function

		}

	}

	if (event.type == SDL_KEYUP)
	{

		if (event.key.keysym.sym == SDLK_a)
		{
			velX += PLAYER_VELOCITY;
		}
		if (event.key.keysym.sym == SDLK_d)
		{
			velX -= PLAYER_VELOCITY;
		}
		if (event.key.keysym.sym == SDLK_SPACE)
		{
			velY = velY;
		}



	}




}

void Player::render()
{

	playerTexture.render(posX, posY);

}

void Player::move()
{
	posX += velX;
	

	if (posX < 0)
	{
		posX = 0;
	}

	if (posX > 640 - PLAYER_WIDTH)
	{
		posX = 640 - PLAYER_WIDTH;
	}


	posY += velY;

	if (posY < 0)
	{
		posY = 0;
	}

	if (posY > 480 - PLAYER_HEIGHT)
	{
		posY = 480 - PLAYER_HEIGHT;
	}

}