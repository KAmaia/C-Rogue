#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../include/renderer.h"
#include "../include/world.h"
#include "../include/tile.h"

using std::vector;

void renderer::init(int ROWS, int COLS, world incWorld){
	sHeight = ROWS;
	sWidth = COLS;
	wHeight = incWorld.getHeight();
	wWidth = incWorld.getWidth();
	setWorldCenter();	
	renderCenterY = sHeight / 2 - wHeight;
	renderCenterX = sWidth / 2 - wWidth;	
}

vector<vector<char> > renderer::renderFrame(world incWorld){
	std::vector<std::vector<char> > renderedFrame;
	initializeFrame(renderedFrame);

	//find our offsets.
	int firstTileY;
	int firstTileX;	
	int lastTileY;
	int lastTileX;	
	
	
	renderCenterY = std::min(renderCenterY, 0);
	renderCenterY = std::max(renderCenterY, sHeight - wHeight);

	renderCenterX = std::min(renderCenterX, 0);
	renderCenterX = std::max(renderCenterX, sWidth - wWidth);
	

	calculateOffSets();	
	//using the offsets, set our first tile.
	firstTileY = -renderCenterY;
	firstTileX = -renderCenterX;
	//make sure the first tile is within bounds.
	checkFirsts(firstTileY, firstTileX);
	//now that we know our first tiles, 
	//we can add our screen width and height to figure out
	//what the last tile to render is.
	lastTileY = firstTileY + sHeight + 1;
	lastTileX = firstTileX + sWidth + 1;
	//make sure that the last tile stays within bounds.
	checkLasts( lastTileY, lastTileX );
	
	for(int y = firstTileY; y < lastTileY - 1; y++){
		for(int x = firstTileX; x < lastTileX - 1; x++){
			char c = incWorld.getTile(y,x).getChar();
			renderedFrame[y + renderCenterY][x + renderCenterX] = c;		
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
	lastY = lastY >= wHeight ? wHeight -1 : lastY;
	lastX = lastX >= wWidth ? wWidth  -1 : lastX;
} 
//k.

//Oh boy! Offsets!
void renderer::calculateOffSets(){
	offSetY = renderCenterY - wHeight;
	offSetX = renderCenterX - wWidth ;	
}
//k.

//Movement stuff
void renderer::moveCenterDown(){
	renderCenterY -= renderCenterY >= 1 ? 0 : 1;
}
void renderer::moveCenterUp(){
	renderCenterY += renderCenterY <= 1 ? 1 : 0;
}

void renderer::moveCenterRight(){
	renderCenterX += renderCenterX >= 1 ? 0:1;	
}
void renderer::moveCenterLeft(){	
	renderCenterX -= renderCenterX <= 1 ? 1 : 0;
}
//k.

int renderer::getOffSetX(){
	return offSetX;
}
int renderer::getOffSetY(){
	return offSetY;
}

int renderer::getCenterRenderX(){
	return renderCenterX;
}

int renderer::getCenterRenderY(){
	return renderCenterY;
}
