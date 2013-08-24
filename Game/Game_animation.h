#ifndef _ANIMATION_
#define _ANIMATION_

typedef unsigned int Uint;

typedef float BRadians;
typedef float BDegrees;

class BAnimation {
public:
			BAnimation		( float width_, float height_, float delay_ );
	void	AddFrame		( GLuint texture );
	void	Update			( float dt );
	void	Render			( float x, float y, float w, float h,
							  BRadians r = 0);
	void	Render			( float x, float y );
	void	SetCenter		( float dx_, float dy_ );
	void	SetDelay		( float delay_ );
	Uint	getFrameNumber	();
protected:
	std::vector < GLuint > frames;
	float	width, height;
	float	time,  delay;
	float	dx, dy;
	Uint	frameNumber;
};

#endif