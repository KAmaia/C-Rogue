#ifndef worldgen_h
#define worldgen_h

#include <stdlib.h>

#include "world.h"
#include "tile.h"

class worldgen{
	public:
		worldgen();
		worldgen(int, int);
		world generateworld();
		void initialize();
		
		int getWorldHeight();
		int getWorldWidth();

	private:
		int wHeight;
		int wWidth;
		world gameWorld;
};

#endif
