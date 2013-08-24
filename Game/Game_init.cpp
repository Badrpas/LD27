#define _CRT_SECURE_NO_WARNINGS
#include "Game_refs.h"


bool initGL() {
	glClearColor	( (128.0f / 255.0f), 1.0f, 1.0f, 1.0f );
	glEnable		( GL_DEPTH_TEST );
	glDepthMask		( GL_TRUE );
	glDepthFunc		( GL_LEQUAL );
	glDepthRange	( 1.0f, -1.0f );
	glClearDepth	( 1.0f );
	glViewport		( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );
	glMatrixMode	( GL_PROJECTION );
	glLoadIdentity	();
	glOrtho			( 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1.0, -1.0 );
	glMatrixMode	( GL_MODELVIEW );
	glLoadIdentity	();
	glEnable		( GL_TEXTURE_2D );
	glEnable		( GL_BLEND );								// Here is magic
	glBlendFunc		( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );	// for alpha-blending
	FILE * file; 
	file = fopen( "opengl.log", "w" );
    GLenum error = glGetError();
    if ( error != GL_NO_ERROR ) {
        fprintf( file, "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    } else {
        fprintf( file, "All ok.\n" );
	}
	fclose( file );
    return true;
}


bool init() {
	printf ( "Hello\n" );
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
        return false;    
    }
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,        8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,      8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,       8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,      8);
 
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,      16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,		32);
 
	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,  8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,   8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,  8);
 
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    screen = SDL_SetVideoMode( 
		SCREEN_WIDTH, SCREEN_HEIGHT, 
		SCREEN_BPP, FLAGS );
	initGL();
	
	printf( "Vendor: %s\n",		glGetString( GL_VENDOR ) );
	printf( "Renderer: %s\n",	glGetString( GL_RENDERER ) );
	printf( "GL version: %s\n", glGetString( GL_VERSION ) );
	printf( "SL version: %s\n", glGetString( GL_SHADING_LANGUAGE_VERSION ) );

    if( screen == NULL ) {
        return false;
    }
	SDL_WM_SetCaption( "LD 27 Compo", NULL );
    return true;
}

