#include <vector>
#include <algorithm>

#include "../include/renderer.h"
#include "../include/world.h"
#include "../include/tile.h"

std::vector<char> renderer::renderFrame(int sizeY, int sizeX, world incWorld){
	std::vector<char> renderedFrame;
	screenHeight = sizeY;
	screenWidth = sizeX;
	
	//set our center position.
	setCenter(incWorld.getHeight(), incWorld.getWidth());		
	
	//set the start position.  (This is relative to the map)
	int startY = -renderCenterY;
	int startX = -renderCenterX;
	
	//if the start positions are less than 0 make sure that they don't go below 0.
	if(startY < 0){
		startY = 0;
	}
	if (startX < 0){
		startX = 0;
	}
	
	//if the world is larger than the visible area, trim it.
	
	
	int endY = startY + screenHeight;
	int endX = startX + screenWidth;

	if(endY > incWorld.getHeight()){
		endY = incWorld.getHeight() -1;
	}
	if(endX > incWorld.getWidth()){
		endX = incWorld.getWidth() - 1;
	} 
	
	//finally create the rendered frame.
	renderedFrame.resize(screenHeight*screenWidth);
	for(int y = startY; y <= endY; y++){
		int offsetY = (y + screenHeight / 2) - (incWorld.getHeight() / 2);
		for(int x = startX; x <= endX; x++){
			int offsetX = x + (screenWidth  /2 - incWorld.getWidth() / 2);
			renderedFrame[((offsetY * screenWidth) + offsetX) ] = incWorld.getTile(y,x).getChar();	
		}
	}
	return renderedFrame;
}


void renderer::setCenter(int wWidth, int wHeight){
	// screen height = 25, wHeight = 10
	// yDiff = 15;	
	int yDiff = screenHeight / 2 - wHeight / 2;
	
	//renderCenterY = 0;
	renderCenterY = std::min(renderCenterY, 0);
	//RCY = 0;		
	renderCenterY = std::max(renderCenterY, yDiff);
	
	int xDiff = screenWidth /2 - wWidth / 2;
	renderCenterX = std::min(renderCenterX, 0);
	renderCenterX = std::max(renderCenterX, xDiff);
}
