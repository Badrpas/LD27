#ifndef _PLAYER_
#define _PLAYER_

enum PlayerState { STAND = 0, RUN };

class Player {
public:
				Player			( float x, float y );
	b2Vec2		GetPos			();
	void		Render			();
	void		Update			();
	b2Body*		GetBody			();

protected:
	float32		speed;
	float32		height;
	PlayerState state;
	b2Vec2		pos;
	b2Body*		body;
	GLuint		texture;
	float32		circleRadius;
};


#endif