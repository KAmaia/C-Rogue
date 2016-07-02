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
	//If the Renderable Area is Bigger than the world,
	//Center the world.
	int endY = startY + screenHeight;
	int endX = startX + screenWidth;

	if(endY >= incWorld.getHeight()){
		endY = incWorld.getHeight() -1;
	}
	if(endX >= incWorld.getWidth()){
		endX = incWorld.getWidth() - 1;
	} 
		
	//but what if the world is bigger than the renderable area?!
	//I am pretty sure that this is what's causing my crash!
	int offsetY;
	int offsetX;	
	if(incWorld.getHeight() <= screenHeight){
		offsetY = screenHeight / 2 - incWorld.getHeight() / 2;
	}
	else{
		offsetY = screenHeight / 2;	
	}
	if(incWorld.getWidth() <= screenWidth){	
		offsetX = screenWidth / 2 - incWorld.getWidth() / 2;
	}
	else{
		offsetX = screenWidth / 2;
	}	
	//finally create the rendered frame.
	renderedFrame.resize(screenHeight*screenWidth);
	for(int y = startY; y < endY; y++){
		for(int x = startX; x < endX; x++){
			renderedFrame[(( offsetY + (y * screenWidth) + x + offsetX)) ] = incWorld.getTile(y,x).getChar();	
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
