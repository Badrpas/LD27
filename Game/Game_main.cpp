#include "Game_refs.h"



int main ( int argc, char * argv[] ) {
	Uint32 time = SDL_GetTicks();
	init();
	loadData();

	while ( !quit ) {
		Uint32 timePre = time;
		time = SDL_GetTicks();
		dt = ((double)( time - timePre )) / 1000.0;
		pollEvent();
		update();
		render();
	}

	return 0x127;
}
