#ifndef renderer_h
#define renderer_h

#include <vector>
#include <algorithm>

#include "world.h"
#include "tile.h"

class renderer{
	public:
		//add player/vector<actor> here, later.
		std::vector<std::vector<char> > renderFrame(world);	
		int getCenterRenderX();
		int getCenterRenderY();
		int getOffSetX();
		int getOffSetY();		
		
		void moveCenterUp();
		void moveCenterDown();
		void moveCenterLeft();
		void moveCenterRight();
		void init(int, int, world);
	
	private:
		int worldCenterX, worldCenterY;		
		int renderCenterX, renderCenterY;
		int sHeight, sWidth;
		int wHeight, wWidth;
		int offSetY, offSetX;		
	
		void initializeFrame(std::vector<std::vector<char> >&);
		void calculateOffSets();
		void checkFirsts(int&, int&);
		void checkLasts(int&, int&);
		void setRenderCenter();
		void setWorldCenter();
};

#endif
