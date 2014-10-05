#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>


#ifndef PLAYER_H
#define PLAYER_H

#include "TextureManager.h"
#include "CWorld.h"

class Player
{
private:
	double posX;
	double posY;

	int direction;

	double velX;
	double velY;

	const int LEFT = -1;
	const int RIGHT = 1;

public:
	const double PLAYER_VELOCITY = 5;
	const int PLAYER_HEIGHT = 144;
	const int PLAYER_WIDTH = 150;
	double gravity = -0.66;

	//Camera Rect, relative to player in middle of the screen

	bool left = true;
	bool right = false;
	
	bool isJumping = false;
	bool CanDoSecondJump = false;
	int jumping = 0;

	SDL_Rect playerCam;

	
	void inputHandler(SDL_Event event);
	void move();
	void attack(); //will take direction and posx/posy
	void pickUp(); //takes direction
	void jump();
	void render(int frame);
	double getposX();
	double getposY();
	double getvelY(double distanceInit, double distanceFinal, double initVelY);
	Player(int x , int y);

	void checkCollision(SDL_Rect player, SDL_Rect square);
};



#endif