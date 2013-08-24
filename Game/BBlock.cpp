#include "Game_refs.h"

BBlock::BBlock ( float x_, float y_ ) {	
	float halfWidth  = ptom ( BLOCK_SIZE / 2.0f );
	float halfHeight = ptom ( BLOCK_SIZE / 2.0f );
	
	b2BodyDef		_bodyDef;
	b2PolygonShape	_bodyShape;
	b2FixtureDef	_bodyFixture;

	_bodyDef.angle			= 0;
	_bodyDef.userData		= NULL;
	_bodyDef.position.Set	( x_ / 100.0f, (SCREEN_HEIGHT - y_) / 100.0f );
	_bodyShape.SetAsBox		( halfWidth, halfHeight );
	
	body = world->CreateBody( &_bodyDef );
	_bodyFixture.shape		= &_bodyShape;
	_bodyFixture.density	= 1.0f;
	_bodyFixture.friction	= 0.0f;
	_bodyFixture.restitution= 0.0f;
	body->CreateFixture( &_bodyFixture );

	blocks.push_back( this );
}

void BBlock::Update() {
}

void BBlock::Render() {
	draw ( blockTexture,mtop( body->GetPosition().x ), 
			SCREEN_HEIGHT - mtop( body->GetPosition().y ), 
			BLOCK_SIZE,	BLOCK_SIZE, 0.0f, 
			(BLOCK_SIZE / 2 ), BLOCK_SIZE / 2 );
}

b2Body*	BBlock::GetBody () {
	return body;
}
