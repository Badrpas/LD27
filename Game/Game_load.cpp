#include "Game_refs.h"


void loadData() {
	blockTexture		= loadTexture ( "images/block.png",				GL_RGB );
	blockTextureAlt		= loadTexture ( "images/blockAlt.png",			GL_RGBA );
	
	pointTextureFinish	= loadTexture ( "images/points/finish.png",		GL_RGBA );
	pointTextureVisited	= loadTexture ( "images/points/visited.png",	GL_RGBA );
	pointTextureFree	= loadTexture ( "images/points/free.png",		GL_RGBA );

	manTexture			= loadTexture ( "images/man.png",				GL_RGBA );
	manTextureJump		= loadTexture ( "images/man_jump.png",			GL_RGBA );
	manTextureRun		= loadTexture ( "images/man_run.png" ,			GL_RGBA );
	manTextureRunArray  = ( GLuint* ) malloc ( sizeof (GLuint) * 5 );	
	manTextureRunArray[0]= loadTexture ( "images/run/1.png" ,			GL_RGBA );
	manTextureRunArray[1]= loadTexture ( "images/run/2.png" ,			GL_RGBA );
	manTextureRunArray[2]= loadTexture ( "images/run/3.png" ,			GL_RGBA );
	manTextureRunArray[3]= loadTexture ( "images/run/4.png" ,			GL_RGBA );
	manTextureRunArray[4]= loadTexture ( "images/run/5.png" ,			GL_RGBA );
	manTextureOnEnge	= loadTexture ( "images/man_onEdge.png",		GL_RGBA );
	manTextureOnWall	= loadTexture ( "images/man_onWall.png",		GL_RGBA );
	
	loadMap("1.lua");



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

	int w=0,h=0;/*
	fscanf( file, "%i, ", &w);
	fscanf( file, "%i, ", &h);*/


			char word[255];
			for ( int i = 0; i < 4; i++ ) {
				fscanf( file, "%[^\n]\n", word );
				printf("%s\n", word);
			}
			fscanf( file, "%s = %i,\n", word, &w );
			fscanf( file, "%s = %i,\n", word, &h );
	printf( "Map size: %ix%i\n", w, h );
			while ( strcmp( word, "data = {" ) ) {
				result = fscanf( file, "%[^\n]\n", word );
			}
	Uint size = w*h;
	for ( i = 0; ( result != EOF ) && (i < size); i++ ) {
		int a = 0;
		result = fscanf( file, "%i, ", &(a));
		map.push_back(a);
	}
	printf ( "%i\n", i );
	for ( i = 0; i < size; i++ ) {
		if ( map[i] == 1 )
			new BBlock( BLOCK_SIZE_2 + ( i % w ) * BLOCK_SIZE,  ( i / w ) * BLOCK_SIZE );
		if ( map[i] == 2 ) {
			spawnPoint = new CPoint ( BLOCK_SIZE_2 + ( i % w ) * BLOCK_SIZE,  ( i / w ) * BLOCK_SIZE, CONTROL_POINT);
			player = new Player( BLOCK_SIZE_2 + ( i % w ) * BLOCK_SIZE,  ( i / w ) * BLOCK_SIZE );
		}
		if ( map[i] == 3 ) {
			new CPoint ( BLOCK_SIZE_2 + ( i % w ) * BLOCK_SIZE,  ( i / w ) * BLOCK_SIZE, CONTROL_POINT);
		}		
		if ( map[i] == 4 ) {
			new CPoint ( BLOCK_SIZE_2 + ( i % w ) * BLOCK_SIZE,  ( i / w ) * BLOCK_SIZE, FINISH);
		}
	}

	fclose( file );
}