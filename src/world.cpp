#include <vector>

#include "../include/world.h"
#include "../include/tile.h"

using namespace std;

world::world(){
	width = 0;
	height = 0;
}

world::world(int width, int height){
	this->width = width;
	this->height = height;
	initTiles();
}

void world::initTiles(){
	tileMap.resize(width * height);
}

void world::setTile(int y, int x, char c){
	tileMap[y * width + x].setChar(c);
}

void world::setTile(int y, int x, tile t){
	tileMap[y * width + x] = t;
}
tile world::getTile(int y, int x){
	return tileMap[y * width + x];
}

int world::getWidth(){
	return width;
}

int world::getHeight(){
	return height;
}
