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
	//then if the visible area is larger than the world, make sure we stay in bounds.
	int endY = firstTileY + screenHeight;
	int endX = firstTileX + screenWidth;

	if(endY >= incWorld.getHeight()){
		endY = incWorld.getHeight() -1;
	}
	if(endX >= incWorld.getWidth()){
		endX = incWorld.getWidth() -1;
	} 
	
	//finally create the rendered frame.
	renderedFrame.reseize(screenHeight*screenWidth);
	for(int y = startY; y <= endY; y++){
		for(int x = startX; x <= endX; x++){
		
		}
	}
	
	return renderedFrame;
}

void renderer::setCenter(int wWidth, int wHeight){
	renderCenterY = std::min(renderCenterY, 0);
	renderCenterY = std::max(renderCenterY, screenHeight - wHeight);
	
	renderCenterX = std::min(renderCenterX, 0);
	renderCenterX = std::max(renderCenterX, screenWidth - wWidth);
}
