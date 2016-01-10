#include <stdlib.h>
#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

typedef struct	s_inputs
{
	int		run;
}				t_inputs;

static void			initialization(Uint32 flags)
{
	SDL_SetMainReady();
	if (SDL_Init(flags) != 0)
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

static SDL_Window	*new_window(const char *title, int x, int y, Uint32 flags)
{
	SDL_Window	*window;

	if ((window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, flags)) == NULL)
	{
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	return (window);
}

static void			manage_events(SDL_Event *event, t_inputs *inputs)
{
		while (SDL_PollEvent(event))
		{
			if (event->key.keysym.sym == SDLK_ESCAPE)
				inputs->run = 0;
		}
}

int					main(int argc, char *argv[])
{
	SDL_Window	*window;
	SDL_Event	event;
	t_inputs	inputs;

	initialization(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (argc == 3)
		window = new_window("Yo", atoi(argv[1]), atoi(argv[2]), 0);
	else
	{
		window = new_window("Yo", 800, 600, 0);
		printf("You can use ./SDL_2_Windows 'width' 'height'\n");
	}
	inputs.run = 1;
	while (inputs.run)
	{
		manage_events(&event, &inputs);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}