#ifndef _BBLOCK_
#define _BBLOCK_
//#include "Game_refs.h"

class BBlock {
public:
				BBlock			( float x_, float y_ );
	void		Render			();
	void		Update			();
	b2Body*		GetBody			();
	void		SetTexture		( GLuint texture_ );
	GLdouble*	color;
protected:
	b2Body*		body;
	GLuint		texture;
};

#endif _BBLOCK_