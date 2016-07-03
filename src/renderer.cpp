#include <vector>
#include <algorithm>

#include "../include/renderer.h"
#include "../include/world.h"
#include "../include/tile.h"

using std::vector;

int startX;
int startY;


void renderer::init(int ROWS, int COLS, world incWorld){
	sHeight = ROWS;
	sWidth = COLS;
	wHeight = incWorld.getHeight();
	wWidth = incWorld.getWidth();
	setCenter();
}

vector<vector<char> > renderer::renderFrame(world incWorld){
	std::vector<std::vector<char> > renderedFrame;
	initializeFrame(renderedFrame);

	//find our offsets.
	int offSetY;
	int offSetX;
	int firstTileY;
	int firstTileX;	
	int lastTileY;
	int lastTileX;	
	
	setRenderCenterY(std::min(renderCenterY, 0));
	setRenderCenterY(std::max(renderCenterY, sHeight - wHeight));

	setRenderCenterX(std::min(renderCenterX, 0));
	setRenderCenterX(std::max(renderCenterX, sWidth - wWidth));
	
	getOffSets(offSetY, offSetX);	
	//using the offsets, set our first tile.
	firstTileY = -renderCenterY;
	firstTileX = -renderCenterX;
	//make sure the first tile is within bounds.
	checkFirsts(firstTileY, firstTileX);
	//now that we know our first tiles, 
	//we can add our screen width and height to figure out
	//what the last tile to render is.
	lastTileY = firstTileY + sHeight;
	lastTileX = firstTileX + sWidth;
	//make sure that the last tile stays within bounds.
	checkLasts(lastTileY, lastTileX);
	
	for(int y = firstTileY; y < lastTileY; y++){
		for(int x = firstTileX; x < lastTileX; x++){
			renderedFrame[y + renderCenterY][x + renderCenterX] = incWorld.getTile(y,x).getChar();		
		}
	}
	return renderedFrame;
}

void renderer::initializeFrame(vector<vector<char> > &renderFrame){
	renderFrame.resize(sHeight);
	for(int y = 0; y < sHeight; y++){
		renderFrame[y].resize(sWidth, 'x');
	}		
}

void renderer::checkLasts(int &lastY, int &lastX){
	if(lastY >= wHeight){
		lastY = wHeight -1;
		renderCenterY = renderCenterY;
	}
	if(lastX > wWidth){
		lastX = wWidth -1;
		renderCenterX = renderCenterX;
	}
}

void renderer::checkFirsts(int &firstY, int &firstX){
	if(firstY < 0){
		firstY = 0;
		renderCenterY = renderCenterY;
	}
	if(firstX < 0){
		firstX = 0;
		renderCenterX = 0;
	}
}

void renderer::getOffSets(int &offY, int &offX){
	offY = sHeight / 2 - wHeight / 2;
	offX = sWidth / 2 - wWidth / 2;	
}

void renderer::setRenderCenterY(int centerY){
	renderCenterY = centerY;
}

void renderer::setRenderCenterX(int centerX){
	renderCenterX = centerX;
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


