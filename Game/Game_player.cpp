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
	_bodyDef.position.Set( ptom( x ), ptom ( SCREEN_HEIGHT - y ) );
	_bodyDef.linearDamping = 0.0f;		// Торможение
	//_bodyDef.angularDamping= b2_maxFloat;
	body = world->CreateBody( &_bodyDef );
	body->SetBullet(true);
	
	_circleShape.m_p.Set			( 0, -ptom ( BLOCK_SIZE / 2.0f ) );
	_circleShape.m_radius = ptom	( BLOCK_SIZE / 2.0f - 5.0f );
	_circleShape2.m_p.Set			( 0,  ptom ( BLOCK_SIZE / 2.0f ) );
	_circleShape2.m_radius = ptom	( BLOCK_SIZE / 2.0f - 5.0f );
	_bodyFixture.shape			= &_circleShape;
	_bodyFixture.density		= 1.0f;
	_bodyFixture.friction		= 0.0f;
	_bodyFixture.restitution	= 0.0f;	
    body->CreateFixture(&_bodyFixture);
	_bodyFixture.shape			= &_circleShape2;
	_bodyFixture.density		= 1.0f;
	_bodyFixture.friction		= 0.0f;
	_bodyFixture.restitution	= 0.0f;
    body->CreateFixture(&_bodyFixture);

	body->SetFixedRotation(true);
	
	printf("%.6f %.6f\n", body->GetMass(), body->GetForce().y);
}

void Player::Update() {
	float32 mod = 0;
	b2Vec2 vel = body->GetLinearVelocity();
    float desiredVel = 0;

	if ( keyPressed(SDLK_LEFT ) ) desiredVel = -5;
	if ( keyPressed(SDLK_RIGHT) ) desiredVel =  5; 
    if ( keyPressed(SDLK_RIGHT) && keyPressed(SDLK_LEFT ) )  desiredVel =  0;



    float velChange = desiredVel - vel.x;
    float force = body->GetMass() * velChange / (dt); //f = mv/t

    body->ApplyForce( b2Vec2(force,0), body->GetWorldCenter() );



	CAMERA_SHIFT_X = mtop(body->GetPosition().x) - 128.0f;
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