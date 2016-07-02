#ifndef renderer_h
#define renderer_h

#include <vector>
#include <algorithm>

#include "world.h"
#include "tile.h"

class renderer{
	public:
		//add player/vector<actor> here, later.
		std::vector<char> renderFrame(int, int, world);	
	private:
		int renderCenterX, renderCenterY;
		int screenHeight, screenWidth;
		
		void setCenter(int, int);
};
#endif
