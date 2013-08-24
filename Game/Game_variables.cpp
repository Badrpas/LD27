#include "Game_refs.h"
	
	bool			quit = false;
	const	Uint	SCREEN_WIDTH	= 800;
	const	Uint	SCREEN_HEIGHT	= 600;
	const	int		SCREEN_BPP		= 32;
	const	float	BLOCK_SIZE		= 64.0f;
	SDL_Surface*	screen;
	int		FLAGS = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL;
	float	dt;

	// gameplay vars

	std::vector < BBlock* > blocks;

