#include "Game_refs.h"


void render(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for ( Uint i = 0; i < blocks.size(); i++ )
		blocks[i]->Render();
	for ( Uint i = 0; i < points.size(); i++ )
		points[i]->Render();
	player->Render();
	

	draw(0, 20.0, SCREEN_HEIGHT/2, 30, (SCREEN_HEIGHT - 40) * ( timeLeft / 10.0 ), 0, 15.0,
		SCREEN_HEIGHT/2);
	double l = ( SCREEN_WIDTH/2.0 - 20 ) * (timeLeft/10.0);
	glColor4d(1-(timeLeft/10.0), (timeLeft/10.0), 1.0, 1.0);
	glBegin	( GL_QUADS );
		glVertex2d( SCREEN_WIDTH/2.0 + l, SCREEN_HEIGHT - 20.0 );
		glVertex2d( SCREEN_WIDTH/2.0 - l, SCREEN_HEIGHT - 20.0 );
		glVertex2d( SCREEN_WIDTH/2.0 - l, SCREEN_HEIGHT - 40.0 );
		glVertex2d( SCREEN_WIDTH/2.0 + l, SCREEN_HEIGHT - 40.0 );
    glEnd();
	glColor4d(0.3, 0.5, 1.0, 1.0);
	glBegin	( GL_LINES );
		glVertex2d( SCREEN_WIDTH/2.0 + l, SCREEN_HEIGHT - 20.0 );
		glVertex2d( SCREEN_WIDTH/2.0 - l, SCREEN_HEIGHT - 20.0 );
		glVertex2d( SCREEN_WIDTH/2.0 - l, SCREEN_HEIGHT - 40.0 );
		glVertex2d( SCREEN_WIDTH/2.0 + l, SCREEN_HEIGHT - 40.0 );
    glEnd();
	glColor4d(1.0, 1.0, 1.0, 1.0);

    SDL_GL_SwapBuffers();
}

