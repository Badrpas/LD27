#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <Box2D.h>

#include <vector>

#include "Game_animation.h"
#include "BBlock.h"

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
// loop funcs
extern			void			pollEvent		();
extern			void			render			();
extern			void			update			();

// graphics
extern			GLuint			loadTexture		(char * file, GLint glFormat, 
												GLint filter, GLint wrapping );
extern			void			draw			(GLuint texture,  float x, float y, 
												float w, float h, float r = 0.0f, 
												float dx = 0.0f,  float dy = 0.0f );

// physics

extern			b2Vec2	gravity;
extern			b2World * world;

extern			std::vector < BBlock* > blocks;

extern	const	float	BLOCK_SIZE;
