#include "Game_refs.h"


void loadData() {
	blockTexture		= loadTexture ( "images/block.png",    GL_RGB );
	blockTextureAlt		= loadTexture ( "images/blockAlt.png", GL_RGBA );
	manTexture			= loadTexture ( "images/man.png", GL_RGBA );
	manTextureJump		= loadTexture ( "images/man_jump.png", GL_RGBA );
	manTextureRun		= loadTexture ( "images/man_run.png", GL_RGBA );
	manTextureOnEnge	= loadTexture ( "images/man_onEdge.png", GL_RGBA );
	manTextureOnWall	= loadTexture ( "images/man_onWall.png", GL_RGBA );
	
	loadMap("1.map");
	player = new Player(100.0f, 400.0f);

}

void loadMap( char * fileName ){
	FILE* file;
	char path[255];
	strcpy ( path, "maps/" );
	strcat ( path, fileName );
	file = fopen( path, "r" );
	std::vector< int > map;
	Uint i;
	int result = 0;

	int w=0,h=0;
	fscanf( file, "%i, ", &w);
	fscanf( file, "%i, ", &h);
	printf( "Map size: %ix%i\n", w, h );
	Uint size = w*h;
	for ( i = 0; ( result != EOF ) && (i < size); i++ ) {
		int a = 0;
		result = fscanf( file, "%i, ", &(a));
		map.push_back(a);
	}
	printf ( "%i\n", i );
	//Uint length = w;
	for ( i = 0; i < size; i++ ) {
		if ( map[i] == 1 )
			new BBlock( BLOCK_SIZE/2.0f + ( i % w ) * BLOCK_SIZE,  ( i / w ) * BLOCK_SIZE );
	}

	fclose( file );
}