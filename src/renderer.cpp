#include <vector>
#include <algorithm>

#include "../include/renderer.h"
#include "../include/world.h"
#include "../include/tile.h"

int startX;
int startY;


void renderer::init(int ROWS, int COLS, world incWorld){
	sHeight = ROWS;
	sWidth = COLS;
	wHeight = incWorld.getHeight();
	wWidth = incWorld.getWidth();
	setCenter();
}

std::vector<char> renderer::renderFrame(world incWorld){
	std::vector<char> renderedFrame;
	
	//find our offsets.
	int offSetY;
	int offSetX;
	getOffSets(offSetY, offSetX);	
	
	//using the offsets, set our first tile.
	int firstTileY = renderCenterY + offSetY;
	int firstTileX = renderCenterX + offSetX;
	//make sure the first tile is within bounds.
	if(firstTileY <= 0){
		firstTileY = 0;
		renderCenterY = renderCenterY;
	}
	if(firstTileX <= 0){
		firstTileX = 0;
		renderCenterX = renderCenterX;
	}
	
	//now that we know our first tiles, 
	//we can add our screen width and height to figure out
	//what the last tile to render is.
	int lastTileY = firstTileY + sHeight;
	int lastTileX = firstTileX + sWidth;
	
	//make sure that the last tile stays within bounds.
	if(lastTileY >= wHeight){
		lastTileY = lastTileY;
		renderCenterY = renderCenterY;
	}
	if(lastTileX >= wWidth){
		lastTileX = lastTileX;
		renderCenterX = renderCenterX;
	}
	
	renderedFrame.resize(sHeight*sWidth);
	for(int y = firstTileY; y < lastTileY; y++){
		for(int x = firstTileX; x < lastTileX; x++){
			renderedFrame[y * wWidth + x] = incWorld.getTile(y,x).getChar();
		}
	}
	return renderedFrame;
}

void renderer::getOffSets(int &offY, int &offX){
	offY = sHeight / 2 - wHeight / 2;
	offX = sWidth / 2 - wWidth / 2;	
}

void renderer::setCenter(){
	renderCenterX = wWidth / 2;
	renderCenterY = wHeight / 2;
}

void renderer::moveCenterUp(){
	renderCenterY += 1;
}
void renderer::moveCenterDown(){
	renderCenterY -= 1;
}

void renderer::moveCenterLeft(){
	renderCenterX += 1;
}
void renderer::moveCenterRight(){
	renderCenterX -= 1;
}


