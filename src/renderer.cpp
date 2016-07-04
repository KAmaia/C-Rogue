#include <vector>
#include <algorithm>

#include "../include/renderer.h"
#include "../include/world.h"
#include "../include/tile.h"

using std::vector;



void renderer::init(int ROWS, int COLS, world incWorld){
	sHeight = ROWS;
	sWidth = COLS;
	wHeight = incWorld.getHeight();
	wWidth = incWorld.getWidth();
	setRenderCenter();
	setWorldCenter();
}

vector<vector<char> > renderer::renderFrame(world incWorld){
	std::vector<std::vector<char> > renderedFrame;
	initializeFrame(renderedFrame);

	//find our offsets.
	int firstTileY;
	int firstTileX;	
	int lastTileY;
	int lastTileX;	
	
	calculateOffSets();	
	//using the offsets, set our first tile.
	firstTileY = worldCenterY - renderCenterY;
	firstTileX = worldCenterX - renderCenterX;
	//make sure the first tile is within bounds.
	checkFirsts(firstTileY, firstTileX);
	//now that we know our first tiles, 
	//we can add our screen width and height to figure out
	//what the last tile to render is.
	lastTileY = firstTileY + sHeight;
	lastTileX = firstTileX + sWidth;
	//make sure that the last tile stays within bounds.
	checkLasts( lastTileY, lastTileX );
	
	for(int y = firstTileY; y < lastTileY -1; y++){
		for(int x = firstTileX; x < lastTileX -1; x++){
			char c = incWorld.getTile(y,x).getChar();
			renderedFrame[y + offSetY][x + offSetX] = c;		
		}
	}
	return renderedFrame;
}

void renderer::initializeFrame(vector<vector<char> > &renderedFrame){
	renderedFrame.resize(sHeight);
	for(int y = 0; y < sHeight; y++){
		renderedFrame[y].resize(sWidth, ' ');
	}		
}
//set both centers
void renderer::setRenderCenter(){
	renderCenterY = sHeight / 2;
	renderCenterX = sWidth / 2;
}

void renderer::setWorldCenter(){
	worldCenterY = wHeight / 2;	
	worldCenterX = wWidth / 2;
}
//k.

//check first and last
void renderer::checkFirsts(int &firstY, int &firstX){
	firstY = firstY < 0 ? 0 : firstY;
	firstX = firstX < 0 ? 0 : firstX;
}

void renderer::checkLasts(int &lastY, int &lastX){
	lastY = lastY >= wHeight ? wHeight : lastY;
	lastX = lastX >= wWidth ? wWidth : lastX;
} 
//k.

//Oh boy! Offsets!
void renderer::calculateOffSets(){
	offSetY = renderCenterY - (wHeight / 2);
	offSetX = renderCenterX - (wWidth / 2);	
}
//k.

//Movement stuff
void renderer::moveCenterUp(){
	renderCenterY += renderCenterY + worldCenterY >= sHeight - 1 ? 0 : 1;
}
void renderer::moveCenterDown(){
	renderCenterY -= renderCenterY - worldCenterY <= 1 ? 0 : 1;
}

void renderer::moveCenterRight(){
	renderCenterX -= renderCenterX - worldCenterX <= 0 ? 0 : 1;
}
void renderer::moveCenterLeft(){
	renderCenterX += renderCenterX + worldCenterX > sWidth - 1 ? 0 : 1;
}
//k.

int renderer::getCenterRenderX(){
	return renderCenterX;
}

int renderer::getCenterRenderY(){
	return renderCenterY;
}
