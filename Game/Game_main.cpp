#include "Game_refs.h"



int main ( int argc, char * argv[] ) {
	Uint32 time = SDL_GetTicks();
	init();
	loadData();

	while ( !quit ) {
		Uint32 timePre = time;
		time = SDL_GetTicks();
		dt = ((float)( time - timePre )) / 1000.0f;
		printf( "%5.4f %i\n", dt, time - timePre );
		pollEvent();
		update();
		render();
	}

	return 0x127;
}
