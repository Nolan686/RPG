#include "Player.h"


Player::Player(int x, int y)
{
	posX = x;
	posY = y;

	velX = 0;
	velY = 25 ;

	playerCam = { 0, 0, application.SCREEN_WIDTH, application.SCREEN_HEIGHT };

	//Set frame for right
	frameRight = 594;
	//Set frame for left
	frameLeft = 0;
	frameStandStillLeft = 0;
	frameStandStillRight = 0;
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
			//Is moving left
			left = true;
			//If not moving right currently, A was the first key to be pressed in the case that D gets pressed while holding this down
			if (right == false)
			{
				firstLeft = true;
			}
			
			break;

		case SDLK_d:
			velX += PLAYER_VELOCITY;
			//Is moving right
			right = true;
			//If not moving left currently, D was the first key to be pressed in the case that A gets pressed while holding this down
			if (left == false)
			{
				firstRight = true;
			}
			
			
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
			//Stopped moving left
			left = false;
			//If not holding down the D key and A is let go, the last direction you were facing is left
			if (right == false)
			{
				lastLeft = true;
			}
			if (right == false && firstLeft == true)
			{
				firstLeft = false;
			}
			
			
			break;
		case SDLK_d:
			velX -= PLAYER_VELOCITY;
			//Stopped moving right
			right = false;
			//If not holding down the A key and D is let go, the last direction you were facing is right
			if (left == false)
			{
				lastRight = true;
			}
			
			if (left == false && firstRight == true)
			{
				firstRight = false; 
			}
			
			
			
			break;
		case SDLK_SPACE: 
			
			break;
		}
	}




}

void Player::animationLogic()
{
	if ((frameRight / 27) >= playerSpriteSheet.WALKING_ANIMATION_FRAMES - 1)
	{
		frameRight = 0;
	}
	//Increase or decrease speed of animation here
	if (getRight())
	{
		frameRight += 16;
	}
	//Set starting animation clip. divide by 27 to get current clip
	if (getRight() == false)
	{
		frameRight = 594;
	}
	//Same as above one but for running left
	if ((frameLeft / 27) >= playerSpriteSheet.WALKING_ANIMATION_FRAMES - 1)
	{
		frameLeft = 0;
	}

	if (getLeft())
	{
		frameLeft += 16;
	}
	if (getLeft() == false)
	{
		frameLeft = 0;
	}

	if ((frameStandStillRight / 22) >= playerSpriteSheet.WALKING_ANIMATION_FRAMES -6)
	{
		frameStandStillRight = 0;
	}

	if (lastRight)
	{
		frameStandStillRight += 8;
	}
	if (lastRight == false)
	{
		frameStandStillRight = 0;
	}

	



}

void Player::move()
{
	

	
	//If both direction keys are pressed, quit moving until one of the two is released
	if (left && right)
	{
		velX = 0;
	}
	//Add velocity
	posX += velX;
	//Read out velocity
	
	
	//Keep player in bounds
	if (posX < 0)
	{
		posX = 0;
	}
	//Keep player in bounds
	if (posX > application.LEVEL_WIDTH - PLAYER_WIDTH)
	{
		posX = application.LEVEL_WIDTH - PLAYER_WIDTH;
	}


	//If y velocity is the same as the start of the jump, jumping is false, and set the velocity back to normal(need a new system that sets isJumping to false based on if there is collision on the bottom of the player)
	if (velY >= 24.60 && velY < 25.39) 
	{
		isJumping = false;
		velY = 25;
		
	}
	
	//Apply y velocity
	posY += velY;
	//While jumping apply gravity
	if (isJumping)
	{
		velY = velY - gravity;
	}
	
	//If hit ceiling, stop, and set whatever y velocity you had to 0
	if (posY < 0)
	{
		posY = 0;
		velY = 0;
	}
	//Floor boundaries
	if (posY > application.LEVEL_HEIGHT - 240 - PLAYER_HEIGHT)
	{
		posY = application.LEVEL_HEIGHT - 240 - PLAYER_HEIGHT;
	}
	//Set camera offsets
	playerCam.x = (getposX() + PLAYER_WIDTH / 2) - (application.SCREEN_WIDTH / 2);
	playerCam.y = (getposY() + PLAYER_HEIGHT / 2) - (application.SCREEN_HEIGHT / 2);
	//Keep camera in bounds
	if (playerCam.x < 0)
	{
		playerCam.x = 0;
	}
	//Keep camera in bounds
	if (playerCam.y < 0)
	{
		playerCam.y = 0;
	}
	//Keep camera in bounds
	if (playerCam.x > application.LEVEL_WIDTH - playerCam.w)
	{
		playerCam.x = application.LEVEL_WIDTH - playerCam.w;
	}
	//Keep camera in bounds
	if (playerCam.y > application.LEVEL_HEIGHT - playerCam.h)
	{
		playerCam.y = application.LEVEL_HEIGHT - playerCam.h;
	}

	if (posY > 380 & posX < 550)
	{
		posY = 380;
	}

	//Camera moving

}


double Player::getvelY(double distanceInit, double distanceFinal, double initVelY)
{
	double finalVelY;
	//Need the pixel position when the jump starts and the pixel position for the distance wanting to calculate velY for (vf^2) = ((vi^2) + ((2)(a)(d))


	finalVelY = sqrt((pow(initVelY, 2)) + ((2)*(gravity * (distanceFinal - distanceInit))));


	return finalVelY;

}


void Player::render()
{

	
	animationLogic();

	

	//Render player in relation to the camera (in the middle of the camera always, except right now because the screen is so small and the world is poop)
	SDL_Rect* currentClipRight = &playerSpriteSheet.playerSpriteClips[frameRight/27];
	SDL_Rect* currentClipLeft = &playerSpriteSheetLeft.playerLeftSpriteClips[frameLeft / 27];
	SDL_Rect* currentClipStandStillRight = &playerStandStillRight.playerStandStillRightClips[frameStandStillRight / 22];

	//If moving right and the left key isnt press, play the running rightwards anmiation
	if (right && left == false)
	{
		playerSpriteSheet.renderAnimation(getposX() - playerCam.x, getposY() - playerCam.y, currentClipRight);
		lastLeft = false;
		lastRight = false;
	}
	// if moving left and the right key isnt pressed, play the running leftwards animation
	if (left && right == false)
	{
		playerSpriteSheetLeft.renderAnimation(getposX() - playerCam.x, getposY() - playerCam.y, currentClipLeft);
		lastRight = false;
		lastLeft = false;
	}
	
	//If the last movement was moving right, set the standing still image to the rightward facing one
	if (lastRight)
	{
		playerStandStillRight.renderAnimation(getposX() - playerCam.x, getposY() - playerCam.y +5, currentClipStandStillRight);
		
	}
	//If the last movement was moving left, set the standing still image to the leftward facing one
	if (lastLeft)
	{
		playerTextureLeft.render(getposX() - playerCam.x, getposY() - playerCam.y + 5);
		
	}
	//If not moving at all and no key has been pressed yet (right when the game starts), start the character out facing right
	//If both keys are held down and the right key was pressed first, keep the character facing right
	if (left == true && right == true && firstRight == true)
	{
		playerStandStillRight.renderAnimation(getposX() - playerCam.x, getposY() - playerCam.y + 5, currentClipStandStillRight);
	}
	//If both keys are held down adn the left key was pressed first, keep the character facing left
	if (left == true && right == true && firstLeft == true)
	{
		playerTextureLeft.render(getposX() - playerCam.x, getposY() - playerCam.y + 5);
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



bool Player::getLeft()
{
	return left;
}

bool Player::getRight()
{
	return right;
}