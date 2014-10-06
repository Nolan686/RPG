#ifndef SOUND_H
#define SOUND_H
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>




class Sound
{


private:



public:


	Mix_Music *goneFishing = NULL;
	Sound();

	void playMusic(Mix_Music *song);
	void stopMusic();



};

extern Sound sound;

#endif