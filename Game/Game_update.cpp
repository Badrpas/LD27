#include "Game_refs.h"

void considerKeys();




void update(){
	considerKeys();
	world->Step(dt, 10, 8);
	timeLeft -= dt;
	for ( Uint i = 0; i < blocks.size(); i++ )
		blocks[i]->Update();
	player->Update();
}

void considerKeys(){
	if ( keyPressed( SDLK_ESCAPE ) )
		quit = true;
}