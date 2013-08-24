#include "Game_refs.h"


void loadData() {
	blockTexture = loadTexture ( "images/block.png", GL_RGB );
	
	loadMap("1.map");
}

void loadMap( char * fileName ){
	FILE* file;
	char path[255];
	strcpy ( path, "maps/" );
	strcat ( path, fileName );
	file = fopen( path, "r" );
	int map[1000] = {0};
	Uint i;
	int result = 0;
	for ( i = 0; ( result != EOF ) && (i < 1000); i++ ) {
		result = fscanf( file, "%i, ", &(map[i]));
	}
	printf ( "%i\n", i );
	Uint size = i;
	Uint length = size / 10;
	for ( i = 0; i < size; i++ ) {
		if ( map[i] == 1 )
			new BBlock( BLOCK_SIZE/2.0f + ( i % length ) * BLOCK_SIZE,  ( i / length ) * BLOCK_SIZE );
	}

	fclose( file );
}