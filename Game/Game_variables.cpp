#include "Game_refs.h"
	
			bool	quit			= false;
	const	Uint	SCREEN_WIDTH	= 1024;
	const	Uint	SCREEN_HEIGHT	= 600;
	const	int		SCREEN_BPP		= 32;
	const	float32 SCALE_IMAGE		= 0.5;
	const	float32	BLOCK_SIZE		= 64.0;
	const	float32	BLOCK_SIZE_2	= BLOCK_SIZE / 2.0;
	const	float32 BLOCK_SIZE_DIAGONAL		= sqrt( BLOCK_SIZE*BLOCK_SIZE + BLOCK_SIZE*BLOCK_SIZE );
	const	float32 BLOCK_SIZE_DIAGONAL_2	= BLOCK_SIZE_DIAGONAL / 2.0;
	const	float32 BLOCK_SIZE_DIAGONAL_P2	= BLOCK_SIZE_DIAGONAL * BLOCK_SIZE_DIAGONAL;
	SDL_Surface*	screen;
	int		FLAGS = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL;
	float	dt;

	// gameplay vars

	Player*		player;
	std::vector < BBlock* > blocks;

	// graphics

	BAnimation*	playerStand;
	GLuint		blockTexture;
	GLuint		blockTextureAlt;
	GLuint		manTexture;
	GLuint		manTextureJump;