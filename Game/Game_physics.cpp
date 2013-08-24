#include "Game_refs.h"

b2Vec2	gravity(0.0f, -10.0f);
b2World * world = new b2World(gravity);

const float TRANSLATE_MODIFIER = 100.0f;

// Pixels to Metrs
float ptom ( float pixels ) {
	return pixels / TRANSLATE_MODIFIER;
}

// Metrs to Pixels
float mtop ( float metrs ) {
	return metrs * TRANSLATE_MODIFIER;
}