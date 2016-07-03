#include <vector>

#include "../include/world.h"
#include "../include/tile.h"



using std::vector;

world::world(){
	width = 0;
	height = 0;
}

world::world(int height, int width){
	this->width = width;
	this->height = height;
	initTiles();
}

void world::initTiles(){
	tileMap.resize(height);
	for(int i = 0; i < height; ++i){
		tileMap[i].resize(width);
	}
}

/* This Method will go away
 * Eventually.
*/

void world::setTile(int y, int x, char c){
	tileMap[y][x].setChar(c);
}

void world::setTile(int y, int x, tile t){
	tileMap[y][x] = t;
}
tile world::getTile(int y, int x){
	return tileMap[y][x];
}

int world::getWidth(){
	return width;
}

int world::getHeight(){
	return height;
}
