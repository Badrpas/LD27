#include "Game_refs.h"


void pollEvent() {
	SDL_Event event;
	while ( SDL_PollEvent( &event ) ) {
		if ( event.type == SDL_QUIT ) {
            quit = true;
        } else if ( event.type == SDL_MOUSEMOTION ) {
		} else if ( event.type == SDL_MOUSEBUTTONDOWN ) {
		} else if ( event.type == SDL_KEYDOWN ) {
			SDLKey key = event.key.keysym.sym;
		} else if ( event.type == SDL_KEYUP ) {
			SDLKey key = event.key.keysym.sym;
		}
	}
}