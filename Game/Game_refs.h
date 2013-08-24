#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <Box2D.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

#include "Game_animation.h"
#include "BBlock.h"
#include "Player.h"

typedef unsigned int Uint;

extern			bool			quit;
extern const	Uint			SCREEN_WIDTH;
extern const	Uint			SCREEN_HEIGHT;
extern const	int				SCREEN_BPP;
extern			SDL_Surface*	screen;
extern			int				FLAGS;
extern			float			dt;

// init funcs
extern			bool			initGL			();
extern			bool			init			();
extern			void			loadData		();
extern			void			loadMap			( char * fileName );

// loop funcs
extern			void			pollEvent		();
extern			void			render			();
extern			void			update			();
extern			bool			keyPressed		( SDLKey key );
extern			bool			keyUp			( SDLKey key );
extern			bool			keyDown			( SDLKey key );

// graphics
extern			GLuint			loadTexture		(char * file, GLint glFormat = GL_RGBA, 
												GLint filter = GL_LINEAR, GLint wrapping = GL_CLAMP );
extern			void			draw			(GLuint texture,  float x, float y, 
												float w, float h, float r = 0.0f, 
												float dx = 0.0f,  float dy = 0.0f );

extern			BAnimation*		playerStand;
extern			GLuint			blockTexture;
extern			GLuint			manTexture;


extern			float			CAMERA_SHIFT_X;
extern			float			CAMERA_SHIFT_Y;


// physics

extern			b2Vec2			gravity;
extern			b2World*		world;

extern			Player*			player;
extern			std::vector < BBlock* > blocks;

extern	const	float			BLOCK_SIZE;

// Pixels to Metrs
extern			float			ptom			( float pixels );
// Metrs to Pixels
extern			float			mtop			( float metrs  ); 
