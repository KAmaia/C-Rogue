#ifndef worldgen_h
#define worldgen_h

#include <stdlib.h>

#include "world.h"
#include "tile.h"

class worldgen{
	public:
		worldgen();
		void generateworld(int, int);
	
	private:
		int wHeight;
		int wWidth;
		world gameWorld;
};

#endif
