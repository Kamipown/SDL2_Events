#include "defs.h"

SDL_Window	*new_window(int x, int y, int argc, char *argv[])
{
	SDL_Window	*window;

	if (argc == 3)
		window = SDL_CreateWindow("Yo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, atoi(argv[1]), atoi(argv[2]), 0);
	else
	{
		window = SDL_CreateWindow("Yo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, 0);
		printf("You can use ./SDL_2_Windows 'width' 'height'\n");
	}
	if (window == NULL)
	{
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	return (window);
}