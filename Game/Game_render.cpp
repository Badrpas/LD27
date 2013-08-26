#include "Game_refs.h"


void render(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLuint texture = 0;

	if ( strcmp( mapList[currentMap], "jumpToWin.lua" ) == 0 )
		texture = backgroundTexture[2];
	if ( strcmp( mapList[currentMap], "init.lua" ) == 0 )
		texture = backgroundTexture[1];
	if ( strcmp( mapList[currentMap], "restart.lua" ) == 0 )
		texture = backgroundTexture[3];
	if ( strcmp( mapList[currentMap], "maze.lua" ) == 0 )
		texture = backgroundTexture[4];

	if ( texture != 0 ) {		
		glBindTexture	( GL_TEXTURE_2D, texture );
		glColor4d(1.0, 1.0, 1.0, 1.0);
		glBegin	( GL_QUADS );
			glTexCoord2f(0   ,0   );
			glVertex2d( 0, 0 );
			glTexCoord2f(1.0f,0   );
			glVertex2d( SCREEN_WIDTH, 0 );
			glTexCoord2f(1.0f,1.0f);
			glVertex2d( SCREEN_WIDTH, SCREEN_HEIGHT );
			glTexCoord2f(0,   1.0f);
			glVertex2d( 0, SCREEN_HEIGHT );
		glEnd();
	}


	for ( Uint i = 0; i < blocks.size(); i++ )
		blocks[i]->Render();
	for ( Uint i = 0; i < points.size(); i++ )
		points[i]->Render();
	if (player)
		player->Render();
	

	draw(0, 20.0, SCREEN_HEIGHT/2, 0, 0, 0, 15.0,
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

