#include "Game_refs.h"



int main ( int argc, char * argv[] ) {
	Uint32 time = SDL_GetTicks();
	init();
	loadData();

	while ( !quit ) {
		Uint32 timePre = time;
		Uint32 time = SDL_GetTicks();
		dt = ( time - timePre ) / 1000.0f;
		pollEvent();
		update();
		render();
	}

	return 0x127;
}
