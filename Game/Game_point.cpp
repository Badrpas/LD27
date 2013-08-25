#include "Game_refs.h"

CPoint::CPoint( float32 x, float32 y, CPointType type_ ) {
	type = type_;

	switch (type) {
		case CONTROL_POINT			: texture = pointTextureFree;		break;
		case CONTROL_POINT_VISITED	: texture = pointTextureVisited;	break;
		case FINISH					: texture = pointTextureFinish;		break;
	}

	b2BodyDef		_bodyDef;
	b2PolygonShape	_bodyShape;
	b2FixtureDef	_bodyFixture;	
	_bodyDef.angle  = 0;
	_bodyDef.position.Set( ptom(x), ptom( SCREEN_HEIGHT - y ) );
	_bodyDef.userData = NULL;
	body = world->CreateBody(&_bodyDef);	
	_bodyShape.SetAsBox ( ptom ( BLOCK_SIZE_2 ), ptom ( BLOCK_SIZE_2 ) );
	_bodyFixture.shape = &_bodyShape;
	_bodyFixture.density = 0.0f;
	_bodyFixture.friction= 0.0f;
	_bodyFixture.restitution = 1.0f;
	_bodyFixture.isSensor = true;
	body->CreateFixture(&_bodyFixture);
	points.push_back( this );
	ObjectPointer *p;
	p = new ObjectPointer();
	p->pointer	= this;
	p->type		= O_POINT;
	body->SetUserData( p );
}

void CPoint::Update() {

}

void CPoint::Render() {
	glColor4d( 1.0, 1.0, 1.0, 1.0 );
	draw ( texture, mtop( body->GetPosition().x ), 
			SCREEN_HEIGHT - mtop( body->GetPosition().y ), 
			BLOCK_SIZE,	BLOCK_SIZE, 0.0f, 
			(BLOCK_SIZE / 2 ), BLOCK_SIZE / 2 );
}

void CPoint::SetActive() {
	type = CONTROL_POINT_VISITED;
	spawnPoint->SetUnActive();
	texture = pointTextureVisited;
	timeLeft = 10.0;
	spawnPoint = this;
}

void CPoint::SetUnActive() {
	type = CONTROL_POINT;
	texture = pointTextureFree;
}

b2Body* CPoint::GetBody() {
	return body;
}