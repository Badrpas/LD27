#include "Game_refs.h"


void render(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for ( Uint i = 0; i < blocks.size(); i++ )
		blocks[i]->Render();	
    SDL_GL_SwapBuffers();
}

