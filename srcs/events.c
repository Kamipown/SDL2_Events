#include "defs.h"

void	manage_events(SDL_Event *event, t_inputs *inputs)
{
	while (SDL_PollEvent(event))
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
			inputs->run = 0;
	}
}