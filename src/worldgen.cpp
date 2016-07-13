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
	wHeight = height;
	wWidth = width;
	initialize();
}

world worldgen::generateworld(){
	//this is where the world is going to be generated. I hope.	
	for(int y = 0; y < wHeight; y++){
		for(int x = 0; x < wWidth; x++){
			if((y % 2 == 0) && (x % 2 == 0)){
				gameWorld.setTile(y, x, tile('+'));
				continue;			
			}
			else if(y % 2 == 0){
				if(y == 0){
					gameWorld.setTile(y,x,tile('T'));
				}
				else{
					gameWorld.setTile(y,x, tile('-'));
				}				
				continue;
			}
			else if(x % 2 == 0){
				
				if(x == 0){
					gameWorld.setTile(y,x,tile('L'));
				}
				else{				
					gameWorld.setTile(y,x,tile('|'));
				}				
				continue;
			}
			
			else{
				if((y < wHeight / 2) && (x < wWidth / 2)){
					gameWorld.setTile(y,x,tile('1'));
				}
				if((y < wHeight / 2) && (x >= wWidth / 2)){
					gameWorld.setTile(y,x, tile('2'));
				}
				if((y >= wHeight / 2) && (x < wWidth /2)){
					gameWorld.setTile(y, x, tile('3'));
				}
				if((y >= wHeight / 2) && (x >= wWidth / 2)){
					gameWorld.setTile(y, x, tile('4'));
				}
			}
			
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
