#include "Game_refs.h"

BBlock::BBlock ( float x_, float y_ ) {	
	float halfWidth  = BLOCK_SIZE/2 / 100.0f;
	float halfHeight = BLOCK_SIZE/2 / 100.0f;

	b2BodyDef		_bodyDef;
	b2PolygonShape	_bodyShape;
	b2FixtureDef	_bodyFixture;

	_bodyDef.angle			= 0;
	_bodyDef.userData		= NULL;
	_bodyDef.position.Set	( x_ / 100.0f, (SCREEN_HEIGHT - y_) / 100.0f );
	_bodyShape.SetAsBox		( halfWidth, halfHeight );
	
	body = world->CreateBody( &_bodyDef );
	_bodyFixture.shape = &_bodyShape;
	_bodyFixture.density  = 1.0f;
	_bodyFixture.friction = 0.0f;
	_bodyFixture.restitution = 1.0f;
	body->CreateFixture( &_bodyFixture );

	blocks.push_back( this );
}

void BBlock::Render() {
	draw ( blockTexture, 
						body->GetPosition().x * 100.0f, 
		SCREEN_HEIGHT - body->GetPosition().y * 100.0f, 
		BLOCK_SIZE,	BLOCK_SIZE, 0.0f, 
		(BLOCK_SIZE / 2 ), BLOCK_SIZE / 2 );
	//printf( "%.3f %.3f\n", body->GetPosition().x * 100.0f, SCREEN_HEIGHT - body->GetPosition().y * 100.0f);
}

b2Body*	BBlock::GetBody () {
	return body;
}
