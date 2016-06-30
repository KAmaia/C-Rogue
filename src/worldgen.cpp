#include <stdlib.h>

#include "../include/worldgen.h"
#include "../include/world.h"
#include "../include/tile.h"

void worldgen::generateworld(int height, int width){
	wWidth = width;
	wHeight = height;
}

void initialize(){
	gameWorld = world(wWidth, wHeight);
	gameWorld.init();
}
