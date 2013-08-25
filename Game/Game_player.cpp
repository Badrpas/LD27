#include "Game_refs.h"

Player::Player( float x, float y ) {
	state = STAND;
	speed = 200.5f;
	look  = RIGHT;
	timeToControl = 0;
	b2BodyDef		_bodyDef;
	b2PolygonShape	_bodyShape;
	b2CircleShape	_circleShape, 
					_circleShape2;
	b2FixtureDef	_bodyFixture;

	_bodyDef.type = b2_dynamicBody;		// Объект, ска, динамичен!
	_bodyDef.position.Set( ptom( x ), ptom ( SCREEN_HEIGHT - y ) );
	_bodyDef.linearDamping = 0.0f;		// Торможение
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

	body->SetFixedRotation( true );
}

void Player::Update() {
	if ( timeToControl > 0 );
		timeToControl -= dt;

	float32 mod = 0;
	b2Vec2 vel = body->GetLinearVelocity();
	
	float32 jumpPower = ptom( speed );
	jumpPower *= body->GetMass();


	//if ( timeToControl <= 0 ) {
	//	if ( keyPressed( SDLK_RIGHT ) || keyPressed( SDLK_LEFT ) ) {
	//		if ( keyPressed( SDLK_LEFT  ) ) {
	//			look = LEFT;
	//			state = RUN;
	//			body->ApplyLinearImpulseCenter( b2Vec2(-jumpPower, 0 ) );
	//		}
	//		if ( keyPressed( SDLK_RIGHT ) ) {
	//			look = RIGHT;
	//			state = RUN;
	//			body->ApplyLinearImpulseCenter( b2Vec2( jumpPower, 0 ) );
	//		}
	//		if ( keyPressed( SDLK_RIGHT ) && keyPressed( SDLK_LEFT ) ) {
	//			state = STAND;
	//		}
	//	}
	//}



    float desiredVel = 0;
	//state = STAND;
	if ( ( timeToControl <= 0 ) ) {
		if ( keyPressed(SDLK_RIGHT) || keyPressed(SDLK_LEFT ) ) {
			if ( keyPressed(SDLK_LEFT ) ) {
				desiredVel = -5;
				look  = LEFT;
				state = RUN;
			}
			if ( keyPressed(SDLK_RIGHT) ) {
				desiredVel =  5; 
				look  = RIGHT;
				state = RUN;
			}
			if ( keyPressed(SDLK_RIGHT) && keyPressed(SDLK_LEFT ) ) {
				desiredVel =  0;
				state = STAND;
			}
		} else 
		if ( (state == STAND) || (state == RUN) )
			desiredVel = 0;
		float velChange = desiredVel - vel.x;
		float force = body->GetMass() * velChange / (dt); //f = mv/t
		body->ApplyForce ( b2Vec2(force,0), body->GetWorldCenter() );
	}


	height  = 10000.0f;
	canJump = false;
	b2Vec2 pos = GetPos(); // player pos

	for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()) {
		if ( pos.y > f->GetBody()->GetPosition().y )	// Gtting center of
			 pos =   f->GetBody()->GetPosition();		// lower circleShape
	}
	// player down pos (lower edge)
	b2Vec2 pdpos = pos;
	pdpos.y -= ptom ( circleRadius );

	Uint8 blockContactCount = 0;

	for ( b2ContactEdge* ce = body->GetContactList(); ce; ce = ce->next ) {
		b2Contact* c = ce->contact;
		c->SetRestitution( 0.0 );
		BBlock* block =  ( BBlock* )( ce->other->GetUserData() );
		block->SetTexture( blockTextureAlt );
		b2Vec2 bpos = block->GetBody()->GetPosition();
				// onWall
		if ( abs( bpos.x - pos.x ) <= ptom( BLOCK_SIZE_2 + circleRadius + 2.0f ) &&
			 abs( bpos.x - pos.x ) >= ptom( BLOCK_SIZE_2 + circleRadius - 2.0f ) &&
			      bpos.y - pos.y   <= ptom( BLOCK_SIZE ) &&
				  bpos.y - pos.y   >= ptom(-BLOCK_SIZE_2 )
			) {
				block->color[0] = 0;
				block->color[1] = 0;
				//state = ON_WALL;
				blockContactCount++;
				if ( bpos.x < pos.x )
					look = RIGHT;
				else
					look = LEFT;
		} else {
		}

		// canJump
		if  (  abs( bpos.x - pdpos.x ) <= ptom( BLOCK_SIZE_DIAGONAL_2 ) &&
					( pdpos.y >=bpos.y ) &&
					( pdpos.y - bpos.y <= BLOCK_SIZE_DIAGONAL_2 ) ) {
			height = body->GetPosition().y - bpos.y;
			if ( keyPressed( SDLK_RIGHT ) || keyPressed( SDLK_LEFT ) )
				state = RUN;
			else 
				state = STAND;
			canJump = true;
			timeToControl = 0;
		}


	}

	if ( !canJump ) {
		state = JUMP;
		if ( blockContactCount >= 1 ) {
			state = ON_WALL;
			body->ApplyLinearImpulseCenter ( b2Vec2 ( 2.0 * (-(int)look), 0.0  ) );
		}
	}



	if ( keyDown ( SDLK_UP ) ) {
		if ( state == RUN || state == STAND ) {
			float32 jumpPower = ptom(speed);
			jumpPower *= body->GetMass() * 2.0 ;
			body->SetLinearVelocity ( b2Vec2(body->GetLinearVelocity().x, 0) );
			body->ApplyLinearImpulse( b2Vec2(0,jumpPower), body->GetWorldCenter() );
			//state = JUMP;
		} else if ( state == ON_WALL ) {
			float32 jumpPower = ptom(speed);
			jumpPower *= body->GetMass() * 2.5 ;
			body->SetLinearVelocity ( b2Vec2( 0, 0 ) );
			body->SetForce ( b2Vec2( 0, 0 ) );
			body->ApplyLinearImpulse( b2Vec2( jumpPower*1.0*((int)look), jumpPower ), body->GetWorldCenter() );
			timeToControl = 0.5;
		}
	}
	

	CAMERA_SHIFT_X = mtop(body->GetPosition().x) - SCREEN_WIDTH / 2 / SCALE_IMAGE;
	CAMERA_SHIFT_Y = mtop(body->GetPosition().y) - SCREEN_HEIGHT/ 2 * SCALE_IMAGE;
}

b2Body*	Player::GetBody() {
	return body;
}

void Player::Render() {
	switch ( state ) {
		case STAND:		texture = manTexture;		break;
		case RUN:		texture = manTextureRun;	break;
		case JUMP:		texture = manTextureJump;	break;
		case ON_EDGE:	texture = manTextureOnEnge;	break;
		case ON_WALL:	texture = manTextureOnWall;	break;
	}
	draw (	texture,  mtop( body->GetPosition().x ), 
			SCREEN_HEIGHT - mtop( body->GetPosition().y ), 
			BLOCK_SIZE   * (int)look, BLOCK_SIZE*2, body->GetAngle(), 
			BLOCK_SIZE_2 * (int)look, BLOCK_SIZE );
}

b2Vec2 Player::GetPos() {
	pos = body->GetPosition();
	return pos;
}