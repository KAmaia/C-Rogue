#include <stdlib.h>

#include "../include/worldgen.h"
#include "../include/world.h"
#include "../include/tile.h"

worldgen::worldgen(){
	wWidth = 10;
	wHeight = 10;
	initialize();
}

worldgen::worldgen(int height, int width ){
//not-so default ctor
	wWidth = width;
	wHeight = height;
	initialize();
}

world worldgen::generateworld(){
	//this is where the world is going to be generated. I hope.	
	for(int y = 0; y < wHeight; y++){
		for(int x = 0; x < wWidth; x++){
			gameWorld.setTile(y, x, tile('#'));
		}
	}
	return gameWorld;
}

void worldgen::initialize(){
	//set up anything that needs to be set up prior to generation.
	gameWorld = world(wHeight, wWidth);
}

int worldgen::getWorldHeight(){
	return wHeight;
}

int worldgen::getWorldWidth(){
	return wWidth;
}
