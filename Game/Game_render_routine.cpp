#define _CRT_SECURE_NO_WARNINGS
#include "Game_refs.h"

float CAMERA_SHIFT_X = 0;
float CAMERA_SHIFT_Y = 0;

void draw(	GLuint texture, 
			float x, float y, 
			float w, float h, 
			float r, 
			float dx,float dy ) {
	glBindTexture	( GL_TEXTURE_2D, texture );
	GLfloat _z = 0.0f;
	glPushMatrix	();
	glTranslatef	( x, y, 0);
	glRotatef		( r/M_PI*180.0, 0, 0, 1 );
	glTranslatef	(-x,-y, 0);
    glBegin			( GL_QUADS );
		glTexCoord2f(0   ,0   );	glVertex3f( (- CAMERA_SHIFT_X + x - dx)	* SCALE_IMAGE	,  (CAMERA_SHIFT_Y + y - dy	)* SCALE_IMAGE	, _z);
		glTexCoord2f(1.0f,0   );	glVertex3f( (- CAMERA_SHIFT_X + x - dx + w)* SCALE_IMAGE	,  (CAMERA_SHIFT_Y + y - dy	)* SCALE_IMAGE	, _z);
		glTexCoord2f(1.0f,1.0f);	glVertex3f( (- CAMERA_SHIFT_X + x - dx + w)* SCALE_IMAGE	,  (CAMERA_SHIFT_Y + y - dy + h)* SCALE_IMAGE	, _z);
		glTexCoord2f(0,   1.0f);	glVertex3f( (- CAMERA_SHIFT_X + x - dx)* SCALE_IMAGE		,  (CAMERA_SHIFT_Y + y - dy + h)* SCALE_IMAGE	, _z);
    glEnd();
	glPopMatrix();
}



SDL_Surface *load_image( char * filename ) {
    SDL_Surface* loadedImage	= NULL;
    SDL_Surface* optimizedImage	= NULL;
	loadedImage = IMG_Load( filename );
	return loadedImage;
}
GLuint convToGLTex (SDL_Surface * surface, 
					GLuint &result,
					GLint glFormat = GL_RGBA, 
					GLint filter   = GL_LINEAR, 
					GLint wrapping = GL_CLAMP) {
	glGenTextures ( 1, &result );
	glBindTexture ( GL_TEXTURE_2D, result );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapping );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapping );
	glTexImage2D (
			GL_TEXTURE_2D, 
			0, glFormat, 
			surface->w, surface->h, 
			0, glFormat, 
			GL_UNSIGNED_BYTE, 
			surface->pixels );
	return result;
}

GLuint loadTexture (char * file,
					GLint glFormat , 
					GLint filter   , 
					GLint wrapping ) {
	GLuint texture = 0;
	SDL_Surface *surface;
	surface = load_image ( file );
	glGenTextures ( 1, &texture );
	glBindTexture ( GL_TEXTURE_2D, texture );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapping );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapping );
	glTexImage2D (
			GL_TEXTURE_2D, 
			0, glFormat, 
			surface->w, surface->h, 
			0, glFormat, 
			GL_UNSIGNED_BYTE, 
			surface->pixels );

	return texture;
}