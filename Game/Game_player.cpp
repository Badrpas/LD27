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

	circleRadius = BLOCK_SIZE_2 - 5.0f;
	_circleShape.m_p.Set			( 0, -ptom ( BLOCK_SIZE_2 - 5.0f )  );
	_circleShape.m_radius  = ptom	( circleRadius );
	_circleShape2.m_p.Set			( 0,  ptom ( BLOCK_SIZE_2 )  );
	_circleShape2.m_radius = ptom	( circleRadius );

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

	height = 10000.0f;
	bool canJump = false;
	b2Vec2 ppos = GetPos(); // player pos
	printf("%8.5f %8.5f\n", ppos.x, ppos.y );
	for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()) {
		if ( ppos.y > f->GetBody()->GetPosition().y )	// Gtting center of
			 ppos =   f->GetBody()->GetPosition();		// lower circleShape
	}
	b2Vec2 pdpos = ppos; // player down pos (lower edge)
	pdpos.y -= ptom ( circleRadius );
	for ( b2ContactEdge* ce = body->GetContactList(); ce; ce = ce->next ) {
		b2Contact* c = ce->contact;
		BBlock* block =  ( BBlock* )( ce->other->GetUserData() );
		block->SetTexture( blockTextureAlt );
		b2Vec2 pos = block->GetBody()->GetPosition();
		if ( (  abs( pos.x - pdpos.x ) <= ptom( BLOCK_SIZE_DIAGONAL_2 ) )
			&& ( pdpos.y >=pos.y ) 
			&& ( pdpos.y - pos.y <= BLOCK_SIZE_DIAGONAL_2 )		) {
			height = body->GetPosition().y - pos.y;
			canJump = true;
		}
	}

	if (canJump)
		texture = manTexture;
	else
		texture = manTextureJump;

    body->ApplyForce ( b2Vec2(force,0), body->GetWorldCenter() );
	if ( keyDown ( SDLK_UP ) ) {
		if ( canJump ) {
			float32 jumpPower = ptom(speed);
			jumpPower *= body->GetMass() * 2.0 ;
			body->SetLinearVelocity ( b2Vec2(body->GetLinearVelocity().x, 0) );
			body->ApplyLinearImpulse( b2Vec2(0,jumpPower), body->GetWorldCenter() );
		}
	}
	

	
	CAMERA_SHIFT_X = mtop(body->GetPosition().x) - SCREEN_WIDTH / 2 / SCALE_IMAGE;

	CAMERA_SHIFT_Y = mtop(body->GetPosition().y) - SCREEN_HEIGHT/ 2 * SCALE_IMAGE;
}

b2Body*	Player::GetBody() {
	return body;
}

void Player::Render() {
	draw ( texture,  mtop( body->GetPosition().x ), 
		SCREEN_HEIGHT - mtop( body->GetPosition().y ), 
		BLOCK_SIZE,	BLOCK_SIZE*2, body->GetAngle(), 
		(BLOCK_SIZE / 2.0f ), BLOCK_SIZE);
}

b2Vec2 Player::GetPos() {
	pos = body->GetPosition();
	return pos;
}