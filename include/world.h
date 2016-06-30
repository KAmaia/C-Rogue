#ifndef world_h
#define world_h

#include <vector>

#include "tile.h"


class world{
	public:
		world();
		world(int, int);
		
		tile getTile(int, int);
		int getWidth();
		int getHeight();
		


	private:
		void initTiles();
		std::vector<tile> tileMap;
		int width;
		int height;
};
#endif
