#include "Player.h"

Player::Player(int x, int y)
{




}

bool Player::checkPlayerCollision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh)
{



}

void Player::inputHandler(SDL_Event event)
{
	double mouseX = 0;
	double mouseY = 0;

	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_a)
		{
			velX -= 10;
		}

		if (event.key.keysym.sym == SDLK_d)
		{
			velX += 10;
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




}