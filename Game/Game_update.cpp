#include "Game_refs.h"

void considerKeys();




void update(){
	considerKeys();
	world->Step(dt, 10, 8);
	timeLeft -= dt;
	for ( Uint i = 0; i < blocks.size(); i++ )
		blocks[i]->Update();
	player->Update();
	for ( Uint i = 0; i < points.size(); i++ )
		points[i]->Update();
	if ( NEED_LOAD_NEXT_MAP ) {
		loadNextMap();
		NEED_LOAD_NEXT_MAP = false;
	}
}

void considerKeys(){
	if ( keyPressed( SDLK_ESCAPE ) )
		quit = true;
}