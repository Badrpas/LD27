#include "Game_refs.h"



int main ( int argc, char * argv[] ) {
	Uint32 time = SDL_GetTicks();
	init();
	loadData();
	long long iterator = 0;

	while ( !quit ) {
		printf( "\tLoop start {\n " );
		Uint32 timePre = time;
		time = SDL_GetTicks();
		long dtl = ( time - timePre );
		dt = ( (double) dtl ) / 1000.0;
		if ( dt < 1.0/58.0 ) {
			SDL_Delay( (Uint32)(((1.0/58.0)- dt)*1000) );
			dt = 1.0/58.0;
		}
		printf( "\tEvents\n " );
		pollEvent();
		printf( "\tUpdate\n " );
		update();
		printf( "\tRender\n " );
		render();
		printf( "%i\t} Loop end\n ", iterator++ );
		
	}

	return 0x127;
}
