#ifndef ANIMATIONCLIPS_H
#define ANIMATIONCLIPS_H

#include "TextureManager.h"


class AnimationClips
{

private:






public:

	AnimationClips();
	void playerLeftRunningClips();
	void playerRightRunningClips();
	void playerStandStillLeftClips();
	void playerStandStillRightClips();
	void setClips(int numFrames, SDL_Rect* clipRect, int index);



};

extern AnimationClips animationClips;

#endif