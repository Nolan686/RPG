#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

SDL_Event event;
int main(int argc, char *argv[])
{
	bool quit = false;



	while (quit == false)
	{

		while (SDL_PollEvent(&event))
		{

			//Call Player handling shit


			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}







	}




	return 0;
}