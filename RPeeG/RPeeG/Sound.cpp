#include "Sound.h"

Sound sound;

Sound::Sound()
{




}

void Sound::playMusic(Mix_Music *song)
{
	//If no Music is playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(goneFishing, -1);
	}
	else
	{
		//If music is paused
		if (Mix_PausedMusic() == 1)
		{
			//Resume the music
			Mix_ResumeMusic();
		}


	}
	

}

void Sound::stopMusic()
{

	Mix_HaltMusic();

}