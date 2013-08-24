#ifndef _BBLOCK_
#define _BBLOCK_
//#include "Game_refs.h"

class BBlock {
public:
				BBlock			( float x_, float y_ );
	void		Render			();
	void		Update			();
	b2Body*		GetBody			();
protected:
	b2Body*		body;
};

#endif _BBLOCK_