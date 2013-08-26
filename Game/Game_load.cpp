#include "Game_refs.h"

char	mapList[255][255];
int		mapCount;
int		currentMap;
bool	NEED_LOAD_NEXT_MAP = false;

void loadData() {

	backgroundTexture   = ( GLuint* ) malloc ( sizeof (GLuint) * 5 );	
	backgroundTexture[0]= loadTexture ( "images/bg/1.png" ,			GL_RGBA );
	backgroundTexture[1]= loadTexture ( "images/bg/init.png" ,		GL_RGBA );
	backgroundTexture[2]= loadTexture ( "images/bg/jumpToWin.png" ,	GL_RGBA );
	backgroundTexture[3]= loadTexture ( "images/bg/restart.png" ,	GL_RGBA );
	backgroundTexture[4]= loadTexture ( "images/bg/maze.png" ,			GL_RGBA );


	blockTexture		= loadTexture ( "images/block.png",				GL_RGB  );
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
	
	loadMapList();
	loadNextMap();
}



void loadNextMap() {
	currentMap++;
	printf ( "loading map ¹ %i %s\n", currentMap, mapList[currentMap] );
	flushMap();
	world = new b2World(gravity);
	if ( currentMap < mapCount )
		loadMap ( mapList[currentMap] );
	else {
		loadMap ( "default.lua" );
		SCALE_IMAGE = 0.25;
	}
}

void flushMap() {
	delete world;
	delete player;
	player = NULL;
	for ( Uint i = 0; i < blocks.size(); i++ ) {
		delete blocks[i];
	}
	blocks.resize(0);
	for ( Uint i = 0; i < points.size(); i++ ) {
		delete points[i];
	}
	points.resize(0);
}



void loadMapList() {
	FILE* file;
	currentMap = -1;
	char path[255] = "maps/maplist.txt" ;
	file = fopen( path, "r" );
	fscanf ( file, "%i\n", &mapCount );
	printf ( "%i maps:\n", mapCount );
	for (int i = 0; i < mapCount; i++ ) {
		fscanf ( file, "%s\n", mapList[i] );
		printf ( "%s\n", mapList[i] );
	}
	fclose(file);
}

void loadMap( char * fileName ){
	FILE* file;
	char path[255];
	strcpy ( path, "maps/" );
	strcat ( path, fileName );
	printf("Loading %s\n", path);
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
	printf("Map readed\n");
	for ( i = 0; i < size; i++ ) {
		printf("Block (%i) %i:%i ", map[i], ( i % w ),  ( i / w ) );
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
	printf ( "Loaded.\n" );
}