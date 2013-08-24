#include "Game_refs.h"

BBlock::BBlock ( float x_, float y_ ) {
	
	float halfWidth  = BLOCK_SIZE/2;
	float halfHeight = BLOCK_SIZE/2;

	b2BodyDef		_bodyDef;
	b2PolygonShape	_bodyShape;
	b2FixtureDef	_bodyFixture;

	_bodyDef.angle  = 0;
	_bodyDef.position.Set(x_,y_);
	_bodyDef.userData = NULL;
	_bodyShape.SetAsBox(halfWidth, halfHeight);
	
	body = world->CreateBody(&_bodyDef);
	_bodyFixture.shape = &_bodyShape;
	_bodyFixture.density  = 1.0f;
	_bodyFixture.friction = 0.0f;
	_bodyFixture.restitution = 1.0f;
	body->CreateFixture(&_bodyFixture);

	blocks.push_back(this);
}

void BBlock::Render() {

}

b2Body*	BBlock::GetBody (){
	return body;
}
