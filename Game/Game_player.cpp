#include "Game_refs.h"

Player::Player( float x, float y ) {
	state = STAND;
	speed = 200.5f;
	
	b2BodyDef		_bodyDef;
	b2PolygonShape	_bodyShape;
	b2CircleShape	_circleShape, 
					_circleShape2;
	b2FixtureDef	_bodyFixture;

	_bodyDef.type = b2_dynamicBody;		// Объект, ска, динамичен!
	_bodyDef.position.Set( ptom(x), ptom( SCREEN_HEIGHT - y) );
	_bodyDef.linearDamping = 0.0f;		// Торможение
	//_bodyDef.angularDamping= b2_maxFloat;
	body = world->CreateBody(&_bodyDef);
	body->SetBullet(true);
	
	_circleShape.m_p.Set ( 0, -ptom ( BLOCK_SIZE / 2.0f ) );
	_circleShape.m_radius = ptom ( BLOCK_SIZE / 2.0f - 10.0f );
	_circleShape2.m_p.Set ( 0, ptom ( BLOCK_SIZE / 2.0f ) );
	_circleShape2.m_radius = ptom ( BLOCK_SIZE / 2.0f - 10.0f );

	_bodyShape.SetAsBox			( ptom(BLOCK_SIZE/2.0f), ptom(BLOCK_SIZE) );
	_bodyFixture.shape			= &_circleShape;
	_bodyFixture.density		= 1.0f;
	_bodyFixture.friction		= 0.0f;
	_bodyFixture.restitution	= 0.0f;

    body->CreateFixture(&_bodyFixture);
	body->SetFixedRotation(true);
	
	printf("%.6f %.6f\n", body->GetMass(), body->GetForce().y);
}

void Player::Update() {
	float32 mod = 0;
	b2Vec2  vel = body->GetLinearVelocity();
	vel.x = 0;
	
	if ( keyUp(SDLK_RIGHT) || keyUp(SDLK_LEFT)  ) {
		body->SetLinearVelocity	( vel );
		//body->SetForce			( b2Vec2(0,0) );
	}
	if ( keyPressed(SDLK_RIGHT) ) {
		vel.x = ptom( speed );
	}
	if ( keyPressed(SDLK_LEFT ) ) {
		vel.x = -ptom( speed );
	}
	if ( keyDown(SDLK_UP   ) ) {
		body->ApplyForceToCenter( b2Vec2( 0, ptom(speed*20.0f) ) );
	}
	if ( keyPressed(SDLK_DOWN ) ) {
	}
	if ( keyPressed(SDLK_RIGHT) || keyPressed(SDLK_LEFT) ||
		 keyPressed(SDLK_UP)    || keyPressed(SDLK_DOWN) ) {
		body->SetLinearVelocity	( vel );
	}

	CAMERA_SHIFT_X = mtop(body->GetPosition().x) - 128.0f;
	//body->ApplyForceToCenter(vel);
	//printf ( "%5.3f %8.6f %8.6f %8.6f\n", dt, body->GetForce().x, body->GetForce().y, body->GetLinearVelocity().x );
}

b2Body*	Player::GetBody() {
	return body;
}

void Player::Render() {
	draw ( manTexture,  mtop( body->GetPosition().x ), 
		SCREEN_HEIGHT - mtop( body->GetPosition().y ), 
		BLOCK_SIZE,	BLOCK_SIZE*2, body->GetAngle(), 
		(BLOCK_SIZE / 2.0f ), BLOCK_SIZE);
}

b2Vec2 Player::GetPos() {
	pos = body->GetPosition();
	return pos;
}