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
		void moveCenterUp();
		void moveCenterDown();
		void moveCenterLeft();
		void moveCenterRight();
		void setRenderCenterY(int);
		void setRenderCenterX(int);
		void init(int, int, world);
	private:
		
		void initializeFrame(std::vector<std::vector<char> >&);
		void getOffSets(int&, int&);
		void checkFirsts(int&, int&);
		void checkLasts(int&, int&);
		int renderCenterX, renderCenterY;
		int sHeight, sWidth;
		int wHeight, wWidth;
		void setCenter();
		
};

#endif
