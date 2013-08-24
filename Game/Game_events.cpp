#include "Game_refs.h"

const int KEY_COUNT = 400;

bool keyPressedArray[KEY_COUNT];
bool keyUpArray		[KEY_COUNT];
bool keyDownArray	[KEY_COUNT];

bool keyPressed ( SDLKey key ) {
	return keyPressedArray	[ (int)key ];
}
bool keyUp		( SDLKey key ) {
	return keyUpArray		[ (int)key ];
}
bool keyDown	( SDLKey key ) {
	return keyDownArray		[ (int)key ];
}


void pollEvent() {
	for ( Uint i = 0; i < KEY_COUNT; i++ ) {
		keyUpArray	[i] = false;
		keyDownArray[i] = false;
	}
	SDL_Event event;
	while ( SDL_PollEvent( &event ) ) {
		if ( event.type == SDL_QUIT ) {
            quit = true;
        } else if ( event.type == SDL_MOUSEMOTION ) {
		} else if ( event.type == SDL_MOUSEBUTTONDOWN ) {
		} else if ( event.type == SDL_KEYDOWN ) {
			SDLKey key = event.key.keysym.sym;
			keyPressedArray	[ (int)key ] = true;
			keyDownArray	[ (int)key ] = true;
		} else if ( event.type == SDL_KEYUP ) {
			SDLKey key = event.key.keysym.sym;
			keyPressedArray	[ (int)key ] = false;
			keyUpArray		[ (int)key ] = true;
		}
	}
}