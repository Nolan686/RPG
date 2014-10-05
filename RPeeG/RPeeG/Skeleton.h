#ifndef SKELETON_H
#define SKELETON_H

#include "CApplication.h"
#include "TextureManager.h"


class Skeleton
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

	const double SKELETON_VELOCITY = 5;
	static const int SKELETON_HEIGHT = 90;
	static const int SKELETON_WIDTH = 80;
	double gravity = -0.66;
		
	bool left = true;
	bool right = false;

	bool isJumping = false;
	bool CanDoSecondJump = false;
	int jumping = 0;


	void move();
	double getposX();
	double getposY();
	void jump();
	void render(double x, double y);

	Skeleton(int x, int y);



};








#endif