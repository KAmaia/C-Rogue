#ifndef renderer_h
#define renderer_h

#include <vector>
#include <algorithm>

#include "world.h"
#include "tile.h"

class renderer{
	public:
		//add player/vector<actor> here, later.
		std::vector<char> renderFrame(world);	
		void moveCenterUp();
		void moveCenterDown();
		void moveCenterLeft();
		void moveCenterRight();
		void init(int, int, world);
	private:
		void getOffSets(int&, int&);
		int renderCenterX, renderCenterY;
		int sHeight, sWidth;
		int wHeight, wWidth;
		void setCenter();
		
};

#endif
