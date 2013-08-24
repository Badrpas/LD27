#include "Game_refs.h"

void considerKeys();




void update(){
	considerKeys();
	world->Step(dt, 6, 2);
	for ( Uint i = 0; i < blocks.size(); i++ )
		blocks[i]->Update();
	player->Update();
}







void considerKeys(){
	if ( keyPressed( SDLK_d ) )
		CAMERA_SHIFT_X += 10.0f * dt;
	if ( keyPressed( SDLK_a ) )
		CAMERA_SHIFT_X -= 10.0f * dt;
	if ( keyPressed( SDLK_ESCAPE ) )
		quit = true;
}